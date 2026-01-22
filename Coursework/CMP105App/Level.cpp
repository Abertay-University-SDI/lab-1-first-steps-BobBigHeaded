#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	// initialise game objects
	m_snake.setRadius(10.f);
	m_snake.setFillColor(sf::Color::Green);
	m_snake.setPosition({ 300.f, 300.f });

	m_snakeSpeed = 150.f;
}

// handle user input
void Level::handleInput(float dt)
{
	if (m_input.isLeftMousePressed())
	{
		std::cout << "left mouse pressed" << std::endl;
	}

	if (m_input.isKeyDown(sf::Keyboard::Scancode::W)) {
		m_movementVector = { 0.f, -m_snakeSpeed };
	}else if (m_input.isKeyDown(sf::Keyboard::Scancode::A)){
		m_movementVector = { -m_snakeSpeed, 0.f };
	}else if (m_input.isKeyDown(sf::Keyboard::Scancode::S)) {
		m_movementVector = { 0.f, m_snakeSpeed };
	}else if (m_input.isKeyDown(sf::Keyboard::Scancode::D)) {
		m_movementVector = { m_snakeSpeed, 0.f };
	}
}

// Update game objects
void Level::update(float dt)
{
	sf::Vector2f newPos = m_snake.getPosition();
	newPos += m_movementVector * dt;
	
	m_snake.setPosition(newPos);
}

// Render level
void Level::render()
{
	beginDraw();

	m_window.draw(m_snake);

	endDraw();
}

