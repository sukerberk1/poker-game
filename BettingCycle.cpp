#include "BettingCycle.h"

Bet::Bet(Player* player, unsigned int bet) {
	this->player = player;
	this->bet = bet;
	this->inGame = true;
}

//BettingCycle::BettingCycle(std::vector<Player*>* roundPlayers) {
//	this->
//}

void BettingCycle::getBets() {
	/* Initial turn - players are betting */
	for (Player* player : *roundPlayers) {
		std::optional<Bet> bet = getPlayerBet(player);
		if (bet.has_value())
			playerBets.push_back(bet.value());
	}
	/* Next turns - players must all have equal bets at the end of this billing cycle */
	do {
		// TODO!
	} while (!areBetsEqual());
	/* End - remove folded players from the round */
	removeFoldedPlayers();
}

std::optional<Bet> BettingCycle::getPlayerBet(Player* player) {
	unsigned int betAmount;
	playerBettingDisplay(&betAmount, player->getName());
	if (betAmount == 0)
		return std::nullopt;
	return std::optional{ Bet(player, betAmount) };
}

// 	Function checks if every player in roundPlayers has their bets in playerBets vector. If there is a player in roundPlayers
//  and there is no bet from that player in playerBets, they should be removed. 
void BettingCycle::removeFoldedPlayers() {
	
}

void BettingCycle::playerBettingDisplay(unsigned int* betAmount, std::string playerName) {

}

// This function checks if all bets in playerBets have the same bet value.
bool BettingCycle::areBetsEqual() {
	
	return false;
}