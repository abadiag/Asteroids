#pragma once
#include <list>
#include "GameObject.h"
#include "Asteroid.h"
#include "Player.h"
#include "AssetManager.h"

class CollisionManager
{
public:
	CollisionManager(AssetManager* _assetMng); 
	std::list<GameObject*> CheckCollisions(std::list<GameObject*>& gameObjects);
private:
	const AssetManager* assMng;
	
	bool isCollide(GameObject* a, GameObject* b);
};

