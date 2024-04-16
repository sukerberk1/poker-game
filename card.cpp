#include <iostream>
#include "Card.h"

Card::Card(int power, char color) {
	if (isColorValid(color) && isPowerValid(power)) {
		this->color = color;
		this->power = power;
	}
	else {
		throw;
	}
}

/*
	S - spades
	C - clubs
	H - hearts
	D - diamonds
*/
const char Card::validColors[4] = {'S', 'C', 'H', 'D'};

bool Card::isColorValid(char color) {
	for (int i = 0; i < 4; i++) {
		if (validColors[i] == color)
			return true;
	}
	return false;
}
/*	14 - ace 
	13 - king 
	12 - queen 
	11 - jopek
	10 - 2 - numbers
*/ 
bool Card::isPowerValid(short power) {
	return power >= 2 && power <= 14;
}

char* Card::getValidColors() {
	char* validColorsCopy = new char[4];
	for (int i = 0; i < 4; i++) {
		validColorsCopy[i] = validColors[i];
	}
	return validColorsCopy;
}

short Card::getPower() {
	return this->power;
}
char Card::getColor() {
	return this->color;
}

void Card::displayDebug() {
	std::cout << "Card: { Color: " << this->color << ", Power: " << this->power << "}" << std::endl;
}