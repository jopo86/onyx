#include "Monitor.h"

using Onyx::Math::Vec2, Onyx::Math::IVec2, Onyx::Math::IVec3, Onyx::Math::IVec4;

void onyx_add_malloc(void*, bool);

Onyx::Monitor::Monitor()
{
	m_pGlfwMonitor = nullptr;
	m_refreshRate = 0;
	m_primary = false;
	m_connected = false;
}

GLFWmonitor* Onyx::Monitor::getGlfwMonitor() const
{
	return m_pGlfwMonitor;
}

const std::string& Onyx::Monitor::getName() const
{
	return m_name;
}

const IVec2& Onyx::Monitor::getDimensions() const
{
	return m_dimensions;
}

const IVec3& Onyx::Monitor::getBitDepth() const
{
	return m_bitDepth;
}

int Onyx::Monitor::getRefreshRate() const
{
	return m_refreshRate;
}

const IVec2& Onyx::Monitor::getPhysicalSize() const
{
	return m_physicalSize;
}

const Vec2& Onyx::Monitor::getContentScale() const
{
	return m_contentScale;
}

const IVec2& Onyx::Monitor::getPosition() const
{
	return m_position;
}

const IVec4& Onyx::Monitor::getWorkArea() const
{
	return m_workArea;
}

bool Onyx::Monitor::isPrimary() const
{
	return m_primary;
}

bool Onyx::Monitor::isConnected() const
{
	return m_connected;
}

Onyx::Monitor::Monitor(GLFWmonitor* pGlfwMonitor)
{
	m_pGlfwMonitor = pGlfwMonitor;
	m_name = glfwGetMonitorName(pGlfwMonitor);
	const GLFWvidmode* pVideoMode = glfwGetVideoMode(pGlfwMonitor);
	m_dimensions = IVec2(pVideoMode->width, pVideoMode->height);
	m_bitDepth = IVec3(pVideoMode->redBits, pVideoMode->greenBits, pVideoMode->blueBits);
	m_refreshRate = pVideoMode->refreshRate;
	int tmpInt0, tmpInt1, tmpInt2, tmpInt3;
	float tmpFloat0, tmpFloat1;
	glfwGetMonitorPhysicalSize(pGlfwMonitor, &tmpInt0, &tmpInt1);
	m_physicalSize = IVec2(tmpInt0, tmpInt1);
	glfwGetMonitorContentScale(pGlfwMonitor, &tmpFloat0, &tmpFloat1);
	m_contentScale = Vec2(tmpFloat0, tmpFloat1);
	glfwGetMonitorPos(pGlfwMonitor, &tmpInt0, &tmpInt1);
	m_position = IVec2(tmpInt0, tmpInt1);
	glfwGetMonitorWorkarea(pGlfwMonitor, &tmpInt0, &tmpInt1, &tmpInt2, &tmpInt3);
	m_workArea = IVec4(tmpInt0, tmpInt1, tmpInt2, tmpInt3);
	m_primary = pGlfwMonitor == glfwGetPrimaryMonitor();
	m_connected = true;
	glfwSetMonitorUserPointer(pGlfwMonitor, this);
}

void Onyx::Monitor::callback(GLFWmonitor* pGlfwMonitor, int event)
{
	if (glfwGetMonitorUserPointer(pGlfwMonitor) == nullptr) return;
	if (event == GLFW_CONNECTED) ((Monitor*)glfwGetMonitorUserPointer(pGlfwMonitor))->m_connected = true;
	else if (event == GLFW_DISCONNECTED) ((Monitor*)glfwGetMonitorUserPointer(pGlfwMonitor))->m_connected = false;
}

Onyx::Monitor Onyx::Monitor::GetPrimary()
{
	return Monitor(glfwGetPrimaryMonitor());
}

std::vector<Onyx::Monitor> Onyx::Monitor::GetAll()
{
	int count;
	GLFWmonitor** monitors = glfwGetMonitors(&count);

	std::vector<Onyx::Monitor> vec;
	for (int i = 0; i < count; i++)
	{
		vec.push_back(Monitor(monitors[i]));
	}

	return vec;
}
