#include "game.h"

struct Game game;
struct Move move;
int statusError = 0; //zero when all is good, 1 when sth is wrong

extern void game_init(void)
{
	printf("\nGimme name for player 1 (white)\n");
    game.player[0] = player_init(0);
    printf("\nplayer 1 name is: %s\n", (game.player[0])->playerName);
	printf("\nGimme name for player 2 (black)\n");
	game.player[1] = player_init(1);
	printf("\nplayer 1 name is: %s", (game.player[0])->playerName);
	game.board = initBoard(); 
	showBoard();
}

extern void game_play(void)
{
	enum Piece piece;
	enum PieceColor pieceColor;
	statusError = getMove(&move);
	piece = boardGetPiece(game.board, &(move.positionFrom));
	pieceColor = boardGetPieceColor(game.board, &(move.positionFrom));
	statusError = pieceCheckRule(piece, pieceColor, &move);

	printf("\n move game:\n %u \t %u \t %u \t %u \t", move.positionFrom.row, move.positionFrom.column, move.positionTo.row, move.positionTo.column);

	if (statusError == 0)
	{
		BoardMovePiece(&move);
		showBoard();
	}
	else 
		printf("\n\nillegal move\n\n"); 
}


	