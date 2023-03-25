#include "player.hpp"
#include "game.hpp"

Player::Player(int x, int y, int w, int h)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
    image = new Image(DIR_RES"player.png", x, y, w, h);
    stuffToDraw.push_back(image);
}

void Player::update()
{
    if(game::key_state[SDL_SCANCODE_W])
    {
        y-=PLAYER_WALK_SPEED;
    }
    if(game::key_state[SDL_SCANCODE_A])
    {
        x-=PLAYER_WALK_SPEED;
    }
    if(game::key_state[SDL_SCANCODE_S])
    {
        y+=PLAYER_WALK_SPEED;
    }
    if(game::key_state[SDL_SCANCODE_D])
    {
        x+=PLAYER_WALK_SPEED;
    }

    image->setX(x);
    image->setY(y);
}

