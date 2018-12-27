#include <stdlib.h>
#include "check_player.h"
#include "../src/player.h"

CellPoint mocked_human_move(Board *board) {
  (void)(board);
  return (CellPoint){1, 1};
}

CellPoint mocked_computer_move(Board *board, Cell marker) {
  (void)(board);
  (void)(marker);
  return (CellPoint){2, 2};
}

START_TEST(test_player_move_should_call_human_move_for_human_players){
  Player player = {Human, X};
  Board board = board_create();

  CellPoint point = player_move(&player, &board);

  ck_assert_int_eq(point.x, 1);
  ck_assert_int_eq(point.y, 1);
}
END_TEST

START_TEST(test_player_move_should_call_computer_move_for_computer_players){
  Player player = {Computer, O};
  Board board = board_create();

  CellPoint point = player_move(&player, &board);

  ck_assert_int_eq(point.x, 2);
  ck_assert_int_eq(point.y, 2);
}
END_TEST

TCase *player_tcase(void) {
  TCase *tcase = tcase_create("player");

  tcase_add_test(tcase, test_player_move_should_call_human_move_for_human_players);
  tcase_add_test(tcase, test_player_move_should_call_computer_move_for_computer_players);

  return tcase;
}
