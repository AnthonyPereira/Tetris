#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class Block
{
protected:
	sf::Sprite sprite;
	sf::Vector2f coordinates;


public:
	static const float FACTOR;
	static const int TEXTURE_SIZE = 64;

	sf::IntRect rectangle = sf::IntRect(0, 0, 512, 512);


	Block(double x, double y,sf::Texture *t);
	void setX(double x);
	void setY(double y);
	double getX() const;
	double getY() const;
	void changeTexture(int n);
	sf::Sprite getSprite() const;
	void setTexture(sf::Texture *t, int size, int xOrigin, int yOrigin);
};

