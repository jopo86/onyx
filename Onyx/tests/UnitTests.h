#pragma once

#include <vector>

#include "Result.h"

#include "../src/Core.h"
#include "../src/ErrorHandler.h"
#include "../src/Window.h"
#include "../src/Texture.h"
#include "../src/Shader.h"
#include "../src/Renderer.h"
#include "../src/Projection.h"
#include "../src/Mesh.h"
#include "../src/InputHandler.h"
#include "../src/Font.h"
#include "../src/Camera.h"

namespace UnitTests
{
	Result ErrorHandlerConstructor1Test();
	Result ErrorHandlerConstructor2Test();
	Result WindowConstructor1Test();
	Result WindowConstructor2Test();
    Result ProjectionConstructor1Test();
    Result ProjectionOrthographicMethodTest();
    Result ProjectionPerspectiveMethod1Test();
    Result ProjectionPerspectiveMethod2Test();
    Result ProjectionPerspectiveMethod3Test();

	void RunAllConstructorTests();

    void RunAllTests();
}
