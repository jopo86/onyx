#pragma once

#include <onyx/math_wrappers.hpp>

namespace onyx
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
		Fog(const math::Vec3& color, float start, float end);

		/*
			@brief Returns the color of the fog.
			@return The color of the fog.
		 */
		const math::Vec3& get_color() const;

		/*
			@brief Returns the distance from the camera where the fog starts.
			@return The distance from the camera where the fog starts.
		 */
		float get_start() const;

		/*
			@brief Returns the distance from the camera where the fog ends.
			@return The distance from the camera where the fog ends.
		 */
		float get_end() const;

		/*
			@brief Sets the color of the fog.
			@param color The new color of the fog.
		 */
		void set_color(const math::Vec3& color);

		/*
			@brief Sets the distance from the camera where the fog starts.
			@param start The new distance from the camera where the fog starts.
		 */
		void set_start(float start);

		/*
			@brief Sets the distance from the camera where the fog ends.
			@param end The new distance from the camera where the fog ends.
		 */
		void set_end(float end);

	private:
		math::Vec3 color;
		float start;
		float end;
	};
}
