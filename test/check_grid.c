#include <stdlib.h>
#include "check_grid.h"
#include "../src/grid.h"

START_TEST(test_grid_from_board_should_return_all_board_cells_as_string) {
  Board board = {{
    {_, X, _},
    {O, _, _},
    {_, _, _}
  }};

  ck_assert_str_eq(grid_from_board(&board),
    "\n 1 | X | 3"
    "\n===+===+==="
    "\n O | 5 | 6"
    "\n===+===+==="
    "\n 7 | 8 | 9"
    "\n"
  );
}
END_TEST

TCase *grid_tcase(void) {
  TCase *tcase = tcase_create("grid");

  tcase_add_test(tcase, test_grid_from_board_should_return_all_board_cells_as_string);

  return tcase;
}
