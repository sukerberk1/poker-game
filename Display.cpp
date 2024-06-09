#include "Display.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <conio.h> //! Linux does not work with that

#define KEY_UP    72
#define KEY_DOWN  80
#define KEY_ENTER 13


void Display::clear()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void Display::awaitAcknowledge()
{
    getchar();
}

std::string Display::optionChoiceInterface(std::vector<std::string> options, int& chosenIdx)
{
    std::cout << "[Choose your option using arrows and enter keys]" << std::endl;
    for (int i = 0; i < options.size(); i++) {
        if (i == chosenIdx) {
            std::cout << "->";
        }
        std::cout << options[i] << std::endl;
    }
    std::string nextChoice;
    switch (_getch())
    {
    case KEY_ENTER:
        return options[chosenIdx];
    case KEY_UP:
        chosenIdx = chosenIdx == 0 ? options.size() - 1 : chosenIdx - 1;
        break;
    case KEY_DOWN:
        chosenIdx = chosenIdx == options.size() - 1 ? 0 : chosenIdx + 1;
        break;
    }
    return "";
}

void Display::showTableCards(std::array<Card, 5> tableCards)
{
    std::cout << "Current Cards on the table: " << std::endl;
    for (Card card : tableCards) {
        if (Card::isPlaceholder(card))
            std::cout << "[CARD UNREVEALED]" << std::endl;
        else
            card.display();
    }
    std::cout << std::endl;
}

void Display::announceBet(Player* player)
{
    clear();
    std::cout << player->getName() <<  " will be betting now...\n";
    awaitAcknowledge();
}

void Display::announceWinner(Player* player, int wonAmount) 
{
    clear();
    std::cout << player->getName() << " is the winner of this round! \nCongrats you won " << wonAmount;
    awaitAcknowledge();
}
