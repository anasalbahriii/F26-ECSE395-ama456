# Week 11: Project Log

**Anas Albahri (ama456)** — ECSE 395, Fall 2026
Week of November 2–6, 2026

## What the Team Did

**2026-11-02**
- Linked all three boards over ESP-NOW and confirmed delivery with a ping test and a receive counter on the brain
- Fixed the ultrasonic wiring by moving VCC to 5 V, and added an empty-doorway baseline so the door sensors pick up a person farther out
- Rewrote the crate node to track the door angle with the gyroscope, so a bump no longer registers as a close
- Made the window node steadier: it now needs three readings in a row to change state and flags a lost laser
- Submitted the MVP report with a system diagram, photos, and a video of each node

**2026-11-04**
- Ray added a DS1302 clock to the brain, and we time-stamped every event
- Added a CSV log on the brain's own memory that survives a power cut, plus a script to copy it to a laptop
- Ran the first physical tests: the log caught 11 crate closes with the window closed, and the system stayed silent every time
- Added a buzzer for the alert and configured it for our low-level-trigger module

**2026-11-06**
- Presented the design review in the Sears Lab, covering test protocols and raw data, verification evidence, failures and fixes, the requirements matrix, and the Gantt chart

## My Contributions

**2026-11-02**
- tested out the system 

**2026-11-04**
- added a way to save data as csv files

**2026-11-07**
- Updated my repository and wrote this log

## Meeting Minutes

**Date:** 2026-11-06
**Format:** In person, Sears Lab
**Attendees:** Anas Albahri, Ray Zhang, Minh Hoang Nguyen

**Discussion**
- Walked through the design review: test protocols, raw data, verification evidence, failures and fixes, requirements matrix, Gantt chart
- Reviewed the two defects the physical tests exposed

**Decisions**
- Move ahead with validation once two fixes land: the crate node logging repeated closes, and one ultrasonic sensor returning no echo

**Action Items**
- fix the crate double-close
- fix the ultrasonic echo
- All: mount the system on a real window and crate

## Open Defects

- The crate node logs repeated closes for a single event
- One ultrasonic sensor returns no echo

## Next Week

- [ ] Fix the crate double-close and the ultrasonic echo
- [ ] Mount the system on a real window and a real crate
- [ ] Run TS.04 alert speed, TS.11 sash detection, TS.16 range, and TS.01 buzzer loudness
