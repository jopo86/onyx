#pragma once

#include "Core.h"
#include "Projection.h"
#include "Math.h"
#include "Window.h"

namespace Onyx
{

	/*
		@brief A class to represent a camera.
		To be used by the renderer to render objects from the POV of the camera.
	 */
	class Camera
	{
		friend class Renderer;
		friend class Window;

	public:
		/*
			@brief Creates an empty camera.
			Trying to use a camera constructed like this will result in undefined behavior.
		 */
		Camera();

		/*
			@brief Creates a camera, orthographic by default.
			Camera starts at (0, 0, 0) facing the negative (forward) z-axis.
			Pitch clamp is set to 89 degrees by default.
			@param window The window that the camera is used for.
		 */
		Camera(Window& window);

		/*
			@brief Creates a camera with the specified projection.
			Camera starts at (0, 0, 0) facing the negative (forward) z-axis.
			Pitch clamp is set to 89 degrees by default.
			@param window The window that the camera is used for.
			@param proj The projection to use.
		 */
		Camera(Window& window, Projection proj);

		/*
			@brief Creates a camera with the specified projection and pitch limit.
			Camera starts at (0, 0, 0) facing the negative (forward) z-axis.
			@param window The window that the camera is used for.
			@param proj The projection to use.
			@param pitchLimit The pitch limit to use.
		 */
		Camera(Window& window, Projection proj, float pitchLimit);

		/*
			@brief Updates the view matrix of the camera.
			The renderer uses the view matrix to render objects from the camera's POV.
			This should be called every frame after the camera has been translated/rotated.
		 */
		void update();

		/*
			@brief Translates/moves the camera left/right from the camera's POV.
			This IS NOT the same as moving along the x-axis.
			@param dist The distance to move. (-) left, (+) right
		 */
		void translateLR(float dist);

		/*
			@brief Translates/moves the camera up/down from the camera's POV.
			This IS the same as moving along the y-axis.
			@param dist The distance to move. (+) up, (-) down
		 */
		void translateUD(float dist);

		/*
			@brief Translates/moves the camera forward/backward from the camera's POV.
			This IS NOT the same as moving along the z-axis.
			@param dist The distance to move. (+) forward, (-) backward
		 */
		void translateFB(float dist);

		/*
			@brief Translates/moves the camera relative to its POV.
			This IS NOT the same as moving along the xyz axis.
			@param dist The distance to move left/right, up/down, and forward/backward for the 3 values respectively.
			lr: (-) left, (+) right
			ud: (+) up, (-) down
			fb: (+) forward, (-) backward
		 */
		void translate(Onyx::Math::Vec3 LR_UD_FB);

		/*
			@brief Rotates the camera the specified angles.
			@param yaw The angle along (not about) the x-axis, AKA yaw, in degrees.
			@param pitch The angle along (not about) the y-axis, AKA pitch, in degrees.
		 */
		void rotate(float yaw, float pitch);

		/*
			@brief Gets the position of camera.
			@return The position of the camera.
		 */
		Onyx::Math::Vec3 getPosition() const;

		/*
			@brief Gets the projection of the camera.
			@return The projection of the camera.
		 */
		Projection getProjection() const;

		/*
			@brief Gets the view matrix of the camera.
			Used by the renderer to render objects from the camera's POV.
			@return The view matrix.
		 */
		Onyx::Math::Mat4 getViewMatrix() const;

		/*
			@brief Gets the projection matrix of the camera.
			Used by the renderer to render objects with perspective or orthographically.
			@return The projection matrix.
		 */
		Onyx::Math::Mat4 getProjectionMatrix() const;

		/*
			@brief Sets the pitch limit of the camera.
			The pitch limit is the maximum angle the camera can look up/down.
			90 degrees will allow the camera to look no further than straight up/down.
			The default is 89 degrees.
			@param pitchLimit The desired pitch limit, in degrees.
		 */
		void setPitchLimit(float pitchLimit);

		/*
			@brief Sets the projection of the camera.
			@param proj The projection of the camera.
		 */
		void setProjection(Projection proj);

	private:
		Window* p_win;

		Onyx::Math::Vec3 pos;
		Onyx::Math::Vec3 front;
		Onyx::Math::Vec3 up;

		float yaw;
		float pitch;

		float pitchClamp;

		Projection proj;

		Onyx::Math::Mat4 view;
	};

}
