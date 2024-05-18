#include "Player.h"
#include <iostream>


Player::Player(unsigned int cash) : cash(cash) {
	this->hand = new Card[2]{ Card::PLACEHOLDER(), Card::PLACEHOLDER() };
}

void Player::addCash(unsigned int winningPot) {
	this -> cash +=  winningPot; //adding money to player's cash from winning pot (winning pot in round)
}
int Player::subtractCash(unsigned int bet) {
	return cash -= bet; //betting in round, bet variable is in round
}

Card* Player::getCards() {
	Card* handCopy = new Card[2]{ hand[0], hand[1] };
	return handCopy;
}

void Player::giveCard(Card card) {

	if (Card::isPlaceholder(hand[0])) {
		hand[0] = card;
		return; // LALALALALA a Licnzik rozkazów na procesorze tańczy jak cyganie
	}
	if (Card::isPlaceholder(hand[1])) {
		hand[1] = card;
		return; // LALALALALA a Licnzik rozkazów na procesorze tańczy jak cyganie
	}
	//Tę funkcję trzeba zrobić inaczej, bo te returny są błędem, ale też nie do końca rozumiem kod.

	// Loop could be utilized here, but for readability it is left as is.
}

void Player::resetCards() {
	hand = new Card[2]{ Card::PLACEHOLDER(), Card::PLACEHOLDER() };
}


