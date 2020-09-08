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

    window.clear(sf::Color::Black);
    window.display();
}
