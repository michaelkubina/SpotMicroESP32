#pragma once

#include "esp_err.h"
#include "driver/ledc.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	int D0;             /*!< GPIO pin for camera D0 line */
	int D1;             /*!< GPIO pin for camera D1 line */
	int D2;             /*!< GPIO pin for camera D2 line */
	int D3;             /*!< GPIO pin for camera D3 line */
	int D4;             /*!< GPIO pin for camera D4 line */
	int D5;             /*!< GPIO pin for camera D5 line */
	int D6;             /*!< GPIO pin for camera D6 line */
	int D7;             /*!< GPIO pin for camera D7 line */
	int XCLK;           /*!< GPIO pin for camera XCLK line */
	int PCLK;           /*!< GPIO pin for camera PCLK line */
	int VSYNC;          /*!< GPIO pin for camera VSYNC line */
	int xclk_freq_hz;       	/*!< Frequency of XCLK signal, in Hz */
	ledc_timer_t ledc_timer;    /*!< LEDC timer to be used for generating XCLK  */
	ledc_channel_t ledc_channel;/*!< LEDC channel to be used for generating XCLK  */
	int frame_width;
	int frame_height;
	uint8_t pixel_byte_num;

}camera_config_t;

esp_err_t I2S_camera_init(camera_config_t* config);
uint16_t* camera_getLine(uint16_t lineno);
//uint16_t* camera_getFrame(void);


#ifdef __cplusplus
}
#endif