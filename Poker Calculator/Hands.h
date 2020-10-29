#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum {FALSE, TRUE}boolean;

typedef enum {H, D, C, S} suit;

typedef struct card
{
	int number;  // Number On The Card
	suit s;		 // Suit Of The Card
}card, *cardPtr;

typedef struct flop
{
	card card1;		// First Board Card
	card card2;		// Second Board Card
	card card3;		// Third Board Card
}flop, *flopPtr;

typedef struct turn
{
	card turn;		//4th Board Card
}turn, *turnPtr;

typedef struct river
{
	card river;		//5th River Card
}river, *riverPtr;

typedef struct board
{
	flop f;
	turn t;
	river r;
}board, *boardPtr;

typedef struct pocket
{
	card card1;
	card card2;
}pocket, *pocketPtr;

typedef struct hand
{
	card arr[7];
}hand, *handPtr;

typedef struct bestHand
{
	card arr[5];
}bestHand, *bestHandPtr;

hand initHand(pocket p, board b);