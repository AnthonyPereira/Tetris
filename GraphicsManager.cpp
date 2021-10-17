#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

#include "GraphicsManager.h"
#include "Block.h"


GraphicsManager::GraphicsManager() {
    tetromino = new Block();

};


int GraphicsManager::Render(sf::RenderWindow* window) {
    if (tetromino->getY() < 650)
        tetromino->setY(tetromino->getY() + 0.1);
    else {
        tetromino->setY(0);
        tetromino->changeTexture(rand() % 5);
    }

    window->clear();
    window->draw(background);
    int X = tetromino->getX();
    for (int i = 0; i < 4; ++i) {
        tetromino->setX(X+Block::TEXTURE_SIZE*i);
        window->draw(tetromino->sprite);
    }
    tetromino->setX(X);
    window->display();
    return 1;
};