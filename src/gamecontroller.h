#include "../include/stdafx.h"
#include "game.h"

class GameController {

    public:
        Game* game;

        GameController();
        ~GameController();

        bool MakeMove(const Move *);
        Move GetMoveInput();
        void ResetGame();
        bool Play();
};