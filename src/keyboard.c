#include "keyboard.h"

typedef struct keyboard_t {
    uint8_t layer_active[2];
    uint32_t layer_keys[2][N_LAYERS-1];
    matrix_handle_t matrix;
    matrix_result_t matrix_state;
    joystick_handle_t joystick;
    joystick_result_t joystick_state;
} keyboard_t;

typedef keyboard_t* keyboard_handle_t;

keyboard_handle_t keyboard_init ( void )
{
    keyboard_handle_t keyboard = malloc(sizeof(keyboard_t));

    keyboard->matrix = matrix_init_default();
    keyboard->matrix_state = 0;
    keyboard->joystick = joystick_init_default();
    keyboard->joystick_state = (joystick_result_t) { .x = 0, .y = 0 };

    keyboard->layer_active[0] = 0;
    keyboard->layer_active[1] = 0;

    /* Left Side Layer Keys */
    keyboard->layer_keys[SPKB_LEFT][0] = find_key_bitmask(KC_LFK1, SPKB_LEFT);
    keyboard->layer_keys[SPKB_LEFT][1] = find_key_bitmask(KC_LFK2, SPKB_LEFT);

    /* Right Side Layer Keys */
    keyboard->layer_keys[SPKB_RIGHT][0] = find_key_bitmask(KC_LFK1, SPKB_RIGHT);
    keyboard->layer_keys[SPKB_RIGHT][1] = find_key_bitmask(KC_LFK2, SPKB_RIGHT);

    return keyboard;
}

void brain ( void* param )
{
    keyboard_handle_t keyboard = keyboard_init();
    for (;;)
    {

        
        matrix_result_t matrix_result = matrix_scan(keyboard->matrix);
        joystick_result_t joystick_result = joystick_scan(keyboard->joystick);

        printf(PRINTF_BINARY_PATTERN_INT32"\t", PRINTF_BYTE_TO_BINARY_INT32(matrix_result));
        printf("X: %.04f Y: %.04f\n", joystick_result.x, joystick_result.y);

        keyboard->matrix_state = matrix_result;

        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

void kb_handle_matrix_result ( keyboard_handle_t keyboard, matrix_result_t matrix_result )
{
    /* CHECK FOR LAYER KEYS */
    if ( (matrix_result & keyboard->layer_keys[SPKB_LEFT][0]) > 0 )
    {
        keyboard->layer_active[SPKB_LEFT] = 1;
    } 
    else if ( (matrix_result & keyboard->layer_keys[SPKB_LEFT][1]) > 0 )
    {
        keyboard->layer_active[SPKB_LEFT] = 2;
    }
    else
    {
        keyboard->layer_active[SPKB_LEFT] = 3;
    }
    /* CHECK FOR USB ACTION */


    /* CHECK FOR KB ACTION */
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