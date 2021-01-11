#include "EventManager.h"
#include <iostream>

EventManager::EventManager() {}

Actions EventManager::GetEvntActions(sf::RenderWindow& w)
{
	sf::Event e;
	Actions r = Actions();

	if (w.pollEvent(e)) {
		
		r.DownArrow = (e.key.code == sf::Keyboard::Down);
		r.UpArrow = (e.key.code == sf::Keyboard::Up);
		r.LeftArrow = (e.key.code == sf::Keyboard::Left);
		r.RightArrow = (e.key.code == sf::Keyboard::Right);
		r.Space = (e.key.code == sf::Keyboard::Space);
		if (e.type == sf::Event::Resized) { r.WinSizeChange = true; }
		
		if (e.type == sf::Event::Closed) 
		{
			r.WinClosed = true;
			w.close();
		}
	}

	return r;
	
}
//struct Actions
//{
//	bool* WinSizeChange = false;
//	bool* UpArrow = false;
//	bool* DownArrow = false;
//	bool* LeftArrow = false;
//	bool* RightArrow = false;
//	bool* Space = false;
//};