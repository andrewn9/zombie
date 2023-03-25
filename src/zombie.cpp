#include "zombie.hpp"

Zombie::Zombie(int x, int y, int w, int h, Game *game)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;

    this->game = game;

    image = new Image(DIR_RES"zombie.png", x, y, w, h);
    game->stuffToDraw.push_back(image);
}

void Zombie::update()
{
    if(targetX<x)
        x-=WALK_SPEED;
    if(targetX>x)
        x+=WALK_SPEED;
    if(targetY<y)
        y-=WALK_SPEED;
    if(targetY>y)
        y+=WALK_SPEED;
    image->setX(x);
    image->setY(y);
}

//zomb

