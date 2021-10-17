#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class Block
{
protected:
	sf::Vector2f coordinates;


public:
	static const float FACTOR;
	static const int TEXTURE_SIZE = 32;
	sf::Sprite sprite;

	sf::IntRect rectangle = sf::IntRect(0, 0, 512, 512);


	Block();
	void setX(double x);
	void setY(double y);
	double getX() const;
	double getY() const;
	void changeTexture(int n);
};

