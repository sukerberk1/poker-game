// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Player.h"
#include "BettingCycle.h"

int main()
{
    //std::cout << "!!! UWAGA !!!\n";
    //std::cout << "POKER TO GRA HAZARDOWA. GRAJ ODPOWIEDZIALNIE.\n"; 
    //std::cout << "TYLKO OD 18 ROKU ZYCIA.\n\n";
    //std::cout << "CO CHCESZ ZROBIC, GRACZU?\n";
    //std::cout << "[1] - CHCE ZARYZYKOWAC WSZYSTKO, ZEBY ZDOBYC NIESKONCZENIE WIELE PIENIEDZY GRAJAC W GRE POKER.\n[2] - SPENIALEM. ZABIERZCIE MNIE STAD, DOPOKI JESZCZE MAM JAKIES PIENIADZE...";

    Deck d = Deck();
    d.shuffle();

    Player playerOne = Player("Maciek");
    playerOne.addCash(100);
    Player playerTwo = Player("Krzysiek");
    playerTwo.addCash(100);
    std::vector<Player*> players;
    players.push_back(&playerOne);
    players.push_back(&playerTwo);
    BettingCycle cycle = BettingCycle(&players);
    cycle.run();
    std::cout<<"Total amount bet in this cycle: " << cycle.getTotalBetAmount();
    system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
