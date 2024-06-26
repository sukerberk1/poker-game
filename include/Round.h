#pragma once
#ifndef ROUND_H
#define ROUND_H
#include <vector>
#include <array>
#include "Player.h"
#include "Deck.h"

class Round
{
private:
	/* 
	Players vector consists of players that are still within the round. At the beginning all the players that have
	enough cash to place at least one bet can play. If the player runs out of money OR folds in the betting cycle,
	he is removed from the players on the Round level.
	*/
	std::vector<Player*> players;
	unsigned int pool;
	Deck deck;
	short turnNumber;
	/* Cards on the table. Placeholders will be used when the card is not disposed yet. */
	std::array<Card, 5> tableCards;
	void giveCardsToPlayers();
public:
	/* 
	Round constructor takes in a vector of players. Round constructor initializes all the private values
	as well as gives all the players cards. Note that the state of the players will change after the constructor is called.
	*/
	Round(std::vector<Player*> players);
	/* Function designed to be used together with displaying the current place of cards on the table. */
	void placeTableCards(short turnNumber);
	std::array<Card, 5> getTableCards();
	/* Function gathering bets from players, running a betting cycle */
	void gatherBetsFromPlayers();
	/*
	Resolves round returning the pointer to the player that won. This function cashes out the prize into the winners' account
	*/
	Player* resolveRound();
	unsigned int getPool();
	void run();
};

#endif // !ROUND_H

