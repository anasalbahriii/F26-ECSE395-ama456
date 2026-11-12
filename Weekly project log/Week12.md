# Week 12: Project Log

**Anas Albahri (ama456)** — ECSE 395, Fall 2026
Week of November 6–12, 2026

## What the Team Did

**2026-11-06**
- Presented the design review: verification evidence, failures and fixes, the requirements matrix, and the Gantt chart

**2026-11-08**
- Added phone notifications so the brain joins Wi-Fi and sends each alert through the ntfy app
- Traced the Wi-Fi failure to a typo in the network name and got the brain connected
- Found that Wi-Fi power saving made the brain miss node messages, which kept dropping nodes offline, and turned power saving off

**2026-11-09**
- Tuned the thresholds: crate open past 10°, closed within 5°, ultrasonic sensitivity at 25 cm
- Ran the first validation session with a real user, P1, from 18:13 to 18:22: 10 crate closes, front-door passes, 7 sensor-failure trials, and an exit survey
- Fixed both findings from P1: the door direction when a person steps in and backs out, and the crate's closed position drifting each cycle
- Removed unused code: the buzzer, the debug prints, and the ping test
- Submitted the Validation Testing Checkpoint with the raw CSV and the survey


**2026-11-13**
- Present the design review of the data analysis in the Sears Lab at 2:05 PM

## My Contributions

**2026-11-06**
- Added phone notifications so the brain joins Wi-Fi and sends each alert through the ntfy app
- Traced the Wi-Fi failure to a typo in the network name and got the brain connected

**2026-11-12**
- Updated my repository and wrote this log

## Validation Session

**Date:** 2026-11-09
**Time:** 18:00 to 18:45
**Participant:** P1, a neighbor recruited as a real user

**Protocol**
- 10 crate closes
- Front-door passes
- 7 sensor-failure trials
- Exit survey

**Findings**
- The door direction logic misread a person stepping in and backing out
- The crate's closed position shifted on each cycle

Both were fixed the same day.

## Meeting Minutes

**Date:** 2026-11-09
**Format:** Asynchronous 
**Attendees:** Anas Albahri, Ray Zhang, Minh Hoang Nguyen

**Discussion**
- Reviewed P1's results and the two defects they exposed

**Decisions**
N/A

## Next Week

- [ ] Present the data analysis design review on 2026-11-13 at 2:05 PM in the Sears Lab
