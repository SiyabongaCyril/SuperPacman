#include "screen.h"
#include "ResourcesManager.h"
#include "Maze.h"
//#include "doctest.h"

#include <string>

screen::screen():window(sf::VideoMode(630,650),"Super Pacman"),SuperBalls()
{

    //Declare splash screen icons
    splashScreen();

    //set text for the scores
    scoreTexts();

    //Load ghosts
    //store ghosts in a vector

    //Load Pallets
    //Loads Power Pallets
    //uses a vector to store pallets with their specific coordinates
    sf::CircleShape  superB;

    for( unsigned int i = 0; i<600; i++)
    {
        for(unsigned int j = 0; j<600; j++)
        {

            if(i == 130 && j==105 || i ==465 && j == 105||
                    i == 130 && j==495 || i == 465 && j == 495)
            {
                superB.setRadius(10);
                superB.setFillColor(sf::Color::Blue);
                superB.setPosition(sf::Vector2f(i,j));
                SuperBalls.push_back(superB);
            }
            else if(i == 210 && j ==364 || i == 375 && j == 364)
            {
                superB.setRadius(12);
                superB.setFillColor(sf::Color::Green);
                superB.setPosition(sf::Vector2f(i,j));
                SuperBalls.push_back(superB);
            }
        }
    }

}
//Window Setup
void screen::run()
{
    clock.restart();
    while(window.isOpen())
    {
        processEvents();
        render();
    }
}

void screen::processEvents()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::EventType::Closed: //Called when the x icon on window is pressed
            window.close();
            break;
        case sf::Event::EventType::KeyPressed: //called whenever a key is pressed (Keeps track of all the keys)
            if(event.key.code == sf::Keyboard::Escape)
                window.close(); //key can be closed by close button and space
            if(event.key.code == sf::Keyboard::Enter)
                start = true;
        default:
            break;
        }
    }
}

void screen::render()
{
    ResourcesManager manager;

    //loads picture and stores it as a sprite
    //Animate PacMan

    sf::IntRect rectPac(900,0,900,1000);
    sf::Sprite SplashScreenPacMan(ResourcesManager::GetTexture("resources/pacman.png"));

    //declaring pack man icon to display on the splashscreen
    if(!start)
    {
        //scales PacMan to the desired size
        SplashScreenPacMan.setTextureRect(rectPac);
        SplashScreenPacMan.setPosition(sf::Vector2f(194.f,47.5));

        SplashScreenPacMan.scale(sf::Vector2f(0.027,0.027));

        if (clock.getElapsedTime().asMilliseconds() > 100.0f)
        {
            if(rectPac.left == 900)
            {
                rectPac.left = 0;
            }
            else
                rectPac.left +=900;
            SplashScreenPacMan.setTextureRect(rectPac);

            if (clock.getElapsedTime().asMilliseconds() > 200.0f)
                clock.restart();
        }
    }

    //Start the game mode if the player enters the game mode
    if(start)
    {
        Maze getFunction;

        window.clear(sf::Color::Black);
        printMaze();
        pacM();
        createGhosts();
        //createFruits();
        createKeys();

        printScores();
    }
    else
    {
        //splashscreen draw variables on window if in splashhscreen mode
        window.draw(startUpMessage);
        window.draw(SplashScreenPacMan);
    }
    window.display();
}


bool screen::splashScreen()
{

    //Initialise pre-game window
    //Load Text Font
    //Set up text to be written on the splashcreen
    if(!font.loadFromFile("resources/OstrichSans-Medium.otf"))
        return EXIT_FAILURE;

    startUpMessage.setFont(font);
    startUpMessage.setCharacterSize(20);
    startUpMessage.setPosition(30.f, 50.f);
    startUpMessage.setFillColor(sf::Color::White);
    startUpMessage.setString("Welcome to Super Pac-Man\n\nPress Enter to start the game, Esc to exit\n\nTo play the game, use the arrow keys: Down, Up, Left, Right ");
    return true;
}
//pacman function
bool screen::pacM()
{
    ResourcesManager manager;

    sf::IntRect rectPac(900,0,900,1000);
    sf::Sprite PacMan(ResourcesManager::GetTexture("resources/pacman.png"));
    PacMan.setTextureRect(rectPac);
    PacMan.scale(sf::Vector2f(0.027,0.027));
    PacMan.setPosition(sf::Vector2f(273,65));

    float deltaTime = clock.restart().asSeconds();

    //scales PacMan to the desired size
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        //PacMan.move(sf::Vector2f(10, 0));
        PacMan.setPosition(sf::Vector2f(80+pos,65));
    }

    //Divides the PacMan sprite into two
    //Allocates time and switches between sections of sprite to create animation
    if (clock.getElapsedTime().asMilliseconds() > 100.0f)
    {
        if(rectPac.left == 900)
        {
            rectPac.left = 0;
        }
        else
            rectPac.left +=900;
        PacMan.setTextureRect(rectPac);

        if (clock.getElapsedTime().asMilliseconds() > 200.0f)
            clock.restart();
    }
    window.draw(PacMan);
}

void screen::createGhosts()
{
    ResourcesManager manager;

    sf::Sprite red(ResourcesManager::GetTexture("resources/redGhost.png"));
    red.scale(sf::Vector2f(0.21,0.21));
    red.setPosition(sf::Vector2f(255,200));

    sf::Sprite pink(ResourcesManager::GetTexture("resources/pinkGhost.png"));
    pink.scale(sf::Vector2f(0.21,0.21));
    pink.setPosition(sf::Vector2f(329,200));

    sf::Sprite orange(ResourcesManager::GetTexture("resources/orangeGhost.png"));
    orange.scale(sf::Vector2f(0.21,0.21));
    orange.setPosition(sf::Vector2f(255,234));

    sf::Sprite blue(ResourcesManager::GetTexture("resources/blueGhost.png"));
    blue.scale(sf::Vector2f(0.21,0.21));
    blue.setPosition(sf::Vector2f(329,234));

    window.draw(red);
    window.draw(pink);
    window.draw(orange);
    window.draw(blue);
}

void screen::createKeys()
{
    ResourcesManager manager;

    //sf::IntRect rectKey(900,0,900,1000);
    sf::Sprite key(ResourcesManager::GetTexture("resources/key.png"));
    //key.setTextureRect(rectKey);

    for( unsigned int i = 0; i<600; i++)
    {
        for(unsigned int j = 0; j<600; j++)
        {

            sf::Sprite key(ResourcesManager::GetTexture("resources/key.png"));

            if(i == 85 && j==65 || i == 510 && j == 65 || i == 85 && j == 525 || i == 510 && j ==  525 ||
               i == 85 && j ==  240 || i == 510 && j ==  240 ||   i == 85 && j ==  325 || i == 510 && j ==  325 ||
                  i == 170 && j ==  150 || i == 425 && j ==  150 || i == 170 && j ==  490 || i == 425 && j ==  490
                  || i == 215 && j ==  325 || i == 380 && j ==  325)
            {

                key.scale(sf::Vector2f(0.128,0.128));
                key.setPosition(sf::Vector2f(i,j));
                Fruits.push_back(key);
            }
        }
    }

    for(int k = 0; k<Fruits.size(); k++)
    {
        window.draw(Fruits[k]);
    }
}

void screen::printScores()
{
    numToStr = to_string(high_score);

    scoreText.setString(numToStr);

    window.draw(scoreText);

    numToStr = to_string(score);

    highScoreText.setString(numToStr);

    window.draw(highScoreText);
}
bool screen::printMaze()
{
    Maze getFunction;

    for(int k = 0; k<getFunction.Doors.size(); k++)
    {
        window.draw(getFunction.Doors[k]);
    }
    for(int j = 0; j<getFunction.maze.size(); j++)
    {
        window.draw(getFunction.maze[j]);
    }
    for(int i = 0; i<SuperBalls.size(); i++)
    {
        window.draw(SuperBalls[i]);
    }

    window.draw(getFunction.text);

    return true;
}
bool screen::scoreTexts()
{
    //Load font and set text for the scores
    if(!scoreFont.loadFromFile("resources/OstrichSans-Bold.otf"))
        return EXIT_FAILURE;

    scoreText.setFont(scoreFont);
    scoreText.setCharacterSize(20);
    scoreText.setPosition(73,25);
    scoreText.setFillColor(sf::Color::White);

    highScoreText.setFont(scoreFont);
    highScoreText.setCharacterSize(20);
    highScoreText.setPosition(273,25);
    highScoreText.setFillColor(sf::Color::White);

    return true;
}
