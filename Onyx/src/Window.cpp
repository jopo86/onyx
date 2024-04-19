#pragma warning(disable: 4244)

#include "Window.h"

using Onyx::Math::Vec3;

GLFWmonitor* Onyx::Window::p_primaryMonitor = nullptr;
GLFWvidmode* Onyx::Window::p_primaryMonitorInfo = nullptr;

void setOpenGLInitialized(bool);

Onyx::Window::Window()
{
	p_glfwWin = nullptr;
	bufferWidth = bufferHeight = 0;
	p_inputHandler = nullptr;
	p_cam = nullptr;
	p_renderer = nullptr;
	initialized = false;
	frame = fps = 0;
	lastFrameTime = deltaTime = 0;
}

Onyx::Window::Window(WindowProperties properties)
{
	p_glfwWin = nullptr;
	this->properties = properties;
	bufferWidth = bufferHeight = 0;
	p_inputHandler = nullptr;
	p_cam = nullptr;
	p_renderer = nullptr;
	initialized = false;
	frame = fps = 0;
	lastFrameTime = deltaTime = 0;
}

void Onyx::Window::init()
{
	glfwWindowHint(GLFW_RESIZABLE, properties.resizable);
	glfwWindowHint(GLFW_VISIBLE, properties.visible);
	glfwWindowHint(GLFW_FOCUSED, properties.focused);
	glfwWindowHint(GLFW_DECORATED, properties.decorated);
	glfwWindowHint(GLFW_FLOATING, properties.topmost);
	glfwWindowHint(GLFW_FOCUS_ON_SHOW, properties.focusOnShow);
	glfwWindowHint(GLFW_SAMPLES, properties.nSamplesMSAA);

	if (p_primaryMonitor == nullptr) p_primaryMonitor = glfwGetPrimaryMonitor();
	if (p_primaryMonitorInfo == nullptr) p_primaryMonitorInfo = (GLFWvidmode*)glfwGetVideoMode(p_primaryMonitor);

	p_glfwWin = glfwCreateWindow(properties.width, properties.height, properties.title.c_str(), nullptr, nullptr);
	if (p_glfwWin == nullptr)
	{
		Err("failed to create GLFW window.");
		return;
	}

	glfwMakeContextCurrent(p_glfwWin);
	glfwGetFramebufferSize(p_glfwWin, &bufferWidth, &bufferHeight);
	glfwSetWindowUserPointer(p_glfwWin, this);

	glfwSetFramebufferSizeCallback(p_glfwWin, CB_framebufferSize);
	glfwSetWindowSizeCallback(p_glfwWin, CB_windowSize);
	glfwSetKeyCallback(p_glfwWin, CB_key);
	glfwSetMouseButtonCallback(p_glfwWin, CB_mouseButton);
	glfwSetCursorPosCallback(p_glfwWin, CB_cursorPos);

	glfwSwapInterval(1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		Err("failed to initialize OpenGL.");
		return;
	}

	setOpenGLInitialized(true);

	glViewport(0, 0, bufferWidth, bufferHeight);
	glEnable(GL_DEPTH_TEST);
	if (properties.nSamplesMSAA) glEnable(GL_MULTISAMPLE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	if (properties.fullscreen) setFullscreen();

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
	properties.fullscreen = true;
	glfwSetWindowMonitor(p_glfwWin, glfwGetPrimaryMonitor(), 0, 0, p_primaryMonitorInfo->width, p_primaryMonitorInfo->height, p_primaryMonitorInfo->refreshRate);
	glfwSwapInterval(1);
}

void Onyx::Window::setWindowed()
{
	properties.fullscreen = false;
	glfwSetWindowMonitor(p_glfwWin, nullptr, 0, 0, properties.width, properties.height, 0);
	glfwSwapInterval(1);
}

void Onyx::Window::toggleFullscreen()
{
	if (properties.fullscreen) setWindowed();
	else setFullscreen();
}

void Onyx::Window::hide()
{
	properties.visible = false;
	glfwHideWindow(p_glfwWin);
}

void Onyx::Window::show()
{
	properties.visible = true;
	glfwShowWindow(p_glfwWin);
}

void Onyx::Window::toggleVisibility()
{
	if (properties.visible) hide();
	else show();
}

void Onyx::Window::focus()
{
	properties.focused = true;
	glfwFocusWindow(p_glfwWin);
}

void Onyx::Window::unfocus()
{
    properties.focused = false;
    glfwFocusWindow(nullptr);
}

void Onyx::Window::toggleFocus()
{
    if (properties.focused) unfocus();
    else focus();
}

void Onyx::Window::setResizable(bool resizable)
{
	properties.resizable = resizable;
	glfwSetWindowAttrib(p_glfwWin, GLFW_RESIZABLE, resizable);
}

void Onyx::Window::toggleResizable()
{
	setResizable(!properties.resizable);
}

void Onyx::Window::setDecorated(bool decorated)
{
	properties.decorated = decorated;
	glfwSetWindowAttrib(p_glfwWin, GLFW_DECORATED, decorated);
}

void Onyx::Window::toggleDecorated()
{
	setDecorated(!properties.decorated);
}

void Onyx::Window::setTopmost(bool topmost)
{
	properties.topmost = topmost;
	glfwSetWindowAttrib(p_glfwWin, GLFW_FLOATING, topmost);
}

void Onyx::Window::toggleTopmost()
{
	setTopmost(!properties.topmost);
}

void Onyx::Window::setFocusOnShow(bool focusOnShow)
{
	properties.focusOnShow = focusOnShow;
	glfwSetWindowAttrib(p_glfwWin, GLFW_FOCUS_ON_SHOW, focusOnShow);
}

void Onyx::Window::toggleFocusOnShow()
{
	setFocusOnShow(!properties.focusOnShow);
}

void Onyx::Window::maximize()
{
	glfwMaximizeWindow(p_glfwWin);
}

void Onyx::Window::minimize()
{
	properties.fullscreen = false;
	glfwIconifyWindow(p_glfwWin);
}

void Onyx::Window::restore()
{
	glfwRestoreWindow(p_glfwWin);
}

const std::string& Onyx::Window::getTitle() const
{
	return properties.title;
}

int Onyx::Window::getWidth() const
{
    return properties.width;
}

int Onyx::Window::getHeight() const
{
    return properties.height;
}

int Onyx::Window::getBufferWidth() const
{
	return bufferWidth;
}

int Onyx::Window::getBufferHeight() const
{
	return bufferHeight;
}

bool Onyx::Window::isResizable() const
{
    return properties.resizable;
}

bool Onyx::Window::isVisible() const
{
    return properties.visible;
}

bool Onyx::Window::isHidden() const
{
    return !properties.visible;
}

bool Onyx::Window::isDecorated() const
{
    return properties.decorated;
}

bool Onyx::Window::isTopmost() const
{
    return properties.topmost;
}

bool Onyx::Window::isFocused() const
{
    return properties.focused;
}

bool Onyx::Window::focusesOnShow() const
{
    return properties.focusOnShow;
}

int Onyx::Window::getNSamplesMSAA() const
{
    return properties.nSamplesMSAA;
}

bool Onyx::Window::isFullscreen() const
{
    return properties.fullscreen;
}

bool Onyx::Window::isMaximized() const
{
    return glfwGetWindowAttrib(p_glfwWin, GLFW_MAXIMIZED);
}

bool Onyx::Window::isMinimized() const
{
    return glfwGetWindowAttrib(p_glfwWin, GLFW_ICONIFIED);
}

void Onyx::Window::setTitle(const std::string& title)
{
    properties.title = title;
    glfwSetWindowTitle(p_glfwWin, title.c_str());
}

void Onyx::Window::setSize(int width, int height)
{
    properties.width = width;
    properties.height = height;
    glfwSetWindowSize(p_glfwWin, width, height);
}

int Onyx::Window::getFrame() const
{
	return frame;
}

bool Onyx::Window::isInitialized() const
{
	return initialized;
}

int Onyx::Window::getFPS() const
{
	return fps;
}

double Onyx::Window::getDeltaTime() const
{
	return deltaTime;
}

bool Onyx::Window::isOpen() const
{
	return !glfwWindowShouldClose(p_glfwWin);
}

void Onyx::Window::setBackgroundColor(Vec3 rgb)
{
	background = rgb;
}

GLFWwindow* Onyx::Window::getGlfwWindowPtr() const
{
	return p_glfwWin;
}

void Onyx::Window::dispose()
{
	if (initialized)
	{
		glfwDestroyWindow(p_glfwWin);
	}

	p_glfwWin = nullptr;
	bufferWidth = bufferHeight = 0;
	initialized = false;
}

void Onyx::Window::CB_framebufferSize(GLFWwindow* p_glfwWin, int width, int height)
{
	glViewport(0, 0, width, height);

	Window* p_win = (Window*)glfwGetWindowUserPointer(p_glfwWin);
	p_win->bufferWidth = width;
	p_win->bufferHeight = height;
	Camera* p_cam = p_win->p_cam;
	Renderer* p_renderer = p_win->p_renderer;

	if (p_cam != nullptr)
	{
		if (p_cam->getProjection().getType() != Onyx::ProjectionType::Perspective) return;
		Projection proj = p_cam->getProjection();
		p_cam->setProjection(Projection::Perspective(proj.getFOV(), width, height, proj.getNearPlane(), proj.getFarPlane()));
	}

	if (p_renderer != nullptr)
	{
		p_renderer->ortho = Projection::Orthographic(0.0f, width, height, 0.0f).getMatrix();
	}
}

void Onyx::Window::CB_windowSize(GLFWwindow* p_glfwWin, int width, int height)
{
	Window* p_win = (Window*)glfwGetWindowUserPointer(p_glfwWin);
	p_win->properties.width = width;
	p_win->properties.height = height;
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
