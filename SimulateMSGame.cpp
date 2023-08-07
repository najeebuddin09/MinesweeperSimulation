#include "SimulateMSGame.h"
#include "MSGameStat.h"
#include "board.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <time.h>

SimulateMSGame::SimulateMSGame(std::string infileName, std::ostream& os) : out(os) {
	using namespace std;

	ifstream infile(infileName);

	if (!infile) {
		throw "failed to open file!";
	}

	string fread;
	int bgameProb = 0;
	int igameProb = 0;
	int egameProb = 0;

	infile >> fread;
	noOfGameRuns = atoi(fread.c_str());
	infile >> fread;
	bgameProb = atof(fread.c_str()) * 100;
	infile >> fread;
	igameProb = atof(fread.c_str()) * 100;
	infile >> fread;
	egameProb = atof(fread.c_str()) * 100;

	boardProb.push_back(make_pair(bgameProb, MSGame::BEGINNER));
	boardProb.push_back(make_pair(igameProb, MSGame::INTERMEDIATE));
	boardProb.push_back(make_pair(egameProb, MSGame::EXPERT));

	sort(boardProb.begin(), boardProb.end()); // make boardProb in ascending order

	srand(time(0));
}

SimulateMSGame::SimulateMSGame(int ngame, float pbgame, float pigame, float pegame, std::ostream& os) : out(os) {
	using namespace std;
	noOfGameRuns = ngame;

	boardProb.push_back(make_pair(pbgame * 100, MSGame::BEGINNER));
	boardProb.push_back(make_pair(pigame * 100, MSGame::INTERMEDIATE));
	boardProb.push_back(make_pair(pegame * 100, MSGame::EXPERT));

	sort(boardProb.begin(), boardProb.end()); // make boardProb in ascending order
	
	srand(time(0));
}

MSGame::gameStatus SimulateMSGame::play(MSGame& g, MSGame::gameType t) {
	MSGame::gameStatus R;
	int numOfTurns = 0;
	int x = 0;
	int y = 0;
	do {
		switch (t) {
		case MSGame::BEGINNER:
			x = rand() % bBoard<int>::boardDimentions::bdCOLS;
			y = rand() % bBoard<int>::boardDimentions::bdROWS;
			break;
		case MSGame::INTERMEDIATE:
			x = rand() % iBoard<int>::boardDimentions::bdCOLS;
			y = rand() % iBoard<int>::boardDimentions::bdROWS;
			break;
		case MSGame::EXPERT:
			x = rand() % eBoard<int>::boardDimentions::bdCOLS;
			y = rand() % eBoard<int>::boardDimentions::bdROWS;
			break;
		}
		R = g.playTurn(x, y);
		numOfTurns++;
	} while (numOfTurns < 10000 && (R == MSGame::RUNNING || R == MSGame::INVALIDTURN));
	return R;
}

void SimulateMSGame::Play() {
	using namespace std;

	MSGameStat stat;

	for (int i = 0; i < noOfGameRuns; i++) {
		int ran = rand() % 100;
		int fromT = 0;
		out << "Game: " << i <<  "\n\n";
		for_each(boardProb.begin(), boardProb.end(), [this, &stat, &fromT, ran](auto prob) {
			if (ran >= fromT && ran < fromT+prob.first) {
				MSGame g(prob.second);
				if (this->play(g, prob.second) == MSGame::WIN) stat.gamesWonInc();
				else stat.gamesLoseInc();
				stat.gameplayedInc(prob.second);
				g.draw(out);
			}		
			fromT += prob.first;
		});
		out << endl;
	}

	out << "Games Played: " << stat.getgamePlayed() << endl;
	out << "Beginner Games Played: " << stat.getbGamePlayed() << endl;
	out << "Intermediate Games Played: " << stat.getiGamePlayed() << endl;
	out << "Expert Games Played: " << stat.geteGamePlayed() << endl;
	out << "Games Won: " << stat.getgameWon() << endl;
	out << "Games Lose: " << stat.getgameLose() << endl;
}
