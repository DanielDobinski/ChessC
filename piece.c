#include "piece.h"
#include "stdio.h" //only for debbuging

int pieceCheckRule(enum Piece piece, enum PieceColor color, struct Move *move)
{
	if(piece == pawn)
	{
		struct DeltaMove deltaMove;
		int startRow = move->positionFrom.row;
		int rowDelta;
		int colDelta;

		deltaMove = calculateDelta(move);
		rowDelta = deltaMove.row;
		colDelta = deltaMove.col;

		if((rowDelta == 1) && (color == white))
		{
			return 0;
		}
		else if((rowDelta == -1) && (color == black))
		{
			return 0;
		}
		else if((rowDelta == 1) && (colDelta == 1) && (color == white))
		{
			return 0;
		}
		else if(colDelta == 1 && colDelta ==1 && (color == black))
		{
			return 0;
		}
		else if((rowDelta == 2) && (color == white) && (startRow == 2))
		{
			return 0;
		}
		else if((rowDelta == -2) && (color == white) && (startRow == 6))
		{
			return 0;
		}
		else
			{return 1;}
	}
	else
		return 0;
}