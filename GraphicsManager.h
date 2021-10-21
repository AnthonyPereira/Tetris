#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "EventsManager.h"
#include "Block.h"
using namespace std;

class GraphicsManager
{

	public:
		int Render(sf::RenderWindow* window, MouvManager* mManager);
		Block* tetromino;
		sf::Sprite background;
		sf::RectangleShape *plate;

		GraphicsManager();
};

