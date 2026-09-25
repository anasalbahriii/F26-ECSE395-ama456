# Lab 5: Integration Exploration

**Anas Albahri (ama456)** — ECSE 395, Fall 2026
September 25, 2026

## Overview

I integrated a sensor with an actuator to build a small smart system.

- **Sensor:** photoresistor module, read as analog
- **Actuator:** passive buzzer module, driven with PWM

**Setup**
- Board: Adafruit ESP32 Feather V2
- Editor: VS Code with the PlatformIO IDE extension
- Operating system: macOS
- Upload: PlatformIO's Upload task over a USB-C data cable
- Baud rate: 115200, set in the code and in `monitor_speed`
- Equipment: ESP32 and my own Sunfounder kit

## What Is In This Folder

- `main.cpp` — the full integration, commented with my Case ID
- `circuit-photo.jpg` — photo of the wired circuit

The video of the system working is attached as a comment on the Canvas assignment.

## System Behavior

When the photoresistor reading rises above 2000, the buzzer sounds a 1000 Hz beep, 200 ms on and 300 ms off, and keeps beeping until the reading falls back below 2000.

On my module the reading goes **up** as light is blocked, which is the opposite of what I first assumed. My initial code compared in the wrong direction and triggered when I uncovered the sensor. Watching the raw numbers in the serial monitor is what caught it.

Measured values on my desk:

- Uncovered, ambient room light: roughly 1200 to 1400
- Covered with a cupped hand: above 2000, peaking near 2150

I set the threshold to 2000 because it sits above the ambient range with margin to spare. A lower threshold would trigger on a looser cover, but ambient light drifted as high as 1900 during testing, so anything closer risked false alarms. The trade-off is that the sensor now needs a hand fully enclosing it rather than a passing shadow.


Six jumper wires, all running through the breadboard power rails.

| Module | Module pin | ESP32 pin | Purpose |
| --- | --- | --- | --- |
| Photoresistor | VCC | 3V | Powers the sensor |
| Photoresistor | GND | GND | Shared ground |
| Photoresistor | AO | A0 | Analog light reading |
| Buzzer | VCC | 3V | Powers the buzzer |
| Buzzer | GND | GND | Shared ground |
| Buzzer | I/O | A1 | PWM signal that drives the tone |

I used A0 for the sensor because only A0 through A5 read analog signals on this board. Both modules take 3 V rather than USB voltage, since the ESP32's analog input tops out at 3.3 V. Everything shares a single ground, so the ESP32 and both modules measure against the same reference.

## How to Run It

1. Open the project in PlatformIO with the board set to Adafruit Feather ESP32 V2 and the framework set to Arduino.
2. Add `monitor_speed = 115200` to `platformio.ini`.
3. Wire the circuit as in the table above.
4. Put `main.cpp` in `src/`, build with the checkmark, and upload with the arrow.
5. Open the serial monitor with the plug icon and watch the readings.
6. Cover the photoresistor with your hand. The buzzer should start beeping.

The threshold is a single constant at the top of the file. Different rooms will need a different value, so watch the raw readings before settling on one.

## Reflection and Time Reporting

**1. How long did this take?**

around 2 hours 

**2. Difficulty level?**

- [x] Low
- [ ] Medium
- [ ] High

**3. Hardest part?**

N/A

**4. How comfortable do you feel with the course content?**

I feel comfortable

**5. Feedback for the instructors?**
N/A

[EDIT]
