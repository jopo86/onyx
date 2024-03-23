#pragma once

#include <glad/glad.h>

#include "Core.h"
#include "VertexArray.h"
#include "IndexArray.h"

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
			@brief Creates an empty Mesh object.
			Trying to use a mesh object constructed like this will most likely cause errors.
		 */
		Mesh();

		/*
			@brief Creats a new Mesh object with the specified vertices and indices.
			@param vertices The vertex array.
			@param verticesSize The size, in bytes, of the vertex array. Use sizeof().
			@param vertexFormat The format of the vertices. Use the definitions prefixed with MG_VERTEX_FORMAT.
			@param indices The index array.
			@param indicesSize The size, in bytes, of the index array. Use sizeof().
		 */
		Mesh(VertexArray vertexArray, IndexArray indexArray);

		/*
			@brief Creates a new Mesh object from another mesh object.
		 !	This function does not copy the mesh data, rather the IDs of the VAO, VBO, and IBO.
		 !	This means that the mesh data is shared, and disposing of one mesh will dispose of the other.
		 !	This is used appropriately in the Renderable class, but should be used elsewhere with caution.
			@param other The other texture object.
		*/
		Mesh(const Mesh& other);

		/*
			@brief Renders the mesh.
			Not needed if using renderables.
		 */
		void render();

		/*
			@brief Gets the vertex array object ID.
			Access to the VAO is provided for the library, as well as for advanced users.
			@return The VAO ID.
		 */
		uint getVaoID();

		VertexArray getVertexArray();

		IndexArray getIndexArray();

		/*
			@brief Disposes of the mesh.
			This clears up any memory that the object was using.
			This function should be used when the object is no longer needed, such as just before the program ends or the object goes out of scope.
		 */
		void dispose() override;

	private:
		uint vao, vbo, ibo;

		VertexArray vertexArray;
		IndexArray indexArray;
	};
}
