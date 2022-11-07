#include <stdio.h>
#include <ctype.h>
#include "move.h"

/**
* @return 0 if all is good, 1 if sth is wrong 
*/
extern int getMove(struct Move * move)
{
	char fromCol;
	int fromRow; 
	char toCol;
	int toRow;
	int status;

	status = scanf(" %c%u%c%u", &fromCol, &fromRow, &toCol, &toRow);
	while (getchar() != '\n'); //eat buffer
	
	if (status == 4)
	{
		createMove(tolower(fromCol), fromRow, tolower(toCol), toRow, move);
		return 0;

	}
	else
		return 1;
}

extern struct DeltaMove calculateDelta(const struct Move * move)
{
	struct DeltaMove deltaMove;
	deltaMove.col = (move->positionTo.column) - (move->positionFrom.column);
	deltaMove.row = (move->positionTo.row) - (move->positionFrom.row);
	return deltaMove;
}

static void createMove(char fromCol, int fromRow, char toCol, int toRow, struct Move * move)
{	
	createPosition(fromCol, fromRow, &(move->positionFrom)); 
	createPosition(toCol, toRow, &(move->positionTo)); 
}
