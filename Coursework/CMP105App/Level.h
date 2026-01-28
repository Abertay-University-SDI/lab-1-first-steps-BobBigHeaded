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

private:
	//background map size as in properties
	sf::Texture m_mapTexture{sf::Vector2u(800, 300)};

	//P1 controls
	sf::Keyboard::Scancode ctrlP1[4] = {
		sf::Keyboard::Scancode::W,
		sf::Keyboard::Scancode::A,
		sf::Keyboard::Scancode::S,
		sf::Keyboard::Scancode::D
	};
	//P2 controls
	sf::Keyboard::Scancode ctrlP2[4] = {
		sf::Keyboard::Scancode::Up,
		sf::Keyboard::Scancode::Left,
		sf::Keyboard::Scancode::Down,
		sf::Keyboard::Scancode::Right
	};

	//seperate areeas for both players
	sf::RectangleShape m_playAreaOne;
	sf::RectangleShape m_playAreaTwo;

	//initialisation of objects
	Player m_playerOne{m_window.getSize(), sf::Color::Red};
	Player m_playerTwo{m_window.getSize(), sf::Color::Blue};
	
	Food m_foodOne;
	Food m_foodTwo;
};