#include "bullet.hpp"

Bullet::Bullet(Gun *gun, Game *game)
{
    this->x=gun->x;
    this->y=gun->y;
    this->w=gun->w;
    this->h=gun->h;

    this->game = game;
    image = new Image(DIR_RES"bullet.png", x, y, w, h);
    game->stuffToDraw.push_back(image);
}

void Bullet::update()
{
    x+=xspeed;
    y+=yspeed;
    image->setX(x);
    image->setY(y);
}

//zomb

