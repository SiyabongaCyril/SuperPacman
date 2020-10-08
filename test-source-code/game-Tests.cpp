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

    CHECK(ball.SuperBalls.size()== 2);
    CHECK(ball.Balls.size()==4);

}
//pallets radius
TEST_CASE("Check the radius of pallets")
{
    screen radius;
    //The radius of all normal pallets on the maze is 10
    CHECK(radius.Balls[0].getRadius()==10);
    CHECK(radius.Balls[1].getRadius()==10);
    CHECK(radius.Balls[2].getRadius()==10);
    CHECK(radius.Balls[3].getRadius()==10);

    //The radius of all superpallets on the maze is 12
    CHECK(radius.SuperBalls[0].getRadius()==12);
    CHECK(radius.SuperBalls[1].getRadius()==12);
}

//New Test Cases
//Test Case Recommit
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

TEST_CASE ("The score text is displayed")
{
    screen score;
    CHECK(score.scoreTexts()==0);
    CHECK(score.printScores());

}


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
}

TEST_CASE("The ghosts change after a normal pallets has been eaten by pacman")
{
    screen pallets;
    CHECK(pallets.drunkGhosts());
}
