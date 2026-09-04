//Anas Albahri-(ama456)-Lab2
#include <Arduino.h>
#define LED_PIN 13



void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
    Serial.println("Still blinking, still employed.");
    digitalWrite(LED_PIN, HIGH);
    delay(300);
    digitalWrite(LED_PIN, LOW);
    delay(300);
}

