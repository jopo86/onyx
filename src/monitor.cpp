#include <onyx/monitor.hpp>

#include "internal.hpp"

using onyx::math::Vec2, onyx::math::IVec2, onyx::math::IVec3, onyx::math::IVec4;

onyx::Monitor::Monitor()
{
	this->p_glfw_monitor = nullptr;
	this->refresh_rate = 0;
	this->primary = false;
}

GLFWmonitor* onyx::Monitor::get_glfw_monitor() const
{
	return this->p_glfw_monitor;
}

const std::string& onyx::Monitor::get_name() const
{
	return this->name;
}

const IVec2& onyx::Monitor::get_dimensions() const
{
	return this->dimensions;
}

int onyx::Monitor::get_width() const
{
	return this->dimensions.get_x();
}

int onyx::Monitor::get_height() const
{
	return this->dimensions.get_y();
}

const IVec3& onyx::Monitor::get_bit_depth() const
{
	return this->bit_depth;
}

int onyx::Monitor::get_refresh_rate() const
{
	return this->refresh_rate;
}

const IVec2& onyx::Monitor::get_physical_size() const
{
	return this->physical_size;
}

const Vec2& onyx::Monitor::get_content_scale() const
{
	return this->content_scale;
}

const IVec2& onyx::Monitor::get_position() const
{
	return this->position;
}

const IVec4& onyx::Monitor::get_work_area() const
{
	return this->work_area;
}

bool onyx::Monitor::is_primary() const
{
	return this->primary;
}

bool onyx::Monitor::is_connected() const
{
	if (this->p_glfw_monitor == nullptr) return false;

	// Queried live rather than cached, since Monitor objects are copied around freely
	// and a stored `this` pointer would dangle. Only the pointer values are compared.
	int count = 0;
	GLFWmonitor** monitors = glfwGetMonitors(&count);
	if (monitors == nullptr) return false;
	for (int i = 0; i < count; i++)
	{
		if (monitors[i] == this->p_glfw_monitor) return true;
	}
	return false;
}

onyx::Monitor::Monitor(GLFWmonitor* p_glfw_monitor)
{
	this->p_glfw_monitor = p_glfw_monitor;
	this->refresh_rate = 0;
	this->primary = false;
	if (p_glfw_monitor == nullptr) return;

	const char* p_name = glfwGetMonitorName(p_glfw_monitor);
	if (p_name != nullptr) this->name = p_name;
	const GLFWvidmode* p_video_mode = glfwGetVideoMode(p_glfw_monitor);
	if (p_video_mode != nullptr)
	{
		this->dimensions = IVec2(p_video_mode->width, p_video_mode->height);
		this->bit_depth = IVec3(p_video_mode->redBits, p_video_mode->greenBits, p_video_mode->blueBits);
		this->refresh_rate = p_video_mode->refreshRate;
	}
	int tmp_int0 = 0, tmp_int1 = 0, tmp_int2 = 0, tmp_int3 = 0;
	float tmp_float0 = 1.0f, tmp_float1 = 1.0f;
	glfwGetMonitorPhysicalSize(p_glfw_monitor, &tmp_int0, &tmp_int1);
	this->physical_size = IVec2(tmp_int0, tmp_int1);
	glfwGetMonitorContentScale(p_glfw_monitor, &tmp_float0, &tmp_float1);
	this->content_scale = Vec2(tmp_float0, tmp_float1);
	glfwGetMonitorPos(p_glfw_monitor, &tmp_int0, &tmp_int1);
	this->position = IVec2(tmp_int0, tmp_int1);
	glfwGetMonitorWorkarea(p_glfw_monitor, &tmp_int0, &tmp_int1, &tmp_int2, &tmp_int3);
	this->work_area = IVec4(tmp_int0, tmp_int1, tmp_int2, tmp_int3);
	this->primary = p_glfw_monitor == glfwGetPrimaryMonitor();
}

onyx::Monitor onyx::Monitor::get_primary()
{
	GLFWmonitor* p_glfw_monitor = glfwGetPrimaryMonitor();
	if (p_glfw_monitor == nullptr)
	{
		onyx_err(Error{
				.source_function = "onyx::Monitor::get_primary()",
				.message = "No primary monitor found.",
				.how_to_fix = "Ensure onyx::init() has been called and that a monitor is connected. Headless systems have no monitors."
			}
		);
		return Monitor();
	}
	return Monitor(p_glfw_monitor);
}

std::vector<onyx::Monitor> onyx::Monitor::get_all()
{
	int count = 0;
	GLFWmonitor** monitors = glfwGetMonitors(&count);

	std::vector<onyx::Monitor> vec;
	if (monitors == nullptr) return vec;
	for (int i = 0; i < count; i++)
	{
		vec.push_back(Monitor(monitors[i]));
	}

	return vec;
}
