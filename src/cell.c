#include <stdlib.h>
#include "cell.h"

int cell_is_empty(Cell cell) {
  return cell == _;
}

int cell_point_is_null(CellPoint *point) {
  return point->x == -1 || point->y == -1;
}

CellPoint cell_point_null() {
  return (CellPoint){-1, -1};
}
