#include <stdlib.h>
#include <check.h>
#include "check_cell.h"
#include "check_board.h"
#include "check_grid.h"
#include "check_human.h"
#include "check_computer.h"
#include "check_player.h"
#include "check_turns_manager.h"
#include "check_game.h"

void mocked_printf(const char *format, ...);
int mocked_scanf(const char *format, int *pointer);

static Suite *tic_tac_toe_suite(void) {
  Suite *suite = suite_create("tic_tac_toe");

  suite_add_tcase(suite, cell_tcase());
  suite_add_tcase(suite, board_tcase());
  suite_add_tcase(suite, grid_tcase());
  suite_add_tcase(suite, human_tcase());
  suite_add_tcase(suite, computer_tcase());
  suite_add_tcase(suite, player_tcase());
  suite_add_tcase(suite, turns_manager_tcase());
  suite_add_tcase(suite, game_tcase());

  return suite;
}

int main(void) {
  int ntests_failed;

  Suite *suite = tic_tac_toe_suite();
  SRunner *srunner = srunner_create(suite);

  srunner_run_all(srunner, CK_NORMAL);
  ntests_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return ntests_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

void mocked_printf(const char *format, ...) {
  (void)(format);
}

int mocked_scanf(const char *format, int *pointer) {
  (void)(format);
  *pointer = 5;
  return 1;
}
