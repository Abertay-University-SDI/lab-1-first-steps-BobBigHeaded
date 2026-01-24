#pragma once
#include <SFML/Graphics.hpp>

class Food
{
public:
	Food(sf::Vector2u windowSize); //initialisation
	void DetectCollision(sf::CircleShape playerBody, sf::Vector2u windowSize); //when to move self and decide on new food type
	void Spawn(sf::Vector2u windowSize);
	sf::CircleShape getBody();
private:
	sf::CircleShape m_foodShape; //defined in code

	sf::Vector2u m_pointYield; //defined in random selection of food
};

