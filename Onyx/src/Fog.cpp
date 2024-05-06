#include "Fog.h"

using Onyx::Math::Vec3;

Onyx::Fog::Fog()
{
	m_start = m_end = 0.0f;
}

Onyx::Fog::Fog(const Vec3& color, float start, float end)
{
	m_start = start;
	m_end = end;
	m_color = color;
}

const Vec3& Onyx::Fog::getColor() const
{
	return m_color;
}

float Onyx::Fog::getStart() const
{
	return m_start;
}

float Onyx::Fog::getEnd() const
{
	return m_end;
}

void Onyx::Fog::setColor(const Vec3& color)
{
	m_color = color;
}

void Onyx::Fog::setStart(float start)
{
	m_start = start;
}

void Onyx::Fog::setEnd(float end)
{
	m_end = end;
}
