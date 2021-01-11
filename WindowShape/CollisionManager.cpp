#include "CollisionManager.h"

CollisionManager::CollisionManager(AssetManager* _assetMng)
{
	this->assMng = _assetMng;
}

std::list<GameObject*> CollisionManager::CheckCollisions(std::list<GameObject*>& gameObjects)
{
	for (auto a : gameObjects)
		for (auto b : gameObjects)
		{
			if (a->name == "asteroid" && b->name == "bullet")
				if (isCollide(a, b))
				{
					a->life = false;
					b->life = false;

					GameObject* e = new GameObject();
					e->settings(*assMng->sExplosion, a->x, a->y);
					e->name = "explosion";
					gameObjects.push_back(e);


					for (int i = 0; i < 2; i++)
					{
						if (a->R == 15) continue;
						GameObject* e = new Asteroid();
						e->settings(*assMng->sRock_small, a->x, a->y, rand() % 360, 15);
						gameObjects.push_back(e);
					}

				}

			if (a->name == "player" && b->name == "asteroid")
				if (isCollide(a, b))
				{
					b->life = false;

					GameObject* e = new GameObject();
					e->settings(*assMng->sExplosion_ship, a->x, a->y);
					e->name = "explosion";
					gameObjects.push_back(e);

					a->settings(*assMng->sPlayer, 800 / 2, 600 / 2, 0, 20);
					a->dx = 0; a->dy = 0;
				}
		}

	return gameObjects;
}

bool CollisionManager::isCollide(GameObject* a, GameObject* b)
{
	return (b->x - a->x) * (b->x - a->x) +
		(b->y - a->y) * (b->y - a->y) <
		(a->R + b->R) * (a->R + b->R);
}
