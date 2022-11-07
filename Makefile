CC=gcc
CFLAGS=-I

main: main.c game.c board.c move.c position.c player.c piece.c piece_rule.c
	$(CC) -o main main.c game.c board.c move.c position.c player.c piece.c piece_rule.c -I.



	