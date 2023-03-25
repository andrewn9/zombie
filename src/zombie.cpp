#include "zombie.hpp"
#include "game.hpp"

Zombie::Zombie(int x, int y, int w, int h)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;

    image = new Image(DIR_RES"zombie.png", x, y, w, h);
    stuffToDraw.push_back(image);
}

void Zombie::update()
{
    if(targetX<x)
        x-=ZOM_WALK_SPEED;
    if(targetX>x)
        x+=ZOM_WALK_SPEED;
    if(targetY<y)
        y-=ZOM_WALK_SPEED;
    if(targetY>y)
        y+=ZOM_WALK_SPEED;
    image->setX(x);
    image->setY(y);
}

//zomb

