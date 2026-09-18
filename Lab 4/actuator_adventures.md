## Parameter Results

We tested the changes below during the lab and recorded how the TT motor and servo responded.

### TT Motor

**`analogWrite()` value.** We lowered the value from 200 to 100, and the motor slowed. A smaller value shrinks the PWM duty cycle, which drops the average voltage reaching the motor. At very low values the motor stopped turning and buzzed instead, because the torque never rose high enough to break static friction.

**Swapping the `analogWrite()` values.** We moved the PWM signal from input A to input B, which reversed the polarity across the motor. The motor turned the opposite direction at about the same speed for the same PWM value.

**`delay()`.** In the base file, changing `delay()` did almost nothing visible. The loop sent the same motor commands on every pass, so the timing had nothing to alter. In the rotate file, `delay()` set how long the motor held each stage of the rotation sequence. A longer delay stretched each stage; a shorter one pushed the sequence along faster.

### Servo

**`minPulseWidth`.** We raised `minPulseWidth` above 500, and the servo's minimum position shifted inward. The horn stopped short of its original zero-degree mechanical position, cutting the total rotation range.

**`maxPulseWidth`.** We lowered `maxPulseWidth`, and the maximum position moved inward, so the servo fell short of 180 degrees. Pushing the value past the normal operating range drove the servo into its mechanical limit, where it buzzed and strained without gaining rotation.

**`setPeriodHertz`.** This setting changed both movement and stability. The servo ran clean at 50 Hz. Dropping the frequency made the motion rough, and raising it too far left the servo unstable or slow to respond.

**Rotation range.** We narrowed the commanded range to 45–135 degrees, and the servo swept a smaller arc. The motion matched the original sweep inside the new limits.

**`delay`.** The delay between one-degree position updates set the sweep speed. A short delay sped the sweep up; a long one slowed it down.
