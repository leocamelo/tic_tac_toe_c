#ifndef HUMAN_H
#define HUMAN_H

#include "board.h"

CellPoint human_cell_point_by_index(int index);

CellPoint human_move(Board *board);

#endif
