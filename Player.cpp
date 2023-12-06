#include "stdafx.h"
#include "Player.h"

void Player::init_texture()
{
}

void Player::init_sprite()
{
}

Player::Player()
{
	this->init_texture();
	this->init_sprite();
}

Player::~Player()
{
}

void Player::update()
{
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite_player);
}
