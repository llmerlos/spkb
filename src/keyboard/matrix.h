#ifndef KB_MATRIX_H
#define KB_MATRIX_H

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "pico.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MATRIX_ROWS  2
#define MATRIX_COLS  2

#define MATRIX_COLS_PINS { 2, 3, 4 }
#define MATRIX_ROWS_PINS { 28, 29 }

// keyvalues
static const char kb_matrix_key[2][MATRIX_ROWS][MATRIX_COLS] = 
{
    {
        { 'a', 'b'},
        { 'c', ' '}
    },
    {
        { 'd', '\n'},
        { 'e', 'f' }
    }
};

void matrix_init ( void );
void matrix_scan_task ( void *param );
void mock_output_task ( void *param );



#endif