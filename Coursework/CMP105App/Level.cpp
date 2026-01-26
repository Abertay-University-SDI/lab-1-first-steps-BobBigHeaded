#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in){

	float winX = m_window.getSize().x / 2;
	float winY = m_window.getSize().y / 2;

	m_playAreaOne.setSize({ winX, winY });
	m_playAreaTwo.setSize({ winX, winY });

	m_playAreaOne.setPosition({0.f, winY/2});
	m_playAreaTwo.setPosition({winX, winY/2});

	m_playAreaOne.setFillColor(sf::Color(149, 235, 251));
	m_playAreaTwo.setFillColor(sf::Color(110, 194, 66));

	m_playerOne.ResetPosition(m_playAreaOne);
	m_playerTwo.ResetPosition(m_playAreaTwo);

	m_foodOne.Spawn(m_playAreaOne);
}

// handle user input
void Level::handleInput(float dt)
{
	sf::Keyboard::Scancode ctrlP1[4] = {
		sf::Keyboard::Scancode::W,
		sf::Keyboard::Scancode::A,
		sf::Keyboard::Scancode::S,
		sf::Keyboard::Scancode::D
	};
	sf::Keyboard::Scancode ctrlP2[4] = {
		sf::Keyboard::Scancode::Up,
		sf::Keyboard::Scancode::Left,
		sf::Keyboard::Scancode::Down,
		sf::Keyboard::Scancode::Right
	};

	m_playerOne.PlayerInput(m_input, ctrlP1);
	m_playerTwo.PlayerInput(m_input, ctrlP2);
}

// Update game objects
void Level::update(float dt){
	
	m_playerOne.MovePlayer(m_playAreaOne, dt);
	m_playerTwo.MovePlayer(m_playAreaTwo, dt);

	m_foodOne.DetectCollision(m_playerOne.getBody(), m_playAreaOne);
}

// Render level
void Level::render()
{
	beginDraw();

	m_window.draw(m_playAreaOne);
	m_window.draw(m_playAreaTwo);

	m_window.draw(m_foodOne.getBody());
	m_window.draw(m_playerOne.getBody());
	m_window.draw(m_playerTwo.getBody());

	endDraw();
}

