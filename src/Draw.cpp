#include "Engine.h"

void Engine::draw()
{
	m_Window.clear(sf::Color::White);

	if (!m_SplitScreen)
	{
		m_Window.setView(m_BGMainView);
		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_MainView);

		m_Window.draw(m_VALevel, &m_TextureTiles);

		m_Window.draw(m_Thomas.getSprite());

		m_Window.draw(m_Bob.getSprite());
	}
	else
	{
		//Draw players splitscreen's
		m_Window.setView(m_BGLeftView);
		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_LeftView);

		m_Window.draw(m_VALevel, &m_TextureTiles);

		m_Window.draw(m_Bob.getSprite());
		m_Window.draw(m_Thomas.getSprite());

		m_Window.setView(m_BGRightView);
		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_RightView);

		m_Window.draw(m_VALevel, &m_TextureTiles);

		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());
	}

	m_Window.setView(m_HudView);
	m_Window.display();
}