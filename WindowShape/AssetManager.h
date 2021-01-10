#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <list>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <SFML/Graphics/Sprite.hpp>
#include "Animation.h"


struct Asset
{
	std::string name;
	sf::Texture texture;
};

class AssetManager
{
public:
	AssetManager();
	void LoadAssets();
	bool AssetsLoaded;
    //sf::Sprite background(sf::Texture().loadFromFile(texturePath.append("//background.jpg"));
	Asset GetAssetByName(std::string name);
	std::list<Asset>Assets;
	std::list<Animation>animations;
	
private:
	std::string texturePath = "C://Users//albert//source//repos//Graph//External//Textures//";
	Asset GetAsset(std::string path, std::string assetName);
	std::list<std::string>GetTexturePaths();	
	//void SetAnimations(); 
	std::string AssetName(std::string path);
};

