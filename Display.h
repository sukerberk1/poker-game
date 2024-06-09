#pragma once
#ifndef DISPLAY_H
#define DISPLAY_H
#include <vector>
#include "Player.h"

/* This class is a result of a spaghetti design, moreover a helper function for display feature */
class Display
{
public:
	static void clear();
	static void awaitAcknowledge();
	/* Provides choice menu. Returns chosen option if choise occured, empty string otherwise */
	static std::string optionChoiceInterface(std::vector<std::string> options, int& chosenIdx);
	static void announceBet(Player* player);
	static void showTableCards(std::array<Card, 5> tableCards);
	static void announceWinner(Player* player, int wonAmount);
};

#endif // !DISPLAY_H