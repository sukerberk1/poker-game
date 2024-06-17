#pragma once
#ifndef GAME_H
#include "Player.h"

class Game
{
private:
	int initialCash;
	Player* playersArr;
	short playersCount;
	std::vector<Player*> playersToVec();

	void endGameNoPlayers();
	void endGameOnePlayer();
public:
	/* 
	Note that design is anemic - game is defined as not valid, it becomes valid as the players are defined. The decision
	is motivated by game save feature implementation later on.
	*/
	Game(int initialCash);
	/* Defines players in the new game */
	void definePlayers();
	void run();
};

#endif // !GAME_H