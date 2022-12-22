#pragma once
#include "PlayableCharacter.h"

class Bob : public PlayableCharacter
{
	Bob();
	sf::Texture bobTexture;
	bool virtual handleInput() override;
};