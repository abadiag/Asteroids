#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "AssetManager.h"
#include "GameObject.h"
#include "EventManager.h"
#include "CollisionManager.h"


class GameManager
{
public:
	GameWindow* WindowGame;
	float screenWidth = 800.f, screenHeight = 600.f;
	AssetManager* assetManager;
	EventManager* evntManager;
	CollisionManager* collisionMng;
	GameManager(std::string _basePath);
	void Run();

private:
	std::string base_path;// = "D:/Repos/Asteroids/";
	std::list<GameObject*> gameObjects;
	sf::Texture t;
	sf::Sprite s;
	void CreateGameWindow();
	void CreateInstancies();
	void InitialLoad();
	GameObject GetGObjByName(std::string name);
};