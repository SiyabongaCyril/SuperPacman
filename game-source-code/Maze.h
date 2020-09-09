#ifndef MAZE_H
#define MAZE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
class Maze
{
    public:
        Maze();
        void MazeDoors();
        vector<sf::RectangleShape> maze;
        vector<sf::RectangleShape> Doors;

    private:
};

#endif // MAZE_H
