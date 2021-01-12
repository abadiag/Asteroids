#include "AssetManager.h"

AssetManager::AssetManager(std::string path)
{
    texturePath = path + "Textures/";
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

    try {
        for (std::filesystem::directory_iterator iter{ texturePath }; iter != end; ++iter)
        {
            if (std::filesystem::is_regular_file(*iter))
            { // comment out if all names (names of directories tc.) are required
                filenames.push_back(iter->path().string());
            }
        }
    }catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return filenames;
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
    return path;
}

void AssetManager::CreateAnims()
{
    expl = GetAssetByName("type_C").texture;
    sExplosion = new Animation(expl, 0, 0, 256, 256, 48, 0.5);

    rock = GetAssetByName("rock").texture;
    sRock = new Animation(rock, 0, 0, 64, 64, 16, 0.2);

    rockSmall = GetAssetByName("rock_small").texture;
    sRock_small = new Animation(rockSmall, 0, 0, 64, 64, 16, 0.2);

    bullet = GetAssetByName("fire_blue").texture;
    sBullet = new Animation(bullet, 0, 0, 32, 64, 16, 0.8);

    player_t = GetAssetByName("spaceship").texture;
    sPlayer = new Animation(player_t, 40, 0, 40, 40, 1, 0);

    player_go = GetAssetByName("spaceship").texture;
    sPlayer_go = new Animation(player_go, 40, 40, 40, 40, 1, 0);

    sExplosion_text = GetAssetByName("type_B").texture;
    sExplosion_ship = new Animation(sExplosion_text, 0, 0, 192, 192, 64, 0.5);
}
