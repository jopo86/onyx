#pragma once

#include <vector>

#include "../src/core.h"
#include "../src/error_handler.h"
#include "../src/window.h"
#include "../src/index_buffer.h"
#include "../src/texture.h"
#include "../src/shader.h"
#include "../src/renderer.h"
#include "../src/projection.h"
#include "../src/mesh.h"
#include "../src/input_handler.h"
#include "../src/font.h"
#include "../src/camera.h"

namespace preset_tests
{
	bool run_mesh_test(onyx::Window& window, onyx::Mesh mesh);
	bool run_renderable_test(onyx::Window& window, onyx::Renderable renderable);
	bool run_ui_renderable_test(onyx::Window& window, onyx::UiRenderable renderable);

	bool mesh_test_triangle1();
	bool mesh_test_triangle2();
	bool mesh_test_square();
	bool mesh_test_quad();
	bool mesh_test_circle();
	bool mesh_test_cube();
	bool mesh_test_rect_prism();
	bool mesh_test_cylinder();

	bool renderable_test_colored_triangle();
	bool renderable_test_vertex_colored_triangle();
	bool renderable_test_textured_triangle();
	bool renderable_test_colored_square();
	bool renderable_test_colored_quad();
	bool renderable_test_vertex_colored_square();
	bool renderable_test_vertex_colored_quad();
	bool renderable_test_colored_circle();
	bool renderable_test_vertex_colored_circle();
	bool renderable_test_textured_circle();
	bool renderable_test_textured_square();
	bool renderable_test_textured_quad();
	bool renderable_test_colored_cube();
	bool renderable_test_textured_cube();
	bool renderable_test_colored_rect_prism();
	bool renderable_test_textured_rect_prism();
	bool renderable_test_colored_cylinder();
	bool renderable_test_textured_cylinder();

	bool ui_renderable_test_colored_triangle();
	bool ui_renderable_test_textured_triangle();
	bool ui_renderable_test_colored_square();
	bool ui_renderable_test_textured_square();
	bool ui_renderable_test_colored_quad();
	bool ui_renderable_test_textured_quad();
	bool ui_renderable_test_colored_circle();
	bool ui_renderable_test_textured_circle();

	void run_all_tests();
}
