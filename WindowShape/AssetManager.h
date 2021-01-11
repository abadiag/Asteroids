#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <list>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <SFML/Graphics/Sprite.hpp>
#include "Animation.h"

class Asset
{
public:
	std::string name;
	sf::Texture texture;
};

class AssetManager
{
public:
	AssetManager(std::string path);
	void LoadAssets();
	void CreateAnims();
	bool AssetsLoaded;
	Asset GetAssetByName(std::string name);
	std::list<Asset>Assets;
	std::list<Animation>animations;

	Animation* sExplosion;
	Animation* sRock;
	Animation* sRock_small;
	Animation* sBullet;
	Animation* sPlayer;
	Animation* sPlayer_go;
	Animation* sExplosion_ship;
	
private:
	sf::Texture player_t, player_go, rock, bullet, rockSmall, sExplosion_text, expl;
	std::string texturePath;

	Asset GetAsset(std::string path, std::string assetName);
	std::list<std::string>GetTexturePaths();	
	//void SetAnimations(); 
	std::string AssetName(std::string path);
};

