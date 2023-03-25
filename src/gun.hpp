#include "image.hpp"
#include "game.hpp"
#include "dir.hpp"
#include "player.hpp"

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
