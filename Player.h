#pragma once
#ifndef PLAYER
#include <iostream>
#include <vector>
#include <array>
#include "Deck.h"

class Player
{
private:
	std::string name;
	std::array<Card, 2> hand;
	unsigned int cash;
public:
	Player();
	Player(std::string name);
	/* Adds cash for the player */
	void addCash(unsigned int x);
	/* Takes cash away from the player */
	unsigned int takeCash(unsigned int y);
	/* Adds a card to the player's hand. If hand is already fully set (hand contains 2 cards), does nothing. */
	void giveCard(Card card);
	/* Resets cards of a given player. Internally sets the underying array to new array of 2 card placeholders */
	void resetCards();
	/*  Returns a copy of player's cards. */
	std::array<Card, 2> getCards();
	std::string getName();
	unsigned int getCash();
	void display();
	void displayDebug();
};
#endif // !PLAYER



