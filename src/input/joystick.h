#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "pico.h"
#include "pico/stdlib.h"
#include <stdlib.h>
#include <stdio.h>
#include "hardware/adc.h"

#include "board_spkb.h"

typedef struct joystick_t {
    uint ch_x;
    uint ch_y;
    uint16_t min_x;
    uint16_t max_x;
    uint16_t min_y;
    uint16_t max_y;
} joystick_t;

typedef joystick_t* joystick_handle_t;

typedef struct joystick_result_t {
    float x;
    float y;
} joystick_result_t;


joystick_handle_t joystick_init ( uint pin_x, uint pin_y );
joystick_handle_t joystick_init_default ();
joystick_result_t joystick_scan ( joystick_handle_t joystick );

#endif