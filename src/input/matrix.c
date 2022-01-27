#include "matrix.h"

matrix_handle_t matrix_init ( PIO pio, uint sm, uint row_pin_start, uint row_count, uint col_pin_start, uint col_count )
{
    matrix_handle_t m = malloc(sizeof(matrix_t));
    uint offset = pio_add_program(pio, &matrix_scan_pio_program);
    matrix_scan_pio_init(pio, sm, offset, row_pin_start, row_count, col_pin_start, col_count);
    pio_sm_set_enabled(pio, sm, true);

    m->pio = pio;
    m->sm = sm;
    return m;
}

matrix_handle_t matrix_init_default ()
{
    PIO pio = pio0;
    uint sm = pio_claim_unused_sm(pio, true);
    return matrix_init(pio, sm, BOARD_ROW_START_PIN, BOARD_NROW, BOARD_COL_START_PIN, BOARD_NCOL);
}

matrix_result_t matrix_scan ( matrix_handle_t matrix )
{
    return matrix_scan_pio(matrix->pio, matrix->sm);
}