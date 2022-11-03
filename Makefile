CC=gcc
CFLAGS=-I

main: main.c board.c move.c position.c
	$(CC) -o main main.c board.c move.c position.c -I.