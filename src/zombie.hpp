#include "image.hpp"
#include "game.hpp"
#include "dir.hpp"

#define ZOM_WALK_SPEED  3

class Zombie
{
    public:
        Zombie(int x, int y, int w, int h);
        void update();
        int x, y, w, h;
        int targetX, targetY;
        Image* image;
};

#pragma once

//zomb
