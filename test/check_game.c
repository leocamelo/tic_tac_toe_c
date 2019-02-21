#include <stdlib.h>
#include "check_game.h"
#include "../src/game.h"

static int player_move_count = 0;

CellPoint mocked_player_move(Player *player, Board *board) {
  (void)(player);
  player_move_count++;
  BoardSubset subset = board_available_cells(board);
  return subset.size ? subset.points[0] : cell_point_null();
}

START_TEST(test_game_create_should_returns_an_initial_game) {
  Game *game = game_create();

  int i, j;
  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      ck_assert(cell_is_empty(game->board->cells[i][j]));
    }
  }

  ck_assert_int_eq(game->turns_manager->current_player.kind, Human);
  ck_assert_int_eq(game->turns_manager->current_player.marker, X);

  ck_assert_int_eq(game->turns_manager->next_player.kind, Computer);
  ck_assert_int_eq(game->turns_manager->next_player.marker, O);
}
END_TEST

START_TEST(test_game_run_should_loops_until_game_is_over) {
  Game *game = game_create();
  game_run(game);

  ck_assert_int_eq(player_move_count, 7);
}
END_TEST

TCase *game_tcase(void) {
  TCase *tcase = tcase_create("game");

  tcase_add_test(tcase, test_game_create_should_returns_an_initial_game);

  tcase_add_test(tcase, test_game_run_should_loops_until_game_is_over);

  return tcase;
}
