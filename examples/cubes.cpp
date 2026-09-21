#include <cmath>
#include <iostream>
#include <vector>

#include <onyx/core.hpp>
#include <onyx/math_wrappers.hpp>
#include <onyx/window.hpp>
#include <onyx/monitor.hpp>
#include <onyx/input_handler.hpp>
#include <onyx/camera.hpp>
#include <onyx/renderer.hpp>
#include <onyx/renderable.hpp>
#include <onyx/ui_renderable.hpp>
#include <onyx/text_renderable.hpp>
#include <onyx/font.hpp>
#include <onyx/texture.hpp>

using onyx::math::Vec2, onyx::math::Vec3, onyx::math::Vec4;

namespace
{
	constexpr int GRID_COLS = 4;
	constexpr int GRID_ROWS = 2;
	constexpr int CUBE_COUNT = GRID_COLS * GRID_ROWS;
	constexpr float CUBE_SIZE = 1.0f;
	constexpr float CUBE_SPACING = 2.0f;

	// Each cube gets its own angular velocity, in degrees per second, so no two tumble alike.
	const Vec3 SPINS[CUBE_COUNT] = {
		Vec3(  0.0f,  45.0f,   0.0f),	// yaw
		Vec3( 45.0f,   0.0f,   0.0f),	// pitch
		Vec3(  0.0f,   0.0f,  45.0f),	// roll
		Vec3( 30.0f,  30.0f,   0.0f),
		Vec3(  0.0f,  30.0f,  30.0f),
		Vec3( 30.0f,   0.0f,  30.0f),
		Vec3( 25.0f,  25.0f,  25.0f),	// full tumble
		Vec3(  0.0f, -75.0f,   0.0f),	// fast, reversed
	};
}

int main()
{
	bool implicit_init = !onyx::is_initialized();
	onyx::ErrorHandler error_handler(true, true);
	if (implicit_init) onyx::init(error_handler);
	onyx::set_resource_path(ONYX_EXAMPLE_RESOURCES);

	onyx::Monitor primary_monitor = onyx::Monitor::get_primary();

	onyx::Window window(
		onyx::WindowProperties{
			.title = "Example: Cubes",
			.width = 1280,
			.height = 720,
			.position = onyx::math::IVec2(primary_monitor.get_dimensions().get_x() / 2 - 1280 / 2, primary_monitor.get_dimensions().get_y() / 2 - 720 / 2),
			.n_samples_msaa = 4,
			.background_color = Vec3(0.0f, 0.7f, 1.0f)
		}
	);
	window.init();

	onyx::WindowIcon icon = onyx::WindowIcon::load({
		onyx::resources("icons/icon-16x.png"),
		onyx::resources("icons/icon-24x.png"),
		onyx::resources("icons/icon-32x.png"),
		onyx::resources("icons/icon-48x.png"),
		onyx::resources("icons/icon-256x.png"),
	});

	onyx::Renderer::set_vsync(false);

	window.set_icon(icon);
	icon.dispose();

	onyx::InputHandler input;
	window.link_input_handler(input);

	float bg_vertices[] = {
		0.0f,   110.0f, 0.0f,
		200.0f, 110.0f, 0.0f,
		200.0f, 0.0f,   0.0f,
		0.0f,   0.0f,   0.0f
	};

	u32 bg_indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	float logo_vertices[] = {
		0.0f,   0.0f,   0.0f,	0.0f, 0.0f,
		75.0f,  0.0f,   0.0f,	1.0f, 0.0f,
		75.0f,  75.0f,  0.0f,	1.0f, 1.0f,
		0.0f,   75.0f,  0.0f,	0.0f, 1.0f
	};

	u32 logo_indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	onyx::Camera cam(onyx::Projection::perspective(60.0f, 1280, 720));
	window.link_camera(cam);
	cam.set_position(Vec3(0.0f, 0.0f, 9.0f));

	// Key light from up/right/behind-the-camera so the faces pointing at the viewer are lit.
	// A near-vertical direction (the old demo's) leaves the camera-facing faces almost black.
	onyx::Lighting lighting(Vec3(1.0f, 1.0f, 1.0f), 0.35f, Vec3(-0.35f, -0.5f, -0.8f));
	onyx::Fog fog(window.get_background_color(), 14.0f, 30.0f);

	onyx::Renderer renderer(cam, lighting, fog);
	window.link_renderer(renderer);

	float start = onyx::get_time();
	onyx::Font roboto_reg = onyx::Font::load(onyx::resources("fonts/Roboto/Roboto-Regular.ttf"), 32);
	onyx::Font roboto_bold = onyx::Font::load(onyx::resources("fonts/Roboto/Roboto-Bold.ttf"), 32);
	float duration = std::round((onyx::get_time() - start) * 1000);

	start = onyx::get_time();

	const Vec4 colors[CUBE_COUNT] = {
		Vec4::red(), Vec4::orange(), Vec4::yellow(), Vec4::green(),
		Vec4::cyan(), Vec4::blue(), Vec4::purple(), Vec4::pink(),
	};

	// A 4x2 grid centred on the origin, so the camera can just sit back along +Z.
	std::vector<onyx::Renderable> cubes;
	cubes.reserve(CUBE_COUNT);
	for (int row = 0; row < GRID_ROWS; row++)
	{
		for (int col = 0; col < GRID_COLS; col++)
		{
			int i = row * GRID_COLS + col;
			float x = (col - (GRID_COLS - 1) / 2.0f) * CUBE_SPACING;
			float y = ((GRID_ROWS - 1) / 2.0f - row) * CUBE_SPACING;

			cubes.push_back(onyx::Renderable::colored_cube(CUBE_SIZE, colors[i]));
			cubes.back().set_position(Vec3(x, y, 0.0f));
			cubes.back().set_rotation(Vec3(onyx::math::rand(0.0f, 360.0f), onyx::math::rand(0.0f, 360.0f), onyx::math::rand(0.0f, 360.0f)));
		}
	}

	onyx::UiRenderable text_bg(
		onyx::Mesh(onyx::VertexBuffer(bg_vertices, sizeof(bg_vertices), onyx::VertexFormat::P), onyx::IndexBuffer(bg_indices, sizeof(bg_indices))),
		Vec4(0.0f, 0.0f, 0.0f, 0.3f)
	);
	text_bg.set_position(Vec2(10.0f, window.get_buffer_height() - 120.0f));

	onyx::UiRenderable logo(
		onyx::Mesh(onyx::VertexBuffer(logo_vertices, sizeof(logo_vertices), onyx::VertexFormat::PT), onyx::IndexBuffer(logo_indices, sizeof(logo_indices))),
		onyx::Texture::load(onyx::resources("textures/onyx.png"))
	);
	logo.set_position(Vec2(window.get_buffer_width() - 90.0f, window.get_buffer_height() - 90.0f));

	std::vector<onyx::TextRenderable> text_renderables;

	text_renderables.push_back(onyx::TextRenderable("Cubes", roboto_bold, Vec3(1.0f, 1.0f, 1.0f)));
	text_renderables.push_back(onyx::TextRenderable("FPS: 0", roboto_reg, Vec3(1.0f, 1.0f, 1.0f)));
	text_renderables.push_back(onyx::TextRenderable("FRAME 0", roboto_reg, Vec3(1.0f, 1.0f, 1.0f)));
	text_renderables.push_back(onyx::TextRenderable("Toggle Fullscreen: [F12]", roboto_reg, Vec3(1.0f, 1.0f, 1.0f)));
	text_renderables.push_back(onyx::TextRenderable("Toggle Lighting: [F3]", roboto_reg, Vec3(1.0f, 1.0f, 1.0f)));
	text_renderables.push_back(onyx::TextRenderable("Toggle Cubes: [F2]", roboto_reg, Vec3(1.0f, 1.0f, 1.0f)));
	text_renderables.push_back(onyx::TextRenderable("Toggle Wireframe: [F1]", roboto_reg, Vec3(1.0f, 1.0f, 1.0f)));
	text_renderables.push_back(onyx::TextRenderable("Mouse to look around", roboto_reg, Vec3(1.0f, 1.0f, 1.0f)));
	text_renderables.push_back(onyx::TextRenderable("Up/Down: [Space]/[C]", roboto_reg, Vec3(1.0f, 1.0f, 1.0f)));
	text_renderables.push_back(onyx::TextRenderable("Forward/Left/Backward/Right: [W]/[A]/[S]/[D]", roboto_reg, Vec3(1.0f, 1.0f, 1.0f)));
	text_renderables.push_back(onyx::TextRenderable("Exit: [ESCAPE]", roboto_reg, Vec3(1.0f, 1.0f, 1.0f)));

	text_renderables[0].set_position(Vec2(23.0f, window.get_buffer_height() - 50.0f));
	text_renderables[1].set_position(Vec2(25.0f, window.get_buffer_height() - 80.0f));
	text_renderables[1].set_scale(0.6f);
	text_renderables[2].set_position(Vec2(25.0f, window.get_buffer_height() - 100.0f));
	text_renderables[2].set_scale(0.6f);
	for (int i = 3; i <= 10; i++)
	{
		text_renderables[i].set_position(Vec2(25.0f, 30.0f + 25.0f * (i - 3)));
		text_renderables[i].set_scale(0.6f);
	}

	duration = std::round((onyx::get_time() - start) * 1000);

	for (onyx::Renderable& cube : cubes) renderer.add(cube);
	renderer.add(text_bg);
	renderer.add(logo);
	for (onyx::TextRenderable& tr : text_renderables) renderer.add(tr);

	const double MOVE_SPEED = 6.0;
	const double MOUSE_SENS = 30.0;

	const float DEAD_ZONE_LEFT = 0.1f;
	const float DEAD_ZONE_RIGHT = 0.1f;

	input.set_cursor_lock(true);

	int fps = 0;

	while (window.is_open())
	{
		input.update();
		double dx = input.get_mouse_deltas().get_x();
		double dy = input.get_mouse_deltas().get_y();
		float lsx = 0.0f, lsy = 0.0f, rsx = 0.0f, rsy = 0.0f;
		bool a = false, b = false, rs = false;
		double dt = window.get_delta_time();

		if (window.get_frame() % 100 == 0 || window.get_frame() == 2) fps = window.get_fps();

		if (input.is_key_down(onyx::Key::Escape)) window.close();
		if (input.is_key_down(onyx::Key::W)) cam.translate_fb(MOVE_SPEED * dt);
		if (input.is_key_down(onyx::Key::A)) cam.translate_lr(-MOVE_SPEED * dt);
		if (input.is_key_down(onyx::Key::S)) cam.translate_fb(-MOVE_SPEED * dt);
		if (input.is_key_down(onyx::Key::D)) cam.translate_lr(MOVE_SPEED * dt);
		if (input.is_key_down(onyx::Key::Space)) cam.translate_ud(MOVE_SPEED * dt);
		if (input.is_key_down(onyx::Key::C)) cam.translate_ud(-MOVE_SPEED * dt);
		if (input.is_key_tapped(onyx::Key::F12)) window.toggle_fullscreen(1280, 720, onyx::math::IVec2(100, 100));
		if (input.is_key_tapped(onyx::Key::F1)) onyx::Renderer::toggle_wireframe();
		if (input.is_key_tapped(onyx::Key::F2)) for (onyx::Renderable& cube : cubes) cube.toggle_visibility();
		if (input.is_key_tapped(onyx::Key::F3)) renderer.toggle_lighting_enabled();

		for (int i = 0; i < CUBE_COUNT; i++) cubes[i].rotate(SPINS[i] * (float)dt);

		cam.rotate(MOUSE_SENS * .005 * dx, MOUSE_SENS * .005 * dy);
		cam.set_fov(cam.get_projection().get_fov() - input.get_scroll_deltas().get_y());

		for (const onyx::Gamepad& gp : input.get_gamepads())
		{
			if (std::abs(gp.get_axis(onyx::GamepadAxis::LeftX)) > lsx) lsx = gp.get_axis(onyx::GamepadAxis::LeftX);
			if (std::abs(gp.get_axis(onyx::GamepadAxis::LeftY)) > lsy) lsy = gp.get_axis(onyx::GamepadAxis::LeftY);
			if (std::abs(gp.get_axis(onyx::GamepadAxis::RightX)) > rsx) rsx = gp.get_axis(onyx::GamepadAxis::RightX);
			if (std::abs(gp.get_axis(onyx::GamepadAxis::RightY)) > rsy) rsy = gp.get_axis(onyx::GamepadAxis::RightY);
			if (gp.is_button_down(onyx::GamepadButton::A)) a = true;
			if (gp.is_button_down(onyx::GamepadButton::B)) b = true;
			if (gp.is_button_down(onyx::GamepadButton::RightStick)) rs = true;
		}

		lsx = std::abs(lsx) < DEAD_ZONE_LEFT ? 0.0f : lsx;
		lsy = std::abs(lsy) < DEAD_ZONE_LEFT ? 0.0f : lsy;
		rsx = std::abs(rsx) < DEAD_ZONE_RIGHT ? 0.0f : rsx;
		rsy = std::abs(rsy) < DEAD_ZONE_RIGHT ? 0.0f : rsy;

		cam.translate_fb(MOVE_SPEED * dt * lsy);
		cam.translate_lr(MOVE_SPEED * dt * lsx);
		if (a) cam.translate_ud(MOVE_SPEED * dt);
		if (b || rs) cam.translate_ud(-MOVE_SPEED * dt);

		cam.rotate(MOUSE_SENS * 10.0f * dt * rsx, MOUSE_SENS * 10.0f * dt * rsy);

		cam.update();

		text_renderables[1].set_text("FPS: " + std::to_string(fps));
		text_renderables[2].set_text("FRAME " + std::to_string(window.get_frame()));

		text_renderables[0].set_position(Vec2(23.0f, window.get_buffer_height() - 50.0f));
		text_renderables[1].set_position(Vec2(25.0f, window.get_buffer_height() - 80.0f));
		text_renderables[2].set_position(Vec2(25.0f, window.get_buffer_height() - 100.0f));
		text_bg.set_position(Vec2(10.0f, window.get_buffer_height() - 120.0f));
		logo.set_position(Vec2(window.get_buffer_width() - 90.0f, window.get_buffer_height() - 90.0f));

		window.start_render();
		renderer.render();
		window.end_render();
	}

	renderer.dispose();
	window.dispose();
	roboto_reg.dispose();
	roboto_bold.dispose();

	if (implicit_init) onyx::cleanup();
}
