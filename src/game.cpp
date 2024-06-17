#include "Game.h"
#include <iostream>
#include <string>
#include "Round.h"
#include "Display.h"

Game::Game(int initialCash) : 
	playersArr(nullptr), 
	playersCount(0),
	initialCash(initialCash)
{ }


std::vector<Player*> Game::playersToVec()
{
	std::vector<Player*> playersVec;
	for (int i = 0; i < playersCount; i++) {
		playersVec.push_back(&(i[playersArr])); // magiczna sztuczka
	}
	return playersVec;
}

void Game::endGameNoPlayers()
{
	std::cout << "No players in the game! No game then.";
}

void Game::endGameOnePlayer()
{
	std::cout << "You can't play poker solo!";
}

void Game::definePlayers() {
	std::cout << "How many players will play POKER? ";
	std::cin >> playersCount;
	playersArr = new Player[playersCount];
	for (int i = 0; i < playersCount; i++) {
		std::cout << "Player " << i + 1 << " - choose your name: ";
		std::string playerName;
		std::getline(std::cin >> std::ws, playerName);
		playersArr[i] = Player(playerName);
		playersArr[i].addCash(initialCash);
		std::cout << std::endl;
	}
}

void Game::run()
{
	if (playersCount == 0) {
		return endGameNoPlayers();
	}
	if (playersCount == 1) {
		return endGameOnePlayer();
	}
	while (true) {
		Round round = Round(playersToVec());
		round.run();
	}
}
