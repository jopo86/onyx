#pragma warning(disable : 4244; disable: 4267)

#include "Core.h"

#include <string>

#include "Math.h"
#include "Window.h"
#include "RenderablePresets.h"
#include "Projection.h"
#include "Model.h"
#include "ShaderPresets.h"
#include "TextRenderable.h"

using Onyx::Math::Vec2, Onyx::Math::Vec3, Onyx::Math::Vec4;

bool initialized = false;
Onyx::ErrorHandler* p_errorHandler = nullptr;
std::string resourcePath;
FT_Library ft;
void* p_user;

std::vector<std::pair<void*, bool>> mallocs;

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

int Onyx::GetVersionMajor()
{
	return ONYX_VERSION_MAJOR;
}

int Onyx::GetVersionMinor()
{
	return ONYX_VERSION_MINOR;
}

int Onyx::GetVersionPatch()
{
	return ONYX_VERSION_PATCH;
}

bool Onyx::IsBeta()
{
	return ONYX_BETA;
}

std::string Onyx::GetVersionString()
{
	return std::to_string(ONYX_VERSION_MAJOR) + "." + std::to_string(ONYX_VERSION_MINOR) + "." + std::to_string(ONYX_VERSION_PATCH) + (ONYX_BETA ? "-beta" : "");
}

void Onyx::Terminate()
{
	if (!initialized) return;

	FT_Done_FreeType(ft);

	for (int i = mallocs.size() - 1; i >= 0; i--)
	{
		if (mallocs[i].second) delete[] mallocs[i].first;
		else delete mallocs[i].first;
		mallocs.pop_back();
	}
	initialized = false;
}

void Onyx::Demo()
{
	Window window("Onyx", 1280, 720);
	window.init(8);
	window.setBackgroundColor(Vec3(0.0f, 0.7f, 1.0f));

	InputHandler input(window);
	
	float bgVertices[] = {
		10.0f,  710.0f, 0.0f,
		200.0f, 710.0f, 0.0f,
		200.0f, 600.0f, 0.0f,
		10.0f,  600.0f, 0.0f
	};

	uint bgIndices[] = {
		0, 1, 2,
		2, 3, 0
	};

	float start = GetTime();
	ModelRenderable car(Model::LoadOBJ(Onyx::Resources("models/Corvette C8.obj")));
	float duration = round((GetTime() - start) * 100) / 100;
	
	std::cout << "Model loaded in " << duration << " sec\n";

	UiRenderable textBg(
		Mesh(VertexArray(bgVertices, sizeof(bgVertices), Onyx::VertexFormat::V), IndexArray(bgIndices, sizeof(bgIndices))),
		Vec4(0.0f, 0.0f, 0.0f, 0.3f)
	);

	Camera cam(window, Projection::Perspective(60.0f, 1280, 720));
	cam.translateFB(-4.0f);

	Lighting lighting(Vec3(1.0f, 1.0f, 1.0f), 0.3f, Vec3(-0.2f, -1.0f, -0.3f));

	Renderer renderer(window, cam, lighting);
	renderer.add(car);
	renderer.add(textBg);

	Font robotoReg = Font::Load(Resources("fonts/Roboto/Roboto-Regular.ttf"), 32);
	Font robotoBold = Font::Load(Resources("fonts/Roboto/Roboto-Bold.ttf"), 32);

	std::vector<TextRenderable> textRenderables;

	textRenderables.push_back(TextRenderable("Onyx Demo", robotoBold, Vec3(1.0f, 1.0f, 1.0f)));
	textRenderables.push_back(TextRenderable("FPS: 0", robotoReg, Vec3(1.0f, 1.0f, 1.0f)));
	textRenderables.push_back(TextRenderable("FRAME 0", robotoReg, Vec3(1.0f, 1.0f, 1.0f)));
	textRenderables.push_back(TextRenderable("Toggle Fullscreen: [F12]", robotoReg, Vec3(1.0f, 1.0f, 1.0f)));
	textRenderables.push_back(TextRenderable("Toggle Lighting: [3]", robotoReg, Vec3(1.0f, 1.0f, 1.0f)));
	textRenderables.push_back(TextRenderable("Toggle Car Visibility: [2]", robotoReg, Vec3(1.0f, 1.0f, 1.0f)));
	textRenderables.push_back(TextRenderable("Toggle Wireframe: [1]", robotoReg, Vec3(1.0f, 1.0f, 1.0f)));
	textRenderables.push_back(TextRenderable("Mouse to look around", robotoReg, Vec3(1.0f, 1.0f, 1.0f)));
	textRenderables.push_back(TextRenderable("Up/Down: [Space]/[C]", robotoReg, Vec3(1.0f, 1.0f, 1.0f)));
	textRenderables.push_back(TextRenderable("Forward/Left/Backward/Right: [W]/[A]/[S]/[D]", robotoReg, Vec3(1.0f, 1.0f, 1.0f)));
	textRenderables.push_back(TextRenderable("Exit: [ESCAPE]", robotoReg, Vec3(1.0f, 1.0f, 1.0f)));

	textRenderables[0].translate(Vec2(23.0f, window.getBufferHeight() - 50.0f));
	textRenderables[1].translate(Vec2(25.0f, window.getBufferHeight() - 80.0f));
	textRenderables[1].scale(0.6f);
	textRenderables[2].translate(Vec2(25.0f, window.getBufferHeight() - 100.0f));
	textRenderables[2].scale(0.6f);
	textRenderables[3].translate(Vec2(25.0f, 30.0f));
	textRenderables[3].scale(0.6f);
	textRenderables[4].translate(Vec2(25.0f, 55.0f));
	textRenderables[4].scale(0.6f);
	textRenderables[5].translate(Vec2(25.0f, 80.0f));
	textRenderables[5].scale(0.6f);
	textRenderables[6].translate(Vec2(25.0f, 105.0f));
	textRenderables[6].scale(0.6f);
	textRenderables[7].translate(Vec2(25.0f, 130.0f));
	textRenderables[7].scale(0.6f);
	textRenderables[8].translate(Vec2(25.0f, 155.0f));
	textRenderables[8].scale(0.6f);
	textRenderables[9].translate(Vec2(25.0f, 180.0f));
	textRenderables[9].scale(0.6f);
	textRenderables[10].translate(Vec2(25.0f, 205.0f));
	textRenderables[10].scale(0.6f);

	for (int i = 0; i < textRenderables.size(); i++) renderer.add(textRenderables[i]);

	double camSpeed = 5.0;
	double camSens = 30.0;

	input.setCursorLock(true);

	input.setKeyCooldown(Onyx::Key::F12, 1.0f);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);
	input.setKeyCooldown(Onyx::Key::Num2, 0.5f);
	input.setKeyCooldown(Onyx::Key::Num3, 0.5f);
	input.setMouseButtonCooldown(Onyx::MouseButton::Left, 0.5f);

	int fps = 0;

	while (window.isOpen())
	{
		input.update();

		double deltaTime = window.getDeltaTime();
		if (window.getFrame() % 100 == 0 || window.getFrame() == 2) fps = window.getFPS();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-camSpeed * deltaTime);
		if (input.isKeyDown(Onyx::Key::F12)) window.toggleFullscreen();
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::Num2))
		{
			car.toggleVisibility();
		}
		if (input.isKeyDown(Onyx::Key::Num3)) renderer.toggleLightingEnabled();

		cam.rotate(camSens * input.getMouseDeltas().getX() * deltaTime, camSens * input.getMouseDeltas().getY() * deltaTime);
		cam.update();

		car.rotate(20.0f * window.getDeltaTime(), Vec3(0, 1, 0));

		window.startRender();
		renderer.render();

		textRenderables[1].setText("FPS: " + std::to_string(fps));
		textRenderables[2].setText("FRAME " + std::to_string(window.getFrame()));

		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	robotoReg.dispose();
	robotoBold.dispose();
}

void Onyx::Warn(const std::string& msg)
{
	if (p_errorHandler != nullptr) p_errorHandler->warn(msg);
}

void Onyx::Err(const std::string& msg)
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

void Onyx::SetUserPtr(void* ptr)
{
	p_user = ptr;
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

void* Onyx::GetUserPtr()
{
	return p_user;
}

double Onyx::GetTime()
{
	return glfwGetTime();
}

void Onyx::AddMalloc(void* ptr, bool array)
{
	mallocs.push_back(std::pair<void*, bool>(ptr, array));
}
