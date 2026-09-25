#include <thread>
#include <cmath>
#include <algorithm>

#include <stb_image.h>

#include <onyx/window.hpp>
#include <onyx/camera.hpp>
#include <onyx/input_handler.hpp>
#include "internal.hpp"

using onyx::math::Vec3;

std::vector<onyx::Window*> onyx::Window::p_windows;
std::mutex onyx::Window::mtx_windows;

namespace
{
	/*
		@brief Applies the vsync setting of the Renderer to the current OpenGL context.
	 */
	void apply_vsync()
	{
		std::pair<bool, int> vsync = onyx::Renderer::get_vsync();
		glfwSwapInterval(vsync.first ? vsync.second : 0);
	}
}

onyx::WindowIcon::WindowIcon()
{
	this->p_images = nullptr;
	this->n_images = 0;
}

onyx::WindowIcon onyx::WindowIcon::load(const std::initializer_list<std::string>& filepaths, bool* result)
{
	WindowIcon icon;

	icon.n_images = (u32)filepaths.size();
	icon.p_images = new GLFWimage[icon.n_images];
	for (u32 i = 0; i < icon.n_images; i++) icon.p_images[i] = GLFWimage{ 0, 0, nullptr };

	stbi_set_flip_vertically_on_load(false);
	for (u32 i = 0; i < icon.n_images; i++)
	{
		const std::string& filepath = filepaths.begin()[i];
		icon.p_images[i].pixels = stbi_load(filepath.c_str(), &icon.p_images[i].width, &icon.p_images[i].height, nullptr, 4);
		if (icon.p_images[i].pixels == nullptr)
		{
			stbi_set_flip_vertically_on_load(true);
			const char* reason = stbi_failure_reason();
			onyx_err(Error{
					.source_function = "onyx::WindowIcon::load(const std::initializer_list<std::string>& filepaths)",
					.message = "Failed to load image data from \"" + filepath + "\" (" + (reason != nullptr ? reason : "unknown reason") + ")",
					.how_to_fix = "Ensure the file exists, is not locked by another process, and is a valid image file. Supported formats: .jpg/.jpeg, .png, .tga, .bmp, .psd, .gif, .hdr, .pic, .pnm"
				}
			);
			icon.dispose();
			if (result != nullptr) *result = false;
			return WindowIcon();
		}
	}
	stbi_set_flip_vertically_on_load(true);

	if (result != nullptr) *result = true;
	return icon;
}

void onyx::WindowIcon::dispose()
{
	if (this->disposed) return;
	if (this->p_images != nullptr)
	{
		for (u32 i = 0; i < this->n_images; i++)
		{
			if (this->p_images[i].pixels != nullptr) stbi_image_free(this->p_images[i].pixels);
		}
		delete[] this->p_images;
	}
	this->p_images = nullptr;
	this->n_images = 0;
	this->disposed = true;
}

onyx::Cursor::Cursor()
{
	this->p_cursor = nullptr;
	this->type = CursorType::Null;
}

onyx::CursorType onyx::Cursor::get_type() const
{
	return this->type;
}

onyx::Cursor onyx::Cursor::standard(CursorType type, bool* result)
{
	if (type == CursorType::Null || type == CursorType::Custom)
	{
		onyx_err(Error{
				.source_function = "onyx::Cursor::standard(CursorType type)",
				.message = "CursorType::Null and CursorType::Custom are not standard cursor shapes.",
				.how_to_fix = "Pass one of the standard shapes, such as CursorType::Arrow or CursorType::Hand. Use Cursor::load() to create a custom cursor from an image."
			}
		);
		if (result != nullptr) *result = false;
		return Cursor();
	}

	GLFWcursor* p_cursor = glfwCreateStandardCursor((int)type);
	if (p_cursor == nullptr)
	{
		onyx_err(Error{
				.source_function = "onyx::Cursor::standard(CursorType type)",
				.message = "Failed to create standard cursor.",
				.how_to_fix = "Ensure onyx::init() has been called, and that the requested shape is supported by the platform and by the GLFW version Onyx was linked against (the resize and not-allowed shapes require GLFW 3.4)."
			}
		);
		if (result != nullptr) *result = false;
		return Cursor();
	}

	Cursor cursor;
	cursor.type = type;
	cursor.p_cursor = p_cursor;

	if (result != nullptr) *result = true;
	return cursor;
}

onyx::Cursor onyx::Cursor::load(const std::string& filepath, math::IVec2 hotspot, bool* result)
{
	GLFWimage image;
	image.pixels = stbi_load(filepath.c_str(), &image.width, &image.height, nullptr, 4);
	if (image.pixels == nullptr)
	{
		const char* reason = stbi_failure_reason();
		onyx_err(Error{
				.source_function = "onyx::Cursor::load(const std::string& filepath)",
				.message = "Failed to load image data from \"" + filepath + "\" (" + (reason != nullptr ? reason : "unknown reason") + ")",
				.how_to_fix = "Ensure the file exists, is not locked by another process, and is a valid image file. Supported formats: .jpg/.jpeg, .png, .tga, .bmp, .psd, .gif, .hdr, .pic, .pnm"
			}
		);
		if (result != nullptr) *result = false;
		return Cursor();
	}

	GLFWcursor* p_cursor = glfwCreateCursor(&image, hotspot.get_x(), hotspot.get_y());
	stbi_image_free(image.pixels);

	if (p_cursor == nullptr)
	{
		onyx_err(Error{
				.source_function = "onyx::Cursor::load(const std::string& filepath)",
				.message = "Image data loaded, but failed to create cursor from it: \"" + filepath + "\"",
				.how_to_fix = "Ensure onyx::init() has been called, and that the hotspot lies within the bounds of the image."
			}
		);
		if (result != nullptr) *result = false;
		return Cursor();
	}

	Cursor cursor;
	cursor.type = CursorType::Custom;
	cursor.p_cursor = p_cursor;

	if (result != nullptr) *result = true;
	return cursor;
}

void onyx::Cursor::dispose()
{
	if (this->disposed) return;
	if (this->p_cursor != nullptr) glfwDestroyCursor(this->p_cursor);
	this->p_cursor = nullptr;
	this->disposed = true;
}

onyx::Window::Window()
{
	this->p_glfw_win = nullptr;
	this->buffer_width = this->buffer_height = 0;
	this->initialized = false;
	this->frame = 0L;
	this->fps = 0;
	this->last_frame_time = this->delta_time = 0;
	this->p_framebuffer_size_callback = nullptr;
	this->p_window_size_callback = nullptr;
	this->p_window_pos_callback = nullptr;
	this->p_file_drop_callback = nullptr;
	this->num_frames_cam_not_updated = this->num_frames_input_not_updated = 0;
	this->warned_cam_not_updated = this->warned_input_not_updated = false;
}

onyx::Window::Window(const WindowProperties& properties)
{
	this->p_glfw_win = nullptr;
	this->properties = properties;
	this->buffer_width = this->buffer_height = 0;
	this->initialized = false;
	this->frame = 0L;
	this->fps = 0;
	this->last_frame_time = this->delta_time = 0;
	this->p_framebuffer_size_callback = nullptr;
	this->p_window_size_callback = nullptr;
	this->p_window_pos_callback = nullptr;
	this->p_file_drop_callback = nullptr;
	this->num_frames_cam_not_updated = this->num_frames_input_not_updated = 0;
	this->warned_cam_not_updated = this->warned_input_not_updated = false;
}

void onyx::Window::init(bool* result)
{
	glfwWindowHint(GLFW_RESIZABLE, this->properties.resizable);
	glfwWindowHint(GLFW_VISIBLE, this->properties.visible);
	glfwWindowHint(GLFW_FOCUSED, this->properties.focused);
	glfwWindowHint(GLFW_DECORATED, this->properties.decorated);
	glfwWindowHint(GLFW_FLOATING, this->properties.topmost);
	glfwWindowHint(GLFW_FOCUS_ON_SHOW, this->properties.focus_on_show);
	glfwWindowHint(GLFW_SAMPLES, this->properties.n_samples_msaa);

	this->p_glfw_win = glfwCreateWindow(this->properties.width, this->properties.height, this->properties.title.c_str(), nullptr, nullptr);
	if (this->p_glfw_win == nullptr)
	{
		onyx_err(Error{
				.source_function = "onyx::Window::init()",
				.message = "Failed to create GLFW window.",
				.how_to_fix = "Ensure onyx::init() succeeded, the window is not already initialized, a display is available, and the system supports OpenGL 4.1."
			}
		);
		if (result != nullptr) *result = false;
		return;
	}

	glfwMakeContextCurrent(this->p_glfw_win);
	glfwGetFramebufferSize(this->p_glfw_win, &this->buffer_width, &this->buffer_height);
	glfwSetWindowUserPointer(this->p_glfw_win, this);

	glfwSetWindowOpacity(this->p_glfw_win, this->properties.opacity);
	glfwSetWindowPos(this->p_glfw_win, this->properties.position.get_x(), this->properties.position.get_y());

	glfwSetFramebufferSizeCallback(this->p_glfw_win, framebuffer_size_callback);
	glfwSetWindowSizeCallback(this->p_glfw_win, window_size_callback);
	glfwSetWindowPosCallback(this->p_glfw_win, window_pos_callback);
	glfwSetKeyCallback(this->p_glfw_win, key_callback);
	glfwSetMouseButtonCallback(this->p_glfw_win, mouse_button_callback);
	glfwSetCursorPosCallback(this->p_glfw_win, cursor_pos_callback);
	glfwSetScrollCallback(this->p_glfw_win, scroll_callback);
	glfwSetJoystickCallback(joystick_callback);
	glfwSetDropCallback(this->p_glfw_win, file_drop_callback);

	apply_vsync();

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		onyx_err(Error{
				.source_function = "onyx::Window::init()",
				.message = "Failed to initialize OpenGL.",
				.how_to_fix = "Ensure the system's graphics drivers support OpenGL 4.1."
			}
		);
		glfwDestroyWindow(this->p_glfw_win);
		this->p_glfw_win = nullptr;
		if (result != nullptr) *result = false;
		return;
	}

	onyx_set_gl_init(true);

	if (this->properties.fullscreen) fullscreen();

	if (glfwRawMouseMotionSupported()) glfwSetInputMode(this->p_glfw_win, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);

	glViewport(0, 0, this->buffer_width, this->buffer_height);
	glEnable(GL_DEPTH_TEST);
	if (this->properties.n_samples_msaa != 0) glEnable(GL_MULTISAMPLE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	this->initialized = true;
	{
		std::lock_guard lock(Window::mtx_windows);
		Window::p_windows.push_back(this);
	}
	if (result != nullptr) *result = true;

	this->cursor.dispose();
	this->cursor = Cursor::standard(CursorType::Arrow);
	set_cursor(this->cursor);
}

void onyx::Window::init(const Window& share, bool* result)
{
	glfwWindowHint(GLFW_RESIZABLE, this->properties.resizable);
	glfwWindowHint(GLFW_VISIBLE, this->properties.visible);
	glfwWindowHint(GLFW_FOCUSED, this->properties.focused);
	glfwWindowHint(GLFW_DECORATED, this->properties.decorated);
	glfwWindowHint(GLFW_FLOATING, this->properties.topmost);
	glfwWindowHint(GLFW_FOCUS_ON_SHOW, this->properties.focus_on_show);
	glfwWindowHint(GLFW_SAMPLES, this->properties.n_samples_msaa);

	this->p_glfw_win = glfwCreateWindow(this->properties.width, this->properties.height, this->properties.title.c_str(), nullptr, share.get_glfw_window_ptr());
	if (this->p_glfw_win == nullptr)
	{
		onyx_err(Error{
				.source_function = "onyx::Window::init(const Window& share)",
				.message = "Failed to create GLFW window.",
				.how_to_fix = "Ensure onyx::init() succeeded, the window is not already initialized, the shared window is initialized, a display is available, and the system supports OpenGL 4.1."
			}
		);
		if (result != nullptr) *result = false;
		return;
	}

	glfwMakeContextCurrent(this->p_glfw_win);
	glfwGetFramebufferSize(this->p_glfw_win, &this->buffer_width, &this->buffer_height);
	glfwSetWindowUserPointer(this->p_glfw_win, this);

	glfwSetWindowOpacity(this->p_glfw_win, this->properties.opacity);
	glfwSetWindowPos(this->p_glfw_win, this->properties.position.get_x(), this->properties.position.get_y());

	glfwSetFramebufferSizeCallback(this->p_glfw_win, framebuffer_size_callback);
	glfwSetWindowSizeCallback(this->p_glfw_win, window_size_callback);
	glfwSetWindowPosCallback(this->p_glfw_win, window_pos_callback);
	glfwSetKeyCallback(this->p_glfw_win, key_callback);
	glfwSetMouseButtonCallback(this->p_glfw_win, mouse_button_callback);
	glfwSetCursorPosCallback(this->p_glfw_win, cursor_pos_callback);
	glfwSetScrollCallback(this->p_glfw_win, scroll_callback);
	glfwSetJoystickCallback(joystick_callback);
	glfwSetDropCallback(this->p_glfw_win, file_drop_callback);

	apply_vsync();

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		onyx_err(Error{
				.source_function = "onyx::Window::init(const Window& share)",
				.message = "Failed to initialize OpenGL.",
				.how_to_fix = "Ensure the system's graphics drivers support OpenGL 4.1."
			}
		);
		glfwDestroyWindow(this->p_glfw_win);
		this->p_glfw_win = nullptr;
		if (result != nullptr) *result = false;
		return;
	}

	onyx_set_gl_init(true);

	if (this->properties.fullscreen) fullscreen();

	if (glfwRawMouseMotionSupported()) glfwSetInputMode(this->p_glfw_win, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);

	glViewport(0, 0, this->buffer_width, this->buffer_height);
	glEnable(GL_DEPTH_TEST);
	if (this->properties.n_samples_msaa != 0) glEnable(GL_MULTISAMPLE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	this->initialized = true;
	{
		std::lock_guard lock(Window::mtx_windows);
		Window::p_windows.push_back(this);
	}
	if (result != nullptr) *result = true;

	this->cursor.dispose();
	this->cursor = Cursor::standard(CursorType::Arrow);
	set_cursor(this->cursor);
}

void onyx::Window::start_render()
{
	this->delta_time = get_time() - this->last_frame_time;

	std::pair<bool, int> fps_limit = Renderer::get_fps_limit();
	if (fps_limit.first && fps_limit.second > 0)
	{
		const double target_frame_time = 1.0 / fps_limit.second;

		// Sleep for most of the remaining frame time, then yield for the last ~2ms,
		// since sleeping alone is not precise enough to hit the target.
		const double remaining = target_frame_time - this->delta_time;
		if (remaining > 0.002) onyx::sleep(remaining - 0.002);

		while ((this->delta_time = get_time() - this->last_frame_time) < target_frame_time)
		{
			std::this_thread::yield();
		}
	}

	this->fps = this->delta_time > 0.0 ? (int)std::round(1.0 / this->delta_time) : 0;
	this->last_frame_time = get_time();
	this->frame++;
	this->num_frames_cam_not_updated++;
	this->num_frames_input_not_updated++;

	glClearColor(this->properties.background_color.get_x(), this->properties.background_color.get_y(), this->properties.background_color.get_z(), 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (this->p_input_handlers.size() == 0) glfwPollEvents();
}

void onyx::Window::end_render()
{
	glfwSwapBuffers(this->p_glfw_win);

	if (!this->warned_cam_not_updated && this->frame > 2 && this->num_frames_cam_not_updated > 2 && this->p_cams.size() > 0)
	{
		this->warned_cam_not_updated = true;
		onyx_warn(onyx::Warning{
				.source_function = "onyx::Window::end_render()",
				.message = "Camera was not updated this frame. This warning is only shown once per window.",
				.how_to_fix = "Be sure to update the camera with Camera::update() every frame for camera transformations to have any effect.",
				.severity = Warning::Severity::Med
			}
		);
	}

	if (!this->warned_input_not_updated && this->frame > 2 && this->num_frames_input_not_updated > 2 && this->p_input_handlers.size() > 0)
	{
		this->warned_input_not_updated = true;
		onyx_warn(onyx::Warning{
				.source_function = "onyx::Window::end_render()",
				.message = "Input handler was not updated this frame. This warning is only shown once per window.",
				.how_to_fix = "Be sure to update the input handler with InputHandler::update() every frame.",
				.severity = Warning::Severity::High
			}
		);
	}
}

void onyx::Window::close()
{
	glfwSetWindowShouldClose(this->p_glfw_win, GLFW_TRUE);
	glfwPollEvents();
}

void onyx::Window::maximize()
{
	glfwMaximizeWindow(this->p_glfw_win);
}

void onyx::Window::minimize()
{
	this->properties.fullscreen = false;
	glfwIconifyWindow(this->p_glfw_win);
}

void onyx::Window::restore()
{
	glfwRestoreWindow(this->p_glfw_win);
}

void onyx::Window::request_attention()
{
	glfwRequestWindowAttention(this->p_glfw_win);
}

bool onyx::Window::is_open() const
{
	return !glfwWindowShouldClose(this->p_glfw_win);
}

const std::string& onyx::Window::get_title() const
{
	return this->properties.title;
}

int onyx::Window::get_width() const
{
	return this->properties.width;
}

int onyx::Window::get_height() const
{
	return this->properties.height;
}

int onyx::Window::get_buffer_width() const
{
	return this->buffer_width;
}

int onyx::Window::get_buffer_height() const
{
	return this->buffer_height;
}

const onyx::math::IVec2& onyx::Window::get_position() const
{
	return this->properties.position;
}

usize onyx::Window::get_frame() const
{
	return this->frame;
}

int onyx::Window::get_fps() const
{
	return this->fps;
}

double onyx::Window::get_delta_time() const
{
	return this->delta_time;
}

float onyx::Window::get_opacity() const
{
	return this->properties.opacity;
}

const Vec3& onyx::Window::get_background_color() const
{
	return this->properties.background_color;
}

const onyx::WindowIcon& onyx::Window::get_icon() const
{
	return this->icon;
}

const onyx::Cursor& onyx::Window::get_cursor() const
{
	return this->cursor;
}

GLFWwindow* onyx::Window::get_glfw_window_ptr() const
{
	return this->p_glfw_win;
}

bool onyx::Window::is_initialized() const
{
	return this->initialized;
}

bool onyx::Window::is_resizable() const
{
	return this->properties.resizable;
}

bool onyx::Window::is_visible() const
{
	if (this->p_glfw_win == nullptr) return this->properties.visible;
	return glfwGetWindowAttrib(this->p_glfw_win, GLFW_VISIBLE) == GLFW_TRUE;
}

bool onyx::Window::is_hidden() const
{
	return !is_visible();
}

bool onyx::Window::is_focused() const
{
	if (this->p_glfw_win == nullptr) return this->properties.focused;
	return glfwGetWindowAttrib(this->p_glfw_win, GLFW_FOCUSED) == GLFW_TRUE;
}

bool onyx::Window::is_decorated() const
{
	return this->properties.decorated;
}

bool onyx::Window::is_topmost() const
{
	return this->properties.topmost;
}

bool onyx::Window::focuses_on_show() const
{
	return this->properties.focus_on_show;
}

int onyx::Window::get_n_samples_msaa() const
{
	return this->properties.n_samples_msaa;
}

bool onyx::Window::is_fullscreen() const
{
	return this->properties.fullscreen;
}

bool onyx::Window::is_maximized() const
{
	return glfwGetWindowAttrib(this->p_glfw_win, GLFW_MAXIMIZED);
}

bool onyx::Window::is_minimized() const
{
	return glfwGetWindowAttrib(this->p_glfw_win, GLFW_ICONIFIED);
}

void onyx::Window::set_title(const std::string& title)
{
	this->properties.title = title;
	glfwSetWindowTitle(this->p_glfw_win, title.c_str());
}

void onyx::Window::set_size(int width, int height)
{
	this->properties.width = width;
	this->properties.height = height;
	glfwSetWindowSize(this->p_glfw_win, width, height);
}

void onyx::Window::set_position(const math::IVec2& position)
{
	this->properties.position = position;
	glfwSetWindowPos(this->p_glfw_win, position.get_x(), position.get_y());
}

void onyx::Window::set_background_color(onyx::math::Vec3 rgb)
{
	this->properties.background_color = rgb;
}

void onyx::Window::set_icon(const WindowIcon& new_icon)
{
	this->icon = new_icon;
	glfwSetWindowIcon(this->p_glfw_win, new_icon.n_images, new_icon.p_images);
}

void onyx::Window::set_cursor(const Cursor& new_cursor)
{
	glfwSetCursor(this->p_glfw_win, new_cursor.p_cursor);
}

void onyx::Window::set_opacity(float opacity)
{
	this->properties.opacity = math::clamp(opacity, 0.0f, 1.0f);
	glfwSetWindowOpacity(this->p_glfw_win, this->properties.opacity);
}

void onyx::Window::fullscreen()
{
	// Queried each time rather than cached: GLFW monitor pointers are invalidated by
	// glfwTerminate() and by the monitor being disconnected.
	GLFWmonitor* p_primary_monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* p_video_mode = p_primary_monitor != nullptr ? glfwGetVideoMode(p_primary_monitor) : nullptr;
	if (p_video_mode == nullptr)
	{
		onyx_err(Error{
				.source_function = "onyx::Window::fullscreen()",
				.message = "Failed to get the primary monitor or its video mode.",
				.how_to_fix = "Ensure a monitor is connected."
			}
		);
		return;
	}

	this->properties.fullscreen = true;
	glfwSetWindowMonitor(this->p_glfw_win, p_primary_monitor, 0, 0, p_video_mode->width, p_video_mode->height, p_video_mode->refreshRate);
	apply_vsync();
}

void onyx::Window::fullscreen(Monitor& monitor)
{
	if (monitor.get_glfw_monitor() == nullptr)
	{
		onyx_err(Error{
				.source_function = "onyx::Window::fullscreen(Monitor& monitor)",
				.message = "The monitor is invalid (null GLFW monitor).",
				.how_to_fix = "Use a monitor from Monitor::get_primary() or Monitor::get_all()."
			}
		);
		return;
	}

	this->properties.fullscreen = true;
	glfwSetWindowMonitor(this->p_glfw_win, monitor.get_glfw_monitor(), 0, 0, monitor.get_dimensions().get_x(), monitor.get_dimensions().get_y(), monitor.get_refresh_rate());
	apply_vsync();
}

void onyx::Window::windowed()
{
	this->properties.fullscreen = false;
	glfwSetWindowMonitor(this->p_glfw_win, nullptr, this->properties.position.get_x(), this->properties.position.get_y(), this->properties.width, this->properties.height, 0);
	if (this->properties.decorated) set_decorated(true);
	apply_vsync();
}

void onyx::Window::windowed(int width, int height, math::IVec2 position)
{
	this->properties.fullscreen = false;
	glfwSetWindowMonitor(this->p_glfw_win, nullptr, position.get_x(), position.get_y(), width, height, 0);
	if (this->properties.decorated) set_decorated(true);
	apply_vsync();
}

void onyx::Window::toggle_fullscreen()
{
	if (this->properties.fullscreen)
		windowed();
	else
		fullscreen();
}

void onyx::Window::toggle_fullscreen(int width, int height, math::IVec2 position)
{
	if (this->properties.fullscreen)
		windowed(width, height, position);
	else
		fullscreen();
}

void onyx::Window::hide()
{
	this->properties.visible = false;
	glfwHideWindow(this->p_glfw_win);
}

void onyx::Window::show()
{
	this->properties.visible = true;
	glfwShowWindow(this->p_glfw_win);
}

void onyx::Window::toggle_visibility()
{
	if (this->properties.visible)
		hide();
	else
		show();
}

void onyx::Window::focus()
{
	this->properties.focused = true;
	glfwFocusWindow(this->p_glfw_win);
}

void onyx::Window::set_resizable(bool resizable)
{
	this->properties.resizable = resizable;
	glfwSetWindowAttrib(this->p_glfw_win, GLFW_RESIZABLE, resizable);
}

void onyx::Window::toggle_resizable()
{
	set_resizable(!this->properties.resizable);
}

void onyx::Window::set_decorated(bool decorated)
{
	this->properties.decorated = decorated;
	glfwSetWindowAttrib(this->p_glfw_win, GLFW_DECORATED, decorated);
}

void onyx::Window::toggle_decorated()
{
	set_decorated(!this->properties.decorated);
}

void onyx::Window::set_topmost(bool topmost)
{
	this->properties.topmost = topmost;
	glfwSetWindowAttrib(this->p_glfw_win, GLFW_FLOATING, topmost);
}

void onyx::Window::toggle_topmost()
{
	set_topmost(!this->properties.topmost);
}

void onyx::Window::set_focus_on_show(bool focus_on_show)
{
	this->properties.focus_on_show = focus_on_show;
	glfwSetWindowAttrib(this->p_glfw_win, GLFW_FOCUS_ON_SHOW, focus_on_show);
}

void onyx::Window::toggle_focus_on_show()
{
	set_focus_on_show(!this->properties.focus_on_show);
}

void onyx::Window::link_input_handler(InputHandler& input_handler)
{
	input_handler.p_win = this;
	this->p_input_handlers.push_back(&input_handler);
	input_handler.scan_gamepads();

	// Cursor positions are in screen coordinates, so flip using the window size (not the framebuffer size).
	double mouse_x = 0.0, mouse_y = 0.0;
	int win_width = 0, win_height = this->properties.height;
	glfwGetCursorPos(this->p_glfw_win, &mouse_x, &mouse_y);
	glfwGetWindowSize(this->p_glfw_win, &win_width, &win_height);
	mouse_y = win_height - mouse_y;
	input_handler.mouse_pos = math::DVec2(mouse_x, mouse_y);
	input_handler.last_mouse_pos = math::DVec2(mouse_x, mouse_y);
}

void onyx::Window::link_camera(Camera& camera)
{
	camera.p_win = this;
	this->p_cams.push_back(&camera);
}

void onyx::Window::link_renderer(Renderer& renderer)
{
	renderer.p_win = this;
	this->p_renderers.push_back(&renderer);

	renderer.ortho = Projection::orthographic(static_cast<float>(this->buffer_width), static_cast<float>(this->buffer_height)).get_matrix();
}

void onyx::Window::set_framebuffer_size_callback(FramebufferSizeCallbackFn callback)
{
	this->p_framebuffer_size_callback = callback;
}

void onyx::Window::set_window_size_callback(WindowSizeCallbackFn callback)
{
	this->p_window_size_callback = callback;
}

void onyx::Window::set_window_pos_callback(WindowPosCallbackFn callback)
{
	this->p_window_pos_callback = callback;
}

void onyx::Window::set_file_drop_callback(FileDropCallbackFn callback)
{
	this->p_file_drop_callback = callback;
}

void onyx::Window::dispose()
{
	if (this->disposed) return;
	this->cursor.dispose();
	if (this->initialized)
	{
		{
			std::lock_guard lock(Window::mtx_windows);
			Window::p_windows.erase(std::remove(Window::p_windows.begin(), Window::p_windows.end(), this), Window::p_windows.end());
		}
		glfwDestroyWindow(this->p_glfw_win);
	}

	this->p_glfw_win = nullptr;
	this->buffer_width = this->buffer_height = 0;
	this->initialized = false;
	this->disposed = true;
}

void onyx::Window::framebuffer_size_callback(GLFWwindow* p_glfw_win, int width, int height)
{
	glViewport(0, 0, width, height);

	Window* p_win = (Window*)glfwGetWindowUserPointer(p_glfw_win);
	p_win->buffer_width = width;
	p_win->buffer_height = height;

	for (Camera* p_cam : p_win->p_cams)
	{
		if (p_cam->get_projection().get_type() == onyx::ProjectionType::Perspective)
		{
			Projection proj = p_cam->get_projection();
			p_cam->set_projection(Projection::perspective(proj.get_fov(), width, height, proj.get_near_plane(), proj.get_far_plane()));
		}
		else if (p_cam->get_projection().get_type() == onyx::ProjectionType::Orthographic)
		{
			p_cam->set_projection(Projection::orthographic(static_cast<float>(width), static_cast<float>(height)));
		}
	}

	for (Renderer* p_renderer : p_win->p_renderers)
	{
		p_renderer->ortho = Projection::orthographic(static_cast<float>(width), static_cast<float>(height)).get_matrix();
	}

	if (p_win->p_framebuffer_size_callback) p_win->p_framebuffer_size_callback(width, height);

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Window::window_size_callback(GLFWwindow* p_glfw_win, int width, int height)
{
	Window* p_win = (Window*)glfwGetWindowUserPointer(p_glfw_win);
	p_win->properties.width = width;
	p_win->properties.height = height;

	if (p_win->p_window_size_callback) p_win->p_window_size_callback(width, height);
}

void onyx::Window::window_pos_callback(GLFWwindow* p_glfw_win, int x, int y)
{
	Window* p_win = (Window*)glfwGetWindowUserPointer(p_glfw_win);
	p_win->properties.position = math::IVec2(x, y);

	if (p_win->p_window_pos_callback) p_win->p_window_pos_callback(x, y);
}

void onyx::Window::key_callback(GLFWwindow* p_glfw_win, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_UNKNOWN) return;

	Window* p_win = (Window*)glfwGetWindowUserPointer(p_glfw_win);
	for (InputHandler* p_input_handler : p_win->p_input_handlers)
	{
		p_input_handler->key_callback(key, scancode, action, mods);
	}
}

void onyx::Window::mouse_button_callback(GLFWwindow* p_glfw_win, int button, int action, int mods)
{
	Window* p_win = (Window*)glfwGetWindowUserPointer(p_glfw_win);
	for (InputHandler* p_input_handler : p_win->p_input_handlers)
	{
		p_input_handler->mouse_button_callback(button, action, mods);
	}
}

void onyx::Window::cursor_pos_callback(GLFWwindow* p_glfw_win, double x, double y)
{
	Window* p_win = (Window*)glfwGetWindowUserPointer(p_glfw_win);
	// Cursor positions are in screen coordinates, so flip using the window size (not the framebuffer size).
	int win_width = 0, win_height = p_win->properties.height;
	glfwGetWindowSize(p_glfw_win, &win_width, &win_height);
	for (InputHandler* p_input_handler : p_win->p_input_handlers)
	{
		p_input_handler->mouse_pos_callback(x, win_height - y);
	}
}

void onyx::Window::scroll_callback(GLFWwindow* p_glfw_win, double dx, double dy)
{
	Window* p_win = (Window*)glfwGetWindowUserPointer(p_glfw_win);
	for (InputHandler* p_input_handler : p_win->p_input_handlers)
	{
		p_input_handler->scroll_callback(dx, dy);
	}
}

void onyx::Window::joystick_callback(int jid, int event)
{
	// Joystick events are global rather than per-window, so notify the input handlers of every window.
	// Copy the list first so a callback that disposes a window can't invalidate the iteration.
	std::vector<Window*> p_windows_copy;
	{
		std::lock_guard lock(Window::mtx_windows);
		p_windows_copy = Window::p_windows;
	}

	for (Window* p_win : p_windows_copy)
	{
		for (InputHandler* p_input_handler : p_win->p_input_handlers)
		{
			p_input_handler->joystick_callback(jid, event);
		}
	}
}

void onyx::Window::file_drop_callback(GLFWwindow* p_glfw_win, int count, const char** paths)
{
	Window* p_win = (Window*)glfwGetWindowUserPointer(p_glfw_win);
	if (p_win->p_file_drop_callback) p_win->p_file_drop_callback(paths, count);
}
