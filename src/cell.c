#include <stdlib.h>
#include "cell.h"

int cell_is_empty(Cell cell) {
  return cell == _;
}

char *cell_to_string(Cell cell) {
  switch (cell) {
    case X:
      return "X";
    case O:
      return "O";
    default:
      return "_";
  }
}

int cell_point_is_null(CellPoint *point) {
  return point->x == -1 || point->y == -1;
}

CellPoint cell_point_null(void) {
  return (CellPoint){-1, -1};
}
