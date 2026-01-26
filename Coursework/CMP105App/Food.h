#pragma once
#include <SFML/Graphics.hpp>

class Food
{
public:
	Food(); //initialisation
	void DetectCollision(sf::CircleShape playerBody, sf::RectangleShape playArea); //when to move self and decide on new food type
	void Spawn(sf::RectangleShape playArea);
	sf::CircleShape getBody();
private:
	sf::CircleShape m_foodShape; //defined in code

	sf::Vector2u m_pointYield; //defined in random selection of food
};

