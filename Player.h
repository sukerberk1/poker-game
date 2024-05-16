#pragma once
#ifndef PLAYER
#include <iostream>
#include <vector>
#include "Deck.h"
class Player
{
public:
	Player(unsigned int cash);
	/* Adds cash for the player */
	void addCash(unsigned int x);
	/* Takes cash away from the player */
	int subtractCash(unsigned int y);
	/* Adds a card to the player's hand. If hand is already fully set (hand contains 2 cards), does nothing. */
	void giveCard(Card card);
	/* Resets cards of a given player. Internally sets the underying pointer to the new array of 2 card placeholders */
	void resetCards();
	/* 
	Returns a pointer to the copy of the hand array. Note that it points to the copy, 
	therefore modification of the returned array does not affect the player
	*/
	Card* getCards();
	
private:
	Card* hand;
	unsigned int cash;
};
#endif // !PLAYER



