#include "Deck.h"

deckPtr initDeck()
{
	deckPtr d = (deck*)malloc(sizeof(deck));
	int i = 0;

	for (valueType value = 2; value < 15; value++)
	{
		for (int j = 0; j < 4; j++)
		{
			d->deck[i] = *buildCard(value, suitArr[j]);
			i++;
		}
	}
	return d;
}

usedPtr initUsed()
{
	usedPtr u = (used*)malloc(sizeof(used));
	
	for (int i = 0; i < 52; i++)
		u->used[i] = False;

	return u;
}