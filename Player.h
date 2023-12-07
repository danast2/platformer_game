#pragma once
class Player
{
private:
	sf::Sprite sprite_player;
	sf::Texture texture_sheet_player;
	bool moving;
	sf::Clock animation_timer;

	//Animation
	sf::IntRect current_frame;

	//Movement

	//Core
	void init_variables();
	void init_texture();
	void init_sprite();
	void init_animations();

public:
	Player();
	virtual ~Player();

	//functions
	void update_movement();
	void update_animations();
	void update();
	void render(sf::RenderTarget& target);
};

