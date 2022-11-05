#pragma once

#define PIECE_NAMES\
    X(pawn)\
    X(rook)\
    X(knight)\
    X(bishop)\
    X(queen)\
    X(king)

#define X(piece) piece,
    enum Piece {PIECE_NAMES};
#undef X

enum PieceColor
{
	white = 0,
	black = 8
};

