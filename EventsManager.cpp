#include <SFML/Graphics.hpp>
#include "EventsManager.h"
#include "MouvManager.h"
#include <iostream>
#include "Block.h"



void EventsManager::analyseEvent(sf::Event* event,MouvManager* mManager, sf::RenderWindow* window) {
    switch (event->type)
    {

        case sf::Event::Resized:
            window->setSize(sf::Vector2u(window->getSize().x, window->getSize().x * 0.5625));

            break;
        case sf::Event::Closed:
            window->close();
            break;

            // touche pressée
        case sf::Event::KeyPressed:
            switch (event->key.code) {
            case sf::Keyboard::D:
                mManager->goRight();
                break;
            case sf::Keyboard::Q:
                mManager->goLeft();
                break;
            case sf::Keyboard::Z:
                mManager->turnLeft();
                break;
            case sf::Keyboard::S:
                mManager->goDown();
                break;
            default:
                break;
            }
            break;

        default:
            break;
    }
}


void EventsManager::MenuEvent(sf::Event* event, sf::RenderWindow* window,int &gamestatus) {

    switch (event->type)
    {
    case sf::Event::Resized:
        window->setSize(sf::Vector2u(window->getSize().x, window->getSize().x * 0.5625));

        break;
    case sf::Event::Closed:
        window->close();
        break;

        // touche pressée
    case sf::Event::KeyPressed:
        switch (event->key.code) {
        case sf::Keyboard::P:
            gamestatus=1;
            break;
        default:
            break;
        }    
        
    default:
        break;
    }
}
