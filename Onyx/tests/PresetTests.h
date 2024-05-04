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
	bool RunBufferTest(Onyx::Window& window, Onyx::VertexBuffer vb, Onyx::IndexBuffer ib);

	bool MeshTest_Triangle1();
	bool MeshTest_Triangle2();
	bool MeshTest_Triangle3();
	bool MeshTest_Square();
	bool MeshTest_Quad1();
	bool MeshTest_Quad2();
	bool MeshTest_Cube();
	bool MeshTest_RectPrism1();
	bool MeshTest_RectPrism2();

	bool RenderableTest_ColoredTriangle();
	bool RenderableTest_VertexColoredTriangle();
	bool RenderableTest_TexturedTriangle();
	bool RenderableTest_ColoredSquare();
	bool RenderableTest_ColoredQuad();
	bool RenderableTest_VertexColoredSquare();
	bool RenderableTest_VertexColoredQuad();
	bool RenderableTest_TexturedSquare();
	bool RenderableTest_TexturedQuad();
	bool RenderableTest_ColoredCube();
	bool RenderableTest_TexturedCube();

	bool UiRenderableTest_ColoredTriangle();
	bool UiRenderableTest_TexturedTriangle();
	bool UiRenderableTest_ColoredSquare();
	bool UiRenderableTest_TexturedSquare();
	bool UiRenderableTest_ColoredQuad();
	bool UiRenderableTest_TexturedQuad();

	bool BufferTest_Triangle();
	bool BufferTest_Square();
	bool BufferTest_Quad();
	bool BufferTest_Cube();
	bool BufferTest_RectPrism();

	void RunAllTests();
}
