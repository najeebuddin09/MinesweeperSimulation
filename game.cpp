#include <time.h>
#include <cstdlib>
#include "game.h"
#include "board.h"

MSGame::MSGame(gameType gT) {
	gType = gT;
	switch (gType) {
	case INTERMEDIATE:
		hBoard = new iBoard<int>();
		vBoard = new iBoard<char>();
		break;
	case EXPERT:
		hBoard = new eBoard<int>();
		vBoard = new eBoard<char>();
		break;
	default:
		hBoard = new bBoard<int>();
		vBoard = new bBoard<char>();
		break;
	}
	populateHBoard();
}

MSGame::~MSGame() {
	delete hBoard;
	delete vBoard;
}

void MSGame::populateHBoard() {
	int n = 0;
	int x, y;
	//srand(time(0));
	for (int i = 0; i < hBoard->getNoMines(); i++) {
		x = rand() % hBoard->getNoRows();
		y = rand() % hBoard->getNoCols();
		if (hBoard->get(x, y) == 33) i--;	// already mine here, repeat
		else hBoard->set(x, y, 33);
	}
	for (int i = 0; i < hBoard->getNoRows(); i++) {
		for (int k = 0; k < hBoard->getNoCols(); k++) {
			if (hBoard->get(i, k) == 33) continue;
			if (hBoard->get(i + 1, k) == 33 /*mine*/) n++; // up
			if (hBoard->get(i - 1, k) == 33 /*mine*/) n++; // down
			if (hBoard->get(i, k + 1) == 33 /*mine*/) n++; // right
			if (hBoard->get(i, k - 1) == 33 /*mine*/) n++; // left
			if (hBoard->get(i + 1, k + 1) == 33 /*mine*/) n++; // up right
			if (hBoard->get(i - 1, k + 1) == 33 /*mine*/) n++; // donw right
			if (hBoard->get(i + 1, k - 1) == 33 /*mine*/) n++; // up left
			if (hBoard->get(i - 1, k - 1) == 33 /*mine*/) n++; // donw left
			hBoard->set(i, k, n);
			n = 0;
		}
	}
}

MSGame::gameStatus MSGame::playTurn(int x, int y) {
	if (x > vBoard->getNoRows()) return INVALIDTURN;
	if (y > vBoard->getNoCols()) return INVALIDTURN;

	if (hBoard->get(x, y) == 33) {
		vBoard->set(x, y, 'X');
		return LOSE;
	}
	if (hBoard->get(x, y) > 0) {
		vBoard->set(x, y, hBoard->get(x, y) | 48);

		//count closed boxes
		int closedBoxes = 0;
		for (int i = 0; i < vBoard->getNoRows(); i++) {
			for (int k = 0; k < vBoard->getNoCols(); k++) {
				if (vBoard->get(i, k) == 'B') closedBoxes;
			}
		}
		if (closedBoxes == vBoard->getNoMines()) return WIN;

		return RUNNING;
	}
	if (hBoard->get(x, y) == 0) {
		// for now i am just opening the current box
		vBoard->set(x, y, hBoard->get(x, y) | 48);
		return RUNNING;
	}
	return RUNNING;
}

void MSGame::draw(std::ostream& out) {
	vBoard->draw(out);
}

MSGame::gameType MSGame::getGameType() {
	return gType;
}

int MSGame::getRows() {
	return vBoard->getNoRows();
}

int MSGame::getCols() {
	return vBoard->getNoCols();
}

