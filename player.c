#include <stdio.h>
#include <string.h>
#include "player.h"

struct Player players[2];
static char playerName[PLAYER_NAME_LENGTH];
static char *playerNamePtr = &playerName[0];

static char* getPlayerName(void)
{
	scanf("%s", playerName);

	return(playerNamePtr);
}

extern struct Player* player_init(int piecesFlag)
{
	struct Player *player = &players[piecesFlag];
	char * name = getPlayerName();
	strcpy((player->playerName), name);

	if(piecesFlag == 0)
		player->color = white;
	else if(piecesFlag == 1)
		player->color = black;

	return player;
}

