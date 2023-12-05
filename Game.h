#pragma once
#include "stdafx.h"
class Game
{
private:
	sf::RenderWindow window;
	void init_window();
public:

	Game();
	virtual ~Game();

	//Functions
	void update();
	void render();
	const sf::RenderWindow& getWindow() const;
};

