//***********
// Servo motor test
// SDA - pin next to GND - 21
// SCL - 22
//************


#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <CommandParser.h>

#define PWM_SERVO_ADDR    0x40
Adafruit_PWMServoDriver PWM = Adafruit_PWMServoDriver(PWM_SERVO_ADDR);


typedef CommandParser<> MyCommandParser;
MyCommandParser servoCommandParser;
int pulse = 170;
int servo_id = 0;



// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // 12-Bit 16 Channel PWM Module

  PWM.begin();
  PWM.setPWMFreq(50);

  Serial.begin(115200);

  while (!Serial);

  servoCommandParser.registerCommand("s", "uu", &cmd_servo);
  Serial.println("registered command: s <uint64> <uint64> ");
  Serial.println("example: s 0 150");
  servoCommandParser.registerCommand("sleep", "", &servosSleep);
  Serial.println("registered command: sleep ");
  servoCommandParser.registerCommand("wake", "", &servosWake);
  Serial.println("registered command: wake ");
  Serial.println("");
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second

  if (checkSerialInput())
    writePWM();
}

void cmd_servo(MyCommandParser::Argument *args, char *response) {
  servo_id = args[0].asInt64;
  pulse = args[1].asInt64;
  strlcpy(response, "success", MyCommandParser::MAX_RESPONSE_SIZE);
}

bool checkSerialInput(){
  if (Serial.available()) {
    char line[128];
    size_t lineLength = Serial.readBytesUntil('\n', line, 127);
    line[lineLength] = '\0';

    char response[MyCommandParser::MAX_RESPONSE_SIZE];
    servoCommandParser.processCommand(line, response);
    Serial.println(response);

    if (strcmp(response, "success") == 0)
      return true;
  }

  return false;
//    if (Serial.available() > 0) {
//      char symbol = Serial.read();
//      Serial.print(symbol);
//    switch (symbol) {
//      case '0':
//        pos = 0;
//        break;
//      case '3':
//        pos = 30;
//        break;
//      case '9':
//        pos = 90;
//        break;
//      case '5':
//        pos = 150;
//        break;
//      case '8':
//        pos = 180;
//        break;
//      case '+':
//        pos += 5;
//        break;
//      case '-':
//        pos -= 5;
//        break;
//    }
//  }
}

void servosSleep(MyCommandParser::Argument *args, char *response) {
  PWM.sleep();
}

void servosWake(MyCommandParser::Argument *args, char *response) {
  PWM.wakeup();
}

void writePWM(){
  Serial.printf("Servo %d: Pulse %d\n", servo_id, pulse);
  PWM.setPWM(servo_id, 0, pulse);
  
}
