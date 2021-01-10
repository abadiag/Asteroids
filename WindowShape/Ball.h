#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

using namespace sf;

class Ball :public GameObject
{
private:
	Texture* _texture;
	Sprite _sprite;
	Vector2f _position;
	

public:
	Ball(Vector2f, Texture*);
	void MovePosition(Vector2f);
	CircleShape ball_shape;
};

