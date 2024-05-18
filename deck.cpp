#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

Deck::Deck() {
    char* validColors = Card::getValidColors();
    short* validPowers = Card::getValidPowers();
    // Tworzenie talii 52 kart
    for (int powerIndex = 0; powerIndex < 13; powerIndex++) {
        for (int colorIndex = 0; colorIndex < 4; ++colorIndex) {
            Card card = Card(validPowers[powerIndex], validColors[colorIndex]);
            cards.push_back(card);
        }
    }
}

void Deck::shuffle() {
    auto rng = std::default_random_engine{};
    std::shuffle(std::begin(cards), std::end(cards), rng);
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

void Deck::displayDebug() {
    for (Card card : cards) {
        card.displayDebug();
    }
}
