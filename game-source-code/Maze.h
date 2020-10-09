#ifndef MAZE_H
#define MAZE_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
class MazeLoaded{};
class Maze
{
    public:
        Maze();
         bool setText();
         //Last Comment
         //vectors to store the maze componets
        vector<sf::RectangleShape> maze;
        vector<sf::RectangleShape> Doors;
        sf::Font textFont;
        sf::Text text;
    private:

};

#endif // MAZE_H
