#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

typedef enum {
  Human, Computer
} PlayerKind;

typedef struct {
  PlayerKind kind;
  Cell marker;
} Player;

CellPoint player_move(Player *player, Board *board);

#endif
