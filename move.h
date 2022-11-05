#pragma once

#include "position.h"

struct Move
{
	struct Position positionFrom;
	struct Position positionTo;
};

struct DeltaMove
{
	int row;
	int col;
};

extern int getMove(struct Move * move);
static void createMove(char fromCol, int fromRow, char toCol, int toRow, struct Move * move);
static int checkMoveRange(struct Move * move); 
extern struct DeltaMove calculateDelta(struct Move * move);