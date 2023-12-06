#include "stdafx.h"
#include "Player.h"

void Player::init_texture()
{
	if (!this->texture_sheet_player.loadFromFile("textures/player_sheet.png")) {
		std::cout << "ERROR: COULD NOT LOAD PLAYYER TEXTURE"<<std::endl;
	}
}

void Player::init_sprite()
{
	this->sprite_player.setTexture(this->texture_sheet_player);
	this->current_frame = sf::IntRect(0, 0, 50, 50);
	this->sprite_player.setTextureRect(current_frame);
}

Player::Player()
{
	this->init_texture();
	this->init_sprite();
}

Player::~Player()
{
}



void Player::update_movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		//left
		this->sprite_player.move(-1.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		this->sprite_player.move(1.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		this->sprite_player.move(0.f, -1.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		this->sprite_player.move(0.f, 1.f);
	}
}

void Player::update()
{
	this->update_movement();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite_player);
}
