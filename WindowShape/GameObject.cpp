#include "GameObject.h"

GameObject::GameObject()
{
	life = 1;
}

void GameObject::settings(Animation& a, int X, int Y, float Angle, int radius)
{
	anim = a;
	x = X; y = Y;
	angle = Angle;
	R = radius;
}

void GameObject::draw(sf::RenderWindow& app)
{
	anim.sprite.setPosition(x, y);
	anim.sprite.setRotation(angle + 90);
	app.draw(anim.sprite);

	sf::CircleShape circle(R);
	circle.setFillColor(sf::Color::Color(255, 0, 0, 170));
	circle.setPosition(x, y);
	circle.setOrigin(R, R);
}