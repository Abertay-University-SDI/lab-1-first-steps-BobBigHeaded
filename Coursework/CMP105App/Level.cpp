#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in){

	float winX = m_window.getSize().x / 2;
	float winY = m_window.getSize().y / 2;

	m_playAreaOne.setSize({ winX, winY });
	m_playAreaTwo.setSize({ winX, winY });

	m_playAreaOne.setPosition({0.f, winY/2});
	m_playAreaTwo.setPosition({winX, winY/2});

	m_playAreaOne.setFillColor(sf::Color::Yellow);
	m_playAreaTwo.setFillColor(sf::Color::Blue);
}

// handle user input
void Level::handleInput(float dt)
{
	m_playerOne.PlayerInput(m_input);
}

// Update game objects
void Level::update(float dt){
	
	m_playerOne.MovePlayer(m_window.getSize(), dt);
	m_foodOne.DetectCollision(m_playerOne.getBody(), m_window.getSize());
}

// Render level
void Level::render()
{
	beginDraw();

	m_window.draw(m_playAreaOne);
	m_window.draw(m_playAreaTwo);

	m_window.draw(m_foodOne.getBody());
	m_window.draw(m_playerOne.getBody());

	endDraw();
}

