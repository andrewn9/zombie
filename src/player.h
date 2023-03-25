#include "image.h"
#include "game.h"

class Player
{
    public:
        Player(int x, int y, int w, int h, Game *game);
        void update();
        int x, y, w, h;
        Image* image;
        Game* game;
};

#pragma once