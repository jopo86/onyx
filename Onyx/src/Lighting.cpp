#include "Lighting.h"

using Onyx::Math::Vec3;

Onyx::Lighting::Lighting()
{
	m_ambientStrength = 0.0f;
}

Onyx::Lighting::Lighting(const Vec3& color, float ambientStrength, const Vec3& direction)
{
	m_color = color;
	m_ambientStrength = ambientStrength;
	m_direction = direction;
}

const Vec3& Onyx::Lighting::getColor() const
{
	return m_color;
}

float Onyx::Lighting::getAmbientStrength() const
{
	return m_ambientStrength;
}

const Vec3& Onyx::Lighting::getDirection() const
{
	return m_direction;
}

void Onyx::Lighting::setColor(const Vec3& color)
{
	m_color = color;
}

void Onyx::Lighting::setAmbientStrength(float ambientStrength)
{
	m_ambientStrength = ambientStrength;
}

void Onyx::Lighting::setDirection(const Vec3& direction)
{
	m_direction = direction;
}
