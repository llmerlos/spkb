#include "leds.h"

static inline void leds_put_pixel(leds_handle_t leds, uint32_t pixel_grb)
{
    leds_show_pio_put_pixel(leds->pio, leds->sm, pixel_grb);
}

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) 
{
    return ((uint32_t) (r) << 8) | ((uint32_t) (g) << 16) | (uint32_t) (b);
}

leds_handle_t leds_init ( PIO pio, uint sm, uint led_pin )
{
    leds_handle_t leds = malloc(sizeof(leds_t));
    uint offset = pio_add_program(pio, &leds_show_pio_program);
    leds_show_pio_program_init(pio, sm, offset, led_pin, 800000, false);
    pio_sm_set_enabled(pio, sm, true);

    leds->pio = pio;
    leds->sm = sm;

    for (uint i = 0; i < BOARD_NLED; i++)
    {
        leds_put_pixel(leds, 0);
    }
    return leds;
}

leds_handle_t leds_init_default ()
{
    PIO pio = pio1;
    uint sm = pio_claim_unused_sm(pio, true);
    return leds_init(pio, sm, BOARD_LED);
}

static int t = 0;
void leds_show ( leds_handle_t leds )
{
    static int status = 1;
    for (uint i = 0; i < BOARD_NLED; i++) {
        if (status == 1)
        {
            printf("1");
            leds_put_pixel(leds, urgb_u32(0, 0, 0xff));
        } else {
            printf("0");
            leds_put_pixel(leds, urgb_u32(0, 0, 0));
        }
    }
    status = 1 - status;
    printf("\n");
    t++;
    t %= BOARD_NLED;
}