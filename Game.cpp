#include "stdafx.h"
#include "Game.h"

void Game::init_window() {
	this->window.create(sf::VideoMode(800, 600), "platformer_game", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}


void Game::init_player()
{
	this->player = new Player();
}

Game::Game() {
	this->init_window();
	this->init_player();
}

Game::~Game() {
	delete this->player;
}

void Game::update_player()
{
	this->player->update();
}

void Game::update()
{
	//std::cout << "platformer game";
	while (this->window.pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed()) {
			this->window.close();
		}
		else if (this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape) {
			this->window.close();
		}
	}
	this->update_player();
}

void Game::render_player()
{
	this->player->render(this->window);
}

void Game::render()
{
	this->window.clear();

	//render game;
	this->render_player();

	this->window.display();
}

const sf::RenderWindow& Game::getWindow() const
{
	// TODO: insert return statement here
	return this->window;
}
