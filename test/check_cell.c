#include <stdlib.h>
#include "check_cell.h"
#include "../src/cell.h"

START_TEST(test_cell_is_empty_returns_true_for_empty_cell) {
  Cell cell = _;
  ck_assert(cell_is_empty(cell));
}
END_TEST

START_TEST(test_cell_is_empty_returns_false_for_non_empty_cell) {
  Cell cell_x = X;
  Cell cell_o = O;
  ck_assert(!cell_is_empty(cell_x));
  ck_assert(!cell_is_empty(cell_o));
}
END_TEST

START_TEST(test_cell_point_is_null_returns_true_for_out_of_board_points) {
  CellPoint point = {-1, -1};
  ck_assert(cell_point_is_null(&point));
}
END_TEST

START_TEST(test_cell_point_is_null_returns_false_for_in_board_points) {
  CellPoint point = {1, 1};
  ck_assert(!cell_point_is_null(&point));
}
END_TEST

START_TEST(test_cell_point_null_returns_an_out_of_board_point) {
  CellPoint point = cell_point_null();
  ck_assert(cell_point_is_null(&point));
}
END_TEST

TCase *cell_tcase(void) {
  TCase *tcase = tcase_create("cell");

  tcase_add_test(tcase, test_cell_is_empty_returns_true_for_empty_cell);
  tcase_add_test(tcase, test_cell_is_empty_returns_false_for_non_empty_cell);

  tcase_add_test(tcase, test_cell_point_is_null_returns_true_for_out_of_board_points);
  tcase_add_test(tcase, test_cell_point_is_null_returns_false_for_in_board_points);

  tcase_add_test(tcase, test_cell_point_null_returns_an_out_of_board_point);

  return tcase;
}
