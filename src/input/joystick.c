#include "joystick.h"

joystick_handle_t joystick_init ( uint pin_x, uint pin_y )
{
    joystick_handle_t joystick = malloc(sizeof(joystick_t));
    uint ch_x = pin_x - 26;
    uint ch_y = pin_y - 26;

    adc_init();
    adc_gpio_init(pin_x);
    adc_gpio_init(pin_y);

    adc_select_input(ch_x);

    joystick->ch_x = ch_x;
    joystick->ch_y = ch_y;
    joystick->min_x = 1<<15;
    joystick->min_y = 1<<15;
    joystick->max_x = 0;
    joystick->max_y = 0;

    return joystick;
}

joystick_handle_t joystick_init_default ()
{
    return joystick_init(BOARD_JOYSTICK_X, BOARD_JOYSTICK_Y);
}

joystick_result_t joystick_scan ( joystick_handle_t joystick )
{
    joystick_result_t result;
    
    adc_select_input(joystick->ch_x);
    uint16_t x = adc_read() >> 4;

    if (x < joystick->min_x )
    {
        joystick->min_x = x;
    }
    else if (x > joystick->max_x)
    {
        joystick->max_x = x;
    }

    adc_select_input(joystick->ch_y);
    uint16_t y = adc_read() >> 4;

    if (y < joystick->min_y )
    {
        joystick->min_y = y;
    }
    else if (y > joystick->max_y)
    {
        joystick->max_y = y;
    }

    result.x = joystick->max_x - joystick->min_x > 0 ? (float) (x - joystick->min_x) / (joystick->max_x - joystick->min_x) : 0.5;
    result.y = joystick->max_y - joystick->min_y > 0 ? (float) (y - joystick->min_y) / (joystick->max_y - joystick->min_y) : 0.5;

    result.x = (result.x < 0.60) && (result.x > 0.40) ? 0.5 : result.x;
    result.y = (result.y < 0.60) && (result.y > 0.40) ? 0.5 : result.y;


    return result;
}