#include <stdio.h>
#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "soc/soc.h"
#include "driver/gpio.h"
#include "soc/gpio_sig_map.h"
#include "soc/i2s_reg.h"
#include "soc/i2s_struct.h"
#include "soc/io_mux_reg.h"
#include <stdlib.h>
#include <string.h>
#include "rom/lldesc.h"
#include "esp_intr_alloc.h"
#include "I2Scamera.h"
#include "esp_log.h"
#include "driver/periph_ctrl.h"

static const char* TAG = "camera";

static camera_config_t s_config;
static lldesc_t s_dma_desc[2];
static uint32_t* s_dma_buf[2];
static uint8_t* s_fb[2];
static volatile int s_fb_idx = 0;
static bool s_initialized = false;
static int s_buf_line_width;
static int s_buf_height;
static volatile int s_line_count = 0;
static volatile int s_cur_buffer = 0;
static volatile bool s_i2s_running = false;
static SemaphoreHandle_t s_data_ready;
static SemaphoreHandle_t s_line_ready;
static SemaphoreHandle_t s_vsync_catch;
static volatile bool vsync_check = false;

static intr_handle_t s_i2s_intr_handle = NULL;

static void i2s_init();
static void i2s_frameReadStart(void);
static void i2s_readStart(int index);
static void IRAM_ATTR i2s_isr(void* arg);
static esp_err_t dma_desc_init(void);
static void line_filter_task(void *pvParameters);
static void IRAM_ATTR VSYNC_isr( void *arg );

//---------- VSYNC Interrupt --------------------------
static void IRAM_ATTR VSYNC_isr( void *arg )
{
//	uint32_t gpio_num = (uint32_t)arg;
	if( vsync_check ){
		BaseType_t xHigherPriorityTaskWoken;// = pdFALSE;
		xSemaphoreGiveFromISR( s_vsync_catch, &xHigherPriorityTaskWoken);
	}
}

//---------------------------------------------------
esp_err_t I2S_camera_init(camera_config_t* config)
{
	memcpy(&s_config, config, sizeof(s_config));

	s_buf_line_width = s_config.frame_width * s_config.pixel_byte_num;
	s_buf_height = s_config.frame_height;

	for(int i = 0; i < 2; i++){
		if( s_fb[i] != NULL) free( s_fb[i] );
		s_fb[i] = (uint8_t*)malloc(s_buf_line_width);
		if (s_fb[i] == NULL) {
			ESP_LOGE(TAG, "Failed to allocate frame buffer");
			return ESP_ERR_NO_MEM;
		}
	}
	s_fb_idx = 0;
	s_data_ready = xSemaphoreCreateBinary();
	s_line_ready = xSemaphoreCreateBinary();
	s_vsync_catch = xSemaphoreCreateBinary();

	i2s_init();
	esp_err_t err = dma_desc_init();
	if (err != ESP_OK) {
		free(s_fb[0]);
		free(s_fb[1]);
		ESP_LOGE(TAG, "Faild to allocate dma buffer");
		return err;
	}
	xTaskCreatePinnedToCore(&line_filter_task, "line_filter", 4096, NULL, 10, NULL, 0);

	// skip at least one frame after changing camera settings
	while (gpio_get_level(s_config.VSYNC) == 1) {}
	while (gpio_get_level(s_config.VSYNC) == 0) {}
	while (gpio_get_level(s_config.VSYNC) == 1) {}

	s_initialized = true;
	return ESP_OK;
}

static void i2s_frameReadStart(void)
{
	xSemaphoreTake( s_vsync_catch, portMAX_DELAY);		// VSYNC wait
	vsync_check = false;
	s_cur_buffer = 0;
	s_line_count = 0;
	s_i2s_running = true;
	i2s_readStart(s_cur_buffer);	// start RX
}

uint16_t* camera_getLine(uint16_t lineno)
{
	if (!s_initialized) {
		return NULL;
	}
	unsigned long time = millis();;
	do{
		if(!s_i2s_running){
			vsync_check = true;
			i2s_frameReadStart();
		}
		xSemaphoreTake(s_line_ready, portMAX_DELAY);
		if( millis() - time > 5000 ) return NULL;
	}while(lineno != s_line_count);

	return (uint16_t*)s_fb[s_fb_idx];
}

static inline void i2s_conf_reset()
{
	const uint32_t conf_reset_flags = I2S_RX_RESET_M | I2S_RX_FIFO_RESET_M | I2S_TX_RESET_M | I2S_TX_FIFO_RESET_M;
	I2S0.conf.val |= conf_reset_flags;
	I2S0.conf.val &= ~conf_reset_flags;

	while (I2S0.state.rx_fifo_reset_back) {
		;
	}
}

static void i2s_init()
{
	// Configure input GPIOs
	gpio_num_t pins[] = {
		s_config.D0,
		s_config.D1,
		s_config.D2,
		s_config.D3,
		s_config.D4,
		s_config.D5,
		s_config.D6,
		s_config.D7,
		s_config.PCLK,
		s_config.VSYNC,
	};

	gpio_config_t conf = {
		.pin_bit_mask = 0,
		.mode 		  = GPIO_MODE_INPUT,
		.pull_up_en   = GPIO_PULLUP_DISABLE,
		.pull_down_en = GPIO_PULLDOWN_DISABLE,
		.intr_type	  = GPIO_INTR_DISABLE
	};

	for (int i = 0; i < 10; ++i) {
		conf.pin_bit_mask = 1LL << pins[i];
		gpio_config(&conf);
	}

	// VSYNC Interrupt Enable
	gpio_set_intr_type( s_config.VSYNC, GPIO_INTR_NEGEDGE );
	gpio_install_isr_service( 0 );
	gpio_isr_handler_add( s_config.VSYNC, VSYNC_isr, (void*)s_config.VSYNC );

	// Route input GPIOs to I2S peripheral using GPIO matrix
	gpio_matrix_in(s_config.D0,		I2S0I_DATA_IN0_IDX, false);
	gpio_matrix_in(s_config.D1,		I2S0I_DATA_IN1_IDX, false);
	gpio_matrix_in(s_config.D2,		I2S0I_DATA_IN2_IDX, false);
	gpio_matrix_in(s_config.D3,		I2S0I_DATA_IN3_IDX, false);
	gpio_matrix_in(s_config.D4,		I2S0I_DATA_IN4_IDX, false);
	gpio_matrix_in(s_config.D5,		I2S0I_DATA_IN5_IDX, false);
	gpio_matrix_in(s_config.D6,		I2S0I_DATA_IN6_IDX, false);
	gpio_matrix_in(s_config.D7,		I2S0I_DATA_IN7_IDX, false);
	gpio_matrix_in(s_config.VSYNC,	I2S0I_V_SYNC_IDX,	false);		// VSYNC は　ネガティブ　にしておくこと
	gpio_matrix_in(0x38,			I2S0I_H_SYNC_IDX,	false);		// 0x38 is Allways hight (0x30 is Allways low)
	gpio_matrix_in(0x38,			I2S0I_H_ENABLE_IDX, false);		// HREF は　見ない
	gpio_matrix_in(s_config.PCLK,	I2S0I_WS_IN_IDX,	false);		// PCLK は　HREF が　ON　の時のみ有効にすること

	// Enable and configure I2S peripheral
	periph_module_enable(PERIPH_I2S0_MODULE);	// I2S0 enable

	// Toggle some reset bits in LC_CONF register
	const uint32_t lc_conf_reset_flags = I2S_IN_RST_S | I2S_AHBM_RST_S | I2S_AHBM_FIFO_RST_S;

	I2S0.lc_conf.val |= lc_conf_reset_flags;
	I2S0.lc_conf.val &= ~lc_conf_reset_flags;
	
	// Toggle some reset bits in CONF register
	i2s_conf_reset();
	// Enable slave mode (sampling clock is external)
	I2S0.conf.rx_slave_mod = 1;
	// Enable parallel mode
	I2S0.conf2.lcd_en = 1;
	// Use HSYNC/VSYNC/HREF to control sampling
	I2S0.conf2.camera_en = 1;
	// Configure clock divider
	I2S0.clkm_conf.clkm_div_a = 1;
	I2S0.clkm_conf.clkm_div_b = 0;
	I2S0.clkm_conf.clkm_div_num = 2;
	// FIFO will sink data to DMA
	I2S0.fifo_conf.dscr_en = 1;
	// FIFO configuration, TBD if needed
	I2S0.fifo_conf.rx_fifo_mod_force_en = 1;	// The bit should always be set to 1.receive FIFO on
	I2S0.fifo_conf.rx_fifo_mod = 1;				// receive 16-bit single channel data
	I2S0.conf_chan.rx_chan_mod = 1;				// left channel + left channel [31:0]
	// Grab 16 samples
	I2S0.sample_rate_conf.rx_bits_mod = 16;	// Set the bits to configure the bit length of I2S receiver channel.
	// Clear flags which are used in I2S serial mode
	I2S0.conf.rx_right_first = 0;				// left fast
	I2S0.conf.rx_msb_right = 0;					// msb left
	I2S0.conf.rx_msb_shift = 0;					// Set this bit to enable receiver in Philips standard mode.
	I2S0.conf.rx_mono = 0;						// Set this bit to enable receiver’s mono mode.
	I2S0.conf.rx_short_sync = 0;				// Set this bit to enable receiver in PCM standard mode.

	// Allocate I2S interrupt, keep it disabled
	esp_intr_alloc( ETS_I2S0_INTR_SOURCE, ESP_INTR_FLAG_INTRDISABLED | ESP_INTR_FLAG_LEVEL1 | ESP_INTR_FLAG_IRAM,
		&i2s_isr, NULL, &s_i2s_intr_handle);
}

static void i2s_readStart(int index)
{
	esp_intr_disable(s_i2s_intr_handle);

	i2s_conf_reset();
	I2S0.rx_eof_num = s_buf_line_width;
	I2S0.in_link.addr = (uint32_t) &s_dma_desc[index];
	I2S0.in_link.start = 1;
	I2S0.int_clr.val = I2S0.int_raw.val;
	I2S0.int_ena.in_done = 1;		// DMA interrupt Enable when the current txlink descriptor is handled

	esp_intr_enable(s_i2s_intr_handle);
	I2S0.conf.rx_start = 1;			// receive Start
}

static void i2s_stop()
{
	I2S0.conf.rx_start = 0;
	esp_intr_disable(s_i2s_intr_handle);
	I2S0.int_ena.in_done = 0;		// DMA interrupt Disable
	s_i2s_running = false;
	i2s_conf_reset();
}

//-------------------------------------------------
esp_err_t  dma_desc_init(void)
{
	size_t buf_size = s_buf_line_width * 2;	// 2byte --> 32bit(4bytes)

	for (int i = 0; i < 2; ++i) {
		s_dma_buf[i] = (uint32_t*) malloc(buf_size);
		if (s_dma_buf[i] == NULL){
			return ESP_ERR_NO_MEM;
		}
		s_dma_desc[i].length = buf_size;     // size of a single DMA buf
		s_dma_desc[i].size = buf_size;       // total size of the chain
		s_dma_desc[i].owner = 1;
		s_dma_desc[i].sosf = 1;
		s_dma_desc[i].buf = (uint8_t*) s_dma_buf[i];
		s_dma_desc[i].offset = i;
		s_dma_desc[i].empty = 0;
		s_dma_desc[i].eof = 1;
		s_dma_desc[i].qe.stqe_next = NULL;
	}
	return ESP_OK;
}

//============= task ===================================

static void line_filter_task(void *pvParameters)
{
	while (true) {
		gpio_set_level( 2, 1);	// 2 = LED pin

		xSemaphoreTake(s_data_ready, portMAX_DELAY);
		int buf_idx = !s_cur_buffer;

		gpio_set_level( 2, 0);	// 2 = LED pin

		s_fb_idx = (s_fb_idx + 1) % 1;
		uint8_t* pfb = s_fb[s_fb_idx];
		const uint32_t* buf = s_dma_buf[buf_idx];

		for (int i = 0; i < s_buf_line_width/2; ++i) {
			uint32_t v = *buf++;	// Get 32 bit from DMA buffer
			// 1 Pixel = (2Byte i2s overhead + 2Byte pixeldata)
			*pfb++ = (uint8_t)(v & 0x000000ff);
			*pfb++ = (uint8_t)((v & 0x00ff0000)>>16);
		}
		xSemaphoreGive(s_line_ready);
	}
}

//---------- Interrupt ------------------------------
static void IRAM_ATTR i2s_isr(void* arg)	// 1 Line read done
{
	I2S0.int_clr.val = I2S0.int_raw.val;

	s_cur_buffer = !s_cur_buffer;
	++s_line_count;
	if(s_line_count == s_buf_height) {		// 1 Frame read done
		i2s_stop();
	} else {
		i2s_readStart(s_cur_buffer);
	}
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	xSemaphoreGiveFromISR(s_data_ready, &xHigherPriorityTaskWoken);
/*	if (xHigherPriorityTaskWoken != pdFALSE) {
		portYIELD_FROM_ISR();
	}
*/
}
