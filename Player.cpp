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
	this->sprite_player.setScale(3.f, 3.f);
}

void Player::init_animations()
{
	this->animation_timer.restart();
	this->animation_switch = true;
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
	this->velocity_min = 2.f;
	this->velocity_max = 22.f;
	this->acceleration = 3.0f;
	this->drag = 0.80f;
	this->gravity = 4.f;
	this->velocity_max_y = 15.f;
}



void Player::update_movement()
{
	this->animation_state = PLAYER_ANIMATIONS_STATES::IDLE;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		//left
		this->move(-1.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		this->move(1.f, 0.f);
	}
	
	if (this->velocity.x > 0.f) 
	{
		this->animation_state = PLAYER_ANIMATIONS_STATES::MOVING_RIGHT;
	}else if(this->velocity.x < 0.f)
	{
		this->animation_state = PLAYER_ANIMATIONS_STATES::MOVING_LEFT;
	}
	else
	{
		this->animation_state = PLAYER_ANIMATIONS_STATES::IDLE;
	}

}

void Player::update_animations()
{
	if (this->animation_state == PLAYER_ANIMATIONS_STATES::IDLE) {
		if (this->animation_timer.getElapsedTime().asSeconds() >= 0.2f || this->get_anim_switch()) {
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
		if (this->animation_timer.getElapsedTime().asSeconds() >= 0.1f || this->get_anim_switch()) {
			this->current_frame.top = 50.f;
			this->current_frame.left += 40.f;
			if (this->current_frame.left >= 360.f) {
				this->current_frame.left = 0;
			}
			this->animation_timer.restart();
			this->sprite_player.setTextureRect(this->current_frame);
		}
		this->sprite_player.setScale(3.f, 3.f);
		this->sprite_player.setOrigin(0.f, 0.f);
	}
	else if (this->animation_state == PLAYER_ANIMATIONS_STATES::MOVING_LEFT) {
		if (this->animation_timer.getElapsedTime().asSeconds() >= 0.1f || this->get_anim_switch()) {
			this->current_frame.top = 50.f;
			this->current_frame.left += 40.f;
			if (this->current_frame.left >= 360.f) {
				this->current_frame.left = 0;
			}
			this->animation_timer.restart();
			this->sprite_player.setTextureRect(this->current_frame);
		}
		this->sprite_player.setScale(-3.f, 3.f);
		this->sprite_player.setOrigin(this->sprite_player.getGlobalBounds().width / 3.f, 0.f); //This is done so that the sprite reversal is normal.
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

void Player::reset_velocity_y()
{
	this->velocity.y = 0.f;
}

void Player::set_position(const float x, const float y)
{
	this->sprite_player.setPosition(x, y);
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite_player);

	sf::CircleShape circle;
	circle.setFillColor(sf::Color::Red);
	circle.setRadius(2.f);
	circle.setPosition(this->sprite_player.getPosition());

	target.draw(circle);
}

void Player::update_phisics()
{
	//gravity

	this->velocity.y += 1.0 * this->gravity;
	if (std::abs(this->velocity.x) > this->velocity_max_y)
	{
		this->velocity.y = this->velocity_max_y * ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}

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

	if (std::abs(this->velocity.x) <= 1.f) 
	{
		this->velocity.x = 0.f;
	}

	this->sprite_player.move(this->velocity);
}

const sf::FloatRect Player::getGlobalBounds() const
{
	return this->sprite_player.getGlobalBounds();
}

const sf::Vector2f Player::get_position() const
{
	return this->sprite_player.getPosition();
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

void Player::reset_animation_timer() {
	this->animation_timer.restart();
	this->animation_switch = true;
}

const bool& Player::get_anim_switch() {
	bool anim_switch = this->animation_switch;

	if (this -> animation_switch) {
		this->animation_switch = false;

	}
	return anim_switch;
}