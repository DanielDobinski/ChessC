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
extern struct DeltaMove calculateDelta(const struct Move * move);