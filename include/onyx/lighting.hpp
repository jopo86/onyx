#pragma once

#include <onyx/math_wrappers.hpp>

namespace onyx
{
	/*
		@brief A class to represent lighting settings for the renderer.
	 */
	class Lighting
	{
	public:
		/*
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
		 */
		Lighting();

		/*
			@brief Creates a new Lighting object with the specified settings.
			@param color The color of the light.
			@param ambient_strength The strength of ambient light.
			@param direction The direction of the light.
		 */
		Lighting(const math::Vec3& color, float ambient_strength, const math::Vec3& direction);

		/*
			@brief Gets the color of the light.
			@return The color of the light.
		 */
		const math::Vec3& get_color() const;

		/*
			@brief Gets the strength of ambient light.
			@return The strength of ambient light.
		 */
		float get_ambient_strength() const;

		/*
			@brief Gets the direction of the light.
			@return The direction of the light.
		 */
		const math::Vec3& get_direction() const;

		/*
			@brief Sets the color of the light.
			@param color The new color of the light.
		 */
		void set_color(const math::Vec3& color);

		/*
			@brief Sets the strength of ambient light.
			@param ambient_strength The new strength of ambient light.
		 */
		void set_ambient_strength(float ambient_strength);

		/*
			@brief Sets the direction of the light.
			@param direction The new direction of the light.
		 */
		void set_direction(const math::Vec3& direction);

	private:
		math::Vec3 color;
		float ambient_strength;
		math::Vec3 direction;
	};
}
