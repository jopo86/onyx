#pragma once

#include "Core.h"
#include "Math.h"
#include "Mesh.h"
#include "Texture.h"
#include "Shader.h"

namespace Onyx
{
	/*
		@brief A class that represents a renderable UI object.
		A renderable can be rendered directly, or through the Renderer class.
		This class is disposable.
	 */
	class UiRenderable : public Disposable
	{
	public:
		/*
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
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
			@param result A pointer to a boolean that will be set to true if the renderable was created successfully, and false otherwise.
		 */
		UiRenderable(Mesh mesh, Texture texture, bool* result = nullptr);

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
			@brief Gets the position of the renderable.
			@return The position.
		 */
		const Math::Vec2& getPosition() const;

		/*
			@brief Gets the rotation of the renderable.
			@return The rotation around each axis.
		 */
		float getRotation() const;

		/*
			@brief Gets the scale of the renderable.
			@return The scale for each axis.
		 */
		const Math::Vec2& getScale() const;

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
			@brief Sets the position of the renderable.
			@param position The new position.
		 */
		void setPosition(const Math::Vec2& position);

		/*
			@brief Sets the rotation of the renderable.
			@param rotation The new rotation.
		 */
		void setRotation(float rotation);

		/*
			@brief Sets the scale of the renderable.
			@param scales The new scale for each axis.
		 */
		void setScale(const Math::Vec2& scale);

		/*
			@brief Translates the renderable by the specified positional amount.
			This function does not set the position, it adds to it.
			The translation is in world space, not local space, so rotation will not affect the translation.
			@param translation The positional amount to translate by.
		 */
		void translate(const Math::Vec2& translation);

		/*
			@brief Translate the renderable by the specified positional amount in local space.
			This function does not set the position, it adds to it.
			The translation is in local space, not world space, so rotation will affect the translation.
			@param translation The positional amount to translate by.
		 */
		void translateLocal(const Math::Vec2& translation);

		/*
			@brief Rotates the renderable by the specified rotation amounts.
			This function does not set the rotation, it adds to it.
			@param rotations The rotation amounts around each axis.
		 */
		void rotate(float rotation);

		/*
			@brief Scales the renderable by the specified scalar amounts.
			This function does not set the scale, it multiplies it.
			@param scalars The scalar amounts for each axis.
		 */
		void scale(const Math::Vec2& scalars);

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
			@brief Destroys the object, freeing any used memory.
			Do not use the object after this is called.
		 */
		void dispose() override;

	private:
		Mesh m_mesh;
		Shader m_shader;
		Texture m_texture;

		Math::Mat4 m_model;

		Math::Vec2 m_position;
		float m_rotation;
		Math::Vec2 m_scale;

		bool m_hidden;

		void updateModel();
	};
}
