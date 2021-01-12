#include "EventManager.h"
#include <iostream>

EventManager::EventManager()
{
	r = Actions();
}

Actions EventManager::GetEvntActions(sf::RenderWindow& w)
{
	sf::Event e;

	if (w.pollEvent(e)) {

		if (e.type == e.KeyPressed)
		{
			if (e.key.code == sf::Keyboard::Down)r.DownArrow = true;
			if (e.key.code == sf::Keyboard::Up)r.UpArrow = true;
			if (e.key.code == sf::Keyboard::Left)r.LeftArrow = true;
			if (e.key.code == sf::Keyboard::Right)r.RightArrow = true;
			if (e.key.code == sf::Keyboard::Space)r.Space = true;
		}
		if (e.type == e.KeyReleased)
		{
			if (e.key.code == sf::Keyboard::Down)r.DownArrow = false;
			if (e.key.code == sf::Keyboard::Up)r.UpArrow = false;
			if (e.key.code == sf::Keyboard::Left)r.LeftArrow = false;
			if (e.key.code == sf::Keyboard::Right)r.RightArrow = false;
			if (e.key.code == sf::Keyboard::Space)r.Space = false;
		}

		if (e.type == sf::Event::Resized)
		{
			r.WinSizeChange = true;
		}

		if (e.type == sf::Event::Closed)
		{
			r.WinClosed = true;
			w.close();
		}
	}

	return r;
}