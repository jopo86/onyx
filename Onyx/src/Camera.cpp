#include "Camera.h"

using Onyx::Math::Vec3;
using Onyx::Math::Mat4; 
using Onyx::Math::Cross;
using Onyx::Math::LookAt;
using Onyx::Math::Radians;

Onyx::Camera::Camera()
{
	pos = Vec3(0.0f, 0.0f, 0.0f);
	front = Vec3(0.0f, 0.0f, -1.0f);
	up = Vec3(0.0f, 1.0f, 0.0f);

	yaw = pitch = 0.0f;
	proj = Projection::Orthographic(-1.0f, 1.0f, 1.0f, -1.0f);
	pitchClamp = 89.0f;

	update();
}

Onyx::Camera::Camera(Projection proj)
{
	pos = Vec3(0.0f, 0.0f, 0.0f);
	front = Vec3(0.0f, 0.0f, -1.0f);
	up = Vec3(0.0f, 1.0f, 0.0f);

	yaw = pitch = 0.0f;
	this->proj = proj;
	pitchClamp = 89.0f;

	rotate(-90.0f, 0.0f);

	update();
}

Onyx::Camera::Camera(Projection proj, float pitchClamp)
{
	pos = Vec3(0.0f, 0.0f, 0.0f);
	front = Vec3(0.0f, 0.0f, -1.0f);
	up = Vec3(0.0f, 1.0f, 0.0f);

	yaw = pitch = 0.0f;
	this->proj = proj;
	this->pitchClamp = pitchClamp;

	rotate(-90.0f, 0.0f);

	update();
}

void Onyx::Camera::update()
{
	view = LookAt(pos, pos + front, up);
}

void Onyx::Camera::translateLR(float dist)
{
	pos = pos + (Vec3(Cross(front, up)).getNormalized() * dist);
}

void Onyx::Camera::translateUD(float dist)
{
	pos = pos + Vec3(0.0f, dist, 0.0f);
}

void Onyx::Camera::translateFB(float dist)
{
	pos = pos + (front * dist);
}

void Onyx::Camera::translate(Vec3 LR_UD_FB)
{
	pos = pos + (Vec3(Cross(front, up)).getNormalized() * LR_UD_FB.getX());
	pos = pos + Vec3(0.0f, LR_UD_FB.getY(), 0.0f);
	pos = pos + pos = pos + (front * LR_UD_FB.getZ());
}

void Onyx::Camera::rotate(float x, float y)
{
	yaw += x;
	pitch -= y;

	if (pitch >= pitchClamp) pitch = pitchClamp;
	else if (pitch <= -pitchClamp) pitch = -pitchClamp;

	front.setX(cosf(Radians(yaw)) * cosf(Radians(pitch)));
	front.setY(sinf(Radians(pitch)));
	front.setZ(sinf(Radians(yaw)) * cosf(Radians(pitch)));
}

Onyx::Projection Onyx::Camera::getProjection()
{
	return proj;
}

Mat4 Onyx::Camera::getViewMatrix()
{
	return view;
}

Mat4 Onyx::Camera::getProjectionMatrix()
{
	return proj.getMatrix();
}

void Onyx::Camera::setPitchLimit(float pitchClamp)
{
	this->pitchClamp = pitchClamp;
}

void Onyx::Camera::setProjection(Projection proj)
{
	this->proj = proj;
}
