#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <sstream>
#include <fstream>
#include "LevelManager.h"

float LevelManager::getTimeLimit()
{
	return m_BaseTimeLimit * m_TimeModifier;
}

sf::Vector2f LevelManager::getStartPosition()
{
	return m_StartPosition;
}

int** LevelManager::nextLevel(sf::VertexArray& rVaLevel)
{
	m_LevelSize.x = 0;
	m_LevelSize.y = 0;
	m_CurrentLevel++;

	if (m_CurrentLevel > Constants::NUM_LEVELS)
	{
		m_CurrentLevel = 1;
		m_TimeModifier -= .1f;
	}

	std::string levelToLoad;
	switch (m_CurrentLevel)
	{
	case 1:
		levelToLoad = "levels/level1.txt";
		m_StartPosition.x = 100.f;
		m_StartPosition.y = 100.f;
		m_BaseTimeLimit = 30.f;
		break;

	case 2:
		levelToLoad = "levels/level2.txt";
		m_StartPosition.x = 100.f;
		m_StartPosition.y = 3600.f;
		m_BaseTimeLimit = 100.f;
		break;

	case 3:
		levelToLoad = "levels/level3.txt";
		m_StartPosition.x = 1250;
		m_StartPosition.y = 0;
		m_BaseTimeLimit = 30.f;
		break;

	case 4:
		levelToLoad = "levels/level4.txt";
		m_StartPosition.x = 50;
		m_StartPosition.y = 200;
		m_BaseTimeLimit = 50.f;
		break;
	}

	std::ifstream inputFile(levelToLoad);
	std::string s;

	while (std::getline(inputFile, s))
	{
		++m_LevelSize.y;
	}
	m_LevelSize.x = s.length();

	//Change flag state and set stream start of file
	inputFile.clear();
	inputFile.seekg(0, std::ios::beg);
	
	//Declare 2d array to keep current level 
	int** arrayLevel = new int* [m_LevelSize.y];
	for (auto i = 0; i < m_LevelSize.y; ++i)
	{
		arrayLevel[i] = new int[m_LevelSize.x];
	}

	std::string row;
	int row_count = 0;

	while (inputFile >> row)
	{
		for (auto i = 0; i < row.length(); i++)
		{
			const char val = row[i];
			arrayLevel[row_count][i] = atoi(&val);
		}
		row_count++;
	}
	inputFile.close();

	rVaLevel.setPrimitiveType(sf::Quads);
	rVaLevel.resize(m_LevelSize.x * m_LevelSize.y * Constants::VERTS_IN_QUAD);
	int currentVertex = 0;

	for (auto x = 0; x < m_LevelSize.x; x++)
	{
		for (auto y = 0; y < m_LevelSize.y; y++)
		{
			rVaLevel[currentVertex + 0].position = sf::Vector2f(x * Constants::TILE_SIZE,
				y * Constants::TILE_SIZE);
			rVaLevel[currentVertex + 1].position = sf::Vector2f((x * Constants::TILE_SIZE) +
				Constants::TILE_SIZE, y * Constants::TILE_SIZE);
			rVaLevel[currentVertex + 2].position = sf::Vector2f((x * Constants::TILE_SIZE) +
				Constants::TILE_SIZE, (y * Constants::TILE_SIZE) + Constants::TILE_SIZE);
			rVaLevel[currentVertex + 3].position = sf::Vector2f((x * Constants::TILE_SIZE)
				, (y * Constants::TILE_SIZE) + Constants::TILE_SIZE);

			int verticalOffset = arrayLevel[y][x] * Constants::TILE_SIZE;

			rVaLevel[currentVertex + 0].texCoords = sf::Vector2f(0, 0 + verticalOffset);
			rVaLevel[currentVertex + 1].texCoords = sf::Vector2f(Constants::TILE_SIZE, 0 + verticalOffset);
			rVaLevel[currentVertex + 2].texCoords = sf::Vector2f(Constants::TILE_SIZE, Constants::TILE_SIZE + verticalOffset);
			rVaLevel[currentVertex + 3].texCoords = sf::Vector2f(0, Constants::TILE_SIZE + verticalOffset);

			currentVertex = currentVertex + Constants::VERTS_IN_QUAD;
		}
	}
	return arrayLevel;
}

sf::Vector2i LevelManager::getLevelSize()
{
	return m_LevelSize;
}

int LevelManager::getCurrentLevel()
{
	return m_CurrentLevel;
}
