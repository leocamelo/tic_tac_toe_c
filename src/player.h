#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

#ifdef TEST_ENV

CellPoint *mocked_human_move(Board *board);
CellPoint *mocked_computer_move(Board *board, Cell marker);

#define HUMAN_MOVE_FN mocked_human_move
#define COMPUTER_MOVE_FN mocked_computer_move

#else

#define HUMAN_MOVE_FN human_move
#define COMPUTER_MOVE_FN computer_move

#endif

typedef enum {
  Human, Computer
} PlayerKind;

typedef struct {
  PlayerKind kind;
  Cell marker;
} Player;

Player *player_create(PlayerKind kind, Cell marker);

CellPoint *player_move(Player *player, Board *board);

#endif
