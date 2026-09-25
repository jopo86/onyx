#pragma once

#include <GLFW/glfw3.h>
#include <string>
#include <vector>

#include <onyx/core.hpp>
#include <onyx/math_wrappers.hpp>

namespace onyx
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
		GLFWmonitor* get_glfw_monitor() const;

		/*
			@brief Gets the name of the monitor.
			@return The human-readable name of the monitor. Not guaranteed to be unique.
		 */
		const std::string& get_name() const;

		/*
			@brief Gets the dimensions of the monitor.
			@return The dimensions of the monitor in pixels (width, height).
		 */
		const math::IVec2& get_dimensions() const;

		/*
			@brief Gets the width of the monitor.
			@return The width of the monitor in pixels.
		 */
		int get_width() const;

		/*
			@brief Gets the height of the monitor.
			@return The height of the monitor in pixels.
		 */
		int get_height() const;

		/*
			@brief Gets the bit depth of the monitor.
			@return The bit depth of the monitor (red, green, blue).
		 */
		const math::IVec3& get_bit_depth() const;

		/*
			@brief Gets the refresh rate of the monitor.
			@return The refresh rate of the monitor in Hz.
		 */
		int get_refresh_rate() const;

		/*
			@brief Gets (an estimation of) the physical size of the monitor.
			@return The physical size of the monitor in millimeters (width, height).
		 */
		const math::IVec2& get_physical_size() const;

		/*
			@brief Gets the content scale of the monitor.
			@return The content scale of the monitor (x, y).
		 */
		const math::Vec2& get_content_scale() const;

		/*
			@brief Gets the position of the monitor.
			@return The position of the monitor in screen coordinates (x, y).
		 */
		const math::IVec2& get_position() const;

		/*
			@brief Gets the work area of the monitor.
			@return The work area of the monitor in screen coordinates (x, y, width, height).
		 */
		const math::IVec4& get_work_area() const;

		/*
			@brief Gets whether the monitor is the primary monitor.
			@return True if the monitor is the primary monitor, false otherwise.
		 */
		bool is_primary() const;

		/*
			@brief Gets whether the monitor is (still) connected.
			This is queried from GLFW each time it is called.
			@return True if the monitor is connected, false otherwise.
		 */
		bool is_connected() const;

	private:
		GLFWmonitor* p_glfw_monitor;
		std::string name;
		math::IVec2 dimensions;
		math::IVec3 bit_depth;
		int refresh_rate;
		math::IVec2 physical_size;
		math::Vec2 content_scale;
		math::IVec2 position;
		math::IVec4 work_area;
		bool primary;

		Monitor(GLFWmonitor* p_glfw_monitor);

	public:
		/*
			@brief Gets the primary monitor.
			If there is no primary monitor (e.g. on a headless system), an error is passed to the error handler
			and a default-constructed monitor (null GLFW monitor pointer, zero dimensions) is returned.
			@return The primary monitor.
		 */
		static Monitor get_primary();

		/*
			@brief Gets all connected monitors.
			@return A vector of all connected monitors.
		 */
		static std::vector<Monitor> get_all();
	};
}
