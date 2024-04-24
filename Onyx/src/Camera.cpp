#include "Camera.h"

using Onyx::Math::Vec3;
using Onyx::Math::Mat4; 
using Onyx::Math::Cross;
using Onyx::Math::LookAt;
using Onyx::Math::Radians;

Onyx::Camera::Camera()
{
	p_win = nullptr;

	yaw = pitch = pitchClamp = 0.0f;

	update();
}

Onyx::Camera::Camera(Window& window)
{
	p_win = &window;
	window.p_cam = this;

	pos = Vec3(0.0f, 0.0f, 0.0f);
	front = Vec3(0.0f, 0.0f, -1.0f);
	up = Vec3(0.0f, 1.0f, 0.0f);

	yaw = pitch = 0.0f;
	proj = Projection::Orthographic(-1.0f, 1.0f, 1.0f, -1.0f);
	pitchClamp = 88.0f;

	update();
}

Onyx::Camera::Camera(Window& window, const Projection& proj)
{
	p_win = &window;
	window.p_cam = this;

	pos = Vec3(0.0f, 0.0f, 0.0f);
	front = Vec3(0.0f, 0.0f, -1.0f);
	up = Vec3(0.0f, 1.0f, 0.0f);

	yaw = pitch = 0.0f;
	this->proj = proj;
	pitchClamp = 88.0f;

	if (proj.getType() == Onyx::ProjectionType::Perspective) rotate(-90.0f, 0.0f);

	update();
}

Onyx::Camera::Camera(Window& window, const Projection& proj, float pitchClamp)
{
	p_win = &window;
	window.p_cam = this;

	pos = Vec3(0.0f, 0.0f, 0.0f);
	front = Vec3(0.0f, 0.0f, -1.0f);
	up = Vec3(0.0f, 1.0f, 0.0f);

	yaw = pitch = 0.0f;
	this->proj = proj;
	this->pitchClamp = pitchClamp;

	if (proj.getType() == Onyx::ProjectionType::Perspective) rotate(-90.0f, 0.0f);

	update();
}

void Onyx::Camera::update()
{
	view = LookAt(pos, pos + front, up);
}

void Onyx::Camera::translateLR(float dist)
{
	if (dist == 0) return;
	pos += (Vec3(Cross(front, up)).getNormalized() * dist);
}

void Onyx::Camera::translateUD(float dist)
{
	if (dist == 0) return;
	pos += Vec3(0.0f, dist, 0.0f);
}

void Onyx::Camera::translateFB(float dist)
{
	if (dist == 0) return;
	pos += (front * dist);
}

void Onyx::Camera::translate(const Vec3& LR_UD_FB)
{
	if (LR_UD_FB.isZero()) return;
	pos += (Vec3(Cross(front, up)).getNormalized() * LR_UD_FB.getX());
	pos += Vec3(0.0f, LR_UD_FB.getY(), 0.0f);
	pos += (front * LR_UD_FB.getZ());
}

void Onyx::Camera::translateGlobal(const Vec3& xyz)
{
	pos += xyz;
}

void Onyx::Camera::rotate(float _yaw, float _pitch)
{
	if (p_win->frame > 0 && p_win->frame < 5 || _yaw == 0 && _pitch == 0) return;

	yaw += _yaw;
	pitch += _pitch;
	if (pitch > pitchClamp) pitch = pitchClamp;
	if (pitch < -pitchClamp) pitch = -pitchClamp;

	float yawRad = Radians(yaw);
	float pitchRad = Radians(pitch);

	front.setX(cosf(yawRad) * cosf(pitchRad));
	front.setY(sinf(pitchRad));
	front.setZ(sinf(yawRad) * cosf(pitchRad));

	front.normalize();
}

void Onyx::Camera::rotate(float _yaw, float _pitch, const Vec3& origin)
{
	if (p_win->frame > 0 && p_win->frame < 5 || _yaw == 0 && _pitch == 0) return;

	if (pitch + _pitch > pitchClamp || pitch + _pitch < -pitchClamp) _pitch = 0.0f;

	Vec3 diff = pos - origin;
	//std::cout << diff.magnitude() << " --> ";
	translateGlobal(diff);

	yaw += _yaw;
	pitch += _pitch;

	float yawRad = Radians(yaw);
	float pitchRad = Radians(pitch);

	front.setX(cosf(yawRad) * cosf(pitchRad));
	front.setY(sinf(pitchRad));
	front.setZ(sinf(yawRad) * cosf(pitchRad));
	front.normalize();
	
	Vec3 left = Cross(front, up).getNormalized();

	diff = Math::Rotate(diff, Vec3(-_pitch * left.getX(), _yaw, -_pitch * left.getZ()));
	std::cout << diff.magnitude() << "\n";
	translateGlobal(-diff);
}

Vec3 Onyx::Camera::getPosition() const
{
	return pos;
}

Onyx::Projection Onyx::Camera::getProjection() const
{
	return proj;
}

Mat4 Onyx::Camera::getViewMatrix() const
{
	return view;
}

Mat4 Onyx::Camera::getProjectionMatrix() const
{
	return proj.getMatrix();
}

const Vec3& Onyx::Camera::getFront() const
{
	return front;
}

const Vec3& Onyx::Camera::getUp() const
{
	return up;
}

void Onyx::Camera::setPosition(const Math::Vec3& pos)
{
	this->pos = pos;
}

void Onyx::Camera::setPitchLimit(float pitchClamp)
{
	this->pitchClamp = pitchClamp;
}

void Onyx::Camera::setProjection(const Projection& proj)
{
	this->proj = proj;
}
