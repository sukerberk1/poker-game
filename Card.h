#pragma once
#ifndef CARD

class Card {
private:
	short power;
	char color;
	

	bool isColorValid(char color);
	bool isPowerValid(short power);

	string displayColorName(char color);
	string displayPowerName(short power);

	/* Private constructor for ommiting validation for placeholder purposes */
	Card();
public:
	Card(int power, char color);

	short getPower();
	char getColor();
    static const char validColors[4];
	static char* getValidColors();
	static short* getValidPowers();
	static Card PLACEHOLDER();
	static bool isPlaceholder(Card card);

	void display();
	void displayDebug();
};

#endif // !CARD
