#include "screen.h"
#include "ResourcesManager.h"
#include "Maze.h"
//#include "doctest.h"

screen::screen():window(sf::VideoMode(630,650),"Super Pacman"),SuperBalls()
{

    splashScreen();

    //Load Pallets
    //Loads Power Pallets
    //uses a vector to store pallets with their specific coordinates
    sf::CircleShape  superB;

    for( unsigned int i = 0; i<600; i++)
    {
        for(unsigned int j = 0; j<600; j++)
        {

            if(i == 130 && j==105 || i ==465 && j == 105||
                    i == 130 && j==515 || i == 465 && j == 515)
            {
                superB.setRadius(10);
                superB.setFillColor(sf::Color::Blue);
                superB.setPosition(sf::Vector2f(i,j));
                SuperBalls.push_back(superB);
            }
            else if(i == 210 && j ==374 || i == 370 && j == 374)
            {
                superB.setRadius(15);
                superB.setFillColor(sf::Color::Green);
                superB.setPosition(sf::Vector2f(i,j));
                SuperBalls.push_back(superB);
            }
        }
    }

}
//Window Setup
void screen::run()
{
    clock.restart();
    while(window.isOpen())
    {
        processEvents();
        render();
    }
}

void screen::processEvents()
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
            if(event.key.code == sf::Keyboard::Enter)
                start = true;
        default:
            break;
        }
    }
}

void screen::render()
{
    //loads picture and stores it as a sprite
    //Animate PacMan
    ResourcesManager manager;
   /* sf::Texture texture;
    if(!texture.loadFromFile("resources/pacman.png"))
    {
cout<<"PacMan Not Loaded"<<endl;
    }
    sf::Sprite PacMan;
    PacMan.setTexture(texture);
    PacMan.scale(sf::Vector2f(0.027,0.027));*/

    sf::IntRect rectPac(900,0,900,1000);
    sf::Sprite PacMan(ResourcesManager::GetTexture("resources/pacman.png"));
    PacMan.setTextureRect(rectPac);
    PacMan.scale(sf::Vector2f(0.027,0.027));
    PacMan.setPosition(sf::Vector2f(80,65));

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

        float deltaTime = clock.restart().asSeconds();

        //scales PacMan to the desired size
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            //PacMan.move(sf::Vector2f(10, 0));
            PacMan.setPosition(sf::Vector2f(80+pos*deltaTime,65));
        }

        //Divides the PacMan sprite into two
        //Allocates time and switches between sections of sprite to create animation
       if (clock.getElapsedTime().asMilliseconds() > 100.0f)
        {
            if(rectPac.left == 900)
            {
                rectPac.left = 0;
            }
            else
                rectPac.left +=900;
            PacMan.setTextureRect(rectPac);

            if (clock.getElapsedTime().asMilliseconds() > 200.0f)
                clock.restart();
        }

        window.clear(sf::Color::Black);
printMaze();
        window.draw(PacMan);
    }
    else
    {
        //splashscreen draw variables on window if in splashhscreen mode
        window.draw(startUpMessage);
        window.draw(SplashScreenPacMan);
    }
    window.display();
}


bool screen::splashScreen()
{

    //Initialise pre-game window
    /*
    Load Text Font
    Set up text to be written on the splashcreen
    */
    font.loadFromFile("resources/ostrich-regular.ttf");
    if(!font.loadFromFile("resources/OstrichSans-Medium.otf"))
        return EXIT_FAILURE;

    startUpMessage.setFont(font);
    startUpMessage.setCharacterSize(20);
    startUpMessage.setPosition(30.f, 50.f);
    startUpMessage.setFillColor(sf::Color::White);
    startUpMessage.setString("Welcome to Super Pac-Man\n\nPress Enter to start the game, Esc to exit\n\nTo play the game, use the arrow keys: Down, Up, Left, Right ");
    return true;
}

bool screen::printMaze()
{
    Maze getFunction;

            for(int k = 0; k<getFunction.Doors.size(); k++)
        {
            window.draw(getFunction.Doors[k]);
        }
        for(int j = 0; j<getFunction.maze.size(); j++)
        {
            window.draw(getFunction.maze[j]);
        }
        for(int i = 0; i<SuperBalls.size(); i++)
        {
            window.draw(SuperBalls[i]);
        }

        return true;
}
