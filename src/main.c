#include <stdlib.h>
#include <stdio.h>
#include "board.h"

int main() {
  Board board = {{{NIL}}};
  BoardSubset available_cells = board_available_cells(&board);
  CellPoint point = available_cells.points[0];

  printf("(%d,%d)\n", point.x, point.y);
  board_subset_free(&available_cells);
  return 0;
}
