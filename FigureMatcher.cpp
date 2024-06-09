#include "FigureMatcher.h"
#include "Card.h"
#include <array>

bool FigureMatcher::doesFigureExist(std::array<Card, 7> allCards)
{
    return false;
}

bool FigureMatcher::doesMatch(std::array<Card, 5> tableCards, std::array<Card, 2> playerCards)
{
    int idxCounter = 0;
    std::array<Card, 7> allCards;
    for (Card card : tableCards) {
        allCards[idxCounter++] = card;
    }
    for (Card card : playerCards) {
        allCards[idxCounter++] = card;
    }
    return doesFigureExist(allCards);
}

class PairMatcher : public FigureMatcher {
    bool doesFigureExist(std::array<Card, 7> allCards) {
        // TODO!
        return false;
    }
};

class DoublePairMatcher : public FigureMatcher {
    bool doesFigureExist(std::array<Card, 7> allCards) {
        // TODO!
        return false;
    }
};

class ThreeOfAKindMatcher : public FigureMatcher {
    bool doesFigureExist(std::array<Card, 7> allCards) {
        // TODO!
        return false;
    }
};

class StraightMatcher : public FigureMatcher {
    bool doesFigureExist(std::array<Card, 7> allCards) {
        // TODO!
        return false;
    }
};

class FlushMatcher : public FigureMatcher {
    bool doesFigureExist(std::array<Card, 7> allCards) {
        // TODO!
        return false;
    }
};

class FullHouseMatcher : public FigureMatcher {
    bool doesFigureExist(std::array<Card, 7> allCards) {
        // TODO!
        return false;
    }
};

class FourOfAKindMatcher : public FigureMatcher {
    bool doesFigureExist(std::array<Card, 7> allCards) {
        // TODO!
        return false;
    }
};

class StraightFlushMatcher : public FigureMatcher {
    bool doesFigureExist(std::array<Card, 7> allCards) {
        // TODO!
        return false;
    }
};

class RoyalFlushMatcher : public FigureMatcher {
    bool doesFigureExist(std::array<Card, 7> allCards) {
        // TODO!
        return false;
    }
};


std::vector<FigureMatcher> FigureMatcher::getAllMatchersDescending()
{
    // Matchers ordered from most to least rare
    return std::vector<FigureMatcher> { 
        RoyalFlushMatcher(), 
        StraightFlushMatcher(),
        FourOfAKindMatcher(),
        FullHouseMatcher(),
        FlushMatcher(),
        StraightMatcher(),
        ThreeOfAKindMatcher(),
        DoublePairMatcher(),
        PairMatcher()
    };
}

Player* FigureMatcher::resolveHighCard(std::vector<Player*> players) {
    auto getMaxPlayerPower = [](Player* player) {
        std::array<Card, 2> playerCards = player->getCards();
        return playerCards.at(0).getPower() > playerCards.at(1).getPower() ? 
            playerCards.at(0).getPower() : 
            playerCards.at(1).getPower();
    };

    int maxPower = 0;
    for (Player* player : players) {
        int maxPlayerPower = getMaxPlayerPower(player);
        if (maxPower < maxPlayerPower)
            maxPower = maxPlayerPower;
    }
    for (Player* player : players) {
        if (maxPower == getMaxPlayerPower(player))
            return player;
    }
    std::cout << "Erroneus round resolvement. Winner might not be legitimate." << std::endl;
    return players[0];
}