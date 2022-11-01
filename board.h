#pragma once

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include "piece.h"


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
	struct Field fields[BoardWidth][BoardHeigth];
};


void showColumnNames (void);
void showRowSeparator (void);
void showRow (struct Board * board, int row);
void putFigures(struct Field *fields, enum Piece *pieces, enum PieceColor color);
void putEmptyRow(struct Field *fields);
void showBoard();
struct Board* initBoard();

