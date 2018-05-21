#include <stdlib.h>
#include "check_computer.h"
#include "../src/computer.h"

START_TEST(test_computer_move_should_return_the_center_point_when_it_cans) {
  int center = BOARD_SIZE / 2;

  Board board = board_create();
  CellPoint point = computer_move(board);

  ck_assert_int_eq(point.x, center);
  ck_assert_int_eq(point.y, center);
}
END_TEST

START_TEST(test_computer_move_should_return_at_last_a_random_empty_point) {
  Board board = {{
    {_, X, O},
    {O, O, X},
    {X, O, O}
  }};

  CellPoint point = computer_move(board);

  ck_assert_int_eq(point.x, 0);
  ck_assert_int_eq(point.y, 0);
}
END_TEST

TCase *computer_tcase() {
  TCase *tcase = tcase_create("computer");

  tcase_add_test(tcase, test_computer_move_should_return_the_center_point_when_it_cans);
  tcase_add_test(tcase, test_computer_move_should_return_at_last_a_random_empty_point);

  return tcase;
}
