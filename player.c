#include <stdio.h>
#include <string.h>
#include "player.h"

struct Player players[2];
static int playerCounter = 0;

extern void getPlayerName(void)
{
	char playerName[PLAYER_NAME_LENGTH];
	printf("player %u pieces name is:", playerCounter + 1);
	scanf("%s", playerName);

	player_init(playerName);
	printf("player name is: \n %s\n", playerName);
}

static void player_init(const char * name)
{
	struct Player *player = &players[playerCounter];
	strcpy((player->playerName), name);
	playerCounter = ++playerCounter;
}

