#pragma warning(disable: 4244; disable: 4267)

#include "Window.h"

#include <fstream>

#include <stbi/stb_image.h>

using Onyx::Math::Vec3;

GLFWmonitor* Onyx::Window::p_primaryMonitor = nullptr;
GLFWvidmode* Onyx::Window::p_primaryMonitorInfo = nullptr;

void onyx_set_gl_init(bool);
bool onyx_is_ehandler_nullptr();
void onyx_err(const Onyx::Error&);

Onyx::WindowIcon::WindowIcon() 
{
	images = nullptr;
	nImages = 0;
}

Onyx::WindowIcon Onyx::WindowIcon::Load(const std::initializer_list<std::string>& filepaths)
{
	if (!onyx_is_ehandler_nullptr()) for (const std::string& filepath : filepaths)
	{
		std::ifstream file(filepath);
		if (!file.is_open())
		{
			onyx_err(Error{
					.sourceFunction = "Onyx::WindowIcon::Load(const std::initializer_list<std::string>& filepaths)",
					.message = "File not found (or access denied): \"" + filepath + "\"",
					.howToFix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
				}
			);
			return WindowIcon();
		}
		file.close();
	}

	WindowIcon icon;

	icon.nImages = filepaths.size();
	icon.images = new GLFWimage[icon.nImages];

	for (uint i = 0; i < icon.nImages; i++)
	{
		icon.images[i].pixels = stbi_load(filepaths.begin()[i].c_str(), &icon.images[i].width, &icon.images[i].height, nullptr, 4);
		if (!onyx_is_ehandler_nullptr()) if (icon.images[i].pixels == nullptr)
		{
			onyx_err(Error{
					.sourceFunction = "Onyx::WindowIcon::Load(const std::initializer_list<std::string>& filepaths)",
					.message = "All files found, but failed to load image data from one or more files",
					.howToFix = "Ensure the files ares valid image files. Supported formats: .jpg/.jpeg, .png, .tga, .bmp, .psd, .gif, .hdr, .pic, .pnm"
				}
			);
			return WindowIcon();
		}
	}

	return icon;
}

void Onyx::WindowIcon::dispose()
{
	for (uint i = 0; i < nImages; i++) stbi_image_free(images[i].pixels);
	delete[] images;
}

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
		onyx_err(Error{
				.sourceFunction = "Onyx::Window::init()",
                .message = "Failed to create GLFW window.",
                .howToFix = "Ensure the window is not already initialized, and that the GLFW library is downloaded for your specific platform. If you are not running Windows x64, you will need to download GLFW for yourself, you can't just use the one from the Onyx download."
			}
		);
		return;
	}

	glfwMakeContextCurrent(p_glfwWin);
	glfwGetFramebufferSize(p_glfwWin, &bufferWidth, &bufferHeight);
	glfwSetWindowUserPointer(p_glfwWin, this);

	glfwSetFramebufferSizeCallback(p_glfwWin, cb_framebufferSize);
	glfwSetWindowSizeCallback(p_glfwWin, cb_windowSize);
	glfwSetWindowPosCallback(p_glfwWin, cb_windowPos);
	glfwSetKeyCallback(p_glfwWin, cb_key);
	glfwSetMouseButtonCallback(p_glfwWin, cb_mouseButton);
	glfwSetCursorPosCallback(p_glfwWin, cb_cursorPos);
	glfwSetScrollCallback(p_glfwWin, cb_scroll);

	glfwSwapInterval(1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		onyx_err(Error{
                .sourceFunction = "Onyx::Window::init()",
                .message = "Failed to initialize OpenGL.",
                .howToFix = "Ensure that the window is not already initialized, and that the glad library is downloaded for your specific platofrm. If you are not running Windows x64, you will need to download glad for yourself, you can't just use the one from the Onyx download."
            }
        );
		return;
	}

	onyx_set_gl_init(true);

	glfwSetWindowOpacity(p_glfwWin, properties.opacity);
	if (properties.fullscreen) fullscreen();

	glViewport(0, 0, bufferWidth, bufferHeight);
	glEnable(GL_DEPTH_TEST);
	if (properties.nSamplesMSAA) glEnable(GL_MULTISAMPLE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Onyx::Window::startRender()
{
	deltaTime = GetTime() - lastFrameTime;
	fps = (int)(1.0 / deltaTime);
	lastFrameTime = GetTime();
	frame++;

	glClearColor(properties.backgroundColor.getX(), properties.backgroundColor.getY(), properties.backgroundColor.getZ(), 1.0f);
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

void Onyx::Window::maximize()
{
	properties.fullscreen = true;
	glfwSetWindowMonitor(p_glfwWin, glfwGetPrimaryMonitor(), 0, 0, p_primaryMonitorInfo->width, p_primaryMonitorInfo->height, p_primaryMonitorInfo->refreshRate);
	glfwSwapInterval(1);
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

void Onyx::Window::requestAttention()
{
	glfwRequestWindowAttention(p_glfwWin);
}

bool Onyx::Window::isOpen() const
{
	return !glfwWindowShouldClose(p_glfwWin);
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

const Onyx::Math::IVec2& Onyx::Window::getPosition() const
{
	return properties.position;
}

int Onyx::Window::getFrame() const
{
	return frame;
}

int Onyx::Window::getFPS() const
{
	return fps;
}

double Onyx::Window::getDeltaTime() const
{
	return deltaTime;
}

float Onyx::Window::getOpacity() const
{
	return properties.opacity;
}

const Vec3& Onyx::Window::getBackgroundColor() const
{
	return properties.backgroundColor;
}

const Onyx::WindowIcon& Onyx::Window::getIcon() const
{
	return icon;
}

GLFWwindow* Onyx::Window::getGlfwWindowPtr() const
{
	return p_glfwWin;
}

bool Onyx::Window::isInitialized() const
{
	return initialized;
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

bool Onyx::Window::isFocused() const
{
	return properties.focused;
}

bool Onyx::Window::isDecorated() const
{
	return properties.decorated;
}

bool Onyx::Window::isTopmost() const
{
	return properties.topmost;
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

void Onyx::Window::setPosition(const Math::IVec2& position)
{
	properties.position = position;
	glfwSetWindowPos(p_glfwWin, position.getX(), position.getY());
}

void Onyx::Window::setBackgroundColor(Onyx::Math::Vec3 rgb)
{
	properties.backgroundColor = rgb;
}

void Onyx::Window::setIcon(const WindowIcon& icon)
{
	this->icon = icon;
	glfwSetWindowIcon(p_glfwWin, icon.nImages, icon.images);
}

void Onyx::Window::setOpacity(float opacity)
{
	properties.opacity = opacity;
	glfwSetWindowOpacity(p_glfwWin, opacity);
}

void Onyx::Window::fullscreen()
{
	properties.fullscreen = true;
	glfwSetWindowMonitor(p_glfwWin, glfwGetPrimaryMonitor(), 0, 0, p_primaryMonitorInfo->width, p_primaryMonitorInfo->height, p_primaryMonitorInfo->refreshRate);
	glfwSwapInterval(1);
}

void Onyx::Window::windowed()
{
	properties.fullscreen = false;
	glfwSetWindowMonitor(p_glfwWin, nullptr, properties.position.getX(), properties.position.getY(), properties.width, properties.height, 0);
	if (properties.decorated) setDecorated(true);
	glfwSwapInterval(1);
}

void Onyx::Window::windowed(int width, int height, Math::IVec2 position)
{
	properties.fullscreen = false;
	glfwSetWindowMonitor(p_glfwWin, nullptr, position.getX(), position.getY(), width, height, 0);
	if (properties.decorated) setDecorated(true);
	glfwSwapInterval(1);
}

void Onyx::Window::toggleFullscreen()
{
	if (properties.fullscreen)
		windowed();
	else
		fullscreen();
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
	if (properties.visible)
		hide();
	else
		show();
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
	if (properties.focused)
		unfocus();
	else
		focus();
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


void Onyx::Window::cb_framebufferSize(GLFWwindow* p_glfwWin, int width, int height)
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

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Window::cb_windowSize(GLFWwindow* p_glfwWin, int width, int height)
{
	Window* p_win = (Window*)glfwGetWindowUserPointer(p_glfwWin);
	p_win->properties.width = width;
	p_win->properties.height = height;
}

void Onyx::Window::cb_windowPos(GLFWwindow* p_glfwWin, int x, int y)
{
	Window* p_win = (Window*)glfwGetWindowUserPointer(p_glfwWin);
	p_win->properties.position = Math::IVec2(x, y);
}

void Onyx::Window::cb_key(GLFWwindow *p_glfwWin, int key, int scancode, int action, int mods)
{
	InputHandler *p_input = ((Window*)glfwGetWindowUserPointer(p_glfwWin))->p_inputHandler;
	if (p_input != nullptr) p_input->rcb_key(key, scancode, action, mods);
}

void Onyx::Window::cb_mouseButton(GLFWwindow *p_glfwWin, int button, int action, int mods)
{
	InputHandler *p_input = ((Window*)glfwGetWindowUserPointer(p_glfwWin))->p_inputHandler;
	if (p_input != nullptr) p_input->rcb_mouseButton(button, action, mods);
}

void Onyx::Window::cb_cursorPos(GLFWwindow *p_glfwWin, double x, double y)
{
	InputHandler *p_input = ((Window*)glfwGetWindowUserPointer(p_glfwWin))->p_inputHandler;
	if (p_input != nullptr) p_input->rcb_cursorPos(x, ((Window*)glfwGetWindowUserPointer(p_glfwWin))->properties.height - y);
}

void Onyx::Window::cb_scroll(GLFWwindow *p_glfwWin, double dx, double dy)
{
    InputHandler *p_input = ((Window*)glfwGetWindowUserPointer(p_glfwWin))->p_inputHandler;
    if (p_input != nullptr) p_input->rcb_scroll(dx, dy);
}
