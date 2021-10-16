#include <SFML/Graphics.hpp>
#include <vector>
#include "Block.h"

using namespace std;

Block::Block(double x, double y,sf::Texture *t) {
			coordinates.x = x;
			coordinates.y = y;
			sprite.setScale(sf::Vector2f(FACTOR, FACTOR));

			sprite.setTexture(*t);
			sprite.setTextureRect(rectangle);
		}
void Block::setX(double x) {
	coordinates.x = x;
	sprite.setPosition(coordinates);
};
void Block::setY(double y) {
	coordinates.y = y;
	sprite.setPosition(coordinates);

}

double Block::getX() const {
	return coordinates.x;
};

double Block::getY() const {
	return coordinates.y;
};

sf::Sprite Block::getSprite() const {
	return sprite;
};

void Block::changeTexture(int n){
	rectangle.left = 512*n;
	sprite.setTextureRect(rectangle);
}



const float Block::FACTOR = 0.125f;