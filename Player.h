#pragma once
class Player
{
private:
	sf::Sprite sprite_player;
	sf::Texture texture_sheet_player;

	//Animation

	//Movement

	//Core

	void init_texture();
	void init_sprite();

public:
	Player();
	virtual ~Player();

	//functions

	void update();
	void render(sf::RenderTarget& target);
};

