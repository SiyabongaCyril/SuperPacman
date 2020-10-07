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

    screen pop;
    pop.run();
    return EXIT_SUCCESS;
    }
