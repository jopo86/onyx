#pragma warning(disable: 4244; disable: 4267)

#include "Window.h"

#include <fstream>

#include <stbi/stb_image.h>

using Onyx::Math::Vec3;

GLFWmonitor* Onyx::Window::m_pPrimaryMonitor = nullptr;
GLFWvidmode* Onyx::Window::m_pPrimaryMonitorInfo = nullptr;

void onyx_set_gl_init(bool);
void onyx_err(const Onyx::Error&);

Onyx::WindowIcon::WindowIcon() 
{
	images = nullptr;
	nImages = 0;
}

Onyx::WindowIcon Onyx::WindowIcon::Load(const std::initializer_list<std::string>& filepaths, bool* result)
{
	for (const std::string& filepath : filepaths)
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
			if (result != nullptr) *result = false;
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
		if (icon.images[i].pixels == nullptr)
		{
			onyx_err(Error{
					.sourceFunction = "Onyx::WindowIcon::Load(const std::initializer_list<std::string>& filepaths)",
					.message = "All files found, but failed to load image data from one or more files",
					.howToFix = "Ensure the files ares valid image files. Supported formats: .jpg/.jpeg, .png, .tga, .bmp, .psd, .gif, .hdr, .pic, .pnm"
				}
			);
			icon.dispose();
			if (result != nullptr) *result = false;
			return WindowIcon();
		}
	}

	if (result != nullptr) *result = true;
	return icon;
}

void Onyx::WindowIcon::dispose()
{
	for (uint i = 0; i < nImages; i++) stbi_image_free(images[i].pixels);
	delete[] images;
}

Onyx::Window::Window()
{
	m_pGlfwWin = nullptr;
	m_bufferWidth = m_bufferHeight = 0;
	m_pInputHandler = nullptr;
	m_pCam = nullptr;
	m_pRenderer = nullptr;
	m_initialized = false;
	m_frame = m_fps = 0;
	m_lastFrameTime = m_deltaTime = 0;
}

Onyx::Window::Window(WindowProperties properties)
{
	m_pGlfwWin = nullptr;
	m_properties = properties;
	m_bufferWidth = m_bufferHeight = 0;
	m_pInputHandler = nullptr;
	m_pCam = nullptr;
	m_pRenderer = nullptr;
	m_initialized = false;
	m_frame = m_fps = 0;
	m_lastFrameTime = m_deltaTime = 0;
}

void Onyx::Window::init(bool* result)
{
	glfwWindowHint(GLFW_RESIZABLE, m_properties.resizable);
	glfwWindowHint(GLFW_VISIBLE, m_properties.visible);
	glfwWindowHint(GLFW_FOCUSED, m_properties.focused);
	glfwWindowHint(GLFW_DECORATED, m_properties.decorated);
	glfwWindowHint(GLFW_FLOATING, m_properties.topmost);
	glfwWindowHint(GLFW_FOCUS_ON_SHOW, m_properties.focusOnShow);
	glfwWindowHint(GLFW_SAMPLES, m_properties.nSamplesMSAA);

	if (m_pPrimaryMonitor == nullptr) m_pPrimaryMonitor = glfwGetPrimaryMonitor();
	if (m_pPrimaryMonitorInfo == nullptr) m_pPrimaryMonitorInfo = (GLFWvidmode*)glfwGetVideoMode(m_pPrimaryMonitor);

	m_pGlfwWin = glfwCreateWindow(m_properties.width, m_properties.height, m_properties.title.c_str(), nullptr, nullptr);
	if (m_pGlfwWin == nullptr)
	{
		onyx_err(Error{
				.sourceFunction = "Onyx::Window::init()",
                .message = "Failed to create GLFW window.",
                .howToFix = "Ensure the window is not already initialized, and that the GLFW library is downloaded for your specific platform. If you are not running Windows x64, you will need to download GLFW for yourself, you can't just use the one from the Onyx download."
			}
		);
		if (result != nullptr) *result = false;
		return;
	}

	glfwMakeContextCurrent(m_pGlfwWin);
	glfwGetFramebufferSize(m_pGlfwWin, &m_bufferWidth, &m_bufferHeight);
	glfwSetWindowUserPointer(m_pGlfwWin, this);

	glfwSetFramebufferSizeCallback(m_pGlfwWin, framebufferSizeCallback);
	glfwSetWindowSizeCallback(m_pGlfwWin, windowSizeCallback);
	glfwSetWindowPosCallback(m_pGlfwWin, windowPosCallback);
	glfwSetKeyCallback(m_pGlfwWin, keyCallback);
	glfwSetMouseButtonCallback(m_pGlfwWin, mouseButtonCallback);
	glfwSetCursorPosCallback(m_pGlfwWin, cursorPosCallback);
	glfwSetScrollCallback(m_pGlfwWin, scrollCallback);

	glfwSwapInterval(1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		onyx_err(Error{
                .sourceFunction = "Onyx::Window::init()",
                .message = "Failed to initialize OpenGL.",
                .howToFix = "Ensure that the window is not already initialized, and that the glad library is downloaded for your specific platofrm. If you are not running Windows x64, you will need to download glad for yourself, you can't just use the one from the Onyx download."
            }
        );
		if (result != nullptr) *result = false;
		return;
	}

	onyx_set_gl_init(true);

	glfwSetWindowOpacity(m_pGlfwWin, m_properties.opacity);
	if (m_properties.fullscreen) fullscreen();

	glViewport(0, 0, m_bufferWidth, m_bufferHeight);
	glEnable(GL_DEPTH_TEST);
	if (m_properties.nSamplesMSAA) glEnable(GL_MULTISAMPLE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	m_initialized = true;
	if (result != nullptr) *result = true;
}

void Onyx::Window::startRender()
{
	m_deltaTime = GetTime() - m_lastFrameTime;
	m_fps = (int)(1.0 / m_deltaTime);
	m_lastFrameTime = GetTime();
	m_frame++;

	glClearColor(m_properties.backgroundColor.getX(), m_properties.backgroundColor.getY(), m_properties.backgroundColor.getZ(), 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glfwPollEvents();
}

void Onyx::Window::endRender()
{
	glfwSwapBuffers(m_pGlfwWin);
}

void Onyx::Window::close()
{
	glfwSetWindowShouldClose(m_pGlfwWin, GLFW_TRUE);
	m_initialized = false;
}

void Onyx::Window::maximize()
{
	m_properties.fullscreen = true;
	glfwSetWindowMonitor(m_pGlfwWin, glfwGetPrimaryMonitor(), 0, 0, m_pPrimaryMonitorInfo->width, m_pPrimaryMonitorInfo->height, m_pPrimaryMonitorInfo->refreshRate);
	glfwSwapInterval(1);
}

void Onyx::Window::minimize()
{
	m_properties.fullscreen = false;
	glfwIconifyWindow(m_pGlfwWin);
}

void Onyx::Window::restore()
{
	glfwRestoreWindow(m_pGlfwWin);
}

void Onyx::Window::requestAttention()
{
	glfwRequestWindowAttention(m_pGlfwWin);
}

bool Onyx::Window::isOpen() const
{
	return !glfwWindowShouldClose(m_pGlfwWin);
}

const std::string& Onyx::Window::getTitle() const
{
	return m_properties.title;
}

int Onyx::Window::getWidth() const
{
	return m_properties.width;
}

int Onyx::Window::getHeight() const
{
	return m_properties.height;
}

int Onyx::Window::getBufferWidth() const
{
	return m_bufferWidth;
}

int Onyx::Window::getBufferHeight() const
{
	return m_bufferHeight;
}

const Onyx::Math::IVec2& Onyx::Window::getPosition() const
{
	return m_properties.position;
}

int Onyx::Window::getFrame() const
{
	return m_frame;
}

int Onyx::Window::getFPS() const
{
	return m_fps;
}

double Onyx::Window::getDeltaTime() const
{
	return m_deltaTime;
}

float Onyx::Window::getOpacity() const
{
	return m_properties.opacity;
}

const Vec3& Onyx::Window::getBackgroundColor() const
{
	return m_properties.backgroundColor;
}

const Onyx::WindowIcon& Onyx::Window::getIcon() const
{
	return m_icon;
}

GLFWwindow* Onyx::Window::getGlfwWindowPtr() const
{
	return m_pGlfwWin;
}

bool Onyx::Window::isInitialized() const
{
	return m_initialized;
}

bool Onyx::Window::isResizable() const
{
	return m_properties.resizable;
}

bool Onyx::Window::isVisible() const
{
	return m_properties.visible;
}

bool Onyx::Window::isHidden() const
{
	return !m_properties.visible;
}

bool Onyx::Window::isFocused() const
{
	return m_properties.focused;
}

bool Onyx::Window::isDecorated() const
{
	return m_properties.decorated;
}

bool Onyx::Window::isTopmost() const
{
	return m_properties.topmost;
}

bool Onyx::Window::focusesOnShow() const
{
	return m_properties.focusOnShow;
}

int Onyx::Window::getNSamplesMSAA() const
{
	return m_properties.nSamplesMSAA;
}

bool Onyx::Window::isFullscreen() const
{
	return m_properties.fullscreen;
}

bool Onyx::Window::isMaximized() const
{
	return glfwGetWindowAttrib(m_pGlfwWin, GLFW_MAXIMIZED);
}

bool Onyx::Window::isMinimized() const
{
	return glfwGetWindowAttrib(m_pGlfwWin, GLFW_ICONIFIED);
}

void Onyx::Window::setTitle(const std::string& title)
{
	m_properties.title = title;
	glfwSetWindowTitle(m_pGlfwWin, title.c_str());
}

void Onyx::Window::setSize(int width, int height)
{
	m_properties.width = width;
	m_properties.height = height;
	glfwSetWindowSize(m_pGlfwWin, width, height);
}

void Onyx::Window::setPosition(const Math::IVec2& position)
{
	m_properties.position = position;
	glfwSetWindowPos(m_pGlfwWin, position.getX(), position.getY());
}

void Onyx::Window::setBackgroundColor(Onyx::Math::Vec3 rgb)
{
	m_properties.backgroundColor = rgb;
}

void Onyx::Window::setIcon(const WindowIcon& icon)
{
	m_icon = icon;
	glfwSetWindowIcon(m_pGlfwWin, icon.nImages, icon.images);
}

void Onyx::Window::setOpacity(float opacity)
{
	m_properties.opacity = opacity;
	glfwSetWindowOpacity(m_pGlfwWin, opacity);
}

void Onyx::Window::fullscreen()
{
	m_properties.fullscreen = true;
	glfwSetWindowMonitor(m_pGlfwWin, glfwGetPrimaryMonitor(), 0, 0, m_pPrimaryMonitorInfo->width, m_pPrimaryMonitorInfo->height, m_pPrimaryMonitorInfo->refreshRate);
	glfwSwapInterval(1);
}

void Onyx::Window::windowed()
{
	m_properties.fullscreen = false;
	glfwSetWindowMonitor(m_pGlfwWin, nullptr, m_properties.position.getX(), m_properties.position.getY(), m_properties.width, m_properties.height, 0);
	if (m_properties.decorated) setDecorated(true);
	glfwSwapInterval(1);
}

void Onyx::Window::windowed(int width, int height, Math::IVec2 position)
{
	m_properties.fullscreen = false;
	glfwSetWindowMonitor(m_pGlfwWin, nullptr, position.getX(), position.getY(), width, height, 0);
	if (m_properties.decorated) setDecorated(true);
	glfwSwapInterval(1);
}

void Onyx::Window::toggleFullscreen()
{
	if (m_properties.fullscreen)
		windowed();
	else
		fullscreen();
}

void Onyx::Window::toggleFullscreen(int width, int height, Math::IVec2 position)
{
	if (m_properties.fullscreen)
		windowed(width, height, position);
	else
		fullscreen();
}

void Onyx::Window::hide()
{
	m_properties.visible = false;
	glfwHideWindow(m_pGlfwWin);
}

void Onyx::Window::show()
{
	m_properties.visible = true;
	glfwShowWindow(m_pGlfwWin);
}

void Onyx::Window::toggleVisibility()
{
	if (m_properties.visible)
		hide();
	else
		show();
}

void Onyx::Window::focus()
{
	m_properties.focused = true;
	glfwFocusWindow(m_pGlfwWin);
}

void Onyx::Window::unfocus()
{
	m_properties.focused = false;
	glfwFocusWindow(nullptr);
}

void Onyx::Window::toggleFocus()
{
	if (m_properties.focused)
		unfocus();
	else
		focus();
}

void Onyx::Window::setResizable(bool resizable)
{
	m_properties.resizable = resizable;
	glfwSetWindowAttrib(m_pGlfwWin, GLFW_RESIZABLE, resizable);
}

void Onyx::Window::toggleResizable()
{
	setResizable(!m_properties.resizable);
}

void Onyx::Window::setDecorated(bool decorated)
{
	m_properties.decorated = decorated;
	glfwSetWindowAttrib(m_pGlfwWin, GLFW_DECORATED, decorated);
}

void Onyx::Window::toggleDecorated()
{
	setDecorated(!m_properties.decorated);
}

void Onyx::Window::setTopmost(bool topmost)
{
	m_properties.topmost = topmost;
	glfwSetWindowAttrib(m_pGlfwWin, GLFW_FLOATING, topmost);
}

void Onyx::Window::toggleTopmost()
{
	setTopmost(!m_properties.topmost);
}

void Onyx::Window::setFocusOnShow(bool focusOnShow)
{
	m_properties.focusOnShow = focusOnShow;
	glfwSetWindowAttrib(m_pGlfwWin, GLFW_FOCUS_ON_SHOW, focusOnShow);
}

void Onyx::Window::toggleFocusOnShow()
{
	setFocusOnShow(!m_properties.focusOnShow);
}

void Onyx::Window::dispose()
{
	if (m_initialized)
	{
		glfwDestroyWindow(m_pGlfwWin);
	}

	m_pGlfwWin = nullptr;
	m_bufferWidth = m_bufferHeight = 0;
	m_initialized = false;
}


void Onyx::Window::framebufferSizeCallback(GLFWwindow* p_glfwWin, int width, int height)
{
	glViewport(0, 0, width, height);

	Window* p_win = (Window*)glfwGetWindowUserPointer(p_glfwWin);
	p_win->m_bufferWidth = width;
	p_win->m_bufferHeight = height;
	Camera* m_pCam = p_win->m_pCam;
	Renderer* m_pRenderer = p_win->m_pRenderer;

	if (m_pCam != nullptr)
	{
		if (m_pCam->getProjection().getType() != Onyx::ProjectionType::Perspective) return;
		Projection proj = m_pCam->getProjection();
		m_pCam->setProjection(Projection::Perspective(proj.getFOV(), width, height, proj.getNearPlane(), proj.getFarPlane()));
	}

	if (m_pRenderer != nullptr)
	{
		m_pRenderer->m_ortho = Projection::Orthographic(0.0f, width, height, 0.0f).getMatrix();
	}

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Window::windowSizeCallback(GLFWwindow* p_glfwWin, int width, int height)
{
	Window* p_win = (Window*)glfwGetWindowUserPointer(p_glfwWin);
	p_win->m_properties.width = width;
	p_win->m_properties.height = height;
}

void Onyx::Window::windowPosCallback(GLFWwindow* p_glfwWin, int x, int y)
{
	Window* p_win = (Window*)glfwGetWindowUserPointer(p_glfwWin);
	p_win->m_properties.position = Math::IVec2(x, y);
}

void Onyx::Window::keyCallback(GLFWwindow *p_glfwWin, int key, int scancode, int action, int mods)
{
	InputHandler *p_input = ((Window*)glfwGetWindowUserPointer(p_glfwWin))->m_pInputHandler;
	if (p_input != nullptr) p_input->keyCallback(key, scancode, action, mods);
}

void Onyx::Window::mouseButtonCallback(GLFWwindow *p_glfwWin, int button, int action, int mods)
{
	InputHandler *p_input = ((Window*)glfwGetWindowUserPointer(p_glfwWin))->m_pInputHandler;
	if (p_input != nullptr) p_input->mouseButtonCallback(button, action, mods);
}

void Onyx::Window::cursorPosCallback(GLFWwindow *p_glfwWin, double x, double y)
{
	InputHandler *p_input = ((Window*)glfwGetWindowUserPointer(p_glfwWin))->m_pInputHandler;
	if (p_input != nullptr) p_input->cursorPosCallback(x, ((Window*)glfwGetWindowUserPointer(p_glfwWin))->m_properties.height - y);
}

void Onyx::Window::scrollCallback(GLFWwindow *p_glfwWin, double dx, double dy)
{
    InputHandler *p_input = ((Window*)glfwGetWindowUserPointer(p_glfwWin))->m_pInputHandler;
    if (p_input != nullptr) p_input->scrollCallback(dx, dy);
}
