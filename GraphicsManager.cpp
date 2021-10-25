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


int GraphicsManager::Render(sf::RenderWindow* window,MouvManager* mManager,sf::Time time) {
    window->clear();
    window->draw(background);
    window->draw(*plate);
    tetromino->setX(mManager->currentPiece->mid);
    tetromino->changeTexture(mManager->currentPiece->color);

   ;

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

    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("Font/stocky.ttf"))
    {
        return 0;
    }

    text.setFont(font);
    text.setString("Score : " + mManager->points);
    text.setPosition(250, 600);
    text.setCharacterSize(40);
    window->draw(text);

    for (int* i : mManager->currentPiece->compoPiece) {
        tetromino->setX(512 + i[0] * Block::TEXTURE_SIZE);
        tetromino->setY(50 + ((i[1]-1+ time.asSeconds()*(mManager->speed)) * Block::TEXTURE_SIZE));
        window->draw(tetromino->sprite);
    } 

    

    window->display();
    return 1;
};

int GraphicsManager::RenderMenu(sf::RenderWindow* window,sf::Clock &c) {
    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("Font/stocky.ttf"))
    {
        return 0;
    }

    text.setFont(font);
    text.setString("Press P to start");
    text.setPosition(400,300);
    text.setCharacterSize(50); 

    if (c.getElapsedTime().asMilliseconds() > 500) {
        text.setFillColor(sf::Color::Black);
    }
    else {
        text.setFillColor(sf::Color::White);
    }
    window->clear();    
    window->draw(background);
    window->draw(text);
    window->display();
    return 1;
};