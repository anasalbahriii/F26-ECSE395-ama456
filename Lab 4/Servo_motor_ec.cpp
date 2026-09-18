// ama456 - Anas Albahri - Lab 4 Extra Credit
// ama456: Sweeps the servo with easing, so it accelerates out of each end
// ama456: and decelerates into the other instead of moving at one speed.
// ama456: Requires lib_deps = madhephaestus/ESP32Servo in platformio.ini.

#include <Arduino.h>
#include <ESP32Servo.h>

// ama456: Creates the servo object that drives the signal line.
Servo myServo;

// ama456: The servo's orange signal wire lands on A0.
#define SERVO_PIN A0

// ama456: Pulse widths in microseconds for the servo's end stops.
#define MIN_PULSE_WIDTH 500
#define MAX_PULSE_WIDTH 2400

// ama456: The servo expects a new pulse 50 times a second.
#define SERVO_FREQUENCY 50

// ama456: The sweep runs between these two angles.
#define MIN_ANGLE 0
#define MAX_ANGLE 180

// ama456: Shortest pause, used at the middle of the sweep where the
// ama456: servo is moving fastest.
#define FAST_DELAY 1

// ama456: Longest pause, used at both ends where the servo is slowest.
#define SLOW_DELAY 15

void setup() {
  // ama456: 115200 baud, matches monitor_speed in platformio.ini.
  Serial.begin(115200);

  // ama456: Set the PWM frequency before attaching the servo.
  myServo.setPeriodHertz(SERVO_FREQUENCY);

  // ama456: Attach the servo and tell it the pulse width limits.
  myServo.attach(SERVO_PIN, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
}

// ama456: Works out how long to wait after a given angle.
// ama456: The step delay is longest at both ends of the sweep and
// ama456: shortest in the middle, which reads as easing in and out.
int easedDelay(int angle) {
  // ama456: Distance from the midpoint, 0 at the centre and 90 at an end.
  int midpoint = (MIN_ANGLE + MAX_ANGLE) / 2;
  int distanceFromMiddle = abs(angle - midpoint);

  // ama456: Scale that distance onto the delay range, so the ends get
  // ama456: SLOW_DELAY and the centre gets FAST_DELAY.
  return map(distanceFromMiddle, 0, midpoint, FAST_DELAY, SLOW_DELAY);
}

void loop() {
  // ama456: Sweep up, easing out of the start and into the far end.
  Serial.println("Accelerating up to 180");
  for (int angle = MIN_ANGLE; angle <= MAX_ANGLE; angle++) {
    myServo.write(angle);
    delay(easedDelay(angle));
  }

  // ama456: Sweep back down with the same easing applied in reverse.
  Serial.println("Accelerating back to 0");
  for (int angle = MAX_ANGLE; angle >= MIN_ANGLE; angle--) {
    myServo.write(angle);
    delay(easedDelay(angle));
  }
}
