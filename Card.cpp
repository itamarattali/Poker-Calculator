#include "Card.h"

cardPtr buildCard(valueType value, suitType suit)
{
	cardPtr c = (card*)malloc(sizeof(card));
	c->suit = suit;
	c->value = value;
	return c;
}