#include <onyx/fog.hpp>

using onyx::math::Vec3;

onyx::Fog::Fog()
{
	this->start = this->end = 0.0f;
}

onyx::Fog::Fog(const Vec3& color, float start, float end)
{
	this->start = start;
	this->end = end;
	this->color = color;
}

const Vec3& onyx::Fog::get_color() const
{
	return this->color;
}

float onyx::Fog::get_start() const
{
	return this->start;
}

float onyx::Fog::get_end() const
{
	return this->end;
}

void onyx::Fog::set_color(const Vec3& new_color)
{
	this->color = new_color;
}

void onyx::Fog::set_start(float new_start)
{
	this->start = new_start;
}

void onyx::Fog::set_end(float new_end)
{
	this->end = new_end;
}
