#include "HandEval.h"

//Init Functions

handPtr initHand()
{
	handPtr h = (hand*)malloc(sizeof(hand));
	return h;
}

//Useful Functions

booly valueInHand(handPtr h, valueType value)
{
	for (int i = 0; i < 7; i++)
	{
		if (h->hand[i].value == value)
			return True;
	}
	return False;
}

booly cardInHand(handPtr h, valueType value, suitType suit)
{
	for (int i = 0; i < 7; i++)
	{
		if (h->hand[i].value == value && h->hand[i].suit == suit)
			return True;
	}
	return False;
}

int numOfApp(handPtr h, valueType value)
{
	int count = 0;

	for (int i = 0; i < 7; i++)
	{
		if (h->hand[i].value == value)
			count++;
	}
	return count;
}

//Hand Evaluation

booly isRoyalFlush(handPtr h)
{
	suitType suit;

	for (int i = 0; i < 7; i++)
	{
		if (h->hand[i].value == 10)
		{
			suit = h->hand[i].suit;

			for (int j = 1; j < 5; j++)
			{
				if (!cardInHand(h, 10 + j, suit))
					break;
				if (j == 4)
					return True;
			}
		}
	}
	return False;
}

booly isStraightFlush(handPtr h)
{
	suitType suit;
	valueType value;

	for (int i = 0; i < 7; i++)
	{
		suit = h->hand[i].suit;
		value = h->hand[i].value;

		if (value == 14)			// If the bottom end of the straight is an Ace
			value = 1;

		for (int j = 1; j < 5; j++)
		{
			if (!cardInHand(h, value + j, suit))
				break;
			if (j == 4)
				return True;
		}
	}
	return False;
}

booly isQuads(handPtr h)
{
	for (int i = 0; i < 7; i++)
	{
		if (numOfApp(h, h->hand[i].value) == 4)
			return True;
	}
	return False;
}

booly isFullHouse(handPtr h)
{
	booly checkTOK = False;

	for (int i = 0; i < 7; i++)
	{
		if (numOfApp(h, h->hand[i].value) == 3)
		{
			checkTOK = True;
			break;
		}
	}
	if (checkTOK == False)
		return False;
	for (int i = 0; i < 7; i++)
	{
		if (numOfApp(h, h->hand[i].value) == 2)
			return True;
	}
	return False;
}

booly isFlush(handPtr h)
{
	int countD = 0, countH = 0, countS = 0, countC = 0;

	for (int i = 0; i < 7; i++)
	{
		if (h->hand[i].suit == 'D')
			countD++;
		else
			if (h->hand[i].suit == 'H')
				countH++;
			else
				if (h->hand[i].suit == 'C')
					countC++;
				else
					if (h->hand[i].suit == 'S')
						countS++;
	}

	if (countD >= 5 || countH >= 5 || countS >= 5 || countC >= 5)
		return True;
	return False;
}

booly isStraight(handPtr h)
{
	valueType value;

	for (int i = 0; i < 7; i++)
	{
		value = h->hand[i].value;
		if (value == 14)				//If the bottom end of the straight is an Ace
			value = 1;

		for (int j = 1; j < 5; j++)
		{
			if (!valueInHand(h, value + j))
				break;
			if (j == 4)
				return True;
		}
	}
	return False;
}

booly isThreeOfKind(handPtr h)
{
	for (int i = 0; i < 7; i++)
	{
		if (numOfApp(h, h->hand[i].value) == 3)
			return True;
	}
	return False;
}

booly isTwoPair(handPtr h)
{
	valueType firstPair = 15;

	for (int i = 0; i < 7; i++)
	{
		if (numOfApp(h, h->hand[i].value) == 2)
		{
			firstPair = h->hand[i].value;
			break;
		}
	}

	if (firstPair == 15)
		return False;

	for (int i = 0; i < 7; i++)
	{
		if (numOfApp(h, h->hand[i].value) == 2 && h->hand[i].value != firstPair)
			return True;
	}
	return False;
}

booly isPair(handPtr h)
{
	for (int i = 0; i < 7; i++)
	{
		if (numOfApp(h, h->hand[i].value) == 2)
			return True;
	}
	return False;
}