#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "EventManager.h"

class GameObject
{
public:
	float x, y, dx, dy, R, angle;
	bool life;
	std::string name;
	Animation anim;
	float DEGTORAD = 0.017453f;
	GameObject();
	void settings(Animation& a, int X, int Y, float Angle = 0, int radius = 1);
	virtual void update() {};
	void draw(sf::RenderWindow& app);
	virtual ~GameObject(){};
};

