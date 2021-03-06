#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 3

#include "cell.h"

typedef struct {
  Cell cells[BOARD_SIZE][BOARD_SIZE];
} Board;

typedef struct {
  int size;
  CellPoint **points;
} BoardSubset;

Board *board_create(void);

BoardSubset *board_available_cells(Board *board);

void board_subset_free(BoardSubset *subset);

int board_is_full(Board *board);

int board_has_match(Board *board);

#endif
