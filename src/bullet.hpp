#include "image.hpp"
#include "game.hpp"
#include "dir.hpp"
#include "gun.hpp"

class Bullet
{
    public:
        Bullet(Gun *gun, Game *game);
        void update();
        Gun* gun;
        int xspeed, yspeed;
        int x, y, w, h;
        Image* image;
        Game* game;
};

#pragma once

//zomb
