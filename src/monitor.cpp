#include <onyx/monitor.hpp>

using onyx::math::Vec2, onyx::math::IVec2, onyx::math::IVec3, onyx::math::IVec4;

void onyx_add_malloc(void*, bool);

onyx::Monitor::Monitor()
{
	this->p_glfw_monitor = nullptr;
	this->refresh_rate = 0;
	this->primary = false;
	this->connected = false;
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
	return this->connected;
}

onyx::Monitor::Monitor(GLFWmonitor* p_glfw_monitor)
{
	this->p_glfw_monitor = p_glfw_monitor;
	this->name = glfwGetMonitorName(p_glfw_monitor);
	const GLFWvidmode* p_video_mode = glfwGetVideoMode(p_glfw_monitor);
	this->dimensions = IVec2(p_video_mode->width, p_video_mode->height);
	this->bit_depth = IVec3(p_video_mode->redBits, p_video_mode->greenBits, p_video_mode->blueBits);
	this->refresh_rate = p_video_mode->refreshRate;
	int tmp_int0, tmp_int1, tmp_int2, tmp_int3;
	float tmp_float0, tmp_float1;
	glfwGetMonitorPhysicalSize(p_glfw_monitor, &tmp_int0, &tmp_int1);
	this->physical_size = IVec2(tmp_int0, tmp_int1);
	glfwGetMonitorContentScale(p_glfw_monitor, &tmp_float0, &tmp_float1);
	this->content_scale = Vec2(tmp_float0, tmp_float1);
	glfwGetMonitorPos(p_glfw_monitor, &tmp_int0, &tmp_int1);
	this->position = IVec2(tmp_int0, tmp_int1);
	glfwGetMonitorWorkarea(p_glfw_monitor, &tmp_int0, &tmp_int1, &tmp_int2, &tmp_int3);
	this->work_area = IVec4(tmp_int0, tmp_int1, tmp_int2, tmp_int3);
	this->primary = p_glfw_monitor == glfwGetPrimaryMonitor();
	this->connected = true;
	glfwSetMonitorUserPointer(p_glfw_monitor, this);
}

void onyx::Monitor::callback(GLFWmonitor* p_glfw_monitor, int event)
{
	if (glfwGetMonitorUserPointer(p_glfw_monitor) == nullptr) return;
	if (event == GLFW_CONNECTED) ((Monitor*)glfwGetMonitorUserPointer(p_glfw_monitor))->connected = true;
	else if (event == GLFW_DISCONNECTED) ((Monitor*)glfwGetMonitorUserPointer(p_glfw_monitor))->connected = false;
}

onyx::Monitor onyx::Monitor::get_primary()
{
	return Monitor(glfwGetPrimaryMonitor());
}

std::vector<onyx::Monitor> onyx::Monitor::get_all()
{
	int count;
	GLFWmonitor** monitors = glfwGetMonitors(&count);

	std::vector<onyx::Monitor> vec;
	for (int i = 0; i < count; i++)
	{
		vec.push_back(Monitor(monitors[i]));
	}

	return vec;
}
