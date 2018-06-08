#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "grid.h"

static char *grid_row_separator() {
  int i;

  char *separator = malloc(sizeof(char) * (BOARD_SIZE * 4 + 2));

  strcpy(separator, "\n");
  for (i = 0; i < BOARD_SIZE; i++) {
    if (i) strcat(separator, "+");
    strcat(separator, "===");
  }
  strcat(separator, "\n");
  return separator;
}

char *grid_from_board(Board *board) {
  int i, j;

  char fallback_cell = '1';
  char *separator = grid_row_separator();

  char *grid = malloc(sizeof(char) * (
    8 * pow(BOARD_SIZE, 2) - 5 * BOARD_SIZE + 2
  ));

  strcpy(grid, "\n");
  for (i = 0; i < BOARD_SIZE; i++) {
    if (i) strcat(grid, separator);

    for (j = 0; j < BOARD_SIZE; j++) {
      strcat(grid, j ? " | " : " ");

      if (cell_is_empty(board->cells[i][j])) {
        strcat(grid, (char[2]){fallback_cell, '\0'});
      } else {
        strcat(grid, cell_to_string(board->cells[i][j]));
      }
      fallback_cell++;
    }
  }
  strcat(grid, "\n");
  free(separator);
  return grid;
}
