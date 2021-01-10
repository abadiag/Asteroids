#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "AssetManager.h"
#include "GameObject.h"
#include "EventManager.h"


class GameManager
{
public:
	GameWindow* WindowGame;
	float screenWidth = 800.f, screenHeight = 600.f;
	AssetManager* assetManager;
	EventManager* evntManager;
	GameManager();
	void Run();

private:
	std::list<GameObject*> gameObjects;
	void CreateGameWindow();
	void CreateInstancies();
	void InitialLoad();
	GameObject GetGObjByName(std::string name);
	void CollisionManager();
	bool isCollide(GameObject* a, GameObject* b);
	sf::Texture player_t, player_go, rock, bullet, rockSmall, sExplosion_text, expl;

	Animation* sExplosion;
	Animation* sRock;
	Animation* sRock_small;
	Animation* sBullet; 
	Animation* sPlayer; 
	Animation* sPlayer_go;
	Animation* sExplosion_ship;
};

