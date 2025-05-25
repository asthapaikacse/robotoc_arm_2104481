#include <Servo.h>
Servo servo1, servo2, servo3, servo4;
// Joystick analog input pins
const int joy1X = A0;
const int joy1Y = A1;
const int joy2X = A2;
const int joy2Y = A3;
// Servo motor pins
const int servo1Pin = 5;
const int servo2Pin = 6;
const int servo3Pin = 9;
const int servo4Pin = 10;
void setup() {
  // Attach servos to pins
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo3.attach(servo3Pin);
  servo4.attach(servo4Pin);
  // Optionally initialize serial monitor
  Serial.begin(9600);
}
void loop() {
  // Read joystick values (0 to 1023)
  int joyVal1X = analogRead(joy1X);
  int joyVal1Y = analogRead(joy1Y);
  int joyVal2X = analogRead(joy2X);
  int joyVal2Y = analogRead(joy2Y);
  // Map joystick values to servo angles (0 to 180)
  int angle1 = map(joyVal1X, 0, 1023, 0, 180);
  int angle2 = map(joyVal1Y, 0, 1023, 0, 180);
  int angle3 = map(joyVal2X, 0, 1023, 0, 180);
  int angle4 = map(joyVal2Y, 0, 1023, 0, 180);
  // servo movement
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
  servo4.write(angle4);
  // Delay to stabilize motion
  delay(100);
}
