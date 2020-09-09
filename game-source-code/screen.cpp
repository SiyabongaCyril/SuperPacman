#include "screen.h"
#include "ResourcesManager.h"
#include "Maze.h"

screen::screen():window(sf::VideoMode(630,650),"Super Pacman"),SuperBalls()
{


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
    for(int j = 0; j<getFunction.maze.size(); j++)
    {
        window.draw(getFunction.maze[j]);
    }
        window.draw(PacMan);
        window.display();
    }
