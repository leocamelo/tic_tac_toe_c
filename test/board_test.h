#ifndef BOARD_TEST_H
#define BOARD_TEST_H

void test_board_empty_cell_at_should_set_cell_to_nil();

void test_board_available_cells_should_return_all_empty_cells();

void test_board_is_full_when_is_not_fully_marked_should_return_false();

void test_board_is_fill_when_is_fully_marked_should_return_true();

#endif
