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
#include "ShaderPresets.h"
#include "MeshPresets.h"
#include "Renderer.h"
#include "TextRenderer.h"

using Onyx::Math::Vec3;
using Onyx::Math::Vec2;

bool initialized = false;
std::string resourcePath;
FT_Library* p_ft = new FT_Library;

void Onyx::Init()
{
	initialized = true;
	resourcePath = "resources/";

	FT_Init_FreeType(p_ft);
}

void Onyx::Init(ErrorHandler& errorHandler)
{
	if (initialized) errorHandler.err("Onyx already initialized");
	initialized = true;
	resourcePath = "resources/";

	if (FT_Init_FreeType(p_ft)) errorHandler.err("failed to initialize FreeType library");
}

void Onyx::Terminate()
{
	if (!initialized) return;

	FT_Done_FreeType(*p_ft);
	delete p_ft;
}

void Onyx::Demo()
{
	ErrorHandler errorHandler(true, false);

	Window window("Onyx", 1280, 720);
	window.init(errorHandler);
	window.setBackgroundColor(Vec3(0.0f, 0.0f, 0.0f));

	InputHandler input;
	window.setInputHandler(input);

	float vertices[] = {
	//	 XYZ					RGB
		-1.0f, -1.0f, -1.0f,	1.0f, 0.0f, 0.0f,
		 1.0f, -1.0f, -1.0f,	1.0f, 0.3f, 0.0f,
		 1.0f,  1.0f, -1.0f,	1.0f, 1.0f, 0.0f,
		-1.0f,  1.0f, -1.0f,	0.0f, 1.0f, 0.0f,

		-1.0f, -1.0f,  1.0f,	0.0f, 0.7f, 1.0f,
		 1.0f, -1.0f,  1.0f,	0.0f, 0.0f, 1.0f,
		 1.0f,  1.0f,  1.0f,	0.5f, 0.0f, 1.0f,
		-1.0f,  1.0f,  1.0f,	1.0f, 0.0f, 1.0f
	};

	Mesh cubeMesh(
		VertexArray(vertices, sizeof(vertices), ONYX_VERTEX_FORMAT_VC, false),
		MeshPresets::GetIndices(ONYX_MESH_CUBE)
	);
	Renderable cube(cubeMesh, ShaderPresets::VC());
	cube.scale(0.5f);

	Camera cam(Projection::Perspective(60.0f, 1280, 720));
	window.setCamera(cam);

	Renderer renderer(cam);
	renderer.add(cube);

	Font roboto(Onyx::GetResourcePath() + "fonts/Roboto/Roboto-Regular.ttf", 32, errorHandler);
	TextRenderer textRenderer(window);
	textRenderer.setFont(roboto);

	double camSpeed = 5.0;
	double camSens = 30.0;

	double lastTime = 0.0;
	double deltaTime = 0.0;

	double lastX = input.getMouseX();
	double deltaX = 0.0;

	double lastY = input.getMouseY();
	double deltaY = 0.0;

	int fps = 0;

	input.lockCursor();

	input.setKeyCooldown(ONYX_KEY_LEFT_CONTROL, 0.5f);
	input.setKeyCooldown(ONYX_KEY_F12, 0.5f);
	input.setKeyCooldown(ONYX_KEY_1, 0.5f);
	input.setKeyCooldown(ONYX_KEY_2, 0.5f);

	for (int frame = 1; window.isOpen(); frame++)
	{
		fps = round(1.0f / deltaTime);
		//std::cout << "FPS: " << fps << ", FRAME: " << frame << "\n";

		input.updateCooldowns(deltaTime);

		if (input.isKeyDown(ONYX_KEY_ESCAPE)) window.close();
		if (input.isKeyDown(ONYX_KEY_LEFT_CONTROL)) input.toggleCursorLock();
		if (input.isKeyDown(ONYX_KEY_W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(ONYX_KEY_A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(ONYX_KEY_S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(ONYX_KEY_D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(ONYX_KEY_SPACE)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(ONYX_KEY_C)) cam.translateUD(-camSpeed * deltaTime);
		if (input.isKeyDown(ONYX_KEY_F12)) window.toggleFullscreen();
		if (input.isKeyDown(ONYX_KEY_1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(ONYX_KEY_2)) renderer.toggleVisibility(0);

		cam.rotate(camSens * deltaX * deltaTime, camSens * deltaY * deltaTime);
		cam.update();

		cube.rotate(20.0f * deltaTime, Vec3(0.5f, 0.3f, 1.0f));

		window.startRender();
		renderer.render();

		textRenderer.renderText("Onyx Demo", Vec2(23.0f, window.getBufferHeight() - 50.0f), Vec3(0.0f, 0.5f, 1.0f));

		textRenderer.renderText("forward/left/backward/right - [W]/[A]/[S]/[D]", Vec2(25.0f, window.getBufferHeight() - 80.0f), 0.6f, Vec3(1.0f, 1.0f, 1.0f));
		textRenderer.renderText("up/down - [Space]/[C]", Vec2(25.0f, window.getBufferHeight() - 105.0f), 0.6f, Vec3(1.0f, 1.0f, 1.0f));
		textRenderer.renderText("Mouse to look around", Vec2(25.0f, window.getBufferHeight() - 130.0f), 0.6f, Vec3(1.0f, 1.0f, 1.0f));

		textRenderer.renderText("Toggle wireframe: [1]", Vec2(25.0f, window.getBufferHeight() - 170.0f), 0.6f, Vec3(1.0f, 1.0f, 1.0f));
		textRenderer.renderText("Toggle cube visibility: [2]", Vec2(25.0f, window.getBufferHeight() - 195.0f), 0.6f, Vec3(1.0f, 1.0f, 1.0f));
		textRenderer.renderText("Toggle fullscreen: [F12]", Vec2(25.0f, window.getBufferHeight() - 220.0f), 0.6f, Vec3(1.0f, 1.0f, 1.0f));
		window.endRender();

		double x = input.getMouseX();
		deltaX = x - lastX;
		lastX = x;

		double y = input.getMouseY();
		deltaY = y - lastY;
		lastY = y;

		double time = Onyx::GetTime();
		deltaTime = time - lastTime;
		lastTime = time;
	}

	renderer.dispose();
	window.dispose();
}

bool Onyx::IsInitialized()
{
	return initialized;
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

FT_Library* Onyx::GetFreeTypeLibrary()
{
	return p_ft;
}

double Onyx::GetTime()
{
	return glfwGetTime();
}
