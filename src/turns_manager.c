#include <stdlib.h>
#include "turns_manager.h"

TurnsManager *turns_manager_create(Player *player1, Player *player2) {
  TurnsManager *turns_manager = malloc(sizeof(TurnsManager));

  turns_manager->current_player = player1;
  turns_manager->next_player = player2;

  return turns_manager;
}

void turns_manager_swap_current_player(TurnsManager *turns_manager) {
  Player *temp_player = turns_manager->current_player;

  turns_manager->current_player = turns_manager->next_player;
  turns_manager->next_player = temp_player;
}
