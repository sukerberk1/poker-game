#pragma once
#ifndef DISPLAY_H
#define DISPLAY_H
#include <vector>
#include <string>

/* This class is a result of a spaghetti design */
class Display
{
public:
	static void clear();
	/* Provides choice menu. Returns chosen option if choise occured, empty string otherwise */
	static std::string optionChoiceInterface(std::vector<std::string> options, int& chosenIdx);
};

#endif // !DISPLAY_H