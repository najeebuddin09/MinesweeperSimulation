#pragma once

#include "partition.h"
#include "SimMSGame.h"
#include "MSGameStat.h"

class TimingWheel {
	Partition<SimMSGame>* slot;
	std::ostream& out;
	int size;
	int currentSlot;
public:
	TimingWheel(int md, std::ostream& o = std::cout);
	~TimingWheel();
	void insert(int play_time, SimMSGame* p1);
	int schedule(MSGameStat&);
	void clearCurrSlot();
};

