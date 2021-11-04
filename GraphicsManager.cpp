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


int GraphicsManager::Render(sf::RenderWindow* window,MouvManager* mManager,sf::Time time,vector<int> destroyed) {
    window->clear();
    window->draw(background);
    window->draw(*plate);
    tetromino->setX(mManager->currentPiece->mid);
    tetromino->changeTexture(mManager->currentPiece->color);
    sf::RectangleShape ghostrec(sf::Vector2f(32, 32));
    ghostrec.setOutlineColor(sf::Color::White);

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
    for (int i : destroyed) {
        for (int y = 0; y < mManager->plateau->nbCol; ++y) {
            ghostrec.setPosition(sf::Vector2f(512 + y * Block::TEXTURE_SIZE, 50 + i * Block::TEXTURE_SIZE));
            window->draw(ghostrec);
            
        }
    }

    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("Font/stocky.ttf"))
    {
        return 0;
    }

    text.setFont(font);
    text.setString("Score : "+to_string(mManager->points));
    text.setPosition(250, 600);
    text.setCharacterSize(40);
    window->draw(text);
    text.setString(to_string(mManager->level));
    text.setPosition(250, 500);
    text.setCharacterSize(80);
    window->draw(text);

    sf::RectangleShape r(sf::Vector2f(192,128));
    r.setFillColor(sf::Color(100, 100, 100, 150));
    r.setPosition(286, 68);
    window->draw(r);

    for (int* i : mManager->currentPiece->compoPiece) {
        tetromino->setX(512 + i[0] * Block::TEXTURE_SIZE);
        tetromino->setY(50 + ((i[1]-1+ time.asSeconds()*(mManager->speed)) * Block::TEXTURE_SIZE));
        window->draw(tetromino->sprite);
    } 


    Piece ghostpiece = *mManager->currentPiece;
    while (down(mManager->plateau,&ghostpiece))
    {
        ghostpiece.goDown();
    }
    
    ghostrec.setFillColor(sf::Color::Transparent );
    ghostrec.setOutlineThickness(1);

    for (int* i : ghostpiece.compoPiece) {
        ghostrec.setPosition(sf::Vector2f(512 + i[0] * Block::TEXTURE_SIZE, 50 + (i[1] * Block::TEXTURE_SIZE)));
        
        window->draw(ghostrec);
    }

    for (int* i : mManager->nextPiece->compoPiece) {
        blockplateau->changeTexture(mManager->nextPiece->color);
        if (mManager->nextPiece->piece == 3) {
            blockplateau->setX(222 + i[0] * Block::TEXTURE_SIZE);
            blockplateau->setY(120 + i[1] * Block::TEXTURE_SIZE);
        }
        else if (mManager->nextPiece->piece == 4) {
            blockplateau->setX(190 + i[0] * Block::TEXTURE_SIZE);
            blockplateau->setY(100 + i[1] * Block::TEXTURE_SIZE);
        }else{

            blockplateau->setX(205 + i[0] * Block::TEXTURE_SIZE);
            blockplateau->setY(100 + i[1] * Block::TEXTURE_SIZE);
        }

        window->draw(blockplateau->sprite);
    }
    

    window->display();
    return 1;
};

int GraphicsManager::RenderMenu(sf::RenderWindow* window,sf::Clock &c,int& menubutton) {
    sf::Text text;
    sf::Font font;
    vector<string> list = { "Jouer à Tetris","Jouer à Tetris 1942","Quitter" };

    if (!font.loadFromFile("Font/stocky.ttf"))
    {
        return 0;
    }
    
    window->clear();    
    window->draw(background);

    text.setCharacterSize(50);     
    sf::Color color(100, 100, 100,150);
    text.setFont(font);

    for (int i = 0; i < 3; ++i) {
        text.setString(list[i]);
        text.setPosition(400,i*100+200);
        text.setFillColor(sf::Color::White);

        if (i == menubutton && c.getElapsedTime().asMilliseconds() < 500) {
                text.setFillColor(color);
        }
        else {
        }
        window->draw(text);
    }
    

    
    window->display();
    return 1;
};