#pragma once

#include <vector>

#include "Core.h"
#include "Math.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

namespace Onyx
{
	/*
		@brief A class that represents a renderable object.
		A renderable can be rendered directly, or through the Renderer class.
		This class is disposable.
	 */
	class Renderable : public Disposable
	{
	public:
		/*
			@brief Creates an empty Renderable object.
			Trying to use a renderable constructed like this will most likely cause errors.
		 */
		Renderable();

		/*
			@brief Creates a new Renderable object out of the specified mesh.
			@param mesh The mesh to use.
		 */
		Renderable(Mesh mesh);

		/*
			@brief Creates a new Renderable object out of the specified mesh and shader.
			@param mesh The mesh to use.
			@param shader The shader to use.
		 */
		Renderable(Mesh mesh, Shader shader);

		/*
			@brief Creates a new Renderable object out of the specified mesh, shader, and texture.
			@param mesh The mesh to use.
			@param shader The shader to use.
			@param texture The texture to use.
		 */
		Renderable(Mesh mesh, Shader shader, Texture texture);

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
		void render(Onyx::Math::Mat4 view, Onyx::Math::Mat4 proj);

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
		void translate(Onyx::Math::Vec3 xyz);

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
		void rotate(float degrees, Onyx::Math::Vec3 mask);

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
		void scale(Onyx::Math::Vec3 xyzScalar);

		/*
			@brief Resets the renderable's transforms.
			This resets its position to its original vertex positions, its rotation to 0, and its scale to 1.
		 */
		void resetTransform();

		/*
			@brief Gets the mesh associated with the renderable.
			@return A pointer to the mesh.
		 */
		Mesh* getMesh();

		/*
			@brief Gets the shader associated with the renderable.
			@return A pointer to the shader.
		 */
		Shader* getShader();

		/*
			@brief Gets the texture associated with the renderable.
			@return A pointer to the texture.
		 */
		Texture* getTexture();

		/*
			@brief Gets the model matrix of the renderable.
			@return The model matrix.
		 */
		const Onyx::Math::Mat4& getModel() const;

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

		Onyx::Math::Mat4 model;
		Onyx::Math::Mat4 inverseModel;

		bool hidden;
	};
}
