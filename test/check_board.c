#include <stdlib.h>
#include <check.h>
#include "check_board.h"
#include "../src/board.h"

START_TEST(test_board_empty_cell_at_should_set_cell_to_nil) {
  Board board = {{{X}}};
  ck_assert(board.cells[0][0] == X);

  board_empty_cell_at(&board, &(CellPoint){0, 0});
  ck_assert_int_eq(board.cells[0][0], NIL);
}
END_TEST

START_TEST(test_board_available_cells_should_return_all_empty_cells) {
  Board board = {{{NIL, X, X}, {X, NIL, X}, {X, X, NIL}}};
  BoardSubset available_cells = board_available_cells(&board);

  int i;
  const int expectedSize = 3;
  const int expected[][2] = {{0, 0}, {1, 1}, {2, 2}};

  ck_assert_int_eq(expectedSize, available_cells.size);

  for (i = 0; i < expectedSize; i++) {
    ck_assert_int_eq(expected[i][0], available_cells.points[i].x);
    ck_assert_int_eq(expected[i][1], available_cells.points[i].y);
  }
  board_subset_free(&available_cells);
}
END_TEST

START_TEST(test_board_is_full_when_is_not_fully_marked_should_return_false) {
  Board board = {{{X, O, NIL}, {O, X, O}, {X, O, X}}};
  ck_assert_int_eq(board_is_full(&board), 0);
}
END_TEST

START_TEST(test_board_is_full_when_is_fully_marked_should_return_true) {
  Board board = {{{X, O, X}, {O, X, O}, {X, O, X}}};
  ck_assert_int_eq(board_is_full(&board), 1);
}
END_TEST

START_TEST(test_board_has_match_when_doenst_have_should_return_false) {
  Board board = {{{NIL}}};
  ck_assert_int_eq(board_has_match(&board), 0);
}
END_TEST

START_TEST(test_board_has_match_when_have_in_diagonal_lr_should_return_true) {
  Board board_x = {{{X, NIL, NIL}, {NIL, X, NIL}, {NIL, NIL, X}}};
  Board board_o = {{{O, NIL, NIL}, {NIL, O, NIL}, {NIL, NIL, O}}};
  ck_assert_int_eq(board_has_match(&board_x), 1);
  ck_assert_int_eq(board_has_match(&board_o), 1);
}
END_TEST

START_TEST(test_board_has_match_when_have_in_diagonal_rl_should_return_true) {}
  Board board_x = {{{NIL, NIL, X}, {NIL, X, NIL}, {X, NIL, NIL}}};
  Board board_o = {{{NIL, NIL, O}, {NIL, O, NIL}, {O, NIL, NIL}}};
  ck_assert_int_eq(board_has_match(&board_x), 1);
  ck_assert_int_eq(board_has_match(&board_o), 1);
END_TEST

START_TEST(test_board_has_match_when_have_in_horizontal_should_return_true) {
  Board board_x = {{{X, X, X}, {NIL, NIL, NIL}, {NIL, NIL, NIL}}};
  Board board_o = {{{NIL, NIL, NIL}, {O, O, O}, {NIL, NIL, NIL}}};
  ck_assert_int_eq(board_has_match(&board_x), 1);
  ck_assert_int_eq(board_has_match(&board_o), 1);
}
END_TEST

START_TEST(test_board_has_match_when_have_in_vertical_should_return_true) {
  Board board_x = {{{NIL, X, NIL}, {NIL, X, NIL}, {NIL, X, NIL}}};
  Board board_o = {{{NIL, NIL, O}, {NIL, NIL, O}, {NIL, NIL, O}}};
  ck_assert_int_eq(board_has_match(&board_x), 1);
  ck_assert_int_eq(board_has_match(&board_o), 1);
}
END_TEST

TCase *board_tcase() {
  TCase *tcase = tcase_create("board");

  tcase_add_test(tcase, test_board_empty_cell_at_should_set_cell_to_nil);

  tcase_add_test(tcase, test_board_available_cells_should_return_all_empty_cells);
  tcase_add_test(tcase, test_board_is_full_when_is_not_fully_marked_should_return_false);
  tcase_add_test(tcase, test_board_is_full_when_is_fully_marked_should_return_true);

  tcase_add_test(tcase, test_board_has_match_when_doenst_have_should_return_false);
  tcase_add_test(tcase, test_board_has_match_when_have_in_diagonal_lr_should_return_true);
  tcase_add_test(tcase, test_board_has_match_when_have_in_diagonal_rl_should_return_true);
  tcase_add_test(tcase, test_board_has_match_when_have_in_horizontal_should_return_true);
  tcase_add_test(tcase, test_board_has_match_when_have_in_vertical_should_return_true);

  return tcase;
}
