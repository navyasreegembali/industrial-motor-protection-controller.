# System architecture and design assumptions

## Functional flow
1. Read the speed-reference ADC channel.
2. Convert the reference to a bounded PWM duty request.
3. Capture speed-sensor edges with a timer input-capture channel and calculate RPM.
4. Sample current and temperature channels, applying the sensor's transfer function and calibration.
5. Call the protection logic at a known periodic interval.
6. If a fault is detected, command PWM duty to zero, disable the driver using its documented enable input, latch a fault indication, and report the fault through UART.
7. Require a deliberate reset/recovery process after the cause has been checked.

## Target peripheral plan (to verify in CubeMX)
- PWM: TIM1 CH1
- Speed capture: TIM2 CH1
- ADC: speed reference, current sensor, temperature sensor
- UART: USART1 or another configured UART
- GPIO: status and fault indication

These are the project's planned choices, not verified pin mappings. Check the selected NUCLEO-G431RB pinout and avoid pin conflicts.

## Engineering notes
- Define ADC reference voltage, resolution, sensor sensitivity, divider/gain and calibration.
- RPM calculation depends on timer input clock, prescaler, capture period and sensor pulses per revolution.
- A motor stall should be detected only when drive is commanded and no valid speed pulses arrive for the configured timeout.
- Consider ADC filtering, hysteresis, debounce, startup blanking, sensor-disconnect detection, watchdog behavior and safe fault reset.
- Never drive a motor directly from an MCU pin. Use a properly rated motor driver and current-limited supply.
