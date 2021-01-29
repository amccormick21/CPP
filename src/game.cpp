#include "game.h"

Game::Game()
{
    this->Reset();
}

Game::~Game()
{
    delete[] this->grid;
}

void Game::MakeMove(const Move* move)
{
    score_t moveScore = score_t(0);

    this->score += moveScore;
}

void Game::Reset()
{
    this->score = score_t(0);
    this->grid = new Grid(Grid::grid_size_t(4));
}