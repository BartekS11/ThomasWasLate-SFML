#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Constants.h"
#include "Bob.h"
#include "Thomas.h"
#include "LevelManager.h"
#include "SoundManager.h"

class Engine
{
private:
	TextureHolder th;

	Thomas m_Thomas;
	Bob m_Bob;

	LevelManager m_LM;

	SoundManager m_SM;

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
	
	sf::VertexArray m_VALevel;
	int** m_ArrayLevel = nullptr;
	sf::Texture m_TextureTiles;

	void input();
	void update(float dtAsSeconds);
	void draw();
	void loadLevel();

	//Polimorphic method, can pass bob or thomas
	bool detectCollisions(PlayableCharacter& character);

	void populateEmmiters(std::vector<sf::Vector2f>& vSoundEmitters,
		int** arrayLevel);

	std::vector<sf::Vector2f> m_FireEmitters;
public:
	Engine();

	void run();
};