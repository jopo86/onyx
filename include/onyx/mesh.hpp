#pragma once

#include <onyx/core.hpp>
#include <onyx/vertex_buffer.hpp>
#include <onyx/index_buffer.hpp>
#include <onyx/math_wrappers.hpp>

namespace onyx
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
			@brief Creates a new Mesh object with the specified vertices and indices.
			@param vertex_buffer The vertex buffer object.
			@param index_buffer The index buffer object.
			@param result A pointer to a boolean that will be set to true if the mesh was created successfully, and false otherwise.
		 */
		Mesh(VertexBuffer vertex_buffer, IndexBuffer index_buffer, bool* result = nullptr);

		/*
			@brief Creates a new Mesh object from another mesh object.
		 !	This function does not copy the mesh data, rather the IDs of the VAO, VBO, and IBO.
		 !	This means that the mesh data is shared, and disposing of one mesh will dispose of the other.
		 !	This is used appropriately in the Renderable class, but should be used elsewhere with caution.
			@param other The other mesh object.
		 */
		Mesh(const Mesh& other);

		/*
			@brief Assigns another mesh object to this one.
		 !	Like the copy constructor, this shares the IDs of the VAO, VBO, and IBO rather than copying the data.
			@param other The other mesh object.
			@return A reference to this object.
		 */
		Mesh& operator=(const Mesh& other) = default;

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
		u32 get_vao() const;

		/*
			@brief Gets the vertex buffer object ID.
			Access to the VBO is provided for the library, as well as for advanced users.
			@return The VBO ID.
		 */
		u32 get_vbo() const;

		/*
			@brief Gets the index buffer object ID.
			Access to the IBO is provided for the library, as well as for advanced users.
			@return The IBO ID.
		 */
		u32 get_ibo() const;

		/*
			@brief Gets the size of the vertex array.
			@return The size of the vertex array, in bytes.
		 */
		u32 get_vertices_size() const;

		/*
			@brief Gets the size of the index array.
			@return The size of the index array, in bytes.
		 */
		u32 get_indices_size() const;

		/*
			@brief Gets the format of the vertex array.
			@return The vertex format.
		 */
		VertexFormat get_vertex_format() const;

		void dispose() override;

	private:
		u32 vao, vbo, ibo;

		u32 vertices_size, indices_size;
		VertexFormat vertex_format;

	public:
		/*
			@brief Generates an equilateral triangle mesh with the specified side length.
			@param side The side length.
			@param gen_normals Whether to generate normal vectors.
			@param gen_tex_coords Whether to generate texture coordinates.
			@return The generated mesh.
		 */
		static Mesh triangle(float side, bool gen_normals = false, bool gen_tex_coords = false);

		/*
			@brief Generates a triangle mesh with the specified base and height.
			@param base The base length.
			@param height The height.
			@param gen_normals Whether to generate normal vectors.
			@param gen_tex_coords Whether to generate texture coordinates.
			@return The generated mesh.
		 */
		static Mesh triangle(float base, float height, bool gen_normals = false, bool gen_tex_coords = false);

		/*
			@brief Generates a square mesh with the specified side length.
			@param side The side length.
			@param gen_normals Whether to generate normal vectors.
			@param gen_tex_coords Whether to generate texture coordinates.
			@return The generated mesh.
		 */
		static Mesh square(float side, bool gen_normals = false, bool gen_tex_coords = false);

		/*
			@brief Generates a rectangle mesh with the specified width and height.
			@param width The width of the rectangle.
			@param height The height of the rectangle.
			@param gen_normals Whether to generate normal vectors.
			@param gen_tex_coords Whether to generate texture coordinates.
			@return The generated mesh.
		 */
		static Mesh quad(float width, float height, bool gen_normals = false, bool gen_tex_coords = false);

		/*
			@brief Generates a circle mesh from the specified radius and number of segments.
			@param radius The radius of the circle.
			@param n_segments The number of line segments used to approximate the circle outline.
			@param gen_normals Whether to generate normal vectors.
			@param gen_tex_coords Whether to generate texture coordinates.
			@return The generated mesh.
		 */
		static Mesh circle(float radius, int n_segments, bool gen_normals = false, bool gen_tex_coords = false);

		/*
			@brief Generates a circle mesh from the specified radius and angle step.
			@param radius The radius of the circle.
			@param angle_step The angle step, in degrees, between vertices.
			@param gen_normals Whether to generate normal vectors.
			@param gen_tex_coords Whether to generate texture coordinates.
			@return The generated mesh.
		 */
		static Mesh circle(float radius, float angle_step, bool gen_normals = false, bool gen_tex_coords = false);

		/*
			@brief Generates a cube mesh with the specified side length.
			@param side The side length.
			@param gen_normals Whether to generate normal vectors.
			@param gen_tex_coords Whether to generate texture coordinates.
			@return The generated mesh.
		 */
		static Mesh cube(float side, bool gen_normals = false, bool gen_tex_coords = false);

		/*
			@brief Generates a rectangular prism / cuboid mesh with the specified dimensions.
			@param width The width (x-axis) of the prism.
			@param height The height (y-axis) of the prism.
			@param depth The depth (z-axis) of the prism.
			@param gen_normals Whether to generate normal vectors.
			@param gen_tex_coords Whether to generate texture coordinates.
			@return The generated mesh.
		 */
		static Mesh rect_prism(float width, float height, float depth, bool gen_normals = false, bool gen_tex_coords = false);

		/*
			@brief Generates a cylinder mesh with the specified radius, height, and number of segments.
			@param radius The radius of the cylinder.
			@param height The height of the cylinder.
			@param n_segments The number of line segments used to approximate the circle outline.
			@param gen_normals Whether to generate normal vectors.
			@param gen_tex_coords Whether to generate texture coordinates.
			@return The generated mesh.
		 */
		static Mesh cylinder(float radius, float height, int n_segments, bool gen_normals = false, bool gen_tex_coords = false);

		/*
			@brief Generates a cylinder mesh with the specified radius, height, and angle step.
			@param radius The radius of the cylinder.
			@param height The height of the cylinder.
			@param angle_step The angle step, in degrees, between circle vertices.
			@param gen_normals Whether to generate normal vectors.
			@param gen_tex_coords Whether to generate texture coordinates.
			@return The generated mesh.
		 */
		static Mesh cylinder(float radius, float height, float angle_step, bool gen_normals = false, bool gen_tex_coords = false);
	};
}
