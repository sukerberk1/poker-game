#pragma once
#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck {
private:
    std::vector<Card> cards;

public:
    Deck();

    void shuffle();
    Card drawCard();
    void display();
};

#endif // DECK_H