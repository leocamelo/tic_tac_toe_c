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

int cell_point_is_null(CellPoint *point);

CellPoint cell_point_null();

#endif
