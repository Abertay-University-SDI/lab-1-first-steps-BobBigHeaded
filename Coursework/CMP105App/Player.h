#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"

class Player
{
public:
	Player(sf::Vector2u windowSize, sf::Color bodyColour);
	sf::CircleShape getBody();
	void PlayerInput(Input& input, sf::Keyboard::Scancode ctrls[4]);
	int getSpeed();
	void MovePlayer(sf::RectangleShape playArea, float dt);
	void ResetPosition(sf::RectangleShape playArea);

private:
	sf::Texture m_sprites{ sf::Vector2u(100, 100) };

	sf::CircleShape m_snake;
	sf::Vector2f m_movementVector;
	float m_snakeSpeed;

	std::vector<sf::Vector2f> m_moveHistory;
	std::vector<sf::Sprite> m_snakeBody;
};

