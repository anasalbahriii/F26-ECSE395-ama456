//Anas Albahri-(ama456)-Lab2
#include <Arduino.h>
#define LED_PIN 13

void setup() {
  pinMode(LED_PIN, OUTPUT);
  // ama456: 115200 baud, matches monitor_speed in platformio.ini
  Serial.begin(115200);
}

void loop() {
    // ama456: my custom serial message, prints once per blink cycle
    Serial.println("Still blinking, still employed.");
    digitalWrite(LED_PIN, HIGH);
    delay(300);   // ama456: 300 ms on, slow enough to see clearly
    digitalWrite(LED_PIN, LOW);
    delay(300);   // ama456: 300 ms off, same duration for an even blink
}
