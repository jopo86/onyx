#include "Lighting.h"

using Onyx::Math::Vec3;

Onyx::Lighting::Lighting()
{
	ambientStrength = 0.0f;
}

Onyx::Lighting::Lighting(const Vec3& color, float ambientStrength, const Vec3& direction)
{
	this->color = color;
	this->ambientStrength = ambientStrength;
	this->direction = direction;
}

const Vec3& Onyx::Lighting::getColor() const
{
	return color;
}

float Onyx::Lighting::getAmbientStrength() const
{
	return ambientStrength;
}

const Vec3& Onyx::Lighting::getDirection() const
{
	return direction;
}

void Onyx::Lighting::setColor(const Vec3& color)
{
	this->color = color;
}

void Onyx::Lighting::setAmbientStrength(float ambientStrength)
{
	this->ambientStrength = ambientStrength;
}

void Onyx::Lighting::setDirection(const Vec3& direction)
{
	this->direction = direction;
}
