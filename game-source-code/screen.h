#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

class screen
{
    public:
        screen();
        void run();
        vector<sf::CircleShape> SuperBalls;

    private :
        sf::Font font;
        sf::Text startUpMessage;
        sf::RenderWindow window;
        sf::Clock clock;
    private:
        void render();
        void processEvents();

};

#endif // SCREEN_H

