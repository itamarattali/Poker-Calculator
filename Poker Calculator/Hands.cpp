#include "Hands.h"

hand initHand(pocket p, board b)
{
	handPtr h = (hand*)malloc(sizeof(hand));

	h->arr[0] = p.card1;	h->arr[1] = p.card2;

	h->arr[2] = b.f.card1;	h->arr[3] = b.f.card2;

	h->arr[4] = b.f.card3;	h->arr[5] = b.t.turn;

	h->arr[6] = b.r.river;

	return *h;
}
