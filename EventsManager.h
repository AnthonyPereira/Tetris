#pragma once
#include <SFML/Graphics.hpp>

#include "MouvManager.h"

class EventsManager
{
public:
	void analyseEvent(sf::Event* event, MouvManager* mManager, sf::RenderWindow* window);
	void MenuEvent(sf::Event* event, sf::RenderWindow* window, int& gamestatus);
};

