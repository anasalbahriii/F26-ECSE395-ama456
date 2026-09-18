// ama456 - Anas Albahri - Lab 4
// ama456: Moves the SG90 servo to random angles with random pauses
// ama456: instead of sweeping linearly.
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

// ama456: The servo can land anywhere in this range.
#define MIN_ANGLE 0
#define MAX_ANGLE 180

// ama456: Shortest and longest pause between moves, in milliseconds.
#define MIN_DELAY 300
#define MAX_DELAY 1500

void setup() {
  // ama456: 115200 baud, matches monitor_speed in platformio.ini.
  Serial.begin(115200);

  // ama456: Seed the generator from a floating analog pin so the
  // ama456: sequence differs each time the board powers on.
  randomSeed(analogRead(A5));

  // ama456: Set the PWM frequency before attaching the servo.
  myServo.setPeriodHertz(SERVO_FREQUENCY);

  // ama456: Attach the servo and tell it the pulse width limits.
  myServo.attach(SERVO_PIN, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
}

void loop() {
  // ama456: Pick a random target angle. The upper bound is exclusive,
  // ama456: so MAX_ANGLE + 1 lets the servo reach a full 180.
  int targetAngle = random(MIN_ANGLE, MAX_ANGLE + 1);

  // ama456: Pick a random pause so the motion never falls into a rhythm.
  int pause = random(MIN_DELAY, MAX_DELAY);

  Serial.print("Moving to ");
  Serial.print(targetAngle);
  Serial.print(" degrees, waiting ");
  Serial.print(pause);
  Serial.println(" ms");

  // ama456: Jump straight to the target instead of stepping through
  // ama456: every degree, which is what makes the motion look random.
  myServo.write(targetAngle);

  // ama456: Hold before choosing the next angle.
  delay(pause);
}
