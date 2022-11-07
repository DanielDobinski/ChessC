#pragma once

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include "piece.h"
#include "move.h"

#define BOARD_HEIGTH (8)
#define BOARD_WIDTH (8)


struct Field
{
	bool isEmpty;
	enum Piece piece;
	enum PieceColor color;
};

struct Board
{
	struct Field fields[BOARD_HEIGTH][BOARD_WIDTH]; 
};

static void showColumnNames (void);
static void showRowSeparator (void);
static void showRow (struct Board * board, int row);
static void putFigures(struct Field *fields, enum Piece *pieces, enum PieceColor color);
static void putEmptyRow(struct Field *fields);
extern int checkMoveRange(struct Move * move);
extern void showBoard();
extern struct Board* initBoard();
extern void BoardMovePiece (struct Move * move);
extern enum Piece boardGetPiece(struct Board * board, struct Position *position);
extern enum PieceColor boardGetPieceColor(struct Board * board, struct Position *position);
extern int BoardCheckMoveCapture(struct Move * move, enum Piece pieceFrom, enum Piece pieceTo);
extern void BoardCapturePiece (struct Move * move);
