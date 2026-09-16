#pragma warning(disable: 4244)

#include "camera.h"

using onyx::math::Vec3, onyx::math::Mat4, onyx::math::cross,
onyx::math::look_at, onyx::math::radians, onyx::math::degrees;

void onyx_err(const onyx::Error&);

onyx::Camera::Camera()
{
	this->p_win = nullptr;

	this->yaw_ = this->pitch_ = this->pitch_clamp = 0.0f;

	this->view = math::look_at(this->pos, this->pos + this->front, this->up);
}

onyx::Camera::Camera(const Projection& proj)
{
	this->p_win = nullptr;

	this->pos = Vec3(0.0f, 0.0f, 0.0f);
	this->front = Vec3(0.0f, 0.0f, -1.0f);
	this->up = Vec3(0.0f, 1.0f, 0.0f);

	this->yaw_ = this->pitch_ = 0.0f;
	this->proj = proj;
	this->pitch_clamp = 88.0f;

	if (proj.get_type() == onyx::ProjectionType::Perspective) rotate(-90.0f, 0.0f);

	this->view = math::look_at(this->pos, this->pos + this->front, this->up);
}

onyx::Camera::Camera(const Projection& proj, float pitch_clamp)
{
	this->p_win = nullptr;

	this->pos = Vec3(0.0f, 0.0f, 0.0f);
	this->front = Vec3(0.0f, 0.0f, -1.0f);
	this->up = Vec3(0.0f, 1.0f, 0.0f);

	this->yaw_ = this->pitch_ = 0.0f;
	this->proj = proj;
	this->pitch_clamp = pitch_clamp;

	if (proj.get_type() == onyx::ProjectionType::Perspective) rotate(-90.0f, 0.0f);

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
	if (this->p_win != nullptr) if (this->p_win->frame > 0L && this->p_win->frame < 5L || yaw == 0 && pitch == 0) return;

	this->yaw_ += yaw;
	this->pitch_ += pitch;
	if (this->pitch_ > this->pitch_clamp) this->pitch_ = this->pitch_clamp;
	else if (this->pitch_ < -this->pitch_clamp) this->pitch_ = -this->pitch_clamp;
	update_front();
}

//void onyx::Camera::rotate(float yaw, float pitch, const Vec3& origin)
//{
//	if (this->p_win != nullptr) if (this->p_win->frame > 0 && this->p_win->frame < 5 || yaw == 0 && pitch == 0) return;
//
//	if (this->pitch_ + pitch > this->pitch_clamp || this->pitch_ + pitch < -this->pitch_clamp) pitch = 0.0f;
//
//	this->yaw_ += yaw;
//	this->pitch_ += pitch;
//	update_front();
//
//	Vec3 diff = this->pos - origin;
//	this->pos += diff;
//	Vec3 left = cross(this->front, this->up).get_normalized();
//	diff = math::rotate(diff, Vec3(-pitch * left.get_x(), yaw, -pitch * left.get_z()));
//	this->pos -= diff;
//}

void onyx::Camera::pitch(float degrees)
{
	if (this->p_win != nullptr) if (this->p_win->frame > 0L && this->p_win->frame < 5L || degrees == 0) return;
	this->pitch_ += degrees;
	if (this->pitch_ > this->pitch_clamp) this->pitch_ = this->pitch_clamp;
	else if (this->pitch_ < -this->pitch_clamp) this->pitch_ = -this->pitch_clamp;
	update_front();
}

//void onyx::Camera::pitch(float degrees, const math::Vec3& origin)
//{
//	if (this->p_win != nullptr) if (this->p_win->frame > 0 && this->p_win->frame < 5 || degrees == 0) return;
//	if (this->pitch_ + degrees > this->pitch_clamp || this->pitch_ + degrees < -this->pitch_clamp) return;
//	this->pitch_ += degrees;
//	update_front();
//	Vec3 diff = this->pos - origin;
//	this->pos += diff;
//	Vec3 left = cross(this->front, this->up).get_normalized();
//	diff = math::rotate(diff, Vec3(-degrees * left.get_x(), 0.0f, -degrees * left.get_z()));
//	this->pos -= diff;
//}

void onyx::Camera::yaw(float degrees)
{
	if (this->p_win != nullptr) if (this->p_win->frame > 0L && this->p_win->frame < 5L || degrees == 0) return;
	this->yaw_ += degrees;
	update_front();
}

//void onyx::Camera::yaw(float degrees, const math::Vec3& origin)
//{
//	if (this->p_win != nullptr) if (this->p_win->frame > 0 && this->p_win->frame < 5 || degrees == 0) return;
//	this->yaw_ += degrees;
//	update_front();
//	Vec3 diff = this->pos - origin;
//	this->pos += diff;
//	Vec3 left = cross(this->front, this->up).get_normalized();
//	diff = math::rotate(diff, Vec3(0.0f, degrees, 0.0f));
//	this->pos -= diff;
//}

void onyx::Camera::look_at(const Vec3& target)
{
	this->front = (target - this->pos).get_normalized();
	this->yaw_ = degrees(atan2f(this->front.get_z(), this->front.get_x()));
	this->pitch_ = degrees(asinf(this->front.get_y()));
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

void onyx::Camera::set_position(const math::Vec3& pos)
{
	this->pos = pos;
}

void onyx::Camera::set_pitch_clamp(float pitch_clamp)
{
	this->pitch_clamp = pitch_clamp;
}

void onyx::Camera::set_projection(const Projection& proj)
{
	this->proj = proj;
}

void onyx::Camera::set_pitch(float pitch)
{
	if (this->pitch_ + pitch > this->pitch_clamp) this->pitch_ = this->pitch_clamp;
	else if (this->pitch_ + pitch < -this->pitch_clamp) this->pitch_ = -this->pitch_clamp;
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
