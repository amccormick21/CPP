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

void Game::CheckValidMove()
{
    // TODO: array looping properly
    for (const auto dir = { Direction::left, Direction::up, Direction::right, Direction::down }; )
    {
        this->ValidMove[dir] = this->grid->CheckValidMove(dir);
    }
}

void Game::MakeMove(const Direction move)
{
    bool validMove = this->ValidMove[move];
    if (validMove)
    {
        score_t moveScore = score_t(0);
        moveScore = this->grid->MoveGrid(move);
        this->grid->AddValue();
        this->score += moveScore;
        CheckValidMove();
    }
    return validMove;
}

void Game::Reset()
{
    this->score = score_t(0);
    this->GameOver = false;

    this->grid = new Grid(Grid::grid_size_t(4));
    this->ValidMove = {{ Direction::left, true }, {Direction::up, true }, {Direction::right, true }, {Direction::down, true }};
}

void Game::StartNew()
{
    this->grid->Initialise();
    CheckValidMove();
}

void Game::Display()
{
    std::cout << endl;
    std::cout << endl;
    std::cout << endl;
    std::cout << "Game grid:" << endl;
    std::cout << "____________________________" << endl;
    std::cout << endl;

    this->grid->DisplayGrid(this->score);

    std::cout << "____________________________" << endl;
    std::cout << "Enter Move:" << endl;
}