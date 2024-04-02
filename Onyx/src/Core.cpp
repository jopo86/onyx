#pragma warning(disable : 4244)

#include <map>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Core.h"
#include "Window.h"
#include "InputHandler.h"
#include "Math.h"
#include "Mesh.h"
#include "Renderable.h"
#include "UiRenderable.h"
#include "ShaderPresets.h"
#include "MeshPresets.h"
#include "Renderer.h"
#include "TextRenderer.h"
#include "RenderablePresets.h"

using Onyx::Math::Vec2, Onyx::Math::Vec3, Onyx::Math::Vec4;

bool initialized = false;
Onyx::ErrorHandler* p_errorHandler = nullptr;
std::string resourcePath;
FT_Library ft;

void Onyx::Init()
{
	initialized = true;
	resourcePath = "resources/";

	FT_Init_FreeType(&ft);
}

void Onyx::Init(ErrorHandler& errorHandler)
{
	p_errorHandler = &errorHandler;

	if (initialized) Err("Onyx already initialized");
	initialized = true;
	resourcePath = "resources/";

	if (FT_Init_FreeType(&ft)) Err("failed to initialize FreeType library");
}

void Onyx::Terminate()
{
	if (!initialized) return;

	FT_Done_FreeType(ft);
	initialized = false;
}

void Onyx::Demo()
{
	Window window("Onyx", 1280, 720);
	window.init();
	window.setBackgroundColor(Vec3(0.0f, 0.7f, 1.0f));

	InputHandler input(window);

	Renderable cube = RenderablePresets::TexturedCube(1.0f, Texture(ImageData::Load(Resources("textures/container.jpg"))));
	
	float vertices[] = {
		10.0f,  710.0f, 0.0f,
		200.0f, 710.0f, 0.0f,
		200.0f, 600.0f, 0.0f,
		10.0f,  600.0f, 0.0f
	};

	uint indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	UiRenderable textBg(
		Mesh(VertexArray(vertices, sizeof(vertices), ONYX_VERTEX_FORMAT_V, false), IndexArray(indices, sizeof(indices), false)),
		Vec4(0.0f, 0.0f, 0.0f, 0.3f)
	);

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-3.0f);

	Renderer renderer(window, cam);
	renderer.add(cube);
	renderer.add(textBg);

	Font robotoReg(Resources("fonts/Roboto/Roboto-Regular.ttf"), 32);
	Font robotoBold(Resources("fonts/Roboto/Roboto-Bold.ttf"), 32);
	TextRenderer textRenderer(window);

	double camSpeed = 5.0;
	double camSens = 30.0;

	input.setCursorLock(true);

	input.setKeyCooldown(ONYX_KEY_F12, 1.0f);
	input.setKeyCooldown(ONYX_KEY_1, 0.5f);
	input.setKeyCooldown(ONYX_KEY_2, 0.5f);
	input.setMouseButtonCooldown(ONYX_MOUSE_BUTTON_LEFT, 0.5f);

	int fps = 0;

	Projection ortho = Projection::Orthographic(0, 1280, 720, 0);

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();
		if (window.getFrame() % 100 == 0 || window.getFrame() == 2) fps = window.getFPS();

		if (input.isKeyDown(ONYX_KEY_ESCAPE)) window.close();
		if (input.isKeyDown(ONYX_KEY_W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(ONYX_KEY_A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(ONYX_KEY_S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(ONYX_KEY_D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(ONYX_KEY_SPACE)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(ONYX_KEY_C)) cam.translateUD(-camSpeed * deltaTime);
		if (input.isKeyDown(ONYX_KEY_F12)) window.toggleFullscreen();
		if (input.isKeyDown(ONYX_KEY_1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(ONYX_KEY_2)) cube.toggleVisibility();

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		cube.rotate(20.0f * deltaTime, Vec3(0.5f, 0.3f, 1.0f));

		window.startRender();
		renderer.render();

		TextRenderer::StartRender();
		textRenderer.setFont(robotoBold);
		textRenderer.render("Onyx Demo", Vec2(23.0f, window.getBufferHeight() - 50.0f), Vec3(1.0f, 1.0f, 1.0f));
		textRenderer.setFont(robotoReg);
		textRenderer.render("FPS: " + std::to_string(fps), Vec2(25.0f, window.getBufferHeight() - 80.0f), 0.6f, Vec3(1.0f, 1.0f, 1.0f));
		textRenderer.render("FRAME " + std::to_string(window.getFrame()), Vec2(25.0f, window.getBufferHeight() - 100.0f), 0.6f, Vec3(1.0f, 1.0f, 1.0f));

		textRenderer.render("Toggle Fullscreen: [F12]", Vec2(25.0f, 30.0f), 0.6f, Vec3(1.0f, 1.0f, 1.0f));
		textRenderer.render("Toggle Cube Visibility: [2]", Vec2(25.0f, 55.0f), 0.6f, Vec3(1.0f, 1.0f, 1.0f));
		textRenderer.render("Toggle Wireframe: [1]", Vec2(25.0f, 80.0f), 0.6f, Vec3(1.0f, 1.0f, 1.0f));
		textRenderer.render("Mouse to look around", Vec2(25.0f, 105.0f), 0.6f, Vec3(1.0f, 1.0f, 1.0f));
		textRenderer.render("Up/Down: [Space]/[C]", Vec2(25.0f, 130.0f), 0.6f, Vec3(1.0f, 1.0f, 1.0f));
		textRenderer.render("Forward/Left/Backward/Right: [W]/[A]/[S]/[D]", Vec2(25.0f, 155.0f), 0.6f, Vec3(1.0f, 1.0f, 1.0f));
		textRenderer.render("Exit: [ESCAPE]", Vec2(25.0f, 180.0f), 0.6f, Vec3(1.0f, 1.0f, 1.0f));
		TextRenderer::EndRender();

		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	robotoReg.dispose();
	robotoBold.dispose();
}

void Onyx::Err(std::string msg)
{
	if (p_errorHandler != nullptr) p_errorHandler->err(msg);
}

bool Onyx::IsInitialized()
{
	return initialized;
}

void Onyx::SetErrorHandler(ErrorHandler& errorHandler)
{
	p_errorHandler = &errorHandler;
}

void Onyx::SetResourcePath(std::string path)
{
	if (path.length() == 0) return;
	
	if (path[path.length() - 1] != '/' && path[path.length() - 1] != '\\') resourcePath = path + "/";
	else resourcePath = path;
}

std::string Onyx::GetResourcePath()
{
	return resourcePath;
}

std::string Onyx::Resources(std::string path)
{
	return resourcePath + path;
}

FT_Library* Onyx::GetFreeTypeLibrary()
{
	return &ft;
}

double Onyx::GetTime()
{
	return glfwGetTime();
}
