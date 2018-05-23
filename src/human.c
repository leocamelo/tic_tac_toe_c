#include <stdlib.h>
#include "human.h"

CellPoint human_move(Board board) {
  BoardSubset available_cells = board_available_cells(&board);
  CellPoint point = available_cells.points[0];
  board_subset_free(&available_cells);
  return point;
}
