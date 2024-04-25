#pragma once

#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Core.h"
#include "Math.h"
#include "InputHandler.h"
#include "Camera.h"
#include "Renderer.h"

namespace Onyx
{
	struct WindowProperties
	{
		/*
			@brief The title of the window.
			This can be changed later with `setTitle()`.
			Default: "Onyx Window"
		 */
		std::string title = "Onyx Window";

		/*
			@brief The width of the window.
			This can be changed later with `setSize()`.
			Default: 800
		 */
		int width = 800;

		/*
			@brief The height of the window.
			This can be changed later with `setSize()`.
			Default: 600
		 */
		int height = 600;

		/*
			@brief The position of the top-left of the window.
            (0, 0) is the top-left of the screen.
			This can be changed later with `setPosition()`.
			Default: (0, 0)
		 */
		Math::IVec2 position = Math::IVec2(0, 0);

		/*
			@brief Whether the window is resizable.
			This can be changed later with `setResizable()` and `toggleResizable()`.
			Default: true
		 */
		bool resizable = true;

		/*
			@brief Whether the window is visible.
			This can be changed later with `hide()`, `show()`, and `toggleVisibility()`.
			Default: true
		 */
		bool visible = true;

		/*
			@brief Whether the window is focused.
			This can be changed later with `focus()`, `unfocus()`, and `toggleFocus()`.
			Default: true
		 */
		bool focused = true;

		/*
			@brief Whether the window is fullscreen.
			This can be changed later with `setFullscreen()` and `toggleFullscreen()`.
			Default: false
		 */
		bool fullscreen = false;

		/*
			@brief Whether the window is decorated (border, close widget, etc.)
			This can be changed later with `setDecorated()` and `toggleDecorated()`.
			Fullscreen borderless can be achieved with setDecorated(false) and maximize().
			Default: true
		 */
		bool decorated = true;

		/*
			@brief Whether the window is topmost (AKA floating, always on top).
			This can be changed later with `setTopmost()` and `toggleTopmost()`.
			Default: false
		 */
		bool topmost = false;

		/*
			@brief Whether to put input focus on the window when it is shown.
			This can be changed later with `setFocusOnShow()` and `toggleFocusOnShow()`.
			Default: true
		 */
		bool focusOnShow = true;

		/*
			@brief The number of samples for multi-sample anti-aliasing.
			This cannot be changed later.
			0 means no anti-aliasing.
			Default: 0
		 */
		int nSamplesMSAA = 0;

		/*
			@brief The opacity of the window (including its decorations).
			This can be changed later with `setOpacity()`.
			Default: 1.0
		 */
		float opacity = 1.0f;

		/*
			@brief The background color of the window.
			This can be changed later with `setBackgroundColor()`.
			Default: Black
		 */
		Math::Vec3 backgroundColor = Math::Vec3::Black();
	};

	/*
		@brief A class to represent a window icon.
	 */
	class WindowIcon : public Disposable
	{
		friend class Window;
	public:
		/*
			@brief Creates an empty window icon.
			Create a window icon with Load().
		 */
		WindowIcon();

		/*
			@brief Creates a window icon from the specified filepaths.
			Multiple filepaths allow for different resolutions, because the automatic scaling sucks.
			Ideally, provide a 16x16, 24x24, 32x32, 48x48, and 256x256 image.
			@param filepaths The filepaths of the images to use as the icon.
		 */
		static WindowIcon Load(const std::initializer_list<std::string>& filepaths);

		/*
			@brief Disposes of the window icon.
			This clears up any memory that the object was using.
			This can be safely called after the icon has been used with Window::setIcon().
		 */
		void dispose() override;

	private:
		GLFWimage* images;
		uint nImages;
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

	public:
		/*
			@brief Creates an uninitialized 800x600 window with the name "Onyx Window"
		 */
		Window();

		/*
			@brief Creates an uninitialized window from the specified window properties.
			@param properties The window properties.
		 */
		Window(WindowProperties properties);

		/*
			@brief Initializes the window.
			This initializes OpenGL, so it must be called before any OpenGL functions.
		 */
		void init();

		/*
			@brief Prepares to render the current frame.
			This function clears the screen to the background color, clears buffers, and polls GLFW events.
		 */
		void startRender();

		/*
			@brief Finishes rendering the current frame.
			This function swaps the buffers of the window.
		 */
		void endRender();

		/*
			@brief Closes the window.
			Once called, isOpen() will return false.
		 */
		void close();

		/*
			@brief Maximizes the window (different from fullscreen).
			Fullscreen borderless can be achieved with setDecorated(false) and maximize().
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
		void requestAttention();

		/*
			@brief Gets the open/closed status of the window.
			@return Whether the window is open.
		 */
		bool isOpen() const;

		/*
			@brief Gets the title of the window.
			@return The title of the window.
		 */
		const std::string& getTitle() const;

		/*
			@brief Gets the width of the window.
			@return The width of the window.
		 */
		int getWidth() const;

		/*
			@brief Gets the height of the window.
			@return The height of the window.
		 */
		int getHeight() const;

		/*
			@brief Gets the width of the rendering frame of the window, not including borders.
			@return The buffer width of the window, explained above.
		 */
		int getBufferWidth() const;

		/*
			@brief Gets the height of the rendering frame of the window, not including borders.
			@return The buffer height of the window, explained above.
		 */
		int getBufferHeight() const;

		/*
			@brief Gets the position of the top-left of the window.
			(0, 0) is the top-left of the screen.
			@return The position of the window.
		 */
		const Math::IVec2& getPosition() const;

		/*
			@brief Gets the current frame number.
			The frame number is increased every time startRender() is called.
			@return The current frame number.
		 */
		int getFrame() const;

		/*
			@brief Gets the current frames per second.
			@return The current frames per second.
		 */
		int getFPS() const;

		/*
			@brief Gets the time since the last frame, in seconds.
			@return The time since the last frame, in seconds.
		 */
		double getDeltaTime() const;

		/*
			@brief Gets the opacity of the window.
			@return The opacity of the window.
		 */
		float getOpacity() const;

		/*
			@brief Gets the background color of the window.
			@return The background color of the window.
		 */
		const Math::Vec3& getBackgroundColor() const;

		/*
			@brief Gets the icon of the window.
			@return The icon of the window.
		 */
		const WindowIcon& getIcon() const;

		/*
			@brief Gets the GLFW window pointer.
			Access to the GLFW window is provided for the library, as well as for advanced users.
			@return A pointer to the GLFW window.
		 */
		GLFWwindow* getGlfwWindowPtr() const;

		/*
			@brief Gets the initialization status of the window.
			@return Whether the window has been initialized.
		 */
		bool isInitialized() const;

		/*
			@brief Gets whether the window is resizable.
			@return Whether the window is resizable.
		 */
		bool isResizable() const;

		/*
			@brief Gets whether the window is visible.
			@return Whether the window is visible.
		 */
		bool isVisible() const;

		/*
			@brief Gets whether the window is hidden.
			@return Whether the window is hidden.
		 */
		bool isHidden() const;

		/*
			@brief Gets whether the window is focused.
			@return Whether the window is focused.
		 */
		bool isFocused() const;

		/*
			@brief Gets whether the window is decorated (border, close widget, etc.)
			@return Whether the window is decorated.
		 */
		bool isDecorated() const;

		/*
			@brief Gets whether the window is topmost (AKA floating, always on top).
			@return Whether the window is topmost.
		 */
		bool isTopmost() const;

		/*
			@brief Gets whether the window automatically becomes input focused when shown.
			@return Whether the window automatically becomes input focused when shown.
		 */
		bool focusesOnShow() const;

		/*
			@brief Gets the number of samples for multi-sample anti-aliasing.
			@return The number of samples for multi-sample anti-aliasing. 0 means no anti-aliasing.
		 */
		int getNSamplesMSAA() const;

		/*
			@brief Gets whether the window is fullscreen.
			@return Whether the window is fullscreen.
		 */
		bool isFullscreen() const;

		/*
			@brief Gets whether the window is maximized.
			@return Whether the window is maximized.
		 */
		bool isMaximized() const;

		/*
			@brief Gets whether the window is minimized.
			@return Whether the window is minimized.
		 */
		bool isMinimized() const;

		/*
			@brief Sets the title of the window.
			@param title The title of the window.
		 */
		void setTitle(const std::string& title);

		/*
			@brief Sets the size of the window.
			@param width The width of the window.
			@param height The height of the window.
		 */
		void setSize(int width, int height);

		/*
			@brief Sets the position of the top-left of the window.
			(0, 0) is the top-left of the screen.
			@param position The position of the window.
		 */
		void setPosition(const Math::IVec2& position);

		/*
			@brief Sets the background color of the window.
			This is what color the window clears to at the start of each frame.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
		 */
		void setBackgroundColor(Onyx::Math::Vec3 rgb);

		/*
			@brief Sets the icon of the window.
			@param icon The icon of the window.
		 */
		void setIcon(const WindowIcon& icon);

		/*
			@brief Sets the opacity of the window, including decorations.
			@param opacity The opacity of the window, ranging from 0 to 1.
		 */
		void setOpacity(float opacity);

		/*
			@brief Sets the window to fullscreen mode.
		 */
		void fullscreen();

		/*
			@brief Sets the window to windowed mode.
			Does not change the width or height if the window was previously fullscreen.
		 */
		void windowed();

		/*
			@brief Sets the window to windowed mode with the specified width, height, and position.
			@param width The width of the window.
			@param height The height of the window.
			@param position The position of the (top-left of the) window.
		 */
		void windowed(int width, int height, Math::IVec2 position = Math::IVec2(0, 0));

		/*
			@brief Toggles between fullscreen and windowed mode.
		 */
		void toggleFullscreen();

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
		void toggleVisibility();

		/*
			@brief Focuses the window.
		 */
		void focus();

		/*
			@brief Unfocuses the window.
		 */
		void unfocus();

		/*
			@brief Toggles focus of the window.
		 */
		void toggleFocus();

		/*
			@brief Sets whether the window is resizable.
			@param resizable Whether the window should be resizable.
		 */
		void setResizable(bool resizable);

		/*
			@brief Toggles whether the window is resizable.
		 */
		void toggleResizable();

		/*
			@brief Sets decoration (border, close widget, etc.) of the window to be enabled/disabled.
			Fullscreen borderless can be achieved with setDecorated(false) and maximize().
			@param decorated Whether decoration should be enabled.
		 */
		void setDecorated(bool decorated);

		/*
			@brief Toggles decoration (border, close widget, etc.) of the window.
		 */
		void toggleDecorated();

		/*
			Sets whether the window is topmost (AKA floating, always on top).
			@param topmost Whether the window should be topmost.
		 */
		void setTopmost(bool topmost);

		/*
			Toggles whether the window is topmost (AKA floating, always on top).
		 */
		void toggleTopmost();

		/*
			@brief Sets whether the window automatically becomes input focused when shown.
			@param focusOnShow Whether the window should be focused when shown.
		 */
		void setFocusOnShow(bool focusOnShow);

		/*
			@brief Toggles whether the window automatically becomes input focused when shown.
		 */
		void toggleFocusOnShow();

		/*
			@brief Disposes of the window.
			This clears up any memory that the object was using.
			This function should be used when the object is no longer needed, such as just before the program ends or the object goes out of scope.
		 */
		void dispose() override;

	private:
		WindowProperties properties;
		WindowIcon icon;

		GLFWwindow* p_glfwWin;
		static GLFWmonitor* p_primaryMonitor;
		static GLFWvidmode* p_primaryMonitorInfo;
		int bufferWidth, bufferHeight;

		InputHandler* p_inputHandler;
		Camera* p_cam;
		Renderer* p_renderer;

		bool initialized;

		int frame;
		int fps;
		double lastFrameTime;
		double deltaTime;

		static void cb_framebufferSize(GLFWwindow* p_window, int width, int height);
		static void cb_windowSize(GLFWwindow* p_window, int width, int height);
		static void cb_windowPos(GLFWwindow* p_window, int x, int y);

		static void cb_key(GLFWwindow* p_window, int key, int scancode, int action, int mods);
		static void cb_mouseButton(GLFWwindow* p_window, int button, int action, int mods);
		static void cb_cursorPos(GLFWwindow* p_window, double x, double y);
		static void cb_scroll(GLFWwindow* p_window, double dx, double dy);
	};
}
