#pragma once

#include <vector>

#include "Result.h"

#include "../src/Core.h"
#include "../src/ErrorHandler.h"
#include "../src/Window.h"
#include "../src/IndexBuffer.h"
#include "../src/Texture.h"
#include "../src/Shader.h"
#include "../src/Renderer.h"
#include "../src/Projection.h"
#include "../src/Mesh.h"
#include "../src/InputHandler.h"
#include "../src/Font.h"
#include "../src/Camera.h"

namespace PresetTests
{
	void MeshTest__Triangle1();
	void MeshTest__Triangle2();
	void MeshTest__Triangle3();
	void MeshTest__Square();
	void MeshTest__Quad1();
	void MeshTest__Quad2();
	void MeshTest__Cube();

	void MeshAndShaderTest__RectPrism1__V_Color();
	void MeshAndShaderTest__RectPrism2__V_XYZtoRGB();

	void ShaderTest__VC();
	void ShaderTest__VT();
	void ShaderTest__VCT();

	void RenderableTest__ColoredTriangle1();
	void RenderableTest__ColoredTriangle2();
	void RenderableTest__ColoredTriangle3();
	void RenderableTest__VertexColoredTriangle1();
	void RenderableTest__VertexColoredTriangle2();
	void RenderableTest__VertexColoredTriangle3();
	void RenderableTest__TexturedTriangle1();
	void RenderableTest__TexturedTriangle2();
	void RenderableTest__TexturedTriangle3();
	void RenderableTest__ColoredSquare();
	void RenderableTest__ColoredQuad1();
	void RenderableTest__ColoredQuad2();
	void RenderableTest__VertexColoredSquare();
	void RenderableTest__VertexColoredQuad1();
	void RenderableTest__VertexColoredQuad2();
	void RenderableTest__TexturedSquare();
	void RenderableTest__TexturedQuad1();
	void RenderableTest__TexturedQuad2();
	void RenderableTest__ColoredCube();
	void RenderableTest__TexturedCube();


	void RunAllTests();
}
