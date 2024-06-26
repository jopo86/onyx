#pragma warning(disable: 4244)

#include "PresetTests.h"

using Onyx::ErrorHandler, Onyx::Window, Onyx::Monitor, Onyx::WindowProperties, 
Onyx::InputHandler, Onyx::Mesh, Onyx::Shader, Onyx::Renderable, Onyx::UiRenderable, 
Onyx::Camera, Onyx::Projection, Onyx::Renderer, Onyx::VertexBuffer,
Onyx::IndexBuffer, Onyx::Texture, Onyx::Lighting, Onyx::Key,
Onyx::Math::Vec2, Onyx::Math::Vec3, Onyx::Math::Vec4, Onyx::Math::IVec2,
Onyx::Init, Onyx::Terminate, Onyx::Resources;

bool PresetTests::RunMeshTest(Onyx::Window& window, Mesh mesh)
{
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));
	Monitor primaryMonitor = Monitor::GetPrimary();
	window.setPosition(IVec2(primaryMonitor.getDimensions().getX() / 2 - window.getWidth() / 2, primaryMonitor.getDimensions().getY() / 2 - window.getHeight() / 2));

	InputHandler input;
	window.linkInputHandler(input);

	Renderable obj(mesh, Onyx::Shader::P_Color(Vec4(1.0f, 1.0f, 1.0f, 1.0f)));

	Camera cam(Projection::Perspective(60.0f, 1280, 720));
	window.linkCamera(cam);
	cam.translateFB(-2.0f);

	Lighting lighting(Vec3::White(), 0.3f, Vec3(-0.2f, -1.0f, -0.3f));

	Renderer renderer(cam, lighting);
	window.linkRenderer(renderer);
	renderer.add(obj);

	const double CAM_SPEED = 4.0;
	const double CAM_SENS = 50.0;

	input.setCursorLock(true);

	bool result = true;

	while (window.isOpen())
	{
		input.update();

		double dt = window.getDeltaTime();

		if (input.isKeyDown(Key::Escape)) window.close();
		if (input.isKeyDown(Key::X))
		{
			result = false;
			window.close();
		}
		if (input.isKeyTapped(Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Key::W)) cam.translateFB( CAM_SPEED * dt);
		if (input.isKeyDown(Key::A)) cam.translateLR(-CAM_SPEED * dt);
		if (input.isKeyDown(Key::S)) cam.translateFB(-CAM_SPEED * dt);
		if (input.isKeyDown(Key::D)) cam.translateLR( CAM_SPEED * dt);
		if (input.isKeyDown(Key::Space)) cam.translateUD( CAM_SPEED * dt);
		if (input.isKeyDown(Key::C)) cam.translateUD(-CAM_SPEED * dt);

		cam.rotate(CAM_SENS / 200 * input.getMouseDeltas().getX(), CAM_SENS / 200 * input.getMouseDeltas().getY());
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	window.dispose();
	renderer.dispose();

	return result;
}

bool PresetTests::RunRenderableTest(Onyx::Window& window, Renderable renderable)
{
	window.setBackgroundColor(Vec3(0.0f, 0.0f, 0.0f));
	Monitor primaryMonitor = Monitor::GetPrimary();
	window.setPosition(IVec2(primaryMonitor.getDimensions().getX() / 2 - window.getWidth() / 2, primaryMonitor.getDimensions().getY() / 2 - window.getHeight() / 2));

	InputHandler input;
	window.linkInputHandler(input);

	Renderable obj = renderable;

	Camera cam(Projection::Perspective(60.0f, 1280, 720));
	window.linkCamera(cam);
	cam.translateFB(-2.0f);

	Lighting lighting(Vec3::White(), 0.3f, Vec3(-0.2f, -1.0f, -0.3f));

	Renderer renderer(cam, lighting);
	window.linkRenderer(renderer);
	renderer.add(obj);

	const double CAM_SPEED = 4.0;
	const double CAM_SENS = 50.0;

	input.setCursorLock(true);

	bool result = true;

	while (window.isOpen())
	{
		input.update();

		double dt = window.getDeltaTime();

		if (input.isKeyDown(Key::Escape)) window.close();
		if (input.isKeyDown(Key::X))
        {
            result = false;
            window.close();
        }
		if (input.isKeyTapped(Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Key::W)) cam.translateFB(CAM_SPEED * dt);
		if (input.isKeyDown(Key::A)) cam.translateLR(-CAM_SPEED * dt);
		if (input.isKeyDown(Key::S)) cam.translateFB(-CAM_SPEED * dt);
		if (input.isKeyDown(Key::D)) cam.translateLR(CAM_SPEED * dt);
		if (input.isKeyDown(Key::Space)) cam.translateUD(CAM_SPEED * dt);
		if (input.isKeyDown(Key::C)) cam.translateUD(-CAM_SPEED * dt);

		cam.rotate(CAM_SENS / 200 * input.getMouseDeltas().getX(), CAM_SENS / 200 * input.getMouseDeltas().getY());
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	window.dispose();
	renderer.dispose();

	return result;
}

bool PresetTests::RunUiRenderableTest(Onyx::Window& window, UiRenderable renderable)
{
    window.setBackgroundColor(Vec3(0.0f, 0.0f, 0.0f));
	Monitor primaryMonitor = Monitor::GetPrimary();
	window.setPosition(IVec2(primaryMonitor.getDimensions().getX() / 2 - window.getWidth() / 2, primaryMonitor.getDimensions().getY() / 2 - window.getHeight() / 2));

    InputHandler input;
    window.linkInputHandler(input);

    UiRenderable obj = renderable;
	obj.setPosition(Vec2(300, 300));

    Camera cam(Projection::Orthographic(1280, 720));
    window.linkCamera(cam);

    Renderer renderer(cam);
    window.linkRenderer(renderer);
    renderer.add(obj);

    const double CAM_SPEED = 4.0;
    const double CAM_SENS = 50.0;

    input.setCursorLock(true);
    input.setKeyCooldown(Key::Num1, 0.5f);

    bool result = true;

    while (window.isOpen())
    {
        input.update();

        double dt = window.getDeltaTime();

        if (input.isKeyDown(Key::Escape)) window.close();
        if (input.isKeyDown(Key::X))
        {
            result = false;
            window.close();
        }
        if (input.isKeyTapped(Key::Num1)) Renderer::ToggleWireframe();
        if (input.isKeyDown(Key::W)) cam.translateFB(CAM_SPEED * dt);
        if (input.isKeyDown(Key::A)) cam.translateLR(-CAM_SPEED * dt);
        if (input.isKeyDown(Key::S)) cam.translateFB(-CAM_SPEED * dt);
        if (input.isKeyDown(Key::D)) cam.translateLR(CAM_SPEED * dt);
        if (input.isKeyDown(Key::Space)) cam.translateUD(CAM_SPEED * dt);
        if (input.isKeyDown(Key::C)) cam.translateUD(-CAM_SPEED * dt);

        cam.rotate(CAM_SENS / 200 * input.getMouseDeltas().getX(), CAM_SENS / 200 * input.getMouseDeltas().getY());
        cam.update();

        window.startRender();
        renderer.render();
        window.endRender();
    }

    window.dispose();
    renderer.dispose();

    return result;
}

bool PresetTests::MeshTest_Triangle1()
{
	ErrorHandler errorHandler(true, true);
	Init(errorHandler);
	Window win(WindowProperties{ .title = "MeshTest_Triangle1", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
	win.init();
	bool result = RunMeshTest(win, Mesh::Triangle(1.0f));
	Terminate();
	return result;
}

bool PresetTests::MeshTest_Triangle2()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
	Window win(WindowProperties{ .title = "MeshTest_Triangle2", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
	win.init();
    bool result = RunMeshTest(win, Mesh::Triangle(1.0f, 1.0f));
    Terminate();
	return result;
}

bool PresetTests::MeshTest_Square()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
	Window win(WindowProperties{ .title = "MeshTest_Square", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
	win.init();
    bool result = RunMeshTest(win, Mesh::Square(1.0f));
    Terminate();
	return result;
}

bool PresetTests::MeshTest_Quad()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
	Window win(WindowProperties{ .title = "MeshTest_Quad1", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
	win.init();
    bool result = RunMeshTest(win, Mesh::Quad(2.0f, 1.0f));
    Terminate();
	return result;
}

bool PresetTests::MeshTest_Circle()
{
	ErrorHandler errorHandler(true, true);
	Init(errorHandler);
	Window win(WindowProperties{ .title = "MeshTest_Circle", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
	win.init();
	bool result = RunMeshTest(win, Mesh::Circle(
		0.5f, 50
	));
	Terminate();
	return result;
}

bool PresetTests::MeshTest_Cube()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
	Window win(WindowProperties{ .title = "MeshTest_Cube", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
	win.init();
    bool result = RunMeshTest(win, Mesh::Cube(1.0f));
    Terminate();
	return result;
}

bool PresetTests::MeshTest_RectPrism()
{
	ErrorHandler errorHandler(true, true);
	Init(errorHandler);
	Window win(WindowProperties{ .title = "MeshTest_RectPrism", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
	win.init();
    bool result = RunMeshTest(win, Mesh::RectPrism(1.0f, 1.0f, 1.0f));
    Terminate();
	return result;
}

bool PresetTests::MeshTest_Cylinder()
{
	ErrorHandler errorHandler(true, true);
	Init(errorHandler);
	Window win(WindowProperties{ .title = "MeshTest_Cylinder", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
	win.init();
	bool result = RunMeshTest(win, Mesh::Cylinder(0.2f, 2.0f, 50, false, false));
	Terminate();
	return result;
}

bool PresetTests::RenderableTest_ColoredTriangle()
{
	ErrorHandler errorHandler(true, true);
	Init(errorHandler);
    Window win(WindowProperties{ .title = "RenderableTest_ColoredTriangle", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
    win.init();
	bool result = RunRenderableTest(win, Renderable::ColoredTriangle(1.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
	Terminate();
	return result;
}

bool PresetTests::RenderableTest_VertexColoredTriangle()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "RenderableTest_VertexColoredTriangle", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
    win.init();
    bool result = RunRenderableTest(win, Renderable::VertexColoredTriangle(1.0f));
    Terminate();
	return result;
}

bool PresetTests::RenderableTest_TexturedTriangle()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "RenderableTest_TexturedTriangle", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
    win.init();
    bool result = RunRenderableTest(win, Renderable::TexturedTriangle(1.0f, Texture::Load(Resources("textures/container.jpg"))));
    Terminate();
	return result;
}

bool PresetTests::RenderableTest_ColoredSquare()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "RenderableTest_ColoredSquare", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
    win.init();
    bool result = RunRenderableTest(win, Renderable::ColoredSquare(1.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
    Terminate();
	return result;
}

bool PresetTests::RenderableTest_ColoredQuad()
{
	ErrorHandler errorHandler(true, true);
	Init(errorHandler);
    Window win(WindowProperties{ .title = "RenderableTest_ColoredQuad", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
    win.init();
    bool result = RunRenderableTest(win, Renderable::ColoredQuad(2.0f, 1.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
    Terminate();
	return result;
}

bool PresetTests::RenderableTest_VertexColoredSquare()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "RenderableTest_VertexColoredSquare", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
    win.init();
    bool result = RunRenderableTest(win, Renderable::VertexColoredSquare(1.0f));
    Terminate();
	return result;
}

bool PresetTests::RenderableTest_VertexColoredQuad()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "RenderableTest_VertexColoredQuad", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
    win.init();
    bool result = RunRenderableTest(win, Renderable::VertexColoredQuad(2.0f, 1.0f));
    Terminate();
	return result;
}

bool PresetTests::RenderableTest_ColoredCircle()
{
	ErrorHandler errorHandler(true, true);
	Init(errorHandler);
	Window win(WindowProperties{ .title = "RenderableTest_ColoredCircle", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
	win.init();
	bool result = RunRenderableTest(win, Renderable::ColoredCircle(0.5f, 50, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
	Terminate();
	return result;
}

bool PresetTests::RenderableTest_VertexColoredCircle()
{
	ErrorHandler errorHandler(true, true);
	Init(errorHandler);
	Window win(WindowProperties{ .title = "RenderableTest_VertexColoredCircle", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
	win.init();
	bool result = RunRenderableTest(win, Renderable::VertexColoredCircle(0.5f, 50));
	Terminate();
	return result;
}

bool PresetTests::RenderableTest_TexturedCircle()
{
	ErrorHandler errorHandler(true, true);
	Init(errorHandler);
	Window win(WindowProperties{ .title = "RenderableTest_TexturedCircle", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
	win.init();
	bool result = RunRenderableTest(win, Renderable::TexturedCircle(0.5f, 50, Texture::Load(Resources("textures/container.jpg"))));
	Terminate();
	return result;
}

bool PresetTests::RenderableTest_TexturedSquare()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "RenderableTest_TexturedSquare", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
    win.init();
    bool result = RunRenderableTest(win, Renderable::TexturedSquare(1.0f, Texture::Load(Resources("textures/container.jpg"))));
    Terminate();
	return result;
}

bool PresetTests::RenderableTest_TexturedQuad()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "RenderableTest_TexturedQuad", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
    win.init();
    bool result = RunRenderableTest(win, Renderable::TexturedQuad(2.0f, 1.0f, Texture::Load(Resources("textures/container.jpg"))));
    Terminate();
	return result;
}

bool PresetTests::RenderableTest_ColoredCube()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "RenderableTest_ColoredCube", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
    win.init();
    bool result = RunRenderableTest(win, Renderable::ColoredCube(1.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
    Terminate();
	return result;
}

bool PresetTests::RenderableTest_TexturedCube()
{
	ErrorHandler errorHandler(true, true);
	Init(errorHandler);
    Window win(WindowProperties{ .title = "RenderableTest_TexturedCube", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
    win.init();
    bool result = RunRenderableTest(win, Renderable::TexturedCube(1.0f, Texture::Load(Resources("textures/container.jpg"))));
    Terminate();
	return result;
}

bool PresetTests::RenderableTest_ColoredRectPrism()
{
	ErrorHandler errorHandler(true, true);
	Init(errorHandler);
	Window win(WindowProperties{ .title = "RenderableTest_ColoredRectPrism", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
	win.init();
	bool result = RunRenderableTest(win, Renderable::ColoredRectPrism(2.0f, 1.0f, 1.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
	Terminate();
	return result;
}

bool PresetTests::RenderableTest_TexturedRectPrism()
{
	ErrorHandler errorHandler(true, true);
	Init(errorHandler);
	Window win(WindowProperties{ .title = "RenderableTest_TexturedRectPrism", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
	win.init();
	bool result = RunRenderableTest(win, Renderable::TexturedRectPrism(2.0f, 1.0f, 1.0f, Texture::Load(Resources("textures/container.jpg"))));
	Terminate();
	return result;
}

bool PresetTests::RenderableTest_ColoredCylinder()
{
	ErrorHandler errorHandler(true, true);
	Init(errorHandler);
	Window win(WindowProperties{ .title = "RenderableTest_ColoredCylinder", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
	win.init();
	bool result = RunRenderableTest(win, Renderable::ColoredCylinder(0.2f, 2.0f, 50, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
	Terminate();
	return result;
}

bool PresetTests::RenderableTest_TexturedCylinder()
{
	ErrorHandler errorHandler(true, true);
	Init(errorHandler);
	Window win(WindowProperties{ .title = "RenderableTest_TexturedCylinder", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
	win.init();
	bool result = RunRenderableTest(win, Renderable::TexturedCylinder(0.2f, 2.0f, 50, Texture::Load(Resources("textures/container.jpg"))));
	Terminate();
	return result;
}

bool PresetTests::UiRenderableTest_ColoredTriangle()
{
    ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "UiRenderableTest_ColoredTriangle", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
    win.init();
    bool result = RunUiRenderableTest(win, UiRenderable::ColoredTriangle(100.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
    Terminate();
    return result;
}

bool PresetTests::UiRenderableTest_TexturedTriangle()
{
    ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "UiRenderableTest_TexturedTriangle", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
    win.init();
    bool result = RunUiRenderableTest(win, UiRenderable::TexturedTriangle(100.0f, Texture::Load(Resources("textures/container.jpg"))));
    Terminate();
    return result;
}

bool PresetTests::UiRenderableTest_ColoredSquare()
{
    ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "UiRenderableTest_ColoredSquare", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
    win.init();
    bool result = RunUiRenderableTest(win, UiRenderable::ColoredSquare(100.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
    Terminate();
    return result;
}

bool PresetTests::UiRenderableTest_TexturedSquare()
{
    ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "UiRenderableTest_TexturedSquare", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
    win.init();
    bool result = RunUiRenderableTest(win, UiRenderable::TexturedSquare(100.0f, Texture::Load(Resources("textures/container.jpg"))));
    Terminate();
    return result;
}

bool PresetTests::UiRenderableTest_ColoredQuad()
{
    ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "UiRenderableTest_ColoredQuad", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
    win.init();
    bool result = RunUiRenderableTest(win, UiRenderable::ColoredQuad(200.0f, 100.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
    Terminate();
    return result;
}

bool PresetTests::UiRenderableTest_TexturedQuad()
{
    ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "UiRenderableTest_TexturedQuad", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
    win.init();
    bool result = RunUiRenderableTest(win, UiRenderable::TexturedQuad(200.0f, 100.0f, Texture::Load(Resources("textures/container.jpg"))));
    Terminate();
    return result;
}

bool PresetTests::UiRenderableTest_ColoredCircle()
{
	ErrorHandler errorHandler(true, true);
	Init(errorHandler);
	Window win(WindowProperties{ .title = "UiRenderableTest_ColoredCircle", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
	win.init();
	bool result = RunUiRenderableTest(win, UiRenderable::ColoredCircle(50.0f, 50, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
	Terminate();
	return result;
}

bool PresetTests::UiRenderableTest_TexturedCircle()
{
	ErrorHandler errorHandler(true, true);
	Init(errorHandler);
	Window win(WindowProperties{ .title = "UiRenderableTest_TexturedCircle", .width = 1280, .height = 720, .nSamplesMSAA = 16 });
	win.init();
	bool result = RunUiRenderableTest(win, UiRenderable::TexturedCircle(50.0f, 50, Texture::Load(Resources("textures/container.jpg"))));
	Terminate();
	return result;
}

void PresetTests::RunAllTests()
{
	if (MeshTest_Triangle1()) std::cout << "MeshTest_Triangle1 - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "MeshTest_Triangle1 - \x1b[31mFAILED\x1b[39m\n";

	if (MeshTest_Triangle2()) std::cout << "MeshTest_Triangle2 - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "MeshTest_Triangle2 - \x1b[31mFAILED\x1b[39m\n";

	if (MeshTest_Square()) std::cout << "MeshTest_Square - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "MeshTest_Square - \x1b[31mFAILED\x1b[39m\n";

	if (MeshTest_Quad()) std::cout << "MeshTest_Quad - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "MeshTest_Quad - \x1b[31mFAILED\x1b[39m\n";

	if (MeshTest_Circle()) std::cout << "MeshTest_Circle - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "MeshTest_Circle - \x1b[31mFAILED\x1b[39m\n";

	if (MeshTest_Cube()) std::cout << "MeshTest_Cube - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "MeshTest_Cube - \x1b[31mFAILED\x1b[39m\n";

	if (MeshTest_RectPrism()) std::cout << "MeshTest_RectPrism - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "MeshTest_RectPrism - \x1b[31mFAILED\x1b[39m\n";

	if (MeshTest_Cylinder()) std::cout << "MeshTest_Cylinder - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "MeshTest_Cylinder - \x1b[31mFAILED\x1b[39m\n";

	if (RenderableTest_ColoredTriangle()) std::cout << "RenderableTest_ColoredTriangle - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "RenderableTest_ColoredTriangle - \x1b[31mFAILED\x1b[39m\n";

	if (RenderableTest_VertexColoredTriangle()) std::cout << "RenderableTest_VertexColoredTriangle - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "RenderableTest_VertexColoredTriangle - \x1b[31mFAILED\x1b[39m\n";

	if (RenderableTest_TexturedTriangle()) std::cout << "RenderableTest_TexturedTriangle - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "RenderableTest_TexturedTriangle - \x1b[31mFAILED\x1b[39m\n";

	if (RenderableTest_ColoredSquare()) std::cout << "RenderableTest_ColoredSquare - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "RenderableTest_ColoredSquare - \x1b[31mFAILED\x1b[39m\n";

	if (RenderableTest_ColoredQuad()) std::cout << "RenderableTest_ColoredQuad - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "RenderableTest_ColoredQuad - \x1b[31mFAILED\x1b[39m\n";

	if (RenderableTest_VertexColoredSquare()) std::cout << "RenderableTest_VertexColoredSquare - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "RenderableTest_VertexColoredSquare - \x1b[31mFAILED\x1b[39m\n";

	if (RenderableTest_VertexColoredQuad()) std::cout << "RenderableTest_VertexColoredQuad - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "RenderableTest_VertexColoredQuad - \x1b[31mFAILED\x1b[39m\n";

	if (RenderableTest_ColoredCircle()) std::cout << "RenderableTest_ColoredCircle - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "RenderableTest_ColoredCircle - \x1b[31mFAILED\x1b[39m\n";

	if (RenderableTest_VertexColoredCircle()) std::cout << "RenderableTest_VertexColoredCircle - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "RenderableTest_VertexColoredCircle - \x1b[31mFAILED\x1b[39m\n";

	if (RenderableTest_TexturedCircle()) std::cout << "RenderableTest_TexturedCircle - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "RenderableTest_TexturedCircle - \x1b[31mFAILED\x1b[39m\n";

	if (RenderableTest_TexturedSquare()) std::cout << "RenderableTest_TexturedSquare - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "RenderableTest_TexturedSquare - \x1b[31mFAILED\x1b[39m\n";

	if (RenderableTest_TexturedQuad()) std::cout << "RenderableTest_TexturedQuad - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "RenderableTest_TexturedQuad - \x1b[31mFAILED\x1b[39m\n";

	if (RenderableTest_ColoredCube()) std::cout << "RenderableTest_ColoredCube - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "RenderableTest_ColoredCube - \x1b[31mFAILED\x1b[39m\n";

	if (RenderableTest_TexturedCube()) std::cout << "RenderableTest_TexturedCube - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "RenderableTest_TexturedCube - \x1b[31mFAILED\x1b[39m\n";

	if (RenderableTest_ColoredRectPrism()) std::cout << "RenderableTest_ColoredRectPrism - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "RenderableTest_ColoredRectPrism - \x1b[31mFAILED\x1b[39m\n";

	if (RenderableTest_TexturedRectPrism()) std::cout << "RenderableTest_TexturedRectPrism - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "RenderableTest_TexturedRectPrism - \x1b[31mFAILED\x1b[39m\n";

	if (RenderableTest_ColoredCylinder()) std::cout << "RenderableTest_ColoredCylinder - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "RenderableTest_ColoredCylinder - \x1b[31mFAILED\x1b[39m\n";

	if (RenderableTest_TexturedCylinder()) std::cout << "RenderableTest_TexturedCylinder - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "RenderableTest_TexturedCylinder - \x1b[31mFAILED\x1b[39m\n";

	if (UiRenderableTest_ColoredTriangle()) std::cout << "UiRenderableTest_ColoredTriangle - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "UiRenderableTest_ColoredTriangle - \x1b[31mFAILED\x1b[39m\n";

	if (UiRenderableTest_TexturedTriangle()) std::cout << "UiRenderableTest_TexturedTriangle - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "UiRenderableTest_TexturedTriangle - \x1b[31mFAILED\x1b[39m\n";

	if (UiRenderableTest_ColoredSquare()) std::cout << "UiRenderableTest_ColoredSquare - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "UiRenderableTest_ColoredSquare - \x1b[31mFAILED\x1b[39m\n";

	if (UiRenderableTest_TexturedSquare()) std::cout << "UiRenderableTest_TexturedSquare - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "UiRenderableTest_TexturedSquare - \x1b[31mFAILED\x1b[39m\n";

	if (UiRenderableTest_ColoredQuad()) std::cout << "UiRenderableTest_ColoredQuad - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "UiRenderableTest_ColoredQuad - \x1b[31mFAILED\x1b[39m\n";

	if (UiRenderableTest_TexturedQuad()) std::cout << "UiRenderableTest_TexturedQuad - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "UiRenderableTest_TexturedQuad - \x1b[31mFAILED\x1b[39m\n";

	if (UiRenderableTest_ColoredCircle()) std::cout << "UiRenderableTest_ColoredCircle - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "UiRenderableTest_ColoredCircle - \x1b[31mFAILED\x1b[39m\n";

	if (UiRenderableTest_TexturedCircle()) std::cout << "UiRenderableTest_TexturedCircle - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "UiRenderableTest_TexturedCircle - \x1b[31mFAILED\x1b[39m\n";

	std::cout << "\n";
}