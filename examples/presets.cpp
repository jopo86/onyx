#include <iostream>

#include <onyx/core.hpp>
#include <onyx/math_wrappers.hpp>
#include <onyx/window.hpp>
#include <onyx/monitor.hpp>
#include <onyx/input_handler.hpp>
#include <onyx/camera.hpp>

using onyx::ErrorHandler, onyx::Window, onyx::Monitor, onyx::WindowProperties, 
onyx::InputHandler, onyx::Mesh, onyx::Shader, onyx::Renderable, onyx::UiRenderable, 
onyx::Camera, onyx::Projection, onyx::Renderer, onyx::VertexBuffer,
onyx::IndexBuffer, onyx::Texture, onyx::Lighting, onyx::Key,
onyx::math::Vec2, onyx::math::Vec3, onyx::math::Vec4, onyx::math::IVec2,
onyx::init, onyx::cleanup, onyx::resources, onyx::set_resource_path;

int main() {
	ErrorHandler error_handler(true, true);
	init(error_handler);
	set_resource_path(ONYX_EXAMPLE_RESOURCES);
	Window window(WindowProperties{ .title = "Example: Presets", .width = 1280, .height = 720, .n_samples_msaa = 16 });
	window.init();

	window.set_background_color(onyx::math::Vec3(0.0f, 0.0f, 0.0f));
	Monitor primary_monitor = Monitor::get_primary();
	window.set_position(IVec2(primary_monitor.get_dimensions().get_x() / 2 - window.get_width() / 2, primary_monitor.get_dimensions().get_y() / 2 - window.get_height() / 2));

	InputHandler input;
	window.link_input_handler(input);

	Shader white_shader = Shader::p_color(Vec4(1.0f, 1.0f, 1.0f, 1.0f));
	Texture container = Texture::load(resources("textures/container.jpg"));
	Renderable mesh_presets[] = {
		Renderable(Mesh::triangle(1.0f), white_shader),
		Renderable(Mesh::triangle(1.0f, 1.0f), white_shader),
		Renderable(Mesh::square(1.0f), white_shader),
		Renderable(Mesh::quad(2.0f, 1.0f), white_shader),
		Renderable(Mesh::circle(0.5f, 50), white_shader),
		Renderable(Mesh::cube(1.0f), white_shader),
		Renderable(Mesh::rect_prism(1.0f, 1.0f, 1.0f), white_shader),
		Renderable(Mesh::cylinder(0.2f, 2.0f, 50, false, false), white_shader),
	};
	int len_mesh_presets = sizeof(mesh_presets) / sizeof(mesh_presets[0]);
	Renderable renderable_presets[] = {
		Renderable::colored_triangle(1.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)),
		Renderable::vertex_colored_triangle(1.0f),
		Renderable::textured_triangle(1.0f, container),
		Renderable::colored_square(1.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)),
		Renderable::colored_quad(2.0f, 1.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)),
		Renderable::vertex_colored_square(1.0f),
		Renderable::vertex_colored_quad(2.0f, 1.0f),
		Renderable::colored_circle(0.5f, 50, Vec4(0.0f, 1.0f, 0.0f, 1.0f)),
		Renderable::vertex_colored_circle(0.5f, 50),
		Renderable::textured_circle(0.5f, 50, container),
		Renderable::textured_square(1.0f, container),
		Renderable::textured_quad(2.0f, 1.0f, container),
		Renderable::colored_cube(1.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)),
		Renderable::textured_cube(1.0f, container),
		Renderable::colored_rect_prism(2.0f, 1.0f, 1.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)),
		Renderable::textured_rect_prism(2.0f, 1.0f, 1.0f, container),
		Renderable::colored_cylinder(0.2f, 2.0f, 50, Vec4(0.0f, 1.0f, 0.0f, 1.0f)),
		Renderable::textured_cylinder(0.2f, 2.0f, 50, container),
	};
	int len_renderable_presets = sizeof(renderable_presets) / sizeof(renderable_presets[0]);
	UiRenderable ui_renderable_presets[] = {
		UiRenderable::colored_triangle(100.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)),
		UiRenderable::textured_triangle(100.0f, container),
		UiRenderable::colored_square(100.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)),
		UiRenderable::textured_square(100.0f, container),
		UiRenderable::colored_quad(200.0f, 100.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)),
		UiRenderable::textured_quad(200.0f, 100.0f, container),
		UiRenderable::colored_circle(50.0f, 50, Vec4(0.0f, 1.0f, 0.0f, 1.0f)),
		UiRenderable::textured_circle(50.0f, 50, container),
	};
	int len_ui_renderable_presets = sizeof(ui_renderable_presets) / sizeof(ui_renderable_presets[0]);

	Camera cam(Projection::perspective(60.0f, 1280, 720));
	window.link_camera(cam);
	cam.translate_fb(-2.0f);

	Lighting lighting(Vec3::white(), 0.3f, Vec3(-0.2f, -1.0f, -0.3f));

	Renderer renderer(cam, lighting);
	window.link_renderer(renderer);

	for (Renderable& r : mesh_presets) {
		r.hide();
		renderer.add(r);
	}
	for (Renderable& r : renderable_presets) {
		r.hide();
		renderer.add(r);
	}
	for (UiRenderable& r : ui_renderable_presets) {
		r.hide();
		r.set_position(Vec2(300, 300));
		renderer.add(r);
	}

	int len_all_presets = len_mesh_presets + len_renderable_presets + len_ui_renderable_presets;

	auto set_preset_visible = [&](int idx, bool visible) {
		if (idx < len_mesh_presets) {
			if (visible) mesh_presets[idx].show();
			else mesh_presets[idx].hide();
		} else if (idx < len_mesh_presets + len_renderable_presets) {
			Renderable& r = renderable_presets[idx - len_mesh_presets];
			if (visible) r.show();
			else r.hide();
		} else {
			UiRenderable& r = ui_renderable_presets[idx - len_mesh_presets - len_renderable_presets];
			if (visible) r.show();
			else r.hide();
		}
	};

	int i = 0;
	set_preset_visible(i, true);

	const float CAM_SPEED = 4.0f;
	const float CAM_SENS = 50.0f;

	input.set_cursor_lock(true);

	std::cout << "Press [ENTER] to move on to the next preset.\n";

	while (window.is_open())
	{
		input.update();

		float dt = static_cast<float>(window.get_delta_time());

		if (input.is_key_down(Key::Escape)) window.close();
		if (input.is_key_tapped(Key::Num1)) Renderer::toggle_wireframe();
		if (input.is_key_down(Key::W)) cam.translate_fb( CAM_SPEED * dt);
		if (input.is_key_down(Key::A)) cam.translate_lr(-CAM_SPEED * dt);
		if (input.is_key_down(Key::S)) cam.translate_fb(-CAM_SPEED * dt);
		if (input.is_key_down(Key::D)) cam.translate_lr( CAM_SPEED * dt);
		if (input.is_key_down(Key::Space)) cam.translate_ud( CAM_SPEED * dt);
		if (input.is_key_down(Key::C)) cam.translate_ud(-CAM_SPEED * dt);
		if (input.is_key_tapped(Key::Enter)) {
			set_preset_visible(i, false);
			i++;
			if (i == len_all_presets) window.close();
			else set_preset_visible(i, true);
		}

		cam.rotate(CAM_SENS / 200 * static_cast<float>(input.get_mouse_deltas().get_x()), CAM_SENS / 200 * static_cast<float>(input.get_mouse_deltas().get_y()));
		cam.update();

		window.start_render();
		renderer.render();
		window.end_render();
	}

	window.dispose();
	renderer.dispose();

	cleanup();

	return 0;
}
