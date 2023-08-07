#include "timingWheel.h"
#include "SimMSGame.h"

TimingWheel::TimingWheel(int md, std::ostream& o) : out(o) {
	size = md + 1;
	slot = new Partition<SimMSGame>[size];
	currentSlot = 0;
}

TimingWheel::~TimingWheel() {
	delete [] slot;
}

void TimingWheel::insert(int playTime, SimMSGame* p1) {
	slot[(currentSlot + playTime - 1) % size].push(p1);
}

int TimingWheel::schedule(MSGameStat& gamestat) {
	int gamesPlayed = 0;
	while (slot[currentSlot].getHead()) {
		slot[currentSlot].getHead()->getContainer()->playNDraw(out);

		if (slot[currentSlot].getHead()->getContainer()->getGameStatus() == MSGame::WIN) gamestat.gamesWonInc();
		else gamestat.gamesLoseInc();

		slot[currentSlot].pop();
		gamesPlayed++;
	}
	currentSlot = (currentSlot + 1) % size;
	return gamesPlayed;
}

void TimingWheel::clearCurrSlot() {
	while (slot[currentSlot].getHead()) {
		slot[currentSlot].pop();
	}
}

