// Diese Datei enthält die Funktion "main"
//

#include <iostream>
#include <string>
#include <stdexcept>
#include "tttGame.h"

using namespace std;
using namespace ttt;

int main()
{
	try {

		string name1, name2;

		cout << "Bitte ersten Spielernamen eingeben: ";
		cin >> name1;
		cout << "Bitte zweiten Spielernamen eingeben: ";
		cin >> name2;

		cout << "Das Spiel beginnt: " << name1 << " gegen " << name2 << "!\n";

		tttGame game(name1, name2);

		while (!game.isFinished()) {
			cout << game.createField() << endl;
			int a, b;
			cout << "Spieler " << game.getCurrentPlayer() << " is dran: ";
			cin >> a >> b;
			if (cin.fail()) {
				throw InputExept();
			}
			
			cin.ignore(std::cin.rdbuf()->in_avail());
			game.play(a, b);

		}

		cout << "Der Gewinner ist: " << game.getWinnerName(game.getWinner());
	}
	catch (exception &e) {
		cout << e.what() << endl;
	}
}

