#pragma warning(disable: 4244)

#include "PresetTests.h"

using Onyx::ErrorHandler, Onyx::Window, Onyx::WindowProperties, Onyx::InputHandler,
Onyx::Mesh, Onyx::Shader, Onyx::Renderable, Onyx::Camera,
Onyx::Projection, Onyx::Renderer, Onyx::VertexBuffer,
Onyx::IndexBuffer, Onyx::Texture, Onyx::Lighting, Onyx::Key,
Onyx::Math::Vec2, Onyx::Math::Vec3, Onyx::Math::Vec4, Onyx::Init, Onyx::Terminate, Onyx::Resources;

bool PresetTests::RunMeshTest(Onyx::Window& window, Mesh mesh)
{
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

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
		if (input.isKeyDown(Key::Num1)) Renderer::ToggleWireframe();
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
		if (input.isKeyDown(Key::Num1)) Renderer::ToggleWireframe();
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

bool PresetTests::RunBufferTest(Onyx::Window& window, Onyx::VertexBuffer vb, Onyx::IndexBuffer ib)
{
	window.setBackgroundColor(Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input;
	window.linkInputHandler(input);

	Renderable obj(Mesh(vb, ib), Shader::P_Color(Vec4(1.0f, 1.0f, 1.0f, 1.0f)));

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
		if (input.isKeyDown(Key::Num1)) Renderer::ToggleWireframe();
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
	Window win(WindowProperties{ .title = "MeshTest_Triangle1", .width = 1280, .height = 720 });
	win.init();
	bool result = RunMeshTest(win, Mesh::Triangle(1.0f));
	Terminate();
	return result;
}

bool PresetTests::MeshTest_Triangle2()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
	Window win(WindowProperties{ .title = "MeshTest_Triangle2", .width = 1280, .height = 720 });
	win.init();
    bool result = RunMeshTest(win, Mesh::Triangle(1.0f, 1.0f));
    Terminate();
	return result;
}

bool PresetTests::MeshTest_Triangle3()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
	Window win(WindowProperties{ .title = "MeshTest_Triangle3", .width = 1280, .height = 720 });
	win.init();
    bool result = RunMeshTest(win, Mesh::Triangle(
		Vec2(0.0f, 0.0f), Vec2(1.0f, 0.0f), Vec2(0.0f, 1.0f)
	));
    Terminate();
	return result;
}

bool PresetTests::MeshTest_Square()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
	Window win(WindowProperties{ .title = "MeshTest_Square", .width = 1280, .height = 720 });
	win.init();
    bool result = RunMeshTest(win, Mesh::Square(1.0f));
    Terminate();
	return result;
}

bool PresetTests::MeshTest_Quad1()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
	Window win(WindowProperties{ .title = "MeshTest_Quad1", .width = 1280, .height = 720 });
	win.init();
    bool result = RunMeshTest(win, Mesh::Quad(2.0f, 1.0f));
    Terminate();
	return result;
}

bool PresetTests::MeshTest_Quad2()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
	Window win(WindowProperties{ .title = "MeshTest_Quad2", .width = 1280, .height = 720 });
	win.init();
    bool result = RunMeshTest(win, Mesh::Quad(
		Vec2(0.0f, 0.0f), Vec2(2.0f, 0.0f), Vec2(2.0f, 1.0f), Vec2(0.0f, 1.0f)
	));
    Terminate();
	return result;
}

bool PresetTests::MeshTest_Cube()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
	Window win(WindowProperties{ .title = "MeshTest_Cube", .width = 1280, .height = 720 });
	win.init();
    bool result = RunMeshTest(win, Mesh::Cube(1.0f));
    Terminate();
	return result;
}

bool PresetTests::MeshTest_RectPrism1()
{
	ErrorHandler errorHandler(true, true);
	Init(errorHandler);
	Window win(WindowProperties{ .title = "MeshTest_RectPrism1", .width = 1280, .height = 720 });
	win.init();
    bool result = RunMeshTest(win, Mesh::RectPrism(1.0f, 1.0f, 1.0f));
    Terminate();
	return result;
}

bool PresetTests::MeshTest_RectPrism2()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
	Window win(WindowProperties{ .title = "MeshTest_RectPrism2", .width = 1280, .height = 720 });
	win.init();
    bool result = RunMeshTest(win, Mesh::RectPrism(
        Vec3(0.0f, 0.0f, 0.0f), Vec3(2.0f, 0.0f, 0.0f), Vec3(2.0f, 1.0f, 0.0f), Vec3(0.0f, 1.0f, 0.0f),
		Vec3(0.0f, 0.0f, 1.0f), Vec3(2.0f, 0.0f, 1.0f), Vec3(2.0f, 1.0f, 1.0f), Vec3(0.0f, 1.0f, 1.0f)
    ));
    Terminate();
	return result;
}

bool PresetTests::RenderableTest_ColoredTriangle()
{
	ErrorHandler errorHandler(true, true);
	Init(errorHandler);
    Window win(WindowProperties{ .title = "RenderableTest_ColoredTriangle", .width = 1280, .height = 720 });
    win.init();
	bool result = RunRenderableTest(win, Renderable::ColoredTriangle(1.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
	Terminate();
	return result;
}

bool PresetTests::RenderableTest_VertexColoredTriangle()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "RenderableTest_VertexColoredTriangle", .width = 1280, .height = 720 });
    win.init();
    bool result = RunRenderableTest(win, Renderable::VertexColoredTriangle(1.0f));
    Terminate();
	return result;
}

bool PresetTests::RenderableTest_TexturedTriangle()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "RenderableTest_TexturedTriangle", .width = 1280, .height = 720 });
    win.init();
    bool result = RunRenderableTest(win, Renderable::TexturedTriangle(1.0f, Texture::Load(Resources("textures/container.jpg"))));
    Terminate();
	return result;
}

bool PresetTests::RenderableTest_ColoredSquare()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "RenderableTest_ColoredSquare", .width = 1280, .height = 720 });
    win.init();
    bool result = RunRenderableTest(win, Renderable::ColoredSquare(1.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
    Terminate();
	return result;
}

bool PresetTests::RenderableTest_ColoredQuad()
{
	ErrorHandler errorHandler(true, true);
	Init(errorHandler);
    Window win(WindowProperties{ .title = "RenderableTest_ColoredQuad", .width = 1280, .height = 720 });
    win.init();
    bool result = RunRenderableTest(win, Renderable::ColoredQuad(2.0f, 1.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
    Terminate();
	return result;
}

bool PresetTests::RenderableTest_VertexColoredSquare()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "RenderableTest_VertexColoredSquare", .width = 1280, .height = 720 });
    win.init();
    bool result = RunRenderableTest(win, Renderable::VertexColoredSquare(1.0f));
    Terminate();
	return result;
}

bool PresetTests::RenderableTest_VertexColoredQuad()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "RenderableTest_VertexColoredQuad", .width = 1280, .height = 720 });
    win.init();
    bool result = RunRenderableTest(win, Renderable::VertexColoredQuad(2.0f, 1.0f));
    Terminate();
	return result;
}

bool PresetTests::RenderableTest_TexturedSquare()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "RenderableTest_TexturedSquare", .width = 1280, .height = 720 });
    win.init();
    bool result = RunRenderableTest(win, Renderable::TexturedSquare(1.0f, Texture::Load(Resources("textures/container.jpg"))));
    Terminate();
	return result;
}

bool PresetTests::RenderableTest_TexturedQuad()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "RenderableTest_TexturedQuad", .width = 1280, .height = 720 });
    win.init();
    bool result = RunRenderableTest(win, Renderable::TexturedQuad(2.0f, 1.0f, Texture::Load(Resources("textures/container.jpg"))));
    Terminate();
	return result;
}

bool PresetTests::RenderableTest_ColoredCube()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "RenderableTest_ColoredCube", .width = 1280, .height = 720 });
    win.init();
    bool result = RunRenderableTest(win, Renderable::ColoredCube(1.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
    Terminate();
	return result;
}

bool PresetTests::RenderableTest_TexturedCube()
{
	ErrorHandler errorHandler(true, true);
	Init(errorHandler);
    Window win(WindowProperties{ .title = "RenderableTest_TexturedCube", .width = 1280, .height = 720 });
    win.init();
    bool result = RunRenderableTest(win, Renderable::TexturedCube(1.0f, Texture::Load(Resources("textures/container.jpg"))));
    Terminate();
	return result;
}

bool PresetTests::BufferTest_Triangle()
{
	ErrorHandler errorHandler(true, true);
	Init(errorHandler);
    Window win(WindowProperties{ .title = "BufferTest_Triangle", .width = 1280, .height = 720 });
    win.init();
    bool result = RunBufferTest(win, VertexBuffer::Triangle(1.0f), IndexBuffer::Triangle());
    Terminate();
    return result;
}

bool PresetTests::BufferTest_Square()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "BufferTest_Square", .width = 1280, .height = 720 });
    win.init();
    bool result = RunBufferTest(win, VertexBuffer::Square(1.0f), IndexBuffer::Square());
    Terminate();
    return result;
}

bool PresetTests::BufferTest_Quad()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "BufferTest_Quad", .width = 1280, .height = 720 });
    win.init();
    bool result = RunBufferTest(win, VertexBuffer::Quad(2.0f, 1.0f), IndexBuffer::Quad());
    Terminate();
    return result;
}

bool PresetTests::BufferTest_Cube()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "BufferTest_Cube", .width = 1280, .height = 720 });
    win.init();
    bool result = RunBufferTest(win, VertexBuffer::Cube(1.0f), IndexBuffer::Cube());
    Terminate();
    return result;
}

bool PresetTests::BufferTest_RectPrism()
{
	ErrorHandler errorHandler(true, true);
    Init(errorHandler);
    Window win(WindowProperties{ .title = "BufferTest_RectPrism", .width = 1280, .height = 720 });
    win.init();
    bool result = RunBufferTest(win, VertexBuffer::RectPrism(2.0f, 1.0f, 1.0f), IndexBuffer::RectPrism());
    Terminate();
    return result;
}

void PresetTests::RunAllTests()
{
	if (MeshTest_Triangle1()) std::cout << "MeshTest_Triangle1 - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "MeshTest_Triangle1 - \x1b[31mFAILED\x1b[39m\n";

	if (MeshTest_Triangle2()) std::cout << "MeshTest_Triangle2 - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "MeshTest_Triangle2 - \x1b[31mFAILED\x1b[39m\n";

	if (MeshTest_Triangle3()) std::cout << "MeshTest_Triangle3 - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "MeshTest_Triangle3 - \x1b[31mFAILED\x1b[39m\n";

	if (MeshTest_Square()) std::cout << "MeshTest_Square - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "MeshTest_Square - \x1b[31mFAILED\x1b[39m\n";

	if (MeshTest_Quad1()) std::cout << "MeshTest_Quad1 - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "MeshTest_Quad1 - \x1b[31mFAILED\x1b[39m\n";

	if (MeshTest_Quad2()) std::cout << "MeshTest_Quad2 - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "MeshTest_Quad2 - \x1b[31mFAILED\x1b[39m\n";

	if (MeshTest_Cube()) std::cout << "MeshTest_Cube - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "MeshTest_Cube - \x1b[31mFAILED\x1b[39m\n";

	if (MeshTest_RectPrism1()) std::cout << "MeshTest_RectPrism1 - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "MeshTest_RectPrism1 - \x1b[31mFAILED\x1b[39m\n";

	if (MeshTest_RectPrism2()) std::cout << "MeshTest_RectPrism2 - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "MeshTest_RectPrism2 - \x1b[31mFAILED\x1b[39m\n";

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

	if (RenderableTest_TexturedSquare()) std::cout << "RenderableTest_TexturedSquare - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "RenderableTest_TexturedSquare - \x1b[31mFAILED\x1b[39m\n";

	if (RenderableTest_TexturedQuad()) std::cout << "RenderableTest_TexturedQuad - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "RenderableTest_TexturedQuad - \x1b[31mFAILED\x1b[39m\n";

	if (RenderableTest_ColoredCube()) std::cout << "RenderableTest_ColoredCube - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "RenderableTest_ColoredCube - \x1b[31mFAILED\x1b[39m\n";

	if (RenderableTest_TexturedCube()) std::cout << "RenderableTest_TexturedCube - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "RenderableTest_TexturedCube - \x1b[31mFAILED\x1b[39m\n";

	if (BufferTest_Triangle()) std::cout << "BufferTest_Triangle - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "BufferTest_Triangle - \x1b[31mFAILED\x1b[39m\n";

	if (BufferTest_Square()) std::cout << "BufferTest_Square - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "BufferTest_Square - \x1b[31mFAILED\x1b[39m\n";

	if (BufferTest_Quad()) std::cout << "BufferTest_Quad - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "BufferTest_Quad - \x1b[31mFAILED\x1b[39m\n";

	if (BufferTest_Cube()) std::cout << "BufferTest_Cube - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "BufferTest_Cube - \x1b[31mFAILED\x1b[39m\n";

	if (BufferTest_RectPrism()) std::cout << "BufferTest_RectPrism - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "BufferTest_RectPrism - \x1b[31mFAILED\x1b[39m\n";

	std::cout << "\n";
}
