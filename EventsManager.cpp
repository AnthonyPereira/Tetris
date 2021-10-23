#include <SFML/Graphics.hpp>
#include "EventsManager.h"
#include "MouvManager.h"

#include "Block.h"



void EventsManager::analyseEvent(sf::Event* event,MouvManager* mManager, sf::RenderWindow* window) {
    switch (event->type)
    {
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
