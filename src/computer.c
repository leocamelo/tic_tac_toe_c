#include <stdlib.h>
#include <time.h>
#include "computer.h"

static int computer_check_board_match(Board board, CellPoint point, Cell marker) {
  board.cells[point.x][point.y] = marker;
  return board_has_match(&board);
}

static CellPoint computer_to_over_move(Board *board, BoardSubset *available_cells, Cell marker) {
  int i;
  CellPoint point;

  for (i = 0; i < available_cells->size; i++) {
    point = available_cells->points[i];
    if (computer_check_board_match(*board, point, marker)) return point;
  }

  marker = (marker == X ? O : X);
  for (i = 0; i < available_cells->size; i++) {
    point = available_cells->points[i];
    if (computer_check_board_match(*board, point, marker)) return point;
  }

  return cell_point_null();
}

static CellPoint computer_center_move(Board *board) {
  int center = BOARD_SIZE / 2;

  if (cell_is_empty(board->cells[center][center])) {
    return (CellPoint){center, center};
  }
  return cell_point_null();
}

static CellPoint computer_random_move(BoardSubset *available_cells) {
  srand(time(NULL));
  return available_cells->points[rand() % available_cells->size];
}

CellPoint computer_move(Board *board, Cell marker) {
  BoardSubset available_cells = board_available_cells(board);
  if (available_cells.size == 0) return cell_point_null();

  CellPoint move = computer_to_over_move(board, &available_cells, marker);
  if (cell_point_is_null(&move)) move = computer_center_move(board);
  if (cell_point_is_null(&move)) move = computer_random_move(&available_cells);

  board_subset_free(&available_cells);
  return move;
}
