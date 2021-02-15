#include "gamecontroller.h"
#include <stdio.h>
#include <iostream>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

GameController::GameController()
{
    this->game = new Game();

    // Todo: highscores
}

GameController::~GameController()
{

}

void GameController::ResetGame()
{
    this->game->Reset();
}

Direction GameController::GetMoveInput()
{
    bool moveInput(false);
    int keyPress;
    Direction direction;

    while (!moveInput)
    {
        keyPress = getch();
        switch (keyPress)
        {
            case KEY_UP:
                direction = Direction::up;
                moveInput = true;
                std::cout << "Moved: up" << endl;
                break;
            case KEY_DOWN:
                direction = Direction::down;
                moveInput = true;
                std::cout << "Moved: down" << endl;
                break;
            case KEY_LEFT:
                direction = Direction::left;
                moveInput = true;
                std::cout << "Moved: left" << endl;
                break;
            case KEY_RIGHT:
                direction = Direction::right;
                moveInput = true;
                std::cout << "Moved: right" << endl;
                break;
        }
    }

    return direction;
}

bool GameController::MakeMove(const Direction move)
{
    this->game->MakeMove(move);
    return this->game->GameOver;
}

bool GameController::Play()
{
    bool gameOver(false);
    this->game->StartNew();
    Direction direction;

    while (!gameOver)
    {
        this->game->Display();
        direction = GetMoveInput();

        gameOver = MakeMove(direction);
    }
    
    return gameOver;
}