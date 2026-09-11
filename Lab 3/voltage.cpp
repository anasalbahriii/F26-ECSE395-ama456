// ama456: Lab 3 - Anas Albahri
#include <Arduino.h>

// ama456: A0 is an analog-capable pin. Only A0 to A5 read analog on this board.
#define sensorPin A0

// ama456: The ESP32 runs its ADC against a 3.3 V reference.
#define REFERENCE_VOLTAGE 3.3

// ama456: The ADC is 12-bit, so its full scale is 4095.
#define RESOLUTION 4095.0

void setup() {
  // ama456: 115200 baud, matches monitor_speed in platformio.ini.
  Serial.begin(115200);
}

void loop() {
  // ama456: Store the raw reading in an integer instead of printing it, so the same value can be reused in the math below.
  int sensorValue = analogRead(sensorPin);

  // ama456: Convert the raw reading to volts. (analog value x reference voltage) / resolution
  float sensorVoltage = (sensorValue * REFERENCE_VOLTAGE) / RESOLUTION;

  // ama456: Print the converted voltage to the serial monitor.
  Serial.print("Voltage: ");
  Serial.print(sensorVoltage);
  Serial.println(" V");

  // ama456: Changed the delay from the skeleton's 50 ms to 200 ms.
  delay(200);
}
