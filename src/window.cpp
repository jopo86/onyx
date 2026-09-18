#pragma warning(disable: 4244; disable: 4267)

#include <fstream>

#include <stbi/stb_image.h>

#include <onyx/window.hpp>
#include <onyx/camera.hpp>
#include <onyx/input_handler.hpp>

using onyx::math::Vec3;

GLFWmonitor* onyx::Window::p_primary_monitor = nullptr;
GLFWvidmode* onyx::Window::p_primary_monitor_info = nullptr;
std::mutex onyx::Window::mtx_primary_monitor;

void onyx_set_gl_init(bool);
void onyx_err(const onyx::Error&);
void onyx_warn(const onyx::Warning&);

onyx::WindowIcon::WindowIcon()
{
	this->p_images = nullptr;
	this->n_images = 0;
}

onyx::WindowIcon onyx::WindowIcon::load(const std::initializer_list<std::string>& filepaths, bool* result)
{
	for (const std::string& filepath : filepaths)
	{
		std::ifstream file(filepath);
		if (!file.is_open())
		{
			onyx_err(Error{
					.source_function = "onyx::WindowIcon::load(const std::initializer_list<std::string>& filepaths)",
					.message = "File not found (or access denied): \"" + filepath + "\"",
					.how_to_fix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
				}
			);
			if (result != nullptr) *result = false;
			return WindowIcon();
		}
		file.close();
	}

	WindowIcon icon;

	icon.n_images = filepaths.size();
	icon.p_images = new GLFWimage[icon.n_images];

	stbi_set_flip_vertically_on_load(false);
	for (u32 i = 0; i < icon.n_images; i++)
	{
		icon.p_images[i].pixels = stbi_load(filepaths.begin()[i].c_str(), &icon.p_images[i].width, &icon.p_images[i].height, nullptr, 4);
		if (icon.p_images[i].pixels == nullptr)
		{
			onyx_err(Error{
					.source_function = "onyx::WindowIcon::load(const std::initializer_list<std::string>& filepaths)",
					.message = "All files found, but failed to load image data from one or more files",
					.how_to_fix = "Ensure the files ares valid image files. Supported formats: .jpg/.jpeg, .png, .tga, .bmp, .psd, .gif, .hdr, .pic, .pnm"
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
	for (u32 i = 0; i < this->n_images; i++) stbi_image_free(this->p_images[i].pixels);
	delete[] this->p_images;
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
	std::ifstream file(filepath);
	if (!file.is_open())
	{
		onyx_err(Error{
				.source_function = "onyx::Cursor::load(const std::string& filepath)",
				.message = "File not found (or access denied): \"" + filepath + "\"",
				.how_to_fix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
			}
		);
		if (result != nullptr) *result = false;
		return Cursor();
	}

	GLFWimage image;
	image.pixels = stbi_load(filepath.c_str(), &image.width, &image.height, nullptr, 4);
	if (image.pixels == nullptr)
	{
		onyx_err(Error{
				.source_function = "onyx::Cursor::load(const std::string& filepath)",
				.message = "File found, but failed to load image data from it: \"" + filepath + "\"",
				.how_to_fix = "Ensure the file is a valid image file. Supported formats: .jpg/.jpeg, .png, .tga, .bmp, .psd, .gif, .hdr, .pic, .pnm"
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
	glfwDestroyCursor(this->p_cursor);
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

	Window::mtx_primary_monitor.lock();
	if (Window::p_primary_monitor == nullptr) Window::p_primary_monitor = glfwGetPrimaryMonitor();
	if (Window::p_primary_monitor_info == nullptr) Window::p_primary_monitor_info = (GLFWvidmode*)glfwGetVideoMode(Window::p_primary_monitor);
	Window::mtx_primary_monitor.unlock();

	this->p_glfw_win = glfwCreateWindow(this->properties.width, this->properties.height, this->properties.title.c_str(), nullptr, nullptr);
	if (this->p_glfw_win == nullptr)
	{
		onyx_err(Error{
				.source_function = "onyx::Window::init()",
				.message = "Failed to create GLFW window.",
				.how_to_fix = "Ensure the window is not already initialized, and that the GLFW library is downloaded for your specific platform. If you are not running Windows x64, you will need to download GLFW for yourself, you can't just use the one from the Onyx download."
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

	glfwSwapInterval(1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		onyx_err(Error{
				.source_function = "onyx::Window::init()",
				.message = "Failed to initialize OpenGL.",
				.how_to_fix = "Ensure that the window is not already initialized, and that the glad library is downloaded for your specific platofrm. If you are not running Windows x64, you will need to download glad for yourself, you can't just use the one from the Onyx download."
			}
		);
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
	if (result != nullptr) *result = true;

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

	Window::mtx_primary_monitor.lock();
	if (Window::p_primary_monitor == nullptr) Window::p_primary_monitor = glfwGetPrimaryMonitor();
	if (Window::p_primary_monitor_info == nullptr) Window::p_primary_monitor_info = (GLFWvidmode*)glfwGetVideoMode(Window::p_primary_monitor);
	Window::mtx_primary_monitor.unlock();

	this->p_glfw_win = glfwCreateWindow(this->properties.width, this->properties.height, this->properties.title.c_str(), nullptr, share.get_glfw_window_ptr());
	if (this->p_glfw_win == nullptr)
	{
		onyx_err(Error{
				.source_function = "onyx::Window::init()",
				.message = "Failed to create GLFW window.",
				.how_to_fix = "Ensure the window is not already initialized, and that the GLFW library is downloaded for your specific platform. If you are not running Windows x64, you will need to download GLFW for yourself, you can't just use the one from the Onyx download."
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

	glfwSwapInterval(1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		onyx_err(Error{
				.source_function = "onyx::Window::init()",
				.message = "Failed to initialize OpenGL.",
				.how_to_fix = "Ensure that the window is not already initialized, and that the glad library is downloaded for your specific platofrm. If you are not running Windows x64, you will need to download glad for yourself, you can't just use the one from the Onyx download."
			}
		);
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
	if (result != nullptr) *result = true;

	this->cursor = Cursor::standard(CursorType::Arrow);
	set_cursor(this->cursor);
}

void onyx::Window::start_render()
{
	this->delta_time = get_time() - this->last_frame_time;
	if (Renderer::get_fps_limit().first)
	{
		while (this->delta_time < 1.0 / Renderer::get_fps_limit().second)
		{
			this->delta_time = get_time() - this->last_frame_time;
		}
	}

	this->fps = round(1.0 / this->delta_time);
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

	if (this->frame > 2 && this->num_frames_cam_not_updated > 2 && this->p_cams.size() > 0) onyx_warn(onyx::Warning{
			.source_function = "onyx::Window::end_render()",
			.message = "Camera was not updated this frame.",
			.how_to_fix = "Be sure to update the camera with Camera::update() every frame for camera transformations to have any effect.",
			.severity = Warning::Severity::Med
		}
	);

	if (this->frame > 2 && this->num_frames_input_not_updated > 2 && this->p_input_handlers.size() > 0) onyx_warn(onyx::Warning{
			.source_function = "onyx::Window::end_render()",
			.message = "Input handler was not updated this frame.",
			.how_to_fix = "Be sure to update the input handler with InputHandler::update() every frame.",
			.severity = Warning::Severity::High
		}
	);
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
	return this->properties.visible;
}

bool onyx::Window::is_hidden() const
{
	return !this->properties.visible;
}

bool onyx::Window::is_focused() const
{
	return this->properties.focused;
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

void onyx::Window::set_icon(const WindowIcon& icon)
{
	this->icon = icon;
	glfwSetWindowIcon(this->p_glfw_win, icon.n_images, icon.p_images);
}

void onyx::Window::set_cursor(const Cursor& cursor)
{
	glfwSetCursor(this->p_glfw_win, cursor.p_cursor);
}

void onyx::Window::set_opacity(float opacity)
{
	this->properties.opacity = math::clamp(opacity, 0.0f, 1.0f);
	glfwSetWindowOpacity(this->p_glfw_win, this->properties.opacity);
}

void onyx::Window::fullscreen()
{
	this->properties.fullscreen = true;
	Window::mtx_primary_monitor.lock();
	glfwSetWindowMonitor(this->p_glfw_win, Window::p_primary_monitor, 0, 0, Window::p_primary_monitor_info->width, Window::p_primary_monitor_info->height, Window::p_primary_monitor_info->refreshRate);
	Window::mtx_primary_monitor.unlock();
	glfwSwapInterval(1);
}

void onyx::Window::fullscreen(Monitor& monitor)
{
	this->properties.fullscreen = true;
	glfwSetWindowMonitor(this->p_glfw_win, monitor.get_glfw_monitor(), 0, 0, monitor.get_dimensions().get_x(), monitor.get_dimensions().get_y(), monitor.get_refresh_rate());
	glfwSwapInterval(1);
}

void onyx::Window::windowed()
{
	this->properties.fullscreen = false;
	glfwSetWindowMonitor(this->p_glfw_win, nullptr, this->properties.position.get_x(), this->properties.position.get_y(), this->properties.width, this->properties.height, 0);
	if (this->properties.decorated) set_decorated(true);
	glfwSwapInterval(1);
}

void onyx::Window::windowed(int width, int height, math::IVec2 position)
{
	this->properties.fullscreen = false;
	glfwSetWindowMonitor(this->p_glfw_win, nullptr, position.get_x(), position.get_y(), width, height, 0);
	if (this->properties.decorated) set_decorated(true);
	glfwSwapInterval(1);
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
	double mouse_x, mouse_y;
	glfwGetCursorPos(this->p_glfw_win, &mouse_x, &mouse_y);
	mouse_y = this->properties.height - mouse_y;
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

	renderer.ortho = Projection::orthographic(this->buffer_width, this->buffer_height).get_matrix();
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
	if (this->initialized)
	{
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
			p_cam->set_projection(Projection::orthographic(width, height));
		}
	}

	for (Renderer* p_renderer : p_win->p_renderers)
	{
		p_renderer->ortho = Projection::orthographic(width, height).get_matrix();
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
	for (InputHandler* p_input_handler : p_win->p_input_handlers)
	{
		p_input_handler->mouse_pos_callback(x, ((Window*)glfwGetWindowUserPointer(p_glfw_win))->properties.height - y);
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
	Window* p_win = (Window*)glfwGetWindowUserPointer(glfwGetCurrentContext());
	for (InputHandler* p_input_handler : p_win->p_input_handlers)
	{
		p_input_handler->joystick_callback(jid, event);
	}
}

void onyx::Window::file_drop_callback(GLFWwindow* p_glfw_win, int count, const char** paths)
{
	Window* p_win = (Window*)glfwGetWindowUserPointer(p_glfw_win);
	if (p_win->p_file_drop_callback) p_win->p_file_drop_callback(paths, count);
}
