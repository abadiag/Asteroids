#pragma once
#include <SFML/Graphics.hpp>
#include "AssetManager.h"

class UI
{
public:
	UI(AssetManager*);
	void SetInitial();

	void setLives(int);
	void setAsteroidCout(int);
	void setPoints(int);

	void DrawUI(sf::RenderWindow& window);


private:
	sf::Text asteroidsCounTxt; 
	sf::Text livesCountTxt; 
	sf::Text pointsTxt;
};

