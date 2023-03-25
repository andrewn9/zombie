#include "gun.hpp"

Gun::Gun(Player *plr, Game *game)
{
    player = plr;
    this->game = game;

    image = new Image(DIR_RES"gun.png", player->x,player->y,player->w,player->h);
    game->stuffToDraw.push_back(image);
}

void Gun::update()
{
    image->setX(player->x);
    image->setY(player->y);
}

