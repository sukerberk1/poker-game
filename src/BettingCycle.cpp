#include "../include/BettingCycle.h"
#include "../include/Display.h"

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

void Bet::askPlayerForAction(std::array<Card, 5> tableCards, unsigned int minBetAmount) {
	std::vector<std::string> options { "CALL", "RAISE", "FOLD" };
	int currentChoiceIdx = 0;
	std::string finalChoice = "";
	do {
		Display::clear();
		Display::showTableCards(tableCards);
		this->player->display();
		std::cout << "You have bet already " << this->bet << " in this turn." << std::endl;
		std::cout << "To CALL you must bet at least " << minBetAmount << std::endl << std::endl;
		finalChoice = Display::optionChoiceInterface(options, currentChoiceIdx);
	} while (finalChoice.size() == 0);

	if (finalChoice == "FOLD") {
		this->fold();
		return;
	}
	unsigned int wannaBetAmount = 0;
	if (finalChoice == "CALL") {
		wannaBetAmount = minBetAmount;
	}
	else if (finalChoice == "RAISE") {
		std::cout << "What is your desired bet? ";
		std::cin >> wannaBetAmount;
		if (wannaBetAmount < minBetAmount) {
			std::cout << "You did not raise the bet...";
			Display::awaitAcknowledge();
			return askPlayerForAction(tableCards, minBetAmount);
		}
	}
	if (player->getCash() < wannaBetAmount) {
		std::cout << "You may not bet this amount since your balance is only " << player->getCash() << std::endl;
		Display::awaitAcknowledge();
		return askPlayerForAction(tableCards, minBetAmount); // this call is a workaround for coming back to the loop
	}
	player->takeCash(wannaBetAmount - this->bet);
	this->bet = wannaBetAmount;
}

void Bet::displayDebug()
{
	std::cout << "Bet: player " << player->getName() << "; bet: " << this->bet << "; fold: " << this->folded << std::endl;
}

BettingCycle::BettingCycle(std::vector<Player*>* roundPlayers, std::array<Card, 5>* tableCards) 
{
	this->tableCards = tableCards;
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
		Display::announceBet(currentBet->getPlayerPointer());
		currentBet->askPlayerForAction(*tableCards, getPreviousBet()->getAmount());
		turn++;
	} while (!areBetsEstablished());
	removeFoldedPlayersFromRound();
}

/* Bets are considered established when all are equal, all the players have made the decision, and a player had a chance to raise after the full circle */
bool BettingCycle::areBetsEstablished() {
	return turn >= roundPlayers->size() && areBetsEqual();
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
		if (bet.isFolded())
			continue;
		betAmount = bet.getAmount();
		break;
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
	std::cout << "Searching for previous bet" << std::endl;
	int currentIndex = turn % playerBets.size();
	int prevIndex = currentIndex == 0 ? playerBets.size() - 1 : currentIndex - 1;
	while (playerBets.at(prevIndex).isFolded()) {
		prevIndex = prevIndex == 0 ? playerBets.size() - 1 : prevIndex - 1;
	}
	std::cout << "Prev bet found" << std::endl;
	return &(playerBets.at(prevIndex));
}
