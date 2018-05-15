#include <stdlib.h>
#include "unity/unity.h"
#include "../src/board.h"

void test_board_empty_cell_at_should_set_cell_to_nil() {
  Board board = {{{X}}};
  TEST_ASSERT(board.cells[0][0] == X);

  board_empty_cell_at(&board, 0, 0);
  TEST_ASSERT_EQUAL_INT(board.cells[0][0], NIL);
}

void test_board_available_cells_should_return_all_empty_cells() {
  Board board = {{{NIL, X, X}, {X, NIL, X}, {X, X, NIL}}};
  BoardSubset subset = board_available_cells(&board);

  const int expectedSize = 3;
  const int expected[][2] = {{0, 0}, {1, 1}, {2, 2}};

  TEST_ASSERT_EQUAL_INT(expectedSize, subset.size);

  for (int i = 0; i < expectedSize; i++) {
    TEST_ASSERT_EQUAL_INT_ARRAY(expected[i], subset.cells[i], 2);
  }
}

void test_board_is_full_when_is_not_fully_marked_should_return_false() {
  Board board = {{{X, X, NIL}, {X, X, X}, {X, X, X}}};
  TEST_ASSERT_FALSE(board_is_full(&board));
}

void test_board_is_fill_when_is_fully_marked_should_return_true() {
  Board board = {{{X, X, X}, {X, X, X}, {X, X, X}}};
  TEST_ASSERT_TRUE(board_is_full(&board));
}
