#include "piece.h"

#define PLAYER_NAME_LENGTH (20)


struct Player
{
	char playerName[PLAYER_NAME_LENGTH];
	enum PieceColor color;
};

static char* getPlayerName(void);
extern struct Player* player_init(int piecesFlag);