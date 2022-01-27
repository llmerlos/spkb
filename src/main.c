/* Kernel includes. */
#include "FreeRTOS.h" /* Must come first. */
#include "task.h"     /* RTOS task related API prototypes. */

#include "pico.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"

#include "utils.h"

#include "matrix.h"


void brain ( void* param )
{
    matrix_pio_t matrix = matrix_pio_init_default();

    uint32_t previous_scan = 0;
    for (;;)
    {
        uint32_t result = matrix_scan(matrix.pio, matrix.sm);

        if (result != previous_scan)
            printf(PRINTF_BINARY_PATTERN_INT32"\n", PRINTF_BYTE_TO_BINARY_INT32(result));
        previous_scan = result;
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

void main( void ) 
{
    stdio_init_all();

    xTaskCreate(brain, "BRAIN", 1024*10, NULL, tskIDLE_PRIORITY+5, NULL);

    printf("Core %d: Launching FreeRTOS scheduler\n", get_core_num());
    /* Start the tasks and timer running. */
    vTaskStartScheduler();
    /* shoulxd never reach here */
    panic_unsupported();
}