#pragma once

#include <vector>

#include "Result.h"

#include "../src/Core.h"
#include "../src/ErrorHandler.h"
#include "../src/Window.h"
#include "../src/File.h"
#include "../src/VertexArray.h"
#include "../src/Texture.h"
#include "../src/TextRenderer.h"
#include "../src/Shader.h"
#include "../src/Renderer.h"
#include "../src/Projection.h"
#include "../src/Mesh.h"
#include "../src/InputHandler.h"
#include "../src/IndexArray.h"
#include "../src/ImageData.h"
#include "../src/Font.h"
#include "../src/Camera.h"

namespace UnitTests
{
	Result ErrorHandlerConstructor1Test();
	Result ErrorHandlerConstructor2Test();
	Result FileConstructor1Test();
	Result FileConstructor2Test();
	Result WindowConstructor1Test();
	Result WindowConstructor2Test(); 
    Result VertexArrayConstructor1Test();
    Result VertexArrayConstructor2Test();
    Result ProjectionConstructor1Test();
    Result ProjectionOrthographicMethodTest();
    Result ProjectionPerspectiveMethod1Test();
    Result ProjectionPerspectiveMethod2Test();
    Result ProjectionPerspectiveMethod3Test();
    Result IndexArrayConstructor1Test();
    Result IndexArrayConstructor2Test();
    Result ImageDataConstructor1Test();
    Result ImageDataConstructor2Test();

	void RunAllConstructorTests();

    void RunAllTests();
}
