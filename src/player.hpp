#include "image.hpp"
#include "dir.hpp"

#define PLAYER_WALK_SPEED  8

class Player
{
    public:
        Player(int x, int y, int w, int h);
        void update();
        int x, y, w, h;
        Image* image;
};

#pragma once
