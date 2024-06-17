#include <iostream>
#include <string>
#include <algorithm>
#include "../include/Card.h"

Card::Card(int power, char color) {
	if (isColorValid(color) && isPowerValid(power)) {
		this->color = color;
		this->power = power;
	}
	else {
		std::cout << "Card constructor misuse. See card class for details.";
		throw;
	}
}

/* Placeholder constructor */
Card::Card() : power(0), color('P') {}

Card Card::PLACEHOLDER() { return Card(); }

bool Card::isPlaceholder(Card card) {
	return card.getPower() == 0 && card.getColor() == 'P';
}



bool Card::isColorValid(char color) {
	std::array<char, 4> colors = getValidColors();
	return !(std::find(colors.begin(), colors.end(), color) == colors.end());
}
/*	14 - ace 
	13 - king 
	12 - queen 
	11 - jopek
	10 - 2 - numbers
*/ 
bool Card::isPowerValid(short power) {
	return power >= getValidPowers().at(0) && power <= getValidPowers().at(12);
}

/*
	S - spades
	C - clubs
	H - hearts
	D - diamonds
*/
std::array<char,4> Card::getValidColors() {
	std::array<char, 4> validColors {'S', 'C', 'H', 'D'};
	return validColors;
}

std::array<short, 13> Card::getValidPowers() {
	std::array<short, 13> validPowers { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
	return validPowers;
}

short Card::getPower() {
	return this->power;
}
char Card::getColor() {
	return this->color;
}

void Card::display()
{
	if (Card::isPlaceholder(*this)) {
		std::cout << "[No card in this slot]" << std::endl;
		return;
	}
	std::string colorName;
	switch (this->color)
	{
	case 'S':
		colorName = "Spades"; 
		break;
	case 'H':
		colorName = "Hearts"; 
		break;
	case 'D':
		colorName = "Diamonds"; 
		break;
	case 'C':
		colorName = "Clubs"; 
		break;
	default:
		break;
	}
	std::string powerName;
	switch (this->power)
	{
	case 11:
		powerName = "Jester";
		break;
	case 12:
		powerName = "Queen";
		break;
	case 13:
		powerName = "King";
		break;
	case 14:
		powerName = "Ace";
		break;
	default:
		powerName = std::to_string(this->power);
	}
	std::cout << powerName << " of " << colorName << std::endl;
}

void Card::displayDebug() {
	std::cout << "Card: { Color: " << this->color << ", Power: " << this->power << "}" << std::endl;
}
