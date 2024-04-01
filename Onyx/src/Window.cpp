#pragma warning(disable: 4244)

#include "Window.h"

using Onyx::Math::Vec3;

GLFWmonitor* Onyx::Window::p_primaryMonitor = nullptr;
GLFWvidmode* Onyx::Window::p_primaryMonitorInfo = nullptr;

Onyx::Window::Window()
{
	p_glfwWin = nullptr;
	title = "Onyx Window";
	width = 800;
	height = 600;
	bufferWidth = bufferHeight = 0;
	p_inputHandler = nullptr;
	p_cam = nullptr;
	p_textRenderer = nullptr;
	fullscreen = false;
	initialized = false;
	frame = fps = 0;
	lastFrameTime = deltaTime = 0;
}

Onyx::Window::Window(const char *title, int width, int height)
{
	p_glfwWin = nullptr;
	this->title = title;
	this->width = width;
	this->height = height;
	bufferWidth = bufferHeight = 0;
	p_inputHandler = nullptr;
	p_cam = nullptr;
	p_textRenderer = nullptr;
	fullscreen = false;
	initialized = false;
	frame = fps = 0;
	lastFrameTime = deltaTime = 0;
}

void Onyx::Window::init()
{
	if (!glfwInit())
	{
		Err("failed to initialize GLFW.");
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef ONYX_OS_MAC
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

	if (p_primaryMonitor == nullptr) p_primaryMonitor = glfwGetPrimaryMonitor();
	if (p_primaryMonitorInfo == nullptr) p_primaryMonitorInfo = (GLFWvidmode*)glfwGetVideoMode(p_primaryMonitor);

	p_glfwWin = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (p_glfwWin == nullptr)
	{
		Err("failed to create GLFW window.");
		return;
	}

	glfwMakeContextCurrent(p_glfwWin);
	glfwGetFramebufferSize(p_glfwWin, &bufferWidth, &bufferHeight);
	glfwSetWindowUserPointer(p_glfwWin, this);

	glfwSetFramebufferSizeCallback(p_glfwWin, CB_framebufferSize);
	glfwSetKeyCallback(p_glfwWin, CB_key);
	glfwSetMouseButtonCallback(p_glfwWin, CB_mouseButton);
	glfwSetCursorPosCallback(p_glfwWin, CB_cursorPos);

	glfwSwapInterval(1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		Err("failed to initialize OpenGL.");
		return;
	}

	glViewport(0, 0, bufferWidth, bufferHeight);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	initialized = true;
}

void Onyx::Window::startRender()
{
	deltaTime = GetTime() - lastFrameTime;
	fps = (int)(1.0 / deltaTime);
	lastFrameTime = GetTime();
	frame++;

	glClearColor(background.getX(), background.getY(), background.getZ(), 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glfwPollEvents();
}

void Onyx::Window::endRender()
{
	glfwSwapBuffers(p_glfwWin);
}

void Onyx::Window::close()
{
	glfwSetWindowShouldClose(p_glfwWin, GLFW_TRUE);
	initialized = false;
}

void Onyx::Window::setFullscreen()
{
	fullscreen = true;
	glfwSetWindowMonitor(p_glfwWin, glfwGetPrimaryMonitor(), 0, 0, p_primaryMonitorInfo->width, p_primaryMonitorInfo->height, p_primaryMonitorInfo->refreshRate);
	glfwSwapInterval(1);
}

void Onyx::Window::setWindowed()
{
	fullscreen = false;
	glfwSetWindowMonitor(p_glfwWin, nullptr, 0, 0, width, height, 0);
	glfwSwapInterval(1);
}

void Onyx::Window::toggleFullscreen()
{
	if (fullscreen) setWindowed();
	else setFullscreen();
}

GLFWwindow *Onyx::Window::getGlfwWindowPtr()
{
	return p_glfwWin;
}

const char *Onyx::Window::getTitle()
{
	return title;
}

int Onyx::Window::getWidth()
{
	return width;
}

int Onyx::Window::getHeight()
{
	return height;
}

int Onyx::Window::getBufferWidth()
{
	return bufferWidth;
}

int Onyx::Window::getBufferHeight()
{
	return bufferHeight;
}

int Onyx::Window::getFrame()
{
	return frame;
}

bool Onyx::Window::isInitialized()
{
	return initialized;
}

int Onyx::Window::getFPS()
{
	return fps;
}

double Onyx::Window::getDeltaTime()
{
	return deltaTime;
}

bool Onyx::Window::isOpen()
{
	return !glfwWindowShouldClose(p_glfwWin);
}

void Onyx::Window::setBackgroundColor(Vec3 rgb)
{
	background = rgb;
}

void Onyx::Window::dispose()
{
	if (initialized)
	{
		glfwDestroyWindow(p_glfwWin);
	}

	p_glfwWin = nullptr;
	title = "";
	width = height = bufferWidth = bufferHeight = 0;
	initialized = false;

	glfwTerminate();
}

void Onyx::Window::CB_framebufferSize(GLFWwindow* p_glfwWin, int width, int height)
{
	glViewport(0, 0, width, height);

	Window* p_win = (Window*)glfwGetWindowUserPointer(p_glfwWin);
	p_win->bufferWidth = width;
	p_win->bufferHeight = height;
	Camera* p_cam = p_win->p_cam;
	TextRenderer* p_textRenderer = p_win->p_textRenderer;

	if (p_cam != nullptr)
	{
		if (p_cam->getProjection().getType() != ONYX_PROJECTION_TYPE_PERSPECTIVE) return;
		Projection proj = p_cam->getProjection();
		p_cam->setProjection(Projection::Perspective(proj.getFOV(), width, height, proj.getNearPlane(), proj.getFarPlane()));
	}

	if (p_textRenderer != nullptr)
	{
		p_textRenderer->shader.use();
		p_textRenderer->shader.uniform("u_projection", Projection::Orthographic(0.0f, width, height, 0.0f).getMatrix());
	}
}

void Onyx::Window::CB_key(GLFWwindow *p_glfwWin, int key, int scancode, int action, int mods)
{
	InputHandler *p_input = ((Window*)glfwGetWindowUserPointer(p_glfwWin))->p_inputHandler;
	if (p_input != nullptr) p_input->RCB_key(key, scancode, action, mods);
}

void Onyx::Window::CB_mouseButton(GLFWwindow *p_glfwWin, int button, int action, int mods)
{
	InputHandler *p_input = ((Window*)glfwGetWindowUserPointer(p_glfwWin))->p_inputHandler;
	if (p_input != nullptr) p_input->RCB_mouseButton(button, action, mods);
}

void Onyx::Window::CB_cursorPos(GLFWwindow *p_glfwWin, double x, double y)
{
	InputHandler *p_input = ((Window*)glfwGetWindowUserPointer(p_glfwWin))->p_inputHandler;
	if (p_input != nullptr) p_input->RCB_cursorPos(x, y);
}
