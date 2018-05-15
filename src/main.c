#include <stdlib.h>
#include <stdio.h>
#include "board.h"

int main() {
  Board board = {{{NIL}}};

  BoardSubset available_cells = board_available_cells(&board);
  int *cell = available_cells.cells[0];

  printf("(%d,%d)\n", cell[0], cell[1]);
  return 0;
}
