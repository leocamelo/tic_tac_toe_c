#ifndef GAME_H
#define GAME_H

#define VERSION "0.1.0"

#include "board.h"
#include "turns_manager.h"

typedef struct {
  Board board;
  TurnsManager turns_manager;
} Game;

Game game_create();

void game_run(Game *game);

#endif
