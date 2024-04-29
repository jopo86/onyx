#pragma once

#include "Core.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

namespace Onyx
{
	/*
		@brief A class that represents a renderable object.
	 */
	class Renderable : public Disposable
	{
	public:
		/*
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
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
		void render(const Math::Mat4& view, const Math::Mat4& proj);

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
		const Math::Vec3& getPosition() const;

		/*
			@brief Gets the rotation of the renderable.
			@return The rotation around each axis.
		 */
		const Math::Vec3& getRotation() const;

		/*
			@brief Gets the scale of the renderable.
			@return The scale for each axis.
		 */
		const Math::Vec3& getScale() const;

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
		const Math::Mat4& getModel() const;

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
		void setPosition(const Math::Vec3& position);

		/*
			@brief Sets the rotation of the renderable.
			@param rotations The new rotation around each axis.
		 */
		void setRotation(const Math::Vec3& rotations);

		/*
			@brief Sets the scale of the renderable.
			@param scales The new scale for each axis.
		 */
		void setScale(const Math::Vec3& scales);

		/*
			@brief Translates the renderable by the specified positional amount.
			This function does not set the position, it adds to it.
			The translation is in world space, not local space, so rotation will not affect the translation.
			@param translation The positional amount to translate by.
		 */
		void translate(const Math::Vec3& translation);

		/*
			@brief Translate the renderable by the specified positional amount in local space.
			This function does not set the position, it adds to it.
			The translation is in local space, not world space, so rotation will affect the translation.
			@param translation The positional amount to translate by.
		 */
		void translateLocal(const Math::Vec3& translation);

		/*
			@brief Rotates the renderable by the specified rotation amounts.
			This function does not set the rotation, it adds to it.
			@param rotations The rotation amounts around each axis.
		 */
		void rotate(const Math::Vec3& rotations);

		/*
			@brief Rotates the renderable by the specified rotation amounts around the specified origin.
			This function does not set the rotation, it adds to it.
			@param rotations The rotation amounts around each axis.
			@param origin The origin to rotate around.
		 */
		void rotate(const Math::Vec3& rotations, const Math::Vec3& origin);

		/*
			@brief Scales the renderable by the specified scalar amounts.
			This function does not set the scale, it multiplies it.
			@param scalars The scalar amounts for each axis.
		 */
		void scale(const Math::Vec3& scalars);

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
		Math::Mat4 m_inverseModel;

		Math::Vec3 m_position;
		Math::Vec3 m_rotation;
		Math::Vec3 m_scale;

		bool m_hidden;

		void updateModel();

	public:

		/*
			@brief Creates an equilateral triangle renderable with the specified side length and color.
			@param side The side length.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The resulting renderable.
		 */
		static Renderable ColoredTriangle(float side, Math::Vec3 rgb);

		/*
			@brief Creates an equilateral triangle renderable with the specified side length and color.
			@param side The side length.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The resulting renderable.
		 */
		static Renderable ColoredTriangle(float side, Math::Vec4 rgba);

		/*
			@brief Creates a triangle renderable with the specified base, height, and color.
			@param base The base length.
			@param height The height.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The resulting renderable.
		 */
		static Renderable ColoredTriangle(float base, float height, Math::Vec3 rgb);

		/*
			@brief Creates a triangle renderable with the specified base, height, and color.
			@param base The base length.
			@param height The height.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The resulting renderable.
		 */
		static Renderable ColoredTriangle(float base, float height, Math::Vec4 rgba);

		/*
			@brief Creates a triangle renderable with the specified 3 vertices and color.
			@param a The first vertex.
			@param b The second vertex.
			@param c The third vertex.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The resulting renderable.
		 */
		static Renderable ColoredTriangle(Math::Vec2 a, Math::Vec2 b, Math::Vec2 c, Math::Vec3 rgb);

		/*
			@brief Creates a triangle renderable with the specified 3 vertices and color.
			@param a The first vertex.
			@param b The second vertex.
			@param c The third vertex.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The resulting renderable.
		 */
		static Renderable ColoredTriangle(Math::Vec2 a, Math::Vec2 b, Math::Vec2 c, Math::Vec4 rgba);

		/*
			@brief Creates an equilateral triangle renderable with the specified side length and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
			@param side The side length.
			@return The resulting renderable.
		 */
		static Renderable VertexColoredTriangle(float side);

		/*
			@brief Creates a triangle renderable with the specified base and height, and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
			@param base The base length.
			@param height The height.
			@return The resulting renderable.
		 */
		static Renderable VertexColoredTriangle(float base, float height);

		/*
			@brief Creates a triangle renderable with the specified 3 vertices and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
			@param a The first vertex.
			@param b The second vertex.
			@param c The third vertex.
			@return The resulting renderable.
		 */
		static Renderable VertexColoredTriangle(Math::Vec2 a, Math::Vec2 b, Math::Vec2 c);

		/*
			@brief Creates an equilateral triangle renderable with the specified side length and texture.
			@param side The side length.
			@param texture The texture to use.
			@return The resulting renderable.
		 */
		static Renderable TexturedTriangle(float side, Texture texture);

		/*
			@brief Creates a triangle renderable with the specified base, height, and texture.
			@param base The base length.
			@param height The height.
			@param texture The texture to use.
			@return The resulting renderable.
		 */
		static Renderable TexturedTriangle(float base, float height, Texture texture);

		/*
			@brief Creates a triangle renderable with the specified 3 vertices and texture.
			@param a The first vertex.
			@param b The second vertex.
			@param c The third vertex.
			@param texture The texture to use.
			@return The resulting renderable.
		 */
		static Renderable TexturedTriangle(Math::Vec2 a, Math::Vec2 b, Math::Vec2 c, Texture texture);

		/*
			@brief Creates a square renderable with the specified side length and color.
			@param side The side length.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The resulting renderable.
		 */
		static Renderable ColoredSquare(float side, Math::Vec3 rgb);

		/*
			@brief Creates a square renderable with the specified side length and color.
			@param side The side length.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The resulting renderable.
		 */
		static Renderable ColoredSquare(float side, Math::Vec4 rgba);

		/*
			@brief Creates a rectangle renderable with the specified width, height, and color.
			@param width The width of the rectangle.
			@param height The height of the rectangle.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The resulting renderable.
		 */
		static Renderable ColoredQuad(float width, float height, Math::Vec3 rgb);

		/*
			@brief Creates a rectangle renderable with the specified width, height, and color.
			@param width The width of the rectangle.
			@param height The height of the rectangle.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The resulting renderable.
		 */
		static Renderable ColoredQuad(float width, float height, Math::Vec4 rgba);

		/*
			@brief Creates a quadrilateral renderable with the specified vertices and color.
			@param a The bottom-left vertex.
			@param b The bottom-right vertex.
			@param c The top-right vertex.
			@param d The top-left vertex.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The resulting renderable.
		 */
		static Renderable ColoredQuad(Math::Vec2 a, Math::Vec2 b, Math::Vec2 c, Math::Vec2 d, Math::Vec3 rgb);

		/*
			@brief Creates a quadrilateral renderable with the specified vertices and color.
			@param a The bottom-left vertex.
			@param b The bottom-right vertex.
			@param c The top-right vertex.
			@param d The top-left vertex.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The resulting renderable.
		 */
		static Renderable ColoredQuad(Math::Vec2 a, Math::Vec2 b, Math::Vec2 c, Math::Vec2 d, Math::Vec4 rgba);

		/*
			@brief Creates a square renderable with the specified side length and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
			@param side The side length.
			@return The resulting renderable.
		 */
		static Renderable VertexColoredSquare(float side);

		/*
			@brief Creates a rectangle renderable with the specified width and height, and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
			@param width The width of the rectangle.
			@param height The height of the rectangle.
			@return The resulting renderable.
		 */
		static Renderable VertexColoredQuad(float width, float height);

		/*
			@brief Creates a quadrilateral renderable with the specified 4 vertices and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
			@param a The bottom-left vertex.
			@param b The bottom-right vertex.
			@param c The top-right vertex.
			@param d The top-left vertex.
			@return The resulting renderable.
		 */
		static Renderable VertexColoredQuad(Math::Vec2 a, Math::Vec2 b, Math::Vec2 c, Math::Vec2 d);

		/*
			@brief Creates a square renderable with the specified side length and texture.
			@param side The side length.
			@param texture The texture to use.
			@return The resulting renderable.
		 */
		static Renderable TexturedSquare(float side, Texture texture);

		/*
			@brief Creates a rectangle renderable with the specified width, height, and texture.
			@param width The width of the rectangle.
			@param height The height of the rectangle.
			@param texture The texture to use.
			@return The resulting renderable.
		 */
		static Renderable TexturedQuad(float width, float height, Texture texture);

		/*
			@brief Creates a rectangle renderable with the specified 4 vertices and texture.
			@param a The bottom-left vertex.
			@param b The bottom-right vertex.
			@param c The top-right vertex.
			@param d The top-left vertex.
			@return The resulting renderable.
		 */
		static Renderable TexturedQuad(Math::Vec2 a, Math::Vec2 b, Math::Vec2 c, Math::Vec2 d, Texture texture);

		/*
			@brief Creates a cube renderable with the specified side length and color.
			@param side The side length.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The resulting mesh.
		 */
		static Renderable ColoredCube(float side, Math::Vec3 rgb);

		/*
			@brief Creates a cube renderable with the specified side length and color.
			@param side The side length.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The resulting mesh.
		 */
		static Renderable ColoredCube(float side, Math::Vec4 rgba);

		/*
			@brief Creates a cube renderable with the specified side length and texture.
			@param side The side length.
			@param texture The texture to use.
			@return The resulting mesh.
		 */
		static Renderable TexturedCube(float side, Texture texture);
	};
}
