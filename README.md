# STM32-Based Industrial Motor Protection Controller

## Overview
A proposed embedded controller for monitoring and protecting a DC motor. The target MCU is the STM32G431RB on a NUCLEO-G431RB board. The intended functions are PWM speed control, speed measurement, current and temperature monitoring, fault detection, a safe motor-stop command, status LEDs, and UART diagnostics.

## Important validation statement
**This repository is a starter project package and test plan, not proof of completed hardware validation.** The author has not supplied measured hardware logs or verified CubeMX configuration. Do not describe any expected behavior as a measured result. Label results as:
- **Planned:** not run yet.
- **Simulated:** run in a simulator, with simulator name, version, inputs and logs recorded.
- **Hardware-tested:** run on the real board and motor, with wiring, equipment, calibration and evidence recorded.

## Target architecture
Speed reference (ADC) -> STM32G431RB -> PWM (TIM1 CH1) -> motor driver -> DC motor
Motor speed sensor -> TIM2 input capture
Current sensor -> ADC
Temperature sensor -> ADC
UART -> diagnostics; GPIO -> status/fault LEDs

## Planned fault conditions
1. Overcurrent
2. Overtemperature
3. Overspeed
4. Stall / no speed pulses while drive is commanded

Thresholds, sensor scaling, timer clock, pulse-per-revolution (PPR), ADC channels, driver polarity, and pin mapping must be confirmed for the actual design before use.

## Suggested repository layout
- `Core/motor_protection.c` and `.h`: portable fault logic starter module
- `tests/test_plan.md`: planned test cases and evidence checklist
- `docs/architecture.md`: architecture and assumptions
- `docs/report_content.md`: report content starter
- `docs/hardware_setup_template.md`: fill in only after hardware is available

## Build integration
1. Create/open the STM32CubeIDE project for NUCLEO-G431RB.
2. In CubeMX, configure PWM timer, input-capture timer, ADC channels, UART and GPIO.
3. Confirm generated peripheral handles and pin assignments.
4. Add the portable logic module to the project and call `MP_Update()` periodically using real, scaled measurements.
5. On any fault, force the PWM command to zero and put the motor driver in its documented safe state.
6. Test with a current-limited supply and a safe test setup before connecting a motor.

The code in this repository is not a complete CubeMX-generated firmware project and will need board-specific integration.
