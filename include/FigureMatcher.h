#pragma 
#ifndef FIGURE_MATCHER_H
#include <vector>
#include "Player.h"

class FigureMatcher
{
protected:
	virtual bool doesFigureExist(std::array<Card, 7> allCards);
public:
	/* Returns points amount if the figure matches, 0 otherwise */
	bool doesMatch(std::array<Card, 5> tableCards, std::array<Card, 2> playerCards);
	static std::vector<FigureMatcher> getAllMatchersDescending();
	static Player* resolveHighCard(std::vector<Player*> players);
};

#endif // !FIGURE_MATCHER_H

