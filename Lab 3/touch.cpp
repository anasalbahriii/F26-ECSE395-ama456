// ama456: Lab 3 - Anas Albahri

#include <Arduino.h>

// ama456: A1 is an analog-capable pin on the Feather ESP32 V2.
#define sensorPin A1

// ama456: Define the onboard LED so I can reuse the blink idea from Lab 2, LED_BUILTIN maps to the LED soldered onto the board, pin 13.
#define ledPin LED_BUILTIN

// ama456: Halfway up the 12-bit range. Readings above this count as contact.
#define TOUCH_THRESHOLD 2000

void setup() {
  // ama456: 115200 baud, matches monitor_speed in platformio.ini.
  Serial.begin(115200);

  // ama456: The sensor pin takes a signal in, so it is an input.
  pinMode(sensorPin, INPUT);

  // ama456: The LED pin sends a signal out, so it is an output.
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // ama456: Store the sensor reading so the if and else can both use it.
  int sensorValue = analogRead(sensorPin);

  if (sensorValue > TOUCH_THRESHOLD) {
    Serial.println("Touch detected!");

    // ama456: Contact made, so drive the LED pin high to turn the LED on.
    digitalWrite(ledPin, HIGH);
  } else {
    Serial.println("No touch detected...");

    // ama456: Contact broken, so drive the LED pin low to turn the LED off.
    digitalWrite(ledPin, LOW);
  }

  // ama456: 200 ms keeps the serial monitor readable while I tap the sensor.
  delay(200);
}
    
