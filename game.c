#include "game.h"
#include "piece_rule.h"

struct Game game;
struct Move move;
int statusError = 0; //zero when all is good, 1 when sth is wrong

extern void game_init(void)
{
    getPlayerName();
	getPlayerName();
	game.board = initBoard(); 
	showBoard();
}

extern void game_play(void)
{
	enum Piece piece;
	statusError = getMove(&move);
	piece = boardGetPiece(game.board, &(move.positionFrom));
	if (statusError == 1)
	{
		BoardMovePiece(&move);
		showBoard();
	}
	else 
		printf("\n\nillegal move\n\n"); 
}


	