#include <stdlib.h>
#include <stdio.h>
#include "game.h"
#include "grid.h"
#include "player.h"

Game game_create() {
  Player player1 = {Human, X};
  Player player2 = {Computer, O};
  return (Game){board_create(), (TurnsManager){player1, player2}};
}

static int game_is_over(Game *game) {
  return board_has_match(&game->board) || board_is_full(&game->board);
}

static void game_perform_loop(Game *game) {
  Player current_player;
  CellPoint point;

  while (1) {
    current_player = game->turns_manager.current_player;
    point = PLAYER_MOVE_FN(&current_player, &game->board);

    if (cell_point_is_null(&point)) break;

    game->board.cells[point.x][point.y] = current_player.marker;

    if (game_is_over(game)) break;

    turns_manager_swap_current_player(&game->turns_manager);
  }
}

void game_run(Game *game) {
  PRINTF_FN("Tic-Tac-Toe! (v%s)\n", VERSION);
  game_perform_loop(game);
  PRINTF_FN("%s\nGame Over\n", grid_from_board(&game->board));
}
