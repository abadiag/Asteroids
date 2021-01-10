#include "AssetManager.h"

AssetManager::AssetManager()
{
    //background = new sf::Sprite().sf::Texture().loadFromFile(texturePath.append("//background.jpg")));
	AssetsLoaded = false;
}

void AssetManager::LoadAssets()
{
	std::list<std::string> paths = GetTexturePaths();
    for (std::string s : paths)
    {
        std::string assetName = s.substr(s.find_last_of("/\\") + 1);
        Assets.push_back(GetAsset(s, assetName));
    }

    AssetsLoaded = true;
}

Asset AssetManager::GetAssetByName(std::string name)
{
    for (Asset a : Assets) 
    {
        if (a.name == name)
        {
            return a;
            break;
        }
    }
    return Asset();
}

Asset AssetManager::GetAsset(std::string path, std::string assetName)
{
    Asset r = Asset();
    r.texture.loadFromFile(path);
    r.name = AssetName(assetName);
    std::cout << "asset name: " << r.name << std::endl;
    std::cout << "asset path: " << path << std::endl;
    return r;
}

std::list<std::string> AssetManager::GetTexturePaths()
{
    const std::filesystem::directory_iterator end{};
    std::list<std::string> filenames;
    for (std::filesystem::directory_iterator iter{ texturePath }; iter != end; ++iter)
    {
        // http://en.cppreference.com/w/cpp/experimental/fs/is_regular_file 
        if (std::filesystem::is_regular_file(*iter)) 
        { // comment out if all names (names of directories tc.) are required
            filenames.push_back(iter->path().string());     
        }
    }
	return filenames;
}

std::string AssetManager::AssetName(std::string path)
{
    if (path.find(".jpg") != std::string::npos)
    {
        return path.replace(path.find(".jpg"), sizeof(".jpg") - 1, "");
    }
    if (path.find(".png") != std::string::npos)
    {
        return path.replace(path.find(".png"), sizeof(".png") - 1, "");
    }
    return "";
}

//void AssetManager::SetAnimations()
//{
//    Animation sExplosion(t3, 0, 0, 256, 256, 48, 0.5);
//    Animation sRock(t4, 0, 0, 64, 64, 16, 0.2);
//    Animation sRock_small(t6, 0, 0, 64, 64, 16, 0.2);
//    Animation sBullet(t5, 0, 0, 32, 64, 16, 0.8);
//    Animation sPlayer(t1, 40, 0, 40, 40, 1, 0);
//    Animation sPlayer_go(t1, 40, 40, 40, 40, 1, 0);
//    Animation sExplosion_ship(t7, 0, 0, 192, 192, 64, 0.5);
//}