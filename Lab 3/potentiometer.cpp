//ama456 - Anas Albahri
#include <Arduino.h>

// ama456: A0 is one of the analog-capable pins on the Feather ESP32 V2, Only A0 through A5 can read an analog signal on this board.
#define POTENTIOMETER_PIN A0

// ama456: Holds the pin number so the rest of the code reads from one place.
const int pin = POTENTIOMETER_PIN;

void setup() {
    // ama456: 115200 baud, matches monitor_speed in platformio.ini ,A mismatch here prints garbage symbols instead of numbers.
    Serial.begin(115200);
}

void loop() {
  // ama456: Read the potentiometer and print the raw value straight away, The ESP32 ADC is 12-bit, so turning the knob sweeps 0 to 4095.
  Serial.println(analogRead(pin));

  delay(50);
}
