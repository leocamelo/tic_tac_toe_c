#include <stdlib.h>
#include <time.h>
#include "computer.h"

static int computer_check_board_match(Board board, CellPoint *point, Cell marker) {
  board.cells[point->x][point->y] = marker;
  return board_has_match(&board);
}

static CellPoint *computer_to_over_move(Board *board, BoardSubset *subset, Cell marker) {
  int i, j;
  int size = subset->size;

  CellPoint *point;
  Cell markers[2] = {marker, marker == X ? O : X};

  for (i = 0; i < 2; i++) {
    for (j = 0; j < size; j++) {
      point = subset->points[j];

      if (computer_check_board_match(*board, point, markers[i])) {
        return cell_point_copy(point);
      }
    }
  }

  return NULL;
}

static CellPoint *computer_center_move(Board *board) {
  int center = BOARD_SIZE / 2;

  if (cell_is_empty(board->cells[center][center])) {
    return cell_point_create(center, center);
  }
  return NULL;
}

static CellPoint *computer_random_move(BoardSubset *subset) {
  srand(time(NULL));
  return cell_point_copy(subset->points[rand() % subset->size]);
}

CellPoint *computer_move(Board *board, Cell marker) {
  BoardSubset *subset = board_available_cells(board);
  if (!subset->size) return NULL;

  CellPoint *point = computer_to_over_move(board, subset, marker);
  if (!point) point = computer_center_move(board);
  if (!point) point = computer_random_move(subset);

  board_subset_free(subset);
  return point;
}
