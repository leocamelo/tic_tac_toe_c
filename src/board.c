#include <stdlib.h>
#include "board.h"

#define IS_MATCH(count) abs(count) == BOARD_SIZE

void board_empty_cell_at(Board *board, int x, int y) {
  board->cells[x][y] = NIL;
}

static int board_available_cells_count(Board *board) {
  int count = 0, i, j;

  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      if (board->cells[i][j] == NIL) count++;
    }
  }
  return count;
}

void board_subset_free(BoardSubset *subset) {
  free(*subset->cells);
  free(subset->cells);
}

BoardSubset board_available_cells(Board *board) {
  int aux = 0, i, j;
  BoardSubset subset = { board_available_cells_count(board) };
  int **arr = malloc(sizeof(int*) * subset.size);

  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      if (board->cells[i][j] == NIL) {
        arr[aux] = malloc(sizeof(int) * 2);
        arr[aux][0] = i;
        arr[aux][1] = j;
        aux++;
      }
    }
  }
  subset.cells = arr;
  return subset;
}

int board_is_full(Board *board) {
  int i, j;

  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      if (board->cells[i][j] == NIL) return 0;
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
