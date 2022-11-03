#include "piece.h"

#define PLAYER_NAME_LENGTH (20)


struct Player
{
	char playerName[PLAYER_NAME_LENGTH];
	enum PieceColor color;
};

static void player_init(const char * name);
extern void getPlayerName(void);