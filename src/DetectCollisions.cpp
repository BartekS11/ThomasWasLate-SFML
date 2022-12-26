#include "Engine.h"

bool Engine::detectCollisions(PlayableCharacter& character)
{
	bool reachedGoal = false;

	sf::FloatRect detectionZone = character.getPosition();
	sf::FloatRect block;

	block.width = Constants::TILE_SIZE;
	block.height = Constants::TILE_SIZE;

	int startX = static_cast<int>(detectionZone.left / Constants::TILE_SIZE) - 1;
	int startY = static_cast<int>(detectionZone.top / Constants::TILE_SIZE) - 1;
	int endX = static_cast<int>(detectionZone.left / Constants::TILE_SIZE) + 2;

	int endY = static_cast<int>(detectionZone.top / Constants::TILE_SIZE) + 3;

	if (startX < 0) startX = 0;
	if (startY < 0) startY = 0;
	if (endX >= m_LM.getLevelSize().x)
		endX = m_LM.getLevelSize().x;

	if (endY >= m_LM.getLevelSize().y)
		endY = m_LM.getLevelSize().y;

	sf::FloatRect level(0, 0, m_LM.getLevelSize().x * Constants::TILE_SIZE,
		m_LM.getLevelSize().y * Constants::TILE_SIZE);

	if (!character.getPosition().intersects(level))
	{
		character.spawn(m_LM.getStartPosition(), Constants::GRAVITY);
	}

	for (auto x = startX; x < endX; x++)
	{
		for (int y = startY; y < endY; y++)
		{
			block.left = x * Constants::TILE_SIZE;
			block.top = y * Constants::TILE_SIZE;
			if (m_ArrayLevel[y][x] == 2 || m_ArrayLevel[y][x])
			{
				if (character.getHead().intersects(block))
				{
					character.spawn(m_LM.getStartPosition(), Constants::GRAVITY);
					if (m_ArrayLevel[y][x] == 2)
					{
						m_SM.playFallInFire();
					}
					else
					{
						m_SM.playFallInWater();
					}
				}
			}
			if (m_ArrayLevel[y][x] == 1)
			{
				if (character.getRight().intersects(block))
				{
					character.stopRight(block.left);
				}
				else if (character.getLeft().intersects(block))
				{
					character.stopLeft(block.left);
				}

				if (character.getFeet().intersects(block))
				{
					character.stopFalling(block.top);
				}
				else if (character.getHead().intersects(block))
				{
					character.stopJump();
				}
			}
			if (m_ArrayLevel[y][x] == 4)
			{
				reachedGoal = true;
			}

		}

	}
	return reachedGoal;
}