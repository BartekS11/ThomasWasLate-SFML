#include "Thomas.h"
#include "TextureHolder.h"

Thomas::Thomas()
{
	thomasTexture = TextureHolder::GetTexture("graphics/thomas.png");
	m_Sprite = sf::Sprite(thomasTexture);
	m_JumpDuration = .45;
}

bool Thomas::handleInput()
{
	m_JustJumped = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (!m_IsJumping && !m_IsFalling)
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		Thomas::m_LeftPressed = true;
	}
	else
	{
		Thomas::m_LeftPressed = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		Thomas::m_RightPressed = true;
	}
	else
	{
		Thomas::m_RightPressed = false;
	}

	return m_JustJumped;
}