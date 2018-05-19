#include <stdlib.h>
#include <check.h>
#include "check_board.h"
#include "../src/board.h"

START_TEST(test_board_empty_cell_at_should_set_cell_to_nil) {
  Board board = {{{X}}};
  ck_assert(board.cells[0][0] == X);

  board_empty_cell_at(&board, 0, 0);
  ck_assert_int_eq(board.cells[0][0], NIL);
}
END_TEST

START_TEST(test_board_available_cells_should_return_all_empty_cells) {
  Board board = {{{NIL, X, X}, {X, NIL, X}, {X, X, NIL}}};
  BoardSubset subset = board_available_cells(&board);

  int i;
  const int expectedSize = 3;
  const int expected[][2] = {{0, 0}, {1, 1}, {2, 2}};

  ck_assert_int_eq(expectedSize, subset.size);

  for (i = 0; i < expectedSize; i++) {
    ck_assert_int_eq(expected[i][0], subset.cells[i][0]);
    ck_assert_int_eq(expected[i][1], subset.cells[i][1]);
  }
  board_subset_free(&subset);
}
END_TEST

START_TEST(test_board_is_full_when_is_not_fully_marked_should_return_false) {
  Board board = {{{X, X, NIL}, {X, X, X}, {X, X, X}}};
  ck_assert_int_eq(board_is_full(&board), 0);
}
END_TEST

START_TEST(test_board_is_fill_when_is_fully_marked_should_return_true) {
  Board board = {{{X, X, X}, {X, X, X}, {X, X, X}}};
  ck_assert_int_eq(board_is_full(&board), 1);
}
END_TEST

TCase *board_tcase() {
  TCase *tcase = tcase_create("board");

  tcase_add_test(tcase, test_board_empty_cell_at_should_set_cell_to_nil);
  tcase_add_test(tcase, test_board_available_cells_should_return_all_empty_cells);
  tcase_add_test(tcase, test_board_is_full_when_is_not_fully_marked_should_return_false);
  tcase_add_test(tcase, test_board_is_fill_when_is_fully_marked_should_return_true);

  return tcase;
}
