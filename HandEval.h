#include "Deck.h"

typedef struct handType
{
	card hand[7];
}hand, *handPtr;

//Init Functions

handPtr initHand();

//Useful Functions

booly valueInHand(handPtr h, valueType value);
booly cardInHand(handPtr h, valueType value, suitType suit);
int numOfApp(handPtr h, valueType value);

//Hand Evaluation

booly isRoyalFlush(handPtr h);
booly isStraightFlush(handPtr h);
booly isQuads(handPtr h);
booly isFullHouse(handPtr h);
booly isFlush(handPtr h);
booly isStraight(handPtr h);
booly isThreeOfKind(handPtr h);
booly isTwoPair(handPtr h);
booly isPair(handPtr h);