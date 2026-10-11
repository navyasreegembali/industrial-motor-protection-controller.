# Test plan and results template

**Current status:** Planned only. No real hardware results have been provided. Do not mark tests passed until evidence is captured.

| ID | Test | Input / setup | Expected safe behavior | Status |
|---|---|---|---|---|
| T01 | Normal operation | All readings below thresholds; drive commanded | Motor-enable request remains active; no fault | Planned |
| T02 | Overcurrent | Current reading above configured limit | Fault latched; PWM request goes to zero; fault reported | Planned |
| T03 | Overtemperature | Temperature above configured limit | Fault latched; PWM request goes to zero; fault reported | Planned |
| T04 | Overspeed | RPM above configured limit | Fault latched; PWM request goes to zero; fault reported | Planned |
| T05 | Stall | Drive commanded, no speed pulse for timeout | Stall fault latched; PWM request goes to zero | Planned |
| T06 | Sensor pulse resumes | Pulses resume before timeout | Stall timer resets; no stall fault | Planned |
| T07 | Fault latch | A fault is detected, then input returns normal | Motor remains disabled until deliberate reset logic is implemented | Planned |
| T08 | UART report | Trigger each fault | Correct fault label appears on serial terminal | Planned |
| T09 | Startup | Power-on/reset | Driver starts in safe disabled state | Planned |
| T10 | Boundary conditions | Readings at and around thresholds | Behavior matches documented threshold policy | Planned |

## Record evidence for each executed test
- Test ID and date:
- Test environment: simulator name/version OR board and firmware revision:
- Supply voltage/current limit:
- Sensor model and calibration:
- Exact inputs / test steps:
- Expected result:
- Actual result:
- Pass/fail:
- Evidence filename (serial log, screenshot, scope trace, photo):
- Notes / anomalies:

## Status labels
- Planned: not executed.
- Simulated: executed in a named simulator; include reproducible setup and logs.
- Hardware-tested: executed on the physical target; include equipment, wiring, measured data and evidence.

A software unit test is not the same as a simulator run, and neither proves the physical system is safe.
