#include "Asteroid.h"

Asteroid::Asteroid()
{
    dx = rand() % 8 - 4;
    dy = rand() % 8 - 4;
    name = "asteroid";
}

void  Asteroid::update()
{
    x += dx;
    y += dy;

    if (x > 800) x = 0;  if (x < 0) x = 800;
    if (y > 600) y = 0;  if (y < 0) y = 600;
}
