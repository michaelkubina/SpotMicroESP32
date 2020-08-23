#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define PWM_SERVO_ADDR    0x40

#define Servo_Foot     0
#define Servo_Leg      1
#define Servo_Shoulder 2

#define FL  0 // 0, 1, 2
#define FR  1 // 3, 4, 5
#define RL  2 // 6, 7, 8
#define RR  3 // 9, 10, 11

typedef struct 
{
  uint16_t pulse_0; // 0 degrees
  uint16_t pulse_180; // 110 degrees
  float degree2pulse;
  uint8_t sleep_angle;
  uint8_t min_angle;
  uint8_t max_angle;
} ServoSettings_t;

typedef LegAngles_t uint8_t[3];  

const char delim[2] = " "; 

const ServoSettings_t servoSettings[12] = {
                             {150, 150, 0, 0, 0, 0},          // Front Left Foot
                             {150, 150, 0, 0, 0, 0},          // Front Left Leg
                             {150, 150, 0, 0, 0, 0},          // Front Left Shoulder
                             {150, 150, 0, 0, 0, 0},          // Front Right Foot
                             {150, 150, 0, 0, 0, 0},          // Front Right Leg
                             {150, 150, 0, 0, 0, 0},          // Front Right Shoulder
                             {125, 420, 1.640, 0, 0, 180},    // Rear Left Foot
                             {75, 465, 2.167, 150, 0, 280},   // Rear Left Leg
                             {130, 460, 1.833, 90, 60, 120},  // Rear Left Shoulder
                             {145, 515, 2.06, 180, 0, 180},   // Rear Right foot
                             {140, 440, 1.667, 30, 0, 180},   // Rear Right Leg
                             {120, 410, 1.611, 90, 60, 112},  // Rear Right Shoulder};                    

LegAngles_t legAngles[4] = {{servoSettings[0].sleep_angle, servoSettings[1].sleep_angle, servoSettings[2].sleep_angle},
                            {servoSettings[3].sleep_angle, servoSettings[4].sleep_angle, servoSettings[5].sleep_angle},
                            {servoSettings[6].sleep_angle, servoSettings[7].sleep_angle, servoSettings[8].sleep_angle},
                            {servoSettings[9].sleep_angle, servoSettings[10].sleep_angle, servoSettings[11].sleep_angle}};

char *command_token;

Adafruit_PWMServoDriver PWM = Adafruit_PWMServoDriver(PWM_SERVO_ADDR);


void setup() {
  // status led on board
  pinMode(LED_BUILTIN, OUTPUT);

  // 12-Bit 16 Channel PWM Module
  PWM.begin();
  PWM.setPWMFreq(50);

  // Serial for debvug
  Serial.begin(115200);
  Serial.println("SpotMicro Ready");
  Serial.println("");

}

void loop() {
  // put your main code here, to run repeatedly:
  checkSerialInput();
  controlServos();
}


void resolveCommand(char* command) {
  switch (command) {
    case "wake":
      legAngles[0][0] = 90;
      legAngles[0][1] = 120;
      legAngles[0][2] = 90;
      legAngles[1][0] = 90;
      legAngles[1][1] = 60;
      legAngles[1][2] = 90;
      legAngles[2][0] = 90;
      legAngles[2][1] = 120;
      legAngles[2][2] = 90;
      legAngles[3][0] = 90;
      legAngles[3][1] = 60;
      legAngles[3][2] = 90;
      break;
    case "sleep":
      legAngles[0][0] = servoSettings[0].sleep_angle;
      legAngles[0][1] = servoSettings[1].sleep_angle;
      legAngles[0][2] = servoSettings[2].sleep_angle;
      legAngles[1][0] = servoSettings[3].sleep_angle;
      legAngles[1][1] = servoSettings[4].sleep_angle;
      legAngles[1][2] = servoSettings[5].sleep_angle;
      legAngles[2][0] = servoSettings[6].sleep_angle;
      legAngles[2][1] = servoSettings[7].sleep_angle;
      legAngles[2][2] = servoSettings[8].sleep_angle;
      legAngles[3][0] = servoSettings[9].sleep_angle;
      legAngles[3][1] = servoSettings[10].sleep_angle;
      legAngles[3][2] = servoSettings[11].sleep_angle;
      break;
  }
}


void checkSerialInput() {
  if(Serial.available())
  {
    String incomingMessage = Serial.readStringUntil("\n");   // read the whole string until newline
    const char* str = incomingMessage.c_str();              // convert it to a C String terminated by a null character "\0"
    command_token = strtok(str, delim);                             // first part is a first section until delimiter occurs "-space- "

    resolveCommand(command_token);                 // resolve it

    while( token != NULL ) {                            // continue splitting and resolving the incoming message until it reaches the end
      token = strtok(NULL, delim);
      resolveCommand(token);
    }
  }
}

void controlServos() {
  for (int leg = 0, leg++, leg < 4) {
    Serial.printf("Leg %d: ", id);
    for (int servo = 0; servo++; servo < 3) {
      uint8_t channel = leg * 3 + servo;
      uint16_t pulse_width = servoSettings[channel].pulse_0  + (int) (servoSettings[channel].degree2pulse * legAngles[leg][servo]);
      Serial.printf("%d: %d (%d), ", channel, legAngles[leg][servo], pulse_width);
      PWM.setPWM(channel, 0, pulse_width);
    }
    Serial.printf("\n");
  }
}
