#include "../include/stdafx.h"
#include "game.h"

class GameController {

    public:
        Game* game;

        GameController();
        ~GameController();

        void MakeMove(const Move *);
        void ResetGame();
};