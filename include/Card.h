#pragma once
#ifndef CARD
#include <array>

class Card {
private:
	short power;
	char color;
	

	bool isColorValid(char color);
	bool isPowerValid(short power);

public:
	/* Private constructor for ommiting validation for placeholder purposes. May not be used to create valid cards */
	Card();
	Card(int power, char color);

	short getPower();
	char getColor();
	static std::array<char, 4> getValidColors();
	static std::array<short, 13> getValidPowers();
	static Card PLACEHOLDER();
	static bool isPlaceholder(Card card);

	void display();
	void displayDebug();
};

#endif // !CARD
