#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "grid.h"
#include "human.h"

CellPoint *human_cell_point_by_index(int index) {
  index--;
  return cell_point_create(index / BOARD_SIZE, index % BOARD_SIZE);
}

CellPoint *human_move(Board *board) {
  int input;
  int limit = pow(BOARD_SIZE, 2);

  char *grid = grid_from_board(board);

  CellPoint *point;

  PRINTF_FN("%s\n", grid);
  free(grid);

  while (1) {
    PRINTF_FN("Enter [1-%d] to mark or 0 to quit: ", limit);
    if (!SCANF_FN("%d", &input) || !input) return NULL;

    if (input > 0 && input <= limit) {
      point = human_cell_point_by_index(input);
      if (point && cell_is_empty(board->cells[point->x][point->y])) break;
    }
  }

  return point;
}
