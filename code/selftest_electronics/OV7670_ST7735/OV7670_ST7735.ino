//*************************************************************************
//	OV7670 (non FIFO) Sample program for ESP32 
//
//  OUTPUT:	ILI9341 TFT(320x240) SPI 
//					option XPT2046 Touchscreen
//
//*************************************************************************

/*************************************************************
 * 
 * Libraries
 * 
*************************************************************/

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_PWMServoDriver.h>
#include "OV7670.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <Adafruit_ST77xx.h> // Hardware-specific library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789

/*************************************************************
 * 
 * HC-SR04 Ultrasonic Range Sensor
 * 
*************************************************************/

#define SONAR_TRIG_LEFT   2
#define SONAR_ECHO_LEFT   15

long sonar_duration_left = 0;
long sonar_distance_left = 0;

/*************************************************************
 * 
 * HC-SR04 Ultrasonic Range Sensor
 * 
*************************************************************/

#define SONAR_TRIG_RIGHT   2
#define SONAR_ECHO_RIGHT   16

long sonar_duration_right = 0;
long sonar_distance_right = 0;

/*************************************************************
 * 
 * HW-482 5V Relais
 * 
*************************************************************/

#define RELAIS   13

bool RELAIS_STATE = false;


/*************************************************************
 * 
 * 1.77" TFT with LED Backlight
 * 
*************************************************************/

// For the Adafruit shield, these are the default.
/*const int TFT_RS = 5;
const int TFT_CS = 17; 
const int TFT_SDA = 18; 
const int TFT_SCL = 19; 
#define TFT_LED   16*/
const int TFT_RS = 17;
const int TFT_CS = 5; //HW SPI
const int TFT_SDA = 23; //HW SPI
const int TFT_SCL = 18; //HW SPI
#define TFT_LED   19
#define TFT_RES   -1  // Reset physicaly connected to EN (enabled), -1 required by TFT library

const int TFT_LED_PWM_CHANNEL     = 5;
const int TFT_LED_PWM_RESOLUTION  = 8;
const int TFT_LED_PWM_FREQUENCY   = 5000;
      int TFT_LED_PWM_DUTY        = 255;

/*************************************************************
 * 
 * POWER BUTTON with integrated LED
 * 
*************************************************************/

#define PWR_BTN       4
#define PWR_BTN_LED   0 // PWM during boot wont do anything, since RTC GPIO -> used as External Wake Up (ext0)

int PWR_BTN_STATE = 0;

const int PWR_BTN_LED_PWM_CHANNEL     = 4;
const int PWR_BTN_LED_PWM_RESOLUTION  = 8;
const int PWR_BTN_LED_PWM_FREQUENCY   = 5000;
      int PWR_BTN_LED_PWM_DUTY        = 255;

/*************************************************************
 * 
 * OV7670 Camera Module without FIFO
 * 
*************************************************************/
uint16_t *buf;

const camera_config_t cam_conf = {
	.D0	= 36,
	.D1 = 39,
	.D2 = 34,
	.D3 = 35,
	.D4 = 32,
	.D5 = 33,
	.D6 = 25,
	.D7 = 26,
	.XCLK = 12,
	.PCLK = 14,
	.VSYNC = 27,
	.xclk_freq_hz = 12000000,			// XCLK 10MHz
	.ledc_timer		= LEDC_TIMER_0,
	.ledc_channel = LEDC_CHANNEL_0	
};
//	SSCB_SDA(SIOD) 	--> 21(ESP32)
//	SSCB_SCL(SIOC) 	--> 22(ESP32)
//	RESET   --> 3.3V
//	PWDN		--> GND
//	HREF		--> NC

/*************************************************************
 * 
 * GY-521 Gyroscope/Acceleration Sensor (front)
 * 
*************************************************************/

bool GYRO_FRONT_STATE = false;

int16_t gyro_front_acx = 0;
int16_t gyro_front_acy = 0;
int16_t gyro_front_acz = 0;

int16_t gyro_front_gyx = 0;
int16_t gyro_front_gyy = 0;
int16_t gyro_front_gyz = 0;

int16_t gyro_front_tmp = 0;

/*************************************************************
 * 
 * GY-521 Gyroscope/Acceleration Sensor (rear)
 * 
*************************************************************/

bool GYRO_REAR_STATE = false;

int16_t gyro_rear_acx = 0;
int16_t gyro_rear_acy = 0;
int16_t gyro_rear_acz = 0;

int16_t gyro_rear_gyx = 0;
int16_t gyro_rear_gyy = 0;
int16_t gyro_rear_gyz = 0;

int16_t gyro_rear_tmp = 0;

/*************************************************************
 * 
 * PCA9685 12Bit 16Ch PWM-Servomodule
 * 
*************************************************************/

bool PWM_SERVO_STATE = false;

/*************************************************************
 * 
 * I2C TwoWire
 * 
*************************************************************/

#define I2C_SCL   22
#define I2C_SDA   21
#define I2C_FRQ   400000

bool I2C_STATE = false;

/*************************************************************
 * 
 * I2C Adresses
 * 
*************************************************************/

#define PWM_SERVO_ADDR    0x40

#define GYRO_FRONT_ADDR   0x68
#define GYRO_REAR_ADDR    0x69  // ad0 pin connected to 3v3

#define CAM_WRITE_ADDR    0x42
#define CAM_READ_ADDR     0x43

/*************************************************************
 * 
 * Objects
 * 
*************************************************************/

//TwoWire I2C = TwoWire(0);

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_RS, TFT_SDA, TFT_SCL, 0);
//Adafruit_ST7735 TFT = Adafruit_ST7735(TFT_CS, TFT_RS, TFT_SDA, TFT_SCL, TFT_RES);
//Adafruit_PWMServoDriver PWM = Adafruit_PWMServoDriver(PWM_SERVO_ADDR, I2C);
Adafruit_PWMServoDriver PWM = Adafruit_PWMServoDriver(PWM_SERVO_ADDR);
OV7670 cam;						// camera

/*************************************************************
 * 
 * Other
 * 
*************************************************************/

int pos = 0;
int duty = 0;

/*************************************************************
 * 
 * ### SETUP ###
 * 
*************************************************************/

void setup() {

  /*************************************************************
   * 
   * PinModes
   * 
  *************************************************************/

  // HC-SR04 Ultrasonic Range Sensor
  pinMode(SONAR_TRIG_LEFT, OUTPUT);
  pinMode(SONAR_ECHO_LEFT, INPUT);

  pinMode(SONAR_TRIG_RIGHT, OUTPUT);
  pinMode(SONAR_ECHO_RIGHT, INPUT);

  // HW-482 5V Relais
  pinMode(RELAIS, OUTPUT);

  // 1.77" TFT with LED Backlight
  pinMode(TFT_LED, OUTPUT);
  ledcSetup(TFT_LED_PWM_CHANNEL, TFT_LED_PWM_FREQUENCY, TFT_LED_PWM_RESOLUTION);
  ledcAttachPin(TFT_LED,TFT_LED_PWM_CHANNEL);

  // POWER BUTTON with integrated LED
  pinMode(PWR_BTN_LED, OUTPUT);
  pinMode(PWR_BTN, INPUT_PULLDOWN);
  ledcSetup(PWR_BTN_LED_PWM_CHANNEL, PWR_BTN_LED_PWM_FREQUENCY, PWR_BTN_LED_PWM_RESOLUTION);
  ledcAttachPin(PWR_BTN_LED,PWR_BTN_LED_PWM_CHANNEL);

  /*************************************************************
   * 
   * I2C
   * 
  *************************************************************/

  Wire.begin(21, 22);
  Wire.begin();
  Wire.setClock(400000);

  // Initialize I2C Bus
  
  //I2C_STATE = I2C.begin(I2C_SDA, I2C_SCL, I2C_FRQ);

  // 12-Bit 16 Channel PWM Module

  PWM.begin();
  PWM.setPWMFreq(50);

  // Gyroscopes
/*
  I2C.beginTransmission(GYRO_FRONT_ADDR);
  I2C.write(0x6B);  // PWR_MGMT_1 register
  I2C.write(0);     // set to zero (wakes up the MPU-6050)
  I2C.endTransmission(true);

  I2C.beginTransmission(GYRO_REAR_ADDR);
  I2C.write(0x6B);  // PWR_MGMT_1 register
  I2C.write(0);     // set to zero (wakes up the MPU-6050)
  I2C.endTransmission(true);
*/
    Wire.beginTransmission(GYRO_FRONT_ADDR);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);

  Wire.beginTransmission(GYRO_REAR_ADDR);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);

  /*************************************************************
   * 
   * 1.77" TFT with background illumination
   * 
  *************************************************************/
  tft.initSPI(40000000);
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);

  /*************************************************************
   * 
   * Serial Output
   * 
  *************************************************************/

  Serial.begin(115200);
  Serial.println("< ESP32 DevKitC is ready >");
  Serial.println("");

  // I2C
  /*
  Serial.print("I2C Initialization: ");
  if(I2C_STATE){
    Serial.println("PASSED");
  } else {
    Serial.println("FAILED");
  }*/
	
  Serial.println("OV7670 camera Init...");     
  esp_err_t err = cam.init(&cam_conf, QQVGA, RGB565);		// カメラを初期化
  //esp_err_t err = cam.init(&cam_conf, QQCIF, RGB565);    // カメラを初期化
	if(err != ESP_OK)		Serial.println("cam.init ERROR");

	cam.setPCLK(2, DBLV_CLK_x4);	// PCLK 設定 : 10MHz / (pre+1) * 4 --> 13.3MHz  
	cam.vflip( false );		// 画面１８０度回転
 
  Serial.printf("cam MID = %X\n\r",cam.getMID());
  Serial.printf("cam PID = %X\n\r",cam.getPID());

//	cam.colorbar(true);			// カラーバーを表示する場合

}

void loop(void) {
    Serial.println("Making LED glow (TFT & PWR)");
  ledcWrite(TFT_LED_PWM_CHANNEL, TFT_LED_PWM_DUTY);
  ledcWrite(PWR_BTN_LED_PWM_CHANNEL, PWR_BTN_LED_PWM_DUTY);
  Serial.println("Starting Loop");

	while(1){
		for( int y = 0; y < 40; y++){			
			buf = cam.getLine( (y*3)+1 );								// カメラから１ライン分読み込む LineNo(1~240)
			tft.drawRGBBitmap( 0, y*3, buf, 160, 1);	// TFT に１ライン出力
  	}
   for( int y = 0; y < 40; y++){     
      buf = cam.getLine( (y*3)+2 );               // カメラから１ライン分読み込む LineNo(1~240)
      tft.drawRGBBitmap( 0, y*3+1, buf, 160, 1);  // TFT に１ライン出力
    }
    for( int y = 0; y < 40; y++){     
      buf = cam.getLine( (y*3)+3 );               // カメラから１ライン分読み込む LineNo(1~240)
      tft.drawRGBBitmap( 0, y*3+2, buf, 160, 1);  // TFT に１ライン出力
    }    
    
    // put your main code here, to run repeatedly:
     Serial.println("Reading Gyro");
  readGyro();
  Serial.println("Reading Sonar");
  readSonar();
  Serial.println("Printing Status Screen");
  printStatusScreen();
  Serial.println("Checking for Serial Input");
  checkSerialInput();
  Serial.println("Doing the PWM Servo Magic");
  writePWM();

// ### TESTING FROM HERE ###


Serial.println("Reading Power Button Input");
  readPowerButton();
	}
 }

/* void readGyro() {
  Serial.println("### READING GYRO SENSORS ###");
  
  // GYRO FRONT
  I2C.beginTransmission(GYRO_FRONT_ADDR);
  I2C.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  I2C.endTransmission(false);
  I2C.requestFrom(GYRO_FRONT_ADDR,14,true);  // request a total of 14 registers
  gyro_front_acx=I2C.read()<<8|I2C.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  gyro_front_acy=I2C.read()<<8|I2C.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  gyro_front_acz=I2C.read()<<8|I2C.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  gyro_front_tmp=I2C.read()<<8|I2C.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  gyro_front_gyx=I2C.read()<<8|I2C.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  gyro_front_gyy=I2C.read()<<8|I2C.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  gyro_front_gyz=I2C.read()<<8|I2C.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  Serial.print("Front: AcX = "); Serial.print(gyro_front_acx);
  Serial.print(" | AcY = "); Serial.print(gyro_front_acy);
  Serial.print(" | AcZ = "); Serial.print(gyro_front_acz);
  Serial.print(" | Tmp = "); Serial.print(gyro_front_tmp/340.00+36.53);  //equation for temperature in degrees C from datasheet
  Serial.print(" | GyX = "); Serial.print(gyro_front_gyx);
  Serial.print(" | GyY = "); Serial.print(gyro_front_gyy);
  Serial.print(" | GyZ = "); Serial.println(gyro_front_gyz);
  delay(333);

  // GYRO REAR
  I2C.beginTransmission(GYRO_REAR_ADDR);
  I2C.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  I2C.endTransmission(false);
  I2C.requestFrom(GYRO_REAR_ADDR,14,true);  // request a total of 14 registers
  gyro_rear_acx=I2C.read()<<8|I2C.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  gyro_rear_acy=I2C.read()<<8|I2C.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  gyro_rear_acz=I2C.read()<<8|I2C.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  gyro_rear_tmp=I2C.read()<<8|I2C.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  gyro_rear_gyx=I2C.read()<<8|I2C.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  gyro_rear_gyy=I2C.read()<<8|I2C.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  gyro_rear_gyz=I2C.read()<<8|I2C.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  Serial.print("Rear:  AcX = "); Serial.print(gyro_rear_acx);
  Serial.print(" | AcY = "); Serial.print(gyro_rear_acy);
  Serial.print(" | AcZ = "); Serial.print(gyro_rear_acz);
  Serial.print(" | Tmp = "); Serial.print(gyro_rear_tmp/340.00+36.53);  //equation for temperature in degrees C from datasheet
  Serial.print(" | GyX = "); Serial.print(gyro_rear_gyx);
  Serial.print(" | GyY = "); Serial.print(gyro_rear_gyy);
  Serial.print(" | GyZ = "); Serial.println(gyro_rear_gyz);
  delay(333);

  Serial.println();
}
*/

void readGyro() {
  Serial.println("### READING GYRO SENSORS ###");
  
  // GYRO FRONT
  Wire.beginTransmission(GYRO_FRONT_ADDR);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(GYRO_FRONT_ADDR,14,true);  // request a total of 14 registers
  gyro_front_acx=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  gyro_front_acy=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  gyro_front_acz=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  gyro_front_tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  gyro_front_gyx=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  gyro_front_gyy=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  gyro_front_gyz=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  Serial.print("Front: AcX = "); Serial.print(gyro_front_acx);
  Serial.print(" | AcY = "); Serial.print(gyro_front_acy);
  Serial.print(" | AcZ = "); Serial.print(gyro_front_acz);
  Serial.print(" | Tmp = "); Serial.print(gyro_front_tmp/340.00+36.53);  //equation for temperature in degrees C from datasheet
  Serial.print(" | GyX = "); Serial.print(gyro_front_gyx);
  Serial.print(" | GyY = "); Serial.print(gyro_front_gyy);
  Serial.print(" | GyZ = "); Serial.println(gyro_front_gyz);
  delay(333);

  // GYRO REAR
  Wire.beginTransmission(GYRO_REAR_ADDR);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(GYRO_REAR_ADDR,14,true);  // request a total of 14 registers
  gyro_rear_acx=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  gyro_rear_acy=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  gyro_rear_acz=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  gyro_rear_tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  gyro_rear_gyx=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  gyro_rear_gyy=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  gyro_rear_gyz=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  Serial.print("Rear:  AcX = "); Serial.print(gyro_rear_acx);
  Serial.print(" | AcY = "); Serial.print(gyro_rear_acy);
  Serial.print(" | AcZ = "); Serial.print(gyro_rear_acz);
  Serial.print(" | Tmp = "); Serial.print(gyro_rear_tmp/340.00+36.53);  //equation for temperature in degrees C from datasheet
  Serial.print(" | GyX = "); Serial.print(gyro_rear_gyx);
  Serial.print(" | GyY = "); Serial.print(gyro_rear_gyy);
  Serial.print(" | GyZ = "); Serial.println(gyro_rear_gyz);
  delay(333);

  Serial.println();
}

void readSonar(){
  Serial.println("### READING ULTRASONIC SENSOR LEFT ###");
  
  digitalWrite(SONAR_TRIG_LEFT, LOW);
  delayMicroseconds(5);
  digitalWrite(SONAR_TRIG_LEFT, HIGH);
  delayMicroseconds(10);
  digitalWrite(SONAR_TRIG_LEFT, LOW);

  sonar_duration_left = pulseIn(SONAR_ECHO_LEFT, HIGH);
  sonar_duration_left = (sonar_duration_left/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  Serial.print(sonar_duration_left);
  Serial.println("cm");

  Serial.println();

  delay(200);

  Serial.println("### READING ULTRASONIC SENSOR RIGHT ###");
  
  digitalWrite(SONAR_TRIG_RIGHT, LOW);
  delayMicroseconds(5);
  digitalWrite(SONAR_TRIG_RIGHT, HIGH);
  delayMicroseconds(10);
  digitalWrite(SONAR_TRIG_RIGHT, LOW);

  sonar_duration_right = pulseIn(SONAR_ECHO_RIGHT, HIGH);
  sonar_duration_right = (sonar_duration_right/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  Serial.print(sonar_duration_right);
  Serial.println("cm");

  Serial.println();
}

void readPowerButton(){
  PWR_BTN_STATE = digitalRead(PWR_BTN);
  if (PWR_BTN_STATE == HIGH) {
    RELAIS_STATE = !RELAIS_STATE;
    Serial.println("Pushbutton HIGH");
    Serial.print("Relais-State at: ");
    Serial.println(RELAIS_STATE);
  }
  if (PWR_BTN_STATE == LOW) {
    Serial.println("Pushbutton LOW");
  }
  delay(100);
  
  if (RELAIS_STATE == false) {
  Serial.println("Relais-Pin LOW");
  digitalWrite(RELAIS, LOW);
  }
  else {
  Serial.println("Relais-Pin HIGH");
  digitalWrite(RELAIS, HIGH);
  }
}

void printStatusScreen(){
  tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);

  tft.drawRect(1, 1, 157, 13, ST77XX_WHITE);
  tft.setCursor(3,3);
  tft.println("SpotMicroAIoT");

  tft.drawRect(1, 15, 157, 110, ST77XX_WHITE);
  tft.setCursor(3, 17);
  tft.println("by MiKu");
}

void checkSerialInput(){
    if (Serial.available() > 0) {
      char symbol = Serial.read();
      Serial.print(symbol);
    switch (symbol) {
      case 'e':
        RELAIS_STATE = true;
        break;
      case 'q':
        RELAIS_STATE = false;
        break;
      case 'a':
        pos = 0;
        break;
      case 's':
        pos = 90;
        break;
      case 'd':
        pos = 180;
        break;
      case 'w':
      if (pos < 180) {
        pos += 15;
      }
        break;
      case 'x':
        if (pos > 0) {
        pos -= 15;
      }
        break;
    }
  }
}

void writePWM(){
  PWM.setPWM(0, 0, pos+75);
  PWM.setPWM(1, 0, pos+175);
  PWM.setPWM(2, 0, pos+75);
}

void SetServoPos(float pos)
{
    uint32_t duty = ((400.0/180.0)*pos) + 75;
         // convert 0-180 degrees to 0-4096

        // set channel to pos
        Serial.print("Duty: ");
   Serial.println(duty);
}
