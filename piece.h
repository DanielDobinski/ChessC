#pragma once
#include "piece_rule.h"
#include "move.h"

enum Piece {
    pawn = 0,
    rook,
    knight,
    bishop,
    queen,
    king
};

enum PieceColor
{
	white = 0,
	black = 8
};

int pieceCheckRule(enum Piece piece, enum PieceColor color, struct Move *move);