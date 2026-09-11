# Lab 3: Playing With Sensors

**Anas Albahri (ama456)** — ECSE 395, Fall 2026
September 11, 2026

## Overview

This is my second assignment working with the ESP32. I connected two sensors and streamed their data to the serial monitor: a potentiometer and a touch sensor.

**Setup**
- Board: Adafruit ESP32 Feather V2
- Editor: VS Code with the PlatformIO IDE extension
- Operating system: macOS
- Upload: PlatformIO's Upload task over a USB-C data cable
- Baud rate: 115200, set in the code and in `monitor_speed`

**Equipment**

- ESP 32
- touch sensor 
- potentiometer
- breadboard 
- wires 

## What Is In This Folder

- `potentiometer.cpp` — reads the raw analog value from the potentiometer, 0 to 4095
- `voltage.cpp` — converts that reading into a voltage and prints it
- `touch.cpp` — reads the touch sensor and lights the onboard LED on contact

**How to run any of these.** Only one `setup()` and one `loop()` can exist in `src` at a time. Comment out every other `.cpp` with `/*` before the first line and `*/` after the last, leave one uncommented, then build and upload.

## Part 1: Potentiometer

**Wiring.** The potentiometer module sits in the breadboard. VCC goes to 3V, GND to GND, and OUT to A0. I used A0 because only A0 through A5 read analog signals on this board.

**Raw values.** `potentiometer.cpp` prints the reading on its own. Turning the knob sweeps it from 0 to 4095, since the ADC is 12-bit.

**Converting to voltage.** In `voltage.cpp` I stored the reading in an integer called `sensorValue` rather than printing it inline, which let me reuse the same value. I then made a float called `sensorVoltage` using the formula from the lab:

```
voltage = (analog value x reference voltage) / resolution
```

With a 3.3 V reference and a resolution of 4095, a full turn moves the output from 0.00 V to 3.30 V.

**Delay.** The skeleton used 50 ms. Lines scrolled past too fast to read while I turned the knob, so I raised it to 200 ms.

## Part 2: Touch Sensor

**Wiring.** The touch sensor sits in the breadboard with VCC on 3V, GND on GND, and its signal pin on A1.

**Combining with Lab 2.** I defined the onboard LED at the top of the file, set it as an output in `setup()`, and added an `if` and `else` in the main loop. On contact the board prints `Touch detected!` and turns the LED on. On release it prints `No touch detected...` and turns the LED off.

## Reflection and Time Reporting

**1. How long did this take?**

around 3 hours

**2. Difficulty level?**

- [x] Low
- [ ] Medium
- [ ] High

**3. Hardest part?**

N/A

**4. How comfortable do you feel with the course content?**

pretty comfortable so far

**5. Feedback for the instructors?**

N/A
