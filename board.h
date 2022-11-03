#pragma once

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include "piece.h"
#include "move.h"

#define BoardHeigth 8
#define BoardWidth 8

struct Field
{
	bool isEmpty;
	enum Piece piece;
	enum PieceColor color;
};

struct Board
{
	struct Field fields[BoardHeigth][BoardWidth];
};


static void showColumnNames (void);
static void showRowSeparator (void);
static void showRow (struct Board * board, int row);
static void putFigures(struct Field *fields, enum Piece *pieces, enum PieceColor color);
static void putEmptyRow(struct Field *fields);
extern void showBoard();
extern struct Board* initBoard();
extern void BoardMovePiece (struct Move * move);
extern enum Piece boardGetPiece(struct Board * board, struct Position *position);

