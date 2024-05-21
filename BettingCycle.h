#pragma once
#ifndef BETTING_CYCLE_H
#include <vector>
#include <optional>
#include "Player.h"

enum PlayerAction {
	FOLD,
	CALL,
	RAISE
};

class Bet {
private:
	Player* player;
	unsigned int bet;
	bool inGame;
public:
	Bet(Player* player, unsigned int bet);
};

/*
Betting cycle is defined as a turn of betting that takes place between each card reveal.
*/
class BettingCycle
{
private:
	std::vector<Player*>* roundPlayers;
	unsigned int totalBets;
	unsigned int currentBet;
	std::vector<Bet> playerBets;

	std::optional<Bet> getPlayerBet(Player* player);
	/* Removes folded players from the roundPlayers. Folded players are computed based on playerBets and roundPlayers fields. */
	void removeFoldedPlayers();
	bool areBetsEqual();
	void playerBettingDisplay(unsigned int* betAmount, std::string playerName);
public:
	BettingCycle(std::vector<Player*>* roundPlayers);
	void getBets();
	unsigned int getTotalBets();
};

#endif // !BETTING_CYCLE_H