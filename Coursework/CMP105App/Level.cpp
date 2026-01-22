#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	// initialise game objects
	m_snake.setRadius(15.f);
	m_snake.setFillColor(sf::Color::Green);
	m_snake.setPosition({ m_window.getSize().x * 0.5f, m_window.getSize().y * 0.5f });
	m_snakeSpeed = 150.f;

	m_food.setRadius(10.f);
	m_food.setFillColor(sf::Color::Red);

	spawnFood();
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
	
	if (newPos.x > m_window.getSize().x - m_snake.getRadius() * 2 || newPos.x < 0.f) {
		m_snake.setPosition({ m_window.getSize().x * 0.5f, m_window.getSize().y * 0.5f });
	}
	else if (newPos.y > m_window.getSize().y - m_snake.getRadius() * 2 || newPos.y < 0.f){
		m_snake.setPosition({ m_window.getSize().x * 0.5f, m_window.getSize().y * 0.5f });
	}
	else
	{
		m_snake.setPosition(newPos);
	}

	float xDistance = m_food.getPosition().x - m_snake.getPosition().x;
	float yDistance = m_food.getPosition().y - m_snake.getPosition().y;
	if (xDistance < 0.f) xDistance*=-1;
	if (yDistance < 0.f) yDistance *= -1;

	std::cout << xDistance << " " << m_snake.getRadius() + m_food.getRadius() << std::endl;

	if(xDistance < m_snake.getRadius() + m_food.getRadius() && yDistance < m_snake.getRadius() + m_food.getRadius()){
		spawnFood();
	}
}

// Render level
void Level::render()
{
	beginDraw();

	m_window.draw(m_food);
	m_window.draw(m_snake);

	endDraw();
}

void Level::spawnFood() {
	float x = rand() % m_window.getSize().x;
	float y = rand() % m_window.getSize().y;

	m_food.setPosition({x, y});
}

