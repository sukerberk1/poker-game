#pragma once
#ifndef BETTING_CYCLE_H
#include <vector>
#include "Player.h"

enum PlayerAction {
    FOLD,
    CALL,
    RAISE
};

class Bet {
private:
    Player* player;
    unsigned int bet;
    bool folded;
public:
    Bet(Player* player);
    bool isFolded();
    void fold();
    unsigned int getAmount();
    void askPlayerForBet(unsigned int minAmount);
};


/*
Betting cycle is defined as a turn of betting that takes place between each card reveal.
*/
class BettingCycle
{
private:
    std::vector<Player*>* roundPlayers;
    /* playerBets is initialized to contain active (unfolded) bets with bet amount equal to 0 */
    std::vector<Bet> playerBets;
    int turn;

   
    bool areBetsEstablished();
    int getCurrentBet() const;
    int getPreviousBet() const;
    void setCurrentBet(int bet);
    void setPreviousBet(int bet);
    int askPlayerForBet(Player& player);
    /* Removes folded players from the roundPlayers. Affects round's state */
    void removeFoldedPlayersFromRound(std::vector<Player>& players);
    bool areBetsEqual(const std::vector<Player>& players);

    
public:
    BettingCycle(std::vector<Player*>* roundPlayers);
    void run(std::vector<Player>& players);
    unsigned int getTotalBetAmount();
    int currentBet = 0;
    int previousBet = 0;
};

#endif // !BETTING_CYCLE_H
