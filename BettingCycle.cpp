#include "BettingCycle.h"
#include <iostream>
#include <algorithm>

int BettingCycle::getCurrentBet() const {
    return currentBet;
}

int BettingCycle::getPreviousBet() const {
    return previousBet;
}

void BettingCycle::setCurrentBet(int bet) {
    previousBet = currentBet;
    currentBet = bet;
}

void BettingCycle::setPreviousBet(int bet) {
    previousBet = bet;
}

int BettingCycle::askPlayerForBet(Player& player) {
    int betAmount;
    std::cout << player.getName() << ", ile chcesz obstawić? ";
    std::cin >> betAmount;
    setPreviousBet(getCurrentBet());
    setCurrentBet(betAmount);
    player.setCurrentBet(betAmount); // Ustawienie aktualnego zakładu gracza
    return betAmount;
}

void BettingCycle::removeFoldedPlayersFromRound(std::vector<Player>& players) {
    players.erase(
        std::remove_if(players.begin(), players.end(), [](Player& player) {
            return player.hasFolded();
        }),
        players.end()
    );
}

bool BettingCycle::areBetsEqual(const std::vector<Player>& players) {
    if (players.empty()) return true;
    int firstBet = players.front().getCurrentBet();
    return std::all_of(players.begin(), players.end(), [firstBet](const Player& player) {
        return player.getCurrentBet() == firstBet;
    });
}

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


BettingCycle::BettingCycle(std::vector<Player*>* roundPlayers) 
{
	this->roundPlayers = roundPlayers;
	this->turn = 0;
	for (Player* p : *roundPlayers)
	{
		this->playerBets.push_back(Bet(p));
	}
}

void BettingCycle::run(std::vector<Player>& players) {
    bool betsEqual = false;

    while (!betsEqual) {
        for (Player& player : players) {
            if (!player.hasFolded()) {
                int betAmount = askPlayerForBet(player);
                player.setCurrentBet(betAmount);
            }
        }
        
        removeFoldedPlayersFromRound(players);
        betsEqual = areBetsEqual(players);
    }

    std::cout << "Wszyscy gracze wyrównali swoje zakłady." << std::endl;
}
unsigned int BettingCycle::getTotalBetAmount() {
	//TODO!
	return 0;
}
