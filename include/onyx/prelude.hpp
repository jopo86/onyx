#pragma once

/*
	@file Convenience header that pulls in the commonly used parts of Onyx.
	For the short math names, add `using namespace onyx::prelude;` in your own source file.
 */

#include <onyx/core.hpp>
#include <onyx/window.hpp>
#include <onyx/input_handler.hpp>
#include <onyx/camera.hpp>
#include <onyx/renderer.hpp>
#include <onyx/renderable.hpp>
#include <onyx/math_wrappers.hpp>

namespace onyx::prelude
{
	using onyx::math::Vec2, onyx::math::Vec3, onyx::math::Vec4;
	using onyx::math::Mat4;
}
