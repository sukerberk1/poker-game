#include "Player.h"
#include "deck.cpp"
#include <iostream>

//Have to add drawing cards
Player player;
int Player::addCash(int winningPot) {
	player.cash = player.cash + winningPot; //adding money to player's cash from winning pot
	return player.cash;
}
int Player::takeCash(int bet) {
	/*std::cout << "How much money you want to bet?\n";
	std::cin >> bet;
	return player.cash - bet;*/
	return player.cash - bet;
}

Card Deck::drawFirstCard() {
	Card firstCard = cards.back();
	cards.pop_back();
	
	return firstCard;
}

Card Deck::drawSecondCard() {
	Card secondCard = cards.back();
	cards.pop_back();
	return secondCard;
}
int main() {
	Deck drawningCards;
	std::cout << "Current money in your wallet: " << player.cash << std::endl;
	std::cout << "Your cards: " << Deck::drawFirstCard() <<" " << Deck::drawSecondCard() << std::endl;
	
	return 0;
};