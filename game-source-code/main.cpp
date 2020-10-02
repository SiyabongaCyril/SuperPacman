#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
#include <vector>
#include <ctime>
#include "screen.h"
#include "ResourcesManager.h"
#include "Maze.h"

using namespace std;

int main()
{

    srand(time(0));
    /*Maze getFunction;

    sf::RenderWindow window(sf::VideoMode(600,600), "Check Move");

    sf::Texture texture;

    texture.loadFromFile("resources/pacman.png");

    if(!texture.loadFromFile("resources/pacman.png"))
    {
        //return EXIT_FAILURE;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.scale(sf::Vector2f(0.03,0.03));

    float maize_size = getFunction.maze.size();

    while (window.isOpen())
    {
        sf::Event event;
        sf::Clock clock;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        for(unsigned int k=0; k<getFunction.maze.size(); k++)
        {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))

        {
            if(sprite.getGlobalBounds().intersects(getFunction.maze[k].getGlobalBounds()))
            {
                cout<<"collision"<<endl;
            }
            else
            {
                sprite.move(sf::Vector2f(0.001, 0));
            }

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {

            if(sprite.getGlobalBounds().intersects(getFunction.maze[k].getGlobalBounds()))
            {
                cout<<"collision"<<endl;
            }
            else
            {
                sprite.move(sf::Vector2f(0,0.001));
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if(sprite.getGlobalBounds().intersects(getFunction.maze[k].getGlobalBounds()))
            {
                cout<<"collision"<<endl;
            }
            else
            {
                sprite.move(sf::Vector2f(-0.001,0));
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if(sprite.getGlobalBounds().intersects(getFunction.maze[k].getGlobalBounds()))
            {
                cout<<"collision"<<endl;
            }
            else
            {
                sprite.move(sf::Vector2f(0,-0.001));
            }

        }

    }
        window.clear();
        window.draw(sprite);
        for(int j = 0; j<getFunction.maze.size(); j++)
        {
            window.draw(getFunction.maze[j]);
        }
    window.display();


     }  */

    screen pop;
    pop.run();
    return EXIT_SUCCESS;
    }
