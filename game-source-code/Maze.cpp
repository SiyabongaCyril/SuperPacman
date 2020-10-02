#include "Maze.h"
#include "screen.h"

Maze::Maze():maze(),Doors()
{
    //Create Maze
    //Builds the frame of the maze
    //Uses vector to store coordinates of maze building blocks

    //set texts for the maze
    setText();
//Maze Updated
    sf::RectangleShape maze_blocks(sf::Vector2f(618,584));

    for( unsigned int i = 0; i<600; i++)
    {
        for(unsigned int j = 0; j<600; j++)
        {
            if(i==115 && j==105 || i==115 && j==185 ||i==157 && j==105||i==451 && j==105 ||i==493 && j==185||
                    i==493 && j==105 ||i==115 && j==484 || i==157 && j==484||i==451 && j==484 || i==493 && j==484||
                    i==241 && j==315 || i==283 && j==315||i==325 && j==315 || i==367 && j==315||i==283 && j==439 || i==325 && j==439 )
            {
                maze_blocks.setScale(sf::Vector2f(0.01,0.07));
                maze_blocks.setFillColor(sf::Color::Blue);
                maze_blocks.setPosition(sf::Vector2f(i,j));
                maze.push_back(maze_blocks);
            }
            else if(i==157 && j==225 || i==451 && j==225)
            {
                maze_blocks.setScale(sf::Vector2f(0.01,0.09));
                maze_blocks.setFillColor(sf::Color::Blue);
                maze_blocks.setPosition(sf::Vector2f(i,j));
                maze.push_back(maze_blocks);
            }
            else if(i==73 && j==272 || i==73 && j==314 ||i==241 && j==314 || i==241 && j==350 ||i==325 && j==314 || i==325 && j==350 ||
                    i== 493 && j==272 || i==493 && j==314 ||i==157 && j==314 || i==411 && j==314||i==157 && j==185 || i==241 && j==185 ||
                    i==325 && j==185 || i==409 && j==185 || i==241 && j==391 || i==328 && j==392 || i==284 && j==439)
            {
                maze_blocks.setScale(sf::Vector2f(0.07,0.01));
                maze_blocks.setFillColor(sf::Color::Blue);
                maze_blocks.setPosition(sf::Vector2f(i,j));
                maze.push_back(maze_blocks);
            }
            else if(i==241 && j==186 || i==367 && j==186||i==115 && j==354 || i==157 && j==354
                    || i==241 && j==392 || i==367 && j==392||i==451 && j==354 || i==493 && j==354)
            {
                maze_blocks.setScale(sf::Vector2f(0.01,0.15));
                maze_blocks.setFillColor(sf::Color::Blue);
                maze_blocks.setPosition(sf::Vector2f(i,j));
                maze.push_back(maze_blocks);
            }
            else if(i==199 && j==186 || i==409 && j==186)
            {
                maze_blocks.setScale(sf::Vector2f(0.01,0.16));
                maze_blocks.setFillColor(sf::Color::Blue);
                maze_blocks.setPosition(sf::Vector2f(i,j));
                maze.push_back(maze_blocks);
            }
            else if(i == 199 && j ==105 || i == 325 && j == 105|| i == 199 && j ==519 || i == 325 && j == 519|| i==242 && j==272 || i==286 && j==272 )
            {
                maze_blocks.setScale(sf::Vector2f(0.14,0.01));
                maze_blocks.setFillColor(sf::Color::Blue);
                maze_blocks.setPosition(sf::Vector2f(i,j));
                maze.push_back(maze_blocks);
            }
            else if(i == 199 && j == 142)
            {
                maze_blocks.setScale(sf::Vector2f(0.35,0.01));
                maze_blocks.setFillColor(sf::Color::Blue);
                maze_blocks.setPosition(sf::Vector2f(i,j));
                maze.push_back(maze_blocks);
            }
            else if(i == 199 && j == 354 || i ==409 && j ==354 )
            {
                maze_blocks.setScale(sf::Vector2f(0.01,0.215));
                maze_blocks.setFillColor(sf::Color::Blue);
                maze_blocks.setPosition(sf::Vector2f(i,j));
                maze.push_back(maze_blocks);
            }
            else if(i==73 && j==315 || i==535 && j==314)
            {
                maze_blocks.setScale(sf::Vector2f(0.01,0.427));
                maze_blocks.setFillColor(sf::Color::Blue);
                maze_blocks.setPosition(sf::Vector2f(i,j));
                maze.push_back(maze_blocks);
            }
            else if(i==73 && j==66 || i==535 && j==66)
            {
                maze_blocks.setScale(sf::Vector2f(0.01,0.36));
                maze_blocks.setFillColor(sf::Color::Blue);
                maze_blocks.setPosition(sf::Vector2f(i,j));
                maze.push_back(maze_blocks);
            }
            else if(i==73 && j==557 || i==74 && j==66)
            {
                maze_blocks.setScale(sf::Vector2f(0.75,0.01));
                maze_blocks.setFillColor(sf::Color::Blue);
                maze_blocks.setPosition(sf::Vector2f(i,j));
                maze.push_back(maze_blocks);
            }
        }
    }

    //Create MazeDoors
    //Creates doors for parts of the maze that cannot be entered without keys
//Maze readjusted
    sf::RectangleShape door_blocks(sf::Vector2f(618,584));

    for( unsigned int i = 0; i<600; i++)
    {
        for(unsigned int j = 0; j<600; j++)
        {

            if(i==73 && j==278 || i==115 && j==278|| i==157 && j==278 ||i==199 && j==278
                    ||  i==538 && j==276 || i==493 && j==278 || i==451 && j==278 || i==412 && j==278
                    || i==199 && j==106 || i==412 && j==106 || i==199 && j==519 || i==412 && j==519
                    || i==327 && j==354 || i==283 && j==354
              )
            {
                door_blocks.setScale(sf::Vector2f(0.005,0.07));
                door_blocks.setFillColor(sf::Color::Red);
                door_blocks.setPosition(sf::Vector2f(i,j));
                Doors.push_back(door_blocks);
            }
            else if(i==115 && j==105 || i==115 && j==143 || i==115 && j==185 || i==115 && j==225
                    || i==115 && j==355 || i==115 && j==438 || i==115 && j==485 || i==115 && j==522
                    || i==451 && j==105  || i==451 && j==143 || i==452 && j==185 || i==451 && j==225
                    || i==451 && j==355 || i==451 && j==438 || i==451 && j==485 || i==451 && j==522
                    || i==283 && j==105  || i==283 && j==185 || i==283 && j==477 || i==283 && j==519
                    || i==200 && j==354 || i==367 && j==354 || i==200 && j==477 || i==367 && j==477)
            {

                door_blocks.setScale(sf::Vector2f(0.07,0.005));
                door_blocks.setFillColor(sf::Color::Red);
                door_blocks.setPosition(sf::Vector2f(i,j));
                Doors.push_back(door_blocks);
            }
        }
    }
}

bool Maze::setText()
{
    if(!textFont.loadFromFile("resources/OstrichSans-Bold.otf"))
    return EXIT_FAILURE;

            text.setFont(textFont);
            text.setCharacterSize(20);
            text.setPosition(273,1);
            text.setFillColor(sf::Color::Red);
            text.setString("HIGH SCORE");

     return true;
}
