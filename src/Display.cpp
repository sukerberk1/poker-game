#include "Display.h"
#include <iostream>
#include <cstdlib>


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
    std::cin.ignore();
}

std::string Display::optionChoiceInterface(std::vector<std::string> options, int& chosenIdx)
{
    std::cout << "[Choose your option by chosing its number and entering 0 to forward]" << std::endl;
    for (int i = 0; i < options.size(); i++) {
        if (i == chosenIdx) {
            std::cout << "->";
        }
        std::cout << "[" << i+1 << "]" << options[i] << std::endl;
    }
    std::string nextChoice;
    int idxInput = 0;
    std::cin >> idxInput;
    if (idxInput < 1 || idxInput > options.size())
        return options[chosenIdx];
    else 

        chosenIdx = idxInput-1; 
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
