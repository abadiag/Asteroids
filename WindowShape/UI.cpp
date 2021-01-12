#include "UI.h"


UI::UI(AssetManager* asMng)
{
	pointsTxt.setFont(asMng->font);
	asteroidsCounTxt.setFont(asMng->font);
	livesCountTxt.setFont(asMng->font);

	SetInitial();
}

void UI::SetInitial()
{
	pointsTxt.setCharacterSize(24);
	pointsTxt.setPosition(10,10);
	pointsTxt.setFillColor(sf::Color::White);
	setPoints(0);

	asteroidsCounTxt.setCharacterSize(24);
	asteroidsCounTxt.setPosition(300, 10);
	asteroidsCounTxt.setFillColor(sf::Color::White);
	setAsteroidCout(15);

	livesCountTxt.setCharacterSize(24);
	livesCountTxt.setPosition(500, 10);
	livesCountTxt.setFillColor(sf::Color::White);
	setLives(3);
}



void UI::setLives(int lives)
{
	livesCountTxt.setString(std::to_string(lives) + " LIVES");
}

void UI::setAsteroidCout(int asteroids)
{
	asteroidsCounTxt.setString(std::to_string(asteroids) + " * Remain");
}

void UI::setPoints(int points)
{
	pointsTxt.setString(std::to_string(points) + " Points");
}

void UI::DrawUI(sf::RenderWindow& window)
{
	window.draw(pointsTxt); 
	window.draw(asteroidsCounTxt);
	window.draw(livesCountTxt);
}

