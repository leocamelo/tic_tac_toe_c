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

CellPoint *cell_point_create(const int x, const int y) {
  CellPoint *point = malloc(sizeof(CellPoint));

  point->x = x;
  point->y = y;

  return point;
}
