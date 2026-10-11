# Project report content starter

## Title
STM32-Based Industrial Motor Protection Controller

## Abstract
This project proposes an embedded controller for monitoring a DC motor and responding to abnormal operating conditions. An STM32G431RB microcontroller is the target platform. The planned firmware uses timer PWM for the drive command, timer input capture for speed measurement, ADC channels for current, temperature and speed-reference inputs, GPIO for status indication, and UART for diagnostics. The protection logic considers overcurrent, overtemperature, overspeed and stall conditions. The controller is intended to move to a safe disabled state when a fault is detected.

## Problem statement
Motor faults can lead to overheating, equipment damage and unsafe operation. A compact controller that monitors key signals and disables the drive command when configured limits are exceeded can support safer operation. Thresholds and response times must be selected from the motor and sensor specifications.

## Objectives
- Generate a PWM speed command.
- Estimate actual speed from sensor pulses.
- Monitor current and temperature.
- Detect four defined fault classes.
- Disable the motor command on a fault.
- Provide status and diagnostic output.

## Methodology
1. Configure MCU clocks, PWM, input capture, ADC, UART and GPIO in STM32CubeMX.
2. Implement measurement conversion and filtering.
3. Execute the fault logic periodically.
4. On a fault, request zero PWM and disable the driver through its enable input.
5. Log state and fault codes over UART.
6. Verify with unit tests, then simulator tests where available, followed by cautious bench testing.

## Expected outcome (not measured)
The intended outcome is a controller that reports measured speed and sensor values, and latches a fault when a configured limit is crossed. These are design expectations, not test results.

## Results and validation
At preparation time, no physical hardware measurements have been supplied. The test plan therefore lists all cases as Planned. If a simulator is used, report the simulator, version, exact inputs and logs and label those results Simulated. Hardware results must include actual measurements and evidence.

## Limitations
- Hardware integration and CubeMX pin mapping are not verified in this package.
- Sensor models and calibration values are unspecified.
- Threshold values require the motor's datasheet and risk assessment.
- A software stop request does not replace a correctly rated driver, fuse, emergency stop or other required protection.

## Conclusion
The design establishes a modular starting point for a motor monitoring and protection controller. Further work is required to integrate the firmware with the actual CubeMX project, confirm sensor scaling and timer configuration, and execute documented software, simulation and hardware tests.
