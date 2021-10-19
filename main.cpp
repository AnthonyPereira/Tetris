#include <SFML/Graphics.hpp>
#include "GraphicsManager.h"
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Tetris 1945", sf::Style::Titlebar | sf::Style::Close);
    window.setKeyRepeatEnabled(false);
    GraphicsManager gManager;
    sf::Texture texture,background;
    if (!background.loadFromFile("Img/Background.png"))
        return -1;
    if (!texture.loadFromFile("Img/TextureTetris.png"))
        return -1;

    gManager.background.setTexture(background);
    gManager.background.setScale(sf::Vector2f(0.5,0.5));

    gManager.tetromino->sprite.setTexture(texture);

    while (window.isOpen())
    {          
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                    // touche pressée
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::D:
                            gManager.tetromino->setX(gManager.tetromino->getX() + Block::TEXTURE_SIZE);
                            break;
                        case sf::Keyboard::Q:
                            gManager.tetromino->setX(gManager.tetromino->getX() - Block::TEXTURE_SIZE);
                            break;
                        default:
                            break;
                    }
                    break;

                default:
                    break;
            }
        }



        gManager.Render(&window);
        
    }

    return 0;
}
