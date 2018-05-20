#include <stdlib.h>
#include <check.h>
#include "check_board.h"
#include "check_computer.h"

static Suite *tic_tac_toe_suite() {
  Suite *suite = suite_create("tic_tac_toe");

  suite_add_tcase(suite, board_tcase());
  suite_add_tcase(suite, computer_tcase());

  return suite;
}

int main() {
  int ntests_failed;

  Suite *suite = tic_tac_toe_suite();
  SRunner *srunner = srunner_create(suite);

  srunner_run_all(srunner, CK_NORMAL);
  ntests_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return ntests_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
