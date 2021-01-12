#include "Bullet.h"

Bullet::Bullet()
{
	name = "bullet";
}

void Bullet::update()
{
	dx = cos(angle * DEGTORAD) * 10;
	dy = sin(angle * DEGTORAD) * 10;
	x += dx;
	y += dy;

	if (x > 800 || x<0 || y>600 || y < 0) life = 0;
}