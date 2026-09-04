# Lab 2: ESP32 Basics

**Anas Albahri (ama456)** — ECSE 395, Fall 2026
September 4, 2026

## Overview

This is my first assignment working with the ESP32. I made the onboard LED blink and printed my own message to the serial monitor.

I used the Adafruit ESP32 Feather V2 with VS Code and the PlatformIO IDE extension. I uploaded my code over a USB-C data cable using PlatformIO's Upload task.

## Steps

1. Installed VS Code and the PlatformIO IDE extension.
2. Created a project named `Blink Test`, board `Adafruit Feather ESP32 V2`, framework `Arduino`.
3. Added `monitor_speed = 115200` to `platformio.ini`.
4. Opened `main.cpp` and filled in the skeleton code.
5. Set the LED to 300 ms on and 300 ms off.
6. Wrote my own serial message.
7. Marked my comments with `ama456`.
8. Built the code, uploaded it, and opened the serial monitor.
9. Demonstrated the working board to Prof. Fu.
10. Recorded a video and pushed my code to my repository.

## My Choices

**Blink timing.** I set the LED to 300 ms on and 300 ms off. I picked 300 ms because the blink stays easy to follow without dragging.

**Serial message.** The loop prints `Still blinking` on every cycle. Each new line tells me the board is running rather than frozen.

## Video

See `blink-demo.mp4` in this folder.

## Reflection and Time Reporting

**1. How long did this take?**

Around 90 minutes in total.

**2. Difficulty level?**

- [x] Low
- [ ] Medium
- [ ] High

**3. Hardest part?**

N/A

**4. How comfortable do you feel with the course content?**

I feel comfortable with the content so far.

**5. Feedback for the instructors?**

N/A
