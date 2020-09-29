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
        sf::Font textFont;
        sf::Text text;
    private:
        bool setText();

};

#endif // MAZE_H
