#pragma once

#include "Math.h"

namespace Onyx
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
			@param ambientStrength The strength of ambient light.
			@param direction The direction of the light.
		 */
		Lighting(const Math::Vec3& color, float ambientStrength, const Math::Vec3& direction);

		/*
			@brief Gets the color of the light.
			@return The color of the light.
		 */
		const Math::Vec3& getColor() const;

		/*
			@brief Gets the strength of ambient light.
			@return The strength of ambient light.
		 */
		float getAmbientStrength() const;

		/*
			@brief Gets the direction of the light.
			@return The direction of the light.
		 */
		const Math::Vec3& getDirection() const;

		/*
			@brief Sets the color of the light.
			@param color The new color of the light.
		 */
		void setColor(const Math::Vec3& color);

		/*
			@brief Sets the strength of ambient light.
			@param ambientStrength The new strength of ambient light.
		 */
		void setAmbientStrength(float ambientStrength);

		/*
			@brief Sets the direction of the light.
			@param direction The new direction of the light.
		 */
		void setDirection(const Math::Vec3& direction);

	private:
		Math::Vec3 m_color;
		float m_ambientStrength;
		Math::Vec3 m_direction;
	};
}
