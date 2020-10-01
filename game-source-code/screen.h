#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Maze.h"

using namespace std;

class screen
{
    public:
        screen();
        void run();
        vector<sf::CircleShape> SuperBalls;
        vector<sf::Sprite> Keys;
        vector<sf::Sprite> Fruits;

        bool printMaze();

    private :
        sf::Font font; //store font for texts on window
        sf::Font scoreFont;
        sf::Text startUpMessage; //store texts to be drawn on window
        sf::Text scoreText;
        sf::Text highScoreText;
        sf::RenderWindow window;

    private:
        void render();
        void processEvents();

        void animateSplashScreenPac();
        void printScores();
        void createFruits();
        void createKeys();
        void Ghosts();

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
        int create_ghost = 0;

        int random = 0;

};

#endif // SCREEN_H

