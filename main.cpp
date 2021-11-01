#include <SFML/Graphics.hpp>
#include <iostream>
#include "GraphicsManager.h"
#include "MouvManager.h"
#include "EventsManager.h"

using namespace std;

void jeu(sf::RenderWindow& window, sf::Clock& c, GraphicsManager& gManager, EventsManager& eManager, MouvManager& mManager) {
    sf::Event event;
    sf::Time time = c.getElapsedTime();

    while (window.pollEvent(event))
    {
        eManager.analyseEvent(&event, &mManager, &window);
    }

    gManager.Render(&window, &mManager, time);


    if (time.asSeconds() > mManager.delta ) {
        c.restart();
        mManager.goDown();
    }   


}

void menu(sf::RenderWindow& window, sf::Clock& c, GraphicsManager& gManager, EventsManager& eManager,int &gamestatus) {
    sf::Event event;
    sf::Time time = c.getElapsedTime();

    while (window.pollEvent(event))
    {
        eManager.MenuEvent(&event,&window,gamestatus);
    }

    if (time.asSeconds() > 1) {
        c.restart();
    }


    gManager.RenderMenu(&window,c);
}

int main(){
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Tetris 1945");
    //window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(60);
    GraphicsManager gManager;
    EventsManager eManager;
    MouvManager mManager(5,20,10);
    
    sf::Texture texture,background;
    if (!background.loadFromFile("Img/Background.png"))
        return -1;
    if (!texture.loadFromFile("Img/TextureTetris.png"))
        return -1;

    gManager.background.setTexture(background);
    gManager.background.setScale(sf::Vector2f(0.5,0.5));
    sf::RectangleShape r(sf::Vector2f(320, 672));
    r.setFillColor(sf::Color(100, 100, 100,150));
    r.setPosition(512, 20);
    gManager.plate = &r;
    gManager.blockplateau->sprite.setTexture(texture);
    gManager.tetromino->sprite.setTexture(texture);
    sf::Clock c;
    int gameStatus(0);
    /*
    float fps;
    sf::Clock clock = sf::Clock::Clock();
    sf::Time previousTime = clock.getElapsedTime();
    sf::Time currentTime;
    */

    while (window.isOpen())
    {    
        if (gameStatus==1) {
            jeu(window, c, gManager, eManager, mManager);
            if (mManager.verifLose()) {
                gameStatus = 2;
                mManager.resetGame(5,20,10);
            }
        }
        else {
            menu(window, c, gManager, eManager, gameStatus);
        }
        /*
        currentTime = clock.getElapsedTime();
        fps = 1.0f / (currentTime.asSeconds() - previousTime.asSeconds());
        std::cout << "fps =" << floor(fps) << std::endl;
        previousTime = currentTime;
        */
    }
    return 0;
}



