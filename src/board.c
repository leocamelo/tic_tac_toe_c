#include <stdlib.h>
#include "board.h"

#define IS_MATCH(count) abs(count) == BOARD_SIZE

Board board_create() {
  return (Board){{{_}}};
}

void board_empty_cell_at(Board *board, CellPoint *point) {
  board->cells[point->x][point->y] = _;
}

static int board_available_cells_count(Board *board) {
  int count = 0, i, j;

  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      if (CELL_IS_EMPTY(board->cells[i][j])) count++;
    }
  }
  return count;
}

void board_subset_free(BoardSubset *subset) {
  free(subset->points);
}

BoardSubset board_available_cells(Board *board) {
  int aux = 0, i, j;
  int count = board_available_cells_count(board);
  BoardSubset subset = { count, malloc(sizeof(CellPoint) * count) };

  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      if (CELL_IS_EMPTY(board->cells[i][j])) {
        subset.points[aux] = (CellPoint){i, j};
        aux++;
      }
    }
  }
  return subset;
}

int board_is_full(Board *board) {
  int i, j;

  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      if (CELL_IS_EMPTY(board->cells[i][j])) return 0;
    }
  }
  return 1;
}

static int board_has_lr_diagonal_match(Board *board) {
  int count = 0, i;

  for (i = 0; i < BOARD_SIZE; i++) {
    if (board->cells[i][i] == X) count++;
    else if (board->cells[i][i] == O) count--;
  }
  return IS_MATCH(count);
}

static int board_has_rl_diagonal_match(Board *board) {
  int count = 0, i;
  int pivot = BOARD_SIZE - 1;

  for (i = 0; i < BOARD_SIZE; i++) {
    if (board->cells[i][pivot - i] == X) count++;
    else if (board->cells[i][pivot - i] == O) count--;
  }
  return IS_MATCH(count);
}

static int board_has_row_match(Board *board) {
  int count, i, j;

  for (i = 0; i < BOARD_SIZE; i++) {
    count = 0;

    for (j = 0; j < BOARD_SIZE; j++) {
      if (board->cells[i][j] == X) count++;
      else if (board->cells[i][j] == O) count--;
    }
    if (IS_MATCH(count)) return 1;
  }
  return 0;
}

static int board_has_col_match(Board *board) {
  int count, i, j;

  for (i = 0; i < BOARD_SIZE; i++) {
    count = 0;

    for (j = 0; j < BOARD_SIZE; j++) {
      if (board->cells[j][i] == X) count++;
      else if (board->cells[j][i] == O) count--;
    }
    if (IS_MATCH(count)) return 1;
  }
  return 0;
}

int board_has_match(Board *board) {
  return board_has_lr_diagonal_match(board) ||
         board_has_rl_diagonal_match(board) ||
         board_has_row_match(board) ||
         board_has_col_match(board);
}
