#include "piece_rule.h"
#include "move.h"

#define CHECK_FUNCTIONS\
    X(pawn, checkPawn)\
    X(rook, checkRook)\
    X(knight, checkKnight)\
    X(bishop, checkBishop)\
    X(queen, checkQueen)\
    X(king, checkKing)

// Private function
static int checkPawn(enum PieceColor color, struct Move * move);
static int checkRook(enum PieceColor color, struct Move * move);
static int checkKnight(enum PieceColor color, struct Move * move);
static int checkBishop(enum PieceColor color, struct Move * move);
static int checkQueen(enum PieceColor color, struct Move * move);
static int checkKing(enum PieceColor color, struct Move * move);

#define X(piece, checkFunc) checkFunc,
	static int (*checkFunct[])(enum PieceColor color, struct Move * move) = {CHECK_FUNCTIONS};
#undef X

int pieceCheckRule(enum Piece piece, enum PieceColor color, struct Move *move)
{
	return checkFunct[piece](color, move);
}

static int checkPawn(enum PieceColor color, struct Move * move)
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

static int checkRook(enum PieceColor color, struct Move * move)
{
	struct DeltaMove deltaMove;
	int rowDelta;
	int colDelta;

	deltaMove = calculateDelta(move);
	rowDelta = deltaMove.row;
	colDelta = deltaMove.col;
	if ((rowDelta >= 1 && colDelta == 0) || (rowDelta == 0 && colDelta >= 1))
		return 0;
	else
		return 1;
}
static int checkKnight(enum PieceColor color, struct Move * move)
{
	struct DeltaMove deltaMove;
	int rowDelta;
	int colDelta;

	deltaMove = calculateDelta(move);
	rowDelta = deltaMove.row;
	colDelta = deltaMove.col;
	if (((rowDelta == 2) && (colDelta == 1)) || ((rowDelta == 1) && (colDelta == 2)))
		return 0;
	else
		return 1;
}
static int checkBishop(enum PieceColor color, struct Move * move)
{
	struct DeltaMove deltaMove;
	int rowDelta;
	int colDelta;

	deltaMove = calculateDelta(move);
	rowDelta = deltaMove.row;
	colDelta = deltaMove.col;
	if ((rowDelta/colDelta) == 0)
		return 0;
	else
		return 1;
}
static int checkQueen(enum PieceColor color, struct Move * move)
{
	struct DeltaMove deltaMove;
	int rowDelta;
	int colDelta;

	deltaMove = calculateDelta(move);
	rowDelta = deltaMove.row;
	colDelta = deltaMove.col;
	if ((rowDelta >= 1 && colDelta == 0) || (rowDelta == 0 && colDelta >= 1) || (rowDelta/colDelta) == 0)
		return 0;
	else
		return 1;
}
static int checkKing(enum PieceColor color, struct Move * move)
{
	struct DeltaMove deltaMove;
	int rowDelta;
	int colDelta;

	deltaMove = calculateDelta(move);
	rowDelta = deltaMove.row;
	colDelta = deltaMove.col;
	if ((rowDelta < 2) && (colDelta < 2) && (rowDelta > 0 || colDelta > 0))
		return 0;
	else
		return 1;
}