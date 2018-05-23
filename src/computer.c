#include <stdlib.h>
#include <time.h>
#include "computer.h"

static CellPoint computer_center_move(Board *board) {
  int center = BOARD_SIZE / 2;

  if (cell_is_empty(board->cells[center][center])) {
    return (CellPoint){center, center};
  }
  return cell_point_null();
}

static CellPoint computer_random_move(Board *board) {
  BoardSubset available_cells = board_available_cells(board);
  if (available_cells.size == 0) return cell_point_null();

  srand(time(NULL));
  CellPoint point = available_cells.points[rand() % available_cells.size];

  board_subset_free(&available_cells);
  return point;
}

CellPoint computer_move(Board board) {
  CellPoint center_move = computer_center_move(&board);
  if (!cell_point_is_null(&center_move)) return center_move;

  CellPoint random_move = computer_random_move(&board);
  if (!cell_point_is_null(&random_move)) return random_move;

  return cell_point_null();
}
