#ifndef MOTOR_PROTECTION_H
#define MOTOR_PROTECTION_H

#include <stdbool.h>
#include <stdint.h>

typedef enum {
    MP_FAULT_NONE = 0,
    MP_FAULT_OVERCURRENT,
    MP_FAULT_OVERTEMPERATURE,
    MP_FAULT_OVERSPEED,
    MP_FAULT_STALL
} MP_Fault;

typedef struct {
    float current_a;
    float temperature_c;
    float speed_rpm;
    bool drive_commanded;
    bool speed_pulse_seen;
} MP_Input;

typedef struct {
    float current_limit_a;
    float temperature_limit_c;
    float speed_limit_rpm;
    uint32_t stall_timeout_ms;
} MP_Config;

typedef struct {
    MP_Fault fault;
    uint32_t no_pulse_elapsed_ms;
    bool motor_enable;
} MP_State;

void MP_Init(MP_State *state);
MP_Fault MP_Update(MP_State *state, const MP_Config *config,
                   const MP_Input *input, uint32_t elapsed_ms);
const char *MP_FaultName(MP_Fault fault);

#endif
