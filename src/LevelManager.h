#pragma once

#include "SFML/Graphics.hpp"
#include "Constants.h"

class LevelManager
{
private:
	sf::Vector2i m_LevelSize;
	sf::Vector2f m_StartPosition;
	//To decrease time beating same level if beaten once
	float m_TimeModifier = 1.f; 
	float m_BaseTimeLimit = 0.f;
	int m_CurrentLevel = 0;

public:
	float getTimeLimit();
	sf::Vector2f getStartPosition();
	int** nextLevel(sf::VertexArray& rVaLevel);
	sf::Vector2i getLevelSize();
	int getCurrentLevel();
};