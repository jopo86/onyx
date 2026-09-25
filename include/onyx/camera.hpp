#pragma once

#include <onyx/window.hpp>
#include <onyx/renderer.hpp>
#include <onyx/projection.hpp>
#include <onyx/math_wrappers.hpp>

namespace onyx
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
			The camera starts at (0, 0, 0) facing the negative (forward) z-axis, but has no projection.
			Using an object created with this constructor will result in undefined behavior.
		 */
		Camera();

		/*
			@brief Creates a camera with the specified projection.
		 !  MUST BE LINKED TO A WINDOW FOR PROPER PROJECTION
		 !  Use `Window::link_camera()`
			Camera starts at (0, 0, 0) facing the negative (forward) z-axis.
			Pitch clamp is set to 88 degrees by default.
			@param proj The projection to use.
		 */
		Camera(const Projection& proj);

		/*
			@brief Creates a camera with the specified projection and pitch limit.
		 !  MUST BE LINKED TO A WINDOW FOR PROPER PROJECTION
		 !  Use `Window::link_camera()`
			Camera starts at (0, 0, 0) facing the negative (forward) z-axis.
			@param proj The projection to use.
			@param pitch_limit The pitch limit to use, in degrees (clamped to between 0 and 89.9).
		 */
		Camera(const Projection& proj, float pitch_limit);

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
		void translate_lr(float dist);

		/*
			@brief Translates/moves the camera up/down from the camera's POV.
			This IS the same as moving along the y-axis.
			@param dist The distance to move. (+) up, (-) down
		 */
		void translate_ud(float dist);

		/*
			@brief Translates/moves the camera forward/backward from the camera's POV.
			This IS NOT the same as moving along the z-axis.
			@param dist The distance to move. (+) forward, (-) backward
		 */
		void translate_fb(float dist);

		/*
			@brief Translates/moves the camera relative to its POV.
			This IS NOT the same as moving along the xyz axis.
			@param LR_UD_FB The distance to move left/right, up/down, and forward/backward for the 3 values respectively.
			lr: (-) left, (+) right
			ud: (+) up, (-) down
			fb: (+) forward, (-) backward
		 */
		void translate(const math::Vec3& LR_UD_FB);

		/*
			@brief Translates/moves the camera absolutely, instead of relative to its POV.
			@param xyz The translation.
		 */
		void translate_global(const math::Vec3& xyz);

		/*
			@brief Rotates the camera the specified angles.
			The resulting pitch is clamped to the pitch clamp (see set_pitch_clamp()).
			@param yaw The angle around the local Y axis (horizontal angle), AKA yaw, in degrees.
			@param pitch The angle around the local X axis (vertical angle), AKA pitch, in degrees.
		 */
		void rotate(float yaw, float pitch);

		/*
			@brief Pitches the camera the specified degrees.
			The resulting pitch is clamped to the pitch clamp (see set_pitch_clamp()).
			@param degrees The degrees to pitch the camera (around the local X axis).
		 */
		void pitch(float degrees);

		/*
			@brief Yaws the camera the specified degrees.
			@param degrees The degrees to yaw the camera (around the local Y axis).
		 */
		void yaw(float degrees);

		/*
			@brief Faces the camera towards the target.
			The resulting pitch is clamped to the pitch clamp (see set_pitch_clamp()).
			If the target is (almost) straight above/below the camera, the current yaw is kept.
			If the target is at the camera's position, this function does nothing.
			@param target The target to look at.
		 */
		void look_at(const math::Vec3& target);

		/*
			@brief Gets the position of camera.
			@return The position of the camera.
		 */
		const math::Vec3& get_position() const;

		/*
			@brief Gets the projection of the camera.
			@return The projection of the camera.
		 */
		const Projection& get_projection() const;

		/*
			@brief Gets the view matrix of the camera.
			Used by the renderer to render objects from the camera's POV.
			@return The view matrix.
		 */
		const math::Mat4& get_view_matrix() const;

		/*
			@brief Gets the projection matrix of the camera.
			Used by the renderer to render objects with perspective or orthographically.
			@return The projection matrix.
		 */
		const math::Mat4& get_projection_matrix() const;

		/*
			@brief Gets the front vector of the camera.
			The left vector can be created using the cross product of the front and up vectors.
			@return The front vector of the camera.
		 */
		const math::Vec3& get_front() const;

		/*
			@brief Gets the up vector of the camera.
			The left vector can be created using the cross product of the front and up vectors.
			@return The up vector of the camera.
		 */
		const math::Vec3& get_up() const;

		/*
			@brief Gets the yaw of the camera.
			@return The yaw of the camera.
		 */
		float get_yaw() const;

		/*
			@brief Gets the pitch of the camera.
			@return The pitch of the camera.
		 */
		float get_pitch() const;

		/*
			@brief Sets the position of the camera.
			@param new_pos The desired position of the camera.
		 */
		void set_position(const math::Vec3& new_pos);

		/*
			@brief Sets the pitch clamp of the camera.
			The pitch clamp is the maximum angle the camera can look up/down.
			The value is clamped to between 0 and 89.9 degrees, as looking exactly straight up/down (90 degrees) results in a degenerate view matrix.
			The current pitch is re-clamped to the new pitch clamp.
			The default is 88 degrees.
			@param new_pitch_clamp The desired pitch clamp, in degrees.
		 */
		void set_pitch_clamp(float new_pitch_clamp);

		/*
			@brief Sets the projection of the camera.
			@param new_proj The projection of the camera.
		 */
		void set_projection(const Projection& new_proj);

		/*
			@brief Sets the pitch of the camera.
			The pitch is clamped to the pitch clamp (see set_pitch_clamp()).
			@param pitch The desired pitch, in degrees.
		 */
		void set_pitch(float pitch);

		/*
			@brief Sets the yaw of the camera.
			A yaw of -90 degrees faces the negative (forward) z-axis.
			@param yaw The desired yaw, in degrees.
		 */
		void set_yaw(float yaw);

		/*
			@brief Sets the FOV of the camera's projection.
		 !  Only works if the camera's projection is perspective.
			@param fov The desired FOV.
		 */
		void set_fov(float fov);

		/*
			@brief Sets the view distance of the camera.
			If not set for the projection, the default is 100.
			This sets the far plane of the projection.
		 !	Only works if the camera's projection is perspective.
			@param dist The desired view distance.
		 */
		void set_view_distance(float dist);

	private:
		Window* p_win;

		math::Vec3 pos;
		math::Vec3 front;
		math::Vec3 up;

		float yaw_;
		float pitch_;

		float pitch_clamp;

		Projection proj;

		math::Mat4 view;

		void update_front();
	};

}
