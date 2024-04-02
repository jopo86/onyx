#pragma once

#include <vector>

#include "Core.h"
#include "Renderable.h"
#include "UiRenderable.h"
#include "Camera.h"
#include "Projection.h"
#include "Window.h"

namespace Onyx
{
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

	public:
		/*
			@brief Creates a new Renderer object containing no renderables or camera.
		 */
		Renderer();

		/*
			@brief Creates a new Renderer object containing no renderables or camera.
			Links the renderer to the window so that UI elements are rendered properly.
			@param window The window to link to.
		 */
		Renderer(Window& window);

		/*
			@brief Creates a new Renderer object containing no renderables and the specified camera.
			Links the renderer to the window so that UI elements are rendered properly.
			@param window The window to link to.
			@param cam The camera to use.
		 */
		Renderer(Window& window, Camera& cam);

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
			@brief Adds a UI renderable to the renderer.
			Note that renderables cannot be removed once added, instead use hide().
		 */
		void add(UiRenderable& uiRenderable);

		/*
			@brief Sets whether wireframe rendering mode is enabled.
			In wireframe mode, only the lines between vertices are drawn.
			Change the with of the lines with SetLineWidth().
			@param wireframe True to enable wireframe mode, false to disable.
		 */
		static void SetWireframe(bool wireframe);

		/*
			@brief By default, UI elements are never rendered in wireframe mode, regardless of the wireframe setting.
			This function allows you to override this behaviour and render UI elements in wireframe mode if wireframe is enabled.
		 */
		static void SetUiWireframeAllowed(bool allowed);

		/*
			@brief Toggles wireframe rendering mode.
			In wireframe mode, only the lines between vertices are drawn.
			Change the with of the lines with SetLineWidth().
		 */
		static void ToggleWireframe();

		/*
			@brief By default, UI elements are never rendered in wireframe mode, regardless of the wireframe setting.
			This function allows you to override this behaviour and render UI elements in wireframe mode if wireframe is enabled.
		 */
		static void ToggleUiWireframeAllowed();

		/*
			@brief Gets whether wireframe rendering mode is enabled.
			In wireframe mode, only the lines between vertices are drawn.
			Change the with of the lines with SetLineWidth().
		 */
		static bool IsWireframe();

		/*
			@brief Gets whether UI elements are allowed to be rendered in wireframe mode.
			See SetUiWireframeAllowed() for more info.
		 */
		static bool IsUiWireframeAllowed();

		/*
			@brief Sets the width of lines rendered in wireframe mode.
			@param width The width of the lines in pixels. Set to 1 by default.
		 */
		static void SetLineWidth(float width);

		/*
			@brief Gets the width of lines rendered in wireframe mode.
			@return The width of the lines, in pixels. Set to 1 by default.
		 */
		static float GetLineWidth();

		/*
			@brief Disposes of the renderer, including all of the contained renderables.
			This clears up any memory that the object was using.
			This function should be used when the object is no longer needed, such as just before the program ends or the object goes out of scope.
		 */
		void dispose() override;

	private:
		std::vector<Renderable*> renderables;
		std::vector<UiRenderable*> uiRenderables;

		Camera* cam;
		Math::Mat4 ortho;

		static bool wireframe;
		static bool uiWireframeAllowed;
		static float lineWidth;
	};
}
