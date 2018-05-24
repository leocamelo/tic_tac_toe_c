#include <stdlib.h>
#include "turns_manager.h"

void turns_manager_swap_current_player(TurnsManager *turns_manager) {
  Player temp_player = turns_manager->current_player;
  turns_manager->current_player = turns_manager->next_player;
  turns_manager->next_player = temp_player;
}
