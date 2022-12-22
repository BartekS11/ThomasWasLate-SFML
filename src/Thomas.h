#pragma once
#include "PlayableCharacter.h"

class Thomas : public PlayableCharacter
{
public:
	Thomas();
	sf::Texture thomasTexture;
	bool virtual handleInput() override;
};