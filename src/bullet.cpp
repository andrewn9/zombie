#include "bullet.hpp"
#include "game.hpp"
#include "sound.hpp"

Bullet::Bullet(int x, int y, int w, int h) :
	m_x(x),
	m_y(y),
	m_w(w),
	m_h(h)
{
    image = new Image(DIR_RES "bullet.png", x, y, w, h);
    stuffToDraw.push_back(image);
			snd::ss.playSfx(snd::snare);
}

void Bullet::update()
{
    m_x+=xspeed * game::ts;
    m_y+=yspeed * game::ts;
    image->setX(m_x);
    image->setY(m_y);
}

//zomb

