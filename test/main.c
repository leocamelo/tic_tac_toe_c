#include <stdlib.h>
#include "unity/unity.h"
#include "board_test.h"

int main() {
  UNITY_BEGIN();

  RUN_TEST(test_board_empty_cell_at_should_set_cell_to_nil);
  RUN_TEST(test_board_available_cells_should_return_all_empty_cells);
  RUN_TEST(test_board_is_full_when_is_not_fully_marked_should_return_false);
  RUN_TEST(test_board_is_fill_when_is_fully_marked_should_return_true);

  return UNITY_END();
}
