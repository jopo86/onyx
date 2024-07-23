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
	Onyx::ErrorHandler errorHandler(true, true);
	Onyx::Init(errorHandler);
	Onyx::Demo();
	Onyx::Terminate();

	// PresetTests::RunAllTests();

	// WindowTest::Run();

	// BouncingBallTest::Run();
	
	return 0;
}
