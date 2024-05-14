#include "Player.h"
#include <iostream>


Player::Player(int cash) {
	if (cash >= 0) {
		this->cash = cash;
	}
	else {
		throw;
	}
}

void Player::addCash(unsigned int winningPot) {
	this -> cash +=  winningPot; //adding money to player's cash from winning pot (winning pot in round)
}
int Player::subsractCash(unsigned int bet) {
	return cash -= bet; //betting in round, bet variable is in round
}

Card Deck::drawCard() {
	Card drawnCard = cards.back();
	cards.pop_back();
	return drawnCard;
}

Card* Player::getCards() {
	Card card1 = Deck::drawCard();
	Card card2 = Deck::drawCard();
	Player::giveCards(card1, card2);
}

void Player::giveCards(Card c1, Card c2) {
	Player::hand[0] = {c1};
	Player::hand[1] = {c2};
}

void Player::resetHand() {
	Player::hand[0] = {0, 0};
	Player::hand[1] = {0, 0};
}


