#ifndef MATRIX_H
#define MATRIX_H

#include "pico.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "matrix_scan.pio.h"

#include "board_spkb.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct matrix_pio_t {
    PIO pio;
    uint sm;
} matrix_pio_t;


matrix_pio_t matrix_pio_init ( PIO pio, uint sm, uint row_pin_start, uint row_count, uint col_pin_start, uint col_count );
matrix_pio_t matrix_pio_init_default ();

#endif