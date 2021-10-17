#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class Block
{
protected:
	sf::Sprite sprite;
	vector<double> coordinates{ 2,0.0 };

public:
	Block(double x, double y,sf::Texture *t);
	void setX(double x);
	void setY(double y);
	double getX() const;
	double getY() const;
	sf::Sprite getSprite() const;

	void setTexture(sf::Texture *t, int size, int xOrigin, int yOrigin);






};