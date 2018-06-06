#include <stdlib.h>
#include "check_human.h"
#include "../src/human.h"

START_TEST(test_human_cell_point_from_input_should_returns_a_cell_point_by_index) {
  CellPoint point_by1 = human_cell_point_by_index(1);
  CellPoint point_by5 = human_cell_point_by_index(5);
  CellPoint point_by9 = human_cell_point_by_index(9);

  ck_assert_int_eq(point_by1.x, 0);
  ck_assert_int_eq(point_by1.y, 0);

  ck_assert_int_eq(point_by5.x, 1);
  ck_assert_int_eq(point_by5.y, 1);

  ck_assert_int_eq(point_by9.x, 2);
  ck_assert_int_eq(point_by9.y, 2);
}
END_TEST

TCase *human_tcase() {
  TCase *tcase = tcase_create("human");

  tcase_add_test(tcase, test_human_cell_point_from_input_should_returns_a_cell_point_by_index);

  return tcase;
}
