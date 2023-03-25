#include <cmath>

#include "bullet.hpp"
#include "gun.hpp"
#include "game.hpp"
#include "sound.hpp"

#define	BULLET_SPEED	1

Gun::Gun(Player *plr)
{
    player = plr;

    image = new Image(DIR_RES"gun.png", player->x,player->y,player->w,player->h);
    stuffToDraw.push_back(image);
}

void Gun::update()
{
    image->setX(player->x+15);
    image->setY(player->y);

}

void Gun::shoot()
{
	snd::ss.playSfx(snd::square);
	Bullet *b = new Bullet(
			player->x,
			player->y,
			64,
			64
			);
	stuffToShot.push_back(b);
	const int dx = game::mouse.x - b->m_x;
	const int dy = game::mouse.y - b->m_y;
	const double theta = std::atan((double) dy / dx);

	b->xspeed = cos(theta) * BULLET_SPEED;
	b->yspeed = sin(theta) * BULLET_SPEED;
}
