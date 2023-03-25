#include "player.h"

Player::Player(int x, int y, int w, int h, Game *game)
{
    game->stuffToDraw.push_back(new Image("res/player.png", x, y, w, h));
}