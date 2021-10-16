#include <SFML/Graphics.hpp>
#include "Block.h"
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 900), "Tetris 1945");

    sf::Texture texture;
    if (!texture.loadFromFile("Img/TextureTetris.png", sf::IntRect(0, 0, 512,512)))
    {
        return -1;
    }
    vector<Block *> tetromino(5);
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

        window.clear();
        window.draw(tetromino[0]->getSprite());
        

        window.display();
    }

    return 0;
}
