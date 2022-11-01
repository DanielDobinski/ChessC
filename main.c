#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include "main.h"
#include "board.h"

int FlagInit = 0;

int main()
{
	if (FlagInit == 0)
	{
		initBoard(); 
		++FlagInit;
	}
	showBoard();
	return 0;
}