#include "../include/stdafx.h"
#include "score.cpp"
#include "grid.h"

class Game {

    public:
        score_t score;
        Grid * grid;

        Game();
        ~Game();


        void Reset();
        void MakeMove(const Move *);
};