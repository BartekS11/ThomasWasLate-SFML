#include "PlayableCharacter.h"

void PlayableCharacter::spawn(sf::Vector2f startPosition, float gravity)
{
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;

	m_Gravity = gravity;

	m_Sprite.setPosition(m_Position);
}

sf::FloatRect PlayableCharacter::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

sf::FloatRect PlayableCharacter::getFeet()
{
	return m_Feet;
}

sf::FloatRect PlayableCharacter::getHead()
{
	return m_Head;
}

sf::FloatRect PlayableCharacter::getRight()
{
	return m_Right;
}

sf::FloatRect PlayableCharacter::getLeft()
{
	return m_Left;
}

sf::Vector2f PlayableCharacter::getCenter()
{
	return sf::Vector2f(
	m_Position.x + m_Sprite.getGlobalBounds().width / 2.f,
	m_Position.y + m_Sprite.getGlobalBounds().height / 2.f);
}

void PlayableCharacter::update(float elapsedTime)
{
	if (m_RightPressed)
	{
		m_Position.x += m_Speed * elapsedTime;
	}
	if (m_LeftPressed)
	{
		m_Position.x -= m_Speed * elapsedTime;
	}

	if (m_IsJumping)
	{
		m_TimeThisJump += elapsedTime;

		if (m_TimeThisJump < m_JumpDuration)
		{
			m_Position.y -= m_Gravity * 2 * elapsedTime;
		}
		else
		{
			m_IsJumping = false;
			m_IsFalling = true;
		}
	}
	if (m_IsFalling)
	{
		m_Position.y += m_Gravity * elapsedTime;
	}
	sf::FloatRect r = getPosition();

	//Feet
	m_Feet.left = r.left + 3;
	m_Feet.top = r.top + r.height - 1;
	m_Feet.width = r.width - 6;
	m_Feet.height = 1;

	//Right
	m_Right.left = r.left + r.width - 2;
	m_Right.top = r.top + r.height * .35;
	m_Right.width = 1;
	m_Right.height = r.height * .3;

	//Left
	m_Left.left = r.left;
	m_Left.top = r.top + r.height * .5;
	m_Left.width = 1;
	m_Left.height = r.height * .3;

	//Head
	m_Head.left = r.left;
	m_Head.top = r.top + (r.height * .3);
	m_Head.width = r.width;
	m_Head.height = 1;

	m_Sprite.setPosition(m_Position);

}

sf::Sprite PlayableCharacter::getSprite()
{
	return m_Sprite;
}

void PlayableCharacter::stopFalling(float position)
{
	m_Position.y = position - getPosition().height;
	m_Sprite.setPosition(m_Position);
	m_IsFalling = false;
}

void PlayableCharacter::stopRight(float position)
{
	m_Position.x = position - m_Sprite.getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);
}

void PlayableCharacter::stopLeft(float position)
{
	m_Position.x = position - m_Sprite.getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);
}

void PlayableCharacter::stopJump()
{
	m_IsJumping = false;
	m_IsFalling = true;
}
