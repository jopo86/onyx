#pragma once

#include <vector>

#include "Core.h"
#include "Renderable.h"
#include "Camera.h"

namespace Onyx
{
	/*
	 * @brief A class to represent a renderer.
	 * This class contains renderables, and renders all of them when render() is called.
	 * The benefits of this class are that renderables can be shown/hidden,
	 * and there is also an optimization function that will significantly speed up rendering large scenes.
	 * This class is disposable.
	 */
	class Renderer : public Disposable
	{
	public:
		/*
		 * @brief Creates a new Renderer object containing no renderables or camera.
		 */
		Renderer();

		/*
		 * @brief Creates a new Renderer object containing no renderables and the specified camera.
		 * @param cam The camera to use.
		 */
		Renderer(Camera& cam);

		/*
		 * @brief Renders all of the renderables contained by the renderer.
		 * Does not render any renderables that have been hidden by hide().
		 */
		void render();

		/*
		 * @brief Adds a renderable to the renderer.
		 * Note that renderables cannot be removed once added, instead use hide().
		 */
		void add(Renderable& renderable);

		/*
		 * @brief Enables rendering for the renderable at the specified index.
		 * The first renderable added has index 0, the next 1, and so on.
		 */
		void show(int index);

		/*
		 * @brief Disables rendering for the renderable at the specified index.
		 * The first renderable added has index 0, the next 1, and so on.
		 */
		void hide(int index);

		/*
		 * @brief Toggles the visibility (shows/hides) the renderable at the specified index.
		 * The first renderable added has index 0, the next 1, and so on.
		 */
		void toggleVisibility(int index);

		/*
		 * @brief Enables wireframe rendering mode.
		 * In wireframe mode, only the lines between vertices are drawn.
		 * Change the with of the lines with SetLineWidth().
		 */
		static void EnableWireframe();

		/*
		 * @brief Disables wireframe rendering mode.
		 * In wireframe mode, only the lines between vertices are drawn.
		 * Change the with of the lines with SetLineWidth().
		 */
		static void DisableWireframe();

		/*
		 * @brief Toggles wireframe rendering mode.
		 * In wireframe mode, only the lines between vertices are drawn.
		 * Change the with of the lines with SetLineWidth().
		 */
		static void ToggleWireframe();

		/*
		 * @brief Gets whether wireframe rendering mode is enabled.
		 * In wireframe mode, only the lines between vertices are drawn.
		 * Change the with of the lines with SetLineWidth().
		 */
		static bool IsWireframe();

		/*
		 * @brief Sets the width of lines rendered in wireframe mode.
		 * @param width The width of the lines in pixels. Set to 1 by default.
		 */
		static void SetLineWidth(float width);

		/*
		 * @brief Gets the width of lines rendered in wireframe mode.
		 * @return The width of the lines, in pixels. Set to 1 by default.
		 */
		static float GetLineWidth();

		/*
		 * @brief Disposes of the renderer, including all of the contained renderables.
		 * This clears up any memory that the object was using.
		 * This function should be used when the object is no longer needed, such as just before the program ends or the object goes out of scope.
		 */
		void dispose() override;

	private:
		std::vector<std::pair<Renderable*, bool>> renderables;
		Camera* cam;

		static bool wireframe;
		static float lineWidth;
	};
}
