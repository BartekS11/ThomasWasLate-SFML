#include "Engine.h"

void Engine::populateEmmiters(std::vector<sf::Vector2f>& vSoundEmitters,
	int** arrayLevel)
{
	vSoundEmitters.empty();
	sf::FloatRect previousEmitter;

	for (auto x = 0; x < static_cast<int>(m_LM.getLevelSize().x); x++)
	{
		for (auto y = 0; y < static_cast<int>(m_LM.getLevelSize().y); y++)
		{
			if (arrayLevel[y][x] == 2)
			{
				if (!sf::FloatRect(x * Constants::TILE_SIZE,
					y * Constants::TILE_SIZE, Constants::TILE_SIZE,
					Constants::TILE_SIZE).intersects(previousEmitter))
				{
					vSoundEmitters.push_back(sf::Vector2f(x * Constants::TILE_SIZE,
						y * Constants::TILE_SIZE));

					previousEmitter.left = x * Constants::TILE_SIZE;
					previousEmitter.top = y * Constants::TILE_SIZE;

					previousEmitter.width = Constants::TILE_SIZE * 6;
					previousEmitter.height = Constants::TILE_SIZE * 6;
				}
			}
		}
	}
	return;
}