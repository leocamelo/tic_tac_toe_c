#ifndef GAME_H
#define GAME_H

#define VERSION "0.1.0"

#include "board.h"
#include "turns_manager.h"

#ifdef TEST_ENV

void mocked_printf(const char *format, ...);
CellPoint mocked_player_move(Player *player, Board *board);

#define PRINTF_FN mocked_printf
#define PLAYER_MOVE_FN mocked_player_move

#else

#define PRINTF_FN printf
#define PLAYER_MOVE_FN player_move

#endif

typedef struct {
  Board board;
  TurnsManager turns_manager;
} Game;

Game game_create();

void game_run(Game *game);

#endif
