class Card {
private:
	short power;
	char color;

	bool isColorValid(char color) {
		return !(color == 'S' || color == 'C' || color == 'H' || color == 'D');
	}

	bool isPowerValid(short power) {
		return power >= 2 && power <= 14;
	}

public:
	Card(int power, char color) {
		if (isColorValid(color) && isPowerValid(power)){
			this->color = color;
			this->power = power;
		}
		else {
			throw;
		}
	}

	void display() {
		//TODO
	}

	void displayDebug() {

	}

	short getPower() {
		return this->power;
	}
	char getColor() {
		return this->color;
	}

};