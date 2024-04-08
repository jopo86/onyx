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
			@brief Creates an empty projection.
		 */
		Projection();

		/*
			@brief Creates an orthographic projection with the specified left, right, top, and bottom distances.
			@param left The left of the screen, use -1 for default.
			@param right The right of the screen, use 1 for default.
			@param top The top of the screen, use 1 for default.
			@param bottom The bottom of the screen, use -1 for default.
			@return The resulting orthographic projection.
		 */
		static Projection Orthographic(float left, float right, float top, float bottom);

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
			Updates the projection matrix based on the type of projection from its member variables.
		 */
		void update();

		/*
			@brief Gets the type of projection.
			@return The type of projection - either MG_PROJECTION_TYPE_ORTHOGRAPHIC or MG_PROJECTION_TYPE_PERSPECTIVE.
		 */
		Onyx::ProjectionType getType() const;

		/*
			@brief Gets the left of the screen.
			FOR ORTHOGRAPHIC PROJECTIONS, will return -999 for perspective (if it hasn't been changed by a setter).
			@return The left of the screen.
		 */
		float getLeft() const;

		/*
			@brief Gets the right of the screen.
			FOR ORTHOGRAPHIC PROJECTIONS, will return -999 for perspective (if it hasn't been changed by a setter).
			@return The right of the screen.
		 */
		float getRight() const;

		/*
			@brief Gets the top of the screen.
			FOR ORTHOGRAPHIC PROJECTIONS, will return -999 for perspective (if it hasn't been changed by a setter).
			@return The top of the screen.
		 */
		float getTop() const;

		/*
			@brief Gets the bottom of the screen.
			FOR ORTHOGRAPHIC PROJECTIONS, will return -999 for perspective (if it hasn't been changed by a setter).
			@return The bottom of the screen.
		 */
		float getBottom() const;

		/*
			@brief Gets the FOV.
			FOR PERSPECTIVE PROJECTIONS, will return -999 for orthograhpic (if it hasn't been changed by a setter).
			@return The field of view.
		 */
		float getFOV() const;

		/*
			@brief Gets the aspect ratio.
			FOR PERSPECTIVE PROJECTIONS, will return -999 for orthograhpic (if it hasn't been changed by a setter).
			@return The aspect ratio (screen width/height).
		 */
		float getAspectRatio() const;

		/*
			@brief Gets the near plane value.
			FOR PERSPECTIVE PROJECTIONS, will return -999 for orthograhpic (if it hasn't been changed by a setter).
			@return The distance to the near plane.
		 */
		float getNearPlane() const;

		/*
			@brief Gets the far plane value.
			FOR PERSPECTIVE PROJECTIONS, will return -999 for orthograhpic (if it hasn't been changed by a setter).
			@return The distance to the far plane.
		 */
		float getFarPlane() const;

		/*
			@brief Gets the projection matrix.
			The projection matrix is passed to the shader before rendering an object to project the object's 3D coordinates onto the 2D screen.
			@return The projection matrix.
		 */
		Onyx::Math::Mat4 getMatrix() const;

		/*
			@brief Sets the left of the screen.
			MATRIX MUST BE UPDATED TO APPLY CHANGES (updateMatrixOrtho() / updateMatrixPersp()).
			@param val The left of the screen.
		 */
		void setLeft(float val);

		/*
			@brief Sets the right of the screen.
			MATRIX MUST BE UPDATED TO APPLY CHANGES (updateMatrixOrtho() / updateMatrixPersp()).
			@param val The right of the screen.
		 */
		void setRight(float val);

		/*
			@brief Sets the top of the screen.
			MATRIX MUST BE UPDATED TO APPLY CHANGES (updateMatrixOrtho() / updateMatrixPersp()).
			@param val The top of the screen.
		 */
		void setTop(float val);

		/*
			@brief Sets the bottom of the screen.
			MATRIX MUST BE UPDATED TO APPLY CHANGES (updateMatrixOrtho() / updateMatrixPersp()).
			@param val The bottom of the screen.
		 */
		void setBottom(float val);

		/*
			@brief Sets the FOV.
			MATRIX MUST BE UPDATED TO APPLY CHANGES (updateMatrixOrtho() / updateMatrixPersp()).
			@param val The field of view.
		 */
		void setFOV(float val);

		/*
			@brief Sets the aspect ratio.
			MATRIX MUST BE UPDATED TO APPLY CHANGES (updateMatrixOrtho() / updateMatrixPersp()).
			@param val The aspect ratio.
		 */
		void setAspectRatio(float val);

		/*
			@brief Sets the near plane value.
			MATRIX MUST BE UPDATED TO APPLY CHANGES (updateMatrixOrtho() / updateMatrixPersp()).
			@param val The distance to the near plane.
		 */
		void setNearPlane(float val);

		/*
			@brief Sets the far plane value.
			MATRIX MUST BE UPDATED TO APPLY CHANGES (updateMatrixOrtho() / updateMatrixPersp()).
			@param val The distance to the far plane.
		 */
		void setFarPlane(float val);

	private:
		Onyx::ProjectionType type;
		float left, right, top, bottom, fov, aspectRatio, nearPlane, farPlane;

		Onyx::Math::Mat4 mat;
	};
}
