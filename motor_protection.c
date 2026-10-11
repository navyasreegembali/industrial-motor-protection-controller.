#include "motor_protection.h"

void MP_Init(MP_State *state)
{
    if (state == 0) return;
    state->fault = MP_FAULT_NONE;
    state->no_pulse_elapsed_ms = 0U;
    state->motor_enable = false;
}

MP_Fault MP_Update(MP_State *state, const MP_Config *config,
                   const MP_Input *input, uint32_t elapsed_ms)
{
    if (state == 0 || config == 0 || input == 0) return MP_FAULT_NONE;

    /* Latched fault: a deliberate, separately designed reset routine is required. */
    if (state->fault != MP_FAULT_NONE) {
        state->motor_enable = false;
        return state->fault;
    }

    if (input->current_a > config->current_limit_a) {
        state->fault = MP_FAULT_OVERCURRENT;
    } else if (input->temperature_c > config->temperature_limit_c) {
        state->fault = MP_FAULT_OVERTEMPERATURE;
    } else if (input->speed_rpm > config->speed_limit_rpm) {
        state->fault = MP_FAULT_OVERSPEED;
    } else {
        if (!input->drive_commanded || input->speed_pulse_seen) {
            state->no_pulse_elapsed_ms = 0U;
        } else {
            state->no_pulse_elapsed_ms += elapsed_ms;
            if (state->no_pulse_elapsed_ms >= config->stall_timeout_ms) {
                state->fault = MP_FAULT_STALL;
            }
        }
    }

    state->motor_enable = (state->fault == MP_FAULT_NONE) && input->drive_commanded;
    return state->fault;
}

const char *MP_FaultName(MP_Fault fault)
{
    switch (fault) {
        case MP_FAULT_OVERCURRENT: return "OVERCURRENT";
        case MP_FAULT_OVERTEMPERATURE: return "OVERTEMPERATURE";
        case MP_FAULT_OVERSPEED: return "OVERSPEED";
        case MP_FAULT_STALL: return "STALL";
        case MP_FAULT_NONE:
        default: return "NONE";
    }
}
