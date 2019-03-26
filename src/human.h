#ifndef HUMAN_H
#define HUMAN_H

#include "board.h"

#ifdef TEST_ENV

void mocked_printf(const char *format, ...);
int mocked_scanf(const char *format, int *pointer);

#define PRINTF_FN mocked_printf
#define SCANF_FN mocked_scanf

#else

#define PRINTF_FN printf
#define SCANF_FN scanf

#endif

CellPoint *human_cell_point_by_index(int index);

CellPoint *human_move(Board *board);

#endif
