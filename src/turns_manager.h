#ifndef TURNS_MANAGER_H
#define TURNS_MANAGER_H

#include "player.h"

typedef struct {
  Player *current_player;
  Player *next_player;
} TurnsManager;

TurnsManager *turns_manager_create(Player *player1, Player *player2);

void turns_manager_swap_current_player(TurnsManager *turns_manager);

#endif
