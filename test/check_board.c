#include <stdlib.h>
#include "check_board.h"
#include "../src/board.h"

START_TEST(test_board_create_should_returns_an_empty_board) {
  Board board = board_create();
  int i, j;

  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      ck_assert(cell_is_empty(board.cells[i][j]));
    }
  }
}
END_TEST

START_TEST(test_board_empty_cell_at_should_set_cell_to_nil) {
  Board board = {{{X}}};
  ck_assert(!cell_is_empty(board.cells[0][0]));

  board_empty_cell_at(&board, &(CellPoint){0, 0});
  ck_assert(cell_is_empty(board.cells[0][0]));
}
END_TEST

START_TEST(test_board_available_cells_should_return_all_empty_cells) {
  Board board = {{
    {_, X, X},
    {X, _, X},
    {X, X, _}
  }};

  int i;
  const int expectedSize = 3;
  const int expected[][2] = {{0, 0}, {1, 1}, {2, 2}};
  BoardSubset available_cells = board_available_cells(&board);

  ck_assert_int_eq(available_cells.size, expectedSize);

  for (i = 0; i < expectedSize; i++) {
    ck_assert_int_eq(available_cells.points[i].x, expected[i][0]);
    ck_assert_int_eq(available_cells.points[i].y, expected[i][1]);
  }
  board_subset_free(&available_cells);
}
END_TEST

START_TEST(test_board_is_full_when_is_not_fully_marked_should_return_false) {
  Board board = {{
    {X, O, _},
    {O, X, O},
    {X, O, X}
  }};
  ck_assert(!board_is_full(&board));
}
END_TEST

START_TEST(test_board_is_full_when_is_fully_marked_should_return_true) {
  Board board = {{
    {X, O, X},
    {O, X, O},
    {X, O, X}
  }};
  ck_assert(board_is_full(&board));
}
END_TEST

START_TEST(test_board_has_match_when_doenst_have_should_return_false) {
  Board board = board_create();
  ck_assert(!board_has_match(&board));
}
END_TEST

START_TEST(test_board_has_match_when_have_in_diagonal_lr_should_return_true) {
  Board board_x = {{
    {X, _, _},
    {_, X, _},
    {_, _, X}
  }};
  Board board_o = {{
    {O, _, _},
    {_, O, _},
    {_, _, O}
  }};
  ck_assert(board_has_match(&board_x));
  ck_assert(board_has_match(&board_o));
}
END_TEST

START_TEST(test_board_has_match_when_have_in_diagonal_rl_should_return_true) {}
  Board board_x = {{
    {_, _, X},
    {_, X, _},
    {X, _, _}
  }};
  Board board_o = {{
    {_, _, O},
    {_, O, _},
    {O, _, _}
  }};
  ck_assert(board_has_match(&board_x));
  ck_assert(board_has_match(&board_o));
END_TEST

START_TEST(test_board_has_match_when_have_in_horizontal_should_return_true) {
  Board board_x = {{
    {X, X, X},
    {_, _, _},
    {_, _, _}
  }};
  Board board_o = {{
    {_, _, _},
    {O, O, O},
    {_, _, _}
  }};
  ck_assert(board_has_match(&board_x));
  ck_assert(board_has_match(&board_o));
}
END_TEST

START_TEST(test_board_has_match_when_have_in_vertical_should_return_true) {
  Board board_x = {{
    {_, X, _},
    {_, X, _},
    {_, X, _}
  }};
  Board board_o = {{
    {_, _, O},
    {_, _, O},
    {_, _, O}
  }};
  ck_assert(board_has_match(&board_x));
  ck_assert(board_has_match(&board_o));
}
END_TEST

TCase *board_tcase() {
  TCase *tcase = tcase_create("board");

  tcase_add_test(tcase, test_board_create_should_returns_an_empty_board);

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
