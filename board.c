#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>   // WinApi for Colors in C
#include "board.h"

#define SHINY_WHITE (15) 
#define GREEN (2)
#define NORMAL_WHITE (7)


#define X(enum_name, piece_char) piece_char,
	static const char fieldName[] = { PIECE_NAMES };
#undef X
static struct Board board;
enum Piece pawns[BOARD_WIDTH] = {pawn, pawn, pawn, pawn, pawn, pawn, pawn, pawn};
enum Piece figures[BOARD_WIDTH] = {rook, knight, bishop, queen, king, bishop, knight, rook};

static void showColumnNames (void)
{
	putchar(' ');
	for (int i = 0;i < BOARD_WIDTH; ++i)
		printf(" %c", ('a' + (char)i));
	putchar('\n');
}

static void showRowSeparator (void)
{
	putchar(' ');
	for (int i = 0; i < BOARD_WIDTH; ++i)
		printf("+-");
    putchar('+');
	putchar('\n');
}

static void showRow (struct Board * board, int row)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	printf("%u", row + 1);
	for (int col = 0; col < BOARD_WIDTH; ++col)
	{
		struct Field *currentField = &(board->fields[row][col]);
		if(currentField->isEmpty == true)
			printf("| ");
		else
		{
			char pieceChar = fieldName[currentField->piece];
			if (currentField->color == white) 
			{
				SetConsoleTextAttribute(hConsole, SHINY_WHITE);
				pieceChar = toupper(pieceChar);
				printf("|%c", pieceChar);
				SetConsoleTextAttribute(hConsole, NORMAL_WHITE);
			}
			else
			{
				SetConsoleTextAttribute(hConsole, GREEN);
				printf("|%c", pieceChar);
				SetConsoleTextAttribute(hConsole, NORMAL_WHITE);
			}
		}
	}
	printf("|"); 
	printf("%u", row + 1);
	putchar('\n');
}

static void putFigures(struct Field * fields, enum Piece * pieces, enum PieceColor color)
{
	for (int col = 0; col < BOARD_WIDTH; ++col)
	{
		fields[col].isEmpty = false;
		fields[col].piece = pieces[col];
		fields[col].color = color;
	}
}

static void putEmptyRow(struct Field * fields)
{
	for(int col = 0; col < BOARD_WIDTH; ++col)
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
	int row = BOARD_HEIGTH;
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
	memset(&board, 0, BOARD_HEIGTH * BOARD_WIDTH * sizeof(struct Field));

	putFigures(board.fields[0], figures, white);
	putFigures(board.fields[1], pawns, white);
	putFigures(board.fields[6], pawns, black);
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
extern void BoardCapturePiece (struct Move * move)
{
	struct Field tempField;
	struct Field * from = &board.fields[(&(move->positionFrom))->row][(&(move->positionFrom))->column];   
	struct Field * to = &board.fields[(&(move->positionTo))->row][(&(move->positionTo))->column];  
	tempField = *to;
	*to = *from;
	from->isEmpty = true;
}
/*
* @return 0 - the move is allowed and you don't capture
          1 - the move is allowed you capture
          2 - the move is not allowed
          3 - End of game, you have captured the King
*/
extern int BoardCheckMoveCapture(struct Move * move, enum Piece pieceFrom, enum Piece pieceTo)
{
	struct Field * from = &board.fields[(&(move->positionFrom))->row][(&(move->positionFrom))->column];   
	struct Field * to = &board.fields[(&(move->positionTo))->row][(&(move->positionTo))->column];
	struct DeltaMove deltaMove = calculateDelta(move);;
	int rowDelta = deltaMove.row;
	int colDelta = deltaMove.col; 
	enum PieceColor pieceFromColor = from->color;
	enum PieceColor pieceToColor = to->color;	
 
	if(to->isEmpty == true)
	{
		if(pieceFrom == pawn)
		{
			if(colDelta == 0)
				return 0;
			else if ((abs(rowDelta == 1) && (abs(colDelta) == 1)))
				return 2;
		} 
		else
			return 0;
	} 
	else if(from->isEmpty == false)
	{
		
			if(pieceFrom == pawn)
			{
				if(colDelta == 0)
					return 0;
				else if ((rowDelta < 2) && (colDelta < 2) && (rowDelta > -1 || colDelta > -1) && (abs(rowDelta/colDelta) == 1))
					return 1;
			}
			else if (pieceFromColor == pieceToColor)
			{
				return 2;
			}
			else if (pieceTo == king)
			{
				return 3;
			}
			else 
				return 1;
	}else
		return 0;
}

extern int checkMoveRange(struct Move * move)
{
	if (((&(move->positionFrom))->column) < 0 || ((&(move->positionFrom))->column) > BOARD_WIDTH)
		return 1;
	else if (((&(move->positionFrom))->row) < 0 || ((&(move->positionFrom))->row) > BOARD_HEIGTH)
		return 1;
	else if (((&(move->positionTo))->column) < 0 || ((&(move->positionTo))->column) > BOARD_WIDTH)
		return 1;
	else if (((&(move->positionTo))->row) < 0 || ((&(move->positionTo))->row) > BOARD_HEIGTH)
		return 1;
	else
		return 0;
}