#pragma once

#include "position.h"

struct Move
{
	struct Position positionFrom;
	struct Position positionTo;
};

extern int getMove(struct Move * move);
static void createMove(char fromCol, int fromRow, char toCol, int toRow, struct Move * move);
static int checkMoveRange(struct Move * move); 