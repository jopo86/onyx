#pragma once

#include "Core.h"
#include "Math.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Font.h"
#include "ShaderPresets.h"

namespace Onyx
{
	/*
		@brief A class that represents a renderable UI object.
		A renderable can be rendered directly, or through the MgRenderer class.
		This class is disposable.
	 */
	class UiRenderable : public Disposable
	{
	public:
		/*
			@brief Creates an empty UiRenderable object.
			Trying to use a renderable constructed like this will most likely cause errors.
		 */
		UiRenderable();

		/*
			@brief Creates a new UiRenderable object out of the specified mesh and color.
			@param mesh The mesh to use.
			@param rgba The color, specified as red, green, and blue values ranging from 0 to 1.
		 */
		UiRenderable(Mesh mesh, Math::Vec3 rgb);

		/*
			@brief Creates a new UiRenderable object out of the specified mesh and color.
			@param mesh The mesh to use.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
		 */
		UiRenderable(Mesh mesh, Math::Vec4 rgba);

		/*
			@brief Creates a new UiRenderable object out of the specified mesh and texture.
			The mesh vertex array should be VT or TV format.
			@param mesh The mesh to use.
			@param texture The texture to use.
		 */
		UiRenderable(Mesh mesh, Texture texture);

		/*
			@brief Renders the object.
			This function, more technically, uses the shader, binds the texture, binds the VAO, draws, unbinds the VAO, unbinds the texture, and unuses the shader.
		 */
		void render();

		/*
			@brief Renders the object and updates the orthographic projection matrix.
			This function, more technically, uses the shader, binds the texture, binds the VAO, draws, unbinds the VAO, unbinds the texture, and unuses the shader.
			@param ortho The orthographic projection matrix to use.
		 */
		void render(Math::Mat4 ortho);

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
			@brief Changes the renderable's position by the specified 2D vector.
			Note that this function inc/decrements the renderable's position, it does not set it.
			Directly setting a transform is not natively supported, that would be up to the user to program.
			@param xy The vector to move by.
		 */
		void translate(Onyx::Math::Vec2 xy);

		/*
			@brief Rotates the renderable by the specified degree angle.
			Note that this function inc/decrements the renderable's rotation, it does not set it.
			Directly setting a transform is not natively supported, that would be up to the user to program.
			@param degrees The degree angle to rotate.
		 */
		void rotate(float degrees);

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
			@param xyScalar The scalars for each dimension. Here are some examples:
			(1, 1) will not change anything.
			(1, 0.5) will half the renderable's size on the y axis.
			(2, 0.5) will double the renderable's size on the x axis and half it on the y axis.
			If any scalar is 0, it will effectively hide the renderable.
		 */
		void scale(Onyx::Math::Vec2 xyScalar);

		/*
			@brief Resets the renderable's transforms.
			This resets its position to its original vertex positions, its rotation to 0, and its scale to 1.
		 */
		void resetTransform();

		/*
			@brief Gets the mesh associated with the renderable.
			@return The mesh.
		 */
		Mesh getMesh() const;

		/*
			@brief Gets the shader associated with the renderable.
			@return The shader.
		 */
		Shader getShader() const;

		/*
			@brief Gets the texture associated with the renderable.
			@return The texture.
		 */
		Texture getTexture() const;

		/*
			@brief Gets whether the renderable is hidden.
			See hide() and show() for more info.
			@return Whether the renderable is hidden.
		 */
		bool isHidden() const;

		/*
			@brief Disposes of the renderable, including the associated mesh, shader, and texture.
			This clears up any memory that the object was using.
			This function should be used when the object is no longer needed, such as just before the program ends or the object goes out of scope.
		 */
		void dispose() override;

	private:
		Mesh mesh;
		Shader shader;
		Texture texture;

		Math::Mat4 model;

		bool hidden;
	};
}
