#include "UnitTests.h"

Result UnitTests::ErrorHandlerConstructor1Test()
{
	Result result("ErrorHandlerConstructor1Test", true, "");

	Onyx::ErrorHandler errorHandler;

    result.verify("logsWarnings", errorHandler.logsWarnings(), false);
	result.verify("logsErrors", errorHandler.logsErrors(), false);
	result.verify("crashesOnError", errorHandler.crashesOnError(), false);

	return result;
}

Result UnitTests::ErrorHandlerConstructor2Test()
{
	Result result("ErrorHandlerConstructor2Test", true, "");

	Onyx::ErrorHandler errorHandler(true, true, true);

	result.verify("logsWarnings", errorHandler.logsWarnings(), true);
	result.verify("logsErrors", errorHandler.logsErrors(), true);
    result.verify("crashesOnError", errorHandler.crashesOnError(), true);

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

void UnitTests::RunAllConstructorTests()
{
	std::vector<Result> results;

	results.push_back(ErrorHandlerConstructor1Test());
	results.push_back(ErrorHandlerConstructor2Test());
	results.push_back(WindowConstructor1Test());
	results.push_back(WindowConstructor2Test());
    results.push_back(ProjectionConstructor1Test());
    results.push_back(ProjectionOrthographicMethodTest());
    results.push_back(ProjectionPerspectiveMethod1Test());
    results.push_back(ProjectionPerspectiveMethod2Test());
    results.push_back(ProjectionPerspectiveMethod3Test());

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
