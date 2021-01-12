#include "Player.h"

Player::Player()
{
    name = "player";
}

void Player::InputKeyb(Actions a)
{
    if (a.RightArrow) angle += 3;
    if (a.LeftArrow) angle -= 3;
    if (a.UpArrow) thrust = true;
    else thrust = false;
}

void Player::update()
{
    if (thrust)
    {
        //accel force
        dx += cos(angle * DEGTORAD) * 0.2;
        dy += sin(angle * DEGTORAD) * 0.2;
    }
    else
    {
        //brake force
        dx *= 0.70;
        dy *= 0.70;
    }

    int maxSpeed = 15;

    float speed = sqrt(dx * dx + dy * dy);
    
    if (speed > maxSpeed)
    {
        dx *= maxSpeed / speed;
        dy *= maxSpeed / speed;
    }

    x += dx;
    y += dy;

    if (x > 800) x = 0; if (x < 0) x = 800;
    if (y > 600) y = 0; if (y < 0) y = 600;
}