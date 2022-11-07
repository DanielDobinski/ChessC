#pragma once

#define PIECE_NAMES\
    X(pawn = 0, 'p')\
    X(rook, 'r')\
    X(knight, 'y')\
    X(bishop, 'b')\
    X(queen, 'q')\
    X(king, 'k')

#define X(piece, pieceChar) piece,
    enum Piece {PIECE_NAMES};
#undef X

enum PieceColor
{
	white = 0,
	black = 8
};

