#pragma once

#include "timingWheel.h"
#include "MSGameStat.h"
#include <vector>
#include <map>
#include <algorithm>

class GenTimingWheel {
	std::ostream& out;
	TimingWheel* tw;
	MSGameStat* stat;
	int maxDelay;
	int levelOfConcurrency;
	int noOfGames;
	std::vector<std::pair<int, MSGame::gameType>> probabilities;
	int IDs = 0;
	std::map<MSGame::gameType, int> upperLimit;
	std::map<MSGame::gameType, int> lowerLimit;
	int genRand(int max, int min);
	void add();
public:
	GenTimingWheel(int md, int cl, int games, std::map<MSGame::gameType, int>, std::map<MSGame::gameType, int>, 
		std::vector<std::pair<int, MSGame::gameType>>, std::ostream& o = std::cout);
	~GenTimingWheel();
	void run();
};