#include "Player.h"
#include <iostream>


Player::Player(std::string name) : 
	cash(0), 
	name(name),
	hand(std::array<Card, 2> { Card::PLACEHOLDER(), Card::PLACEHOLDER() }) 
{ }

void Player::addCash(unsigned int winningPot) {
	cash +=  winningPot; //adding money to player's cash from winning pot (winning pot in round)
}
int Player::subtractCash(unsigned int bet) {
	return cash -= bet; //betting in round, bet variable is in round
}

std::array<Card, 2> Player::getCards() {
	return hand;
}

void Player::giveCard(Card card) {
	if (Card::isPlaceholder(hand.at(0))) {
		hand[0] = card;
		return;
	}
	if (Card::isPlaceholder(hand.at(1))) {
		hand[1] = card;
		return;
	}
	// Loop could be utilized here, but for readability it is left as is.
}

void Player::resetCards() {
	hand.fill(Card::PLACEHOLDER());
}


