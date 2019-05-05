#include "tttGame.h"

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
using namespace ttt;


tttGame::tttGame(string p1, string p2)
{
	current_player = 1;
	player1 = p1;
	player2 = p2;

	field = {
	{0, 0, 0},
	{0, 0, 0},
	{0, 0, 0}
	};
}

string tttGame::createField() {
    stringstream f;

	for (const auto &row : field) {
		f << "| ";
		for (const auto &item : row) {
			f << item << " | ";
		}
		f << endl;
	}

	return f.str();
}

void tttGame::play(int a, int b) {
	if (a < 0 || a >= field.size()) {
		cout << "Fehlerhafte Eingabe, bitte nur Kombination von Zahlen zwischen 0 und 2 eingeben." << endl;
		return;
	}
	else if (b < 0 || b >= field[a].size()) {
		cout << "Fehlerhafte Eingabe, bitte nur Kombination von Zahlen zwischen 0 und 2 eingeben." << endl;
		return;
	}
	else if (field[a][b] != 0) {
		cout << "Fehlerhafte Eingabe, Feld ist bereits bespielt." << endl;
		return;
	}


	if (current_player == 1) {
		field[a][b] = 1;
		current_player = 2;
	}
	else {
		field[a][b] = 2;
		current_player = 1;
	}
}


int tttGame::getWinner() {

	if (field[0][0] != 0 && field[0][0] == field[1][1] && field[0][0] == field[2][2]) {


		return field[0][0];

	} else if (field[0][2] != 0 && field[0][2] == field[1][1] && field[0][2] == field[2][0]) {

		
		return field[0][2];

	}

	for (int i = 0; i < field.size(); i++) {
		if (field[i][0] != 0 && field[i][0] == field[i][1] && field[i][0] == field[i][2]) {
			
			return field[i][0];
		}
	}

	for (int i = 0; i < field[0].size(); i++) {
		if (field[0][i] != 0 && field[0][i] == field[1][i] && field[0][i] == field[2][i]) {

			return field[0][i];
		}
	}

		return 0;
}


string tttGame::getCurrentPlayer() {

	if (current_player == 1) {
		return player1;
	}
	else {
		return player2;
	}
}

string tttGame::getWinnerName(int x) {

	if (x == 1) {
		return player1;
	}
	else if (x == 2) {
		return player2;
	}
	else {
		return "Niemand, es gibt ein Unentschieden";
	}
}

bool tttGame::isFinished() {
	if (getWinner() != 0) {
		return true;
	}

	for (const auto& row : field) {
		for (const auto& item : row) {
			if (item == 0) {
				return false;
			}
		}
	}

	return true;
}

const char* InputExept::what() const noexcept {
	return "Fehlerhafte Eingabe, bitte nur Ganzzahlen eingeben.";
}