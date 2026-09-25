// ama456 - Anas Albahri - Lab 5
// ama456: Integrates a photoresistor module with a passive buzzer.
// ama456: While light reaches the sensor the system stays silent. When the
// ama456: sensor is covered, the buzzer beeps until it is uncovered again.

#include <Arduino.h>

// ama456: The photoresistor's analog output lands on A0.
#define LIGHT_PIN A0

// ama456: The passive buzzer's signal pin lands on A1.
#define BUZZER_PIN A1

// ama456: On this module the reading rises when the sensor is covered, so
// ama456: anything above this counts as covered. The ESP32 ADC is 12-bit,
// ama456: giving a 0 to 4095 range. Ambient light reads roughly 1100-2600
// ama456: on my desk, and a hand over the sensor pushes it past 3000.
#define COVERED_THRESHOLD 2000



// ama456: The ESP32 makes PWM through numbered LEDC channels.
// ama456: Channel 0 is free, and 8-bit resolution is plenty for a buzzer.
#define BUZZER_CHANNEL 0
#define PWM_RESOLUTION 8

// ama456: Tone frequency in hertz. 1000 Hz is loud without being harsh.
#define BEEP_FREQUENCY 1000

// ama456: How long each beep lasts and how long the gap between beeps is.
#define BEEP_ON 200
#define BEEP_OFF 300

void setup() {
  // ama456: 115200 baud, matches monitor_speed in platformio.ini.
  Serial.begin(115200);

  // ama456: The photoresistor sends a signal in, so its pin is an input.
  pinMode(LIGHT_PIN, INPUT);

  // ama456: Set up the PWM channel before using it. Skipping this is what
  // ama456: causes the "LEDC is not initialized" error at runtime.
  ledcSetup(BUZZER_CHANNEL, BEEP_FREQUENCY, PWM_RESOLUTION);

  // ama456: Route that channel's output to the buzzer's pin.
  ledcAttachPin(BUZZER_PIN, BUZZER_CHANNEL);

  // ama456: Duty cycle 0 means no signal, so the buzzer starts silent.
  ledcWrite(BUZZER_CHANNEL, 0);
}

void loop() {
  // ama456: Read the light level from the photoresistor.
  int lightLevel = analogRead(LIGHT_PIN);

  if (lightLevel > COVERED_THRESHOLD) {
    // ama456: Sensor is covered, so sound one beep.
    Serial.print("Covered - reading ");
    Serial.print(lightLevel);
    Serial.println(" - sounding alert");

    // ama456: A duty cycle of 128 out of 255 drives the buzzer.
    ledcWrite(BUZZER_CHANNEL, 128);
    delay(BEEP_ON);

    // ama456: Back to zero duty, which creates the gap between beeps.
    ledcWrite(BUZZER_CHANNEL, 0);
    delay(BEEP_OFF);
  } else {
    // ama456: Enough light reaching the sensor, so stay quiet.
    Serial.print("Lit - reading ");
    Serial.println(lightLevel);
    ledcWrite(BUZZER_CHANNEL, 0);
    delay(200);
  }
}
