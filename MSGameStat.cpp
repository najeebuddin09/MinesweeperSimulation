#include "MSGameStat.h"
#include "game.h"

void MSGameStat::gameplayedInc(MSGame::gameType T) {
	gamePlayed++; 
	switch (T) {
	case MSGame::BEGINNER:
		bGamePlayed++;
		break;
	case MSGame::EXPERT:
		eGamePlayed++;
		break;
	case MSGame::INTERMEDIATE:
		iGamePlayed++;
		break;
	}
}

int MSGameStat::getTotalDelays() { return totalDelays; }
void MSGameStat::totalDelaysInc(int d) { totalDelays += d; }
void MSGameStat::gamesWonInc(){gameWon++; }
void MSGameStat::gamesLoseInc(){gameLose++; }
int MSGameStat::getgamePlayed() { return gamePlayed; }
int MSGameStat::getbGamePlayed() { return bGamePlayed; }
int MSGameStat::getiGamePlayed() { return iGamePlayed; }
int MSGameStat::geteGamePlayed() { return eGamePlayed; }
int MSGameStat::getgGamePlayed() { return gGamePlayed; }
int MSGameStat::getgameWon() { return gameWon; }
int MSGameStat::getgameLose() { return gameLose; }
