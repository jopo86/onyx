#pragma once

#include <vector>

#include "Core.h"
#include "Window.h"
#include "Camera.h"
#include "Lighting.h"
#include "Renderable.h"
#include "ModelRenderable.h"
#include "UiRenderable.h"
#include "TextRenderable.h"

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
		friend class Lighting;

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
			@brief Creates a new Renderer object containing no renderables and the specified camera and lighting settings.
			Links the renderer to the window so that UI elements are rendered properly.
			@param window The window to link to.
			@param cam The camera to use.
			@param lighting The lighting settings to use.
		 */
		Renderer(Window& window, Camera& cam, Lighting& lighting);

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
		void add(ModelRenderable& modelRenderable);

		/*
			@brief Adds a UI renderable to the renderer.
			Note that renderables cannot be removed once added, instead use hide().
		 */
		void add(UiRenderable& uiRenderable);

		/*
            @brief Adds a text renderable to the renderer.
            Note that renderables cannot be removed once added, instead use hide().
         */
		void add(TextRenderable& textRenderable);

		/*
			@brief Gets whether lighting is enabled for the renderer.
			@return True if lighting is enabled, false if not.
		 */
		bool isLightingEnabled() const;

		/*
			@brief Sets whether lighting is enabled for the renderer.
			@param enabled True to enable lighting, false to disable.
		 */
		void setLightingEnabled(bool enabled);

		/*
			@brief Toggles whether lighting is enabled for the renderer.
		 */
		void toggleLightingEnabled();

		/*
			@brief Gets the lighting settings for the renderer.
			@return A pointer to the lighting settings.
		 */
		const Lighting& getLighting() const;

		/*
			@brief Sets the lighting settings for the renderer.
			@param lighting The lighting settings to use.
		 */
		void setLighting(Lighting& lighting);

		/*
			@brief Refreshes the lighting variables in the shaders of all renderables contained in the renderer.
			This needs to be called if the lighting values are changed after an object has been added to the renderer.
		 */
		void refreshLighting();

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
		std::vector<Renderable*> m_renderables;
		std::vector<UiRenderable*> m_uiRenderables;
		std::vector<TextRenderable*> m_textRenderables;

		Camera* m_pCam;
		Lighting* m_pLighting;
		Math::Mat4 m_ortho;
		
		bool m_lightingEnabled;
		static bool sm_wireframe;
		static bool sm_uiWireframeAllowed;
		static float sm_lineWidth;
	};
}
