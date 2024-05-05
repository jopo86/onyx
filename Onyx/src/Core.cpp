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

void onyx_set_gl_init(bool val)
{
	glInitialized = val;
}

FT_Library* onyx_get_ft()
{
	return &ft;
}

void onyx_add_malloc(void* ptr, bool array)
{
	mallocs.push_back(std::pair<void*, bool>(ptr, array));
}

void onyx_err(const Onyx::Error& error)
{
	if (p_errorHandler != nullptr) p_errorHandler->err(error);
}

void onyx_warn(const Onyx::Warning& warning)
{
	if (p_errorHandler != nullptr) p_errorHandler->warn(warning);
}

void onyx_glerr(const Onyx::GLError& error)
{
	std::cout << error.toString() << "\n\n";
}

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
		onyx_glerr(Onyx::GLError{
			.code = errorCode,
			.file = file.substr(file.find_last_of("\\") + 1),
			.line = line
			}
		);
	}
	return errorCode;
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

	if (initialized)
	{
		onyx_warn(Warning{
				.sourceFunction = "Onyx::Init(ErrorHandler& errorHandler)",
				.message = "Attempted to initialize library when it is already initialize. Initialization aborted.",
				.howToFix = "If reinitialization was intentional, terminate the library first.",
				.severity = Warning::Severity::Low
			}
		);
		return;
	}
	initialized = true;
	resourcePath = "resources/";

	if (FT_Init_FreeType(&ft))
	{
		onyx_err(Error{
			.sourceFunction = "Onyx::Init(ErrorHandler& errorHandler)",
			.message = "Failed to initialize FreeType.",
			.howToFix = "Ensure the FreeType library is downloaded for your specific platform. If you are not running Windows x64, you will need to download FreeType for yourself, you can't just use the one from the Onyx download.",
			}
		);
		return;
	}

	if (!glfwInit())
	{
		onyx_err(Error{
			   .sourceFunction = "Onyx::Init(ErrorHandler& errorHandler)",
			   .message = "Failed to initialize GLFW.",
			   .howToFix = "Ensure the GLFW library is downloaded for your specific platform. If you are not running Windows x64, you will need to download GLFW for yourself, you can't just use the one from the Onyx download.",
			}
		);
		return;
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

bool Onyx::IsAlpha()
{
	return ONYX_ALPHA;
}

bool Onyx::IsBeta()
{
	return ONYX_BETA;
}

bool Onyx::IsReleaseCandidate()
{
	return ONYX_RELEASE_CANDIDATE;
}

bool Onyx::IsStable()
{
	return ONYX_STABLE;
}

std::string Onyx::GetVersionString()
{
	std::string ver = std::to_string(ONYX_VERSION_MAJOR) + "." + std::to_string(ONYX_VERSION_MINOR) + "." + std::to_string(ONYX_VERSION_PATCH);
	if (ONYX_ALPHA) ver += "-alpha";
	else if (ONYX_BETA) ver += "-beta";
	else if (ONYX_RELEASE_CANDIDATE) ver += "-rc";
	if (!ONYX_STABLE) ver += std::to_string(ONYX_PRE_RELEASE_NUM);
	return ver;
}

void Onyx::Terminate()
{
	if (!initialized) return;

	FT_Done_FreeType(ft);
	glfwTerminate();

	for (int i = mallocs.size() - 1; i >= 0; i--)
	{
		if (mallocs[i].second && mallocs[i].first != nullptr) delete[] mallocs[i].first;
		else if (mallocs[i].first != nullptr) delete mallocs[i].first;
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
		Resources("icons/icon-16x.png"),
		Resources("icons/icon-24x.png"),
		Resources("icons/icon-32x.png"),
		Resources("icons/icon-48x.png"),
		Resources("icons/icon-256x.png"),
	});
	
	window.setIcon(icon);
	icon.dispose();

	InputHandler input;
	window.linkInputHandler(input);
	
	float bgVertices[] = {
		0.0f,   110.0f, 0.0f,
		200.0f, 110.0f, 0.0f,
		200.0f, 0.0f,   0.0f,
		0.0f,   0.0f,   0.0f
	};

	uint bgIndices[] = {
		0, 1, 2,
		2, 3, 0
	};

	float logoVertices[] = {
		0.0f,   0.0f,   0.0f,	0.0f, 0.0f,
		75.0f,  0.0f,   0.0f,	1.0f, 0.0f,
		75.0f,  75.0f,  0.0f,	1.0f, 1.0f,
		0.0f,   75.0f,  0.0f,	0.0f, 1.0f
	};

	uint logoIndices[] = {
		0, 1, 2,
		2, 3, 0
	};

	float start = GetTime();
	ModelRenderable car(Model::LoadOBJ(Resources("models/Corvette C8.obj")));
	car.rotate(Vec3(0.0f, -180.0f, 0.0f));
	float duration = round((GetTime() - start) * 100) / 100;

	std::cout << "Model loaded in " << duration << " sec\n";

	UiRenderable textBg(
		Mesh(VertexBuffer(bgVertices, sizeof(bgVertices), Onyx::VertexFormat::P), IndexBuffer(bgIndices, sizeof(bgIndices))),
		Vec4(0.0f, 0.0f, 0.0f, 0.3f)
	);
	textBg.setPosition(Vec2(10.0f, window.getBufferHeight() - 120.0f));

	UiRenderable logo(
		Mesh(VertexBuffer(logoVertices, sizeof(logoVertices), Onyx::VertexFormat::PT), IndexBuffer(logoIndices, sizeof(logoIndices))),
		Texture::Load(Resources("textures/onyx.png"))
	);
	logo.setPosition(Vec2(window.getBufferWidth() - 90.0f, window.getBufferHeight() - 90.0f));

	Camera cam(Projection::Perspective(60.0f, 1280, 720));
	window.linkCamera(cam);
	cam.translateFB(-6.0f);
	cam.translateUD(2.0f);

	Lighting lighting(Vec3(1.0f, 1.0f, 1.0f), 0.3f, Vec3(-0.2f, -1.0f, -0.3f));

	Renderer renderer(cam, lighting);
	window.linkRenderer(renderer);
	renderer.add(car);
	renderer.add(textBg);
	renderer.add(logo);

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

	for (TextRenderable& tr : textRenderables) renderer.add(tr);

	const double MOVE_SPEED = 6.0;
	const double MOUSE_SENS = 30.0;
	const double CONTROLLER_SENS = 30.0f;

	const float DEAD_ZONE_LEFT = 0.1f;
	const float DEAD_ZONE_RIGHT = 0.1f;

	input.setCursorLock(true);

	input.setKeyCooldown(Onyx::Key::F12, 1.0f);
	input.setKeyCooldown(Onyx::Key::Num1, 0.5f);
	input.setKeyCooldown(Onyx::Key::Num2, 0.5f);
	input.setKeyCooldown(Onyx::Key::Num3, 0.5f);
	input.setMouseButtonCooldown(Onyx::MouseButton::Left, 0.5f);

	int fps = 0;

	bool lookAtOrigin = false;

	while (window.isOpen())
	{
		input.update();
		double dx = input.getMouseDeltas().getX();
		double dy = input.getMouseDeltas().getY();
		float lsx = 0.0f, lsy = 0.0f, rsx = 0.0f, rsy = 0.0f;
		bool a = false, b = false, x = false, y = false, rs = false;
		double dt = window.getDeltaTime();

		if (window.getFrame() % 100 == 0 || window.getFrame() == 2) fps = window.getFPS();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(MOVE_SPEED * dt);
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-MOVE_SPEED * dt);
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-MOVE_SPEED * dt);
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(MOVE_SPEED * dt);
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(MOVE_SPEED * dt);
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-MOVE_SPEED * dt);
		if (input.isKeyDown(Onyx::Key::F12)) window.toggleFullscreen(1280, 720, Math::IVec2(100, 100));
		if (input.isKeyDown(Onyx::Key::Num1)) Renderer::ToggleWireframe();
		if (input.isKeyDown(Onyx::Key::Num2)) car.toggleVisibility();
		if (input.isKeyDown(Onyx::Key::Num3)) renderer.toggleLightingEnabled();

		car.rotate(Vec3(0.0f, 10.0f * dt, 0.0f));

		cam.rotate(MOUSE_SENS * .005 * dx, MOUSE_SENS * .005 * dy);
		cam.setFOV(cam.getProjection().getFOV() - input.getScrollDeltas().getY());

		for (const Gamepad& gp : input.getGamepads())
		{
			if (abs(gp.getAxis(GamepadAxis::LeftX)) > lsx) lsx = gp.getAxis(GamepadAxis::LeftX);
			if (abs(gp.getAxis(GamepadAxis::LeftY)) > lsy) lsy = gp.getAxis(GamepadAxis::LeftY);
			if (abs(gp.getAxis(GamepadAxis::RightX)) > rsx) rsx = gp.getAxis(GamepadAxis::RightX);
			if (abs(gp.getAxis(GamepadAxis::RightY)) > rsy) rsy = gp.getAxis(GamepadAxis::RightY);
			if (gp.isButtonPressed(GamepadButton::A)) a = true;
			if (gp.isButtonPressed(GamepadButton::B)) b = true;
			if (gp.isButtonPressed(GamepadButton::X)) x = true;
			if (gp.isButtonPressed(GamepadButton::Y)) y = true;
			if (gp.isButtonPressed(GamepadButton::RightStick)) rs = true;
		}

		lsx = abs(lsx) < DEAD_ZONE_LEFT ? 0.0f : lsx;
		lsy = abs(lsy) < DEAD_ZONE_LEFT ? 0.0f : lsy;
		rsx = abs(rsx) < DEAD_ZONE_RIGHT ? 0.0f : rsx;
		rsy = abs(rsy) < DEAD_ZONE_RIGHT ? 0.0f : rsy;

		cam.translateFB(MOVE_SPEED * dt * lsy);
		cam.translateLR(MOVE_SPEED * dt * lsx);
		if (a) cam.translateUD(MOVE_SPEED * dt);
		if (b || rs) cam.translateUD(-MOVE_SPEED * dt);

		cam.rotate(MOUSE_SENS * 10.0f * dt * rsx, MOUSE_SENS * 10.0f * dt * rsy);

		cam.update();

		textRenderables[1].setText("FPS: " + std::to_string(fps));
		textRenderables[2].setText("FRAME " + std::to_string(window.getFrame()));

		textRenderables[0].setPosition(Vec2(23.0f, window.getBufferHeight() - 50.0f));
		textRenderables[1].setPosition(Vec2(25.0f, window.getBufferHeight() - 80.0f));
		textRenderables[2].setPosition(Vec2(25.0f, window.getBufferHeight() - 100.0f));
		textBg.setPosition(Vec2(10.0f, window.getBufferHeight() - 120.0f));
		logo.setPosition(Vec2(window.getBufferWidth() - 90.0f, window.getBufferHeight() - 90.0f));
		
		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	robotoReg.dispose();
	robotoBold.dispose();
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

std::string Onyx::GetGraphicsName(bool* result)
{
	if (!glInitialized)
	{
		onyx_err(Error{
				.sourceFunction = "Onyx::GetGraphics()",
				.message = "OpenGL is not initialized, name unavailable.",
				.howToFix = "Initialze OpenGL by initializing a window before this function is called."
			}
		);
		if (result != nullptr) *result = false;
		return "";
	}
	if (result != nullptr) *result = true;
	return std::string((const char*)glGetString(GL_RENDERER));

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}
