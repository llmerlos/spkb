#ifndef LEDS_H
#define LEDS_H

#include "pico.h"
#include "pico/stdlib.h"
#include <stdlib.h>
#include <stdio.h>
#include "hardware/pio.h"
#include "leds_show.pio.h"

#include "board_spkb.h"

typedef struct leds_t {
    PIO pio;
    uint sm;
} leds_t;

typedef leds_t* leds_handle_t;

leds_handle_t leds_init ( PIO pio, uint sm, uint led_pin );
leds_handle_t leds_init_default ();
void leds_show ( leds_handle_t leds );


#endif