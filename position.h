#pragma once

struct Position
{
	int row;
	int column;
};

extern void createPosition(char column, int row, struct Position * position);