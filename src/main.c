/* Kernel includes. */
#include "FreeRTOS.h" /* Must come first. */
#include "task.h"     /* RTOS task related API prototypes. */

#include "pico.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/adc.h"

#include "utils.h"

#include "matrix.h"
#include "joystick.h"

#include "leds.h"


void brain ( void* param )
{
    matrix_handle_t matrix = matrix_init_default();
    joystick_handle_t joystick = joystick_init_default();

    

    matrix_result_t previous_scan = 0;
    for (;;)
    {

        
        matrix_result_t matrix_result = matrix_scan(matrix);
        joystick_result_t joystick_result = joystick_scan(joystick);

        printf(PRINTF_BINARY_PATTERN_INT32"\t", PRINTF_BYTE_TO_BINARY_INT32(matrix_result));
        printf("X: %.04f Y: %.04f\n", joystick_result.x, joystick_result.y);

        previous_scan = matrix_result;

        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

void leds_task ( void* param )
{
    leds_handle_t leds = leds_init_default();

    for (;;)
    {
        leds_show(leds);

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void main ( void ) 
{
    stdio_init_all();

    xTaskCreate(brain, "BRAIN", 1024*10, NULL, tskIDLE_PRIORITY+5, NULL);
    xTaskCreate(leds_task, "leds_task", 1024*10, NULL, tskIDLE_PRIORITY+5, NULL);

    vTaskStartScheduler();
    panic_unsupported();
}