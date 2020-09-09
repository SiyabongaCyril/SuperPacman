#include "Maze.h"
#include "screen.h"

Maze::Maze():maze(),Doors()
{
    //Create Maze
    //Builds the frame of the maze
    //Uses vector to store coordinates of maze building blocks
    sf::RectangleShape maze_blocks(sf::Vector2f(618,584));

    for( unsigned int i = 0; i<600; i++)
    {
        for(unsigned int j = 0; j<600; j++)
        {
            if(i==115 && j==95 || i==115 && j==185 ||i==157 && j==95||i==157 && j==230||i==451 && j==95 ||i==493 && j==185||
                    i==493 && j==95 || i==451 && j==230||i==115 && j==504 || i==157 && j==504||i==451 && j==504 || i==493 && j==504||
                    i==241 && j==315 || i==283 && j==315||i==325 && j==315 || i==367 && j==315||i==283 && j==459 || i==325 && j==459 )
            {
                maze_blocks.setScale(sf::Vector2f(0.01,0.07));
                maze_blocks.setFillColor(sf::Color::Blue);
                maze_blocks.setPosition(sf::Vector2f(i,j));
                maze.push_back(maze_blocks);
            }
            else if(i==73 && j==272 || i==73 && j==314 ||i==241 && j==314 || i==241 && j==350 ||i==325 && j==314 || i==325 && j==350 ||
                    i== 493 && j==272 || i==493 && j==314 ||i==157 && j==314 || i==409 && j==314||i==157 && j==185 || i==241 && j==185 ||
                    i==325 && j==185 || i==409 && j==185)
            {
                maze_blocks.setScale(sf::Vector2f(0.07,0.01));
                maze_blocks.setFillColor(sf::Color::Blue);
                maze_blocks.setPosition(sf::Vector2f(i,j));
                maze.push_back(maze_blocks);
            }
            else if(i==199 && j==186 || i==409 && j==186|| i==241 && j==186 || i==367 && j==186||i==115 && j==354 || i==157 && j==354
                    || i==241 && j==414 || i==367 && j==414||i==451 && j==354 || i==493 && j==354)
            {
                maze_blocks.setScale(sf::Vector2f(0.01,0.15));
                maze_blocks.setFillColor(sf::Color::Blue);
                maze_blocks.setPosition(sf::Vector2f(i,j));
                maze.push_back(maze_blocks);
            }
            else if(i == 199 && j ==95 || i == 325 && j == 95|| i == 199 && j ==539 || i == 325 && j == 539|| i==242 && j==272 || i==286 && j==272 )
            {
                maze_blocks.setScale(sf::Vector2f(0.14,0.01));
                maze_blocks.setFillColor(sf::Color::Blue);
                maze_blocks.setPosition(sf::Vector2f(i,j));
                maze.push_back(maze_blocks);
            }
            else if(i == 199 && j == 130)
            {
                maze_blocks.setScale(sf::Vector2f(0.35,0.01));
                maze_blocks.setFillColor(sf::Color::Blue);
                maze_blocks.setPosition(sf::Vector2f(i,j));
                maze.push_back(maze_blocks);
            }
            else if(i == 199 && j == 354 || i ==409 && j ==354 )
            {
                maze_blocks.setScale(sf::Vector2f(0.01,0.25));
                maze_blocks.setFillColor(sf::Color::Blue);
                maze_blocks.setPosition(sf::Vector2f(i,j));
                maze.push_back(maze_blocks);
            }
            else if(i==73 && j==315 || i==535 && j==314)
            {
                maze_blocks.setScale(sf::Vector2f(0.01,0.45));
                maze_blocks.setFillColor(sf::Color::Blue);
                maze_blocks.setPosition(sf::Vector2f(i,j));
                maze.push_back(maze_blocks);
            }
            else if(i==73 && j==56 || i==535 && j==56)
            {
                maze_blocks.setScale(sf::Vector2f(0.01,0.38));
                maze_blocks.setFillColor(sf::Color::Blue);
                maze_blocks.setPosition(sf::Vector2f(i,j));
                maze.push_back(maze_blocks);
            }
            else if(i==73 && j==573 || i==74 && j==56)
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

    sf::RectangleShape door_blocks(sf::Vector2f(618,584));

    for( unsigned int i = 0; i<600; i++)
    {
        for(unsigned int j = 0; j<600; j++)
        {

            if(i==73 && j==278 || i==115 && j==278|| i==157 && j==278 ||i==199 && j==278
                    ||  i==535 && j==278 || i==493 && j==278 || i==451 && j==278 || i==412 && j==278
                    || i==199 && j==96 || i==413 && j==96 || i==199 && j==539 || i==412 && j==539
              )
            {
                door_blocks.setScale(sf::Vector2f(0.005,0.07));
                door_blocks.setFillColor(sf::Color::Red);
                door_blocks.setPosition(sf::Vector2f(i,j));
                Doors.push_back(door_blocks);
            }
        }
    }
}
