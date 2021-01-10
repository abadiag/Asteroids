#include "Window.h"

GameWindow::GameWindow(const std::string& windowName, float width, float height)
	: WindowGame(sf::VideoMode(width, height), windowName/*, sf::Style::Titlebar*/) // 1
{
	//WindowGame.setVerticalSyncEnabled(true); // 2
	//WindowGame.setFramerateLimit(60);
}

void GameWindow::Update()
{
	if (WindowGame.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			WindowGame.close();
		}
	}
}

void GameWindow::BeginDraw() // 4
{
	WindowGame.clear();
	//Draw(sprite);
}

void GameWindow::Draw(const sf::Drawable& drawable)
{
	WindowGame.draw(drawable);
}

void GameWindow::EndDraw()
{
	WindowGame.display();
}

bool GameWindow::IsOpen() const
{
	return WindowGame.isOpen();
}

void GameWindow::SetSpriteBackground(sf::Texture t)
{
	sf::Texture t2;
	t2.loadFromFile("C:/Users/Albert/source/repos/Graph/External/Textures/background.jpg");
	t2.setSmooth(true);
	sf::Sprite back(t2);
	sprite = back;
}
