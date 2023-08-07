#pragma once

#include <iostream>
#include "game.h"

class SimMSGame {
	MSGame* game;
	MSGame::gameStatus gS;
	int noOfTurns;
	const int maxTurns = 10000;
	int ID;
public:
	SimMSGame(MSGame*, int id = 0);
	void play();
	void draw(std::ostream& out);
	void playNDraw(std::ostream& out);
	int getTurnsPlayed();
	int getID();
	int getGameStatus();
};

