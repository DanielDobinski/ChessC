#pragma once

struct Position
{
	int row;
	int column;
};

void createPosition(char column, int row, struct Position * position);