#ifndef CELL_H
#define CELL_H

typedef enum {
  _, X, O
} Cell;

typedef struct {
  int x;
  int y;
} CellPoint;

int cell_is_empty(Cell cell);

char *cell_to_string(Cell cell);

CellPoint *cell_point_create(const int x, const int y);

#endif
