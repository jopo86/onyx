#include "projection.h"

void onyx_warn(const onyx::Warning& warning);

using onyx::math::Mat4;
using onyx::math::orthographic_projection;
using onyx::math::perspective_projection;

onyx::Projection::Projection()
{
	this->mat = Mat4();
	this->type = ProjectionType::Null;
	this->left = this->right = this->top = this->bottom = this->fov = this->aspect_ratio = this->near_plane = this->far_plane = 0.0f;
}

onyx::Projection onyx::Projection::orthographic(float screen_width, float screen_height)
{
	Projection proj;
	proj.type = ProjectionType::Orthographic;
	proj.left = 0.0f;
	proj.right = screen_width;
	proj.top = screen_height;
	proj.bottom = 0.0f;
	proj.update_matrix();
	return proj;
}

onyx::Projection onyx::Projection::perspective(float fov, int screen_width, int screen_height)
{
	Projection proj;
	proj.type = ProjectionType::Perspective;
	proj.fov = fov;
	proj.aspect_ratio = (float)screen_width / (float)screen_height;
	proj.near_plane = 0.1f;
	proj.far_plane = 100.0f;
	proj.update_matrix();
	return proj;
}

onyx::Projection onyx::Projection::perspective(float fov, int screen_width, int screen_height, float near_plane, float far_plane)
{
	Projection proj;
	proj.type = ProjectionType::Perspective;
	proj.fov = fov;
	proj.aspect_ratio = (float)screen_width / (float)screen_height;
	proj.near_plane = near_plane;
	proj.far_plane = far_plane;
	proj.update_matrix();
	return proj;
}

onyx::ProjectionType onyx::Projection::get_type() const
{
	return this->type;
}

float onyx::Projection::get_left() const
{
	if (this->type != ProjectionType::Orthographic)
	{
		onyx_warn(Warning{
				.source_function = "onyx::Projection::get_left()",
				.message = "Projection type is not orthographic, value returned is senseless.",
				.severity = Warning::Severity::Med
			}
		);
	}
	return this->left;
}

float onyx::Projection::get_right() const
{
	if (this->type != ProjectionType::Orthographic)
	{
		onyx_warn(Warning{
				.source_function = "onyx::Projection::get_right()",
				.message = "Projection type is not orthographic, value returned is senseless.",
				.severity = Warning::Severity::Med
			}
		);
	}
	return this->right;
}

float onyx::Projection::get_top() const
{
	if (this->type != ProjectionType::Orthographic)
	{
		onyx_warn(Warning{
				.source_function = "onyx::Projection::get_top()",
				.message = "Projection type is not orthographic, value returned is senseless.",
				.severity = Warning::Severity::Med
			}
		);
	}
	return this->top;
}

float onyx::Projection::get_bottom() const
{
	if (this->type != ProjectionType::Orthographic)
	{
		onyx_warn(Warning{
				.source_function = "onyx::Projection::get_bottom()",
				.message = "Projection type is not orthographic, value returned is senseless.",
				.severity = Warning::Severity::Med
			}
		);
	}
	return this->bottom;
}

float onyx::Projection::get_fov() const
{
	if (this->type != ProjectionType::Perspective)
	{
		onyx_warn(Warning{
				.source_function = "onyx::Projection::get_fov()",
				.message = "Projection type is not perspective, value returned is senseless.",
				.severity = Warning::Severity::Med
			}
		);
	}
	return this->fov;
}

float onyx::Projection::get_aspect_ratio() const
{
	if (this->type != ProjectionType::Perspective)
	{
		onyx_warn(Warning{
				.source_function = "onyx::Projection::get_aspect_ratio()",
				.message = "Projection type is not perspective, value returned is senseless.",
				.severity = Warning::Severity::Med
			}
		);
	}
	return this->aspect_ratio;
}

float onyx::Projection::get_near_plane() const
{
	if (this->type != ProjectionType::Perspective)
	{
		onyx_warn(Warning{
				.source_function = "onyx::Projection::get_near_plane()",
				.message = "Projection type is not perspective, value returned is senseless.",
				.severity = Warning::Severity::Med
			}
		);
	}
	return this->near_plane;
}

float onyx::Projection::get_far_plane() const
{
	if (this->type != ProjectionType::Perspective)
	{
		onyx_warn(Warning{
				.source_function = "onyx::Projection::get_far_plane()",
				.message = "Projection type is not perspective, value returned is senseless.",
				.severity = Warning::Severity::Med
			}
		);
	}
	return this->far_plane;
}

const Mat4& onyx::Projection::get_matrix() const
{
	return this->mat;
}

void onyx::Projection::set_left(float val)
{
	if (this->type != ProjectionType::Orthographic)
	{
		onyx_warn(Warning{
				.source_function = "onyx::Projection::set_left(float)",
				.message = "Projection type is not orthographic, value set is senseless.",
				.severity = Warning::Severity::Med
			}
		);
	}
	this->left = val;
	update_matrix();
}

void onyx::Projection::set_right(float val)
{
	if (this->type != ProjectionType::Orthographic)
	{
		onyx_warn(Warning{
				.source_function = "onyx::Projection::set_right(float)",
				.message = "Projection type is not orthographic, value set is senseless.",
				.severity = Warning::Severity::Med
			}
		);
	}
	this->right = val;
	update_matrix();
}

void onyx::Projection::set_top(float val)
{
	if (this->type != ProjectionType::Orthographic)
	{
		onyx_warn(Warning{
				.source_function = "onyx::Projection::set_top(float)",
				.message = "Projection type is not orthographic, value set is senseless.",
				.severity = Warning::Severity::Med
			}
		);
	}
	this->top = val;
	update_matrix();
}

void onyx::Projection::set_bottom(float val)
{
	if (this->type != ProjectionType::Orthographic)
	{
		onyx_warn(Warning{
				.source_function = "onyx::Projection::set_bottom(float)",
				.message = "Projection type is not orthographic, value set is senseless.",
				.severity = Warning::Severity::Med
			}
		);
	}
	this->bottom = val;
	update_matrix();
}

void onyx::Projection::set_fov(float val)
{
	if (this->type != ProjectionType::Perspective)
	{
		onyx_warn(Warning{
				.source_function = "onyx::Projection::set_fov(float)",
				.message = "Projection type is not perspective, value set is senseless.",
				.severity = Warning::Severity::Med
			}
		);
	}
	this->fov = val;
	update_matrix();
}

void onyx::Projection::set_aspect_ratio(float val)
{
	if (this->type != ProjectionType::Perspective)
	{
		onyx_warn(Warning{
				.source_function = "onyx::Projection::set_aspect_ratio(float)",
				.message = "Projection type is not perspective, value set is senseless.",
				.severity = Warning::Severity::Med
			}
		);
	}
	this->aspect_ratio = val;
	update_matrix();
}

void onyx::Projection::set_near_plane(float val)
{
	if (this->type != ProjectionType::Perspective)
	{
		onyx_warn(Warning{
				.source_function = "onyx::Projection::set_near_plane(float)",
				.message = "Projection type is not perspective, value set is senseless.",
				.severity = Warning::Severity::Med
			}
		);
	}
	this->near_plane = val;
	update_matrix();
}

void onyx::Projection::set_far_plane(float val)
{
	if (this->type != ProjectionType::Perspective)
	{
		onyx_warn(Warning{
				.source_function = "onyx::Projection::set_far_plane(float)",
				.message = "Projection type is not perspective, value set is senseless.",
				.severity = Warning::Severity::Med
			}
		);
	}
	this->far_plane = val;
	update_matrix();
}

void onyx::Projection::update_matrix()
{
	if (this->type == ProjectionType::Orthographic)
	{
		this->mat = orthographic_projection(this->left, this->right, this->top, this->bottom);
	}
	else if (this->type == ProjectionType::Perspective)
	{
		this->mat = perspective_projection(this->fov, this->aspect_ratio, this->near_plane, this->far_plane);
	}
}
