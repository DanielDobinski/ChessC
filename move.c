#include <stdio.h>
#include "move.h"
#include "position.h"

/**
* @return 1 if all is good, 0 if sth is wrong 
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
		createMove(fromCol, fromRow, toCol, toRow, move);
		if (checkMoveRange(move) == 1)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

static void createMove(char fromCol, int fromRow, char toCol, int toRow, struct Move * move)
{	
	createPosition(fromCol, fromRow, &(move->positionFrom));
	createPosition(toCol, toRow, &(move->positionTo));
}
/**
* TODO: change numbers to Defines from Board.h
* @return 1 if all is good, 0 if sth is wrong 
*/
static int checkMoveRange(struct Move * move)
{
	if (((&(move->positionFrom))->column) < 0 || ((&(move->positionFrom))->column) > 7)
		return 0;
	else if (((&(move->positionFrom))->row) < 0 || ((&(move->positionFrom))->row) > 7)
		return 0;
	else if (((&(move->positionTo))->column) < 0 || ((&(move->positionTo))->column) > 7)
		return 0;
	else if (((&(move->positionTo))->row) < 0 || ((&(move->positionTo))->row) > 7)
		return 0;
	else
		return 1;
}