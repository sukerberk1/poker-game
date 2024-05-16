#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

Deck::Deck() {
    std::cout << "Creating deck..." << std::endl;
    char* validColors = Card::getValidColors();
    short* validPowers = Card::getValidPowers();
    // Tworzenie talii 52 kart
    for (int powerIndex = 0; powerIndex < 13; powerIndex++) {
        for (int colorIndex = 0; colorIndex < 4; ++colorIndex) {
            Card newCard = Card(validPowers[powerIndex], validColors[colorIndex]);
            std::cout << "Adding a card to deck: ";
            newCard.displayDebug();
            cards.push_back(newCard);
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
