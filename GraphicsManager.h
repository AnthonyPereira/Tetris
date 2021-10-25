#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "EventsManager.h"
#include "Block.h"
using namespace std;

class GraphicsManager
{

	public:
		int Render(sf::RenderWindow* window, MouvManager* mManager, sf::Time time);
		int RenderMenu(sf::RenderWindow* window, sf::Clock& c);
		Block* tetromino;
		Block* blockplateau;

		sf::Sprite background;
		sf::RectangleShape *plate;

		GraphicsManager();
};

