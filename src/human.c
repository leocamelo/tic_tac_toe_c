#include <stdlib.h>
#include "human.h"
#include "io.h"

CellPoint human_move(Board *board) {
  char *grid = board_cells_grid(board);
  io_print(grid);
  free(grid);

  BoardSubset available_cells = board_available_cells(board);
  CellPoint point = available_cells.points[0];
  board_subset_free(&available_cells);

  return point;
}
