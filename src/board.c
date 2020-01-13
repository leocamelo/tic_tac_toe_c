#include <stdlib.h>
#include <math.h>
#include "board.h"

#define IS_MATCH(count) abs(count) == BOARD_SIZE

Board *board_create(void) {
  Board *board = malloc(sizeof(Board));

  int i, j;

  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      board->cells[i][j] = _;
    }
  }

  return board;
}

BoardSubset *board_available_cells(Board *board) {
  BoardSubset *subset = malloc(sizeof(BoardSubset));
  CellPoint **points = malloc(sizeof(CellPoint *) * pow(BOARD_SIZE, 2));

  int i, j;
  int size = 0;

  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      if (cell_is_empty(board->cells[i][j])) {
        points[size++] = cell_point_create(i, j);
      }
    }
  }

  subset->size = size;
  subset->points = points;

  return subset;
}

void board_subset_free(BoardSubset *subset) {
  int i;
  int size = subset->size;

  for (i = 0; i < size; i++) {
    free(subset->points[i]);
  }
  free(subset->points);
}

int board_is_full(Board *board) {
  int i, j;

  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      if (cell_is_empty(board->cells[i][j])) return 0;
    }
  }
  return 1;
}

static int board_has_lr_diagonal_match(Board *board) {
  int i;
  int count = 0;

  for (i = 0; i < BOARD_SIZE; i++) {
    if (board->cells[i][i] == X) count++;
    else if (board->cells[i][i] == O) count--;
  }
  return IS_MATCH(count);
}

static int board_has_rl_diagonal_match(Board *board) {
  int i;
  int count = 0;
  int pivot = BOARD_SIZE - 1;

  for (i = 0; i < BOARD_SIZE; i++) {
    if (board->cells[i][pivot - i] == X) count++;
    else if (board->cells[i][pivot - i] == O) count--;
  }
  return IS_MATCH(count);
}

static int board_has_row_match(Board *board) {
  int i, j, count;

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
  int i, j, count;

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
