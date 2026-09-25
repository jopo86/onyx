#include <onyx/camera.hpp>

#include <cmath>

#include "internal.hpp"

using onyx::math::Vec3, onyx::math::Mat4, onyx::math::cross,
onyx::math::look_at, onyx::math::radians, onyx::math::degrees;

// pitch clamps of 90 degrees or more make the front vector parallel to the up vector, producing a degenerate (NaN) view matrix
static constexpr float MAX_PITCH_CLAMP = 89.9f;

onyx::Camera::Camera()
{
	this->p_win = nullptr;

	this->pos = Vec3(0.0f, 0.0f, 0.0f);
	this->front = Vec3(0.0f, 0.0f, -1.0f);
	this->up = Vec3(0.0f, 1.0f, 0.0f);

	// yaw of -90 degrees corresponds to the front vector (0, 0, -1) in update_front()
	this->yaw_ = -90.0f;
	this->pitch_ = 0.0f;
	this->pitch_clamp = 88.0f;

	this->view = math::look_at(this->pos, this->pos + this->front, this->up);
}

onyx::Camera::Camera(const Projection& proj)
{
	this->p_win = nullptr;

	this->pos = Vec3(0.0f, 0.0f, 0.0f);
	this->front = Vec3(0.0f, 0.0f, -1.0f);
	this->up = Vec3(0.0f, 1.0f, 0.0f);

	// yaw of -90 degrees corresponds to the front vector (0, 0, -1) in update_front()
	this->yaw_ = -90.0f;
	this->pitch_ = 0.0f;
	this->proj = proj;
	this->pitch_clamp = 88.0f;

	this->view = math::look_at(this->pos, this->pos + this->front, this->up);
}

onyx::Camera::Camera(const Projection& proj, float pitch_clamp)
{
	this->p_win = nullptr;

	this->pos = Vec3(0.0f, 0.0f, 0.0f);
	this->front = Vec3(0.0f, 0.0f, -1.0f);
	this->up = Vec3(0.0f, 1.0f, 0.0f);

	// yaw of -90 degrees corresponds to the front vector (0, 0, -1) in update_front()
	this->yaw_ = -90.0f;
	this->pitch_ = 0.0f;
	this->proj = proj;
	this->pitch_clamp = math::clamp(pitch_clamp, 0.0f, MAX_PITCH_CLAMP);

	this->view = math::look_at(this->pos, this->pos + this->front, this->up);
}

void onyx::Camera::update()
{
	if (this->p_win == nullptr)
	{
		onyx_err(Error{
			   .source_function = "onyx::Camera::update()",
			   .message = "Window pointer is null.",
			   .how_to_fix = "Make sure the camera was linked to a window (Window::link_camera())."
			}
		);
		return;
	}
	this->view = math::look_at(this->pos, this->pos + this->front, this->up);
	this->p_win->num_frames_cam_not_updated = 0;
}

void onyx::Camera::translate_lr(float dist)
{
	if (dist == 0) return;
	this->pos += (Vec3(cross(this->front, this->up)).get_normalized() * dist);
}

void onyx::Camera::translate_ud(float dist)
{
	if (dist == 0) return;
	this->pos += Vec3(0.0f, dist, 0.0f);
}

void onyx::Camera::translate_fb(float dist)
{
	if (dist == 0) return;
	this->pos += (this->front * dist);
}

void onyx::Camera::translate(const Vec3& LR_UD_FB)
{
	if (LR_UD_FB.is_zero()) return;
	this->pos += (Vec3(cross(this->front, this->up)).get_normalized() * LR_UD_FB.get_x());
	this->pos += Vec3(0.0f, LR_UD_FB.get_y(), 0.0f);
	this->pos += (this->front * LR_UD_FB.get_z());
}

void onyx::Camera::translate_global(const Vec3& xyz)
{
	this->pos += xyz;
}

void onyx::Camera::rotate(float yaw, float pitch)
{
	// TODO: replace the frame 1-4 hack with proper first-mouse handling (the first mouse deltas after window creation are huge)
	if (this->p_win != nullptr) if ((this->p_win->frame > 0L && this->p_win->frame < 5L) || (yaw == 0 && pitch == 0)) return;

	this->yaw_ += yaw;
	this->pitch_ += pitch;
	if (this->pitch_ > this->pitch_clamp) this->pitch_ = this->pitch_clamp;
	else if (this->pitch_ < -this->pitch_clamp) this->pitch_ = -this->pitch_clamp;
	update_front();
}

void onyx::Camera::pitch(float degrees)
{
	// TODO: replace the frame 1-4 hack with proper first-mouse handling (see rotate())
	if (this->p_win != nullptr) if ((this->p_win->frame > 0L && this->p_win->frame < 5L) || degrees == 0) return;
	this->pitch_ += degrees;
	if (this->pitch_ > this->pitch_clamp) this->pitch_ = this->pitch_clamp;
	else if (this->pitch_ < -this->pitch_clamp) this->pitch_ = -this->pitch_clamp;
	update_front();
}

void onyx::Camera::yaw(float degrees)
{
	// TODO: replace the frame 1-4 hack with proper first-mouse handling (see rotate())
	if (this->p_win != nullptr) if ((this->p_win->frame > 0L && this->p_win->frame < 5L) || degrees == 0) return;
	this->yaw_ += degrees;
	update_front();
}

void onyx::Camera::look_at(const Vec3& target)
{
	Vec3 dir = target - this->pos;
	if (dir.magnitude() < 1e-6f) return;
	dir.normalize();

	// keep the current yaw if looking (almost) straight up/down, where yaw is undefined
	if (fabsf(dir.get_x()) > 1e-6f || fabsf(dir.get_z()) > 1e-6f) this->yaw_ = degrees(atan2f(dir.get_z(), dir.get_x()));
	this->pitch_ = math::clamp(degrees(asinf(math::clamp(dir.get_y(), -1.0f, 1.0f))), -this->pitch_clamp, this->pitch_clamp);
	update_front();
}

const Vec3& onyx::Camera::get_position() const
{
	return this->pos;
}

const onyx::Projection& onyx::Camera::get_projection() const
{
	return this->proj;
}

const Mat4& onyx::Camera::get_view_matrix() const
{
	return this->view;
}

const Mat4& onyx::Camera::get_projection_matrix() const
{
	return this->proj.get_matrix();
}

const Vec3& onyx::Camera::get_front() const
{
	return this->front;
}

const Vec3& onyx::Camera::get_up() const
{
	return this->up;
}

float onyx::Camera::get_yaw() const
{
	return this->yaw_;
}

float onyx::Camera::get_pitch() const
{
	return this->pitch_;
}

void onyx::Camera::set_position(const math::Vec3& new_pos)
{
	this->pos = new_pos;
}

void onyx::Camera::set_pitch_clamp(float new_pitch_clamp)
{
	this->pitch_clamp = math::clamp(new_pitch_clamp, 0.0f, MAX_PITCH_CLAMP);
	set_pitch(this->pitch_);
}

void onyx::Camera::set_projection(const Projection& new_proj)
{
	this->proj = new_proj;
}

void onyx::Camera::set_pitch(float pitch)
{
	if (pitch > this->pitch_clamp) this->pitch_ = this->pitch_clamp;
	else if (pitch < -this->pitch_clamp) this->pitch_ = -this->pitch_clamp;
	else this->pitch_ = pitch;
	update_front();
}

void onyx::Camera::set_yaw(float yaw)
{
	this->yaw_ = yaw;
	update_front();
}

void onyx::Camera::set_fov(float fov)
{
	this->proj.set_fov(fov);
}

void onyx::Camera::set_view_distance(float dist)
{
	this->proj.set_far_plane(dist);
}

void onyx::Camera::update_front()
{
	float yaw_rad = radians(this->yaw_);
	float pitch_rad = radians(this->pitch_);

	this->front.set_x(cosf(yaw_rad) * cosf(pitch_rad));
	this->front.set_y(sinf(pitch_rad));
	this->front.set_z(sinf(yaw_rad) * cosf(pitch_rad));
	this->front.normalize();
}
