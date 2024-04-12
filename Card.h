#pragma once
#ifndef CARD

class Card {
private:
	short power;
	char color;
	static const char validColors[4];

	bool isColorValid(char color);
	bool isPowerValid(short power);

public:
	Card(int power, char color);
	void display();
	void displayDebug();

	short getPower();
	char getColor();
	static char* getValidColors();
	static short* getValidPowers();
};

#endif // !CARD
