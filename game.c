#include "game.h"

struct Game game;
struct Move move;

static void fillGameWithData(struct Game * game, struct Move * move);

extern struct Game* game_init(void)
{
	for(int i = 0; i < PLAYER_NUMBER; ++i)
	{
		printf("\nGimme name for player %u\n", i + 1);
	    game.player[i] = player_init(i);
	    printf("\nplayer %u name is: %s\n", i, (game.player[i])->playerName);
	}
	game.board = initBoard();  
	game.currentPlayer = 0;
	game.statusError = 0;
	game.capture = 0;
	game.statusErrorGetMove = 0;           //zero when all is good, 1 when sth is wrong
	game.statusErrorPieceCheckRule = 0;    //zero when all is good, 1 when sth is wrong
	game.statusErrorPlayerCheckColor = 0;  //zero when all is good, 1 when sth is wrong

	return &game;
}

extern void game_play(void)
{
	showBoard();
	printf("Please, player %s, it's your turn\n", game.player[game.currentPlayer]);

	game.statusErrorGetMove = getMove(&move);
	fillGameWithData(&game, &move);

	if ((game.statusErrorOverall == 0) && (game.capture == 0)) 
	{
		BoardMovePiece(&move);
		game.currentPlayer = switchPlayer(game.currentPlayer);		
	}
	else if ((game.statusErrorOverall == 0) && (game.capture == 1))
	{
		BoardCapturePiece(&move); 
		game.currentPlayer = switchPlayer(game.currentPlayer);
	}
	else if (game.capture == 3)
			printf("\nplayer %u WIN!!\n", game.currentPlayer); 
	else 
		printf("\nillegal move\n"); 

	printf("\n%u %u \n", game.pieceFrom, game.pieceColor);
	printf("\nstatus overall: %u move:%u rulecheck:%u playercolor:%u capture %u\n", game.statusErrorOverall, game.statusErrorGetMove, game.statusErrorPieceCheckRule, game.statusErrorPlayerCheckColor, game.capture);
	printf("\n move :\n %u \t %u \t %u \t %u \t\n", move.positionFrom.row, move.positionFrom.column, move.positionTo.row, move.positionTo.column);
}

static void fillGameWithData(struct Game * game, struct Move * move) 
{
	game->pieceFrom = boardGetPiece(game->board, &(move->positionFrom));
	game->pieceTo = boardGetPiece(game->board, &(move->positionTo));
	game->pieceColor = boardGetPieceColor(game->board, &(move->positionFrom));
	game->playerColor = game->player[game->currentPlayer]->color;
	game->capture = BoardCheckMoveCapture(move, game->pieceFrom,  game->pieceTo);   
	game->statusErrorPieceCheckRule = pieceCheckRule(game->pieceFrom, game->pieceColor, move);    
	game->statusErrorPlayerCheckColor = playerCheckColorMove(game->playerColor, game->pieceColor);  
	game->statusErrorMoveRange = checkMoveRange(move);
	game->statusErrorOverall = game->statusErrorPieceCheckRule |  game->statusErrorPlayerCheckColor |  game->statusErrorMoveRange |  game->statusErrorGetMove;
}
