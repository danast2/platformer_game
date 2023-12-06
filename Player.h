#pragma once
class Player
{
private:
	sf::Sprite sprite_player;
	sf::Texture texture_sheet_player;

	//Animation
	sf::IntRect current_frame;

	//Movement

	//Core

	void init_texture();
	void init_sprite();

public:
	Player();
	virtual ~Player();

	//functions
	void update_movement();
	void update();
	void render(sf::RenderTarget& target);
};

