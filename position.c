#include "position.h"

void createPosition(char column, int row, struct Position * position)
{
	position->row = row - 1;
	position->column = (unsigned)(column - 'a');
}

