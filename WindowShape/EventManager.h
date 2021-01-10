#pragma once
#include <SFML/Graphics.hpp>

struct Actions
{
	bool WinSizeChange = false;
	bool WinClosed = false;
	bool UpArrow = false;
	bool DownArrow = false;
	bool LeftArrow = false;
	bool RightArrow = false;
	bool Space = false;
};

class EventManager
{
public:
	EventManager();
	bool pendingEvents = false;
	Actions* GetEvntActions(sf::RenderWindow& w);

private:
	sf::RenderWindow _window;

};

