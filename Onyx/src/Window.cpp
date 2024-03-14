#include "Window.h"

using Onyx::Math::Vec3;

GLFWmonitor* Onyx::Window::p_primaryMonitor = nullptr;
GLFWvidmode* Onyx::Window::p_primaryMonitorInfo = nullptr;

Onyx::Window::Window()
{
	p_window = nullptr;
	title = "Magnesium Window";
	width = 800;
	height = 600;
	bufferWidth = bufferHeight = 0;
	p_inputHandler = nullptr;
	p_cam = nullptr;
	p_textRenderer = nullptr;
	fullscreen = false;
	initialized = false;
}

Onyx::Window::Window(const char *title, int width, int height)
{
	p_window = nullptr;
	this->title = title;
	this->width = width;
	this->height = height;
	bufferWidth = bufferHeight = 0;
	p_inputHandler = nullptr;
	p_cam = nullptr;
	p_textRenderer = nullptr;
	fullscreen = false;
	initialized = false;
}

void Onyx::Window::init()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef ONYX_OS_MAC
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

	if (p_primaryMonitor == nullptr) p_primaryMonitor = glfwGetPrimaryMonitor();
	if (p_primaryMonitorInfo == nullptr) p_primaryMonitorInfo = (GLFWvidmode*)glfwGetVideoMode(p_primaryMonitor);

	p_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	glfwMakeContextCurrent(p_window);
	glfwGetFramebufferSize(p_window, &bufferWidth, &bufferHeight);
	glfwSetWindowUserPointer(p_window, this);

	glfwSetFramebufferSizeCallback(p_window, CB_framebufferSize);
	glfwSetKeyCallback(p_window, CB_key);
	glfwSetMouseButtonCallback(p_window, CB_mouseButton);
	glfwSetCursorPosCallback(p_window, CB_cursorPos);

	glfwSwapInterval(1);

	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glViewport(0, 0, bufferWidth, bufferHeight);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	initialized = true;
}

void Onyx::Window::init(ErrorHandler &errorHandler)
{
	if (!glfwInit())
	{
		errorHandler.err("failed to initialize GLFW.");
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

	p_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (p_window == nullptr)
	{
		errorHandler.err("failed to create GLFW window.");
		return;
	}

	glfwMakeContextCurrent(p_window);
	glfwGetFramebufferSize(p_window, &bufferWidth, &bufferHeight);
	glfwSetWindowUserPointer(p_window, this);

	glfwSetFramebufferSizeCallback(p_window, CB_framebufferSize);
	glfwSetKeyCallback(p_window, CB_key);
	glfwSetMouseButtonCallback(p_window, CB_mouseButton);
	glfwSetCursorPosCallback(p_window, CB_cursorPos);

	glfwSwapInterval(1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		errorHandler.err("failed to initialize OpenGL.");
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
	glClearColor(background.getX(), background.getY(), background.getZ(), 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glfwPollEvents();
}

void Onyx::Window::endRender()
{
	glfwSwapBuffers(p_window);
}

void Onyx::Window::close()
{
	glfwSetWindowShouldClose(p_window, GLFW_TRUE);
	initialized = false;
}

void Onyx::Window::setFullscreen()
{
	fullscreen = true;
	glfwSetWindowMonitor(p_window, glfwGetPrimaryMonitor(), 0, 0, p_primaryMonitorInfo->width, p_primaryMonitorInfo->height, p_primaryMonitorInfo->refreshRate);
	glfwSwapInterval(1);
}

void Onyx::Window::setWindowed()
{
	fullscreen = false;
	glfwSetWindowMonitor(p_window, nullptr, 0, 0, width, height, 0);
	glfwSwapInterval(1);
}

void Onyx::Window::toggleFullscreen()
{
	if (fullscreen) setWindowed();
	else setFullscreen();
}

GLFWwindow *Onyx::Window::getGlfwWindowPtr()
{
	return p_window;
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

bool Onyx::Window::isInitialized()
{
	return initialized;
}

bool Onyx::Window::isOpen()
{
	return !glfwWindowShouldClose(p_window);
}

void Onyx::Window::setBackgroundColor(Vec3 rgb)
{
	background = rgb;
}

void Onyx::Window::setInputHandler(InputHandler& inputHandler)
{
	p_inputHandler = &inputHandler;
	p_inputHandler->p_window = this->p_window;
	glfwGetCursorPos(p_window, &(p_inputHandler->mouseX), &(p_inputHandler->mouseY));
}

void Onyx::Window::setCamera(Camera& cam)
{
	p_cam = &cam;
}

Onyx::InputHandler *Onyx::Window::getInputHandlerPtr()
{
	return p_inputHandler;
}

Onyx::Camera *Onyx::Window::getCameraPtr()
{
	return p_cam;
}

void Onyx::Window::dispose()
{
	if (initialized)
	{
		glfwDestroyWindow(p_window);
	}

	p_window = nullptr;
	title = "";
	width = height = bufferWidth = bufferHeight = 0;
	initialized = false;
}

void Onyx::Window::CB_framebufferSize(GLFWwindow *p_window, int width, int height)
{
	glViewport(0, 0, width, height);

	Window* p_win = (Window*)glfwGetWindowUserPointer(p_window);
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
		p_textRenderer->updateProjection(Projection::Orthographic(0.0f, p_win->bufferWidth, p_win->bufferHeight, 0.0f));
	}
}

void Onyx::Window::CB_key(GLFWwindow *p_window, int key, int scancode, int action, int mods)
{
	InputHandler *p_input = ((Window*)glfwGetWindowUserPointer(p_window))->getInputHandlerPtr();
	if (p_input != nullptr) p_input->RCB_key(key, scancode, action, mods);
}

void Onyx::Window::CB_mouseButton(GLFWwindow *p_window, int button, int action, int mods)
{
	InputHandler *p_input = ((Window*)glfwGetWindowUserPointer(p_window))->getInputHandlerPtr();
	if (p_input != nullptr) p_input->RCB_mouseButton(button, action, mods);
}

void Onyx::Window::CB_cursorPos(GLFWwindow *p_window, double x, double y)
{
	InputHandler *p_input = ((Window*)glfwGetWindowUserPointer(p_window))->getInputHandlerPtr();
	if (p_input != nullptr) p_input->RCB_cursorPos(x, y);
}
