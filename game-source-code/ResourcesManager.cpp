#include "ResourcesManager.h"
#include <assert.h>

ResourcesManager* ResourcesManager::sInstance = nullptr;

ResourcesManager::ResourcesManager()
{
    sInstance = this;
}
//Manage resources
sf::Texture& ResourcesManager::GetTexture(string const& filename)
{
    auto& texMap = sInstance->m_Textures;

    auto pairFound = texMap.find(filename);

//Returns the loaded resource as a texture and allows it to be passed to other functions
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




