#include "image.h"
#include "game.h"
#include "dir.hpp"

#define WALK_SPEED  8

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