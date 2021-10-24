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
		int RenderMenu(sf::RenderWindow* window);
		Block* tetromino;
		Block* blockplateau;

		sf::Sprite background;
		sf::RectangleShape *plate;

		GraphicsManager();
};

