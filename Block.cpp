#include <SFML/Graphics.hpp>
#include <vector>
#include "Block.h"

using namespace std;

Block::Block(double x, double y,sf::Texture *t) {
			coordinates[0] = x;
			coordinates[1] = y;
			sprite.setScale(sf::Vector2f(0.125, 0.125));

			sprite.setTexture(*t);
		}
void Block::setX(double x) {
	coordinates[0] = x;
};
void Block::setY(double y) {
	coordinates[1] = y;
}

double Block::getX() const {
	return coordinates[0];
};

sf::Sprite Block::getSprite() const {
	return sprite;
};

double Block::getY() const {
	return coordinates[1];
};
	
void Block::setTexture(sf::Texture *t,int size,int xOrigin,int yOrigin) {
	sprite.setTextureRect(sf::IntRect(xOrigin, yOrigin, size, size));
	sprite.setScale(sf::Vector2f(0.125, 0.125));
}