#include "GameManager.h"
#include "Player.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "CollisionManager.h"

GameManager::GameManager(std::string _basePath)
{
	this->base_path = _basePath;
	srand(time(0));
	CreateGameWindow();
	InitialLoad();
	CreateInstancies();
	Run();
}

void GameManager::Run()
{
	while (WindowGame->IsOpen())
	{
		Actions actions = evntManager->GetEvntActions(WindowGame->WindowGame);

		if (actions.Space) {
			{
				auto p = GetGObjByName("player");
				Bullet* b = new Bullet();
				b->settings(*assetManager->sBullet, p.x, p.y, p.angle, 10);
				gameObjects.push_back(b);
			}
		}

		for (auto i = gameObjects.begin(); i != gameObjects.end();)
		{
			GameObject* e = *i;
			e->update();
			e->anim.update();
			if (e->name == "player")((Player*)e)->InputKeyb(actions);
			if (e->life == false) { i = gameObjects.erase(i); delete e; }
			else i++;
		}

		gameObjects = collisionMng->CheckCollisions(gameObjects);
		WindowGame->BeginDraw(); //Clear screen
		WindowGame->Draw(s);

		for (auto i : gameObjects)
		{
			i->draw(WindowGame->WindowGame);
		}

		WindowGame->EndDraw(); // Display screen
	}
}

GameObject GameManager::GetGObjByName(std::string name)
{
	for (GameObject* gObj : gameObjects)
	{
		if (gObj->name == name) return *gObj;
	}

	return GameObject();
}

void GameManager::CreateGameWindow()
{
	WindowGame = new GameWindow("Asteroids", screenWidth, screenHeight);
}

void GameManager::CreateInstancies()
{
	Player* player = new Player();
	player->settings(*assetManager->sPlayer, 200, 200, 0, 20);
	gameObjects.push_back(player);

	for (int i = 0; i < 15; i++)
	{
		Asteroid* ast = new Asteroid();
		ast->settings(*assetManager->sRock, rand() % 800, rand() % 600, rand() % 360, 25);
		gameObjects.push_back(ast);
	}

	//DEBUG
	std::cout << assetManager->Assets.size() << std::endl;
	for (Asset a : assetManager->Assets)
	{
		std::cout << "asset name " << a.name << std::endl;
		std::cout << "asset size  " << a.texture.getSize().x << std::endl;
	}
}

void GameManager::InitialLoad()
{
	t.loadFromFile(base_path + "External/Textures/background.jpg");
	s.setTexture(t);
	evntManager = new EventManager();
	assetManager = new AssetManager(base_path + "External/");
	assetManager->LoadAssets();
	assetManager->CreateAnims();
	collisionMng = new CollisionManager(assetManager);
}