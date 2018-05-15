#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 3

typedef enum {
  NIL, X, O
} Cell;

typedef struct {
  Cell cells[BOARD_SIZE][BOARD_SIZE];
} Board;

typedef struct {
  const int size;
  int **cells;
} BoardSubset;

void board_empty_cell_at(Board *board, int x, int y);

BoardSubset board_available_cells(Board *board);

int board_is_full(Board *board);

int board_has_match(Board *board);

#endif
