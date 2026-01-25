#include "Player.h"

Player::Player(sf::Vector2u windowSize) {
	//initialising the player
	m_snake.setRadius(15.f);
	m_snake.setFillColor(sf::Color::Green);
	m_snake.setPosition({ windowSize.x * 0.5f, windowSize.y * 0.5f });
	m_snakeSpeed = 150.f;
}

void Player::PlayerInput(Input& input) {
	//basic input using the input class
	if (input.isKeyDown(sf::Keyboard::Scancode::W)) {

		m_movementVector = { 0.f, -m_snakeSpeed };
	}
	else if (input.isKeyDown(sf::Keyboard::Scancode::A)) {

		m_movementVector = { -m_snakeSpeed, 0.f };
	}
	else if (input.isKeyDown(sf::Keyboard::Scancode::S)) {

		m_movementVector = { 0.f, m_snakeSpeed };
	}
	else if (input.isKeyDown(sf::Keyboard::Scancode::D)) {

		m_movementVector = { m_snakeSpeed, 0.f };
	}
}

void Player::MovePlayer(sf::RectangleShape playArea, float dt) {
	sf::Vector2f newPos = m_snake.getPosition();
	newPos += m_movementVector * dt;

	sf::Vector2f areaSize = playArea.getSize();
	float xPos = playArea.getPosition().x;
	float yPos = playArea.getPosition().y;

	if (newPos.x > areaSize.x + xPos - m_snake.getRadius() * 2 || newPos.x < xPos) ResetPosition(playArea);
	else if (newPos.y > areaSize.y + yPos - m_snake.getRadius() * 2 || newPos.y < yPos) ResetPosition(playArea);
	else
	{
		m_snake.setPosition(newPos);
	}
}

void Player::ResetPosition(sf::RectangleShape playArea) {
	sf::Vector2f areaSize = playArea.getSize();
	//using the playArea location and size to accurately find the bounds of the area
	float newX = areaSize.x * 0.5f - m_snake.getRadius() + playArea.getPosition().x;
	float newY = areaSize.y - m_snake.getRadius();

	m_snake.setPosition({ newX, newY });
}

int Player::getSpeed() {
	return m_snakeSpeed;
}

sf::CircleShape Player::getBody() {
	return m_snake;
}