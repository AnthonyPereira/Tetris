#pragma once
#include <SFML/Graphics.hpp>

#include "MouvManager.h"

class EventsManager
{
public:
	void analyseEvent(sf::Event* event, MouvManager* mManager, sf::RenderWindow* window);
};

