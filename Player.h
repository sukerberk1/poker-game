#pragma once
#ifndef PLAYER
#include <iostream>
#include <vector>
#include "Deck.h"
class Player
{
public:
	Player(int cash);
	/*struct {
		std::string firstCard;
		std::string secondCard;
	} hand;*/
	
	//int hand[2] = {firstCard, secondCard};
	void addCash(unsigned int x); //funkcja dodaj¹ca pieni¹dze do konta gracza - x - pula aktualnej rozgrywki
	int subsractCash(unsigned int y); //funkcja odejmuj¹ca pieni¹dze z konta gracza - y - wysokoœæ betu
	void giveCards(Card c1, Card c2);
	void resetHand();
	Card* getCards();
	
private:
	Card hand[2];
	int cash;
};
#endif // !PLAYER



