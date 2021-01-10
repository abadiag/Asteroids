#include "GameManager.h"
#include "Player.h"
#include "Asteroid.h"
#include "Bullet.h"

GameManager::GameManager()
{
	srand(time(0));
	CreateGameWindow();
	InitialLoad();
	CreateInstancies();
	Run();
}

void GameManager::Run()
{

	sf::Texture t;

	t.loadFromFile("C:/Users/Albert/source/repos/Graph/External/Textures/background.jpg");
	sf::Sprite s(t);

	while (WindowGame->IsOpen())
	{
		Actions* actions = evntManager->GetEvntActions(WindowGame->WindowGame);

		if (actions->Space) {
			{
				auto p = GetGObjByName("player");
				Bullet* b = new Bullet();
				Animation sBullet(bullet, 0, 0, 32, 64, 16, 0.8);
				b->settings(sBullet, p.x, p.y, p.angle, 10);
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

		CollisionManager();

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
}

void GameManager::CreateGameWindow()
{
	WindowGame = new GameWindow("Asteroids", screenWidth, screenHeight);
}

void GameManager::CreateInstancies()
{
	expl = assetManager->GetAssetByName("type_C").texture;
	sExplosion = new Animation(expl, 0, 0, 256, 256, 48, 0.5);

	rock = assetManager->GetAssetByName("rock").texture;
	sRock = new Animation(rock, 0, 0, 64, 64, 16, 0.2);

	rockSmall = assetManager->GetAssetByName("rock_small").texture;
	sRock_small = new Animation(rockSmall, 0, 0, 64, 64, 16, 0.2);

	bullet = assetManager->GetAssetByName("fire_blue").texture;
	sBullet = new Animation(bullet, 0, 0, 32, 64, 16, 0.8);

	player_t = assetManager->GetAssetByName("spaceship").texture;
	sPlayer = new Animation(player_t, 40, 0, 40, 40, 1, 0);

	player_go = assetManager->GetAssetByName("spaceship").texture;
	sPlayer_go = new Animation(player_go, 40, 40, 40, 40, 1, 0);

	sExplosion_text = assetManager->GetAssetByName("type_B").texture;
	sExplosion_ship = new Animation(sExplosion_text, 0, 0, 192, 192, 64, 0.5);

	Player* player = new Player();
	player->settings(*sPlayer, 200, 200, 0, 20);
	gameObjects.push_back(player);

	for (int i = 0; i < 15; i++)
	{
		Asteroid* ast = new Asteroid();
		ast->settings(*sRock, rand() % 800, rand() % 600, rand() % 360, 25);
		gameObjects.push_back(ast);
	}

	std::cout << assetManager->Assets.size() << std::endl;
	for (Asset a : assetManager->Assets)
	{
		std::cout << "asset name " << a.name << std::endl;
		std::cout << "asset size  " << a.texture.getSize().x << std::endl;
	}


}

void GameManager::InitialLoad()
{
	evntManager = new EventManager();
	assetManager = new AssetManager();
	assetManager->LoadAssets();
	WindowGame->SetSpriteBackground(assetManager->GetAssetByName("background").texture);
}

void GameManager::CollisionManager()
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
					e->settings(*sExplosion, a->x, a->y);
					e->name = "explosion";
					gameObjects.push_back(e);


					for (int i = 0; i < 2; i++)
					{
						if (a->R == 15) continue;
						GameObject* e = new Asteroid();
						e->settings(*sRock_small, a->x, a->y, rand() % 360, 15);
						gameObjects.push_back(e);
					}

				}

			if (a->name == "player" && b->name == "asteroid")
				if (isCollide(a, b))
				{
					b->life = false;

					GameObject* e = new GameObject();
					e->settings(*sExplosion_ship, a->x, a->y);
					e->name = "explosion";
					gameObjects.push_back(e);

					a->settings(*sPlayer, 800 / 2, 600 / 2, 0, 20);
					a->dx = 0; a->dy = 0;
				}
		}

}

bool GameManager::isCollide(GameObject* a, GameObject* b)
{
	return (b->x - a->x) * (b->x - a->x) +
		(b->y - a->y) * (b->y - a->y) <
		(a->R + b->R) * (a->R + b->R);
}