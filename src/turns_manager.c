#include <stdlib.h>
#include "turns_manager.h"

void turns_manager_swap_current_player(TurnsManager *turns_manager) {
  Player current_player = turns_manager->current_player;
  Player next_player = turns_manager->next_player;

  turns_manager->current_player = next_player;
  turns_manager->next_player = current_player;
}
