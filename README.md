# industrial-motor-protection-controller.
An STM32G431RB-based DC motor protection and monitoring project featuring PWM speed control, motor speed measurement, current and temperature monitoring, and fault detection for overcurrent, overtemperature, overspeed, and motor stall. Includes C firmware starter code, system architecture, and a test plan.
STM32-Based Industrial Motor Protection Controller

Project Overview

This project aims to develop an embedded system using the STM32G431RB microcontroller to control, monitor, and protect a DC motor.

Objectives

- Control motor speed using PWM.
- Measure actual motor speed using a speed sensor.
- Monitor motor current and temperature.
- Detect overcurrent, overtemperature, overspeed, and motor stall.
- Stop the motor drive command when a fault is detected.
- Display status and fault information using LEDs and UART.

Technologies Used

- Microcontroller: STM32G431RB
- Development environment: STM32CubeIDE and STM32CubeMX
- Programming language: C
- Peripherals: Timers, PWM, ADC, UART, and GPIO

System Architecture

Speed Reference → STM32 → PWM → Motor Driver → DC Motor

Speed, current, and temperature sensors provide feedback to the microcontroller.

Testing and Validation

The repository contains starter fault-logic code, system documentation, and a planned test procedure. Test cases are marked as planned until they have been executed and documented. No physical hardware test results are claimed at this stage.

Future Improvements

- Integrate and verify the code in the complete STM32CubeIDE project.
- Calibrate the sensors and configure protection thresholds.
- Perform simulator testing where supported.
- Conduct controlled hardware testing and document measured results.

Author

navyasreegembali

Disclaimer

This repository is a development starter package. Hardware integration and validation are required before real-world motor operation.
