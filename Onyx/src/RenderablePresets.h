#pragma once

#include "Core.h"
#include "Renderable.h"
#include "Math.h"
#include "ShaderPresets.h"
#include "MeshPresets.h"

namespace Onyx
{
	/*
	 * @brief A namespace providing access to preset renderables for convenience.
	 */
	namespace RenderablePresets
	{

		/*
		 * @brief Creates an equilateral triangle renderable with the specified side length and color.
		 * @param side The side length.
		 * @param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
		 * @return The resulting renderable.
		 */
		Renderable ColoredTriangle(float side, Onyx::Math::Vec3 rgb);

		/*
		 * @brief Creates a triangle renderable with the specified base, height, and color.
		 * @param base The base length.
		 * @param height The height.
		 * @param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
		 * @return The resulting renderable.
		 */
		Renderable ColoredTriangle(float base, float height, Onyx::Math::Vec3 rgb);

		/*
		 * @brief Creates a triangle renderable with the specified 3 vertices and color.
		 * @param a The first vertex.
		 * @param b The second vertex.
		 * @param c The third vertex.
		 * @param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
		 * @return The resulting renderable.
		 */
		Renderable ColoredTriangle(Onyx::Math::Vec2 a, Onyx::Math::Vec2 b, Onyx::Math::Vec2 c, Onyx::Math::Vec3 rgb);

		/*
		 * @brief Creates an equilateral triangle renderable with the specified side length and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
		 * @param side The side length.
		 * @return The resulting renderable.
		 */
		Renderable VertexColoredTriangle(float side);

		/*
		 * @brief Creates a triangle renderable with the specified base and height, and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
		 * @param base The base length.
		 * @param height The height.
		 * @return The resulting renderable.
		 */
		Renderable VertexColoredTriangle(float base, float height);

		/*
		 * @brief Creates a triangle renderable with the specified 3 vertices and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
		 * @param a The first vertex.
		 * @param b The second vertex.
		 * @param c The third vertex.
		 * @return The resulting renderable.
		 */
		Renderable VertexColoredTriangle(Onyx::Math::Vec2 a, Onyx::Math::Vec2 b, Onyx::Math::Vec2 c);

		/*
		 * @brief Creates an equilateral triangle renderable with the specified side length and texture.
		 * @param side The side length.
		 * @param texture The texture to use.
		 * @return The resulting renderable.
		 */
		Renderable TexturedTriangle(float side, Texture texture);

		/*
		 * @brief Creates a triangle renderable with the specified base, height, and texture.
		 * @param base The base length.
		 * @param height The height.
		 * @param texture The texture to use.
		 * @return The resulting renderable.
		 */
		Renderable TexturedTriangle(float base, float height, Texture texture);

		/*
		 * @brief Creates a triangle renderable with the specified 3 vertices and texture.
		 * @param a The first vertex.
		 * @param b The second vertex.
		 * @param c The third vertex.
		 * @param texture The texture to use.
		 * @return The resulting renderable.
		 */
		Renderable TexturedTriangle(Onyx::Math::Vec2 a, Onyx::Math::Vec2 b, Onyx::Math::Vec2 c, Texture texture);

		/*
		 * @brief Creates a square renderable with the specified side length and color.
		 * @param side The side length.
		 * @param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
		 * @return The resulting renderable.
		 */
		Renderable ColoredSquare(float side, Onyx::Math::Vec3 rgb);

		/*
		 * @brief Creates a rectangle renderable with the specified width, height, and color.
		 * @param width The width of the rectangle.
		 * @param height The height of the rectangle.
		 * @param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
		 * @return The resulting renderable.
		 */
		Renderable ColoredQuad(float width, float height, Onyx::Math::Vec3 rgb);

		/*
		 * @brief Creates a quadrilateral renderable with the specified vertices and color.
		 * @param a The bottom-left vertex.
		 * @param b The bottom-right vertex.
		 * @param c The top-right vertex.
		 * @param d The top-left vertex.
		 * @param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
		 * @return The resulting renderable.
		 */
		Renderable ColoredQuad(Onyx::Math::Vec2 a, Onyx::Math::Vec2 b, Onyx::Math::Vec2 c, Onyx::Math::Vec2 d, Onyx::Math::Vec3 rgb);

		/*
		 * @brief Creates a square renderable with the specified side length and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
		 * @param side The side length.
		 * @return The resulting renderable.
		 */
		Renderable VertexColoredSquare(float side);

		/*
		 * @brief Creates a rectangle renderable with the specified width and height, and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
		 * @param width The width of the rectangle.
		 * @param height The height of the rectangle.
		 * @return The resulting renderable.
		 */
		Renderable VertexColoredQuad(float width, float height);

		/*
		 * @brief Creates a quadrilateral renderable with the specified 4 vertices and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
		 * @param a The bottom-left vertex.
		 * @param b The bottom-right vertex.
		 * @param c The top-right vertex.
		 * @param d The top-left vertex.
		 * @return The resulting renderable.
		 */
		Renderable VertexColoredQuad(Onyx::Math::Vec2 a, Onyx::Math::Vec2 b, Onyx::Math::Vec2 c, Onyx::Math::Vec2 d);

		/*
		 * @brief Creates a square renderable with the specified side length and texture.
		 * @param side The side length.
		 * @param texture The texture to use.
		 * @return The resulting renderable.
		 */
		Renderable TexturedSquare(float side, Texture texture);

		/*
		 * @brief Creates a rectangle renderable with the specified width, height, and texture.
		 * @param width The width of the rectangle.
		 * @param height The height of the rectangle.
		 * @param texture The texture to use.
		 * @return The resulting renderable.
		 */
		Renderable TexturedQuad(float width, float height, Texture texture);

		/*
		 * @brief Creates a rectangle renderable with the specified 4 vertices and texture.
		 * @param a The bottom-left vertex.
		 * @param b The bottom-right vertex.
		 * @param c The top-right vertex.
		 * @param d The top-left vertex.
		 * @return The resulting renderable.
		 */
		Renderable TexturedQuad(Onyx::Math::Vec2 a, Onyx::Math::Vec2 b, Onyx::Math::Vec2 c, Onyx::Math::Vec2 d, Texture texture);

		/*
		 * @brief Creates a cube renderable with the specified side length and color.
		 * @param side The side length.
		 * @param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
		 * @return The resulting mesh.
		 */
		Renderable ColoredCube(float side, Onyx::Math::Vec3 rgb);
	}
}
