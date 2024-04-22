#pragma once

#include <map>

#include "Core.h"
#include "Model.h"
#include "Renderable.h"

namespace Onyx
{
    class ModelRenderable : Disposable
    {
		friend class Renderer;
    public:

        ModelRenderable();

        ModelRenderable(Model& model);

		/*
			@brief Renders the object.
			This function, more technically, uses the shader, binds the texture, binds the VAO, draws, unbinds the VAO, unbinds the texture, and unuses the shader.
		 */
		void render();

		/*
			@brief Renders the object using the specified view and projection matrices.
			This function, more technically, uses the shader, binds the texture, binds the VAO, draws, unbinds the VAO, unbinds the texture, and unuses the shader.
			@param view The view matrix to use, generally from an Camera.
			@param proj The projection matrix to use, generally from an Camera.
		 */
		void render(const Onyx::Math::Mat4& view, const Onyx::Math::Mat4& proj);

		/*
			@brief Hides the renderable.
			This function simply makes render() no longer do anything.
		 */
		void hide();

		/*
			@brief Shows the renderable.
			This function simply makes render() do what it's supposed to.
		 */
		void show();

		/*
			@brief Toggles the visibility of the renderable.
			See hide() and show() for more info.
		 */
		void toggleVisibility();

		/*
			@brief Gets all of the model's renderables.
			@return A vector of the model's renderables.
		 */
		const std::map<std::string, Renderable>& getRenderables() const;

		/*
			@brief Gets the renderable with the specified name.
			@return The renderable, by reference.
		 */
		Renderable& getRenderable(std::string name);

		/*
			@brief Gets the position of the renderable.
			@return The position.
		 */
		const Onyx::Math::Vec3& getPosition() const;

		/*
			@brief Gets the rotation of the renderable.
			@return The rotation around each axis.
		 */
		const Onyx::Math::Vec3& getRotation() const;

		/*
			@brief Gets the scale of the renderable.
			@return The scale for each axis.
		 */
		const Onyx::Math::Vec3& getScale() const;

		/*
			@brief Sets the position of the renderable.
			@param position The new position.
		 */
		void setPosition(const Onyx::Math::Vec3& position);

		/*
			@brief Sets the rotation of the renderable.
			@param rotations The new rotation around each axis.
		 */
		void setRotation(const Onyx::Math::Vec3& rotations);

		/*
			@brief Sets the scale of the renderable.
			@param scales The new scale for each axis.
		 */
		void setScale(const Onyx::Math::Vec3& scales);

		/*
			@brief Translates the renderable by the specified positional amount.
			This function does not set the position, it adds to it.
			The translation is in world space, not local space, so rotation will not affect the translation.
			@param translation The positional amount to translate by.
		 */
		void translate(const Onyx::Math::Vec3& translation);

		/*
			@brief Translate the renderable by the specified positional amount in local space.
			This function does not set the position, it adds to it.
			The translation is in local space, not world space, so rotation will affect the translation.
			@param translation The positional amount to translate by.
		 */
		void translateLocal(const Onyx::Math::Vec3& translation);

		/*
			@brief Rotates the renderable by the specified rotation amounts.
			This function does not set the rotation, it adds to it.
			@param rotations The rotation amounts around each axis.
		 */
		void rotate(const Onyx::Math::Vec3& rotations);

		/*
			@brief Scales the renderable by the specified scalar amounts.
			This function does not set the scale, it multiplies it.
			@param scalars The scalar amounts for each axis.
		 */
		void scale(const Onyx::Math::Vec3& scalars);

		/*
			@brief Scales the renderable on all axes by the specified scalar amount.
			This function does not set the scale, it multiplies it.
			@param scalar The scalar amount for all axes.
		 */
		void scale(float scalar);

		/*
			@brief Resets the renderable's transform.
		 */
		void resetTransform();

		/*
			@brief Disposes of all of the renderables contained within the ModelRenderable.
		 */
		void dispose() override;
        
    private:
		std::map<std::string, Renderable> renderableMap;

        bool hidden;
    };
}
