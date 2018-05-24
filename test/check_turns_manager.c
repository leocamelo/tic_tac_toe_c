#include <stdlib.h>
#include "check_turns_manager.h"
#include "../src/turns_manager.h"

START_TEST(test_turns_manager_swap_current_user_should_swaps_it) {
  Player player1 = {Human, X};
  Player player2 = {Computer, O};
  TurnsManager turns_manager = {player1, player2};

  ck_assert_int_eq(turns_manager.current_player.kind, player1.kind);
  ck_assert_int_eq(turns_manager.current_player.marker, player1.marker);

  ck_assert_int_eq(turns_manager.next_player.kind, player2.kind);
  ck_assert_int_eq(turns_manager.next_player.marker, player2.marker);

  turns_manager_swap_current_player(&turns_manager);

  ck_assert_int_eq(turns_manager.current_player.kind, player2.kind);
  ck_assert_int_eq(turns_manager.current_player.marker, player2.marker);

  ck_assert_int_eq(turns_manager.next_player.kind, player1.kind);
  ck_assert_int_eq(turns_manager.next_player.marker, player1.marker);
}
END_TEST

TCase *turns_manager_tcase() {
  TCase *tcase = tcase_create("turns_manager");

  tcase_add_test(tcase, test_turns_manager_swap_current_user_should_swaps_it);

  return tcase;
}
