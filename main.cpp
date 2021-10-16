#include <SFML/Graphics.hpp>
#include "Block.h"
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 900), "Tetris 1945");

    sf::Texture texture;
    if (!texture.loadFromFile("Img/TextureTetris.png"))
    {
        return -1;
    }
    vector<Block *> tetromino(4);
    Block b(0,0, &texture);
    tetromino[0]=&b;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(tetromino[0]->getY()<600)
            tetromino[0]->setY(tetromino[0]->getY() + 0.1);
        else {
            tetromino[0]->setY(0);
            tetromino[0]->changeTexture(rand()%5);
        }


        window.clear();
        for (int i = 0; i < 4; i++) {
            tetromino[0]->setX((Block::TEXTURE_SIZE)*i);
            window.draw(tetromino[0]->getSprite());
        }
        


        window.display();
    }

    return 0;
}
