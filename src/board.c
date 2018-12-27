#include <stdlib.h>
#include <math.h>
#include "board.h"

#define IS_MATCH(count) abs(count) == BOARD_SIZE

Board board_create(void) {
  return (Board){{{_}}};
}

void board_subset_free(BoardSubset *subset) {
  free(subset->points);
}

BoardSubset board_available_cells(Board *board) {
  int i, j;
  int size = 0;
  CellPoint *points = malloc(sizeof(CellPoint) * pow(BOARD_SIZE, 2));

  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      if (cell_is_empty(board->cells[i][j])) {
        points[size++] = (CellPoint){i, j};
      }
    }
  }
  return (BoardSubset){size, points};
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
