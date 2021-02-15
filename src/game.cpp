#include "game.h"
#include <iostream>

Game::Game()
{
    this->grid = new Grid(Grid::grid_size_t(4));
    this->Reset();
}

Game::~Game()
{
    delete[] this->grid;
}

void Game::MakeMove(const Direction move)
{
    score_t moveScore = score_t(0);
    moveScore = this->grid->MoveGrid(move);
    this->grid->AddValue();
    this->score += moveScore;
}

void Game::Reset()
{
    this->score = score_t(0);
    this->GameOver = false;

    this->grid = new Grid(Grid::grid_size_t(4));
}

void Game::StartNew()
{
    this->grid->Initialise();
}

void Game::Display()
{
    std::cout << endl;
    std::cout << endl;
    std::cout << endl;
    std::cout << "Game grid:" << endl;
    std::cout << "____________________________" << endl;
    std::cout << endl;

    this->grid->DisplayGrid();

    std::cout << "____________________________" << endl;
    std::cout << "Enter Move:" << endl;
}