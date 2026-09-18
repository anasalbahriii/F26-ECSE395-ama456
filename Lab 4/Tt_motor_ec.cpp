// ama456 - Anas Albahri - Lab 4 Extra Credit
// ama456: Ramps the TT motor's speed up and back down in a continuous loop
// ama456: instead of holding one fixed speed.

#include <Arduino.h>

// ama456: The L9110's two inputs. A0 and A1 are safe pins per the TA hint.
#define MOTOR_A A0
#define MOTOR_B A1

// ama456: Below this duty cycle the motor buzzes without turning, so the
// ama456: ramp starts here rather than at 0.
#define MIN_SPEED 60

// ama456: Full duty cycle out of 255.
#define MAX_SPEED 255

// ama456: How much the speed changes on each step of the ramp.
#define SPEED_STEP 5

// ama456: Milliseconds between steps. Higher makes the ramp more gradual.
#define RAMP_DELAY 40

void setup() {
  // ama456: 115200 baud, matches monitor_speed in platformio.ini.
  Serial.begin(115200);

  // ama456: Both driver inputs send signals out, so they are outputs.
  pinMode(MOTOR_A, OUTPUT);
  pinMode(MOTOR_B, OUTPUT);

  // ama456: B stays at zero the whole time, so the motor holds one
  // ama456: direction and only its speed changes.
  analogWrite(MOTOR_B, 0);
}

void loop() {
  // ama456: Accelerate. Each pass raises the duty cycle by one step,
  // ama456: so the motor speeds up smoothly instead of jumping.
  Serial.println("Speeding up");
  for (int speed = MIN_SPEED; speed <= MAX_SPEED; speed += SPEED_STEP) {
    analogWrite(MOTOR_A, speed);
    delay(RAMP_DELAY);
  }

  // ama456: Decelerate back down the same way.
  Serial.println("Slowing down");
  for (int speed = MAX_SPEED; speed >= MIN_SPEED; speed -= SPEED_STEP) {
    analogWrite(MOTOR_A, speed);
    delay(RAMP_DELAY);
  }
}
