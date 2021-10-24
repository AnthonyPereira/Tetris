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

    if (time.asSeconds() > 1) {
        mManager.goDown();
        c.restart();
    }


    gManager.Render(&window, &mManager);
}

void menu(sf::RenderWindow& window, sf::Clock& c, GraphicsManager& gManager, EventsManager& eManager, MouvManager& mManager) {
    sf::Event event;
    sf::Time time = c.getElapsedTime();

    while (window.pollEvent(event))
    {
        eManager.analyseEvent(&event, &mManager, &window);
    }

    if (time.asSeconds() > 1) {
        c.restart();
    }


    gManager.RenderMenu(&window);
}

int main(){
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Tetris 1945", sf::Style::Titlebar | sf::Style::Close);
    window.setKeyRepeatEnabled(false);
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
    sf::RectangleShape r(sf::Vector2f(320, 640));
    r.setFillColor(sf::Color(100, 100, 100,150));
    r.setPosition(512, 50);
    gManager.plate = &r;
    gManager.blockplateau->sprite.setTexture(texture);
    gManager.tetromino->sprite.setTexture(texture);
    sf::Clock c;
    int gameStatus=0;

    while (window.isOpen())
    {    
        if (gameStatus) {
            jeu(window, c, gManager, eManager, mManager);
        }
        else {
            menu(window, c, gManager, eManager, mManager);
        }

    }
    return 0;
}



