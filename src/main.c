#include <stdlib.h>
#include "game.h"

int main(void) {
  Game game = game_create();
  game_run(&game);
  return 0;
}
