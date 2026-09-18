# Lab 4: Actuator Adventures

**Anas Albahri (ama456)** — ECSE 395, Fall 2026, September 18, 2026

## Overview

I have now completed three tasks relating to work on the ESP32; in this instance I connected two actuators and controlled them with some code — namely a TT gear motor driven by an L9110 motor driver and an SG90 servo.

Unlike the servo, the TT motor continues to rotate and the speed and direction it attains are controlled by PWM without relying on positional feedback; the servo, by contrast, holds the angle that has been commanded by making the necessary adjustments using an internal potentiometer.

## Setup

- **Board:** Adafruit ESP32 Feather V2
- **Editor:** VS Code with the PlatformIO IDE extension
- **Operating system:** macOS
- **Power:** The power unit used is the HY3005F benchtop DC supply, which supplies a maximum of 3 volts and 0.15 amperes to the motor and 5 volts and 0.75 amperes to the servo.
- **Library:** `madhephaestus/ESP32Servo`, added via the `lib_deps` entry in the `platformio.ini` file

## What Is In This Folder

- `TT Motor.cpp` — causes the TT motor to rotate in one direction at a constant speed.
- `TT Motor Rotate.cpp` — must rotate clockwise for five seconds, then stop for two seconds, then rotate counterclockwise for five seconds before stopping for two seconds, and then carry on with this sequence indefinitely.
- `TT Motor EC.cpp` — extra credit, achieved by varying the motor speed.
- `Servo Motor.cpp` — makes the servo move, the movement extending from 0° to 180° and then returning.
- `Servo Motor Random.cpp` — makes the servo move to random angles while it is waiting for random periods of time.
- `Servo Motor EC.cpp` — includes extra credit in order that the sweeping movement may be made easier through the use of acceleration and deceleration.

The method for doing this is to include only one `setup()` and one `loop()` in the `src` section, comment out all of the other `.cpp` files using `/*` and `*/`, leave just one of them active, and then compile and upload it.

## Steps

1. Establish an Arduino framework project for the Feather ESP32 V2 using PlatformIO.
2. I added `monitor_speed = 115200` and `lib_deps = madhephaestus/ESP32Servo` to the `platformio.ini` file.
3. Before making the connection, set the bench supply to 3 volts with a current limit of 0.15 amperes.
4. Constructed the TT motor circuit by placing the L9110 driver on the breadboard, connecting A0 and A1 to its B-1A and B-1B inputs respectively, attaching the motor to the output terminals, supplying voltage to VCC, and ensuring that a common ground was used by the ESP32, the driver, and the power supply.
5. I wrote `TT Motor.cpp` and `TT Motor Rotate.cpp` and then uploaded them.
6. For the servo, connect the signal to A0, take the power from the supply, and use the common ground.
7. I uploaded `Servo Motor.cpp`, then `Servo Motor Random.cpp`.
8. Wrote the two extra credit assignments.
9. took photographs of both circuits and filmed the actuators in operation.

## Uploading to the ESP32

I carried out the process using PlatformIO in VS Code; a checkmark in the status bar means that the build has been successful, the arrow symbol causes the program to be uploaded over USB-C and the plug icon brings up the serial monitor at 115200 baud. The serial monitor must be closed prior to uploading because it occupies the serial port.

## Circuit Photos

# TT motor with L9110 driver
<img width="4284" height="5712" alt="IMG_2876" src="https://github.com/user-attachments/assets/d14eb9e4-f4c8-4ebe-87ba-de32e24435ed" />

# SG90 servo
<img width="3024" height="4032" alt="IMG_2873" src="https://github.com/user-attachments/assets/dae4ae1e-ea77-433f-a93e-6ed7056fcd69" />


## Parameter Results

I tested the changes below during the lab and recorded how the TT motor and servo responded.

### TT Motor

**`analogWrite()` value.** lowered the value from 200 to 100, and the motor slowed. A smaller value shrinks the PWM duty cycle, which drops the average voltage reaching the motor. At very low values the motor stopped turning and buzzed instead, because the torque never rose high enough to break static friction.

**Swapping the `analogWrite()` values.** I moved the PWM signal from input A to input B, which reversed the polarity across the motor. The motor turned the opposite direction at about the same speed for the same PWM value.

**`delay()`.** In the base file, changing `delay()` did almost nothing visible. The loop sent the same motor commands on every pass, so the timing had nothing to alter. In the rotate file, `delay()` set how long the motor held each stage of the rotation sequence. A longer delay stretched each stage; a shorter one pushed the sequence along faster.

### Servo

**`minPulseWidth`.** raised `minPulseWidth` above 500, and the servo's minimum position shifted inward. The horn stopped short of its original zero-degree mechanical position, cutting the total rotation range.

**`maxPulseWidth`.** lowered `maxPulseWidth`, and the maximum position moved inward, so the servo fell short of 180 degrees. Pushing the value past the normal operating range drove the servo into its mechanical limit, where it buzzed and strained without gaining rotation.

**`setPeriodHertz`.** This setting changed both movement and stability. The servo ran clean at 50 Hz. Dropping the frequency made the motion rough, and raising it too far left the servo unstable or slow to respond.

**Rotation range.** narrowed the commanded range to 45–135 degrees, and the servo swept a smaller arc. The motion matched the original sweep inside the new limits.

**`delay`.** The delay between one-degree position updates set the sweep speed. A short delay sped the sweep up; a long one slowed it down.


## Reflection and Time Reporting

**1. How long did this take?**

about 5 hours in total

**2. Difficulty level?**

- [ ] Low
- [x] Medium
- [ ] High

**3. Hardest part?**
N/A

**4. How comfortable do you feel with the course content?**

so far, I feel comfortable.

**5. Feedback for the instructors?**
N/A
