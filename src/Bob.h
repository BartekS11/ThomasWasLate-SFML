#pragma once
#include "PlayableCharacter.h"

class Bob : public PlayableCharacter
{
public:
	Bob();
	sf::Texture bobTexture;
	bool virtual handleInput() override;
};