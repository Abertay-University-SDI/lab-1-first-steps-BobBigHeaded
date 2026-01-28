#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in){

	sf::Image mapImage("Map.png");
	m_mapTexture.update(mapImage);

	float winX = m_window.getSize().x / 2;
	float winY = m_window.getSize().y / 2;

	m_playAreaOne.setSize({ winX, winY });
	m_playAreaTwo.setSize({ winX, winY });

	m_playAreaOne.setPosition({0.f, winY/2});
	m_playAreaTwo.setPosition({winX, winY/2});

	m_playAreaOne.setFillColor(sf::Color(149, 235, 251));
	m_playAreaTwo.setFillColor(sf::Color(110, 194, 66));

	m_playerOne.ResetPosition(m_playAreaOne);
	m_playerTwo.ResetPosition(m_playAreaTwo);

	m_foodOne.Spawn(m_playAreaOne);
	m_foodTwo.Spawn(m_playAreaTwo);
}

// handle user input
void Level::handleInput(float dt)
{
	m_playerOne.PlayerInput(m_input, ctrlP1);
	m_playerTwo.PlayerInput(m_input, ctrlP2);
}

// Update game objects
void Level::update(float dt){
	
	m_playerOne.MovePlayer(m_playAreaOne, dt);
	m_playerTwo.MovePlayer(m_playAreaTwo, dt);

	m_foodOne.DetectCollision(m_playerOne.getBody(), m_playAreaOne);
	m_foodTwo.DetectCollision(m_playerTwo.getBody(), m_playAreaTwo);
}

// Render level
void Level::render()
{
	beginDraw();

	sf::Sprite mapSprite(m_mapTexture);

	float scaleXCalc = static_cast<float>(m_window.getSize().x) / static_cast<float>(m_mapTexture.getSize().x);
	float scaleYCalc = static_cast<float>(m_window.getSize().y) / static_cast<float>(m_mapTexture.getSize().y) /2;

	mapSprite.setScale({ scaleXCalc, scaleYCalc });
	mapSprite.setPosition({ 0, static_cast<float>(m_window.getSize().y) / 4 });

	m_window.draw(mapSprite);

	m_window.draw(m_foodOne.getBody());
	m_window.draw(m_foodTwo.getBody());
	m_window.draw(m_playerOne.getBody());
	m_window.draw(m_playerTwo.getBody());

	endDraw();
}