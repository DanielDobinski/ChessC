#pragma once

#include "piece.h"
struct Move;

static int checkPawn(enum PieceColor color, struct Move * move);
static int checkRook(enum PieceColor color, struct Move * move);
static int checkKnight(enum PieceColor color, struct Move * move);
static int checkBishop(enum PieceColor color, struct Move * move);
static int checkQueen(enum PieceColor color, struct Move * move);
static int checkKing(enum PieceColor color, struct Move * move);
extern int pieceCheckRule(enum Piece piece, enum PieceColor color, struct Move *move);