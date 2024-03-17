#include "RenderablePresets.h"

using Onyx::Math::Vec2, Onyx::Math::Vec3;

Onyx::Renderable Onyx::RenderablePresets::ColoredTriangle(float side, Vec3 rgb)
{
	return ColoredTriangle(side, sqrtf(powf(side / 2.0f, 2.0f) + powf(side, 2.0f)), rgb);
}

Onyx::Renderable Onyx::RenderablePresets::ColoredTriangle(float base, float height, Vec3 rgb)
{
	return ColoredTriangle(
		Vec2(-base / 2.0f, -height / 2.0f),
		Vec2( base / 2.0f, -height / 2.0f),
		Vec2( 0.0f,		  height / 2.0f),
		rgb
	);
}

Onyx::Renderable Onyx::RenderablePresets::ColoredTriangle(Vec2 a, Vec2 b, Vec2 c, Vec3 rgb)
{
	return Renderable(
		MeshPresets::Triangle(a, b, c),
		ShaderPresets::V_Color(rgb)
	);
}

Onyx::Renderable Onyx::RenderablePresets::VertexColoredTriangle(float side)
{
	return VertexColoredTriangle(side, sqrtf(powf(side / 2.0f, 2.0f) + powf(side, 2.0f)));
}

Onyx::Renderable Onyx::RenderablePresets::VertexColoredTriangle(float base, float height)
{
	return VertexColoredTriangle(
		Vec2(-base / 2.0f, -height / 2.0f),
		Vec2(base / 2.0f, -height / 2.0f),
		Vec2(0.0f, height / 2.0f)
	);
}

Onyx::Renderable Onyx::RenderablePresets::VertexColoredTriangle(Vec2 a, Vec2 b, Vec2 c)
{
	return Renderable(
		MeshPresets::Triangle(a, b, c),
		ShaderPresets::V_XYZtoRGB()
	);
}

Onyx::Renderable Onyx::RenderablePresets::TexturedTriangle(float side, Texture texture)
{
	return TexturedTriangle(side, sqrtf(powf(side / 2.0f, 2.0f) + powf(side, 2.0f)), texture);
}

Onyx::Renderable Onyx::RenderablePresets::TexturedTriangle(float base, float height, Texture texture)
{
	return TexturedTriangle(
		Vec2(-base / 2.0f, -height / 2.0f),
		Vec2(base / 2.0f, -height / 2.0f),
		Vec2(0.0f, height / 2.0f),
		texture
	);
}

Onyx::Renderable Onyx::RenderablePresets::TexturedTriangle(Vec2 a, Vec2 b, Vec2 c, Texture texture)
{
	float *vertices = new float[15]{
		a.getX(), a.getY(), 0.0f,	0.0f, 0.0f,
		b.getX(), b.getY(), 0.0f,	1.0f, 0.0f,
		c.getX(), c.getY(), 0.0f,	0.5f, 1.0f
	};

	uint *indices = new uint[3]{
		0, 1, 2
	};

	return Renderable(
		Mesh(
			VertexArray(vertices, 15 * sizeof(float), ONYX_VERTEX_FORMAT_VT, true),
			IndexArray(indices, 3 * sizeof(uint), true)
		),
		ShaderPresets::VT(),
		texture
	);
}

Onyx::Renderable Onyx::RenderablePresets::ColoredSquare(float side, Vec3 rgb)
{
	return ColoredQuad(side, side, rgb);
}

Onyx::Renderable Onyx::RenderablePresets::ColoredQuad(float width, float height, Vec3 rgb)
{
	return ColoredQuad(
		Vec2(-width / 2.0f, -height / 2.0f),
		Vec2(width / 2.0f, -height / 2.0f),
		Vec2(width / 2.0f, height / 2.0f),
		Vec2(-width / 2.0f, height / 2.0f),
		rgb
	);
}

Onyx::Renderable Onyx::RenderablePresets::ColoredQuad(Vec2 a, Vec2 b, Vec2 c, Vec2 d, Vec3 rgb)
{
	return Renderable(
		MeshPresets::Quad(a, b, c, d),
		ShaderPresets::V_Color(rgb)
	);
}

Onyx::Renderable Onyx::RenderablePresets::VertexColoredSquare(float side)
{
	return VertexColoredQuad(side, side);
}

Onyx::Renderable Onyx::RenderablePresets::VertexColoredQuad(float width, float height)
{
	return VertexColoredQuad(
		Vec2(-width / 2.0f, -height / 2.0f),
		Vec2( width / 2.0f, -height / 2.0f),
		Vec2( width / 2.0f,  height / 2.0f),
		Vec2(-width / 2.0f,  height / 2.0f)
	);
}

Onyx::Renderable Onyx::RenderablePresets::VertexColoredQuad(Vec2 a, Vec2 b, Vec2 c, Vec2 d)
{
	return Renderable(
		MeshPresets::Quad(a, b, c, d),
		ShaderPresets::V_XYZtoRGB()
	);
}

Onyx::Renderable Onyx::RenderablePresets::TexturedSquare(float side, Texture texture)
{
	return TexturedQuad(side, side, texture);
}

Onyx::Renderable Onyx::RenderablePresets::TexturedQuad(float width, float height, Texture texture)
{
	return TexturedQuad(
		Vec2(-width / 2.0f, -height / 2.0f),
		Vec2( width / 2.0f, -height / 2.0f),
		Vec2( width / 2.0f,  height / 2.0f),
		Vec2(-width / 2.0f,  height / 2.0f),
		texture
	);
}

Onyx::Renderable Onyx::RenderablePresets::TexturedQuad(Vec2 a, Vec2 b, Vec2 c, Vec2 d, Texture texture)
{
	float *vertices = new float[20]{
		a.getX(), a.getY(), 0.0f,	0.0f, 0.0f,
		b.getX(), b.getY(), 0.0f,	1.0f, 0.0f,
		c.getX(), c.getY(), 0.0f,	1.0f, 1.0f,
		d.getX(), d.getY(), 0.0f,	0.0f, 1.0f
	};

	uint *indices = new uint[6]{
		0, 1, 2,
		2, 3, 0
	};

	return Renderable(
		Mesh(
			VertexArray(vertices, 20 * sizeof(float), ONYX_VERTEX_FORMAT_VT, true),
			IndexArray(indices, 6 * sizeof(uint), true)
		),
		ShaderPresets::VT(),
		texture
	);
}

Onyx::Renderable Onyx::RenderablePresets::ColoredCube(float side, Vec3 rgb)
{
	return Renderable(
		MeshPresets::Cube(side),
		ShaderPresets::V_Color(rgb)
	);
}
