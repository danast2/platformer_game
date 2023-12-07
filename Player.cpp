#include "stdafx.h"
#include "Player.h"

void Player::init_variables()
{
	this->moving = false;
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
}

Player::~Player()
{
}



void Player::update_movement()
{
	this->moving = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		//left
		this->sprite_player.move(-1.f, 0.f);
		this->moving = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		this->sprite_player.move(1.f, 0.f);
		this->moving = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		this->sprite_player.move(0.f, -1.f);
		this->moving = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		this->sprite_player.move(0.f, 1.f);
		this->moving = true;
	}
}

void Player::update_animations()
{
	if (this->animation_timer.getElapsedTime().asSeconds() >= 0.2f) {
		if (this->moving == false) { //idle animation
			this->current_frame.left += 40.f;
			if (this->current_frame.left >= 160.f) {
				this->current_frame.left = 0;
			}
		}
		this->animation_timer.restart();
		this->sprite_player.setTextureRect(this->current_frame);
	}
		
	
	
}

void Player::update()
{
	this->update_movement();
	this->update_animations();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite_player);
}
