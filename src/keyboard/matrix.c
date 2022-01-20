#include "matrix.h"

static uint32_t matrix_gpio_mask_rows;
static uint32_t matrix_gpio_mask_cols;

static uint8_t matrix_pins_cols[MATRIX_COLS] = MATRIX_COLS_PINS;
static uint8_t matrix_pins_rows[MATRIX_ROWS] = MATRIX_ROWS_PINS;

typedef struct matrix_state_t {
    uint32_t slice[2][MATRIX_ROWS];
} matrix_state_t;

QueueHandle_t kb_scan_queue = NULL;

void matrix_init ( void )
{
    


    uint8_t pin;

    for (int ic = 0; ic < MATRIX_COLS; ic++) 
    {
        pin = matrix_pins_cols[ic];

        matrix_gpio_mask_cols |= (1 << pin);
        gpio_init(pin);
        gpio_set_dir(pin, GPIO_IN);
        gpio_pull_up(pin);
    }

    for (int ir = 0; ir < MATRIX_ROWS; ir++) 
    {
        pin = matrix_pins_rows[ir];

        matrix_gpio_mask_rows |= (1 << pin);
        gpio_init(pin);
        gpio_set_dir(pin, GPIO_OUT);
    }

    kb_scan_queue = xQueueCreate(10, sizeof(matrix_state_t));
}


void matrix_scan_task ( void *param )
{
    matrix_state_t current_state;
    bool b_input_changed = false;

    for (;;)
    {
        b_input_changed = false;
        for (int ir = 0; ir < MATRIX_ROWS; ir++)
        {
            gpio_put(matrix_pins_rows[ir], false);
            //busy_wait_us(100);

            uint32_t slice_values = ~(gpio_get_all()) & matrix_gpio_mask_cols;

            if (slice_values != current_state.slice[0][ir])
            {
                b_input_changed = true;
                current_state.slice[0][ir] = slice_values;
            }

            gpio_put(matrix_pins_rows[ir], true);
        }
        
        if (b_input_changed)
        {
            xQueueSend(kb_scan_queue, &current_state, portMAX_DELAY);
        }

        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

void mock_output_task ( void *param )
{
    matrix_state_t previous_state;
    matrix_state_t scan_state;

    for (;;)
    {
        BaseType_t result = xQueueReceive(kb_scan_queue, &scan_state, portMAX_DELAY);

        if (result == pdPASS)
        {
            for (uint8_t ir = 0; ir < MATRIX_ROWS; ir++)
            {
                uint32_t pressed = scan_state.slice[0][ir] & ~(previous_state.slice[0][ir]);
                for ( uint8_t ic = 0; ic < MATRIX_COLS; ic++)
                {
                    uint8_t pin = matrix_pins_cols[ic];
                    if ( ( (pressed >> pin) & 0b1) > 0 )
                    {
                        printf("%c",kb_matrix_key[ir][ic]);
                    }
                }
            }
        }
    }
}