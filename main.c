#include <stdio.h>
#include "main.h"


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

void showRow (int row)
{
	printf("%u", row + 1);
	for (int i = 0; i < BoardWidth; ++i)
	printf("| ");
	printf("|");
	printf("%u", row + 1);
	putchar('\n');
}
	
int main()
{
    printf("Board \n\n");
	showColumnNames();
	int row = BoardHeigth;
	while(row--)
	{
		showRowSeparator();
		showRow(row);
	}
	showRowSeparator();
	showColumnNames();
	
	return 0;
}