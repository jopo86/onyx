#pragma warning(disable: 4244)

#include "Camera.h"

using Onyx::Math::Vec3, Onyx::Math::Mat4, Onyx::Math::Cross,
Onyx::Math::LookAt, Onyx::Math::Radians, Onyx::Math::Degrees;

void onyx_err(const Onyx::Error&);

Onyx::Camera::Camera()
{
	m_pWin = nullptr;

	m_yaw = m_pitch = m_pitchClamp = 0.0f;

	m_view = LookAt(m_pos, m_pos + m_front, m_up);
}

Onyx::Camera::Camera(const Projection& proj)
{
	m_pWin = nullptr;

	m_pos = Vec3(0.0f, 0.0f, 0.0f);
	m_front = Vec3(0.0f, 0.0f, -1.0f);
	m_up = Vec3(0.0f, 1.0f, 0.0f);

	m_yaw = m_pitch = 0.0f;
	m_proj = proj;
	m_pitchClamp = 88.0f;

	if (proj.getType() == Onyx::ProjectionType::Perspective) rotate(-90.0f, 0.0f);

	m_view = LookAt(m_pos, m_pos + m_front, m_up);
}

Onyx::Camera::Camera(const Projection& proj, float pitchClamp)
{
	m_pWin = nullptr;

	m_pos = Vec3(0.0f, 0.0f, 0.0f);
	m_front = Vec3(0.0f, 0.0f, -1.0f);
	m_up = Vec3(0.0f, 1.0f, 0.0f);

	m_yaw = m_pitch = 0.0f;
	m_proj = proj;
	m_pitchClamp = pitchClamp;

	if (proj.getType() == Onyx::ProjectionType::Perspective) rotate(-90.0f, 0.0f);

	m_view = LookAt(m_pos, m_pos + m_front, m_up);
}

void Onyx::Camera::update()
{
	if (m_pWin == nullptr)
	{
		onyx_err(Error{
			   .sourceFunction = "Onyx::Camera::update()",
			   .message = "Window pointer is null.",
			   .howToFix = "Make sure the camera was linked to a window (Window::linkCamera())."
			}
		);
		return;
	}
	m_view = LookAt(m_pos, m_pos + m_front, m_up);
}

void Onyx::Camera::translateLR(float dist)
{
	if (dist == 0) return;
	m_pos += (Vec3(Cross(m_front, m_up)).getNormalized() * dist);
}

void Onyx::Camera::translateUD(float dist)
{
	if (dist == 0) return;
	m_pos += Vec3(0.0f, dist, 0.0f);
}

void Onyx::Camera::translateFB(float dist)
{
	if (dist == 0) return;
	m_pos += (m_front * dist);
}

void Onyx::Camera::translate(const Vec3& LR_UD_FB)
{
	if (LR_UD_FB.isZero()) return;
	m_pos += (Vec3(Cross(m_front, m_up)).getNormalized() * LR_UD_FB.getX());
	m_pos += Vec3(0.0f, LR_UD_FB.getY(), 0.0f);
	m_pos += (m_front * LR_UD_FB.getZ());
}

void Onyx::Camera::translateGlobal(const Vec3& xyz)
{
	m_pos += xyz;
}

void Onyx::Camera::rotate(float yaw, float pitch)
{
	if (m_pWin != nullptr) if (m_pWin->m_frame > 0 && m_pWin->m_frame < 5 || yaw == 0 && pitch == 0) return;

	if (m_pitch + pitch > m_pitchClamp || m_pitch + pitch < -m_pitchClamp) pitch = 0.0f;

	m_yaw += yaw;
	m_pitch += pitch;
	updateFront();
}

//void Onyx::Camera::rotate(float yaw, float pitch, const Vec3& origin)
//{
//	if (m_pWin != nullptr) if (m_pWin->m_frame > 0 && m_pWin->m_frame < 5 || yaw == 0 && pitch == 0) return;
//
//	if (m_pitch + pitch > m_pitchClamp || m_pitch + pitch < -m_pitchClamp) pitch = 0.0f;
//
//	m_yaw += yaw;
//	m_pitch += pitch;
//	updateFront();
//
//	Vec3 diff = m_pos - origin;
//	m_pos += diff;
//	Vec3 left = Cross(m_front, m_up).getNormalized();
//	diff = Math::Rotate(diff, Vec3(-pitch * left.getX(), yaw, -pitch * left.getZ()));
//	m_pos -= diff;
//}

void Onyx::Camera::pitch(float degrees)
{
	if (m_pWin != nullptr) if (m_pWin->m_frame > 0 && m_pWin->m_frame < 5 || degrees == 0) return;
	if (m_pitch + degrees > m_pitchClamp || m_pitch + degrees < -m_pitchClamp) return;
	m_pitch += degrees;
	updateFront();
}

//void Onyx::Camera::pitch(float degrees, const Math::Vec3& origin)
//{
//	if (m_pWin != nullptr) if (m_pWin->m_frame > 0 && m_pWin->m_frame < 5 || degrees == 0) return;
//	if (m_pitch + degrees > m_pitchClamp || m_pitch + degrees < -m_pitchClamp) return;
//	m_pitch += degrees;
//	updateFront();
//	Vec3 diff = m_pos - origin;
//	m_pos += diff;
//	Vec3 left = Cross(m_front, m_up).getNormalized();
//	diff = Math::Rotate(diff, Vec3(-degrees * left.getX(), 0.0f, -degrees * left.getZ()));
//	m_pos -= diff;
//}

void Onyx::Camera::yaw(float degrees)
{
	if (m_pWin != nullptr) if (m_pWin->m_frame > 0 && m_pWin->m_frame < 5 || degrees == 0) return;
	m_yaw += degrees;
	updateFront();
}

//void Onyx::Camera::yaw(float degrees, const Math::Vec3& origin)
//{
//	if (m_pWin != nullptr) if (m_pWin->m_frame > 0 && m_pWin->m_frame < 5 || degrees == 0) return;
//	m_yaw += degrees;
//	updateFront();
//	Vec3 diff = m_pos - origin;
//	m_pos += diff;
//	Vec3 left = Cross(m_front, m_up).getNormalized();
//	diff = Math::Rotate(diff, Vec3(0.0f, degrees, 0.0f));
//	m_pos -= diff;
//}

void Onyx::Camera::lookAt(const Vec3& target)
{
	m_front = (target - m_pos).getNormalized();
	m_yaw = Degrees(atan2f(m_front.getZ(), m_front.getX()));
	m_pitch = Degrees(asinf(m_front.getY()));
}

const Vec3& Onyx::Camera::getPosition() const
{
	return m_pos;
}

const Onyx::Projection& Onyx::Camera::getProjection() const
{
	return m_proj;
}

const Mat4& Onyx::Camera::getViewMatrix() const
{
	return m_view;
}

const Mat4& Onyx::Camera::getProjectionMatrix() const
{
	return m_proj.getMatrix();
}

const Vec3& Onyx::Camera::getFront() const
{
	return m_front;
}

const Vec3& Onyx::Camera::getUp() const
{
	return m_up;
}

float Onyx::Camera::getYaw() const
{
	return m_yaw;
}

float Onyx::Camera::getPitch() const
{
	return m_pitch;
}

void Onyx::Camera::setPosition(const Math::Vec3& pos)
{
	m_pos = pos;
}

void Onyx::Camera::setPitchClamp(float pitchClamp)
{
	m_pitchClamp = pitchClamp;
}

void Onyx::Camera::setProjection(const Projection& proj)
{
	m_proj = proj;
}

void Onyx::Camera::setPitch(float pitch)
{
	if (m_pitch + pitch > m_pitchClamp) m_pitch = m_pitchClamp;
	else if (m_pitch + pitch < -m_pitchClamp) m_pitch = -m_pitchClamp;
	else m_pitch = pitch;
	updateFront();
}

void Onyx::Camera::setYaw(float yaw)
{
	m_yaw = yaw;
	updateFront();
}

void Onyx::Camera::setFOV(float fov)
{
	m_proj.setFOV(fov);
}

void Onyx::Camera::setViewDistance(float dist)
{
	m_proj.setFarPlane(dist);
}

void Onyx::Camera::updateFront()
{
	float yawRad = Radians(m_yaw);
	float pitchRad = Radians(m_pitch);

	m_front.setX(cosf(yawRad) * cosf(pitchRad));
	m_front.setY(sinf(pitchRad));
	m_front.setZ(sinf(yawRad) * cosf(pitchRad));
	m_front.normalize();
}
