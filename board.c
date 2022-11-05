#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <ctype.h>
#include "board.h"

static struct Board board;
enum Piece pawns[BoardWidth] = {pawn, pawn, pawn, pawn, pawn, pawn, pawn, pawn};
enum Piece figures[BoardWidth] = {rook, knight, bishop, queen, king, bishop, knight, rook};

static void showColumnNames (void)
{
	putchar(' ');
	for (int i = 0;i < BoardWidth; ++i)
		printf(" %c", ('a' + (char)i));
	putchar('\n');
}

static void showRowSeparator (void)
{
	putchar(' ');
	for (int i = 0; i < BoardWidth; ++i)
		printf("+-");
    putchar('+');
	putchar('\n');
}

static void showRow (struct Board * board, int row)
{
	const char pieceName[] = "prkbqk";
	printf("%u", row + 1);
	for (int col = 0; col < BoardWidth; ++col)
	{
		struct Field *currentField = &(board->fields[row][col]);
		if(currentField->isEmpty == true)
			printf("| ");
		else
		{
			char pieceChar = pieceName[currentField->piece];
			if (currentField->color == white) 
				pieceChar = toupper(pieceChar);

			printf("|%c", pieceChar);
		}
	}
	printf("|");
	printf("%u", row + 1);
	putchar('\n');
}

static void putFigures(struct Field * fields, enum Piece * pieces, enum PieceColor color)
{
	for (int col = 0; col < BoardWidth; ++col)
	{
		fields[col].isEmpty = false;
		fields[col].piece = pieces[col];
		fields[col].color = color;
	}
}

static void putEmptyRow(struct Field * fields)
{
	for(int col = 0; col < BoardWidth; ++col)
	{
		fields[col].isEmpty = true;
	}
}

extern enum Piece boardGetPiece(struct Board * board, struct Position *position)
{
	enum Piece piece;
	struct Field *tempField = &(board->fields[position->row][position->column]);
	piece = tempField->piece;

	return piece;
}

extern enum PieceColor boardGetPieceColor(struct Board * board, struct Position *position)
{
	enum PieceColor pieceColor;
	struct Field *tempField = &(board->fields[position->row][position->column]);
	pieceColor = tempField->color;

	return pieceColor;
}  

extern void showBoard()
{
showColumnNames();
	int row = BoardHeigth;
	while(row--)
	{
		showRowSeparator();
		showRow(&board, row);
	}
	showRowSeparator();
	showColumnNames();
}

extern struct Board* initBoard()
{
	memset(&board, 0, BoardHeigth * BoardWidth * sizeof(struct Field));

	putFigures(board.fields[0], figures, white);
	putFigures(board.fields[1], pawns, white);
	putFigures(board.fields[6], pawns, white);
	putFigures(board.fields[7], figures, black);
	for (int row = 2; row < 6; ++row)
	{
		putEmptyRow(board.fields[row]);
	}

	return &board;
}

extern void BoardMovePiece (struct Move * move)
{
	struct Field tempField;
	struct Field * from = &board.fields[(&(move->positionFrom))->row][(&(move->positionFrom))->column];   
	struct Field * to = &board.fields[(&(move->positionTo))->row][(&(move->positionTo))->column];  
	tempField = *to;
	*to = *from;
	*from = tempField;
}


