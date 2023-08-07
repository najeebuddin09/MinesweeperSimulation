#pragma once

#include "game.h"

class MSGameStat {
	int gamePlayed = 0;
	int bGamePlayed = 0;
	int iGamePlayed = 0;
	int eGamePlayed = 0;
	int gGamePlayed = 0;
	int totalDelays = 0;
	int gameWon = 0;
	int gameLose = 0;
public:
	void gameplayedInc(MSGame::gameType);
	void gamesWonInc();
	void gamesLoseInc();
	void totalDelaysInc(int d);
	int getgamePlayed();
	int getbGamePlayed();
	int getiGamePlayed();
	int geteGamePlayed();
	int getgGamePlayed();
	int getgameWon();
	int getgameLose();
	int getTotalDelays();
};

