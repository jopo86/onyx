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
			@brief Default constructor, initializes the color to black and the start and end distances to 0.
			With these values everything is fully fogged, so set the distances before using the object.
		 */
		Fog();

		/*
			@brief Creates a fog object with the given color and distance values.
			@param color The color of the fog. Most of the time you'll want to use the window's background color.
			@param start The distance from the camera where the fog starts.
			@param end The distance from the camera where the fog ends, objects will be completely colored by the fog at and past this distance.
			Should be greater than start; if end <= start everything past start is fully fogged.
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
			@param new_color The new color of the fog.
		 */
		void set_color(const math::Vec3& new_color);

		/*
			@brief Sets the distance from the camera where the fog starts.
			@param new_start The new distance from the camera where the fog starts.
		 */
		void set_start(float new_start);

		/*
			@brief Sets the distance from the camera where the fog ends.
			@param new_end The new distance from the camera where the fog ends.
		 */
		void set_end(float new_end);

	private:
		math::Vec3 color;
		float start;
		float end;
	};
}
