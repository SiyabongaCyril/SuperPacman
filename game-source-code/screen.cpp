#include "screen.h"
#include "ResourcesManager.h"
#include "Maze.h"
#include <iostream>

#include <string>

using namespace std;

screen::screen():window(sf::VideoMode(630,650),"Super Pacman"),SuperBalls()
{

    //Declare splash screen icons
    splashScreen();

    //set text for the scores
    scoreTexts();

    //Load Pallets
    //Loads Power Pallets
    //uses a vector to store pallets with their specific coordinates
    sf::CircleShape  superB;

    for( unsigned int i = 0; i<600; i++)
    {
        for(unsigned int j = 0; j<600; j++)
        {

            if(i == 130 && j==115 || i ==465 && j == 115||
                    i == 130 && j==495 || i == 465 && j == 495)
            {
                superB.setRadius(10);
                superB.setFillColor(sf::Color::Blue);
                superB.setPosition(sf::Vector2f(i,j));
                SuperBalls.push_back(superB);
            }
            else if(i == 210 && j ==364 || i == 375 && j == 364)
            {
                superB.setRadius(12);
                superB.setFillColor(sf::Color::Green);
                superB.setPosition(sf::Vector2f(i,j));
                SuperBalls.push_back(superB);
            }
        }
    }

}
//Window Setup
bool screen::run()
{
    clock.restart();
    pacTimer.restart();
    while(window.isOpen())
    {
        processEvents();
        render();
    }
    return true;
}

bool screen::processEvents()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::EventType::Closed: //Called when the x icon on window is pressed
            window.close();
            break;
        case sf::Event::EventType::KeyPressed: //called whenever a key is pressed (Keeps track of all the keys)
            if(event.key.code == sf::Keyboard::Escape)
                window.close(); //key can be closed by close button and space
            if(event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Space)
                start = true;

            //Events to control pacMan
            if(event.key.code == sf::Keyboard::Right)
                moving = true;
            stop = false;
            if(event.key.code == sf::Keyboard::Up)
                moving = true;
            stop = false;
            if(event.key.code == sf::Keyboard::Down)
                moving = true;
            stop = false;
            if(event.key.code == sf::Keyboard::Left)
                moving = true;
            stop = false;
            break;

        case sf::Event::EventType::KeyReleased: //called when a key is released
            if(event.key.code == sf::Keyboard::Right)
                moving = false;
            if(event.key.code == sf::Keyboard::Up)
                moving = false;
            if(event.key.code == sf::Keyboard::Down)
                moving = false;
            if(event.key.code == sf::Keyboard::Left)
                moving = false;
            break;

        default:
            break;
        }
    }
    //throw EventDeclared{};
    return true;
}

bool screen::render()
{
    ResourcesManager manager;

    //loads picture and stores it as a sprite
    //Animate PacMan

    sf::IntRect rectPac(900,0,900,1000);
    sf::Sprite SplashScreenPacMan(ResourcesManager::GetTexture("resources/pacman.png"));

    //declaring pack man icon to display on the splashscreen
    if(!start)
    {
        //scales PacMan to the desired size
        SplashScreenPacMan.setTextureRect(rectPac);
        SplashScreenPacMan.setPosition(sf::Vector2f(194.f,47.5));

        SplashScreenPacMan.scale(sf::Vector2f(0.027,0.027));

        if (clock.getElapsedTime().asMilliseconds() > 100.0f)
        {
            if(rectPac.left == 900)
            {
                rectPac.left = 0;
            }
            else
                rectPac.left +=900;
            SplashScreenPacMan.setTextureRect(rectPac);

            if (clock.getElapsedTime().asMilliseconds() > 200.0f)
                clock.restart();
        }
    }

    //Start the game mode if the player enters the game mode
    if(start)
    {

        window.clear(sf::Color::Black);
        printMaze();
        pacM();
        createFruits();
        createKeys();
        Ghosts();

        printScores();
    }
    else
    {
        //splashscreen draw variables on window if in splashhscreen mode
        window.draw(startUpMessage);
        window.draw(SplashScreenPacMan);
    }
    window.display();
    return true;
}

bool screen::splashScreen()
{
    //Initialise pre-game window
    //Load Text Font
    //Set up text to be written on the splashcreen
    if(!font.loadFromFile("resources/OstrichSans-Medium.otf"))
        return EXIT_FAILURE;

    startUpMessage.setFont(font);
    startUpMessage.setCharacterSize(20);
    startUpMessage.setPosition(30.f, 50.f);
    startUpMessage.setFillColor(sf::Color::White);
    startUpMessage.setString("Welcome to Super Pac-Man\n\nPress Enter/Space to start the game, Esc to exit\n\nTo play the game, use the arrow keys: Down, Up, Left, Right ");
    return true;
}

bool screen::pacM()
{
   //pacman function
    ResourcesManager manager;

    Maze getFunction;

    sf::IntRect rectPac(900,0,900,1000);
    sf::Sprite PacMan(ResourcesManager::GetTexture("resources/pacman.png"));
    PacMan.setTextureRect(rectPac);
    PacMan.scale(sf::Vector2f(0.025,0.025));

    if(create_pacman == 0)
    {
        PacMan.setPosition(sf::Vector2f(273,74));
        create_pacman = 1;
    }
    else
        PacMan.setPosition(position);

    if(moving && start)
        check = true;

    position = PacMan.getPosition();

    for(unsigned int k=0; k<getFunction.maze.size(); k++)
    {
        if (check && !stop)
        {

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            {

                if(PacMan.getGlobalBounds().intersects(getFunction.maze[k].getGlobalBounds()))
                {
                    cout<<"collision"<<endl;
                    stop = true;
                    PacMan.setPosition(position);
                }
                else
                {
                    PacMan.move(sf::Vector2f(0,0.1));
                    trackDown = true;
                    trackRight = false;
                    trackLeft = false;
                    trackUp = false;
                }

            }
            else if(trackDown)
            {
                if(PacMan.getGlobalBounds().intersects(getFunction.maze[k].getGlobalBounds()))
                {
                    stop = true;
                    PacMan.setPosition(position);
                    cout<<"collision"<<endl;
                }
                else
                {
                    PacMan.move(sf::Vector2f(0,0.1));
                }

            }

            //Move the object
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            {
                if(PacMan.getGlobalBounds().intersects(getFunction.maze[k].getGlobalBounds()))
                {
                    stop = true;
                    PacMan.setPosition(position);
                    cout<<"collision"<<endl;
                }
                else
                {
                    PacMan.move(sf::Vector2f(0.1,0));
                    trackRight = true;
                    trackLeft = false;
                    trackDown = false;
                    trackUp = false;
                }

            }
            else if(trackRight)
            {
                if(PacMan.getGlobalBounds().intersects(getFunction.maze[k].getGlobalBounds()))
                {
                    stop = true;
                    PacMan.setPosition(position);
                    cout<<"collision"<<endl;
                }
                else
                {
                    PacMan.move(sf::Vector2f(0.1,0));
                }

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            {
                if(PacMan.getGlobalBounds().intersects(getFunction.maze[k].getGlobalBounds()))
                {
                    stop = true;
                    PacMan.setPosition(position);
                    cout<<"collision"<<endl;
                }
                else
                {
                    PacMan.move(sf::Vector2f(0, -0.1));
                    trackUp = true;
                    trackRight = false;
                    trackLeft = false;
                    trackDown = false;
                }

            }
            else if(trackUp)
            {
                if(PacMan.getGlobalBounds().intersects(getFunction.maze[k].getGlobalBounds()))
                {
                    stop = true;
                    PacMan.setPosition(position);
                    cout<<"collision"<<endl;
                }
                else
                {
                    PacMan.move(sf::Vector2f(0,-0.1));
                }

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            {
                if(PacMan.getGlobalBounds().intersects(getFunction.maze[k].getGlobalBounds()))
                {
                    stop = true;
                    PacMan.setPosition(position);
                    cout<<"collision"<<endl;
                }
                else
                {
                    PacMan.move(sf::Vector2f(-0.1,0));
                    trackLeft = true;
                    trackRight = false;
                    trackDown = false;
                    trackUp = false;
                }

            }
            else if(trackLeft)
            {
                if(PacMan.getGlobalBounds().intersects(getFunction.maze[k].getGlobalBounds()))
                {
                    stop = true;
                    PacMan.setPosition(position);
                    cout<<"collision"<<endl;
                }
                else
                {
                    PacMan.move(sf::Vector2f(-0.1,0));
                }

            }
        }

        position = PacMan.getPosition();
    }

    for(unsigned int k=0; k<Keys.size(); k++)
    {
        if(PacMan.getGlobalBounds().intersects(Keys[k].getGlobalBounds()))
        {

            Keys.erase( Keys.begin() + k);

            ManageDoors.erase( ManageDoors.begin() + track_doors) ;
            track_doors +1;

        }
    }

    for(unsigned int k=0; k<Fruits.size(); k++)
    {
        if(PacMan.getGlobalBounds().intersects(storeFruits[k].getGlobalBounds()))
        {

            storeFruits.erase( storeFruits.begin() + k);
            ++score;
        }
    }

    window.draw(PacMan);

    return true;
}

bool screen::Ghosts()
{
    //Load ghosts
    //store ghosts
    //Load ghosts and display them in the game-mode window in the maize (at the middle of the maize)
    ResourcesManager manager;
    Maze getFunction;

    sf::Sprite red(ResourcesManager::GetTexture("resources/redGhost.png"));
    red.scale(sf::Vector2f(0.19,0.19));

    sf::Sprite pink(ResourcesManager::GetTexture("resources/pinkGhost.png"));
    pink.scale(sf::Vector2f(0.19,0.19));

    sf::Sprite orange(ResourcesManager::GetTexture("resources/orangeGhost.png"));
    orange.scale(sf::Vector2f(0.19,0.19));

    sf::Sprite blue(ResourcesManager::GetTexture("resources/blueGhost.png"));
    blue.scale(sf::Vector2f(0.19,0.19));
//Ghost Movement
    if(create_ghosts == 0)
    {
        red.setPosition(sf::Vector2f(255,200));
        pink.setPosition(sf::Vector2f(329,200));
        orange.setPosition(sf::Vector2f(255,234));
        blue.setPosition(sf::Vector2f(329,234));
        ++create_ghosts;
    }
    else
    {
        red.setPosition(RedPos);
        blue.setPosition(BluePos);
        pink.setPosition(PinkPos);
        orange.setPosition(OrangePos);
    }

    if(trackDown|| trackLeft||trackRight||trackUp)
    {
        for (unsigned i = 0; i<getFunction.maze.size(); i++)
        {
            if(red.getGlobalBounds().intersects(getFunction.maze[i].getGlobalBounds()))
            {
                moveGhost =false;
                cout<<"Collision"<<endl;
            }

            if(moveGhost)
            {
                if(trackLeft)
                {
                    red.move(sf::Vector2f(0,-0.1));
                }
                else if(trackUp)
                {
                    red.move(sf::Vector2f(0,0.1));
                }
                else if(trackDown)
                {
                    red.move(sf::Vector2f(-0.1,0));
                }
                else if(trackRight)
                {
                    red.move(sf::Vector2f(0.1,0));
                }

                // blue.move(sf::Vector2f(10,0));
                // orange.move(sf::Vector2f(0,10));
                //pink.move(sf::Vector2f(-10,0));
            }
            else if(!moveGhost)
            {
                red.move(sf::Vector2f(0,0));
                collision =true;
            }

            if(collision)
            {
                if(trackLeft)
                {
                    red.move(sf::Vector2f(0,0.1));
                }
                else if(trackUp)
                {
                    red.move(sf::Vector2f(0,-0.1));
                }
                else if(trackDown)
                {
                    red.move(sf::Vector2f(0.1,0));
                }
                else if(trackRight)
                {
                    red.move(sf::Vector2f(-0.1,0));
                }
                collision =false;
                //moveGhost =true;
            }
        }
    }
    RedPos = red.getPosition();
    BluePos = blue.getPosition();
    PinkPos = pink.getPosition();
    OrangePos = orange.getPosition();

    window.draw(red);
    window.draw(pink);
    window.draw(orange);
    window.draw(blue);

    return true;
    //throw GhostsDrawn{};
}

bool screen::createKeys()
{
    ResourcesManager manager;

    //load sprite for keys, display it on the maize in the game-mode window
    sf::Sprite key(ResourcesManager::GetTexture("resources/key.png"));

    for( unsigned int i = 0; i<600; i++)
    {
        for(unsigned int j = 0; j<600; j++)
        {

            sf::Sprite key(ResourcesManager::GetTexture("resources/key.png"));

            if(i == 85 && j== 75 || i == 510 && j == 75 || i == 85 && j == 525 || i == 510 && j ==  525 ||
                    i == 85 && j ==  240 || i == 510 && j ==  240 ||   i == 85 && j ==  325 || i == 510 && j ==  325 ||
                    i == 170 && j ==  150 || i == 425 && j ==  150 || i == 170 && j ==  490 || i == 425 && j ==  490
                    || i == 215 && j ==  325 || i == 380 && j ==  325 || i == 300 && j == 405)
            {

                if(create_keys == 0)
                {
                    key.scale(sf::Vector2f(0.128,0.128));
                    key.setPosition(sf::Vector2f(i,j));
                    Keys.push_back(key);
                }
            }
        }
    }

    create_keys = 1;

    for(int k = 0; k<Keys.size(); k++)
    {
        window.draw(Keys[k]);
    }
    //throw KeysLoaded{};
    return true;
}

bool screen::createFruits()
{
    ResourcesManager manager;

    //Load Sprite for fruits, initialise fruits, store them in a vector and display them on the game-mode window

    for( unsigned int i = 0; i<600; i++)
    {
        for(unsigned int j = 0; j<600; j++)
        {

            sf::Sprite pear(ResourcesManager::GetTexture("resources/pear.png"));

            if(i == 210 && j== 113 || i == 240 && j == 113 || i == 240 && j == 113 || i == 270 && j == 113 || i == 300
                    && j == 113 || i == 330 && j == 113 || i == 360 && j == 113 || i == 390 && j == 113 || i == 170 && j == 195 ||
                    i == 130 && j == 195 || i == 425 && j == 195 || i ==  465 &&  j  == 195 || i ==  170 &&  j  == 235 ||
                    i ==  170 &&  j  == 275 || i ==  425 &&  j  == 235 || i ==  425 &&  j  == 275  || i ==  465 &&  j  == 400 ||
                    i ==  465 &&  j  == 360  || i ==  465 &&  j  == 400|| i ==  465 &&  j  == 360  || i ==  465 &&  j  == 400 ||
                    i ==  465 &&  j  == 360   || i ==  130 &&  j  == 400 || i ==  130 &&  j  == 360 || i == 210 && j== 525 ||
                    i == 240 && j == 525 || i == 240 && j == 525 || i == 270 && j == 525 || i == 300 && j == 525 ||
                    i == 330 && j == 525 || i == 360 && j == 525 || i == 390 && j == 525 || i == 295 && j == 445 ||
                    i == 210 && j == 445 || i == 380 && j == 445 ||  i == 210 && j == 405 || i == 380 && j == 405 ||
                    i == 250 && j == 360 || i == 340 && j == 360)
            {

                if(create_fruits == 0)
                {
                    pear.scale(sf::Vector2f(0.12,0.12));
                    pear.setPosition(sf::Vector2f(i,j));
                    Fruits.push_back(pear);
                    storeFruits.push_back(pear);
                }

            }
        }
    }

    if(check!=0)
    {
        for(int k = 0; k<storeFruits.size(); k++)
        {
            window.draw(storeFruits[k]);
        }
    }
    else
    {
        for(int k = 0; k<storeFruits.size(); k++)
        {
            window.draw(storeFruits[k]);
        }
    }

    create_fruits = 1;

    //throw fruitsLoaded{};
    return true;
}

bool screen::printScores()
{
    //Convert new scores to strings, load them into the sf text variables and display them on the game-mode window
    numToStr = to_string(score);

    scoreText.setString(numToStr);

    window.draw(scoreText);

    numToStr = to_string(high_score);

    numToStr = to_string(score);

    highScoreText.setString(numToStr);

    window.draw(highScoreText);
    //throw scoreShows{};
    return true;
}

bool screen::printMaze()
{
    Maze getFunction;

    if(create_doors == 0)
    {
        for(int k = 0; k<getFunction.Doors.size(); k++)
        {
            window.draw(getFunction.Doors[k]);
            ManageDoors.push_back(getFunction.Doors[k]);
        }

        create_doors = 1;
    }
    else
    {
        for(int k = 0; k<ManageDoors.size(); k++)
        {
            window.draw(ManageDoors[k]);
        }
    }

    for(int j = 0; j<getFunction.maze.size(); j++)
    {
        window.draw(getFunction.maze[j]);
    }
    for(int i = 0; i<SuperBalls.size(); i++)
    {
        window.draw(SuperBalls[i]);
    }

    window.draw(getFunction.text);

    return true;
}

int screen::scoreTexts()
{
    //Load font and set text for the scores
    if(!scoreFont.loadFromFile("resources/OstrichSans-Bold.otf"))
        return EXIT_FAILURE;

    scoreText.setFont(scoreFont);
    scoreText.setCharacterSize(20);
    scoreText.setPosition(73,25);
    scoreText.setFillColor(sf::Color::White);

    highScoreText.setFont(scoreFont);
    highScoreText.setCharacterSize(20);
    highScoreText.setPosition(273,25);
    highScoreText.setFillColor(sf::Color::White);

    return 0;
}

/*if (clock.getElapsedTime().asMilliseconds() > 100.0f)
        {
            if(rectPac.left == 900)
            {
                rectPac.left = 0;
            }
            else
                rectPac.left +=900;
            PacMan.setTextureRect(rectPac);

            if (pacTimer.getElapsedTime().asMilliseconds() > 150.0f)
                pacTimer.restart();
        }*/
//Divides the PacMan sprite into two
//Allocates time and switches between sections of sprite to create animation */
