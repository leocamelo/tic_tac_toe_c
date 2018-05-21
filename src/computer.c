#include <stdlib.h>
#include <time.h>
#include "computer.h"

static CellPoint computer_center_move(Board *board) {
  int center = BOARD_SIZE / 2;

  if (CELL_IS_EMPTY(board->cells[center][center])) {
    return (CellPoint){center, center};
  }
  return (CellPoint){-1, -1};
}

static CellPoint computer_random_move(Board *board) {
  BoardSubset available_cells = board_available_cells(board);
  if (available_cells.size == 0) return (CellPoint){-1, -1};

  srand(time(NULL));
  return available_cells.points[rand() % available_cells.size];
}

CellPoint computer_move(Board board) {
  CellPoint center_move = computer_center_move(&board);
  if (center_move.x != -1) return center_move;

  CellPoint random_move = computer_random_move(&board);
  if (random_move.x != -1) return random_move;

  return (CellPoint){-1, -1};
}
