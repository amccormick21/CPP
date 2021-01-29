#include "gamecontroller.h"

GameController::GameController()
{
    this->game = new Game();
}

GameController::~GameController()
{

}

void GameController::ResetGame()
{
    this->game->Reset();
}

void GameController::MakeMove(const Move * move)
{
    this->game->MakeMove(move);
}