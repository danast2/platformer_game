#pragma once
#include"Player.h"
#include "TileMap.h"
class Game
{
private:
	sf::RenderWindow window;
	sf::Event event;
	sf::Texture tileSheet;

	Player* player;
	TileMap* tileMap;

	void init_window();
	void initTileSheet();
	void init_player();
	void initTileMap();
public:

	Game();
	virtual ~Game();

	//Functions
	void update_player();
	void update_collision();
	void update_tile_map();
	void update();

	void render_player();
	void render_tile_map();
	void render();

	const sf::RenderWindow& getWindow() const;
};

