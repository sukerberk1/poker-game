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

const char Card::validColors[4] = {'S', 'C', 'H', 'D'};

bool Card::isColorValid(char color) {
	/*
		S - spades
		C - clubs
		H - hearts
		D - diamonds
	*/
	return !(color == 'S' || color == 'C' || color == 'H' || color == 'D');
}

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