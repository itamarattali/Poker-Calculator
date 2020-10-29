#include "Board.h"

//Init Functions

flopPtr initFlop()
{
	flopPtr f = (flop*)malloc(sizeof(flop));
	return f;
}

turnPtr initTurn()
{
	turnPtr t = (turn*)malloc(sizeof(turn));
	return t;
}

riverPtr initRiver()
{
	riverPtr r = (river*)malloc(sizeof(river));
	return r;
}

boardPtr initBoard()
{
	boardPtr b = (board*)malloc(sizeof(board));
	return b;
}

//Randomize Board

boardPtr randBoard(deckPtr d, usedPtr u)
{
	int num;
	boardPtr b = initBoard();
	int i = 0;

	while (i < 5)
	{
		num = (rand() %	(52));
		if (u->used[num] == False)
		{
			b->board[i] = d->deck[num];
			i++;
			u->used[num] = True;
		}
	}
	return b;
}