#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class screen
{
public:
    screen();
    bool run();
    bool render();
    bool processEvents();
    bool splashScreen(); //Sets the splasreen
    vector<sf::CircleShape> SuperBalls;
    vector<sf::CircleShape> Balls;
    vector<sf::Sprite> Keys;
    vector<sf::Sprite> storeKeys;
    vector<sf::Sprite> Fruits;
    vector<sf::Sprite> storeFruits;
    vector<sf::Sprite> storeGhosts;
    vector<sf::RectangleShape> ManageDoors;
    vector<unsigned int> eatenGhosts;

    bool printMaze();
    int scoreTexts();
    bool printScores();
    bool createFruits();
    bool pacM();
    bool Ghosts();
    bool createKeys();
    bool drunkGhosts();
    bool endGameScreen();
    bool EnlargedPac();

private :
    sf::Font font;
    sf::Font scoreFont;
    sf::Text startUpMessage;
    sf::Text endMessage;
    sf::Text scoreText;
    sf::Text highScoreText;
    sf::RenderWindow window;
    sf::Vector2f position;
    sf::Vector2f RedPos;
    sf::Vector2f BluePos;
    sf::Vector2f PinkPos;
    sf::Vector2f OrangePos;

private:

    //Variable to check game state:  Start Splashscreen/Gaming-Mode/End-Splashscreen
    bool start = false;
    bool  endGame = false;
    bool isPlaying = false;

    //Variables that control ghost movements
    bool moveRedGhost = true;
    bool moveBlueGhost = true;
    bool movePinkGhost = true;
    bool moveOrangeGhost = true;

    bool normalPacMan = true;

    sf::Clock clock;
    sf::Clock pacTimer;
    int moveBy;

    string numToStr;
    int high_score = 0;
    int  score = 0;
    int randomDoor;

    //Variables for storing and keeping tranck of changes to keys,fruits,doors,ghosts,pellets,super-pellets,maze and Pac-man
    int create_pacman = 0;
    int create_keys = 0;
    int create_fruits = 0;
    int create_doors = 0;
    int track_doors = 1;
    int pellets_collision = 0;

    int create_ghosts = 0;
    int checkCollision = false;

    //variables for controlling Pac-Man movements and changes
    bool moving = false;
    bool stop = false;
    bool trackRight = false;
    bool trackLeft = false;
    bool trackUp = false;
    bool trackDown = false;
    bool check;
    bool PacCaught = false;
};

#endif // SCREEN_H

