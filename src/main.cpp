#include "../include/stdafx.h"
#include <iostream>
#include "gamecontroller.h"

using namespace std;


void gameplayLoop()
{
	auto game = new GameController();

	game->ResetGame();
	game->Play();
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

	cin.get();

	return 0;
}