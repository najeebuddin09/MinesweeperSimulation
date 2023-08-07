#pragma once

#include "board.h"

class MSGame {
public:
	enum gameType {
		BEGINNER=0,
		INTERMEDIATE,
		EXPERT
	};
private:
	board<char>* vBoard;
	board<int>* hBoard;
	void populateHBoard();
	gameType gType;
public:
	enum gameStatus {
		WIN,
		LOSE,
		RUNNING,
		INVALIDTURN
	};
	MSGame(gameType);
	~MSGame();
	gameStatus playTurn(int x, int y);
	void draw(std::ostream&);
	gameType getGameType();
	int getRows();
	int getCols();
};