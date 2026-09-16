#pragma once

#include <vector>
#include <mutex>

#include "core.h"
#include "lighting.h"
#include "fog.h"
#include "renderable.h"
#include "model_renderable.h"
#include "ui_renderable.h"
#include "text_renderable.h"
#include "text_renderable_3d.h"

namespace onyx
{
	class Camera;
	class Window;

	/*
		@brief A class to represent a renderer.
		This class contains renderables, and renders all of them when render() is called.
		The benefits of this class are that renderables can be shown/hidden,
		and there is also an optimization function that will significantly speed up rendering large scenes.
		This class is disposable.
	 */
	class Renderer : public Disposable
	{
		friend class Camera;
		friend class Window;
		friend class Lighting;

	public:
		/*
			@brief Creates a new Renderer object containing no renderables or camera.
		 !  MUST BE LINKED TO A WINDOW TO RENDER UI PROPERLY
		 !  Use `Window::link_renderer()`
		 */
		Renderer();

		/*
			@brief Creates a new Renderer object containing no renderables and the specified camera.
		 !  MUST BE LINKED TO A WINDOW TO RENDER UI PROPERLY
		 !  Use `Window::link_renderer()`
			@param window The window to link to.
			@param cam The camera to use.
		 */
		Renderer(Camera& cam);

		/*
			@brief Creates a new Renderer object containing no renderables and the specified camera and lighting settings.
		 !  MUST BE LINKED TO A WINDOW TO RENDER UI PROPERLY
		 !  Use `Window::link_renderer()`
			@param window The window to link to.
			@param cam The camera to use.
			@param lighting The lighting settings to use.
		 */
		Renderer(Camera& cam, Lighting& lighting);

		/*
			@brief Creates a new Renderer object containing no renderables and the specified camera and fog settings.
		 !  MUST BE LINKED TO A WINDOW TO RENDER UI PROPERLY
		 !	Use `Window::link_renderer()`
			@param window The window to link to.
			@param cam The camera to use.
			@param fog The fog settings to use.
		 */
		Renderer(Camera& cam, Fog& fog);

		/*
			@brief Creates a new Renderer object containing no renderables and the specified camera, lighting settings, and fog settings.
			!  MUST BE LINKED TO A WINDOW TO RENDER UI PROPERLY
			!	Use `Window::link_renderer()`
			@param window The window to link to.
			@param cam The camera to use.
			@param lighting The lighting settings to use.
			@param fog The fog settings to use.
		 */
		Renderer(Camera& cam, Lighting& lighting, Fog& fog);

		/*
			@brief Renders all of the renderables contained by the renderer.
			Does not render any renderables that have been hidden by hide().
		 */
		void render();

		/*
			@brief Adds a renderable to the renderer.
			Note that renderables cannot be removed once added, instead use hide().
		 */
		void add(Renderable& renderable);

		/*
			@brief Adds a model renderable to the renderer.
			Note that renderables cannot be removed once added, instead use hide().
		 */
		void add(ModelRenderable& model_renderable);

		/*
			@brief Adds a UI renderable to the renderer.
			Note that renderables cannot be removed once added, instead use hide().
		 */
		void add(UiRenderable& ui_renderable);

		/*
			@brief Adds a text renderable to the renderer.
			Note that renderables cannot be removed once added, instead use hide().
		 */
		void add(TextRenderable& text_renderable);

		/*
			@brief Adds a 3D text renderable to the renderer.
			Note that renderables cannot be removed once added, instead use hide().
		 */
		void add(TextRenderable3D& text_renderable_3d);

		/*
			@brief Clears (but does not dispose of) all types of renderables from the renderer.
		 */
		void clear();

		/*
			@brief Clears (but does not dispose of) all standard renderables from the renderer.
			Does not clear UI renderables, text renderables, or 3D text renderables.
		 */
		void clear_renderables();

		/*
			@brief Clears (but does not dispose of) all UI renderables from the renderer.
			Does not clear standard renderables, text renderables, or 3D text renderables.
		 */
		void clear_ui_renderables();

		/*
			@brief Clears (but does not dispose of) all text renderables from the renderer.
			Does not clear standard renderables, UI renderables, or 3D text renderables.
		 */
		void clear_text_renderables();

		/*
			@brief Clears (but does not dispose of) all 3D text renderables from the renderer.
			Does not clear standard renderables, UI renderables, or text renderables.
		 */
		void clear_text_renderables3_d();

		/*
			@brief Gets whether lighting is enabled for the renderer.
			@return True if lighting is enabled, false if not.
		 */
		bool is_lighting_enabled() const;

		/*
			@brief Gets whether fog is enabled for the renderer.
			@return True if fog is enabled, false if not.
		 */
		bool is_fog_enabled() const;

		/*
			@brief Sets whether lighting is enabled for the renderer.
			@param enabled True to enable lighting, false to disable.
		 */
		void set_lighting_enabled(bool enabled);

		/*
			@brief Sets whether fog is enabled for the renderer.
			@param enabled True to enable fog, false to disable.
		 */
		void set_fog_enabled(bool enabled);

		/*
			@brief Toggles whether lighting is enabled for the renderer.
		 */
		void toggle_lighting_enabled();

		/*
			@brief Toggles whether fog is enabled for the renderer.
		 */
		void toggle_fog_enabled();

		/*
			@brief Gets the lighting settings for the renderer.
			@return A pointer to the lighting settings.
		 */
		const Lighting& get_lighting() const;

		/*
			@brief Gets the fog settings for the renderer.
			@return A pointer to the fog settings.
		 */
		const Fog& get_fog() const;

		/*
			@brief Sets the lighting settings for the renderer.
			@param lighting The lighting settings to use.
		 */
		void set_lighting(Lighting& lighting);

		/*
			@brief Sets the fog settings for the renderer.
			@param fog The fog settings to use.
		 */
		void set_fog(Fog& fog);

		/*
			@brief Refreshes the lighting variables in the shaders of all renderables contained in the renderer.
			This needs to be called if the lighting values are changed after an object has been added to the renderer.
		 */
		void refresh_lighting();

		/*
			@brief Refreshes the fog variables in the shaders of all renderables contained in the renderer.
			This needs to be called if the fog values are changed after an object has been added to the renderer.
		 */
		void refresh_fog();

		/*
			@brief Gets the standard renderables contained in the renderer.
			@return A vector containing pointers to all standard renderables.
		 */
		const std::vector<Renderable*>& get_renderables() const;

		/*
			@brief Gets the UI renderables contained in the renderer.
			@return A vector containing pointers to all UI renderables.
		 */
		const std::vector<UiRenderable*>& get_ui_renderables() const;

		/*
			@brief Gets the text renderables contained in the renderer.
			@return A vector containing pointers to all text renderables.
		 */
		const std::vector<TextRenderable*>& get_text_renderables() const;

		/*
			@brief Gets the 3D text renderables contained in the renderer.
			@return A vector containing pointers to all 3D text renderables.
		 */
		const std::vector<TextRenderable3D*>& get_text_renderables_3d() const;

		/*
			@brief Gets the camera used by the renderer.
			@return A reference to the camera.
		 */
		const Camera& get_camera() const;

		/*
			@brief Sets the camera used by the renderer.
			@param cam The camera to use.
		 */
		void set_camera(Camera& cam);

		/*
			@brief Sets whether to use the camera for UI elements.
			By default, UI elements are rendered without regard to the camera, which is ideal for HUDs.
			Note that, if true, part of the matrix multiplication will be done on the CPU for each UI element, not the GPU, which may be slow.
			@param use_cam_for_ui Whether to use the camera for UI elements.
		 */
		void set_use_camera_for_ui(bool use_cam_for_ui);

		/*
			@brief Gets whether the camera is used for UI elements.
			By default, UI elements are rendered without regard to the camera, which is ideal for HUDs.
			Note that, if true, part of the matrix multiplication will be done on the CPU for each UI element, not the GPU, which may be slow.
			@return True if the camera is used for UI elements, false if not.
		 */
		bool is_using_camera_for_ui() const;

		/*
			@brief Sets whether wireframe rendering mode is enabled.
			In wireframe mode, only the lines between vertices are drawn.
			Change the with of the lines with set_line_width().
			@param wireframe True to enable wireframe mode, false to disable.
		 */
		static void set_wireframe(bool wireframe);

		/*
			@brief By default, UI elements are never rendered in wireframe mode, regardless of the wireframe setting.
			This function allows you to override this behaviour and render UI elements in wireframe mode if wireframe is enabled.
		 */
		static void set_ui_wireframe_allowed(bool allowed);

		/*
			@brief Toggles wireframe rendering mode.
			In wireframe mode, only the lines between vertices are drawn.
			Change the with of the lines with set_line_width().
		 */
		static void toggle_wireframe();

		/*
			@brief By default, UI elements are never rendered in wireframe mode, regardless of the wireframe setting.
			This function allows you to override this behaviour and render UI elements in wireframe mode if wireframe is enabled.
		 */
		static void toggle_ui_wireframe_allowed();

		/*
			@brief Sets the VSync (Vertical Synchronization) settings.
			VSync helps prevent screen tearing by synchronizing the frame rate with the monitor's refresh rate.
			However, it can increase input lag.
		 *	It is recommended for VSync and FPS limit to be mutually exclusive, as they can conflict.
			@param enabled Whether VSync is enabled.
			@param interval The swap interval, default is 1.
			1: VSync enabled, frame rate locked to monitor refresh rate.
			2: VSync enabled, frame rate locked to 1/2 the monitor refresh rate.
			3: VSync enabled, frame rate locked to 1/3 the monitor refresh rate.
			4: VSync enabled, frame rate locked to 1/4 the monitor refresh rate.
			You get the idea.
		 */
		static void set_vsync(bool enabled, int interval = 1);

		/*
			@brief Toggles whether VSync (Vertical Synchronization) is enabled.
			VSync helps prevent screen tearing by synchronizing the frame rate with the monitor's refresh rate.
			However, it can increase input lag.
		 *	It is recommended for VSync and FPS limit to be mutually exclusive, as they can conflict.
			See `set_vsync()` for more info.
		 */
		static void toggle_vsync_enabled();

		/*
			@brief Sets the frame rate limit settings.
		 *	It is recommended for VSync and FPS limit to be mutually exclusive, as they can conflict.
			@param enabled Whether to limit the frame rate.
			@param target_fps The target frame rate to limit to. Default is 60.
		 */
		static void set_fps_limit(bool enabled, int target_fps = 60);

		/*
			@brief Toggles whether to limit the frame rate.
		 *	It is recommended for VSync and FPS limit to be mutually exclusive, as they can conflict.
			See `set_fps_limit()` for more info.
		 */
		static void toggle_fps_limit_enabled();

		/*
			@brief Gets whether wireframe rendering mode is enabled.
			In wireframe mode, only the lines between vertices are drawn.
			Change the with of the lines with set_line_width().
		 */
		static bool is_wireframe();

		/*
			@brief Gets whether UI elements are allowed to be rendered in wireframe mode.
			See set_ui_wireframe_allowed() for more info.
		 */
		static bool is_ui_wireframe_allowed();

		/*
			@brief Gets the VSync (Vertical Synchronization) settings.
			VSync helps prevent screen tearing by synchronizing the frame rate with the monitor's refresh rate.
			However, it can increase input lag.
			@return A pair containing 1) whether VSync is enabled and 2) the swap interval.
			See `set_vsync()` for swap interval info.
		 */
		static std::pair<bool, int> get_vsync();

		/*
			@brief Gets the frame rate limit settings.
			@return A pair containing 1) whether the frame rate is limited and 2) the target frame rate.
		 */
		static std::pair<bool, int> get_fps_limit();

		/*
			@brief Sets the width of lines rendered in wireframe mode.
			@param width The width of the lines in pixels. Set to 1 by default.
		 */
		static void set_line_width(float width);

		/*
			@brief Gets the width of lines rendered in wireframe mode.
			@return The width of the lines, in pixels. Set to 1 by default.
		 */
		static float get_line_width();

		void dispose() override;

	private:

		std::vector<Renderable*> renderables;
		std::vector<UiRenderable*> ui_renderables;
		std::vector<TextRenderable*> text_renderables;
		std::vector<TextRenderable3D*> text_renderables_3d;

		Window* p_win;
		Camera* p_cam;
		Lighting* p_lighting;
		Fog* p_fog;
		math::Mat4 ortho;

		bool use_cam_for_ui;

		bool lighting_enabled;
		bool fog_enabled;

		static bool wireframe;
		static bool ui_wireframe_allowed;
		static float line_width;
		static std::pair<bool, int> vsync;
		static std::pair<bool, int> fps_limit;

		static std::recursive_mutex mtx_wireframe;
		static std::recursive_mutex mtx_ui_wireframe_allowed;
		static std::recursive_mutex mtx_line_width;
		static std::recursive_mutex mtx_vsync;
		static std::recursive_mutex mtx_fps_limit;
	};
}
