#include "Food.h"

Food::Food(sf::Vector2u windowSize) {
	m_foodShape.setRadius(10.f);
	m_foodShape.setFillColor(sf::Color::Red);

	Spawn(windowSize);
}

void Food::DetectCollision(sf::CircleShape playerBody, sf::Vector2u windowSize) {
	float xDistance = m_foodShape.getPosition().x - playerBody.getPosition().x;
	float yDistance = m_foodShape.getPosition().y - playerBody.getPosition().y;
	if (xDistance < 0.f) xDistance *= -1;
	if (yDistance < 0.f) yDistance *= -1;

	if (xDistance < playerBody.getRadius() + m_foodShape.getRadius() && yDistance < playerBody.getRadius() + m_foodShape.getRadius()) {
		Spawn(windowSize);
	}
}

void Food::Spawn(sf::Vector2u windowSize){
	float x = rand() % windowSize.x;
	float y = rand() % windowSize.y;

	m_foodShape.setPosition({ x, y });
}

sf::CircleShape Food::getBody() {
	return m_foodShape;
}