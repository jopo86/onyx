#pragma once

#include "Math.h"

namespace Onyx
{
	/*
		@brief A class to represent fog settings for the renderer.
	 */
	class Fog
	{
	public:
		/*
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
		 */
		Fog();

		/*
			@brief Creates a fog object with the given color and distance values.
			@param color The color of the fog. Most of the time you'll want to use the window's background color.
			@param start The distance from the camera where the fog starts.
			@param end The distance from the camera where the fog ends, objects will be completely colored by the fog at and past this distance.
		 */
		Fog(const Math::Vec3& color, float start, float end);

		/*
			@brief Returns the color of the fog.
			@return The color of the fog.
		 */
		const Math::Vec3& getColor() const;

		/*
			@brief Returns the distance from the camera where the fog starts.
			@return The distance from the camera where the fog starts.
		 */
		float getStart() const;

		/*
			@brief Returns the distance from the camera where the fog ends.
			@return The distance from the camera where the fog ends.
		 */
		float getEnd() const;

		/*
			@brief Sets the color of the fog.
			@param color The new color of the fog.
		 */
		void setColor(const Math::Vec3& color);

		/*
			@brief Sets the distance from the camera where the fog starts.
			@param start The new distance from the camera where the fog starts.
		 */
		void setStart(float start);

		/*
			@brief Sets the distance from the camera where the fog ends.
			@param end The new distance from the camera where the fog ends.
		 */
		void setEnd(float end);

	private:
		Math::Vec3 m_color;
		float m_start;
		float m_end;
	};
}
