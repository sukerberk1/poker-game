#include "Display.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>

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
