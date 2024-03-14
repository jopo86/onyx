#include "Projection.h"

using Onyx::Math::Mat4;
using Onyx::Math::OrthographicProjection;
using Onyx::Math::PerspectiveProjection;

Onyx::Projection::Projection()
{
	mat = Mat4();
	type = 0;
	left = right = top = bottom = fov = aspectRatio = nearPlane = farPlane = 0.0f;
}

Onyx::Projection Onyx::Projection::Orthographic(float left, float right, float top, float bottom)
{
	Projection proj;
	proj.type = ONYX_PROJECTION_TYPE_ORTHOGRAPHIC;
	proj.left = left;
	proj.right = right;
	proj.top = top;
	proj.bottom = bottom;
	proj.updateMatrixOrtho();
	return proj;
}

Onyx::Projection Onyx::Projection::Perspective(float fov, int screenWidth, int screenHeight)
{
	Projection proj;
	proj.type = ONYX_PROJECTION_TYPE_PERSPECTIVE;
	proj.fov = fov;
	proj.aspectRatio = (float)screenWidth / (float)screenHeight;
	proj.nearPlane = 0.1f;
	proj.farPlane = 100.0f;
	proj.updateMatrixPersp();
	return proj;
}

Onyx::Projection Onyx::Projection::Perspective(float fov, int screenWidth, int screenHeight, float nearPlane, float farPlane)
{
	Projection proj;
	proj.type = ONYX_PROJECTION_TYPE_PERSPECTIVE;
	proj.fov = fov;
	proj.aspectRatio = (float)screenWidth / (float)screenHeight;
	proj.nearPlane = nearPlane;
	proj.farPlane = farPlane;
	proj.updateMatrixPersp();
	return proj;
}

void Onyx::Projection::updateMatrixOrtho()
{
	type = ONYX_PROJECTION_TYPE_ORTHOGRAPHIC;
	mat = OrthographicProjection(left, right, top, bottom);
}

void Onyx::Projection::updateMatrixPersp()
{
	type = ONYX_PROJECTION_TYPE_PERSPECTIVE;
	mat = PerspectiveProjection(fov, aspectRatio, nearPlane, farPlane);
}

int Onyx::Projection::getType()
{
	return type;
}

float Onyx::Projection::getLeft()
{
	return left;
}

float Onyx::Projection::getRight()
{
	return right;
}

float Onyx::Projection::getTop()
{
	return top;
}

float Onyx::Projection::getBottom()
{
	return bottom;
}

float Onyx::Projection::getFOV()
{
	return fov;
}

float Onyx::Projection::getAspectRatio()
{
	return aspectRatio;
}

float Onyx::Projection::getNearPlane()
{
	return nearPlane;
}

float Onyx::Projection::getFarPlane()
{
	return farPlane;
}

Mat4 Onyx::Projection::getMatrix()
{
	return mat;
}

void Onyx::Projection::setLeft(float val)
{
	left = val;
}

void Onyx::Projection::setRight(float val)
{
	right = val;
}

void Onyx::Projection::setTop(float val)
{
	top = val;
}

void Onyx::Projection::setBottom(float val)
{
	bottom = val;
}

void Onyx::Projection::setFOV(float val)
{
	fov = val;
}

void Onyx::Projection::setAspectRatio(float val)
{
	aspectRatio = val;
}

void Onyx::Projection::setNearPlane(float val)
{
	nearPlane = val;
}

void Onyx::Projection::setFarPlane(float val)
{
	farPlane = val;
}
