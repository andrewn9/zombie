
#pragma once

#include "image.hpp"
#include "dir.hpp"
#include "player.hpp"

class Gun
{
    public:
        Gun(Player *plr);
        void update();
	void shoot();
        Player* player;
        Image* image;
};
