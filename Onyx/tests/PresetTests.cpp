#pragma warning(disable: 4244)

#include "PresetTests.h"

using Onyx::ErrorHandler, Onyx::Window, Onyx::InputHandler,
Onyx::Mesh, Onyx::Shader, Onyx::Renderable, Onyx::Camera,
Onyx::Projection, Onyx::Renderer, Onyx::VertexArray,
Onyx::IndexArray, Onyx::Texture, Onyx::ImageData,
Onyx::Math::Vec2, Onyx::Math::Vec3, Onyx::Math::Vec4;

void PresetTests::MeshTest__Triangle1()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);
	
	Window window("MeshTest__Triangle1", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj(Onyx::MeshPresets::Triangle(1.0f), Onyx::ShaderPresets::V_Color(Vec4(1.0f, 1.0f, 1.0f, 1.0f)));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-2.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();
		
		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::MeshTest__Triangle2()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("MeshTest__Triangle2", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj(Onyx::MeshPresets::Triangle(1.0f, 1.0f), Onyx::ShaderPresets::V_Color(Vec4(1.0f, 1.0f, 1.0f, 1.0f)));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-2.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::MeshTest__Triangle3()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("MeshTest__Triangle3", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj(Onyx::MeshPresets::Triangle(Vec2(0.0f, 0.0f), Vec2(0.5f, 0.0f), Vec2(0.1f, 1.0f)), Onyx::ShaderPresets::V_Color(Vec4(1.0f, 1.0f, 1.0f, 1.0f)));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-2.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::MeshTest__Square()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("MeshTest__Square", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj(Onyx::MeshPresets::Square(1.0f), Onyx::ShaderPresets::V_Color(Vec4(1.0f, 1.0f, 1.0f, 1.0f)));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-2.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::MeshTest__Quad1()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("MeshTest__Quad1", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj(Onyx::MeshPresets::Quad(1.0f, 0.5f), Onyx::ShaderPresets::V_Color(Vec4(1.0f, 1.0f, 1.0f, 1.0f)));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-2.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::MeshTest__Quad2()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("MeshTest__Quad2", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj(Onyx::MeshPresets::Quad(Vec2(0.0f, 0.0f), Vec2(0.7f, 0.1f), Vec2(0.8f, 0.6f), Vec2(0.2f, 0.8f)), Onyx::ShaderPresets::V_Color(Vec4(1.0f, 1.0f, 1.0f, 1.0f)));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-2.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::MeshTest__Cube()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("MeshTest__Cube", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj(Onyx::MeshPresets::Cube(1.0f), Onyx::ShaderPresets::V_Color(Vec4(1.0f, 1.0f, 1.0f, 1.0f)));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-2.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::MeshAndShaderTest__RectPrism1__V_Color()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("MeshAndShaderTest__RectPrism1__V_Color", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj(Onyx::MeshPresets::RectPrism(1.0f, 0.5f, 2.0f), Onyx::ShaderPresets::V_Color(Vec4(0.0f, 0.3f, 1.0f, 1.0f)));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-2.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::MeshAndShaderTest__RectPrism2__V_XYZtoRGB()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("MeshAndShaderTest__RectPrism2__V_XYZtoRGB", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj(Onyx::MeshPresets::RectPrism(Vec3(0.0f, 0.0f, 0.0f), Vec3(0.7f, 0.1f, 0.0f), 
		Vec3(0.8f, 0.6f, 0.0f), Vec3(0.2f, 0.8f, 0.0f), 
		Vec3(0.0f, 0.2f, 2.0f), Vec3(0.6f, 0.2f, 1.7f), Vec3(0.85f, 0.6f, 1.6f), Vec3(0.2f, 0.85f, 2.1f)),
		Onyx::ShaderPresets::V_XYZtoRGB());

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::ShaderTest__VC()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("ShaderTest__VC", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f, 1.0f,
		 0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f, 1.0f,
		 0.0f,  0.5f, 0.0f,		0.0f, 0.0f, 1.0f, 1.0f
	};

	Renderable obj(
		Mesh(VertexArray(vertices, sizeof(vertices), Onyx::VertexFormat::VC), Onyx::MeshPresets::GetIndices(Onyx::MeshType::Triangle)),
		Onyx::ShaderPresets::VC()
	);

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::ShaderTest__VT()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("ShaderTest__VT", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	float vertices[] = {
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
	};

	Renderable obj(
		Mesh(VertexArray(vertices, sizeof(vertices), Onyx::VertexFormat::VT), IndexArray(Onyx::MeshPresets::GetIndices(Onyx::MeshType::Square))),
		Onyx::ShaderPresets::VT(),
		Texture(ImageData::Load(Onyx::GetResourcePath() + "textures/container.jpg"))
	);

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::ShaderTest__VCT()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("ShaderTest__VCT", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f, 1.0f,		 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 1.0f, 1.0f,		 1.0f, 0.0f,
		 0.5f,  0.5f, 0.0f,		0.0f, 0.0f, 1.0f, 1.0f,		 1.0f, 1.0f,
		-0.5f,  0.5f, 0.0f,		0.0f, 1.0f, 0.0f, 1.0f,		 0.0f, 1.0f
	};

	Renderable obj(
		Mesh(VertexArray(vertices, sizeof(vertices), Onyx::VertexFormat::VCT), IndexArray(Onyx::MeshPresets::GetIndices(Onyx::MeshType::Square))),
		Onyx::ShaderPresets::VCT(),
		Texture(ImageData::Load(Onyx::GetResourcePath() + "textures/container.jpg"))
	);

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::RenderableTest__ColoredTriangle1()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("RenderableTest__ColoredTriangle1", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::RenderablePresets::ColoredTriangle(1.0f, Vec3(1.0f, 0.0f, 0.0f));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::RenderableTest__ColoredTriangle2()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("RenderableTest__ColoredTriangle2", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::RenderablePresets::ColoredTriangle(2.0f, 1.0f, Vec3(0.0f, 1.0f, 0.0f));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::RenderableTest__ColoredTriangle3()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("RenderableTest__ColoredTriangle3", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::RenderablePresets::ColoredTriangle(Vec2(-0.9f, -0.6f), Vec2(0.8f, -0.9f), Vec2(0.1f, 0.8f), Vec3(0.0f, 0.0f, 1.0f));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::RenderableTest__VertexColoredTriangle1()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("RenderableTest__VertexColoredTriangle1", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::RenderablePresets::VertexColoredTriangle(1.0f);

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::RenderableTest__VertexColoredTriangle2()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("RenderableTest__VertexColoredTriangle2", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::RenderablePresets::VertexColoredTriangle(2.0f, 1.0f);

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::RenderableTest__VertexColoredTriangle3()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("RenderableTest__VertexColoredTriangle3", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::RenderablePresets::VertexColoredTriangle(Vec2(-0.9f, -0.6f), Vec2(0.8f, -0.9f), Vec2(0.1f, 0.8f));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::RenderableTest__TexturedTriangle1()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("RenderableTest__TexturedTriangle1", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::RenderablePresets::TexturedTriangle(1.0f, Texture(ImageData::Load(Onyx::GetResourcePath() + "textures/container.jpg")));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::RenderableTest__TexturedTriangle2()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("RenderableTest__TexturedTriangle2", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::RenderablePresets::TexturedTriangle(2.0f, 1.0f, Texture(ImageData::Load(Onyx::GetResourcePath() + "textures/container.jpg")));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::RenderableTest__TexturedTriangle3()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("RenderableTest__TexturedTriangle3", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::RenderablePresets::TexturedTriangle(Vec2(-0.9f, -0.6f), Vec2(0.8f, -0.9f), Vec2(0.1f, 0.8f), Texture(ImageData::Load(Onyx::GetResourcePath() + "textures/container.jpg")));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::RenderableTest__ColoredSquare()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("RenderableTest__ColoredSquare", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::RenderablePresets::ColoredSquare(1.0f, Vec3(1.0f, 0.0f, 0.0f));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::RenderableTest__ColoredQuad1()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("RenderableTest__ColoredQuad1", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::RenderablePresets::ColoredQuad(2.0f, 1.0f, Vec3(0.0f, 1.0f, 0.0f));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::RenderableTest__ColoredQuad2()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("RenderableTest__ColoredQuad2", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::RenderablePresets::ColoredQuad(Vec2(0.0f, 0.0f), Vec2(0.7f, 0.1f), Vec2(0.8f, 0.6f), Vec2(0.2f, 0.8f), Vec3(0.0f, 0.0f, 1.0f));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::RenderableTest__VertexColoredSquare()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("RenderableTest__VertexColoredSquare", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::RenderablePresets::VertexColoredSquare(1.0f);

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::RenderableTest__VertexColoredQuad1()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("RenderableTest__VertexColoredQuad1", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::RenderablePresets::VertexColoredQuad(2.0f, 1.0f);

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::RenderableTest__VertexColoredQuad2()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("RenderableTest__VertexColoredQuad2", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::RenderablePresets::VertexColoredQuad(Vec2(0.0f, 0.0f), Vec2(0.7f, 0.1f), Vec2(0.8f, 0.6f), Vec2(0.2f, 0.8f));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::RenderableTest__TexturedSquare()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("RenderableTest__TexturedSquare", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::RenderablePresets::TexturedSquare(1.0f, Texture(ImageData::Load(Onyx::GetResourcePath() + "textures/container.jpg")));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::RenderableTest__TexturedQuad1()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("RenderableTest__TexturedQuad1", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::RenderablePresets::TexturedQuad(2.0f, 1.0f, Texture(ImageData::Load(Onyx::GetResourcePath() + "textures/container.jpg")));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::RenderableTest__TexturedQuad2()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("RenderableTest__TexturedQuad2", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::RenderablePresets::TexturedQuad(Vec2(0.0f, 0.0f), Vec2(0.7f, 0.1f), Vec2(0.8f, 0.6f), Vec2(0.2f, 0.8f), Texture(ImageData::Load(Onyx::GetResourcePath() + "textures/container.jpg")));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::RenderableTest__ColoredCube()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("RenderableTest__ColoredCube", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::RenderablePresets::ColoredCube(1.0f, Vec3(1.0f, 0.0f, 0.0f));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::RenderableTest__TexturedCube()
{
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Window window("RenderableTest__TexturedCube", 1280, 720);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::RenderablePresets::TexturedCube(1.0f, Texture(ImageData::Load(Onyx::Resources("textures/container.jpg"))));

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Renderer renderer(window, cam);
	renderer.add(obj);

	double camSpeed = 4.0;
	double camSens = 30.0;

	input.setCursorLock(true);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void PresetTests::RunAllTests()
{
	MeshTest__Triangle1();
	std::cout << "MeshTest__Triangle1 - \x1b[32mCOMPLETE\x1b[39m\n";
	MeshTest__Triangle2();
	std::cout << "MeshTest__Triangle2 - \x1b[32mCOMPLETE\x1b[39m\n";
	MeshTest__Triangle3();
	std::cout << "MeshTest__Triangle3 - \x1b[32mCOMPLETE\x1b[39m\n";
	MeshTest__Square();
	std::cout << "MeshTest__Square - \x1b[32mCOMPLETE\x1b[39m\n";
	MeshTest__Quad1();
	std::cout << "MeshTest__Quad1 - \x1b[32mCOMPLETE\x1b[39m\n";
	MeshTest__Quad2();
	std::cout << "MeshTest__Quad2 - \x1b[32mCOMPLETE\x1b[39m\n";
	MeshTest__Cube();
	std::cout << "MeshTest__Cube - \x1b[32mCOMPLETE\x1b[39m\n";
	MeshAndShaderTest__RectPrism1__V_Color();
	std::cout << "MeshAndShaderTest__RectPrism1__V_Color - \x1b[32mCOMPLETE\x1b[39m\n";
	MeshAndShaderTest__RectPrism2__V_XYZtoRGB();
	std::cout << "MeshAndShaderTest__RectPrism2__V_XYZtoRGB - \x1b[32mCOMPLETE\x1b[39m\n";
	ShaderTest__VC();
	std::cout << "ShaderTest__VC - \x1b[32mCOMPLETE\x1b[39m\n";
	ShaderTest__VT();
	std::cout << "ShaderTest__VT - \x1b[32mCOMPLETE\x1b[39m\n";
	ShaderTest__VCT();
	std::cout << "ShaderTest__VCT - \x1b[32mCOMPLETE\x1b[39m\n";
	RenderableTest__ColoredTriangle1();
	std::cout << "RenderableTest__ColoredTriangle1 - \x1b[32mCOMPLETE\x1b[39m\n";
	RenderableTest__ColoredTriangle2();
	std::cout << "RenderableTest__ColoredTriangle2 - \x1b[32mCOMPLETE\x1b[39m\n";
	RenderableTest__ColoredTriangle3();
	std::cout << "RenderableTest__ColoredTriangle3 - \x1b[32mCOMPLETE\x1b[39m\n";
	RenderableTest__VertexColoredTriangle1();
	std::cout << "RenderableTest__VertexColoredTriangle1 - \x1b[32mCOMPLETE\x1b[39m\n";
	RenderableTest__VertexColoredTriangle2();
	std::cout << "RenderableTest__VertexColoredTriangle2 - \x1b[32mCOMPLETE\x1b[39m\n";
	RenderableTest__VertexColoredTriangle3();
	std::cout << "RenderableTest__VertexColoredTriangle3 - \x1b[32mCOMPLETE\x1b[39m\n";
	RenderableTest__TexturedTriangle1();
	std::cout << "RenderableTest__TexturedTriangle1 - \x1b[32mCOMPLETE\x1b[39m\n";
	RenderableTest__TexturedTriangle2();
	std::cout << "RenderableTest__TexturedTriangle2 - \x1b[32mCOMPLETE\x1b[39m\n";
	RenderableTest__TexturedTriangle3();
	std::cout << "RenderableTest__TexturedTriangle3 - \x1b[32mCOMPLETE\x1b[39m\n";
	RenderableTest__ColoredSquare();
	std::cout << "RenderableTest__ColoredSquare - \x1b[32mCOMPLETE\x1b[39m\n";
	RenderableTest__ColoredQuad1();
	std::cout << "RenderableTest__ColoredQuad1 - \x1b[32mCOMPLETE\x1b[39m\n";
	RenderableTest__ColoredQuad2();
	std::cout << "RenderableTest__ColoredQuad2 - \x1b[32mCOMPLETE\x1b[39m\n";
	RenderableTest__VertexColoredSquare();
	std::cout << "RenderableTest__VertexColoredSquare - \x1b[32mCOMPLETE\x1b[39m\n";
	RenderableTest__VertexColoredQuad1();
	std::cout << "RenderableTest__VertexColoredQuad1 - \x1b[32mCOMPLETE\x1b[39m\n";
	RenderableTest__VertexColoredQuad2();
	std::cout << "RenderableTest__VertexColoredQuad2 - \x1b[32mCOMPLETE\x1b[39m\n";
	RenderableTest__TexturedSquare();
	std::cout << "RenderableTest__TexturedSquare - \x1b[32mCOMPLETE\x1b[39m\n";
	RenderableTest__TexturedQuad1();
	std::cout << "RenderableTest__TexturedQuad1 - \x1b[32mCOMPLETE\x1b[39m\n";
	RenderableTest__TexturedQuad2();
	std::cout << "RenderableTest__TexturedQuad2 - \x1b[32mCOMPLETE\x1b[39m\n";
	RenderableTest__ColoredCube();
	std::cout << "RenderableTest__ColoredCube - \x1b[32mCOMPLETE\x1b[39m\n";

	std::cout << "\n";
}
