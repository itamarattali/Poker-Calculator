#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum { False, True }booly;

typedef char suitType;

const char suitArr[4] = { 'H', 'D', 'S', 'C' };

typedef int valueType;

typedef struct cardType
{
	valueType value;
	suitType suit;
}card, *cardPtr;

cardPtr buildCard(valueType value, suitType suit);
