#pragma once
#include"Player.h"
class Game
{
private:
	sf::RenderWindow window;
	sf::Event event;

	Player* player;

	void init_window();
	void init_player();
public:

	Game();
	virtual ~Game();

	//Functions
	void update_player();
	void update();
	void render();
	const sf::RenderWindow& getWindow() const;
};

