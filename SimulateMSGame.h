#pragma once

#include <iostream>
#include <vector>
#include "game.h" 

class SimulateMSGame {
	std::ostream& out;
	std::vector<std::pair<int, MSGame::gameType>> boardProb;
	int noOfGameRuns;
	MSGame::gameStatus play(MSGame& g, MSGame::gameType);
public:
	SimulateMSGame(std::string infileName, std::ostream& os = std::cout);
	SimulateMSGame(int ngame = 1, float pbgame = 1, float pigame = 0, float pegame = 0, std::ostream& os = std::cout);
	void Play();
};

