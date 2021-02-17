#include "../include/stdafx.h"
#include <iostream>
#include "gamecontroller.h"

using namespace std;


void gameplayLoop()
{
	bool playAgain{true};
	auto game = new GameController();
	cin.clear();

	while (playAgain)
	{
		game->ResetGame();
		game->Play();

		cout << "PLAY AGAIN? (Y/N)" << endl;
		char selection;
		cin >> selection;

		playAgain = (selection == 'y') || (selection == 'Y');
	}
}

int main(int argc, char *argv[])
{

	cout << "2048" << endl << "====" << endl << endl;

	cout << "MENU" << endl;
	cout << "____" << endl;
	cout << "1. Play Game" << endl;
	cout << "2. View Highscores" << endl;
	cout << "3. Settings" << endl;

    int selection;
	cin >> selection;

	switch (selection)
	{
		case 1:
			gameplayLoop();
			break;
		default:
			cout << "Invalid Selection" << endl;
	}

	return 0;
}