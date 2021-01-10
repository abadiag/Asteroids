#pragma once
#include "Window.h"
#include "AssetManager.h"
#include "GameObject.h"

class GameManager
{
public:
	GameWindow* WindowGame;
	float screenWidth = 800.f, screenHeight = 600.f;
	AssetManager* assetManager;

	GameManager();
	void Run();

private:
	std::list<GameObject*> gameObjects;
	void CreateGameWindow();
	void CreateInstancies();
	void InitialLoad();
};

