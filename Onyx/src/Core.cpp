#pragma warning(disable : 4244; disable: 4267)


#include "Core.h"

#include <string>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "Math.h"
#include "Window.h"
#include "Projection.h"
#include "Model.h"
#include "TextRenderable.h"

using Onyx::Math::Vec2, Onyx::Math::Vec3, Onyx::Math::Vec4;

bool initialized = false;
bool glInitialized = false;
Onyx::ErrorHandler* p_errorHandler = nullptr;
std::string resourcePath;
FT_Library ft;
void* p_user;
std::vector<std::pair<void*, bool>> mallocs;

const char* _glErrorToString(uint errorCode)
{
	switch (errorCode)
	{
		case GL_INVALID_ENUM:					return "INVALID_ENUM";
		case GL_INVALID_VALUE:					return "INVALID_VALUE";
		case GL_INVALID_OPERATION:				return "INVALID_OPERATION";
		case GL_STACK_OVERFLOW:					return "STACK_OVERFLOW";
		case GL_STACK_UNDERFLOW:				return "STACK_UNDERFLOW";
		case GL_OUT_OF_MEMORY:					return "OUT_OF_MEMORY";
		case GL_INVALID_FRAMEBUFFER_OPERATION:	return "INVALID_FRAMEBUFFER_OPERATION";
	}

	return "UNKNOWN";
}

uint _glCheckError(const std::string& file, int line)
{
	uint errorCode;
	while ((errorCode = glGetError()) != GL_NO_ERROR)
	{
		std::cout << "[OpenGL Error] " << glErrorToString(errorCode) << " | " << file.substr(file.find_last_of("\\") + 1) << " (" << line << ")\n";
	}
	return errorCode;
}

void onyx_set_gl_init(bool val)
{
	glInitialized = val;
}

bool onyx_is_ehandler_nullptr()
{
	return p_errorHandler == nullptr;
}

FT_Library* onyx_get_ft()
{
	return &ft;
}

void onyx_add_malloc(void* ptr, bool array)
{
	mallocs.push_back(std::pair<void*, bool>(ptr, array));
}

void Onyx::Init()
{
	initialized = true;
	resourcePath = "resources/";

	FT_Init_FreeType(&ft);

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef ONYX_OS_MAC
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif
}

void Onyx::Init(ErrorHandler& errorHandler)
{
	p_errorHandler = &errorHandler;

	if (initialized) Err("Onyx already initialized");
	initialized = true;
	resourcePath = "resources/";

	if (FT_Init_FreeType(&ft)) Err("failed to initialize FreeType.");

	if (!glfwInit())
	{
		Err("failed to initialize GLFW.");
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef ONYX_OS_MAC
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif
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
	std::string ver = std::to_string(ONYX_VERSION_MAJOR) + "." + std::to_string(ONYX_VERSION_MINOR) + "." + std::to_string(ONYX_VERSION_PATCH);
	if (ONYX_STABLE) return ver;
	else if (ONYX_ALPHA) return ver + "-alpha";
	else if (ONYX_BETA) return ver + "-beta";
	else if (ONYX_RELEASE_CANDIDATE) return ver = "-rc";
}

void Onyx::Terminate()
{
	if (!initialized) return;

	FT_Done_FreeType(ft);
	glfwTerminate();

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
	Window window(
		WindowProperties {
			.title = "Onyx Demo",
			.width = 1280,
			.height = 720,
			.nSamplesMSAA = 4
		}
	);
	window.init();
	window.setBackgroundColor(Vec3(0.0f, 0.7f, 1.0f));

	WindowIcon icon = WindowIcon::Load({
		Onyx::Resources("icons/icon-16x.png"),
		Onyx::Resources("icons/icon-24x.png"),
		Onyx::Resources("icons/icon-32x.png"),
		Onyx::Resources("icons/icon-48x.png"),
		Onyx::Resources("icons/icon-256x.png"),
	});
	
	window.setIcon(icon);
	icon.dispose();

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
		Mesh(VertexBuffer(bgVertices, sizeof(bgVertices), Onyx::VertexFormat::V), IndexBuffer(bgIndices, sizeof(bgIndices))),
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

	textRenderables[0].setPosition(Vec2(23.0f, window.getBufferHeight() - 50.0f));
	textRenderables[1].setPosition(Vec2(25.0f, window.getBufferHeight() - 80.0f));
	textRenderables[1].setScale(0.6f);
	textRenderables[2].setPosition(Vec2(25.0f, window.getBufferHeight() - 100.0f));
	textRenderables[2].setScale(0.6f);
	textRenderables[3].setPosition(Vec2(25.0f, 30.0f));
	textRenderables[3].setScale(0.6f);
	textRenderables[4].setPosition(Vec2(25.0f, 55.0f));
	textRenderables[4].setScale(0.6f);
	textRenderables[5].setPosition(Vec2(25.0f, 80.0f));
	textRenderables[5].setScale(0.6f);
	textRenderables[6].setPosition(Vec2(25.0f, 105.0f));
	textRenderables[6].setScale(0.6f);
	textRenderables[7].setPosition(Vec2(25.0f, 130.0f));
	textRenderables[7].setScale(0.6f);
	textRenderables[8].setPosition(Vec2(25.0f, 155.0f));
	textRenderables[8].setScale(0.6f);
	textRenderables[9].setPosition(Vec2(25.0f, 180.0f));
	textRenderables[9].setScale(0.6f);
	textRenderables[10].setPosition(Vec2(25.0f, 205.0f));
	textRenderables[10].setScale(0.6f);

	// make members of TextRenderable public for this to work
	/*for (CharRenderable& c : textRenderables[0].chars)
	{
		std::cout << c.getChar() << ": VAO " << c.getVAO() << ", VBO " << c.getVBO() << ", Tex " << c.getTextureID() << "\n";
	}
	textRenderables[0].setText("Demo Onyx");
	std::cout << "\n";
	for (CharRenderable& c : textRenderables[0].chars)
	{
		std::cout << c.getChar() << ": VAO " << c.getVAO() << ", VBO " << c.getVBO() << ", Tex " << c.getTextureID() << "\n";
	}*/

	for (TextRenderable& tr : textRenderables) renderer.add(tr);

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

		textRenderables[1].setText("FPS: " + std::to_string(fps));
		textRenderables[2].setText("FRAME " + std::to_string(window.getFrame()));
		
		window.startRender();
		renderer.render();
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

bool Onyx::IsOpenGLInitialized()
{
	return glInitialized;
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

const std::string& Onyx::GetResourcePath()
{
	return resourcePath;
}

std::string Onyx::Resources(const std::string& path)
{
	if (path.length() == 0) return resourcePath;
	return resourcePath + (path[0] == '/' || path[0] == '\\' ? path.substr(1) : path);
}

void* Onyx::GetUserPtr()
{
	return p_user;
}

double Onyx::GetTime()
{
	return glfwGetTime();
}

std::string Onyx::GetGraphics()
{
	if (!glInitialized) Err("OpenGL must be initialized before calling GetGraphics(). Initialize a window.");
	return (const char*)glGetString(GL_RENDERER);

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}
