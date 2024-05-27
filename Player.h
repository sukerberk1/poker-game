#pragma once
#ifndef PLAYER
#include <iostream>
#include <vector>
#include <array>
#include "Deck.h"

class Player
{
public:
	Player(std::string name);
	/* Adds cash for the player */
	void addCash(unsigned int x);
	/* Takes cash away from the player */
	int subtractCash(unsigned int y);
	/* Adds a card to the player's hand. If hand is already fully set (hand contains 2 cards), does nothing. */
	void giveCard(Card card);
	/* Resets cards of a given player. Internally sets the underying pointer to the new array of 2 card placeholders */
	void resetCards();
	/*  Returns a copy of player's cards. */
	std::array<Card, 2> getCards();
    std::string getName() const;
    bool hasFolded() const;
    int getCurrentBet() const;
    void setCurrentBet(int bet);
    void fold();
private:
	std::string name;
	std::array<Card, 2> hand;
	unsigned int cash;
    bool folded = false;
    int currentBet = 0;
};
#endif // !PLAYER



