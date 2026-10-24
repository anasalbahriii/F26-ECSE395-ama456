# Week 9: Project Log

**Anas Albahri (ama456)** — ECSE 395, Fall 2026
Week 9

## What the Team Did

**2026-10-17**
- Set the system topology: the door ESP32 is the brain, and the window and crate nodes report to it over ESP-NOW
- Wrote the crate node code and merged the ultrasonic code with the receiver and alert logic

**2026-10-18**
- Ran integration tests and found a dead window node left the brain reporting "closed"
- Decided to make Prototype 3 wired on one ESP32 
- Finished Prototype 3
- Planned the wireless MVP: USB-C power for the brain, two 2000 mAh LiPos for the nodes

**2026-10-23**
- Worked on midterm presentation powerpoint slides covering every rubric section


## My Contributions

**2026-10-17**
- Uploaded the brain code and recovered its MAC address

**2026-10-18**
- built Prototype 3
  
**2026-10-23**
- Wrote the prototypes section of presentation
- Updated my repository and wrote this log

## Meeting Minutes

**Date:** 2026-10-17 and 2026-10-18

**Format:** In person

**Attendees:** Anas Albahri, Ray Zhang, Minh Hoang Nguyen

**Discussion**
- Reviewed the integration test results and the failures we hit
- Weighed staying wireless against a wired build for Prototype 3

**Decisions**
- Prototype 3 runs wired on one ESP32
- Wireless moves to the MVP once batteries arrive
  
**Action Items**
- All: midterm presentation and Prototypes 1, 2, and 3

## Next Week

- [ ] Deliver the midterm presentation
- [ ] Work on the wireless build
