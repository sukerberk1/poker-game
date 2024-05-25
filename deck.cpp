#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <array>
#include <random>

using namespace std;

Deck::Deck() {
    std::array<char, 4> validColors = Card::getValidColors();
    std::array<short, 13> validPowers = Card::getValidPowers();
    // Tworzenie talii 52 kart
    for (short power : validPowers) {
        for (char color : validColors) {
            Card card = Card(power, color);
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
