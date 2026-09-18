// ama456 - Anas Albahri - Lab 4
// ama456: Sweeps the SG90 servo from 0 to 180 degrees and back.
// ama456: Requires lib_deps = madhephaestus/ESP32Servo in platformio.ini.

#include <Arduino.h>
#include <ESP32Servo.h>

// ama456: Creates the servo object that drives the signal line.
Servo myServo;

// ama456: The servo's orange signal wire lands on A0.
#define SERVO_PIN A0

// ama456: Pulse widths in microseconds that map to the servo's end stops.
// ama456: 500 us is the 0 degree end, 2400 us is the 180 degree end.
#define MIN_PULSE_WIDTH 500
#define MAX_PULSE_WIDTH 2400

// ama456: The servo expects a new pulse 50 times a second.
#define SERVO_FREQUENCY 50

// ama456: Rotation range. The servo sweeps between these two angles.
#define MIN_ANGLE 0
#define MAX_ANGLE 180

// ama456: Milliseconds between each one-degree step. Higher means slower.
#define STEP_DELAY 15

void setup() {
  // ama456: 115200 baud, matches monitor_speed in platformio.ini.
  Serial.begin(115200);

  // ama456: Set the PWM frequency before attaching the servo.
  myServo.setPeriodHertz(SERVO_FREQUENCY);

  // ama456: Attach the servo to its pin and tell it the pulse width limits.
  myServo.attach(SERVO_PIN, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
}

void loop() {
  // ama456: Sweep up one degree at a time from the min angle to the max.
  Serial.println("Sweeping 0 to 180");
  for (int angle = MIN_ANGLE; angle <= MAX_ANGLE; angle++) {
    myServo.write(angle);
    delay(STEP_DELAY);
  }

  // ama456: Sweep back down the same way.
  Serial.println("Sweeping 180 to 0");
  for (int angle = MAX_ANGLE; angle >= MIN_ANGLE; angle--) {
    myServo.write(angle);
    delay(STEP_DELAY);
  }
}
