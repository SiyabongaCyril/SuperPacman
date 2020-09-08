#ifndef RESOURCESMANAGER_H
#define RESOURCESMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>

using namespace std;

class ResourcesManager
{
    public:
        ResourcesManager();

        static sf::Texture& GetTexture(string const& filename);
    private:
        map<string, sf::Texture> m_Textures;

        static ResourcesManager* sInstance;
};

#endif // RESOURCESMANAGER_H
