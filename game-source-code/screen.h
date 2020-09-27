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
        sf::Font font; //store font for texts on window
        sf::Text startUpMessage; //store texts to be drawn on window
        sf::RenderWindow window;
        sf::Clock clock;
    private:
        void render();
        void processEvents();
        bool splashScreen(); //Sets the splasreen
        bool start = false; //Variable to check if the game is still in the splash screen/game mode

};

#endif // SCREEN_H

