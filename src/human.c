#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "human.h"

CellPoint human_cell_point_by_index(int index) {
  int aux = 1, i, j;

  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      if (aux++ == index) return (CellPoint){i, j};
    }
  }
  return cell_point_null();
}

CellPoint human_move(Board *board) {
  int input, limit = pow(BOARD_SIZE, 2);

  char *grid = board_cells_grid(board);
  printf("%s\n", grid);
  free(grid);

  printf("Enter [1-%d] to mark or 0 to quit: ", limit);
  if (!scanf("%d", &input) || !input) return cell_point_null();

  if (input > 0 && input <= limit) {
    CellPoint point = human_cell_point_by_index(input);

    if (!cell_point_is_null(&point) &&
        cell_is_empty(board->cells[point.x][point.y])) {
      return point;
    }
  }
  return human_move(board);
}
