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
        bool printMaze();


    private :
        sf::Font font; //store font for texts on window
        sf::Font scoreFont;
        sf::Text startUpMessage; //store texts to be drawn on window
        sf::Text scoreText;
        sf::Text highScoreText;
        sf::RenderWindow window;

        vector<sf::RectangleShape> Enemies;

    private:
        void render();
        void processEvents();
        bool splashScreen(); //Sets the splasreen
        bool scoreTexts();
        bool start = false; //Variable to check if the game is still in the splash screen/game mode
        bool isPlaying = false;

        bool pacM();
        sf::Clock clock;
        sf::Clock pacTimer;
        const float pos =400.f;

        string numToStr;
        int high_score = 0;
        int  score = 0;

};

#endif // SCREEN_H

