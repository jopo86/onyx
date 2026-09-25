#pragma once

#include <onyx/core.hpp>

namespace onyx
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
			@brief Creates a vertex array with the given vertices.
			You are still responsible for handling the memory of the vertices.
			@param vertices The vertices to be used in the vertex array.
			@param size The size of the vertex array, in bytes.
			@param format The vertex format.
		 */
		VertexBuffer(float* vertices, u32 size, onyx::VertexFormat format);

		/*
			@brief Gets the format of the vertex buffer.
			@return The format of the vertex buffer.
		 */
		onyx::VertexFormat get_format() const;

		/*
			@brief Determines whether the specified vertex format has normals.
			@param format The vertex format to check.
			@return True if the vertex format has normals, false otherwise.
		 */
		static bool has_normals(onyx::VertexFormat format);

		/*
			@brief Determines whether the specified vertex format has texture coordinates.
			@param format The vertex format to check.
			@return True if the vertex format has texture coordinates, false otherwise.
		 */
		static bool has_texture_coords(onyx::VertexFormat format);

		/*
			@brief Determines whether the specified vertex format has colors.
			@param format The vertex format to check.
			@return True if the vertex format has colors, false otherwise.
		 */
		static bool has_colors(onyx::VertexFormat format);


	private:
		float* vertices;
		u32 size;
		onyx::VertexFormat format;

		bool heap;

	public:

		/*
			@brief Generates a vertex buffer for a triangle with the specified side length.
			Memory is allocated on the heap and will only be freed when the object is used by the Mesh constructor.
			Vertex format will be P, PN, PT, or PNT depending on the `gen_normals` and `gen_tex_coords` arguments.
			@param side The length of the side of the triangle.
			@param gen_normals Whether to generate normal vectors.
			@param gen_tex_coords Whether to generate texture coordinates.
			@return The generated vertex buffer.
		 */
		static VertexBuffer triangle(float side, bool gen_normals = false, bool gen_tex_coords = false);

		/*
			@brief Generates a vertex buffer for a triangle with the specified base and height.
			Memory is allocated on the heap and will only be freed when the object is used by the Mesh constructor.
			Vertex format will be P, PN, PT, or PNT depending on the `gen_normals` and `gen_tex_coords` arguments.
			@param base The base of the triangle.
			@param height The height of the triangle.
			@param gen_normals Whether to generate normal vectors.
			@param gen_tex_coords Whether to generate texture coordinates.
			@return The generated vertex buffer.
		 */
		static VertexBuffer triangle(float base, float height, bool gen_normals = false, bool gen_tex_coords = false);

		/*
			@brief Generates a vertex buffer for a square with the specified side length.
			Memory is allocated on the heap and will only be freed when the object is used by the Mesh constructor.
			Vertex format will be P, PN, PT, or PNT depending on the `gen_normals` and `gen_tex_coords` arguments.
			@param side The length of the side of the square.
			@param gen_normals Whether to generate normal vectors.
			@param gen_tex_coords Whether to generate texture coordinates.
			@return The generated vertex buffer.
		 */
		static VertexBuffer square(float side, bool gen_normals = false, bool gen_tex_coords = false);

		/*
			@brief Generates a vertex buffer for a rectangle with the specified width and height.
			Memory is allocated on the heap and will only be freed when the object is used by the Mesh constructor.
			Vertex format will be P, PN, PT, or PNT depending on the `gen_normals` and `gen_tex_coords` arguments.
			@param width The width of the rectangle.
			@param height The height of the rectangle.
			@param gen_normals Whether to generate normal vectors.
			@param gen_tex_coords Whether to generate texture coordinates.
			@return The generated vertex buffer.
		 */
		static VertexBuffer quad(float width, float height, bool gen_normals = false, bool gen_tex_coords = false);

		/*
			@brief Generates a vertex buffer for a circle with the specified radius and number of segments.
			Memory is allocated on the heap and will only be freed when the object is used by the Mesh constructor.
			Vertex format will be P, PN, PT, or PNT depending on the `gen_normals` and `gen_tex_coords` arguments.
			@param radius The radius of the circle.
			@param n_segments The number of line segments used to approximate the circle outline.
			@param gen_normals Whether to generate normal vectors.
			@param gen_tex_coords Whether to generate texture coordinates.
			@return The generated vertex buffer.
		 */
		static VertexBuffer circle(float radius, int n_segments, bool gen_normals = false, bool gen_tex_coords = false);

		/*
			@brief Generates a vertex buffer for a circle with the specified radius and angle step.
			Memory is allocated on the heap and will only be freed when the object is used by the Mesh constructor.
			Vertex format will be P, PN, PT, or PNT depending on the `gen_normals` and `gen_tex_coords` arguments.
			@param radius The radius of the circle.
			@param angle_step The angle step, in degrees, between vertices.
			@param gen_normals Whether to generate normal vectors.
			@param gen_tex_coords Whether to generate texture coordinates.
			@return The generated vertex buffer.
		 */
		static VertexBuffer circle(float radius, float angle_step, bool gen_normals = false, bool gen_tex_coords = false);

		/*
			@brief Generates a vertex buffer for a cube with the specified side length.
			Memory is allocated on the heap and will only be freed when the object is used by the Mesh constructor.
			Vertex format will be P, PN, PT, or PNT depending on the `gen_normals` and `gen_tex_coords` arguments.
			@param side The length of the side of the cube.
			@param gen_normals Whether to generate normal vectors.
			@param gen_tex_coords Whether to generate texture coordinates.
			@return The generated vertex buffer.
		 */
		static VertexBuffer cube(float side, bool gen_normals = false, bool gen_tex_coords = false);

		/*
			@brief Generates a vertex buffer for a rectangular prism with the specified width, height, and depth.
			Memory is allocated on the heap and will only be freed when the object is used by the Mesh constructor.
			Vertex format will be P, PN, PT, or PNT depending on the `gen_normals` and `gen_tex_coords` arguments.
			@param width The width (x-axis) of the rectangular prism.
			@param height The height (y-axis) of the rectangular prism.
			@param depth The depth (z-axis) of the rectangular prism.
			@param gen_normals Whether to generate normal vectors.
			@param gen_tex_coords Whether to generate texture coordinates.
			@return The generated vertex buffer.
		 */
		static VertexBuffer rect_prism(float width, float height, float depth, bool gen_normals = false, bool gen_tex_coords = false);

		/*
			@brief Generates a vertex buffer for a cylinder with the specified radius and height.
			Memory is allocated on the heap and will only be freed when the object is used by the Mesh constructor.
			Vertex format will be P, PN, PT, or PNT depending on the `gen_normals` and `gen_tex_coords` arguments.
			@param radius The radius of the cylinder.
			@param height The height (y-axis) of the cylinder.
			@param n_segments The number of line segments used to approximate the circle outline.
			@param gen_normals Whether to generate normal vectors.
			@param gen_tex_coords Whether to generate texture coordinates.
			@return The generated vertex buffer.
		 */
		static VertexBuffer cylinder(float radius, float height, int n_segments, bool gen_normals = false, bool gen_tex_coords = false);

		/*
			@brief Generates a vertex buffer for a cylinder with the specified radius and height.
			Memory is allocated on the heap and will only be freed when the object is used by the Mesh constructor.
			Vertex format will be P, PN, PT, or PNT depending on the `gen_normals` and `gen_tex_coords` arguments.
			@param radius The radius of the cylinder.
			@param height The height (y-axis) of the cylinder.
			@param angle_step The angle step, in degrees, between the circle vertices.
			@param gen_normals Whether to generate normal vectors.
			@param gen_tex_coords Whether to generate texture coordinates.
			@return The generated vertex buffer.
		 */
		static VertexBuffer cylinder(float radius, float height, float angle_step, bool gen_normals = false, bool gen_tex_coords = false);
	};
}
