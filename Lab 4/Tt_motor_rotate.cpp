// ama456 - Anas Albahri - Lab 4
// ama456: Runs the TT motor clockwise 5s, stops 2s, counterclockwise 5s,
// ama456: stops 2s, then repeats the whole sequence.

#include <Arduino.h>

// ama456: The L9110's two inputs. A0 and A1 are safe pins per the TA hint.
#define MOTOR_A A0
#define MOTOR_B A1

// ama456: PWM duty cycle out of 255. Higher means faster.
#define MOTOR_SPEED 200

// ama456: Named timings so the sequence below reads clearly.
#define RUN_TIME 5000    // ama456: 5 seconds of spinning
#define STOP_TIME 2000   // ama456: 2 seconds of rest

void setup() {
  // ama456: 115200 baud, matches monitor_speed in platformio.ini.
  Serial.begin(115200);

  // ama456: Both driver inputs send signals out, so they are outputs.
  pinMode(MOTOR_A, OUTPUT);
  pinMode(MOTOR_B, OUTPUT);
}

void loop() {
  // ama456: Clockwise. Driving A and holding B at zero picks this direction.
  Serial.println("Clockwise for 5 seconds");
  analogWrite(MOTOR_A, MOTOR_SPEED);
  analogWrite(MOTOR_B, 0);
  delay(RUN_TIME);

  // ama456: Stop. Both inputs at zero means no voltage across the motor.
  Serial.println("Stopped for 2 seconds");
  analogWrite(MOTOR_A, 0);
  analogWrite(MOTOR_B, 0);
  delay(STOP_TIME);

  // ama456: Counterclockwise. Swapping which pin carries the PWM
  // ama456: reverses the polarity, so the motor turns the other way.
  Serial.println("Counterclockwise for 5 seconds");
  analogWrite(MOTOR_A, 0);
  analogWrite(MOTOR_B, MOTOR_SPEED);
  delay(RUN_TIME);

  // ama456: Stop again before the sequence loops.
  Serial.println("Stopped for 2 seconds");
  analogWrite(MOTOR_A, 0);
  analogWrite(MOTOR_B, 0);
  delay(STOP_TIME);
}
