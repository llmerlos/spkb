/* Kernel includes. */
#include "FreeRTOS.h" /* Must come first. */
#include "task.h"     /* RTOS task related API prototypes. */

#include "pico.h"
#include <stdio.h>
#include "pico/stdlib.h"

#include "matrix.h"

void main( void ) 
{
    stdio_init_all();
    matrix_init();

    xTaskCreate(matrix_scan_task, "MATRIX", 1024, NULL, tskIDLE_PRIORITY+5, NULL);
    xTaskCreate(mock_output_task, "KB_OUTPUT", 1024, NULL, tskIDLE_PRIORITY+4, NULL);

    printf("Core %d: Launching FreeRTOS scheduler\n", get_core_num());
    /* Start the tasks and timer running. */
    vTaskStartScheduler();
    /* shoulxd never reach here */
    panic_unsupported();
}