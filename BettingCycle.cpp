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

Player* Bet::getPlayerPointer() {
	return this->player;
}

//TODO: refactor to support PlayerAction enum and wyjebać goto
void Bet::askPlayerForAction(unsigned int minBetAmount) {
	this->player->display();
	std::cout << "Your balance: " << this->player->getCash() << std::endl;
	std::cout << "You must now bet at least " << minBetAmount << std::endl;
	std::cout << "![Bet 69 to fold]" << std::endl;
	checkpoint:
	unsigned int betAmount;
	std::cout << "Place your bet: ";
	std::cin >> betAmount;
	std::cout << std::endl;
	if (betAmount == 69) {
		fold();
		return;
	}
	if (betAmount > player->getCash()) {
		std::cout << "You dont have such money! Try placing your bet again\n";
		goto checkpoint;
	}
	player->takeCash(betAmount - this->bet);
	this->bet = betAmount;
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
		Bet* currentBet = getCurrentBet();
		if (currentBet->isFolded())
			continue;
		unsigned int prevBetAmount = getPreviousBet()->getAmount();
		currentBet->askPlayerForAction(prevBetAmount);
		turn++;
	} while (!areBetsEstablished());
	removeFoldedPlayersFromRound();
}

/* Bets are considered established when all are equal, all the players have made the decision, and a player had a chance to raise after the full circle */
bool BettingCycle::areBetsEstablished() {
	return turn > roundPlayers->size() && areBetsEqual();
}

void BettingCycle::removeFoldedPlayersFromRound() {
	for (Bet bet : playerBets) {
		if (bet.isFolded())
			roundPlayers->erase(std::find(roundPlayers->begin(), roundPlayers->end(), bet.getPlayerPointer()));
	}
}

bool BettingCycle::areBetsEqual() {
	unsigned int betAmount = 0;
	for (Bet bet : playerBets) {
		if (!bet.isFolded()) {
			betAmount = bet.getAmount();
			break;
		}
	}
	for (Bet bet : playerBets) {
		if (bet.isFolded())
			continue;
		if (bet.getAmount() != betAmount)
			return false;
	}
	return true;
}

unsigned int BettingCycle::getTotalBetAmount() {
    int totalBetAmount = 0;
    for (Bet bet : playerBets) {
        totalBetAmount += bet.getAmount(); 
    }
    return totalBetAmount;
	
}

Bet* BettingCycle::getCurrentBet() {
	int currentIndex = turn % playerBets.size();
	return &(playerBets.at(currentIndex));
}

Bet* BettingCycle::getPreviousBet() {
	int currentIndex = turn % playerBets.size();
	int prevIndex;

	if (currentIndex == 0) {
		prevIndex = playerBets.size() - 1;
	}
	else {
		prevIndex = currentIndex - 1;
	}
	return &(playerBets.at(prevIndex));
}