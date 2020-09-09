#include "screen.h"
#include "ResourcesManager.h"
#include "Maze.h"

screen::screen():window(sf::VideoMode(630,650),"Super Pacman"),SuperBalls()
{
     sf::Font font;
     sf::Text startUpMessage;

    //Initialise pre-game window
    //startUpMessage.setFont();
    sf::Font font;
    if(!font.loadFromFile("resources/ostrich-regular.ttf"))

	startUpMessage.setFont(font);
    startUpMessage.setCharacterSize(20);
    startUpMessage.setPosition(30.f, 50.f);
    startUpMessage.setFillColor(sf::Color::Red);
    startUpMessage.setString("Welcome to Super Pac-Man\nPress Enter to start the game\nTo play the game, use the arrow keys");

    //Load Pallets
    //Loads Power Pallets
    //uses a vector to store pallets with their specific coordinates
    sf::CircleShape  superB;

    for( unsigned int i = 0; i<600; i++)
    {
        for(unsigned int j = 0; j<600; j++)
        {

            if(i == 130 && j==105 || i ==465 && j == 105||
                    i == 130 && j==515 || i == 465 && j == 515)
            {
                superB.setRadius(10);
                superB.setFillColor(sf::Color::Blue);
                superB.setPosition(sf::Vector2f(i,j));
                SuperBalls.push_back(superB);
            }
            else if(i == 210 && j ==374 || i == 370 && j == 374)
            {
                superB.setRadius(15);
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
        if(event.type == sf::Event::Closed)
            window.close(); //Window is closed by the x cross on the pop up exexutable file
    }
}

void screen::render()
{
    //Animate PacMan
    ResourcesManager manager;
    Maze getFunction;

    //loads picture and stores it as a sprite
    //scales PacMan to the desired size
    sf::IntRect rectPac(900,0,900,1000);
    sf::Sprite PacMan(ResourcesManager::GetTexture("resources/pacman.png"));
    PacMan.setTextureRect(rectPac);
    PacMan.setPosition(sf::Vector2f(80,65));
    PacMan.scale(sf::Vector2f(0.03,0.03));

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

    window.clear(sf::Color::Black);
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
    window.draw(PacMan);
    window.display();
}
