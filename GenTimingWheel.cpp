#include "GenTimingWheel.h"
#include <cstdlib>
#include <time.h>

GenTimingWheel::GenTimingWheel(int md, int cl, int games, std::map<MSGame::gameType, int> ul, std::map<MSGame::gameType, int> ll, std::vector<std::pair<int, 
	MSGame::gameType>> prob, std::ostream& o) : 
	out(o), upperLimit(ul), lowerLimit(ll), probabilities(prob), maxDelay(md),
	levelOfConcurrency(cl), noOfGames(games)
{

	if (ul.size() != prob.size())
		throw "Upper Limit values should be same as number of Probabilities";

	if (ll.size() != prob.size())
		throw "Lower Limit values should be same as number of Probabilities";
	
	tw = new TimingWheel(maxDelay, o);
	stat = new MSGameStat;

	srand(time(0));
}

GenTimingWheel::~GenTimingWheel() {
	delete tw;
	delete stat;
}

int GenTimingWheel::genRand(int max, int min) {
	//return ((valueToScale - min) / (max - min));
	return min + (rand() % (max - min + 1));
}

void GenTimingWheel::add() {
	using namespace std;
	int ran = rand() % 100;
	int fromT = 0;
	for_each(probabilities.begin(), probabilities.end(), [this, &fromT, ran](auto prob) {
		if (ran >= fromT && ran < fromT+prob.first) {
			int delay = genRand(upperLimit[prob.second], lowerLimit[prob.second]);
			this->tw->insert(delay, new SimMSGame(new MSGame(prob.second), this->IDs++));

			out << "Game with ID " << this->IDs - 1 << " " << " with Delay " << delay << " Inserted" << endl << endl;
			/*
			if (this->play(g, prob.second) == MSGame::WIN) this->stat->gamesWonInc();
			else this->stat->gamesLoseInc();
			*/
			this->stat->gameplayedInc(prob.second);
			this->stat->totalDelaysInc(delay);
			//g.draw(out);
		}		
		fromT += prob.first;
	});
}

void GenTimingWheel::run() {
	using namespace std;

	int noOfSchedule = 0;

	for (int i = 0; i < levelOfConcurrency; i++) {
		add();
	}

	int R = 0;

	for (int i = 0; i < noOfGames-levelOfConcurrency;) {
		out << "====================================" << endl;
		out << "		No of Schedule " << noOfSchedule++ << endl;
		out << "====================================" << endl;
		R = tw->schedule(*stat);
		for (int k = 0; k < R; k++) {
			add();
		}
		i += R;
	}

	for (int i = 0; i < maxDelay+1; i++) {
		out << "====================================" << endl;
		out << "		No of Schedule " << noOfSchedule++ << endl;
		out << "====================================" << endl;
		tw->schedule(*stat);
	}

	out << "Games Played: " << stat->getgamePlayed() << endl;
	out << "Beginner Games Played: " << stat->getbGamePlayed() << endl;
	out << "Intermediate Games Played: " << stat->getiGamePlayed() << endl;
	out << "Expert Games Played: " << stat->geteGamePlayed() << endl;
	out << "Games Won: " << stat->getgameWon() << endl;
	out << "Games Lose: " << stat->getgameLose() << endl;
	out << "Avg Game Time: " << stat->getTotalDelays()/stat->getgamePlayed() << endl;
	out << "Avg Game Win: " << (stat->getgameWon()/stat->getgamePlayed())*100 << endl;
	out << "Avg Game Lose: " << (stat->getgameLose()/stat->getgamePlayed())*100 << endl;
}
