#pragma warning(disable: 4244)

#include <iostream>
#include <vector>

#include "../src/core.h"
#include "../src/math_wrappers.h"

#include "demo.h"
#include "preset_tests.h"
#include "window_test.h"
#include "bouncing_ball_test.h"
#include "cubes_test.h"

using onyx::math::Vec2, onyx::math::Vec3, onyx::math::Vec4;

int main()
{
	// demo::run();

	// preset_tests::run_all_tests();

	// window_test::run();

	// bouncing_ball_test::run();

    cubes_test::run();
	
	return 0;
}
