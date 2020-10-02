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
//New Test Cases
TEST_CASE("Check if the window is created")
{
    screen Window;
    CHECK(Window.render());
}

TEST_CASE ("Splash screen created")
{
    screen Screen;
    CHECK(Screen.splashScreen());
}


TEST_CASE ("Maze has been printed")
{
    screen maze;
    CHECK(maze.printMaze());
}

/*TEST_CASE ("The score text is displayed")
{
    screen score;
    CHECK(score.scoreTexts()==0);
    CHECK(score.printScores());

}*/


/*
TEST_CASE ("Fruits are loaded")
{
    screen fruits;
    CHECK(fruits.createFruits());
}


TEST_CASE ("Checks High Score text")
{
    Maze text;
    CHECK(text.setText());
}

TEST_CASE ("Event Created")
{
    screen event;
    CHECK(event.processEvents());
}

TEST_CASE("Check if pacmann is drawn on the window")
{
    screen pacman;
    CHECK(pacman.pacM());
}

TEST_CASE("Check ii ghosts are drawn on the window")
{
    screen ghosts;
    CHECK(ghosts.Ghosts());
}

TEST_CASE("Keys have been loaded to the maze")
{
    screen keys;
    CHECK(keys.createKeys());
}*/
