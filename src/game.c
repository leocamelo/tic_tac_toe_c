#include <stdlib.h>
#include "game.h"
#include "player.h"
#include "io.h"

Game game_create() {
  Player player1 = {Human, X};
  Player player2 = {Computer, O};
  return (Game){board_create(), (TurnsManager){player1, player2}};
}

static int game_is_over(Game *game) {
  return board_has_match(&game->board) || board_is_full(&game->board);
}

static void game_perform_loop(Game *game) {
  while (1) {
    if (game_is_over(game)) break;

    Player current_player = game->turns_manager.current_player;
    CellPoint point = player_move(&current_player, &game->board);

    if (cell_point_is_null(&point)) break;

    game->board.cells[point.x][point.y] = current_player.marker;
    turns_manager_swap_current_player(&game->turns_manager);
  }
}

void game_run(Game *game) {
  io_print("Tic-Tac-Toe! v" VERSION);
  game_perform_loop(game);
  io_print("Game Over");
}
