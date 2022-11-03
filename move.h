#pragma once

#include "position.h"

struct Move
{
	struct Position positionFrom;
	struct Position positionTo;
};

int getMove(struct Move * move);
void createMove(char fromCol, int fromRow, char toCol, int toRow, struct Move * move);
int checkMoveRange(struct Move * move); 