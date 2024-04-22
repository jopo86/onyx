#pragma warning(disable: 4244)

#include "PresetTests.h"

using Onyx::ErrorHandler, Onyx::Window, Onyx::InputHandler,
Onyx::Mesh, Onyx::Shader, Onyx::Renderable, Onyx::Camera,
Onyx::Projection, Onyx::Renderer, Onyx::VertexBuffer,
Onyx::IndexBuffer, Onyx::Texture,
Onyx::Math::Vec2, Onyx::Math::Vec3, Onyx::Math::Vec4;

void PresetTests::MeshTest__Triangle1()
{
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);
	
	Onyx::WindowProperties wp{
		.title = "MeshTest__Triangle1",
		.width = 1280,
		.height = 720,
	};

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj(Onyx::Mesh::Triangle(1.0f), Onyx::Shader::P_Color(Vec4(1.0f, 1.0f, 1.0f, 1.0f)));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "MeshTest__Triangle2",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj(Onyx::Mesh::Triangle(1.0f, 1.0f), Onyx::Shader::P_Color(Vec4(1.0f, 1.0f, 1.0f, 1.0f)));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "MeshTest__Triangle3",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj(Onyx::Mesh::Triangle(Vec2(0.0f, 0.0f), Vec2(0.5f, 0.0f), Vec2(0.1f, 1.0f)), Onyx::Shader::P_Color(Vec4(1.0f, 1.0f, 1.0f, 1.0f)));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "MeshTest__Square",
        .width = 1280,
        .height = 720,
    };


	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj(Onyx::Mesh::Square(1.0f), Onyx::Shader::P_Color(Vec4(1.0f, 1.0f, 1.0f, 1.0f)));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "MeshTest__Quad1",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj(Onyx::Mesh::Quad(1.0f, 0.5f), Onyx::Shader::P_Color(Vec4(1.0f, 1.0f, 1.0f, 1.0f)));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "MeshTest__Quad2",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj(Onyx::Mesh::Quad(Vec2(0.0f, 0.0f), Vec2(0.7f, 0.1f), Vec2(0.8f, 0.6f), Vec2(0.2f, 0.8f)), Onyx::Shader::P_Color(Vec4(1.0f, 1.0f, 1.0f, 1.0f)));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "MeshTest__Cube",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj(Onyx::Mesh::Cube(1.0f), Onyx::Shader::P_Color(Vec4(1.0f, 1.0f, 1.0f, 1.0f)));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "MeshAndShaderTest__RectPrism1__V_Color",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj(Onyx::Mesh::RectPrism(1.0f, 0.5f, 2.0f), Onyx::Shader::P_Color(Vec4(0.0f, 0.3f, 1.0f, 1.0f)));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "MeshAndShaderTest__RectPrism2__V_XYZtoRGB",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj(Onyx::Mesh::RectPrism(Vec3(0.0f, 0.0f, 0.0f), Vec3(0.7f, 0.1f, 0.0f), 
		Vec3(0.8f, 0.6f, 0.0f), Vec3(0.2f, 0.8f, 0.0f), 
		Vec3(0.0f, 0.2f, 2.0f), Vec3(0.6f, 0.2f, 1.7f), Vec3(0.85f, 0.6f, 1.6f), Vec3(0.2f, 0.85f, 2.1f)),
		Onyx::Shader::P_XYZtoRGB());

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "ShaderTest__VC",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f, 1.0f,
		 0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f, 1.0f,
		 0.0f,  0.5f, 0.0f,		0.0f, 0.0f, 1.0f, 1.0f
	};

	Renderable obj(
		Mesh(VertexBuffer(vertices, sizeof(vertices), Onyx::VertexFormat::PC), IndexBuffer::Triangle()),
		Onyx::Shader::PC()
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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "ShaderTest__VT",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
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
		Mesh(VertexBuffer(vertices, sizeof(vertices), Onyx::VertexFormat::PT), IndexBuffer::Square()),
		Onyx::Shader::PT(),
		Texture::Load(Onyx::GetResourcePath() + "textures/container.jpg")
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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "ShaderTest__VCT",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
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
		Mesh(VertexBuffer(vertices, sizeof(vertices), Onyx::VertexFormat::PCT), IndexBuffer::Square()),
		Onyx::Shader::PCT(),
		Texture::Load(Onyx::GetResourcePath() + "textures/container.jpg")
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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "RenderableTest__ColoredTriangle1",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::Renderable::ColoredTriangle(1.0f, Vec3(1.0f, 0.0f, 0.0f));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "RenderableTest__ColoredTriangle2",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::Renderable::ColoredTriangle(2.0f, 1.0f, Vec3(0.0f, 1.0f, 0.0f));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "RenderableTest__ColoredTriangle3",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::Renderable::ColoredTriangle(Vec2(-0.9f, -0.6f), Vec2(0.8f, -0.9f), Vec2(0.1f, 0.8f), Vec3(0.0f, 0.0f, 1.0f));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "RenderableTest__VertexColoredTriangle1",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::Renderable::VertexColoredTriangle(1.0f);

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "RenderableTest__VertexColoredTriangle2",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::Renderable::VertexColoredTriangle(2.0f, 1.0f);

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "RenderableTest__VertexColoredTriangle3",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::Renderable::VertexColoredTriangle(Vec2(-0.9f, -0.6f), Vec2(0.8f, -0.9f), Vec2(0.1f, 0.8f));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "RenderableTest__TexturedTriangle1",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::Renderable::TexturedTriangle(1.0f, Texture::Load(Onyx::GetResourcePath() + "textures/container.jpg"));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "RenderableTest__TexturedTriangle2",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::Renderable::TexturedTriangle(2.0f, 1.0f, Texture::Load(Onyx::GetResourcePath() + "textures/container.jpg"));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "RenderableTest__TexturedTriangle3",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::Renderable::TexturedTriangle(Vec2(-0.9f, -0.6f), Vec2(0.8f, -0.9f), Vec2(0.1f, 0.8f), Texture::Load(Onyx::GetResourcePath() + "textures/container.jpg"));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "RenderableTest__ColoredSquare",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::Renderable::ColoredSquare(1.0f, Vec3(1.0f, 0.0f, 0.0f));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "RenderableTest__ColoredQuad1",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::Renderable::ColoredQuad(2.0f, 1.0f, Vec3(0.0f, 1.0f, 0.0f));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "RenderableTest__ColoredQuad2",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::Renderable::ColoredQuad(Vec2(0.0f, 0.0f), Vec2(0.7f, 0.1f), Vec2(0.8f, 0.6f), Vec2(0.2f, 0.8f), Vec3(0.0f, 0.0f, 1.0f));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "RenderableTest__VertexColoredSquare",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::Renderable::VertexColoredSquare(1.0f);

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "RenderableTest__VertexColoredQuad1",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::Renderable::VertexColoredQuad(2.0f, 1.0f);

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "RenderableTest__VertexColoredQuad2",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::Renderable::VertexColoredQuad(Vec2(0.0f, 0.0f), Vec2(0.7f, 0.1f), Vec2(0.8f, 0.6f), Vec2(0.2f, 0.8f));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "RenderableTest__TexturedSquare",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::Renderable::TexturedSquare(1.0f, Texture::Load(Onyx::GetResourcePath() + "textures/container.jpg"));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "RenderableTest__TexturedQuad1",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::Renderable::TexturedQuad(2.0f, 1.0f, Texture::Load(Onyx::GetResourcePath() + "textures/container.jpg"));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "RenderableTest__TexturedQuad2",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::Renderable::TexturedQuad(Vec2(0.0f, 0.0f), Vec2(0.7f, 0.1f), Vec2(0.8f, 0.6f), Vec2(0.2f, 0.8f), Texture::Load(Onyx::GetResourcePath() + "textures/container.jpg"));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "RenderableTest__ColoredCube",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::Renderable::ColoredCube(1.0f, Vec3(1.0f, 0.0f, 0.0f));

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
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::WindowProperties wp{
        .title = "RenderableTest__TexturedCube",
        .width = 1280,
        .height = 720,
    };

	Window window(wp);
	window.init();
	window.setBackgroundColor(Onyx::Math::Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input(window);

	Renderable obj = Onyx::Renderable::TexturedCube(1.0f, Texture::Load(Onyx::Resources("textures/container.jpg")));

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
