#pragma once

#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

namespace ttt {
	class tttGame;
	class InputExept;
}

class ttt::tttGame
{
public:
	vector<vector<int>> field;
	string player1, player2;
	int current_player;

	tttGame(string p1, string p2);

	string createField();
	void play(int a, int b);
	int getWinner();
	string getCurrentPlayer();
	bool isFinished();
	string getWinnerName(int x);
	
};

class ttt::InputExept : public exception {
	const char* what() const noexcept;
};

