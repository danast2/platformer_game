#include "stdafx.h"
#include "Game.h"

void Game::init_window() {
	this->window.create(sf::VideoMode(800, 600), "platformer_game", sf::Style::Close | sf::Style::Titlebar);
}

Game::Game() {
	this->init_window();
}

Game::~Game() {

}

void Game::update()
{
	//std::cout << "platformer game";
}

void Game::render()
{
}

const sf::RenderWindow& Game::getWindow() const
{
	// TODO: insert return statement here
	return this->window;
}
