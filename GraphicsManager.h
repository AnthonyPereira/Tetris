#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Block.h"
using namespace std;

class GraphicsManager
{

	public:
		int Render(sf::RenderWindow* window);
		Block* tetromino;
		sf::Sprite background;

		GraphicsManager();
};

