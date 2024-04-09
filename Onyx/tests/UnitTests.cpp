#include "UnitTests.h"

Result UnitTests::ErrorHandlerConstructor1Test()
{
	Result result("ErrorHandlerConstructor1Test", true, "");

	Onyx::ErrorHandler errorHandler;

	result.verify("logging", errorHandler.isLogging(), false);
	result.verify("throwing", errorHandler.isThrowing(), false);

	return result;
}

Result UnitTests::ErrorHandlerConstructor2Test()
{
	Result result("ErrorHandlerConstructor2Test", true, "");

	Onyx::ErrorHandler errorHandler(true, true);

	result.verify("logging", errorHandler.isLogging(), true);
	result.verify("throwing", errorHandler.isThrowing(), true);

	return result;
}

Result UnitTests::WindowConstructor1Test()
{
	Result result("WindowConstructor1Test", true, "");

	Onyx::Window win;

	result.verify("title", win.getTitle(), "Onyx Window");
	result.verify("width", win.getWidth(), 800);
	result.verify("height", win.getHeight(), 600);

	return result;
}

Result UnitTests::WindowConstructor2Test()
{
	Result result("WindowConstructor2Test", true, "");

	Onyx::Window win("Test", 1280, 720);

	result.verify("title", win.getTitle(), "Test");
	result.verify("width", win.getWidth(), 1280);
	result.verify("height", win.getHeight(), 720);

	return result;
}

Result UnitTests::VertexArrayConstructor1Test()
{
    Result result("VertexArrayConstructor1Test", true, "");

    Onyx::VertexArray vertexArray;

    result.verify("vertices", vertexArray.getVertices(), (float*)nullptr);
    result.verify("size", vertexArray.getSize(), 0);

    return result;
}

Result UnitTests::VertexArrayConstructor2Test()
{
    Result result("VertexArrayConstructor2Test", true, "");

    float vertices[3] = { 1.0f, 2.0f, 3.0f };
    ushort size = 3;
    Onyx::VertexFormat format = Onyx::VertexFormat::Null;

    Onyx::VertexArray vertexArray(vertices, size, format);

    result.verify("vertices", vertexArray.getVertices(), vertices);
    result.verify("size", vertexArray.getSize(), size);

    return result;
}

Result UnitTests::ProjectionConstructor1Test()
{
    Result result("ProjectionConstructor1Test", true, "");

    Onyx::Projection projection;

    result.verify("left", projection.getLeft(), 0.0f);
    result.verify("right", projection.getRight(), 0.0f);
    result.verify("top", projection.getTop(), 0.0f);
    result.verify("bottom", projection.getBottom(), 0.0f);
    result.verify("fov", projection.getFOV(), 0.0f);
    result.verify("aspectRatio", projection.getAspectRatio(), 0.0f);
    result.verify("nearPlane", projection.getNearPlane(), 0.0f);
    result.verify("farPlane", projection.getFarPlane(), 0.0f);

    return result;
}

Result UnitTests::ProjectionOrthographicMethodTest()
{
    Result result("ProjectionOrthographicMethodTest", true, "");

    Onyx::Projection projection = Onyx::Projection::Orthographic(0.0f, 1.0f, 0.0f, 1.0f);

    result.verify("left", projection.getLeft(), 0.0f);
    result.verify("right", projection.getRight(), 1.0f);
    result.verify("top", projection.getTop(), 0.0f);
    result.verify("bottom", projection.getBottom(), 1.0f);

    return result;
}

Result UnitTests::ProjectionPerspectiveMethod1Test()
{
    Result result("ProjectionPerspectiveMethod1Test", true, "");

    Onyx::Projection projection = Onyx::Projection::Perspective(45.0f, 800, 600);

    result.verify("fov", projection.getFOV(), 45.0f);
    result.verify("aspectRatio", projection.getAspectRatio(), 800.0f / 600.0f);
    result.verify("nearPlane", projection.getNearPlane(), 0.1f);
    result.verify("farPlane", projection.getFarPlane(), 100.0f);

    return result;
}

Result UnitTests::ProjectionPerspectiveMethod2Test()
{
    Result result("ProjectionPerspectiveMethod2Test", true, "");

    Onyx::Projection projection = Onyx::Projection::Perspective(45.0f, 800, 600, 0.5f, 200.0f);

    result.verify("fov", projection.getFOV(), 45.0f);
    result.verify("aspectRatio", projection.getAspectRatio(), 800.0f / 600.0f);
    result.verify("nearPlane", projection.getNearPlane(), 0.5f);
    result.verify("farPlane", projection.getFarPlane(), 200.0f);

    return result;
}

Result UnitTests::ProjectionPerspectiveMethod3Test()
{
    Result result("ProjectionPerspectiveMethod3Test", true, "");

    Onyx::Projection projection = Onyx::Projection::Perspective(45.0f, 800, 600, 0.5f, 200.0f);

    result.verify("fov", projection.getFOV(), 45.0f);
    result.verify("aspectRatio", projection.getAspectRatio(), 800.0f / 600.0f);
    result.verify("nearPlane", projection.getNearPlane(), 0.5f);
    result.verify("farPlane", projection.getFarPlane(), 200.0f);

    return result;
}

Result UnitTests::IndexArrayConstructor1Test()
{
    Result result("IndexArrayConstructor1Test", true, "");

    Onyx::IndexArray indexArray;

    result.verify("indices", indexArray.getIndices(), (uint*)nullptr);
    result.verify("size", indexArray.getSize(), 0);

    return result;
}

Result UnitTests::IndexArrayConstructor2Test()
{
    Result result("IndexArrayConstructor2Test", true, "");

    uint indices[3] = { 0, 1, 2 };

    Onyx::IndexArray indexArray(indices, 3);

    result.verify("indices", indexArray.getIndices(), indices);
    result.verify("size", indexArray.getSize(), 3);

    return result;
}

Result UnitTests::ImageDataConstructor1Test()
{
    Result result("ImageDataConstructor1Test", true, "");

    Onyx::ImageData imageData;

    result.verify("data", imageData.getData(), (ubyte*)nullptr);
    result.verify("width", imageData.getWidth(), 0);
    result.verify("height", imageData.getHeight(), 0);
    result.verify("nChannels", imageData.getNChannels(), 0);

    return result;
}

Result UnitTests::ImageDataConstructor2Test()
{
    Result result("ImageDataConstructor2Test", true, "");

    ubyte* data = new ubyte[4 * 4 * 3];
    int width = 4;
    int height = 4;
    int nChannels = 3;

    Onyx::ImageData imageData(data, width, height, nChannels);

    result.verify("data", imageData.getData(), data);
    result.verify("width", imageData.getWidth(), width);
    result.verify("height", imageData.getHeight(), height);
    result.verify("nChannels", imageData.getNChannels(), nChannels);

    delete[] data;

    return result;
}

void UnitTests::RunAllConstructorTests()
{
	std::vector<Result> results;

	results.push_back(ErrorHandlerConstructor1Test());
	results.push_back(ErrorHandlerConstructor2Test());
	results.push_back(WindowConstructor1Test());
	results.push_back(WindowConstructor2Test());
    results.push_back(VertexArrayConstructor1Test());
    results.push_back(VertexArrayConstructor2Test());
    results.push_back(ProjectionConstructor1Test());
    results.push_back(ProjectionOrthographicMethodTest());
    results.push_back(ProjectionPerspectiveMethod1Test());
    results.push_back(ProjectionPerspectiveMethod2Test());
    results.push_back(ProjectionPerspectiveMethod3Test());
    results.push_back(IndexArrayConstructor1Test());
    results.push_back(IndexArrayConstructor2Test());
    results.push_back(ImageDataConstructor1Test());
    results.push_back(ImageDataConstructor2Test());

	for (int i = 0; i < results.size(); i++)
	{
		std::cout << results[i].test << " - " << (results[i].success ? "\x1b[32mPASSED\x1b[39m" : "\x1b[31mFAILED\x1b[39m\n");
		if (!results[i].success) std::cout << results[i].message;
		std::cout << "\n";
	}

    std::cout << "\n";
}

void UnitTests::RunAllTests()
{
    RunAllConstructorTests();
}
