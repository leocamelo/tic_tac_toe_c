#include <stdlib.h>
#include "player.h"
#include "computer.h"
#include "human.h"

CellPoint player_move(Player *player, Board *board) {
  switch (player->kind) {
    case Human:
      return human_move(board);
    case Computer:
      return computer_move(board, player->marker);
    default:
      return cell_point_null();
  }
}
