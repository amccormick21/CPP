#include "../include/stdafx.h"
#include "grid.h"
#include <map>

class Game {

    public:
        score_t score;
        Grid * grid;
        bool GameOver;
        std::map<Direction, bool> ValidMove;

        Game();
        ~Game();


        void Reset();
        void Display();
        void StartNew();
        bool CheckValidMove();
        bool MakeMove(const Direction);
};