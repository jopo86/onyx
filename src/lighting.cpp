#include <onyx/lighting.hpp>

using onyx::math::Vec3;

onyx::Lighting::Lighting()
{
	this->ambient_strength = 0.0f;
}

onyx::Lighting::Lighting(const Vec3& color, float ambient_strength, const Vec3& direction)
{
	this->color = color;
	this->ambient_strength = ambient_strength;
	this->direction = direction;
}

const Vec3& onyx::Lighting::get_color() const
{
	return this->color;
}

float onyx::Lighting::get_ambient_strength() const
{
	return this->ambient_strength;
}

const Vec3& onyx::Lighting::get_direction() const
{
	return this->direction;
}

void onyx::Lighting::set_color(const Vec3& color)
{
	this->color = color;
}

void onyx::Lighting::set_ambient_strength(float ambient_strength)
{
	this->ambient_strength = ambient_strength;
}

void onyx::Lighting::set_direction(const Vec3& direction)
{
	this->direction = direction;
}
