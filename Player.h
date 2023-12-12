#pragma once

enum PLAYER_ANIMATIONS_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, MOVING_JUMPING, FALLING};

class Player
{
private:
	sf::Sprite sprite_player;
	sf::Texture texture_sheet_player;
	sf::Clock animation_timer;

	//Animation
	short animation_state;
	sf::IntRect current_frame;
	bool animation_switch;

	//Phisics
	sf::Vector2f velocity;
	float velocity_max;
	float velocity_min;
	float acceleration;
	float drag;
	float gravity;
	float velocity_max_y;

	//Core
	void init_variables();
	void init_texture();
	void init_sprite();
	void init_animations();
	void init_phisics();

public:
	Player();
	virtual ~Player();

	//accesors
	const bool& get_anim_switch();

	//functions
	void reset_animation_timer();
	void move(const float dir_x, const float dir_y);
	void update_phisics();
	void update_movement();
	void update_animations();
	void update();
	void render(sf::RenderTarget& target);
};

