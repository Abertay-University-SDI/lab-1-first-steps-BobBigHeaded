#include "Food.h"

Food::Food() {
	m_foodShape.setRadius(10.f);
	m_foodShape.setFillColor(sf::Color::Red);
}

void Food::DetectCollision(sf::CircleShape playerBody, sf::RectangleShape playArea) {
	float xDistance = m_foodShape.getPosition().x - playerBody.getPosition().x;
	float yDistance = m_foodShape.getPosition().y - playerBody.getPosition().y;
	if (xDistance < 0.f) xDistance *= -1;
	if (yDistance < 0.f) yDistance *= -1;

	bool distanceXCalc = xDistance < playerBody.getRadius() + m_foodShape.getRadius();
	bool distanceYCalc = yDistance < playerBody.getRadius() + m_foodShape.getRadius();

	if (distanceXCalc && distanceYCalc){
		Spawn(playArea);
	}
}

void Food::Spawn(sf::RectangleShape playArea){
	unsigned areaX = playArea.getSize().x;
	unsigned areaY = playArea.getSize().y;

	float x = rand() % areaX + (playArea.getPosition().x - m_foodShape.getRadius()*2);
	float y = rand() % areaY + (playArea.getPosition().y - m_foodShape.getRadius()*2);

	m_foodShape.setPosition({ x, y });
}

sf::CircleShape Food::getBody() {
	return m_foodShape;
}