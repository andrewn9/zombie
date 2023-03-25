#include "image.h"
#include "game.h"
#include "dir.hpp"
#include "player.h"

class Gun
{
    public:
        Gun(Player *plr, Game *game);
        void update();
        Player* player;
        Image* image;
        Game* game;
};

#pragma once