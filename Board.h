#include "HandEval.h"

typedef struct flopType
{
	card flop[3];
}flop, *flopPtr;

typedef struct turnType
{
	card turn;
}turn, * turnPtr;

typedef struct riverType
{
	card river;
}river, *riverPtr;

typedef struct boardType
{
	card board[5];
}board, *boardPtr;

//Init Functions

flopPtr initFlop();
turnPtr initTurn();
riverPtr initRiver();
boardPtr initBoard();

//Randomize Board

boardPtr randBoard(deckPtr d, usedPtr u);