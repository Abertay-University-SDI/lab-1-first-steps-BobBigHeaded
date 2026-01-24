#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	// initialise game objects
	

	/*m_points = 0;
	m_timePlayed.start();
	m_isAlive = true;
	m_canDie == true;*/
}

// handle user input
void Level::handleInput(float dt)
{
	if (m_input.isLeftMousePressed())
	{
		std::cout << "left mouse pressed" << std::endl;
	}

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

	m_window.draw(m_foodOne.getBody());
	m_window.draw(m_playerOne.getBody());

	endDraw();
}

