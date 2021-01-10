#include "Ball.h"


Ball::Ball(Vector2f pos, Texture* texture)
{
	_position = pos;
	_texture = texture;
	ball_shape = CircleShape(10.f);
	ball_shape.setTexture(_texture, false);
	ball_shape.setPosition(1, 1);
}

void Ball::MovePosition(Vector2f position)
{
	ball_shape.setPosition(position);
}
