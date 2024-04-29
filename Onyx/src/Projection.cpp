#include "Projection.h"

void onyx_warn(const Onyx::Warning& warning);

using Onyx::Math::Mat4;
using Onyx::Math::OrthographicProjection;
using Onyx::Math::PerspectiveProjection;

Onyx::Projection::Projection()
{
	m_mat = Mat4();
	m_type = ProjectionType::Null;
	m_left = m_right = m_top = m_bottom = m_fov = m_aspectRatio = m_nearPlane = m_farPlane = 0.0f;
}

Onyx::Projection Onyx::Projection::Orthographic(float left, float right, float top, float bottom)
{
	Projection proj;
	proj.m_type = ProjectionType::Orthographic;
	proj.m_left = left;
	proj.m_right = right;
	proj.m_top = top;
	proj.m_bottom = bottom;
	proj.updateMatrix();
	return proj;
}

Onyx::Projection Onyx::Projection::Perspective(float fov, int screenWidth, int screenHeight)
{
	Projection proj;
	proj.m_type = ProjectionType::Perspective;
	proj.m_fov = fov;
	proj.m_aspectRatio = (float)screenWidth / (float)screenHeight;
	proj.m_nearPlane = 0.1f;
	proj.m_farPlane = 100.0f;
	proj.updateMatrix();
	return proj;
}

Onyx::Projection Onyx::Projection::Perspective(float fov, int screenWidth, int screenHeight, float nearPlane, float farPlane)
{
	Projection proj;
	proj.m_type = ProjectionType::Perspective;
	proj.m_fov = fov;
	proj.m_aspectRatio = (float)screenWidth / (float)screenHeight;
	proj.m_nearPlane = nearPlane;
	proj.m_farPlane = farPlane;
	proj.updateMatrix();
	return proj;
}

Onyx::ProjectionType Onyx::Projection::getType() const
{
	return m_type;
}

float Onyx::Projection::getLeft() const
{
	if (m_type != ProjectionType::Orthographic)
	{
		onyx_warn(Warning{
				.sourceFunction = "Onyx::Projection::getLeft()",
				.message = "Projection type is not Orthographic, value returned is senseless.",
				.severity = Warning::Severity::Med
			}
		);
	}
	return m_left;
}

float Onyx::Projection::getRight() const
{
	if (m_type != ProjectionType::Orthographic)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::getRight()",
                .message = "Projection type is not Orthographic, value returned is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	return m_right;
}

float Onyx::Projection::getTop() const
{
	if (m_type != ProjectionType::Orthographic)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::getTop()",
                .message = "Projection type is not Orthographic, value returned is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	return m_top;
}

float Onyx::Projection::getBottom() const
{
	if (m_type != ProjectionType::Orthographic)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::getBottom()",
                .message = "Projection type is not Orthographic, value returned is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	return m_bottom;
}

float Onyx::Projection::getFOV() const
{
	if (m_type != ProjectionType::Perspective)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::getFOV()",
                .message = "Projection type is not Perspective, value returned is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	return m_fov;
}

float Onyx::Projection::getAspectRatio() const
{
	if (m_type != ProjectionType::Perspective)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::getAspectRatio()",
                .message = "Projection type is not Perspective, value returned is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	return m_aspectRatio;
}

float Onyx::Projection::getNearPlane() const
{
	if (m_type != ProjectionType::Perspective)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::getNearPlane()",
                .message = "Projection type is not Perspective, value returned is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	return m_nearPlane;
}

float Onyx::Projection::getFarPlane() const
{
	if (m_type != ProjectionType::Perspective)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::getFarPlane()",
                .message = "Projection type is not Perspective, value returned is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	return m_farPlane;
}

const Mat4& Onyx::Projection::getMatrix() const
{
	return m_mat;
}

void Onyx::Projection::setLeft(float val)
{
	if (m_type != ProjectionType::Orthographic)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::setLeft(float)",
                .message = "Projection type is not Orthographic, value set is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	m_left = val;
    updateMatrix();
}

void Onyx::Projection::setRight(float val)
{
	if (m_type != ProjectionType::Orthographic)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::setRight(float)",
                .message = "Projection type is not Orthographic, value set is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	m_right = val;
    updateMatrix();
}

void Onyx::Projection::setTop(float val)
{
    if (m_type != ProjectionType::Orthographic)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::setTop(float)",
                .message = "Projection type is not Orthographic, value set is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	m_top = val;
    updateMatrix();
}

void Onyx::Projection::setBottom(float val)
{
    if (m_type != ProjectionType::Orthographic)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::setBottom(float)",
                .message = "Projection type is not Orthographic, value set is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	m_bottom = val;
    updateMatrix();
}

void Onyx::Projection::setFOV(float val)
{
    if (m_type != ProjectionType::Perspective)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::setFOV(float)",
                .message = "Projection type is not Perspective, value set is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	m_fov = val;
    updateMatrix();
}

void Onyx::Projection::setAspectRatio(float val)
{
    if (m_type != ProjectionType::Perspective)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::setAspectRatio(float)",
                .message = "Projection type is not Perspective, value set is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	m_aspectRatio = val;
    updateMatrix();
}

void Onyx::Projection::setNearPlane(float val)
{
    if (m_type != ProjectionType::Perspective)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::setNearPlane(float)",
                .message = "Projection type is not Perspective, value set is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	m_nearPlane = val;
    updateMatrix();
}

void Onyx::Projection::setFarPlane(float val)
{
    if (m_type != ProjectionType::Perspective)
    {
        onyx_warn(Warning{
                .sourceFunction = "Onyx::Projection::setFarPlane(float)",
                .message = "Projection type is not Perspective, value set is senseless.",
                .severity = Warning::Severity::Med
            }
        );
    }
	m_farPlane = val;
    updateMatrix();
}

void Onyx::Projection::updateMatrix()
{
    if (m_type == ProjectionType::Orthographic)
    {
        m_mat = OrthographicProjection(m_left, m_right, m_top, m_bottom);
    }
    else if (m_type == ProjectionType::Perspective)
    {
        m_mat = PerspectiveProjection(m_fov, m_aspectRatio, m_nearPlane, m_farPlane);
    }
}
