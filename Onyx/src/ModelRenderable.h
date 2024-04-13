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
			@brief Changes the renderable's position by the specified 3D vector.
			Note that this function inc/decrements the renderable's position, it does not set it.
			Directly setting a transform is not natively supported, that would be up to the user to program.
			@param xyz The vector to move by.
		 */
		void translate(const Onyx::Math::Vec3& xyz);

		/*
			@brief Rotates the renderable by the specified degree angle around the specified axes.
			Note that this function inc/decrements the renderable's rotation, it does not set it.
			Directly setting a transform is not natively supported, that would be up to the user to program.
			@param degrees The degree angle to rotate.
			@param mask Specifies the axes to rotate around. Here are some examples:
			(1, 0, 0) will rotate the specified angle around the x axis only.
			(0, 1, 0) will rotate the specified angle around the y axis only.
			(0, 0, 1) will rotate the specified angle around the z axis only.
			(1, 1, 1) will rotate the specified angle around all axes.
			Numbers below 0 are treated as 0 and any other number is treated as 1.
		 */
		void rotate(float degrees, const Onyx::Math::Vec3& mask);

		/*
			@brief Scales the renderable in all dimensions by the specified scalar.
			Note that this function scales the renderable by whatever its current scale is, it does not set its scale.
			This means that scale(1) will not reset the renderable's scale, it just wont change it at all.
			Directly setting a transform is not natively supported, that would be up to the user to program.
			@param scalar The scale multiplier.
			If the scalar is 0, it will effectively hide the renderable.
		 */
		void scale(float scalar);

		/*
			@brief Scales the renderable by the scalars for each dimension.
			Note that this function scales the renderable by whatever its current scale is, it does not set its scale.
			This means that scale(1) will not reset the renderable's scale, it just wont change it at all.
			Directly setting a transform is not natively supported, that would be up to the user to program.
			@param xyzScalar The scalars for each dimension. Here are some examples:
			(1, 1, 1) will not change anything.
			(1, 0.5, 1) will half the renderable's size on the y axis.
			(0.5, 0.5, 2) will half the renderable's size on the x and y axes, and double it's size on the z axis.
			If any scalar is 0, it will effectively hide the renderable.
		 */
		void scale(const Onyx::Math::Vec3& xyzScalar);

		/*
			@brief Resets the renderable's transforms.
			This resets its position to its original vertex positions, its rotation to 0, and its scale to 1.
		 */
		void resetTransform();

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
			@brief Disposes of all of the renderables contained within the ModelRenderable.
		 */
		void dispose() override;
        
    private:
		std::map<std::string, Renderable> renderableMap;

        bool hidden;
    };
}
