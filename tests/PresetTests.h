#pragma once

#include <vector>

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
	bool RunMeshTest(Onyx::Window& window, Onyx::Mesh mesh);
	bool RunRenderableTest(Onyx::Window& window, Onyx::Renderable renderable);
	bool RunUiRenderableTest(Onyx::Window& window, Onyx::UiRenderable renderable);

	bool MeshTest_Triangle1();
	bool MeshTest_Triangle2();
	bool MeshTest_Square();
	bool MeshTest_Quad();
	bool MeshTest_Circle();
	bool MeshTest_Cube();
	bool MeshTest_RectPrism();
	bool MeshTest_Cylinder();

	bool RenderableTest_ColoredTriangle();
	bool RenderableTest_VertexColoredTriangle();
	bool RenderableTest_TexturedTriangle();
	bool RenderableTest_ColoredSquare();
	bool RenderableTest_ColoredQuad();
	bool RenderableTest_VertexColoredSquare();
	bool RenderableTest_VertexColoredQuad();
	bool RenderableTest_ColoredCircle();
	bool RenderableTest_VertexColoredCircle();
	bool RenderableTest_TexturedCircle();
	bool RenderableTest_TexturedSquare();
	bool RenderableTest_TexturedQuad();
	bool RenderableTest_ColoredCube();
	bool RenderableTest_TexturedCube();
	bool RenderableTest_ColoredRectPrism();
	bool RenderableTest_TexturedRectPrism();
	bool RenderableTest_ColoredCylinder();
	bool RenderableTest_TexturedCylinder();

	bool UiRenderableTest_ColoredTriangle();
	bool UiRenderableTest_TexturedTriangle();
	bool UiRenderableTest_ColoredSquare();
	bool UiRenderableTest_TexturedSquare();
	bool UiRenderableTest_ColoredQuad();
	bool UiRenderableTest_TexturedQuad();
	bool UiRenderableTest_ColoredCircle();
	bool UiRenderableTest_TexturedCircle();

	void RunAllTests();
}
