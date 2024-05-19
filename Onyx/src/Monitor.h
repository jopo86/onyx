#pragma once

#include <GLFW/glfw3.h>
#include <vector>

#include "Core.h"
#include "Math.h"

namespace Onyx
{
	class Monitor
	{
	public:
		/*
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
		 */
		Monitor();

		/*
			@brief Gets the GLFW monitor pointer object.
		 */
		GLFWmonitor* getGlfwMonitor() const;

		/*
			@brief Gets the name of the monitor.
			@return The human-readable name of the monitor. Not guaranteed to be unique.
		 */
		const std::string& getName() const;

		/*
			@brief Gets the dimensions of the monitor.
			@return The dimensions of the monitor in pixels (width, height).
		 */
		const Math::IVec2& getDimensions() const;

		/*
			@brief Gets the width of the monitor.
			@return The width of the monitor in pixels.
		 */
		int getWidth() const;

		/*
			@brief Gets the height of the monitor.
			@return The height of the monitor in pixels.
		 */
		int getHeight() const;

		/*
			@brief Gets the bit depth of the monitor.
			@return The bit depth of the monitor (red, green, blue).
		 */
		const Math::IVec3& getBitDepth() const;

		/*
			@brief Gets the refresh rate of the monitor.
			@return The refresh rate of the monitor in Hz.
		 */
		int getRefreshRate() const;

		/*
			@brief Gets (an estimation of) the physical size of the monitor.
			@return The physical size of the monitor in millimeters (width, height).
		 */
		const Math::IVec2& getPhysicalSize() const;

		/*
			@brief Gets the content scale of the monitor.
			@return The content scale of the monitor (x, y).
		 */
		const Math::Vec2& getContentScale() const;

		/*
			@brief Gets the position of the monitor.
			@return The position of the monitor in screen coordinates (x, y).
		 */
		const Math::IVec2& getPosition() const;

		/*
			@brief Gets the work area of the monitor.
			@return The work area of the monitor in screen coordinates (x, y, width, height).
		 */
		const Math::IVec4& getWorkArea() const;

		/*
			@brief Gets whether the monitor is the primary monitor.
			@return True if the monitor is the primary monitor, false otherwise.
		 */
		bool isPrimary() const;

		/*
			@brief Gets whether the monitor is connected.
			@return True if the monitor is connected, false otherwise.
		 */
		bool isConnected() const;

	private:
		GLFWmonitor* m_pGlfwMonitor;
		std::string m_name;
		Math::IVec2 m_dimensions;
		Math::IVec3 m_bitDepth;
		int m_refreshRate;
		Math::IVec2 m_physicalSize;
		Math::Vec2 m_contentScale;
		Math::IVec2 m_position;
		Math::IVec4 m_workArea;
		bool m_primary;
		bool m_connected;

		Monitor(GLFWmonitor* pGlfwMonitor);
		static void callback(GLFWmonitor* pGlfwMonitor, int event);

	public:
		/*
			@brief Gets the primary monitor.
			@return The primary monitor.
		 */
		static Monitor GetPrimary();

		/*
			@brief Gets all connected monitors.
			@return A vector of all connected monitors.
		 */
		static std::vector<Monitor> GetAll();
	};
}
