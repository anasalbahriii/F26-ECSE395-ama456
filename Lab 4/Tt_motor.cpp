// ama456 - Anas Albahri - Lab 4
// ama456: Base TT motor sketch. Spins the motor one direction at a fixed speed.
// ama456: This is the file I used for the parameter experiments.

#include <Arduino.h>

// ama456: The L9110's two inputs. A0 and A1 are safe pins per the TA hint.
// ama456: Driving one high and the other low sets the direction.
#define MOTOR_A A0
#define MOTOR_B A1

void setup() {
  // ama456: 115200 baud, matches monitor_speed in platformio.ini.
  Serial.begin(115200);

  // ama456: Both driver inputs send signals out, so they are outputs.
  pinMode(MOTOR_A, OUTPUT);
  pinMode(MOTOR_B, OUTPUT);
}

void loop() {
  // ama456: analogWrite sends a PWM duty cycle from 0 to 255.
  // ama456: 200 on A and 0 on B spins the motor one way at that speed.
  analogWrite(MOTOR_A, 200);
  analogWrite(MOTOR_B, 0);

  // ama456: Hold this state before the loop repeats.
  delay(2000);
}
