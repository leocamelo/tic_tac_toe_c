#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "turns_manager.h"

typedef struct {
  Board board;
  TurnsManager turns_manager;
} Game;

Game game_create();

void game_run(Game *game);

#endif
