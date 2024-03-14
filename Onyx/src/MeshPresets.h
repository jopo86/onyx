#pragma once

#include <cmath>

#include "Core.h"
#include "Mesh.h"
#include "Math.h"
#include "VertexArray.h"
#include "IndexArray.h"

namespace Onyx
{
	/*
	 * @brief A namespace providing access to preset meshes for convenience.
	 */
	namespace MeshPresets
	{
		/*
		 * @brief Creates an equilateral triangle mesh with the specified side length.
		 * @param side The side length.
		 * @return The resulting mesh.
		 */
		Mesh Triangle(float side);

		/*
		 * @brief Creates a triangle mesh with the specified base and height.
		 * @param base The base length.
		 * @param height The height.
		 * @return The resulting mesh.
		 */
		Mesh Triangle(float base, float height);

		/*
		 * @brief Creates a triangle mesh with the specified 3 vertices.
		 * @param a The first vertex.
		 * @param b The second vertex.
		 * @param c The third vertex.
		 * @return The resulting mesh.
		 */
		Mesh Triangle(Math::Vec2 a, Math::Vec2 b, Math::Vec2 c);

		/*
		 * @brief Creates a square mesh with the specified side length.
		 * @param The side length.
		 * @return The resulting mesh.
		 */
		Mesh Square(float side);

		/*
		 * @brief Creates a rectangle mesh with the specified width and height.
		 * @param width The width of the rectangle.
		 * @param height The height of the rectangle.
		 * @return The resulting mesh.
		 */
		Mesh Quad(float width, float height);

		/*
		 * @brief Creates a quadrilateral mesh with the specified 4 vertices.
		 * @param a The bottom-left vertex.
		 * @param b The bottom-right vertex.
		 * @param c The top-right vertex.
		 * @param d The top-left vertex.
		 * @return The resulting mesh.
		 */
		Mesh Quad(Math::Vec2 a, Math::Vec2 b, Math::Vec2 c, Math::Vec2 d);

		/*
		 * @brief Creates a cube mesh with the specified side length.
		 * @param side The side length.
		 * @return The resulting mesh.
		 */
		Mesh Cube(float side);

		/*
		 * @brief Creates a rectangular prism / cuboid mesh with the specified dimensions.
		 * @param width The width (x-axis) of the prism.
		 * @param height The height (y-axis) of the prism.
		 * @param depth The depth (z-axis) of the prism.
		 * @return The resulting mesh.
		 */
		Mesh RectPrism(float width, float height, float depth);

		/*
		 * @brief Creates a rectangular prism / cuboid mesh with the specified 8 vertices.
		 * @param a The bottom-left vertex of the first quad.
		 * @param b The bottom-right vertex of the first quad.
		 * @param c The top-right vertex of the first quad.
		 * @param d The top-left vertex of the first quad.
		 * @param e The bottom-left vertex of the second quad.
		 * @param f The bottom-right vertex of the second quad.
		 * @param g The top-right vertex of the second quad.
		 * @param h The top-left vertex of the second quad.
		 * @return The resulting mesh.
		 */
		Mesh RectPrism(Math::Vec3 a, Math::Vec3 b, Math::Vec3 c, Math::Vec3 d, Math::Vec3 e, Math::Vec3 f, Math::Vec3 g, Math::Vec3 h);

		VertexArray GetTriangleVertices(float side);
		VertexArray GetTriangleVertices(float base, float height);
		VertexArray GetSquareVertices(float side);
		VertexArray GetQuadVertices(float width, float height);
		VertexArray GetRectPrismVertices(float width, float height, float depth);
		IndexArray GetIndices(int mesh);
	}
}
