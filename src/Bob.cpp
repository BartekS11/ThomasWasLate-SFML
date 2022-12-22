#include "Bob.h"
#include "TextureHolder.h"

Bob::Bob()
{
	bobTexture = TextureHolder::GetTexture("graphics/bob.png");
	m_Sprite = sf::Sprite(bobTexture);

	m_JumpDuration = .25;
}

bool Bob::handleInput()
{
	m_JustJumped = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (!m_IsFalling && m_IsJumping)
		{
			m_IsJumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;
		}
	}
	else
	{
		m_IsJumping = false;
		m_IsFalling = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_LeftPressed = true;
	}
	else
	{
		m_LeftPressed = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_RightPressed = true;
	}
	else
	{
		m_RightPressed = false;
	}

	return m_JustJumped;
}
