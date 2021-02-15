#include "../include/stdafx.h"
#include "game.h"

class GameController {

    public:
        Game* game;

        GameController();
        ~GameController();

        bool MakeMove(const Direction);
        Direction GetMoveInput();
        void ResetGame();
        bool Play();
};