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

	sf::RectangleShape m_playAreaOne;
	sf::RectangleShape m_playAreaTwo;

	//initialisation of objects
	Player m_playerOne{m_window.getSize(), sf::Color::Red};
	Player m_playerTwo{m_window.getSize(), sf::Color::Blue};
	Food m_foodOne;
};