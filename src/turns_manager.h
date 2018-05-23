#ifndef TURNS_MANAGER_H
#define TURNS_MANAGER_H

#include "player.h"

typedef struct {
  Player current_player;
  Player next_player;
} TurnsManager;

void turns_manager_swap_current_player(TurnsManager *turns_manager);

#endif
