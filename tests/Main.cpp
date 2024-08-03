#pragma warning(disable: 4244)

#include <iostream>
#include <vector>

#include "../src/Core.h"
#include "../src/Math.h"

#include "PresetTests.h"
#include "WindowTest.h"
#include "BouncingBallTest.h"

using Onyx::Math::Vec2, Onyx::Math::Vec3, Onyx::Math::Vec4;

int main()
{
	Onyx::Demo();

	// PresetTests::RunAllTests();

	// WindowTest::Run();

	// BouncingBallTest::Run();



	// Onyx::Init();
	// Onyx::Window win;
	// win.init();
	// Onyx::InputHandler input;
	// win.linkInputHandler(input);

	// while (win.isOpen())
	// {
	// 	input.update();

	// 	win.startRender();
	// 	win.endRender();
	// }

	// win.dispose();
	// Onyx::Terminate();
	
	return 0;
}
