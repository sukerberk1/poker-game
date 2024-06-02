#pragma once
#ifndef BETTING_CYCLE_H
#include <vector>
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
	bool folded;
public:
	Bet(Player* player);
	bool isFolded();
	void fold();
	unsigned int getAmount();
	void askPlayerForBet(unsigned int minAmount);
};


/*
Betting cycle is defined as a turn of betting that takes place between each card reveal.
*/
class BettingCycle
{
private:
	std::vector<Player*>* roundPlayers;
	/* playerBets is initialized to contain active (unfolded) bets with bet amount equal to 0 */
	std::vector<Bet> playerBets;
	int turn;

	Bet* getPreviousBet();
	Bet* getCurrentBet();
	bool areBetsEqual();
	bool areBetsEstablished();
	/* Removes folded players from the roundPlayers. Affects round's state */
	void removeFoldedPlayersFromRound();
	
public:
	BettingCycle(std::vector<Player*>* roundPlayers);
	void run();
	unsigned int getTotalBetAmount();
};

#endif // !BETTING_CYCLE_H
