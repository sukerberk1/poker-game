#include "BettingCycle.h"

Bet::Bet(Player* player) {
	this->player = player;
	this->bet = 0;
	this->folded = false;
}

void Bet::fold() {
	this->folded = true;
}

unsigned int Bet::getAmount() {
	return this->bet;
}

bool Bet::isFolded() {
	return this->folded;
}

void Bet::askPlayerForBet(unsigned int minAmount) {
	//TODO!
}

BettingCycle::BettingCycle(std::vector<Player*>* roundPlayers) 
{
	this->roundPlayers = roundPlayers;
	this->turn = 0;
	for (Player* p : *roundPlayers)
	{
		this->playerBets.push_back(Bet(p));
	}
}

void BettingCycle::run() {
	do
	{
		turn++;
		Bet* currentBet = getCurrentBet();
		if (currentBet->isFolded())
			continue;
		currentBet->askPlayerForBet(getPreviousBet()->getAmount());
		
	} while (!areBetsEstablished());
	removeFoldedPlayersFromRound();
}

/* Bets are considered established when all are equal, all the players have made the decision, and a player had a chance to raise after the full circle */
bool BettingCycle::areBetsEstablished() {
	return turn > roundPlayers->size() && areBetsEqual();
}

void BettingCycle::removeFoldedPlayersFromRound() {
	//TODO!
}

bool BettingCycle::areBetsEqual() {
	//TODO!
	return false;
}

unsigned int BettingCycle::getTotalBetAmount() {
	//TODO!
	return 0;
}

Bet* BettingCycle::getCurrentBet() {

}

Bet* BettingCycle::getPreviousBet() {
	//TODO!
	return nullptr;
}