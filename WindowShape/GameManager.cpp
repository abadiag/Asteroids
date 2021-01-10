#include "GameManager.h"
#include "Player.h"
#include "Asteroid.h"

GameManager::GameManager()
{
	srand(time(0));
	CreateGameWindow();
	CreateInstancies();
	InitialLoad();
	Run();
}

void GameManager::Run()
{
	while (WindowGame->IsOpen())
	{
		WindowGame->Update();

		for (auto i = gameObjects.begin(); i != gameObjects.end();)
		{
			GameObject* e = *i;

			e->update();
			e->anim.update();

			if (e->life == false) { i = gameObjects.erase(i); delete e; }
			else i++;
		}

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
		WindowGame->BeginDraw();

		for (auto i : gameObjects)
			i->draw(WindowGame->WindowGame);

		//WindowGame->Draw(WindowGame->sprite);
//			Update();
			//WindowGame->Draw(WindowGame);
		WindowGame->EndDraw();
	}

}

void GameManager::CreateGameWindow()
{
	WindowGame = new GameWindow("Asteroids", screenWidth, screenHeight);

}

void GameManager::CreateInstancies()
{
	assetManager = new AssetManager();

	auto expl = assetManager->GetAssetByName("type_C").texture;
	Animation sExplosion(expl, 0, 0, 256, 256, 48, 0.5);

	auto rock = assetManager->GetAssetByName("rock").texture;
	Animation sRock(rock, 0, 0, 64, 64, 16, 0.2);

	auto rockSmall = assetManager->GetAssetByName("rock_small").texture;
	Animation sRock_small(rockSmall, 0, 0, 64, 64, 16, 0.2);

	auto bullet = assetManager->GetAssetByName("fire_blue").texture;
	Animation sBullet(bullet, 0, 0, 32, 64, 16, 0.8);
	
	auto player_t = assetManager->GetAssetByName("spaceship").texture;
	Animation sPlayer(bullet, 40, 0, 40, 40, 1, 0);

	auto player_go = assetManager->GetAssetByName("spaceship").texture;
	Animation sPlayer_go(player_t, 40, 40, 40, 40, 1, 0);

	auto sExplosion_text = assetManager->GetAssetByName("type_B").texture;
	Animation sExplosion_ship(sExplosion_text, 0, 0, 192, 192, 64, 0.5);


	//t1.loadFromFile("images/spaceship.png");
	//t2.loadFromFile("images/background.jpg");
	//t3.loadFromFile("images/explosions/type_C.png");
	//t4.loadFromFile("images/rock.png");
	//t5.loadFromFile("images/fire_blue.png");
	//t6.loadFromFile("images/rock_small.png");
	//t7.loadFromFile("images/explosions/type_B.png");
	//Animation sRock(t4, 0, 0, 64, 64, 16, 0.2);
	//Animation sRock_small(t6, 0, 0, 64, 64, 16, 0.2);
	//Animation sBullet(t5, 0, 0, 32, 64, 16, 0.8);
	//Animation sPlayer(t1, 40, 0, 40, 40, 1, 0);
	//Animation sPlayer_go(t1, 40, 40, 40, 40, 1, 0);
	//Animation sExplosion_ship(t7, 0, 0, 192, 192, 64, 0.5);

	Player* player = new Player();
	player->settings(sPlayer, 200, 200, 0, 20);
	gameObjects.push_back(player);

	for (int i = 0; i < 15; i++)
	{

		Asteroid* ast = new Asteroid();
		ast->settings(sRock, rand() % 800, rand() % 600, rand() % 360, 25);
		gameObjects.push_back(ast);
	}


	
}

void GameManager::InitialLoad()
{
	assetManager->LoadAssets();
	WindowGame->SetSpriteBackground(assetManager->GetAssetByName("background").texture);
}
