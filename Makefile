CC=gcc
CFLAGS=-I.

OBJECTS = main.o game.o board.o move.o position.o player.o piece.o piece_rule.o

main: $(OBJECTS)
		$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
		rm -f *.o
	