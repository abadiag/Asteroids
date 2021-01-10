#pragma once
#include <SFML/Graphics.hpp>
class EventManager
{
public:
	EventManager(sf::RenderWindow);
	bool pendingEvents = false;
	sf::Event events;

};

