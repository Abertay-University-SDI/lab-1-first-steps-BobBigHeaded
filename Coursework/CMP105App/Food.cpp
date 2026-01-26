#include "Food.h"


Food::Food() {
	m_foodShape.setRadius(10.f);
	m_foodShape.setFillColor(sf::Color::Red);
}

void Food::DetectCollision(sf::CircleShape playerBody, sf::RectangleShape playArea) {
	//get the distance from each objects center and ensure it is positive
	float xDistance = (m_foodShape.getPosition().x + m_foodShape.getRadius()) - (playerBody.getPosition().x + playerBody.getRadius());
	float yDistance = (m_foodShape.getPosition().y + m_foodShape.getRadius()) - (playerBody.getPosition().y + playerBody.getRadius());
	if (xDistance < 0.f) xDistance *= -1;
	if (yDistance < 0.f) yDistance *= -1;

	//if within the bounds of each object then collided
	bool distanceCalc = (xDistance + yDistance) < playerBody.getRadius() + m_foodShape.getRadius();
	
	if (distanceCalc) Spawn(playArea);
}

void Food::Spawn(sf::RectangleShape playArea){
	//unsigned because rand() does not accept float
	unsigned areaX = playArea.getSize().x;
	unsigned areaY = playArea.getSize().y;
	//diameter so multiple calls of getRadius() isn't needed
	float diameter = m_foodShape.getRadius() * 2;

	//ensure the random position is in the bounds of the area by adding a offset
	float x = rand() % areaX + playArea.getPosition().x;
	x += (x > playArea.getPosition().x + diameter) ? -diameter : diameter;

	float y = rand() % areaY + (playArea.getPosition().y - m_foodShape.getRadius()*2);
	y += (y > playArea.getPosition().y + diameter) ? -diameter : diameter;

	m_foodShape.setPosition({ x, y });
}

sf::CircleShape Food::getBody() {
	return m_foodShape;
}