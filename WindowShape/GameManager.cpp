#include "GameManager.h"

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
}

void GameManager::InitialLoad()
{
	assetManager->LoadAssets();
	WindowGame->SetSpriteBackground(assetManager->GetAssetByName("background").texture);
}
