#include <SFML/Graphics.hpp>
#include "ParticleSystem.h"

void ParticleSystem::init(int numParticles)
{
	m_Vertices.setPrimitiveType(sf::Points);
	m_Vertices.resize(numParticles);

	for (auto i = 0; i < numParticles; i++)
	{
		srand(time(0) + i);
		float angle = (rand() % 360) * 3.14f / 180.f;
		float speed = (rand() % 600) + 600.f;

		sf::Vector2f direction;

		direction = sf::Vector2f(cos(angle) * speed, sin(angle) * speed);
		m_Particles.push_back(Particle(direction));
	}
}

void ParticleSystem::update(float dt)
{
	m_Duration -= dt;
	int currentVertex = 0;

	for (auto i = m_Particles.begin(); i != m_Particles.end(); i++)
	{
		(*i).update(dt);
		m_Vertices[currentVertex++].position = i->getPosition();
	}

	if (m_Duration < 0)
	{
		m_IsRunning = false;
	}
}

void ParticleSystem::emitPatricles(sf::Vector2f startPosition)
{
	m_IsRunning = true;
	m_Duration = 2;
	int currentVertex = 0;
	for (auto it = m_Particles.begin(); it != m_Particles.end(); it++)
	{
		m_Vertices[currentVertex++].color = sf::Color::Yellow;
		it->setPosition(startPosition);
	}
}

void ParticleSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Vertices, states);
}

bool ParticleSystem::running()
{
	return m_IsRunning;
}