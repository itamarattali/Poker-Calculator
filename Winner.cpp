#include "Winner.h"

handRank checkHand(handPtr h)
{
	if (isRoyalFlush(h))
		return 10;
	if (isStraightFlush(h))
		return 9;
	if (isQuads(h))
		return 8;
	if (isFullHouse(h))
		return 7;
	if (isFlush(h))
		return 6;
	if (isStraight(h))
		return 5;
	if (isThreeOfKind(h))
		return 4;
	if (isTwoPair(h))
		return 3;
	if (isPair(h))
		return 2;
	return 1;
}

result findWinner(handPtr h1, handPtr h2)
{
	handRank p1 = checkHand(h1), p2 = checkHand(h2);
	if (p1 > p2)
		return Win;
	if (p2 > p1)
		return Loss;
	switch (p1)			//If Both Players Are Holding The Same Hand Type
	{
	case 10:			//both players have a royal flush... impossible to have 2 combos in 1 board so always a split
		return Split;
	case 9:				//both players have a straight flush
	{
		suitType suit;
		valueType value1;
		valueType top1 = 2;

		for (int i = 0; i < 7; i++)
		{
			suit = h1->hand[i].suit;
			value1 = h1->hand[i].value;

			if (value1 == 14)			
				value1 = 1;

			for (int j = 1; j < 8; j++)
			{
				if (!cardInHand(h1, value1 + j, suit))
					break;
				if (j >= 4)
					top1 = h1->hand->value;
			}
		}
		
		valueType value2;
		valueType top2 = 2;

		for (int i = 0; i < 7; i++)
		{
			suit = h2->hand[i].suit;
			value2 = h2->hand[i].value;

			if (value2 == 14)
				value2 = 1;

			for (int j = 1; j < 8; j++)
			{
				if (!cardInHand(h2, value2 + j, suit))
					break;
				if (j >= 4)
					top2 = h2->hand->value;
			}
		}

		if (top1 == top2)
			return Split;
		if (top1 > top2)
			return Win;
		return Loss;
	}
	case 8:			//both players have quads. always decided by the kicker.
	{				//6th and 7th spots in a hand array are the players pocket cards!!!
		valueType max1 = 2, max2 = 2;

		max1 = h1->hand[5].value > h1->hand[6].value ? h1->hand[5].value : h1->hand[6].value;
		max2 = h2->hand[5].value > h2->hand[6].value ? h2->hand[5].value : h2->hand[6].value;

		if (max1 == max2)
			return Split;
		if (max1 > max2)
			return Win;
		if (max2 > max1)
			return Loss;
	}
	case 7:			//both players have a full house
	{
		valueType trip1 = 2, trip2 = 2, pair1 = 2, pair2 = 2;

		for (int i = 0; i < 7; i++)
		{
			if (numOfApp(h1, h1->hand[i].value) == 3 && h1->hand[i].value > trip1)
				trip1 = h1->hand[i].value;
			if (numOfApp(h2, h2->hand[i].value) == 3 && h2->hand[i].value > trip2)
				trip2 = h2->hand[i].value;
		}

		if (trip1 > trip2)
			return Win;
		if (trip2 > trip1)
			return Loss;

		for (int i = 0; i < 7; i++)
		{
			if (numOfApp(h1, h1->hand[i].value) >= 2 && h1->hand[i].value != trip1 && h1->hand[i].value > pair1)
				pair1 = h1->hand[i].value;
			if (numOfApp(h2, h2->hand[i].value) >= 2 && h2->hand[i].value != trip2 && h2->hand[i].value > pair2)
				pair2 = h2->hand[i].value;
		}

		if (pair1 == pair2)
			return Split;
		if (pair1 > pair2)
			return Win;
		if (pair2 > pair1)
			return Loss;
	}
	case 6:			//both players have a flush 
	{
		int countH = 0, countD = 0, countS = 0, countC = 0;
		int numOfSuit;
		suitType s;

		for (int i = 0; i < 5; i++)
		{
			if (h1->hand[i].suit == 'H')
				countH++;
			if (h1->hand[i].suit == 'D')
				countD++;
			if (h1->hand[i].suit == 'S')
				countS++;
			if (h1->hand[i].suit == 'C')
				countC++;
		}

		if (countS >= 3)
		{
			s = 'S';
			numOfSuit = countS;
		}
		if (countC >= 3)
		{
			s = 'C';
			numOfSuit = countC;
		}
		if (countD >= 3)
		{
			s = 'D';
			numOfSuit = countD;
		}
		if (countH >= 3)
		{
			s = 'H';
			numOfSuit = countH;
		}

		valueType top1 = 2, top2 = 2, bottomFlush = 14;

		for (int i = 5; i < 7; i++)
		{
			if (h1->hand[i].suit == s && h1->hand[i].value > top1)
				top1 = h1->hand[i].value;
			if (h2->hand[i].suit == s && h2->hand[i].value > top2)
				top2 = h2->hand[i].value;
		}

		if (numOfSuit != 5)
		{
			if (top1 > top2)
				return Win;
			if (top2 > top1)
				return Loss;
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				if (h1->hand[i].value < bottomFlush)
					bottomFlush = h1->hand[i].value;
			}

			if (top1 > bottomFlush || top2 > bottomFlush)
			{
				if (top1 > top2)
					return Win;
				if (top2 > top1)
					return Loss;
			}
			return Split;
		}
	}
	case 5:			//both players have a straight... highest end of the straight wins
	{
		valueType max1 = 2, max2 = 2;
		int count1 = 1, count2 = 1;

		for (int i = 0; i < 7; i++)
		{
			while (valueInHand(h1, h1->hand[i].value + count1))
			{
				if (h1->hand[i].value + count1 > max1)
					max1 = h1->hand[i].value + count1;
				count1++;
			}

			while (valueInHand(h2, h2->hand[i].value + count2))
			{
				if (h2->hand[i].value + count2 > max2)
					max2 = h2->hand[i].value + count2;
				count2++;
			}
		}

		if (max1 > max2)
			return Win;
		if (max2 > max1)
			return Loss;
		return Split;
	}
	case 4:			//both players have a three of a kind
	{
		valueType trip1, trip2;

		for (int i = 0; i < 7; i++)
		{
			if (numOfApp(h1, h1->hand[i].value) == 3 && h1->hand[i].value > trip1)
				trip1 = h1->hand[i].value;
			if (numOfApp(h2, h2->hand[i].value) == 3 && h2->hand[i].value > trip2)
				trip2 = h2->hand[i].value;
		}

		if (trip1 > trip2)
			return Win;
		if (trip2 > trip1)
			return Loss;

		valueType maxNotTrip1 = 2, maxNotTrip2 = 2;

		for (int i = 0; i < 7; i++)
		{
			if (h1->hand[i].value != trip1 && h1->hand[i].value > maxNotTrip1)
				maxNotTrip1 = h1->hand[i].value;
			if (h2->hand[i].value != trip2 && h1->hand[i].value > maxNotTrip2)
				maxNotTrip2 = h2->hand[i].value;
		}

		if (maxNotTrip1 > maxNotTrip2)
			return Win;
		if (maxNotTrip2 > maxNotTrip1)
			return Loss;

		valueType secondHigh1 = 2, secondHigh2 = 2;

		for (int i = 0; i < 7; i++)
		{
			if (h1->hand[i].value != trip1 && h1->hand[i].value != maxNotTrip1 && h1->hand[i].value > secondHigh1)
				secondHigh1 = h1->hand[i].value;
			if (h2->hand[i].value != trip2 && h2->hand[i].value != maxNotTrip2 && h2->hand[i].value > secondHigh2)
				secondHigh2 = h2->hand[i].value;
		}

		if (secondHigh1 > secondHigh2)
			return Win;
		if (secondHigh2 > secondHigh1)
			return Loss;
		return Split;
	}
	}
}