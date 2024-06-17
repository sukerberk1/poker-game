#include "../include/Round.h"
#include "../include/BettingCycle.h"
#include "../include/FigureMatcher.h"
#include "../include/Display.h"

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
	std::vector<Player*> regardedPlayers(players);
	for (FigureMatcher matcher : FigureMatcher::getAllMatchersDescending()) {
		std::vector<Player*> thisMatchWinners; 
		for (Player* player : regardedPlayers) {
			if (matcher.doesMatch(tableCards, player->getCards()))
				thisMatchWinners.push_back(player);
		}
		if (thisMatchWinners.size() > 0) {
			regardedPlayers = std::vector<Player*>(thisMatchWinners);
		}
	}
	if (regardedPlayers.size() == 1) 
		return regardedPlayers[0];
	else 
		return FigureMatcher::resolveHighCard(regardedPlayers);
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
	Player* winner = resolveRound();
	Display::announceWinner(winner, pool);
	winner->addCash(pool);
}
