#include "ResourcesManager.h"
#include <assert.h>

ResourcesManager* ResourcesManager::sInstance = nullptr;

ResourcesManager::ResourcesManager()
{
    sInstance = this;
}

sf::Texture& ResourcesManager::GetTexture(string const& filename)
{
    auto& texMap = sInstance->m_Textures;

    auto pairFound = texMap.find(filename);

    if(pairFound != texMap.end())
    {
        return pairFound ->second;
    }
    else
    {
        auto& texture = texMap[filename];
        texture.loadFromFile(filename);
        return texture;
    }
}




