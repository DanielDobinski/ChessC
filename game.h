#pragma once
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include "board.h"
#include "move.h"
#include "player.h"
#include "piece_rule.h"

struct Game 
{
	struct Player * player[2];
	struct Board * board;
	int currentPlayer;
	int statusError;
	int capture;
	int statusErrorGetMove;           //zero when all is good, 1 when sth is wrong
	int statusErrorPieceCheckRule;    //zero when all is good, 1 when sth is wrong
	int statusErrorPlayerCheckColor;  //zero when all is good, 1 when sth is wrong
	int	statusErrorMoveRange;         //zero when all is good, 1 when sth is wrong
	int statusErrorOverall;			  //zero when all is good, 1 when sth is wrong
	enum Piece pieceFrom;
	enum Piece pieceTo;
	enum PieceColor pieceColor;
	enum PieceColor playerColor;
};

extern void game_play(void);
extern struct Game* game_init(void);
