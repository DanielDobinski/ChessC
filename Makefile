CC=gcc
CFLAGS=-I

main: main.c board.c
	$(CC) -o main main.c board.c -I.