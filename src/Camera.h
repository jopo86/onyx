#pragma once

#include "Window.h"
#include "Renderer.h"
#include "Projection.h"
#include "Math.h"

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
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
		 */
		Camera();

		/*
			@brief Creates a camera with the specified projection.
		 !  MUST BE LINKED TO A WINDOW FOR PROPER PROJECTION
		 !  Use `Window::linkCamera()`
			Camera starts at (0, 0, 0) facing the negative (forward) z-axis.
			Pitch clamp is set to 89 degrees by default.
			@param proj The projection to use.
		 */
		Camera(const Projection& proj);

		/*
			@brief Creates a camera with the specified projection and pitch limit.
		 !  MUST BE LINKED TO A WINDOW FOR PROPER PROJECTION
		 !  Use `Window::linkCamera()`
			Camera starts at (0, 0, 0) facing the negative (forward) z-axis.
			@param proj The projection to use.
			@param pitchLimit The pitch limit to use.
		 */
		Camera(const Projection& proj, float pitchLimit);

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
			@param LR_UD_FB The distance to move left/right, up/down, and forward/backward for the 3 values respectively.
			lr: (-) left, (+) right
			ud: (+) up, (-) down
			fb: (+) forward, (-) backward
		 */
		void translate(const Math::Vec3& LR_UD_FB);

		/*
			@brief Translates/moves the camera absolutely, instead of relative to its POV.
			@param xyz The translation.
		 */
		void translateGlobal(const Math::Vec3& xyz);

		/*
			@brief Rotates the camera the specified angles.
			@param yaw The angle around the local Y axis (horizontal angle), AKA yaw, in degrees.
			@param pitch The angle around the local X axis (vertical angle), AKA pitch, in degrees.
		 */
		void rotate(float yaw, float pitch);

		/*
			@brief Pitches the camera the specified degrees.
		 !	Currently bugged - camera seems to slowly stray further from origin
			@param degrees The degrees to pitch the camera (around the local X axis).
		*/
		void pitch(float degrees);

		/*
			@brief Yaws the camera the specified degrees.
		 !	Currently bugged - camera seems to slowly stray further from origin
			@param degrees The degrees to yaw the camera (around the local Y axis).
		 */
		void yaw(float degrees);

		/*
			@brief Faces the camera towards the target.
			@param target The target to look at.
		 */
		void lookAt(const Math::Vec3& target);

		/*
			@brief Gets the position of camera.
			@return The position of the camera.
		 */
		const Math::Vec3& getPosition() const;

		/*
			@brief Gets the projection of the camera.
			@return The projection of the camera.
		 */
		const Projection& getProjection() const;

		/*
			@brief Gets the view matrix of the camera.
			Used by the renderer to render objects from the camera's POV.
			@return The view matrix.
		 */
		const Math::Mat4& getViewMatrix() const;

		/*
			@brief Gets the projection matrix of the camera.
			Used by the renderer to render objects with perspective or orthographically.
			@return The projection matrix.
		 */
		const Math::Mat4& getProjectionMatrix() const;

		/*
			@brief Gets the front vector of the camera.
			The left vector can be created using the cross product of the front and up vectors.
			@return The front vector of the camera.
		 */
		const Math::Vec3& getFront() const;

		/*
			@brief Gets the up vector of the camera.
			The left vector can be created using the cross product of the front and up vectors.
			@return The up vector of the camera.
		 */
		const Math::Vec3& getUp() const;

		/*
			@brief Gets the yaw of the camera.
			@return The yaw of the camera.
		 */
		float getYaw() const;

		/*
			@brief Gets the pitch of the camera.
			@return The pitch of the camera.
		 */
		float getPitch() const;

		/*
			@brief Sets the position of the camera.
			@param pos The desired position of the camera.
		 */
		void setPosition(const Math::Vec3& pos);

		/*
			@brief Sets the pitch clamp of the camera.
			The pitch clamp is the maximum angle the camera can look up/down.
			90 degrees will allow the camera to look no further than straight up/down.
			The default is 89 degrees.
			@param pitchClamp The desired pitch clamp, in degrees.
		 */
		void setPitchClamp(float pitchClamp);

		/*
			@brief Sets the projection of the camera.
			@param proj The projection of the camera.
		 */
		void setProjection(const Projection& proj);

		/*
			@brief Sets the pitch of the camera.
			@param pitch The desired pitch.
		 */
		void setPitch(float pitch);

		/*
			@brief Sets the yaw of the camera.
			@param yaw The desired yaw.
		 */
		void setYaw(float yaw);

		/*
			@brief Sets the FOV of the camera's projection.
		 !  Only works if the camera's projection is perspective.
			@param fov The desired FOV.
		 */
		void setFOV(float fov);

		/*
			@brief Sets the view distance of the camera.
			If not set for the projection, the default is 100.
			This sets the far plane of the projection.
		 !	Only works if the camera's projection is perspective.
			@param dist The desired view distance.
		 */
		void setViewDistance(float dist);

	private:
		Window* m_pWin;

		Math::Vec3 m_pos;
		Math::Vec3 m_front;
		Math::Vec3 m_up;

		float m_yaw;
		float m_pitch;

		float m_pitchClamp;

		Projection m_proj;

		Math::Mat4 m_view;

		void updateFront();
	};

}
