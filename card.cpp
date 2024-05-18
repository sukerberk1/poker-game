#include <iostream>
#include <string>
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

/* Placeholder constructor */
Card::Card() : power(0), color('P') {}

Card Card::PLACEHOLDER() { return Card(); }

bool Card::isPlaceholder(Card card) {
	return card.getPower() == 0 && card.getColor() == 'P';
}

/*
	S - spades
	C - clubs
	H - hearts
	D - diamonds
*/
const char Card::validColors[4] = {'S', 'C', 'H', 'D'};

bool Card::isColorValid(char color) //TEN DEBIL CO TO ROBIŁ TO CHYBA NIE UMIE WSKAŹNIKÓW(ZRESZTĄ JA TEŻ NIE, DLATEGO KODUJE W POWERSHELL). WEŹ TU SZYMON UŻYK: std:find, bo mnie krew zalewa: https://stackoverflow.com/questions/19215027/check-if-element-found-in-array-c
{ 
	for (int i = 0; i < 4; i++) {
		if (validColors[i] == color)
		return true;
	}
	return false;
}
/*	14 - ace 
	13 - king 
	12 - queen 
	11 - walet
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

short* Card::getValidPowers() {
	short* validPowers = new short[13];
	for (short i = 0; i < 13; i++)
	{
		validPowers[i] = i+2;
	}
	return validPowers;
}

short Card::getPower() {
	return this->power;
}
char Card::getColor() {
	return this->color;
}


string displayColorName (char color)
{
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
	return colorName;
}

string displayPowerName(short power)
{
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
	return powerName;
}

void Card::display()
{
	std::cout << this->displayPowerName(this->power) << " of " << this->displayColorName(this->color) << std::endl;
}

void Card::displayDebug() {
	std::cout << "Card: { Color: " << this->color << ", Power: " << this->power << "}" << std::endl;
}