#include "../include/stdafx.h"
#include <iostream>
#include "gamecontroller.h"

using namespace std;

int main(int argc, char *argv[])
{

	cout << "2048" << endl << "====" << endl;
	auto game = new GameController();

	game->ResetGame();
    cin.get();
	return 0;
}