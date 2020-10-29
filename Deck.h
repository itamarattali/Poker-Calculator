#include "Card.h"

typedef struct deckType
{
	card deck[52];
}deck, *deckPtr;

typedef struct usedType			//Struct to keep track of the "burnt" cards in the deck at a certain time
{
	booly used[52];
}used, *usedPtr;

//Init Functions

deckPtr initDeck();
usedPtr initUsed();