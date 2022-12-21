#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Constants.h"

class Engine
{
private:
	TextureHolder th;

	sf::RenderWindow m_Window;

	sf::View m_MainView;
	sf::View m_LeftView;
	sf::View m_RightView;

	sf::View m_BGMainView;
	sf::View m_BGLeftView;
	sf::View m_BGRightView;

	sf::View m_HudView;

	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;

	bool m_Playing = false;
	bool m_Character1 = true;

	bool m_SplitScreen = false;
	float m_TimeRemaining = 10;
	sf::Time m_GameTimeTotal;

	bool m_NewLevelRequired = true;
	
	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	Engine();

	void run();
};