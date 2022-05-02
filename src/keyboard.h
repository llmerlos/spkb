#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "FreeRTOS.h" /* Must come first. */
#include "task.h"

#include "pico/stdlib.h"
#include <stdlib.h>
#include "hardware/pio.h"
#include "hardware/adc.h"

#include "utils.h"

#include "keymap.h"
#include "matrix.h"
#include "joystick.h"

#include "leds.h"

void brain ( void* param );
void leds_task ( void* param );

#endif