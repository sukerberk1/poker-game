#pragma once
#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>


class Deck {
private:
    std::vector<Card> cards;
    
public:
    Deck();

    void shuffle();
    Card drawCard();
    void display();
    void displayDebug();
};

#endif // DECK_H
