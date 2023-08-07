#include "SimMSGame.h"

SimMSGame::SimMSGame(MSGame* g, int id) : 
	game(g), noOfTurns(0), gS(MSGame::RUNNING), ID(id) {}

void SimMSGame::play() {
	MSGame::gameStatus R;
	int x = 0;
	int y = 0;
	int maxTurns = game->getCols() * game->getRows();
	do {
		x = rand() % game->getCols();
		y = rand() % game->getRows();
		R = game->playTurn(x, y);
		noOfTurns++;
	} while (noOfTurns < maxTurns && (R == MSGame::RUNNING || R == MSGame::INVALIDTURN));
	if (R == MSGame::RUNNING)
		gS = MSGame::LOSE;
	gS = R;
}

int SimMSGame::getTurnsPlayed() {
	return noOfTurns;
}

int SimMSGame::getID() {
	return ID;
}

int SimMSGame::getGameStatus() {
	return gS;
}

void SimMSGame::draw(std::ostream& out) {
	game->draw(out);
}

void SimMSGame::playNDraw(std::ostream& out) {
	using namespace std;
	out << "Sim ID: " << ID << endl << endl;
	play();
	game->draw(out);
	cout << endl;
	gS == MSGame::WIN ? cout << "WON" : cout << "LOSE";
	cout << endl << "Number of Turns: " << noOfTurns << endl << endl;
}

