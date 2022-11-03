#include "game.h"

int main()
{
	game_init();
	while(1)
	{
		game_play();
	}

	return 0;
}