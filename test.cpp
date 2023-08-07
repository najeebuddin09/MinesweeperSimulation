#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "GenTimingWheel.h"

int main()
{
	using namespace std;

	string userInput;

	vector<pair<int, MSGame::gameType>> prob;
	cout << "Enter probability for beginner:" << endl;
	cin >> userInput;
	prob.push_back({ stoi(userInput), MSGame::BEGINNER });
	cout << "Enter probability for intermediate:" << endl;
	cin >> userInput;
	prob.push_back({ stoi(userInput), MSGame::INTERMEDIATE });
	cout << "Enter probability for expert:" << endl;
	cin >> userInput;
	prob.push_back({ stoi(userInput), MSGame::EXPERT });

	map<MSGame::gameType, int> ll, ul;

	cout << "Enter lower limit for beginner game time delay:" << endl;
	cin >> userInput;
	ll.insert({ MSGame::BEGINNER, stoi(userInput)});
	cout << "Enter upper limit for beginner game time delay:" << endl;
	cin >> userInput;
	ul.insert({ MSGame::BEGINNER, stoi(userInput)});

	cout << "Enter lower limit for intermediate game time delay:" << endl;
	cin >> userInput;
	ll.insert({ MSGame::INTERMEDIATE, stoi(userInput)});
	cout << "Enter upper limit for intermediate game time delay:" << endl;
	cin >> userInput;
	ul.insert({ MSGame::INTERMEDIATE, stoi(userInput)});

	cout << "Enter lower limit for expert game time delay:" << endl;
	cin >> userInput;
	ll.insert({ MSGame::EXPERT, stoi(userInput)});
	cout << "Enter upper limit for expert game time delay:" << endl;
	cin >> userInput;
	ul.insert({ MSGame::EXPERT, stoi(userInput)});

	auto maxul = std::max_element
	(
		std::begin(ul), std::end(ul),
		[](const auto& p1, const auto& p2) {
			return p1.second < p2.second;
		}
	);

	int max_uppper_limit = maxul->second;

	cout << "Enter of games you want to simulate:" << endl;
	cin >> userInput;
	int no_of_games = stoi(userInput);

	cout << "Enter the level of Concurrency:" << endl;
	cin >> userInput;
	int level_of_concurrency = stoi(userInput);
	
	/*
	map<MSGame::gameType, int> ll;
	ll.insert({ MSGame::BEGINNER, 1 });
	ll.insert({ MSGame::INTERMEDIATE, 4 });
	ll.insert({ MSGame::EXPERT, 7 });

	cars["car 1"] = toyota;

	map<MSGame::gameType, int> ul;
	ul.insert({ MSGame::BEGINNER, 3 });
	ul.insert({ MSGame::INTERMEDIATE, 6 });
	ul.insert({ MSGame::EXPERT, 9 });

	vector<pair<int, MSGame::gameType>> prob;
	prob.push_back({ 40, MSGame::BEGINNER });
	prob.push_back({ 30, MSGame::INTERMEDIATE });
	prob.push_back({ 30, MSGame::EXPERT });
	*/

	try {

		//GenTimingWheel gtw(9, 3, 10, ul, ll, prob, cout);
		GenTimingWheel gtw(max_uppper_limit, level_of_concurrency, no_of_games, 
			ul, ll, prob, cout);
		gtw.run();
	}
	catch (const char * e) {
		cout << e << endl;
	}

	//cin >> userInput;

	return 0;
}
