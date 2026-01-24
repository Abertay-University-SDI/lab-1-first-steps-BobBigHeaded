#include "Player.h"

Player::Player(sf::Vector2u windowSize) {
	m_snake.setRadius(15.f);
	m_snake.setFillColor(sf::Color::Green);
	m_snake.setPosition({ windowSize.x * 0.5f, windowSize.y * 0.5f });
	m_snakeSpeed = 150.f;
}

void Player::PlayerInput(Input& input) {
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

void Player::MovePlayer(sf::Vector2u windowSize, float dt) {
	sf::Vector2f newPos = m_snake.getPosition();
	newPos += m_movementVector * dt;

	if (newPos.x > windowSize.x - m_snake.getRadius() * 2 || newPos.x < 0.f) {
		m_snake.setPosition({ windowSize.x * 0.5f, windowSize.y * 0.5f });
	}
	else if (newPos.y > windowSize.y - m_snake.getRadius() * 2 || newPos.y < 0.f) {
		m_snake.setPosition({ windowSize.x * 0.5f, windowSize.y * 0.5f });
	}
	else
	{
		m_snake.setPosition(newPos);
	}
}

int Player::getSpeed() {
	return m_snakeSpeed;
}

sf::CircleShape Player::getBody() {
	return m_snake;
}