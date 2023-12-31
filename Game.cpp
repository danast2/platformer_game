#include "stdafx.h"
#include "Game.h"

void Game::init_window() {
	this->window.create(sf::VideoMode(800, 600), "platformer_game", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}

void Game::initTileSheet()
{
	if (!this->tileSheet.loadFromFile("textures/player_sheet.png")) {
		std::cout << "ERROR:GAME COULD NOT LOAD tile sheet" << std::endl;
	}
}


void Game::init_player()
{
	this->player = new Player();
}

void Game::initTileMap()
{
	this->tileMap = new TileMap(20,20, &this->tileSheet, 50);
	this->tileMap->addTile(0, 0);
}

Game::Game() {
	this->init_window();
	this->initTileSheet();
	this->init_player();
	this->initTileMap();
}

Game::~Game() {
	delete this->player;
	delete this->tileMap;
}

void Game::update_player()
{
	this->player->update();
}

void Game::update_collision()
{
	//collision bottom of the screen
	if (this->player->get_position().y + this->player->getGlobalBounds().height > this->window.getSize().y)
	{
		this->player->reset_velocity_y();
		this->player->set_position(this->player->get_position().x, this->window.getSize().y - this->player->getGlobalBounds().height);
	}
}

void Game::update_tile_map()
{
	this->tileMap->update();
}

void Game::update()
{
	//polling window events
	while (this->window.pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed()) {
			this->window.close();
		}
		else if (this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape) {
			this->window.close();
		}
		if (this->event.type == sf::Event::KeyReleased &&
				(
				this->event.key.code == sf::Keyboard::A ||
				this->event.key.code == sf::Keyboard::D ||
				this->event.key.code == sf::Keyboard::W ||
				this->event.key.code == sf::Keyboard::S
				)
			)
		{
			this->player->reset_animation_timer();
		}
			
	}
	this->update_player();

	this->update_collision();

	this->update_tile_map();
}

void Game::render_player()
{
	this->player->render(this->window);
}

void Game::render_tile_map()
{
	this->tileMap->render(this->window);
}

void Game::render()
{
	this->window.clear();

	//render game;
	this->render_tile_map();

	this->render_player();

	this->window.display();
}

const sf::RenderWindow& Game::getWindow() const
{
	// TODO: insert return statement here
	return this->window;
}
