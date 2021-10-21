#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

#include "GraphicsManager.h"
#include "MouvManager.h"

#include "Block.h"


GraphicsManager::GraphicsManager() {
    tetromino = new Block();
};


int GraphicsManager::Render(sf::RenderWindow* window,MouvManager* mManager) {
   


    window->clear();    //verifier si on peut clear uniquement les blocks
    window->draw(background);
    window->draw(*plate);
    tetromino->setX(mManager->currentPiece->mid);

    for (int* i : mManager->currentPiece->compoPiece) {
        tetromino->setX(512+i[0] * Block::TEXTURE_SIZE);
        tetromino->setY(50+i[1] * Block::TEXTURE_SIZE);

        window->draw(tetromino->sprite);
    }

    window->display();
    return 1;
};