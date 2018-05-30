#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 3

#include "cell.h"

typedef struct {
  Cell cells[BOARD_SIZE][BOARD_SIZE];
} Board;

typedef struct {
  const int size;
  CellPoint *points;
} BoardSubset;

Board board_create();

void board_empty_cell_at(Board *board, CellPoint *point);

void board_subset_free(BoardSubset *subset);

BoardSubset board_available_cells(Board *board);

int board_is_full(Board *board);

int board_has_match(Board *board);

char *board_cells_grid(Board *board);

#endif
