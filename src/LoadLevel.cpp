#include "Engine.h"

void Engine::loadLevel()
{
	m_Playing = false;
	
	for (auto i = 0; i < m_LM.getLevelSize().y; ++i)
	{
		delete[] m_ArrayLevel[i];
	}
	delete[] m_ArrayLevel;

	m_ArrayLevel = m_LM.nextLevel(m_VALevel);
	m_TimeRemaining = m_LM.getTimeLimit();

	m_Thomas.spawn(m_LM.getStartPosition(), Constants::GRAVITY);
	m_Bob.spawn(m_LM.getStartPosition(), Constants::GRAVITY);
	m_NewLevelRequired = false;
}