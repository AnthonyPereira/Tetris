#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

#include "GraphicsManager.h"
#include "MouvManager.h"
#include <iostream>
#include "Block.h"


GraphicsManager::GraphicsManager() {
    tetromino = new Block();
    blockplateau = new Block();

};


int GraphicsManager::Render(sf::RenderWindow* window,MouvManager* mManager) {
   


    //window->clear();    //verifier si on peut clear uniquement les blocks
    window->draw(background);
    window->draw(*plate);
    tetromino->setX(mManager->currentPiece->mid);
    tetromino->changeTexture(mManager->currentPiece->color);

    for (int x=0; x < mManager->plateau->nbLine ; ++x) {
        for (int y=0; y < mManager->plateau->nbCol ; ++y) {
            if (mManager->plateau->plateau[x][y] !=0) {
                blockplateau->changeTexture(mManager->plateau->plateau[x][y]);
                blockplateau->setX(512 + y * Block::TEXTURE_SIZE);
                blockplateau->setY(50 + x * Block::TEXTURE_SIZE);
                window->draw(blockplateau->sprite);

            }
        }
    }
    

    for (int* i : mManager->currentPiece->compoPiece) {
        tetromino->setX(512+i[0] * Block::TEXTURE_SIZE);
        tetromino->setY(50+i[1] * Block::TEXTURE_SIZE);

        window->draw(tetromino->sprite);
    }

    window->display();
    return 1;
};