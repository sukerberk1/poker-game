#pragma once
#ifndef BETTING_CYCLE_H
#include <vector>
#include "Player.h"

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
	Player* getPlayerPointer();
	void askPlayerForAction(std::array<Card, 5> tableCards, unsigned int minBetAmount);
	void displayDebug();
};


/*
Betting cycle is defined as a turn of betting that takes place between each card reveal.
*/
class BettingCycle
{
private:
	std::vector<Player*>* roundPlayers;
	std::array<Card, 5>* tableCards;
	/* playerBets is initialized to contain active (unfolded) bets with bet amount equal to 0 */
	std::vector<Bet> playerBets;
	/* Variable acting as index for players betting counting */
	int turn;

	Bet* getPreviousBet();
	Bet* getCurrentBet();
	/* Function checks whether all active (not folded) bets are equal */
	bool areBetsEqual();
	/* 
	Function checks whether betting is finished in current cycle - thus, checks for equality using areBetsEqual()
	and checks if all players had a chance to bet or raise.
	*/
	bool areBetsEstablished();
	/* Removes folded players from the roundPlayers. Affects round's state using roundPlayers vector pointer */
	void removeFoldedPlayersFromRound();
	
public:
	BettingCycle(std::vector<Player*>* roundPlayers, std::array<Card, 5>* tableCards);
	void run();
	unsigned int getTotalBetAmount();
};

#endif // !BETTING_CYCLE_H
