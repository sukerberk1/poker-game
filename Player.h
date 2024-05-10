#pragma once
#ifndef PLAYER
#include <iostream>
#include "Deck.h"
class Player
{
public:
	int cash;
	struct {
		std::string firstCard;
		std::string secondCard;
	} hand;
};
#endif // !1



