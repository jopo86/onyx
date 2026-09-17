#pragma once

#include <vector>
#include <mutex>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "core.h"
#include "math_wrappers.h"
#include "renderer.h"
#include "monitor.h"

namespace onyx
{
	class Camera;
	class InputHandler;

	struct WindowProperties
	{
		/*
			@brief The title of the window.
			This can be changed later with `set_title()`.
			Default: "Onyx Window"
		 */
		std::string title = "Onyx Window";

		/*
			@brief The width of the window.
			This can be changed later with `set_size()`.
			Default: 800
		 */
		int width = 800;

		/*
			@brief The height of the window.
			This can be changed later with `set_size()`.
			Default: 600
		 */
		int height = 600;

		/*
			@brief The position of the top-left of the window.
			(0, 0) is the top-left of the screen.
			This can be changed later with `set_position()`.
			Default: (100, 100)
		 */
		math::IVec2 position = math::IVec2(100, 100);

		/*
			@brief Whether the window is resizable.
			This can be changed later with `set_resizable()` and `toggle_resizable()`.
			Default: true
		 */
		bool resizable = true;

		/*
			@brief Whether the window is visible.
			This can be changed later with `hide()`, `show()`, and `toggle_visibility()`.
			Default: true
		 */
		bool visible = true;

		/*
			@brief Whether the window is focused.
			This can be changed later with `focus()`, `unfocus()`, and `toggle_focus()`.
			Default: true
		 */
		bool focused = true;

		/*
			@brief Whether the window is fullscreen.
			This can be changed later with `set_fullscreen()` and `toggle_fullscreen()`.
			Default: false
		 */
		bool fullscreen = false;

		/*
			@brief Whether the window is decorated (border, close widget, etc.)
			This can be changed later with `set_decorated()` and `toggle_decorated()`.
			Fullscreen borderless can be achieved with set_decorated(false) and maximize().
			Default: true
		 */
		bool decorated = true;

		/*
			@brief Whether the window is topmost (AKA floating, always on top).
			This can be changed later with `set_topmost()` and `toggle_topmost()`.
			Default: false
		 */
		bool topmost = false;

		/*
			@brief Whether to put input focus on the window when it is shown.
			This can be changed later with `set_focus_on_show()` and `toggle_focus_on_show()`.
			Default: true
		 */
		bool focus_on_show = true;

		/*
			@brief The number of samples for multi-sample anti-aliasing.
			This cannot be changed later.
			0 means no anti-aliasing.
			Default: 0
		 */
		int n_samples_msaa = 0;

		/*
			@brief The opacity of the window (including its decorations).
			This can be changed later with `set_opacity()`.
			Default: 1.0
		 */
		float opacity = 1.0f;

		/*
			@brief The background color of the window.
			This can be changed later with `set_background_color()`.
			Default: black
		 */
		math::Vec3 background_color = math::Vec3::black();
	};

	/*
		@brief A class to represent a window icon.
	 */
	class WindowIcon : public Disposable
	{
		friend class Window;
	public:
		/*
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
			Use the static load() function to create a valid window icon.
		 */
		WindowIcon();

		/*
			@brief Creates a window icon from the specified filepaths.
			Multiple filepaths allow for different resolutions, because the automatic scaling sucks.
			Ideally, provide a 16x16, 24x24, 32x32, 48x48, and 256x256 image.
			@param filepaths The filepaths of the images to use as the icon.
			@param result A pointer to a boolean that will be set to true if the icon was loaded successfully, false otherwise.
			@return The created window icon.
		 */
		static WindowIcon load(const std::initializer_list<std::string>& filepaths, bool* result = nullptr);

		void dispose() override;

	private:
		GLFWimage* p_images;
		u32 n_images;
	};

	/*
		@brief A class to represent a cursor.
	 */
	class Cursor : public Disposable
	{
		friend class Window;
	public:
		/*
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
			Use the static standard() or load() functions to create a valid cursor.
		 */
		Cursor();

		/*
			@brief Gets the type of the cursor.
			If the cursor was created with standard(), this will return the type of standard cursor.
			If the cursor was created with load(), this will return CursorType::Custom.
			If the cursor was created with the default constructor, this will return CursorType::Null.
			@return The type of the cursor.
		 */
		CursorType get_type() const;

		/*
			@brief Creates a standard cursor.
			@param type The type of standard cursor to create.
			@return The created cursor.
		 */
		static Cursor standard(CursorType type);

		/*
			@brief Creates a cursor from the specified image file.
			@param filepath The filepath of the image to use as the cursor.
			@param hotspot The hotspot of the cursor, specified as a pixel offset from the top-left of the image.
			The hotspot is the part of the cursor that interacts with other elements.
			@param result A pointer to a boolean that will be set to true if the cursor was loaded successfully, false otherwise.
			@return The created cursor.
		 */
		static Cursor load(const std::string& filepath, math::IVec2 hotspot = math::IVec2(0, 0), bool* result = nullptr);

		void dispose() override;

	private:
		GLFWcursor* p_cursor;
		CursorType type;
	};

	/*
		@brief A class to represent a window.
		A window must be created and initialized for anything related to OpenGL to occur.
		Window creation and initialization be the first thing done before any other Onyx functions.
		This class is disposable.
	 */
	class Window : public Disposable
	{
		friend class InputHandler;
		friend class Camera;
		friend class Renderer;

		/*
			@brief The framebuffer resize callback function signature.
			@param width The new framebuffer width.
			@param height The new framebuffer height.
		*/
		typedef void(*FramebufferSizeCallbackFn)(int width, int height);

		/*
			@brief The window resize callback function signature.
			@param width The new window width.
			@param height The new window height.
		*/
		typedef void(*WindowSizeCallbackFn)(int width, int height);

		/*
			@brief The window position callback function signature.
			@param x The new X position of the window as a monitor coordinate.
			@param y The new Y position of the window as a monitor coordinate.
		*/
		typedef void(*WindowPosCallbackFn)(int x, int y);

		/*
			@brief The file drop callback function signature.
			@param paths An array of string literals representing each file path.
			@param count The number of file paths in the array.
		*/
		typedef void(*FileDropCallbackFn)(const char** paths, int count);

	public:
		/*
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
		 */
		Window();

		/*
			@brief Creates an uninitialized window from the specified window properties.
			@param properties The window properties.
		 */
		Window(const WindowProperties& properties);

		/*
			@brief Initializes the window.
			This initializes OpenGL, so it must be called before any OpenGL functions.
			@param result A pointer to a boolean that will be set to true if the window was initialized successfully, false otherwise.
		 */
		void init(bool* result = nullptr);

		/*
			@brief Initializes the window, sharing OpenGL resources with another window.
			This initializes OpenGL, so it must be called before any OpenGL functions.
			@param share The window to share OpenGL resources with.
			@param result A pointer to a boolean that will be set to true if the window was initialized successfully, false otherwise.
		 */
		void init(const onyx::Window& share, bool* result = nullptr);

		/*
			@brief Prepares to render the current frame.
			This function clears the window to the background color and updates the delta time / FPS / frame #.
			It also polls events if no input handler has been linked to do so.
		 */
		void start_render();

		/*
			@brief Finishes rendering the current frame.
			This function swaps the buffers of the window.
		 */
		void end_render();

		/*
			@brief Closes the window.
			Once called, is_open() will return false.
		 */
		void close();

		/*
			@brief Maximizes the window (different from fullscreen).
			Fullscreen borderless can be achieved with set_decorated(false) and maximize().
		 */
		void maximize();

		/*
			@brief Minimizes the window (different from hidden).
		 */
		void minimize();

		/*
			@brief Restores the window to its previous size and position after being minimized or maximized.
		 */
		void restore();

		/*
			@brief Requests attention from the user.
			Use if you wish to notify the user of an event without interrupting.
		 */
		void request_attention();

		/*
			@brief Gets the open/closed status of the window.
			@return Whether the window is open.
		 */
		bool is_open() const;

		/*
			@brief Gets the title of the window.
			@return The title of the window.
		 */
		const std::string& get_title() const;

		/*
			@brief Gets the width of the window.
			@return The width of the window.
		 */
		int get_width() const;

		/*
			@brief Gets the height of the window.
			@return The height of the window.
		 */
		int get_height() const;

		/*
			@brief Gets the width of the rendering frame of the window, not including borders.
			@return The buffer width of the window, explained above.
		 */
		int get_buffer_width() const;

		/*
			@brief Gets the height of the rendering frame of the window, not including borders.
			@return The buffer height of the window, explained above.
		 */
		int get_buffer_height() const;

		/*
			@brief Gets the position of the top-left of the window.
			(0, 0) is the top-left of the screen.
			@return The position of the window.
		 */
		const math::IVec2& get_position() const;

		/*
			@brief Gets the current frame number.
			The frame number is increased every time start_render() is called.
			@return The current frame number.
		 */
		usize get_frame() const;

		/*
			@brief Gets the current frames per second.
			@return The current frames per second.
		 */
		int get_fps() const;

		/*
			@brief Gets the time since the last frame, in seconds.
			@return The time since the last frame, in seconds.
		 */
		double get_delta_time() const;

		/*
			@brief Gets the opacity of the window.
			@return The opacity of the window.
		 */
		float get_opacity() const;

		/*
			@brief Gets the background color of the window.
			@return The background color of the window.
		 */
		const math::Vec3& get_background_color() const;

		/*
			@brief Gets the icon of the window.
			@return The icon of the window.
		 */
		const WindowIcon& get_icon() const;

		/*
			@brief Gets the cursor of the window.
			@return The cursor of the window.
		 */
		const Cursor& get_cursor() const;

		/*
			@brief Gets the GLFW window pointer.
			Access to the GLFW window is provided for the library, as well as for advanced users.
			@return A pointer to the GLFW window.
		 */
		GLFWwindow* get_glfw_window_ptr() const;

		/*
			@brief Gets the initialization status of the window.
			@return Whether the window has been initialized.
		 */
		bool is_initialized() const;

		/*
			@brief Gets whether the window is resizable.
			@return Whether the window is resizable.
		 */
		bool is_resizable() const;

		/*
			@brief Gets whether the window is visible.
			@return Whether the window is visible.
		 */
		bool is_visible() const;

		/*
			@brief Gets whether the window is hidden.
			@return Whether the window is hidden.
		 */
		bool is_hidden() const;

		/*
			@brief Gets whether the window is focused.
			@return Whether the window is focused.
		 */
		bool is_focused() const;

		/*
			@brief Gets whether the window is decorated (border, close widget, etc.)
			@return Whether the window is decorated.
		 */
		bool is_decorated() const;

		/*
			@brief Gets whether the window is topmost (AKA floating, always on top).
			@return Whether the window is topmost.
		 */
		bool is_topmost() const;

		/*
			@brief Gets whether the window automatically becomes input focused when shown.
			@return Whether the window automatically becomes input focused when shown.
		 */
		bool focuses_on_show() const;

		/*
			@brief Gets the number of samples for multi-sample anti-aliasing.
			@return The number of samples for multi-sample anti-aliasing. 0 means no anti-aliasing.
		 */
		int get_n_samples_msaa() const;

		/*
			@brief Gets whether the window is fullscreen.
			@return Whether the window is fullscreen.
		 */
		bool is_fullscreen() const;

		/*
			@brief Gets whether the window is maximized.
			@return Whether the window is maximized.
		 */
		bool is_maximized() const;

		/*
			@brief Gets whether the window is minimized.
			@return Whether the window is minimized.
		 */
		bool is_minimized() const;

		/*
			@brief Sets the title of the window.
			@param title The title of the window.
		 */
		void set_title(const std::string& title);

		/*
			@brief Sets the size of the window.
			@param width The width of the window.
			@param height The height of the window.
		 */
		void set_size(int width, int height);

		/*
			@brief Sets the position of the top-left of the window.
			(0, 0) is the top-left of the screen.
			@param position The position of the window.
		 */
		void set_position(const math::IVec2& position);

		/*
			@brief Sets the background color of the window.
			This is what color the window clears to at the start of each frame.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
		 */
		void set_background_color(onyx::math::Vec3 rgb);

		/*
			@brief Sets the icon of the window.
			@param icon The icon of the window.
		 */
		void set_icon(const WindowIcon& icon);

		/*
			@brief Sets the cursor of the window.
			@param cursor The cursor to set.
		 */
		void set_cursor(const Cursor& cursor);

		/*
			@brief Sets the opacity of the window, including decorations.
			@param opacity The opacity of the window, ranging from 0 to 1.
			Value is clamped to the range [0, 1].
		 */
		void set_opacity(float opacity);

		/*
			@brief Sets the window to fullscreen mode on the primary monitor.
		 */
		void fullscreen();

		/*
			@brief Sets the window to fullscreen mode on the specified monitor.
		 */
		void fullscreen(Monitor& monitor);

		/*
			@brief Sets the window to windowed mode.
			Does not change the width, height or position, so it may still look like fullscreen.
			Use windowed(int, int, math::IVec2) to change these values.
		 */
		void windowed();

		/*
			@brief Sets the window to windowed mode with the specified width, height, and position.
			@param width The width of the window.
			@param height The height of the window.
			@param position The position of the (top-left of the) window.
		 */
		void windowed(int width, int height, math::IVec2 position = math::IVec2(0, 0));

		/*
			@brief Toggles between fullscreen and windowed mode.
		 */
		void toggle_fullscreen();

		/*
			@brief Toggles between fullscreen and windowed mode.
			If the window is fullscreen, it will be windowed with the specified width, height, and position.
			If the window is windowed, it will be set to fullscreen and the parameters will be ignored.
			@param width The width of the window if it gets switched to windowed mode.
			@param height The height of the window if it gets switched to windowed mode.
			@param position The position of the (top-left of the) window if it gets switched to windowed mode.
		 */
		void toggle_fullscreen(int width, int height, math::IVec2 position = math::IVec2(0, 0));

		/*
			@brief Hides the window.
		 */
		void hide();

		/*
			@brief Shows the window.
		 */
		void show();

		/*
			@brief Toggles visibility (hidden/shown) of the window.
		 */
		void toggle_visibility();

		/*
			@brief Focuses the window.
			Not recommended, as it can be annoying to the user.
		 */
		void focus();

		/*
			@brief Sets whether the window is resizable.
			@param resizable Whether the window should be resizable.
		 */
		void set_resizable(bool resizable);

		/*
			@brief Toggles whether the window is resizable.
		 */
		void toggle_resizable();

		/*
			@brief Sets decoration (border, close widget, etc.) of the window to be enabled/disabled.
			Fullscreen borderless can be achieved with set_decorated(false) and maximize().
			@param decorated Whether decoration should be enabled.
		 */
		void set_decorated(bool decorated);

		/*
			@brief Toggles decoration (border, close widget, etc.) of the window.
		 */
		void toggle_decorated();

		/*
			Sets whether the window is topmost (AKA floating, always on top).
			@param topmost Whether the window should be topmost.
		 */
		void set_topmost(bool topmost);

		/*
			Toggles whether the window is topmost (AKA floating, always on top).
		 */
		void toggle_topmost();

		/*
			@brief Sets whether the window automatically becomes input focused when shown.
			@param focus_on_show Whether the window should be focused when shown.
		 */
		void set_focus_on_show(bool focus_on_show);

		/*
			@brief Toggles whether the window automatically becomes input focused when shown.
		 */
		void toggle_focus_on_show();

		/*
			@brief Links an input handler to the window.
			@param input_handler The input handler to link.
		 */
		void link_input_handler(InputHandler& input_handler);

		/*
			@brief Links a camera to the window.
			@param cam The camera to link.
		 */
		void link_camera(Camera& cam);

		/*
			@brief Links a renderer to the window.
			@param renderer The renderer to link.
		 */
		void link_renderer(Renderer& renderer);

		/*
			@brief Sets the framebuffer resize callback function.
			@param callback The callback function.
			See the definition of `FramebufferSizeCallbackFn` for parameter info.
		 */
		void set_framebuffer_size_callback(FramebufferSizeCallbackFn callback);

		/*
			@brief Sets the window resize callback function.
			@param callback The callback function.
			See the definition of `WindowSizeCallbackFn` for parameter info.
		 */
		void set_window_size_callback(WindowSizeCallbackFn callback);

		/*
			@brief Sets the window position callback function.
			@param callback The callback function.
			See the definition of `WindowPosCallbackFn` for parameter info.
		 */
		void set_window_pos_callback(WindowPosCallbackFn callback);

		/*
			@brief Sets the file drop callback function.
			@param callback The callback function.
			See the definition of `FileDropCallbackFn` for parameter info.
		 */
		void set_file_drop_callback(FileDropCallbackFn callback);

		void dispose() override;

	private:
		WindowProperties properties;
		WindowIcon icon;
		Cursor cursor;

		GLFWwindow* p_glfw_win;
		static GLFWmonitor* p_primary_monitor;
		static GLFWvidmode* p_primary_monitor_info;
		static std::mutex mtx_primary_monitor;
		int buffer_width, buffer_height;

		std::vector<InputHandler*> p_input_handlers;
		std::vector<Camera*> p_cams;
		std::vector<Renderer*> p_renderers;

		bool initialized;

		usize frame;
		int fps;
		double last_frame_time;
		double delta_time;

		usize num_frames_cam_not_updated;
		usize num_frames_input_not_updated;

		FramebufferSizeCallbackFn p_framebuffer_size_callback;
		WindowSizeCallbackFn p_window_size_callback;
		WindowPosCallbackFn p_window_pos_callback;
		FileDropCallbackFn p_file_drop_callback;

		static void framebuffer_size_callback(GLFWwindow* p_glfw_win, int width, int height);
		static void window_size_callback(GLFWwindow* p_glfw_win, int width, int height);
		static void window_pos_callback(GLFWwindow* p_glfw_win, int x, int y);

		static void key_callback(GLFWwindow* p_glfw_win, int key, int scancode, int action, int mods);
		static void mouse_button_callback(GLFWwindow* p_glfw_win, int button, int action, int mods);
		static void cursor_pos_callback(GLFWwindow* p_glfw_win, double x, double y);
		static void scroll_callback(GLFWwindow* p_glfw_win, double dx, double dy);
		static void joystick_callback(int jid, int event);

		static void file_drop_callback(GLFWwindow* p_glfw_win, int count, const char** paths);
	};
}
