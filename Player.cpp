#include "stdafx.h"
#include "Player.h"

void Player::init_variables()
{
	this->animation_state = PLAYER_ANIMATIONS_STATES::IDLE;
}

void Player::init_texture()
{
	if (!this->texture_sheet_player.loadFromFile("textures/player_sheet.png")) {
		std::cout << "ERROR: COULD NOT LOAD PLAYYER TEXTURE"<<std::endl;
	}
}

void Player::init_sprite()
{
	this->sprite_player.setTexture(this->texture_sheet_player);
	this->current_frame = sf::IntRect(0, 0, 40, 50);

	this->sprite_player.setTextureRect(current_frame);
	this->sprite_player.setScale(1.5f, 1.5f);
}

void Player::init_animations()
{
	this->animation_timer.restart();
}

Player::Player()
{
	this->init_variables();
	this->init_texture();
	this->init_sprite();
	this->init_animations();
	this->init_phisics();
}

Player::~Player()
{
}

void Player::init_phisics()
{
	this->velocity_min = 1.f;
	this->velocity_max = 10.f;
	this->acceleration = 3.f;
	this->drag = 0.93f;
	
}



void Player::update_movement()
{
	this->animation_state = PLAYER_ANIMATIONS_STATES::IDLE;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		//left
		this->move(-1.f, 0.f);
		this->animation_state = PLAYER_ANIMATIONS_STATES::MOVING_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		this->move(1.f, 0.f);
		this->animation_state = PLAYER_ANIMATIONS_STATES::MOVING_RIGHT;
	}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
	//	this->sprite_player.move(0.f, -1.f);
	//	this->animation_state = PLAYER_ANIMATIONS_STATES::MOVING_JUMPING;
	//}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
	//	this->sprite_player.move(0.f, 1.f);
	//	this->animation_state = PLAYER_ANIMATIONS_STATES::FALLING;
	//}
}

void Player::update_animations()
{
	if (this->animation_state == PLAYER_ANIMATIONS_STATES::IDLE) {
		if (this->animation_timer.getElapsedTime().asSeconds() >= 0.2f) {
			this->current_frame.top = 0.f;
			this->current_frame.left += 40.f;
			if (this->current_frame.left >= 160.f) {
				this->current_frame.left = 0;
			}
			this->animation_timer.restart();
			this->sprite_player.setTextureRect(this->current_frame);
		}
	}
	else if (this->animation_state == PLAYER_ANIMATIONS_STATES::MOVING_RIGHT) {
		if (this->animation_timer.getElapsedTime().asSeconds() >= 0.07f) {
			this->current_frame.top = 50.f;
			this->current_frame.left += 40.f;
			if (this->current_frame.left >= 360.f) {
				this->current_frame.left = 0;
			}
			this->animation_timer.restart();
			this->sprite_player.setTextureRect(this->current_frame);
		}
	}
	else {
		this->animation_timer.restart();
	}
	
}

void Player::update()
{
	this->update_movement();
	this->update_animations();
	this->update_phisics();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite_player);
}

void Player::update_phisics()
{
	//deceleration
	this->velocity *= this->drag;

	//limit deceleration
	if (std::abs(this->velocity.x) < this->velocity_min)
	{
		this->velocity.x = 0.f;
	}
	if (std::abs(this->velocity.y) < this->velocity_min)
	{
		this->velocity.y = 0.f;
	}

	this->sprite_player.move(this->velocity);
}

void Player::move(const float dir_x, const float dir_y)
{
	//acceleration
	this->velocity.x += dir_x * this->acceleration;
	//this->velocity.y += dir_y * this->acceleration; !!!gravity!!!

	//limit velocity
	if (std::abs(this->velocity.x) > this->velocity_max)
	{
		this->velocity.x = this->velocity_max * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
}