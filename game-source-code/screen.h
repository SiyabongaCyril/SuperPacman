#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Maze.h"

using namespace std;
class scoreShows{};
class fruitsLoaded{};
class EventDeclared{};
class GhostsDrawn{};
class KeysLoaded{};
class screen
{
    public:
        screen();
        bool run();
        bool render();
        bool processEvents();
        bool splashScreen(); //Sets the splasreen
        vector<sf::CircleShape> SuperBalls;
        vector<sf::Sprite> Keys;
        vector<sf::Sprite> storeKeys;
        vector<sf::Sprite> Fruits;
         vector<sf::Sprite> storeFruits;
        vector<sf::RectangleShape> ManageDoors;

        bool printMaze();
        int scoreTexts();
        bool printScores();
        bool createFruits();
        bool pacM();
        bool Ghosts();
        bool createKeys();

    private :
        sf::Font font; //store font for texts on window
        sf::Font scoreFont;
        sf::Text startUpMessage; //store texts to be drawn on window
        sf::Text scoreText;
        sf::Text highScoreText;
        sf::RenderWindow window;
        sf::Vector2f position;
        sf::Vector2f RedPos;
        sf::Vector2f BluePos;
        sf::Vector2f PinkPos;
        sf::Vector2f OrangePos;

    private:

        bool start = false; //Variable to check if the game is still in the splash screen/game mode
        bool isPlaying = false;
        bool moveRedGhost = true;
        bool moveBlueGhost = true;
        bool movePinkGhost = true;
        bool moveOrangeGhost = true;

        sf::Clock clock;
        sf::Clock pacTimer;
        int moveBy;

        string numToStr;
        int high_score = 0;
        int  score = 0;
        int randomDoor;
        int create_pacman = 0;

        int create_keys = 0;
        int create_fruits = 0;
        int create_doors = 0;
        int track_doors = 1;

        int create_ghosts = 0;

        //variables for controlling pacma
        bool moving = false;
        bool stop = false;
        bool trackRight = false;
        bool trackLeft = false;
        bool trackUp = false;
        bool trackDown = false;
        bool check;
};

#endif // SCREEN_H

//Adding comment to make changes to allow pull request
