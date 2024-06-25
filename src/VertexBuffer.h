#pragma once

#include "Core.h"

namespace Onyx
{
	class VertexBuffer
	{
		friend class Mesh;
	public:
		/*
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
		 */
		VertexBuffer();

		/*
			@brief Creates an vertex array with the given vertices.
			You are still responsible for handling the memory of the vertices.
			@param vertices The vertices to be used in the vertex array.
			@param size The size of the vertex array, in bytes.
			@param format The vertex format. Use definitions prefixed with ONYX_VERTEX_FORMAT.
		 */
		VertexBuffer(float* vertices, uint size, Onyx::VertexFormat format);

		/*
			@brief Gets the format of the vertex buffer.
			@return The format of the vertex buffer.
		 */
		Onyx::VertexFormat getFormat() const;

		/*
			@brief Determines whether the specified vertex format has normals.
			@param format The vertex format to check.
			@return True if the vertex format has normals, false otherwise.
		 */
		static bool HasNormals(Onyx::VertexFormat format);

		/*
			@brief Determines whether the specified vertex format has texture coordinates.
			@param format The vertex format to check.
			@return True if the vertex format has texture coordinates, false otherwise.
		 */
		static bool HasTextureCoords(Onyx::VertexFormat format);

		/*
			@brief Determines whether the specified vertex format has colors.
			@param format The vertex format to check.
			@return True if the vertex format has colors, false otherwise.
		 */
		static bool HasColors(Onyx::VertexFormat format);


	private:
		float* m_vertices;
		uint m_size;
		Onyx::VertexFormat m_format;

		bool m_heap;

	public:

		/*
			@brief Generates a vertex buffer for a triangle with the specified side length.
			Memory is allocated on the heap and will only be freed when the object is used by the Mesh constructor.
			Vertex format will be P, PN, PT, or PNT depending on the `genNormals` and `genTexCoords` arguments.
			@param side The length of the side of the triangle.
			@param genNormals Whether to generate normal vectors.
			@param genTexCoords Whether to generate texture coordinates.
			@return The generated vertex buffer.
		 */
		static VertexBuffer Triangle(float side, bool genNormals = false, bool genTexCoords = false);

		/*
			@brief Generates a vertex buffer for a triangle with the specified base and height.
			Memory is allocated on the heap and will only be freed when the object is used by the Mesh constructor.
			Vertex format will be P, PN, PT, or PNT depending on the `genNormals` and `genTexCoords` arguments.
			@param base The base of the triangle.
			@param height The height of the triangle.
			@param genNormals Whether to generate normal vectors.
			@param genTexCoords Whether to generate texture coordinates.
			@return The generated vertex buffer.
		 */
		static VertexBuffer Triangle(float base, float height, bool genNormals = false, bool genTexCoords = false);

		/*
			@brief Generates a vertex buffer for a square with the specified side length.
			Memory is allocated on the heap and will only be freed when the object is used by the Mesh constructor.
			Vertex format will be P, PN, PT, or PNT depending on the `genNormals` and `genTexCoords` arguments.
			@param side The length of the side of the square.
			@param genNormals Whether to generate normal vectors.
			@param genTexCoords Whether to generate texture coordinates.
			@return The generated vertex buffer.
		 */
		static VertexBuffer Square(float side, bool genNormals = false, bool genTexCoords = false);

		/*
			@brief Generates a vertex buffer for a rectangle with the specified width and height.
			Memory is allocated on the heap and will only be freed when the object is used by the Mesh constructor.
			Vertex format will be P, PN, PT, or PNT depending on the `genNormals` and `genTexCoords` arguments.
			@param width The width of the rectangle.
			@param height The height of the rectangle.
			@param genNormals Whether to generate normal vectors.
			@param genTexCoords Whether to generate texture coordinates.
			@return The generated vertex buffer.
		 */
		static VertexBuffer Quad(float width, float height, bool genNormals = false, bool genTexCoords = false);

		/*
			@brief Generates a vertex buffer for a circle with the specified radius and number of segments.
			Memory is allocated on the heap and will only be freed when the object is used by the Mesh constructor.
			Vertex format will be P, PN, PT, or PNT depending on the `genNormals` and `genTexCoords` arguments.
			@param radius The radius of the circle.
			@param nSegments The number of line segments used to approximate the circle outline.
			@param genNormals Whether to generate normal vectors.
			@param genTexCoords Whether to generate texture coordinates.
			@return The generated vertex buffer.
		 */
		static VertexBuffer Circle(float radius, int nSegments, bool genNormals = false, bool genTexCoords = false);

		/*
			@brief Generates a vertex buffer for a circle with the specified radius and angle step.
			Memory is allocated on the heap and will only be freed when the object is used by the Mesh constructor.
			Vertex format will be P, PN, PT, or PNT depending on the `genNormals` and `genTexCoords` arguments.
			@param radius The radius of the circle.
			@param angleStep The angle step, in degrees, between vertices.
			@param genNormals Whether to generate normal vectors.
			@param genTexCoords Whether to generate texture coordinates.
			@return The generated vertex buffer.
		 */
		static VertexBuffer Circle(float radius, float angleStep, bool genNormals = false, bool genTexCoords = false);

		/*
			@brief Generates a vertex buffer for a cube with the specified side length.
			Memory is allocated on the heap and will only be freed when the object is used by the Mesh constructor.
			Vertex format will be P, PN, PT, or PNT depending on the `genNormals` and `genTexCoords` arguments.
			@param side The length of the side of the cube.
			@return The generated vertex buffer.
		 */
		static VertexBuffer Cube(float side, bool genNormals = false, bool genTexCoords = false);

		/*
			@brief Generates a vertex buffer for a rectangular prism with the specified width, height, and depth.
			Memory is allocated on the heap and will only be freed when the object is used by the Mesh constructor.
			Vertex format will be P, PN, PT, or PNT depending on the `genNormals` and `genTexCoords` arguments.
			@param width The width (x-axis) of the rectangular prism.
			@param height The height (y-axis) of the rectangular prism.
			@param depth The depth (z-axis) of the rectangular prism.
			@param genNormals Whether to generate normal vectors.
			@param genTexCoords Whether to generate texture coordinates.
			@return The generated vertex buffer.
		 */
		static VertexBuffer RectPrism(float width, float height, float depth, bool genNormals = false, bool genTexCoords = false);

		/*
			@brief Generates a vertex buffer for a cylinder with the specified radius and height.
			Memory is allocated on the heap and will only be freed when the object is used by the Mesh constructor.
			Vertex format will be P, PN, PT, or PNT depending on the `genNormals` and `genTexCoords` arguments.
			@param radius The radius of the cylinder.
			@param height The height (y-axis) of the cylinder.
			@param nSegments The number of line segments used to approximate the circle outline.
			@param genNormals Whether to generate normal vectors.
			@param genTexCoords Whether to generate texture coordinates.
			@return The generated vertex buffer.
		 */
		static VertexBuffer Cylinder(float radius, float height, int nSegments, bool genNormals = false, bool genTexCoords = false);

		/*
			@brief Generates a vertex buffer for a cylinder with the specified radius and height.
			Memory is allocated on the heap and will only be freed when the object is used by the Mesh constructor.
			Vertex format will be P, PN, PT, or PNT depending on the `genNormals` and `genTexCoords` arguments.
			@param radius The radius of the cylinder.
			@param height The height (y-axis) of the cylinder.
			@param angleStep The angle step, in degrees, between the circle vertices.
			@param genNormals Whether to generate normal vectors.
			@param genTexCoords Whether to generate texture coordinates.
			@return The generated vertex buffer.
		 */
		static VertexBuffer Cylinder(float radius, float height, float angleStep, bool genNormals = false, bool genTexCoords = false);
	};
}
