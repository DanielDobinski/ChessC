#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include "main.h"
#include "board.h"
#include "move.h"

int FlagInit = 0;
struct Move move;
int status = 0;

int main()
{
	if (FlagInit == 0)
	{
		initBoard(); 
		showBoard();
		++FlagInit;
	}
	while(1)
	{
		
		status = getMove(&move);
		if (status == 1)
		{
			BoardMovePiece(&move);
			showBoard();
		}
		else 
			printf("\n\nillegal move\n\n");
	}

	return 0;
}