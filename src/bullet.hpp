#pragma once

#include "image.hpp"
#include "dir.hpp"
#include "gun.hpp"

class Bullet
{
    public:
	Bullet(int x, int y, int w, int h);
        void update();
        Gun* gun;
        int xspeed, yspeed;
        int m_x, m_y, m_w, m_h;
        Image* image;
};

//zomb
