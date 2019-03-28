#include <stdlib.h>
#include "player.h"
#include "computer.h"
#include "human.h"

Player *player_create(PlayerKind kind, Cell marker) {
  Player *player = malloc(sizeof(Player));

  player->kind = kind;
  player->marker = marker;

  return player;
}

CellPoint *player_move(Player *player, Board *board) {
  switch (player->kind) {
    case Human:
      return HUMAN_MOVE_FN(board);
    case Computer:
      return COMPUTER_MOVE_FN(board, player->marker);
    default:
      return NULL;
  }
}
