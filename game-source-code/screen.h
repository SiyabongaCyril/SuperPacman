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
        sf::Clock clock;
<<<<<<< HEAD
        int pos =100;
=======
        vector<sf::RectangleShape> Enemies;
>>>>>>> f7f0f56ee19b9e63324c04664c7ec597377d8890
    private:
        void render();
        void processEvents();
        bool splashScreen(); //Sets the splasreen
        bool scoreTexts();
        bool start = false; //Variable to check if the game is still in the splash screen/game mode
<<<<<<< HEAD
        sf::Sprite pacM();
=======
        string numToStr;
        int high_score = 0;
        int  score = 0;
>>>>>>> f7f0f56ee19b9e63324c04664c7ec597377d8890

};

#endif // SCREEN_H

