/* Kernel includes. */
#include "FreeRTOS.h" /* Must come first. */
#include "task.h"     /* RTOS task related API prototypes. */

#include "pico.h"

#include "keyboard.h"

void main ( void ) 
{
    stdio_init_all();

    xTaskCreate(brain, "BRAIN", 1024*10, NULL, tskIDLE_PRIORITY+5, NULL);
    xTaskCreate(leds_task, "LEDS", 1024*5, NULL, tskIDLE_PRIORITY+5, NULL);

    vTaskStartScheduler();
    panic_unsupported();
}