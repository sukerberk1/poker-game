#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <random>       // std::default_random_engine

using namespace std;

Deck::Deck() {
    // Tworzenie talii 52 kart
    for (int power = 2; power <= 14; ++power) {
        for (int colorIndex = 0; colorIndex < 4; ++colorIndex) {
            char color = Card::validColors[colorIndex];
            Card card(power, color);
            cards.push_back(card);
        }
    }
}

void Deck::shuffle() {
    long seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (cards.begin(), cards.end(), std::default_random_engine(seed));
}

Card Deck::drawCard() {
    Card drawnCard = cards.back();
    cards.pop_back();
    return drawnCard;
}

void Deck::display() {
    for (Card card : cards) {
        card.display();
    }
}

int main() {
    Deck deck;
    cout << "Shuffling the deck..." << endl;
    deck.shuffle();

    cout << "Drawing and displaying 5 cards:" << endl;
    for (int i = 0; i < 5; ++i) {
        Card drawnCard = deck.drawCard();
        cout << "Card " << i+1 << ": ";
        drawnCard.displayDebug();
    }

    return 0;
}
