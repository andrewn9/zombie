#include "image.h"
#include "game.h"
#include "dir.hpp"

#define WALK_SPEED  3

class Zombie
{
    public:
        Zombie(int x, int y, int w, int h, Game *game);
        void update();
        int x, y, w, h;
        int targetX, targetY;
        Image* image;
        Game* game;
};

#pragma once

//zomb