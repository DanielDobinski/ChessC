#pragma once

#include "piece.h"
struct Move;

int pieceCheckRule(enum Piece piece, enum PieceColor color, struct Move *move);