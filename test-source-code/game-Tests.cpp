#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
#include <vector>
#include "screen.h"
#include "ResourcesManager.h"
#include "Maze.h"


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

//Test Case

TEST_CASE("Check if there are 6 pallets on the maze")
{
    screen ball;

    CHECK(ball.SuperBalls.size()== 6);

}

