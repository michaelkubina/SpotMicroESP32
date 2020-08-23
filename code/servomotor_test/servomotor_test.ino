//***********
// Servo motor test
// SDA - pin next to GND - 21
// SCL - 22
//************


#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define MIN_PULSE   140
#define ANGLE_FACTOR  1

#define PWM_SERVO_ADDR    0x40
Adafruit_PWMServoDriver PWM = Adafruit_PWMServoDriver(PWM_SERVO_ADDR);

int pos = MIN_PULSE;



// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // 12-Bit 16 Channel PWM Module

  PWM.begin();
  PWM.setPWMFreq(50);

  Serial.begin(115200);
  Serial.println("< ESP32 FireBeetle ESP32 Ready >");
  Serial.println("");
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second

  checkSerialInput();
  writePWM();
}

void checkSerialInput(){
    if (Serial.available() > 0) {
      char symbol = Serial.read();
      Serial.print(symbol);
    switch (symbol) {
      case '0':
        pos = 0;
        break;
      case '3':
        pos = 30;
        break;
      case '9':
        pos = 90;
        break;
      case '5':
        pos = 150;
        break;
      case '8':
        pos = 180;
        break;
      case '+':
        pos += 5;
        break;
      case '-':
        pos -= 5;
        break;
    }
  }
}

void writePWM(){
  
  Serial.print("Pos ");
  Serial.print(pos);
  Serial.print(" -> ");
  Serial.println(pos);
  PWM.setPWM(0, 0, pos);

//    PWM.setPWM(0, 0, MIN_PULSE + int(0 * ANGLE_FACTOR));
//    delay(500);  
//    
//    PWM.setPWM(0, 0, MIN_PULSE + int(45 * ANGLE_FACTOR));
//    delay(500);  
}
