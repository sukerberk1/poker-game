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

/*Card Deck::drawFirstCard() {
	Card firstCard = cards.back();
	cards.pop_back();
	return firstCard;
}

Card Deck::drawSecondCard() {
	Card secondCard = cards.back();
	cards.pop_back();
	return secondCard;
}

Card Player::takeCard() {
	Deck::drawFirstCard();
	hand.back();
	Deck::drawSecondCard();
	hand.back();
}*/

Card Deck::drawCard() {
	Card drawnCard = cards.back();
	cards.pop_back();
	return drawnCard;
}



int main() {
	Deck drawingCards;
	std::cout << "Current money in your wallet: " << player.cash << std::endl;
	std::cout << "Cards in your hand: \n";
	for (int i = 0; i < 2; i++) {
		Card drawnCard = drawingCards.drawCard();
		drawnCard.displayDebug();
	}
	
	return 0;
};