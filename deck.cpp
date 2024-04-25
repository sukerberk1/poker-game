#include "Deck.h"
#include <iostream>
#include <algorithm>

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
    std::random_shuffle(cards.begin(), cards.end());
}

Card Deck::drawCard() {
    Card drawnCard = cards.back();
    cards.pop_back();
    return drawnCard;
}

void Deck::display() {
    for (const Card& card : cards) {
        card.displayDebug();
    }
}

int main() {
    Deck deck;
    std::cout << "Shuffling the deck..." << std::endl;
    deck.shuffle();

    std::cout << "Drawing and displaying 5 cards:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        Card drawnCard = deck.drawCard();
        std::cout << "Card " << i+1 << ": ";
        drawnCard.displayDebug();
    }

    return 0;
}
