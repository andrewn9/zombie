#include "player.h"

Player::Player(int x, int y, int w, int h, Game *game)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;

    this->game = game;

    image = new Image(DIR_RES"player.png", x, y, w, h);
    game->stuffToDraw.push_back(image);
}

void Player::update()
{
    if(game->key_state[SDL_SCANCODE_W])
    {
        y-=WALK_SPEED;
    }
    if(game->key_state[SDL_SCANCODE_A])
    {
        x-=WALK_SPEED;
    }
    if(game->key_state[SDL_SCANCODE_S])
    {
        y+=WALK_SPEED;
    }
    if(game->key_state[SDL_SCANCODE_D])
    {
        x+=WALK_SPEED;
    }

    image->setX(x);
    image->setY(y);
}

