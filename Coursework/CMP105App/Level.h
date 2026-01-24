#pragma once

#include "Framework/BaseLevel.h"
#include "Player.h"
#include "Food.h"

class Level : BaseLevel{
public:
	Level(sf::RenderWindow& window, Input& input);
	~Level() override = default;

	void handleInput(float dt) override;
	void update(float dt);
	void render();
	void spawnFood();

private:

	Player m_playerOne{m_window.getSize()};
	Food m_foodOne{m_window.getSize()};

	// Default functions for rendering to the screen.

	// Default variables for level class.
	
	// Player variables
	sf::CircleShape m_snake;
	sf::Vector2f m_movementVector;
	float m_snakeSpeed;
	//Food variables
	sf::CircleShape m_food;
};