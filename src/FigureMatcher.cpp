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
/*Checks for pairs*/
class PairMatcher : public FigureMatcher {
    bool doesFigureExist(std::array<Card, 7> allCards) {
        int counts[15] = { 0 };
        for (auto card : allCards) {
            counts[card.getPower()]++;
        }
        for (int i = 0; i < 15; i++) {
            if (counts[i] == 2) return true;
        }
        return false;
    }
};
/*Checks for double pairs*/
class DoublePairMatcher : public FigureMatcher {
    bool doesFigureExist(std::array<Card, 7> allCards) {
        int counts[15] = { 0 };
        int pairCount = 0;
        for (auto card : allCards) {
            counts[card.getPower()]++;
        }
        for (int i = 0; i < 15; i++) {
            if (counts[i] == 2) pairCount++;
        }
        return pairCount >= 2;
    }
};
/*Checks for three of a kind*/
class ThreeOfAKindMatcher : public FigureMatcher {
    bool doesFigureExist(std::array<Card, 7> allCards) {
        int counts[15] = { 0 };
        for (auto card : allCards) {
            counts[card.getPower()]++;
        }
        for (int i = 0; i < 15; i++) {
            if (counts[i] == 3) return true;
        }
        return false;
    }
};
/*Checks for a straight*/
class StraightMatcher : public FigureMatcher {
    bool doesFigureExist(std::array<Card, 7> allCards) {
        bool cardPresent[15] = { false };
        for (auto card : allCards) {
            cardPresent[card.getPower()] = true;
        }
        int consecutive = 0;
        for (int i = 2; i <= 14; i++) {
            if (cardPresent[i]) {
                consecutive++;
                if (consecutive == 5) return true;
            }
            else {
                consecutive = 0;
            }
        }
        return false;
    }
};
/*Checks for a flush*/
class FlushMatcher : public FigureMatcher {
    bool doesFigureExist(std::array<Card, 7> allCards) {
        int counts[4] = { 0 };
        for (auto card : allCards) {
            switch (card.getColor()) {
            case 'S': counts[0]++; break;
            case 'H': counts[1]++; break;
            case 'D': counts[2]++; break;
            case 'C': counts[3]++; break;
            }
        }
        for (int i = 0; i < 4; i++) {
            if (counts[i] >= 5) return true;
        }
        return false;
    }
};
/*Checks for a full house*/
class FullHouseMatcher : public FigureMatcher {
    bool doesFigureExist(std::array<Card, 7> allCards) {
        int counts[15] = { 0 };
        bool hasThree = false, hasTwo = false;
        for (auto card : allCards) {
            counts[card.getPower()]++;
        }
        for (int i = 0; i < 15; i++) {
            if (counts[i] == 3) hasThree = true;
            if (counts[i] == 2) hasTwo = true;
        }
        return hasThree && hasTwo;
    }
};
/*Checks for a four of a kind*/
class FourOfAKindMatcher : public FigureMatcher {
    bool doesFigureExist(std::array<Card, 7> allCards) {
        int counts[15] = { 0 };
        for (auto card : allCards) {
            counts[card.getPower()]++;
        }
        for (int i = 0; i < 15; i++) {
            if (counts[i] == 4) return true;
        }
        return false;
    }
};
/*Checks for a staight flush*/
class StraightFlushMatcher : public FigureMatcher {
    bool doesFigureExist(std::array<Card, 7> allCards) {
        bool suits[4][15] = { {false} };
        for (auto card : allCards) {
            switch (card.getColor()) {
            case 'S': suits[0][card.getPower()] = true; break;
            case 'H': suits[1][card.getPower()] = true; break;
            case 'D': suits[2][card.getPower()] = true; break;
            case 'C': suits[3][card.getPower()] = true; break;
            }
        }
        for (int s = 0; s < 4; s++) {
            int consecutive = 0;
            for (int i = 2; i <= 14; i++) {
                if (suits[s][i]) {
                    consecutive++;
                    if (consecutive == 5) return true;
                }
                else {
                    consecutive = 0;
                }
            }
        }
        return false;
    }
};
/*Checks for a royal flush*/
class RoyalFlushMatcher : public FigureMatcher {
    bool doesFigureExist(std::array<Card, 7> allCards) {
        bool suits[4][15] = { {false} };
        for (auto card : allCards) {
            switch (card.getColor()) {
            case 'S': suits[0][card.getPower()] = true; break;
            case 'H': suits[1][card.getPower()] = true; break;
            case 'D': suits[2][card.getPower()] = true; break;
            case 'C': suits[3][card.getPower()] = true; break;
            }
        }
        for (int s = 0; s < 4; s++) {
            if (suits[s][10] && suits[s][11] && suits[s][12] && suits[s][13] && suits[s][14]) {
                return true;
            }
        }
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
