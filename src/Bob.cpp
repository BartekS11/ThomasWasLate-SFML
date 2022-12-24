#include "Bob.h"
#include "TextureHolder.h"

Bob::Bob()
{
	bobTexture = TextureHolder::GetTexture("graphics/bob.png");
	m_Sprite = sf::Sprite(bobTexture);

	m_JumpDuration = .25f;
}

bool Bob::handleInput()
{
	m_JustJumped = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (!m_IsJumping && !m_IsFalling)
		{
			m_IsJumping = true;
			m_TimeThisJump = 0.f;
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
		Bob::m_LeftPressed = true;
	}
	else
	{
		Bob::m_LeftPressed = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		Bob::m_RightPressed = true;
	}
	else
	{
		Bob::m_RightPressed = false;
	}

	return m_JustJumped;
}
