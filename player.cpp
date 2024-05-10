#include "Player.h"
#include "deck.cpp"
#include <iostream>

int main() {
	Player player;
	player.cash = 10000; //to change for some keyboard input, but later
	player.hand.firstCard = ; //giving cards to player's hand
	player.hand.secondCard = ;
	std::cout << "Your cards: " << player.hand.firstCard <<" " << player.hand.secondCard << std::endl;
	return 0;
};