#pragma once
#ifndef PLAYER
#include <iostream>
#include <vector>
#include "Deck.h"
class Player
{
public:
	static int cash;
	/*struct {
		std::string firstCard;
		std::string secondCard;
	} hand;*/
	
	//int hand[2] = {firstCard, secondCard};
	int addCash(int x); //funkcja dodaj¹ca pieni¹dze do konta gracza - x - pula aktualnej rozgrywki
	int takeCash(int y); //funkcja odejmuj¹ca pieni¹dze z konta gracza - y - wysokoœæ betu
	Card takeCard(); //
private:
	std::vector<Deck> hand;
};
#endif // !PLAYER



