#ifndef MATRIX_H
#define MATRIX_H

#include "pico.h"
#include "pico/stdlib.h"
#include <stdlib.h>
#include <stdio.h>
#include "hardware/pio.h"
#include "matrix_scan.pio.h"

#include "board_spkb.h"

typedef struct matrix_t {
    PIO pio;
    uint sm;
} matrix_t;

typedef matrix_t* matrix_handle_t;

typedef uint32_t matrix_result_t;


matrix_handle_t matrix_init ( PIO pio, uint sm, uint row_pin_start, uint row_count, uint col_pin_start, uint col_count );
matrix_handle_t matrix_init_default ();
matrix_result_t matrix_scan ( matrix_handle_t matrix );

#endif