#include "Bullet.h"

Bullet::Bullet()
{
	name = "bullet";
}

void Bullet::update()
{
	dx = cos(angle * DEGTORAD) * 6;
	dy = sin(angle * DEGTORAD) * 6;
	// angle+=rand()%6-3;
	x += dx;
	y += dy;

	if (x > 800 || x<0 || y>600 || y < 0) life = 0;
}