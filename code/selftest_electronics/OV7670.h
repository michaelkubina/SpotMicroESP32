#ifndef OV7670_h_
#define OV7670_h_

#include <Arduino.h>
#include <pgmspace.h>
#include <stdio.h>
#include "esp_log.h"
#include "esp_attr.h"
#include "I2Scamera.h"

#define	VGA	0	// 640 x 480
#define	QVGA	1	// 320 X 240
#define	QQVGA	2	// 160 x 120
#define CIF	3	// 352 x 288
#define QCIF	4	// 176 x 144
#define QQCIF	5	//  88 x 72

#define	YUV422		0x00	// color mode
#define	RGB565		0x04
#define	BAYER_RAW	0x01
#define PBAYER_RAW	0x05

#define OV7670_ADDR	0x21

struct regval_list{
	uint8_t reg_num;
	uint8_t value;
};

class OV7670{
	public:
		OV7670(void);
		~OV7670(void);

		void reset(void);
		esp_err_t init(const camera_config_t *value, uint8_t res, uint8_t colmode);

		void setResolution(uint8_t res);
		void setPCLK(uint8_t pre, uint8_t pll);
		void rewrCLKRC(void);
		void setHStart(uint16_t val);
		void setVStart(uint16_t val);
		uint16_t getHStart(void);
		uint16_t getVStart(void);

		uint16_t* getLine(uint16_t lineno);
		bool getLines(uint16_t lineno, uint8_t *buf, uint16_t n);
		void getFrame(uint8_t *buf);

		void stop(void);
		uint16_t getMID(void);
		uint16_t getPID(void);
		void vflip( bool enable );
		void setColor(uint8_t color);
		void setGain(uint16_t val);
		uint16_t getGain(void);
		void setAGC(uint8_t val);
		bool getAGC(void);
		void setAWB(uint8_t val);
		bool getAWB(void);
		void setAEC(uint8_t val);
		bool getAEC(void);
		void setBright(int8_t val);
		int8_t getBright(void);
		void setContrast(uint8_t val);
		uint8_t getContrast(void);
		void setAWBB(uint8_t val);
		void setAWBR(uint8_t val);
		void setAWBG(uint8_t val);
		void setExposure(uint16_t val);
		void colorbar(bool on);
		void colorbar_super(bool on);

		void wrReg(uint8_t reg,uint8_t dat);
		uint8_t rdReg(uint8_t reg);

	private:
		void wrRegs(const struct regval_list *reglist);
		void conf_setFrameSize(uint8_t res);
		camera_config_t cam_conf;
		uint8_t _resolution;
		uint8_t _colormode;
};

// OV7670 Registers ---------------------------------------------
//
//	AEC	: Automatic Exposure(露出) Control Mode
//	AGC : Automatic Gain Control
//	AWB	: Automatic White Balance Control
//	BLC : Black Level Calibration
//	ABLC: Automatic Black Level Calibration
//	DSP	: Digital Signal Processor
//
#define REG_GAIN	0x00	// AGC[9:0] lower 8bit (higher 2bit VREF[7:6])
#define REG_BLUE	0x01	// AWB Blue gain (00-ff)
#define REG_RED		0x02	// AWB Red gain (00-ff)
#define REG_VREF	0x03	// Pieces of AGC[9:8], VSTOP[1:0], VSTART[1:0]
#define REG_COM1	0x04	/* Control 1 */
#define  COM1_CCIR656		0x40	/* CCIR656 enable */
#define REG_BAVE	0x05	/* U/B Average level */
#define REG_GbAVE	0x06	/* Y/Gb Average level */
#define REG_AECHH	0x07	/* AEC MS 5 bits */
#define REG_RAVE	0x08	/* V/R Average level */
#define REG_COM2	0x09	/* Control 2 */
#define  COM2_SSLEEP		0x10	/* Soft sleep mode */
#define  COM2_OUT_DRIVE_1x	0x00	/* Output drive capability 1x */
#define  COM2_OUT_DRIVE_2x	0x01	/* Output drive capability 2x */
#define  COM2_OUT_DRIVE_3x	0x02	/* Output drive capability 3x */
#define  COM2_OUT_DRIVE_4x	0x03	/* Output drive capability 4x */
#define REG_PID		0x0a	/* Product ID MSB */
#define REG_VER		0x0b	/* Product ID LSB */
#define REG_COM3	0x0c	/* Control 3 */
#define  COM3_SWAP		0x40	/* Byte swap */
#define  COM3_SCALEEN		0x08	/* Enable Scaling */
#define  COM3_DCWEN		0x04	/* Enable Downsampling/Dropping/Windowing */
#define REG_COM4	0x0d	/* Control 4 */
#define  COM4_AEC_FULL		0x00 /* AEC evaluate full window */
#define  COM4_AEC_1_2		0x10 /* AEC evaluate 1/2 window  */
#define  COM4_AEC_1_4		0x20 /* AEC evaluate 1/4 window  */
#define  COM4_AEC_2_3		0x30 /* AEC evaluate 2/3 window  */
#define REG_COM5	0x0e	/* All "reserved" */
#define REG_COM6	0x0f	/* Control 6 */
#define  COM6_BLK_LINE		0x80	// Enable HREF at optional black
#define  COM6_RESET_TIM		0x02	// Reset all timing when format changes
#define  COM6_RESERVE		0x41	// Reserved bit
#define REG_AECH	0x10	/* More bits of AEC value */
#define REG_CLKRC	0x11	/* Clocl control */
#define  CLK_RSVD		0x80	// Reserved
#define  CLK_EXT		0x40	/* Use external clock directly */
#define  CLK_SCALE		0x3f	/* Mask for internal clock scale */
#define REG_COM7	0x12	/* Control 7 */
#define  COM7_RESET		0x80	/* Register reset */
#define  COM7_FMT_MASK		0x38
#define  COM7_FMT_VGA		0x00
#define  COM7_FMT_CIF		0x20	/* CIF format */
#define  COM7_FMT_QVGA		0x10	/* QVGA format */
#define  COM7_FMT_QCIF		0x08	/* QCIF format */
#define  COM7_RGB		0x04	/* bits 0 and 2 - RGB format */
#define  COM7_YUV		0x00	/* YUV */
#define  COM7_BAYER		0x01	/* Bayer format */
#define  COM7_CBAR		0x02	// Color bar
#define  COM7_PBAYER		0x05	/* "Processed bayer" */
#define REG_COM8	0x13	/* Control 8 */
#define  COM8_FASTAEC		0x80	/* Enable fast AGC/AEC */
#define  COM8_AECSTEP		0x40	/* Unlimited AEC step size */
#define  COM8_BFILT		0x20	/* Band filter enable */
#define  COM8_RSVD		0x08	// Reserved fefault 1
#define  COM8_AGC		0x04	/* Auto gain enable */
#define  COM8_AWB		0x02	// Auto White Balance enable
#define  COM8_AEC		0x01	/* Auto exposure enable */
#define REG_COM9	0x14	/* Control 9- gain ceiling */
#define  COM9_AGC_GAIN_2x	0x00 /* Automatic Gain Ceiling 2x  */
#define  COM9_AGC_GAIN_4x	0x10 /* Automatic Gain Ceiling 4x  */
#define  COM9_AGC_GAIN_8x	0x20 /* Automatic Gain Ceiling 8x  */
#define  COM9_AGC_GAIN_16x	0x30 /* Automatic Gain Ceiling 16x */
#define  COM9_AGC_GAIN_32x	0x40 /* Automatic Gain Ceiling 32x */
#define  COM9_AGC_GAIN_64x	0x50 /* Automatic Gain Ceiling 64x  */
#define  COM9_AGC_GAIN_128x	0x60 /* Automatic Gain Ceiling 128x */
#define  COM9_AGC_GAIN_NOT	0x70 /* Automatic Gain Ceiling Not allowed */
#define  COM9_FREEZE_AGC_AEC	0x01
#define REG_COM10	0x15	/* Control 10 */
#define  COM10_HSYNC		0x40	/* HSYNC instead of HREF */
#define  COM10_PCLK_HB		0x20	/* PCLK does not toggle during horizontal blank */
#define  COM10_PCLK_REV 	0x10	// Reverse PCLK
#define  COM10_HREF_REV		0x08	/* Reverse HREF */
#define  COM10_VS_LEAD		0x04	/* VSYNC on clock leading edge */
#define  COM10_VS_NEG		0x02	/* VSYNC negative */
#define  COM10_HS_NEG		0x01	/* HSYNC negative */
#define REG_HSTART	0x17	/* Horiz start high bits */
#define REG_HSTOP	0x18	/* Horiz stop high bits */
#define REG_VSTART	0x19	/* Vert start high bits */
#define REG_VSTOP	0x1a	/* Vert stop high bits */
#define REG_PSHFT	0x1b	/* Pixel delay after HREF */
#define REG_MIDH	0x1c	/* Manuf. ID high */
#define REG_MIDL	0x1d	/* Manuf. ID low */
#define REG_MVFP	0x1e	/* Mirror / vflip */
#define  MVFP_MIRROR		0x20	/* Mirror image */
#define  MVFP_FLIP		0x10	/* Vertical flip */
#define  MVFP_BLACK_SUN		0x04	// black sun enable
#define REG_LAEC	0x1f	// Reserved - Fine AEC Value - defines exposure value less than one row period
#define REG_ADCCTR0	0x20	// ADC range adjustment
#define REG_ADCCTR1	0x21	// Reserved
#define REG_ADCCTR2 	0x22	// Reserved
#define REG_ADCCTR3 	0x23	// Reserved
#define REG_AEW		0x24	/* AGC upper limit */
#define REG_AEB		0x25	/* AGC lower limit */
#define REG_VPT		0x26	/* AGC/AEC fast mode op region */
#define REG_BBIAS	0x27	// B Channel Signal Output Bias
#define REG_GbBIAS	0x28	// Gb Channel Signal Output Bias

#define REG_EXHCH	0x2a	// Dummy Pixel Insert MSB
#define REG_EXHCL	0x2b	// Dummy Pixel Insert LSB
#define REG_RBIAS	0x2c	// R Channel Signal Output Bias
#define REG_ADVFL	0x2d	// LSB of insert dummy rows in vertical direction (1 bit equals 1 row)
#define REG_ADVFH	0x2e	// MSB of insert dummy rows in vertical direction
#define REG_YAVE	0x2f	// Y/G Channel Average Value
#define REG_HSYST	0x30	/* HSYNC rising edge delay */
#define REG_HSYEN	0x31	/* HSYNC falling edge delay */
#define REG_HREF	0x32	/* HREF pieces */
#define REG_CHLF	0x33	// Array Current Control	 ( Reserved )
#define REG_ARBLM	0x34	// Array Referrence Control	 ( Reserved )
#define REG_ADC		0x37	// ADC Control				 ( Reserved )
#define REG_ACOM	0x38	// ADC and Analog Common MOde  Control ( Reserved )
#define REG_OFON	0x39	// Reserved - ADC Offset Control ( Reserved )
#define REG_TSLB	0x3a	// Line Buffer Test Option
#define  TSLB_NEGATE		0x20	// Negative image - see MANU & MANV
#define  TSLB_UVOUT		0x10	// Use fixed UV value
#define  TSLB_YLAST		0x08	/* UYVY or VYUY - see com13 */
#define  TSLB_AUTO		0x01	// Auto output window
#define REG_COM11	0x3b	/* Control 11 */
#define  COM11_NIGHT		0x80	/* NIght mode enable */
#define  COM11_NMFR		0x60	/* Two bit NM frame rate */
#define  COM11_FR_BY_2		0x20	// 1/2 of normal mode frame rate
#define  COM11_FR_BY_4		0x40	// 1/4 of normal mode frame rate
#define  COM11_FR_BY_8		0x60	// 1/8 of normal mode frame rate
#define  COM11_HZAUTO		0x10	/* Auto detect 50/60 Hz */
#define  COM11_50HZ		0x08	/* Manual 50Hz select */
#define  COM11_EXP		0x02	// Exposure timing can be less than limit of banding filter when light is too strong
#define REG_COM12	0x3c	/* Control 12 */
#define  COM12_HREF		0x80	/* HREF always */
#define  COM12_RSVD		0x68	// reserved bit
#define REG_COM13	0x3d	/* Control 13 */
#define  COM13_GAMMA		0x80	/* Gamma enable */
#define  COM13_UVSAT		0x40	/* UV saturation auto adjustment */
#define  COM13_UVSWAP		0x01	/* V before U - w/TSLB */
#define  COM13_RESV		0x08	// reserved bit
#define REG_COM14	0x3e	/* Control 14 */
#define  COM14_DCWEN		0x10	// DCW/PCLK-scale enable */
#define  COM14_MANUAL		0x08	// Manual scaling enable
#define  COM14_PCLKDIV_1	0x00	// PCLK Divided by 1
#define  COM14_PCLKDIV_2	0x01	// PCLK Divided by 2
#define  COM14_PCLKDIV_4	0x02	// PCLK Divided by 4
#define  COM14_PCLKDIV_8	0x03	// PCLK Divided by 8
#define  COM14_PCLKDIV_16	0x04	// PCLK Divided by 16
#define REG_EDGE	0x3f	/* Edge enhancement factor */
#define REG_COM15	0x40	/* Control 15 */
#define  COM15_R10F0		0x00	/* Data range 10 to F0 */
#define  COM15_R01FE		0x80	/*			01 to FE */
#define  COM15_R00FF		0xc0	/*			00 to FF */
#define  COM15_RGB565		0x10	/* RGB565 output */
#define  COM15_RGB555		0x30	/* RGB555 output */
#define REG_COM16	0x41	/* Control 16 */
#define  COM16_YUV_ENHANC	0x20
#define  COM16_DE_NOISE		0x10	//
#define  COM16_AWBGAIN		0x08	/* AWB gain enable */
#define REG_COM17	0x42	/* Control 17 */
#define  COM17_AECWIN		0xc0	/* AEC window - must match COM4 */
#define  COM17_AEC_FULL		0x00	/* AEC evaluate full window */
#define  COM17_AEC_1_2		0x40	/* AEC evaluate 1/2 window  */
#define  COM17_AEC_1_4		0x80	/* AEC evaluate 1/4 window  */
#define  COM17_AEC_2_3		0xC0	/* AEC evaluate 2/3 window  */
#define  COM17_CBAR			0x08	/* DSP Color bar */

#define REG_AWBC1	0x43	// AWB Control 1 (Reserved ?)
#define REG_AWBC2	0x44	// AWB Control 2 (Reserved ?)
#define REG_AWBC3	0x45	// AWB Control 3 (Reserved ?)
#define REG_AWBC4	0x46	// AWB Control 4 (Reserved ?)
#define REG_AWBC5	0x47	// AWB Control 5 (Reserved ?)
#define REG_AWBC6	0x48	// AWB Control 6 (Reserved ?)

#define REG_4B		0x4b	// UV average ebnable
#define  UV_AVR_EN 		0x01	// UV average enable
#define REG_DNSTH	0x4c	// De-noise Threshold
//#define REG_DM_POS	0x4d	// Reserved - Dummy row position
/*
#define	REG_CMATRIX_BASE 0x4f
#define   CMATRIX_LEN 6
#define REG_CMATRIX_SIGN 0x58
*/
#define REG_MTX1	0x4f	/* Matrix Coefficient 1 */
#define REG_MTX2	0x50	/* Matrix Coefficient 2 */
#define REG_MTX3	0x51	/* Matrix Coefficient 3 */
#define REG_MTX4	0x52	/* Matrix Coefficient 4 */
#define REG_MTX5	0x53	/* Matrix Coefficient 5 */
#define REG_MTX6	0x54	/* Matrix Coefficient 6 */

#define REG_BRIGHT	0x55	/* Brightness */
#define REG_CONTRAS	0x56	/* Contrast control */
#define REG_CONTRAS_CENTER 0x57	// Contrast Center
#define REG_MTXS	0x58	/* Matrix Coefficient Sign */
#define REG_AWBC7	0x59	// AWB Control 7
#define REG_AWBC8	0x5a	// AWB Control 8
#define REG_AWBC9	0x5b	// AWB Control 9
#define REG_AWBC10	0x5c	// AWB Control 10
#define REG_AWBC11	0x5d	// AWB Control 11
#define REG_AWBC12	0x5e	// AWB Control 12
#define REG_B_LMT	0x5f	// AWB B Gain Range
#define REG_R_LMT	0x60	// AWB R Gain Range
#define REG_G_LMT	0x61	// AWB G Gain Range
#define REG_LCC1	0x62	// Lens Correction Option 1 - X Coordinate
#define REG_LCC2	0x63	// Lens Correction Option 2 - Y Coordinate
#define REG_LCC3	0x64	// Lens Correction Option 3
#define REG_LCC4	0x65	// Lens Correction Option 4
#define REG_LCC5	0x66	// Lens Correction Control
#define REG_MANU	0x67	// Manual U Value
#define REG_MANV	0x68	// Manual V Value
#define REG_GFIX	0x69	// AWB Pre gain control
#define REG_GGAIN	0x6a	/* G Channel AWB Gain */
#define REG_DBLV	0x6b	// PLL control,Regulator control
#define  DBLV_BYPASS		0x00	// Bypass PLL
#define  DBLV_CLK_x4		0x40	// input clock x4
#define  DBLV_CLK_x6		0x80	// input clock x6
#define  DBLV_CLK_x8		0xC0	// input clock x8
#define  DBLV_RSVD		0x0A	// reserved bit
#define REG_AWBCTR3	0x6c	/* AWB Control 3 */
#define REG_AWBCTR2	0x6d	/* AWB Control 2 */
#define REG_AWBCTR1	0x6e	/* AWB Control 1 */
#define REG_AWBCTR0	0x6f	/* AWB Control 0 */
#define REG_SCALING_XSC	0x70	// test pattern, Horizontal scale factor
#define REG_SCALING_YSC	0x71	// test pattern, Vertical scale factor
#define REG_SCALING_DCWCTR 0x72	// DCW Control
#define  SCALING_DCWCTR_VDS_by_2	0x10	// Vertical Down Sampling rate by 2
#define  SCALING_DCWCTR_VDS_by_4	0x20	// Vertical Down Sampling rate by 4
#define  SCALING_DCWCTR_VDS_by_8	0x30	// Vertical Down Sampling rate by 8
#define  SCALING_DCWCTR_HDS_by_2	0x01	// Horizontal Down Sampling rate by 2
#define  SCALING_DCWCTR_HDS_by_4	0x02	// Horizontal Down Sampling rate by 2
#define  SCALING_DCWCTR_HDS_by_8	0x03	// Horizontal Down Sampling rate by 2

#define REG_SCALING_PCLK_DIV 0x73	// Clock divider control for DSP scale
#define  SCALING_PCLK_DIV_RSVD		0xf0	// Reserved
#define  SCALING_PCLK_DIV_DIS		0x08	// Bypass clock divider
#define  SCALING_PCLK_DIV_1		0x00	// Divided by 1
#define  SCALING_PCLK_DIV_2		0x01	// Divided by 2
#define  SCALING_PCLK_DIV_4		0x02	// Divided by 4
#define  SCALING_PCLK_DIV_8		0x03	// Divided by 8
#define  SCALING_PCLK_DIV_16		0x04	// Divided by 16
#define REG_REG74	0x74	// Digital gain manual control
#define REG_REG75	0x75	// Edge enhanced lower limit
#define REG_REG76	0x76	/* OV's name */
#define  R76_BLKPCOR		0x80	/* Black pixel correction enable */
#define  R76_WHTPCOR		0x40	/* White pixel correction enable */
#define REG_REG77	0x77	// Offset, de-noise range control
// 0x7a - 0x89 Ganma Curve registor
#define REG_SLOP	0x7a	// SLOP = (256-GAM15)x40/30
#define REG_GAM1	0x7b	// XREF1 4
#define REG_GAM2	0x7c	// XREF2 8
#define REG_GAM3	0x7d	// XREF3 16
#define REG_GAM4	0x7e	// XREF4 32
#define REG_GAM5	0x7f	// XREF5 40
#define REG_GAM6	0x80	// XREF6 48
#define REG_GAM7	0x81	// XREF7 56
#define REG_GAM8	0x82	// XREF8 64
#define REG_GAM9	0x83	// XREF9 72
#define REG_GAM10	0x84	// XREF10 80
#define REG_GAM11	0x85	// XREF11 96
#define REG_GAM12	0x86	// XREF12 112
#define REG_GAM13	0x87	// XREF13 144
#define REG_GAM14	0x88	// XREF14 176
#define REG_GAM15	0x89	// XREF15 208

#define REG_RGB444	0x8c	/* RGB 444 control */
#define  R444_DISABLE		0x00
#define  R444_ENABLE		0x02	/* Turn on RGB444, overrides 5x5 */
#define  R444_RGBX		0x01	/* Empty nibble at end */
#define REG_DM_LNL	0x92	// Dummy Row low 8bit
#define REG_DM_LNH	0x93	// Dummy Row high 8bit
#define REG_LCC6	0x94	// Lens Correction Optin 6
#define REG_LCC7	0x95	// Lens Correction Optin 7

#define REG_BD50ST	0x9d	// 50Hz Banding Filter Value
#define REG_BD60ST	0x9e	// 60Hz Banding Filter Value

#define REG_HAECC1	0x9f	// Hist AEC/AGC control 1
#define REG_HAECC2	0xa0	// Hist AEC/AGC control 2
/*
#define REG_HRL		0x9f	// High Reference Luminance
#define REG_LRL		0xa0	// Low Reference Luminance
#define REG_DSPC3	0xa1	// DSP Control 3
*/
#define REG_SCALING_PCLK_DELAY	0xa2	// Pixel Clock Delay

#define REG_NT_CTRL	0xa4	// Auto frame rate adjustment
#define	 NT_CTRL_ROWPF		0x08	// Auto frame rate adjust dummy row per frame
#define  NT_CTRL_DMR_2x		0x00	// insert dummy row at 2x gain
#define  NT_CTRL_DMR_4x		0x01	// insert dummy row at 4x gain
#define  NT_CTRL_DMR_8x		0x02	// insert dummy row at 28 gain

#define REG_BD50MAX	0xa5	// 50hz banding step limit
#define REG_HAECC3	0xa6	// Hist AEC/AGC control 3
#define REG_HAECC4	0xa7	// Hist AEC/AGC control 4
#define REG_HAECC5	0xa8	// Hist AEC/AGC control 5
#define REG_HAECC6	0xa9	// Hist AEC/AGC control 6
#define REG_HAECC7	0xaa	// Hist AEC/AGC control 7
#define REG_BD60MAX	0xab	// 60hz banding step limit

/*
#define REG_AECGMAX	0xa5	// Maximum Banding Filter Step
#define REG_LPH		0xa6	// Low Limit of Probability for HRL
#define REG_UPL		0xa7	// Upper Limit of Probability for LRL
#define REG_TPL		0xa8	// Probablility Threshold for LRL to control AEC/AGC speed
#define REG_TPH		0xa9	// Probablility Threshold for HRL to control AEC/AGC speed
#define REG_NALG	0xaa	// AEC Algorithm selection
*/

#define REG_STR_OPT	0xac	// R/G/B gain control
#define REG_STR_R	0xad	// R Gain for LED Output Frame
#define REG_STR_G	0xae	// G Gain for LED Output Frame
#define REG_STR_B	0xaf	// B Gain for LED Output Frame

#define REG_ABLC1	0xb1	// ABLC enable
#define  ABLC1_EN		0x04	// ABLC enable
#define REG_THL_ST	0xb3	// ABLC Target
#define REG_THL_DLT	0xb5	// ABLC Stable Range
#define REG_AD_CHB	0xbe	// Blue Channel Black Level Compensation
#define REG_AD_CHR	0xbf	// Red Channel Black Level Compensation
#define REG_AD_CHGb	0xc0	// Gb Channel Black Level Compensation
#define REG_AD_CHGr	0xc1	// Gr Channel Black Level Compensation
#define REG_SATCTR	0xc9	// Saturation Control



#endif
