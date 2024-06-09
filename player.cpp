#include "Player.h"
#include <iostream>

//TODO: fix this auto constructor ?
Player::Player() : 
	cash(0),
	name("Player"),
	hand(std::array<Card, 2> { Card::PLACEHOLDER(), Card::PLACEHOLDER() })
{ }

Player::Player(std::string name) :
	cash(0), 
	name(name),
	hand(std::array<Card, 2> { Card::PLACEHOLDER(), Card::PLACEHOLDER() }) 
{ }

void Player::addCash(unsigned int winningPot) {
	cash +=  winningPot; //adding money to player's cash from winning pot (winning pot in round)
}
unsigned int Player::takeCash(unsigned int bet) {
	return cash -= bet; //betting in round, bet variable is in round
}

std::array<Card, 2> Player::getCards() {
	return hand;
}

unsigned int Player::getCash() {
	return cash;
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

std::string Player::getName() {
	return name;
}

void Player::displayDebug() {
	std::cout << "Player: { name: " << name << " , cash: " << cash << std::endl;
	std::cout << "Hand cards: " << std::endl; 
	hand[0].displayDebug();
	hand[1].displayDebug();
}

void Player::display() {
	std::cout << "Player: " << name << std::endl;
	std::cout << "Cash: " << cash << std::endl;
	std::cout << "Cards:" << std::endl;
	hand[0].display();
	hand[1].display();
}
