#include "../include/Deck.h"
#include <iostream>
#include <algorithm>
#include <array>
#include <random>

Deck::Deck() {
    std::cout << "Creating deck\n";
    // Tworzenie talii 52 kart
    for (short power : Card::getValidPowers()) {
        for (char color : Card::getValidColors()) {
            Card card = Card(power, color);
            cards.push_back(card);
        }
    }
}

void Deck::shuffle() {
    auto rd = std::random_device{};
    auto rng = std::default_random_engine{ rd() };
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
