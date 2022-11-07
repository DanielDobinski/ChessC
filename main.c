#include "game.h"

int main()
{
	struct Game * game = game_init();
	while(1)
	{

		game_play();
		if((game->capture) == 3)
			break;
	}	
	printf("END OF GAME");
	return 0;
}