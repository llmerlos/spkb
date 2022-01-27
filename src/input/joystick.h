#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "pico.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

#include "board_spkb.h"

#ifdef __cplusplus
extern "C" {
#endif

enum adc_ch {
    ADC_CH26 = 0,
    ADC_CH27 = 1,
    ADC_CH28 = 2,
    ADC_CH29 = 3
};

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