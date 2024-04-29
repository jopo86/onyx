#pragma once

#include "Core.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Math.h"

namespace Onyx
{
	/*
		@brief A class to represent a mesh.
		This includes vertices, the positions of each point on the mesh, as well as indices, the order of vertices as indices.
		This class is disposable.
	 */
	class Mesh : public Disposable
	{
	public:
		/*
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
		 */
		Mesh();

		/*
			@brief Creats a new Mesh object with the specified vertices and indices.
			@param vertexBuffer The vertex buffer object.
			@param indexBuffer The index buffer object.
			@param result A pointer to a boolean that will be set to true if the mesh was created successfully, and false otherwise.
		 */
		Mesh(VertexBuffer vertexBuffer, IndexBuffer indexBuffer, bool* result = nullptr);

		/*
			@brief Creates a new Mesh object from another mesh object.
		 !	This function does not copy the mesh data, rather the IDs of the VAO, VBO, and IBO.
		 !	This means that the mesh data is shared, and disposing of one mesh will dispose of the other.
		 !	This is used appropriately in the Renderable class, but should be used elsewhere with caution.
			@param other The other mesh object.
		*/
		Mesh(const Mesh& other);

		/*
			@brief Renders the mesh.
			Not needed if using renderables.
		 */
		void render() const;

		/*
			@brief Gets the vertex array object ID.
			Access to the VAO is provided for the library, as well as for advanced users.
			@return The VAO ID.
		 */
		uint getVAO() const;

		/*
			@brief Gets the vertex buffer object ID.
			Access to the VBO is provided for the library, as well as for advanced users.
			@return The VBO ID.
		 */
		uint getVBO() const;

		/*
			@brief Gets the index buffer object ID.
			Access to the IBO is provided for the library, as well as for advanced users.
			@return The IBO ID.
		 */
		uint getIBO() const;

		/*
			@brief Gets the size of the vertex array.
			@return The size of the vertex array, in bytes.
		 */
		uint getVerticesSize() const;

		/*
			@brief Gets the size of the index array.
			@return The size of the index array, in bytes.
		 */
		uint getIndicesSize() const;

		/*
			@brief Gets the format of the vertex array.
			@return The vertex format.
		 */
		VertexFormat getVertexFormat() const;

		/*
			@brief Destroys the object, freeing any used memory.
			Do not use the object after this is called.
		 */
		void dispose() override;

	private:
		uint m_vao, m_vbo, m_ibo;

		uint m_verticesSize, m_indicesSize;
		VertexFormat m_vertexFormat;

	public:
		/*
			@brief Generates an equilateral triangle mesh with the specified side length.
			@param side The side length.
			@return The generated mesh.
		 */
		static Mesh Triangle(float side);

		/*
			@brief Generates a triangle mesh with the specified base and height.
			@param base The base length.
			@param height The height.
			@return The generated mesh.
		 */
		static Mesh Triangle(float base, float height);

		/*
			@brief Generates a triangle mesh with the specified 3 vertices.
			@param a The first vertex.
			@param b The second vertex.
			@param c The third vertex.
			@return The generated mesh.
		 */
		static Mesh Triangle(Math::Vec2 a, Math::Vec2 b, Math::Vec2 c);

		/*
			@brief Generates a square mesh with the specified side length.
			@param The side length.
			@return The generated mesh.
		 */
		static Mesh Square(float side);

		/*
			@brief Generates a rectangle mesh with the specified width and height.
			@param width The width of the rectangle.
			@param height The height of the rectangle.
			@return The generated mesh.
		 */
		static Mesh Quad(float width, float height);

		/*
			@brief Generates a quadrilateral mesh with the specified 4 vertices.
			@param a The bottom-left vertex.
			@param b The bottom-right vertex.
			@param c The top-right vertex.
			@param d The top-left vertex.
			@return The generated mesh.
		 */
		static Mesh Quad(Math::Vec2 a, Math::Vec2 b, Math::Vec2 c, Math::Vec2 d);

		/*
			@brief Generates a cube mesh with the specified side length.
			@param side The side length.
			@return The generated mesh.
		 */
		static Mesh Cube(float side);

		/*
			@brief Generates a rectangular prism / cuboid mesh with the specified dimensions.
			@param width The width (x-axis) of the prism.
			@param height The height (y-axis) of the prism.
			@param depth The depth (z-axis) of the prism.
			@return The generated mesh.
		 */
		static Mesh RectPrism(float width, float height, float depth);

		/*
			@brief Generates a rectangular prism / cuboid mesh with the specified 8 vertices.
			@param a The bottom-left vertex of the first quad.
			@param b The bottom-right vertex of the first quad.
			@param c The top-right vertex of the first quad.
			@param d The top-left vertex of the first quad.
			@param e The bottom-left vertex of the second quad.
			@param f The bottom-right vertex of the second quad.
			@param g The top-right vertex of the second quad.
			@param h The top-left vertex of the second quad.
			@return The generated mesh.
		 */
		static Mesh RectPrism(Math::Vec3 a, Math::Vec3 b, Math::Vec3 c, Math::Vec3 d, Math::Vec3 e, Math::Vec3 f, Math::Vec3 g, Math::Vec3 h);
	};
}
