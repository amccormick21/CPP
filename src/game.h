#include "../include/stdafx.h"
#include "grid.h"

class Game {

    public:
        score_t score;
        Grid * grid;
        bool GameOver;

        Game();
        ~Game();


        void Reset();
        void Display();
        void StartNew();
        void MakeMove(const Direction);
};