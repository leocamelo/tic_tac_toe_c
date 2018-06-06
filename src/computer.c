#include <stdlib.h>
#include <time.h>
#include "computer.h"

static int computer_check_board_match(Board board, CellPoint point, Cell marker) {
  board.cells[point.x][point.y] = marker;
  return board_has_match(&board);
}

static CellPoint computer_to_over_move(Board *board, BoardSubset *subset, Cell marker) {
  int i;

  for (i = 0; i < subset->size; i++) {
    if (computer_check_board_match(*board, subset->points[i], marker)) {
      return subset->points[i];
    }
  }

  marker = (marker == X ? O : X);
  for (i = 0; i < subset->size; i++) {
    if (computer_check_board_match(*board, subset->points[i], marker)) {
      return subset->points[i];
    }
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

static CellPoint computer_random_move(BoardSubset *subset) {
  srand(time(NULL));
  return subset->points[rand() % subset->size];
}

CellPoint computer_move(Board *board, Cell marker) {
  BoardSubset subset = board_available_cells(board);
  if (!subset.size) return cell_point_null();

  CellPoint move = computer_to_over_move(board, &subset, marker);
  if (cell_point_is_null(&move)) move = computer_center_move(board);
  if (cell_point_is_null(&move)) move = computer_random_move(&subset);

  board_subset_free(&subset);
  return move;
}
