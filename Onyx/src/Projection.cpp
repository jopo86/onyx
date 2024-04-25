#include "Projection.h"

bool onyx_is_ehandler_nullptr();
void onyx_warn(const Onyx::Warning& warning);

using Onyx::Math::Mat4;
using Onyx::Math::OrthographicProjection;
using Onyx::Math::PerspectiveProjection;

Onyx::Projection::Projection()
{
	mat = Mat4();
	type = ProjectionType::Null;
	left = right = top = bottom = fov = aspectRatio = nearPlane = farPlane = 0.0f;
}

Onyx::Projection Onyx::Projection::Orthographic(float left, float right, float top, float bottom)
{
	Projection proj;
	proj.type = ProjectionType::Orthographic;
	proj.left = left;
	proj.right = right;
	proj.top = top;
	proj.bottom = bottom;
	proj.update();
	return proj;
}

Onyx::Projection Onyx::Projection::Perspective(float fov, int screenWidth, int screenHeight)
{
	Projection proj;
	proj.type = ProjectionType::Perspective;
	proj.fov = fov;
	proj.aspectRatio = (float)screenWidth / (float)screenHeight;
	proj.nearPlane = 0.1f;
	proj.farPlane = 100.0f;
	proj.update();
	return proj;
}

Onyx::Projection Onyx::Projection::Perspective(float fov, int screenWidth, int screenHeight, float nearPlane, float farPlane)
{
	Projection proj;
	proj.type = ProjectionType::Perspective;
	proj.fov = fov;
	proj.aspectRatio = (float)screenWidth / (float)screenHeight;
	proj.nearPlane = nearPlane;
	proj.farPlane = farPlane;
	proj.update();
	return proj;
}

void Onyx::Projection::update()
{
	if (type == ProjectionType::Orthographic)
	{
		mat = OrthographicProjection(left, right, top, bottom);
	}
	else if (type == ProjectionType::Perspective)
	{
		mat = PerspectiveProjection(fov, aspectRatio, nearPlane, farPlane);
	}
}

Onyx::ProjectionType Onyx::Projection::getType() const
{
	return type;
}

float Onyx::Projection::getLeft() const
{
	if (!onyx_is_ehandler_nullptr()) if (type != ProjectionType::Orthographic)
	{
		onyx_warn(Warning{
				.sourceFunction = "Onyx::Projection::getLeft()",
				.message = "Projection type is not Orthographic, value returned is senseless.",
				.severity = Warning::Severity::Med
			}
		);
	}
	return left;
}

float Onyx::Projection::getRight() const
{
	if (!onyx_is_ehandler_nullptr()) if (type != ProjectionType::Orthographic)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::getRight()",
                .message = "Projection type is not Orthographic, value returned is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	return right;
}

float Onyx::Projection::getTop() const
{
	if (!onyx_is_ehandler_nullptr()) if (type != ProjectionType::Orthographic)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::getTop()",
                .message = "Projection type is not Orthographic, value returned is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	return top;
}

float Onyx::Projection::getBottom() const
{
	if (!onyx_is_ehandler_nullptr()) if (type != ProjectionType::Orthographic)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::getBottom()",
                .message = "Projection type is not Orthographic, value returned is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	return bottom;
}

float Onyx::Projection::getFOV() const
{
	if (!onyx_is_ehandler_nullptr()) if (type != ProjectionType::Perspective)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::getFOV()",
                .message = "Projection type is not Perspective, value returned is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	return fov;
}

float Onyx::Projection::getAspectRatio() const
{
	if (!onyx_is_ehandler_nullptr()) if (type != ProjectionType::Perspective)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::getAspectRatio()",
                .message = "Projection type is not Perspective, value returned is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	return aspectRatio;
}

float Onyx::Projection::getNearPlane() const
{
	if (!onyx_is_ehandler_nullptr()) if (type != ProjectionType::Perspective)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::getNearPlane()",
                .message = "Projection type is not Perspective, value returned is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	return nearPlane;
}

float Onyx::Projection::getFarPlane() const
{
	if (!onyx_is_ehandler_nullptr()) if (type != ProjectionType::Perspective)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::getFarPlane()",
                .message = "Projection type is not Perspective, value returned is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	return farPlane;
}

const Mat4& Onyx::Projection::getMatrix() const
{
	return mat;
}

void Onyx::Projection::setLeft(float val)
{
	if (!onyx_is_ehandler_nullptr()) if (type != ProjectionType::Orthographic)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::setLeft(float)",
                .message = "Projection type is not Orthographic, value set is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	left = val;
    updateMatrix();
}

void Onyx::Projection::setRight(float val)
{
	if (!onyx_is_ehandler_nullptr()) if (type != ProjectionType::Orthographic)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::setRight(float)",
                .message = "Projection type is not Orthographic, value set is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	right = val;
    updateMatrix();
}

void Onyx::Projection::setTop(float val)
{
    if (!onyx_is_ehandler_nullptr()) if (type != ProjectionType::Orthographic)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::setTop(float)",
                .message = "Projection type is not Orthographic, value set is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	top = val;
    updateMatrix();
}

void Onyx::Projection::setBottom(float val)
{
    if (!onyx_is_ehandler_nullptr()) if (type != ProjectionType::Orthographic)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::setBottom(float)",
                .message = "Projection type is not Orthographic, value set is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	bottom = val;
    updateMatrix();
}

void Onyx::Projection::setFOV(float val)
{
    if (!onyx_is_ehandler_nullptr()) if (type != ProjectionType::Perspective)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::setFOV(float)",
                .message = "Projection type is not Perspective, value set is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	fov = val;
    updateMatrix();
}

void Onyx::Projection::setAspectRatio(float val)
{
    if (!onyx_is_ehandler_nullptr()) if (type != ProjectionType::Perspective)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::setAspectRatio(float)",
                .message = "Projection type is not Perspective, value set is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	aspectRatio = val;
    updateMatrix();
}

void Onyx::Projection::setNearPlane(float val)
{
    if (!onyx_is_ehandler_nullptr()) if (type != ProjectionType::Perspective)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::setNearPlane(float)",
                .message = "Projection type is not Perspective, value set is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	nearPlane = val;
    updateMatrix();
}

void Onyx::Projection::setFarPlane(float val)
{
    if (!onyx_is_ehandler_nullptr()) if (type != ProjectionType::Perspective)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::setFarPlane(float)",
                .message = "Projection type is not Perspective, value set is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	farPlane = val;
    updateMatrix();
}

void Onyx::Projection::updateMatrix()
{
    if (type == ProjectionType::Orthographic)
    {
        mat = OrthographicProjection(left, right, top, bottom);
    }
    else if (type == ProjectionType::Perspective)
    {
        mat = PerspectiveProjection(fov, aspectRatio, nearPlane, farPlane);
    }
}
