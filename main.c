#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include "piece.h"
#include "main.h"

struct Field
{
	bool isEmpty;
	enum Piece piece;
	enum PieceColor color;
};

struct Board
{
	struct Field fields[BoardWidth][BoardHeigth];
};

static struct Board board;

void showColumnNames (void)
{
	putchar(' ');
	for (int i = 0;i < BoardWidth; ++i)
	printf(" %c", ('a' + (char)i));

	putchar('\n');
}

void showRowSeparator (void)
{
	putchar(' ');
	for (int i = 0; i < BoardWidth; ++i)
	printf("+-");

    putchar('+');
	putchar('\n');
}

void showRow (struct Board * board, int row)
{
	printf("%u", row + 1);
	for (int col = 0; col < BoardWidth; ++col)
	{
		struct Field *currentField = &(board->fields[row][col]);
		if(currentField->isEmpty == true)
			printf("| ");
		else
			printf("|B");
	}
	printf("|");
	printf("%u", row + 1);
	putchar('\n');
}

struct Board* initBoard()
{
	memset(&board, 0, BoardHeigth * BoardWidth * sizeof(struct Field));
	return &board;
}

int main()
{
	initBoard();
	struct Field *field1 = &(board.fields[0][0]);
	field1->isEmpty = true;


    printf("Board \n\n");
	showColumnNames();
	int row = BoardHeigth;
	while(row--)
	{
		showRowSeparator();
		showRow(&board, row);
	}
	showRowSeparator();
	showColumnNames();
	
	return 0;
}