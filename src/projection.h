#pragma once

#include "core.h"
#include "math.h"

namespace onyx
{
	/*
		@brief A class for handling projection matrices for MgCameras.
	 */
	class Projection
	{
	public:
		/*
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
			Use the static orthographic or perspective functions to create a valid projection.
		 */
		Projection();

		/*
			@brief Creates an orthographic projection with the specified left, right, top, and bottom distances.
			@param screen_width The width of the screen to calculate the left and right values.
			@param screen_height The height of the screen to calculate the top and bottom values.
			@return The resulting orthographic projection.
		 */
		static Projection orthographic(float screen_width, float screen_height);

		/*
			@brief Creates a perspective projection with the specified FOV and aspect ratio from the width/height.
			Near plane is set to 0.1, far plane to 100.
			@param fov The desired field of view, in degrees.
			@param screen_width The width of the screen to calculate the aspect ratio.
			@param screen_height The height of the screen to calculate the aspect ratio.
			@return The resulting perspective projection.
		 */
		static Projection perspective(float fov, int screen_width, int screen_height);

		/*
			@brief Creates a perspective projection with the specified FOV, aspect ratio from the width/height, and near and far plane distances.
			@param fov The desired field of view, in degrees.
			@param screen_width The width of the screen to calculate the aspect ratio.
			@param screen_height The height of the screen to calculate the aspect ratio.
			@param near_plane The distance to the near plane.
			@param far_plane The distance to the far plane.
			@return The resulting perspective projection.
		 */
		static Projection perspective(float fov, int screen_width, int screen_height, float near_plane, float far_plane);

		/*
			@brief Gets the type of projection.
		 */
		onyx::ProjectionType get_type() const;

		/*
			@brief Gets the left of the screen.
			@return The left of the screen.
		 */
		float get_left() const;

		/*
			@brief Gets the right of the screen.
			@return The right of the screen.
		 */
		float get_right() const;

		/*
			@brief Gets the top of the screen.
			@return The top of the screen.
		 */
		float get_top() const;

		/*
			@brief Gets the bottom of the screen.
			@return The bottom of the screen.
		 */
		float get_bottom() const;

		/*
			@brief Gets the FOV.
			@return The field of view.
		 */
		float get_fov() const;

		/*
			@brief Gets the aspect ratio.
			@return The aspect ratio (screen width/height).
		 */
		float get_aspect_ratio() const;

		/*
			@brief Gets the near plane value.
			@return The distance to the near plane.
		 */
		float get_near_plane() const;

		/*
			@brief Gets the far plane value.
			@return The distance to the far plane.
		 */
		float get_far_plane() const;

		/*
			@brief Gets the projection matrix.
			The projection matrix is passed to the shader before rendering an object to project the object's 3D coordinates onto the 2D screen.
			@return The projection matrix.
		 */
		const onyx::math::Mat4& get_matrix() const;

		/*
			@brief Sets the left of the screen.
			@param val The left of the screen.
		 */
		void set_left(float val);

		/*
			@brief Sets the right of the screen.
			@param val The right of the screen.
		 */
		void set_right(float val);

		/*
			@brief Sets the top of the screen.
			@param val The top of the screen.
		 */
		void set_top(float val);

		/*
			@brief Sets the bottom of the screen.
			@param val The bottom of the screen.
		 */
		void set_bottom(float val);

		/*
			@brief Sets the FOV.
			@param val The field of view.
		 */
		void set_fov(float val);

		/*
			@brief Sets the aspect ratio.
			@param val The aspect ratio.
		 */
		void set_aspect_ratio(float val);

		/*
			@brief Sets the near plane value.
			@param val The distance to the near plane.
		 */
		void set_near_plane(float val);

		/*
			@brief Sets the far plane value.
			@param val The distance to the far plane.
		 */
		void set_far_plane(float val);

	private:
		onyx::ProjectionType type;
		float left, right, top, bottom, fov, aspect_ratio, near_plane, far_plane;

		onyx::math::Mat4 mat;

		void update_matrix();
	};
}
