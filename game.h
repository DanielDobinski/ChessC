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
};

extern void game_play(void);
extern void game_init(void);