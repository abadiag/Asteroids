#include <SFML/Graphics.hpp>
#include "GameManager.h"
int main() 
{
	auto g = GameManager();
	return EXIT_SUCCESS;
}
//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <list>
//#include "Ball.h"
//#include "Window.h"
//
//using namespace std;
//using namespace sf;
//
//void EventHandle(sf::Event);
//void DrawableFactory();
//void FillDrawables();
//
//void Update();
//void Draw(sf::RenderWindow*);
//void UpdateScreenSize(sf::RenderWindow*);
//inline bool file_exists(const std::string&);
//
//// velocity movement
//int SPRITE_SPEED = 1;
//// Flags for key pressed
//bool upFlag = false;
//bool downFlag = false;
//bool leftFlag = false;
//bool rightFlag = false;
//bool spFlag = false;
//
//GameWindow* WindowGame;
//float screenWidth = 800.f, screenHeight = 600.f;
//list<sf::Drawable*> drawables;
//sf::RectangleShape shape(Vector2f(100, 20));
//sf::Font font;
//sf::Text txt;
//sf::Texture texture;
//Ball* ball;
//sf::RenderWindow* winPtr;
//string path = "C://Users//albert//source//repos//Graph//External//Fonts//Roboto-Bold.ttf";
//string texturePath = "C://Users//albert//source//repos//Graph//External//Textures//BallTexture.jpg";
//sf::WindowHandle handle;
//
//
//int main()
//{
//	try
//	{
//		WindowGame = new GameWindow("",screenWidth, screenHeight);
//		//sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Arcanoid");
//		handle = WindowGame->WindowGame.getSystemHandle();
//		UpdateScreenSize(&WindowGame->WindowGame);
//
//		DrawableFactory();
//		FillDrawables();
//
//		while (WindowGame->WindowGame.isOpen())
//		{
//			sf::Event event;
//			while (WindowGame->WindowGame.pollEvent(event))
//			{
//				if (event.type == sf::Event::Closed)
//					WindowGame->WindowGame.close();
//				if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased)
//					EventHandle(event);
//				if (event.type == sf::Event::Resized)
//				{
//					UpdateScreenSize(&WindowGame->WindowGame);
//				}		
//			}
//
//			WindowGame->WindowGame.clear();
//			Update();
//			Draw(&WindowGame->WindowGame);
//			WindowGame->WindowGame.display();
//		}
//	}
//	catch (std::exception& e)
//	{
//		std::cout << e.what() << std::endl;
//		return EXIT_FAILURE;
//	}
//	return EXIT_SUCCESS;
//}
//
//void DrawableFactory()
//{
//	texture.loadFromFile(texturePath);
//	ball = new Ball(Vector2f(10, 10), &texture);
//	shape.setFillColor(sf::Color::Yellow);
//	shape.setPosition(1, 1);
//
//	if (file_exists(path)) {
//		cout << "font load in process" << endl;
//		if (font.loadFromFile(path)) {
//			txt.setFont(font);
//			txt.setString("HOLA");
//			txt.setPosition(100, 100);
//			txt.setFillColor(Color::White);
//			txt.setCharacterSize(24); // in pixels, not points!
//		}
//	}
//	else {
//		cout << path << " not exists! " << endl;
//	}
//}
//
//void FillDrawables()
//{
//	drawables.push_back(&shape);
//	drawables.push_back(&ball->ball_shape);
//	drawables.push_back(&txt);
//}
//
//void UpdateScreenSize(sf::RenderWindow* _window)
//{
//	screenWidth = _window->getView().getSize().x - 10.0f;
//	screenHeight = _window->getView().getSize().y - 10.0f;
//}
//
//void EventHandle(sf::Event event)
//{
//	if (event.type == sf::Event::KeyPressed) {
//		switch (event.key.code)
//		{
//		// Process the up, down, left and right keys
//		case sf::Keyboard::Up:upFlag = true; break;
//		case sf::Keyboard::Down:downFlag = true; break;
//		case sf::Keyboard::Left:leftFlag = true; break;
//		case sf::Keyboard::Right:rightFlag = true; break;
//		case sf::Keyboard::Space:spFlag = true; break;
//		default: break;
//		}
//	}
//	// If a key is released
//	if (event.type == sf::Event::KeyReleased)
//	{
//		switch (event.key.code)
//		{
//			// Process the up, down, left and right keys
//		case sf::Keyboard::Up:upFlag = false; break;
//		case sf::Keyboard::Down:downFlag = false; break;
//		case sf::Keyboard::Left:leftFlag = false; break;
//		case sf::Keyboard::Right:rightFlag = false; break;
//		case sf::Keyboard::Space:spFlag = false; break;
//		default: break;
//		}
//	}
//}
//
//void Update()
//{
//	Vector2f v = ball->ball_shape.getPosition();
//	txt.setString(to_string(v.x).append(" " + to_string(v.y)));
//
//	if (v.x == screenWidth + 1.f) v.x = screenWidth;
//	if (v.x == -1)v.x = 0;
//	if (v.y == screenHeight + 1.f)v.y = screenHeight;
//	if (v.y == -1) v.y = 0;
//
//	float x = v.x;
//	float y = v.y;
//
//	// Update coordinates
//	if (leftFlag) v.x -= SPRITE_SPEED;
//	if (rightFlag) v.x += SPRITE_SPEED;
//	if (upFlag) v.y -= SPRITE_SPEED;
//	if (downFlag) v.y += SPRITE_SPEED;
//	ball->MovePosition(v);
//}
//
//void Draw(sf::RenderWindow* _window)
//{
//	for (Drawable* x : drawables) {
//		_window->draw(*x);
//	}
//}

//inline bool file_exists(const std::string& name) {
//	ifstream f(name.c_str());
//	return f.good();
//}