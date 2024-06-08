#include "Round.h"
#include "BettingCycle.h"


Round::Round(std::vector<Player*> players) 
	: tableCards({ Card::PLACEHOLDER(), Card::PLACEHOLDER(), Card::PLACEHOLDER(), Card::PLACEHOLDER(), Card::PLACEHOLDER() }) 
	, players(players)
	, turnNumber(0)
	, pool(0)
{
	giveCardsToPlayers();
}

void Round::giveCardsToPlayers() {
	deck.shuffle();
	for (Player* player : players) {
		player->giveCard(deck.drawCard());
		player->giveCard(deck.drawCard());
	}
}

void Round::placeTableCards(short turnNumber) {
	switch (turnNumber)
	{
	case 0:
		tableCards[0] = deck.drawCard();
		tableCards[1] = deck.drawCard();
		tableCards[2] = deck.drawCard();
		break;
	case 1:
		tableCards[3] = deck.drawCard();
		break;
	case 2:
		tableCards[4] = deck.drawCard();
		break;
	}
}

std::array<Card, 5> Round::getTableCards() {
	return tableCards;
}

void Round::gatherBetsFromPlayers() {
	BettingCycle bettingCycle = BettingCycle(&players, &tableCards);
	bettingCycle.run();
	pool += bettingCycle.getTotalBetAmount();
}

Player* Round::resolveRound() {
	//TODO!
	return players.at(0);
}

unsigned int Round::getPool()
{
	return pool;
}

void Round::run()
{
	short turnNumber = 0;
	while (turnNumber < 3) {
		this->gatherBetsFromPlayers();
		this->placeTableCards(turnNumber);
		turnNumber++;
	}
	this->gatherBetsFromPlayers(); // last betting turn
}
