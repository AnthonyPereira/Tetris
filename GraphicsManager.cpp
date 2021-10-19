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
        tetromino->setY(tetromino->getY() + 0.3);
    else {
        tetromino->setY(0);
        tetromino->changeTexture(rand() % 5);
    }
    int compoPiece[4][3] = { {0,1},
                             {1,1},
                             {1,0},
                             {2,0}};


    window->clear();    //verifier si on peut clear uniquement les blocks
    window->draw(background);
    int X = tetromino->getX();
    int Y = tetromino->getY();

    for (int* i : compoPiece) {
        tetromino->setX(i[0] * Block::TEXTURE_SIZE);
        tetromino->setY(i[1] * Block::TEXTURE_SIZE);

        window->draw(tetromino->sprite);
    }
    tetromino->setX(X);
    tetromino->setY(Y);

    window->display();
    return 1;
};