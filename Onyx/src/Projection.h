#pragma once

#include "Core.h"
#include "Math.h"

namespace Onyx
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
			Use the static Orthographic or Perspective functions to create a valid projection.
		 */
		Projection();

		/*
			@brief Creates an orthographic projection with the specified left, right, top, and bottom distances.
			@param screenWidth The width of the screen to calculate the left and right values.
			@param screenHeight The height of the screen to calculate the top and bottom values.
			@return The resulting orthographic projection.
		 */
		static Projection Orthographic(float screenWidth, float screenHeight);

		/*
			@brief Creates a perspective projection with the specified FOV and aspect ratio from the width/height.
			Near plane is set to 0.1, far plane to 100.
			@param fov The desired field of view, in degrees.
			@param screenWidth The width of the screen to calculate the aspect ratio.
			@param screenHeight The height of the screen to calculate the aspect ratio.
			@return The resulting perspective projection.
		 */
		static Projection Perspective(float fov, int screenWidth, int screenHeight);

		/*
			@brief Creates a perspective projection with the specified FOV, aspect ratio from the width/height, and near and far plane distances.
			@param fov The desired field of view, in degrees.
			@param screenWidth The width of the screen to calculate the aspect ratio.
			@param screenHeight The height of the screen to calculate the aspect ratio.
			@param nearPlane The distance to the near plane.
			@param farPlane The distance to the far plane.
			@return The resulting perspective projection.
		 */
		static Projection Perspective(float fov, int screenWidth, int screenHeight, float nearPlane, float farPlane);

		/*
			@brief Gets the type of projection.
		 */
		Onyx::ProjectionType getType() const;

		/*
			@brief Gets the left of the screen.
			@return The left of the screen.
		 */
		float getLeft() const;

		/*
			@brief Gets the right of the screen.
			@return The right of the screen.
		 */
		float getRight() const;

		/*
			@brief Gets the top of the screen.
			@return The top of the screen.
		 */
		float getTop() const;

		/*
			@brief Gets the bottom of the screen.
			@return The bottom of the screen.
		 */
		float getBottom() const;

		/*
			@brief Gets the FOV.
			@return The field of view.
		 */
		float getFOV() const;

		/*
			@brief Gets the aspect ratio.
			@return The aspect ratio (screen width/height).
		 */
		float getAspectRatio() const;

		/*
			@brief Gets the near plane value.
			@return The distance to the near plane.
		 */
		float getNearPlane() const;

		/*
			@brief Gets the far plane value.
			@return The distance to the far plane.
		 */
		float getFarPlane() const;

		/*
			@brief Gets the projection matrix.
			The projection matrix is passed to the shader before rendering an object to project the object's 3D coordinates onto the 2D screen.
			@return The projection matrix.
		 */
		const Onyx::Math::Mat4& getMatrix() const;

		/*
			@brief Sets the left of the screen.
			@param val The left of the screen.
		 */
		void setLeft(float val);

		/*
			@brief Sets the right of the screen.
			@param val The right of the screen.
		 */
		void setRight(float val);

		/*
			@brief Sets the top of the screen.
			@param val The top of the screen.
		 */
		void setTop(float val);

		/*
			@brief Sets the bottom of the screen.
			@param val The bottom of the screen.
		 */
		void setBottom(float val);

		/*
			@brief Sets the FOV.
			@param val The field of view.
		 */
		void setFOV(float val);

		/*
			@brief Sets the aspect ratio.
			@param val The aspect ratio.
		 */
		void setAspectRatio(float val);

		/*
			@brief Sets the near plane value.
			@param val The distance to the near plane.
		 */
		void setNearPlane(float val);

		/*
			@brief Sets the far plane value.
			@param val The distance to the far plane.
		 */
		void setFarPlane(float val);

	private:
		Onyx::ProjectionType m_type;
		float m_left, m_right, m_top, m_bottom, m_fov, m_aspectRatio, m_nearPlane, m_farPlane;

		Onyx::Math::Mat4 m_mat;

		void updateMatrix();
	};
}
