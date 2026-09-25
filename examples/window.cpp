#include <onyx/core.hpp>
#include <onyx/window.hpp>
#include <onyx/renderer.hpp>
#include <onyx/input_handler.hpp>
#include <onyx/camera.hpp>
#include <onyx/monitor.hpp>

#include <functional>
#include <string>
#include <vector>

/*
	One line of live info text: `text` is rebuilt from `value()` every frame and placed with `place()`,
	which gets the text's width and the window's framebuffer size so rows can anchor to any corner.
 */
struct InfoLine
{
	std::function<std::string()> value;
	std::function<onyx::math::Vec2(float text_width, float buffer_width, float buffer_height)> place;
	onyx::TextRenderable text = onyx::TextRenderable();
};

static std::string bool_str(bool b) { return b ? "true" : "false"; }

// left-anchored, measured down from the top of the window
static auto top_left(float x, float y_from_top)
{
	return [=](float, float, float h) { return onyx::math::Vec2(x, h - y_from_top); };
}

// right-anchored, measured down from the top of the window
static auto top_right(float margin, float y_from_top)
{
	return [=](float text_w, float w, float h) { return onyx::math::Vec2(w - margin - text_w, h - y_from_top); };
}

int main()
{
	onyx::ErrorHandler error_handler(true, true);
	onyx::init(error_handler);
	onyx::set_resource_path(ONYX_EXAMPLE_RESOURCES);

	onyx::Window window(
		onyx::WindowProperties{
			.title = "Example: Window (1)",
			.width = 950,
			.height = 600,
			.position = onyx::math::IVec2(100, 100),
			.n_samples_msaa = 4,
			.background_color = onyx::math::Vec3::white()
		}
	);
	window.init();

	onyx::InputHandler input;
	window.link_input_handler(input);

	onyx::Camera cam(onyx::Projection::orthographic(950.0f, 600.0f));
	window.link_camera(cam);
	onyx::Renderer renderer(cam);
	window.link_renderer(renderer);

	onyx::Monitor monitor = onyx::Monitor::get_primary();

	onyx::Font roboto = onyx::Font::load(onyx::resources("fonts/Roboto/Roboto-Regular.ttf"), 16);

	std::vector<InfoLine> lines = {
		{ [&] { return "Title: " + window.get_title(); }, top_left(10.0f, 20.0f) },
		{ [&] { return "Dimensions: " + std::to_string(window.get_width()) + "x" + std::to_string(window.get_height()); }, top_left(10.0f, 40.0f) },
		{ [&] { return "Buffer Dimensions: " + std::to_string(window.get_buffer_width()) + "x" + std::to_string(window.get_buffer_height()); }, top_left(10.0f, 60.0f) },
		{ [&] { return "Position: " + window.get_position().to_string(); }, top_left(10.0f, 80.0f) },
		{ [&] { return "Frame: " + std::to_string(window.get_frame()); }, top_left(10.0f, 100.0f) },
		{ [&] { return "FPS: " + std::to_string(window.get_fps()); }, top_left(10.0f, 120.0f) },
		{ [&] { return "Background Color: " + window.get_background_color().to_string(); }, top_left(10.0f, 140.0f) },

		{ [&] { return "Delta Time: " + std::to_string(window.get_delta_time()) + "s"; }, top_left(260.0f, 20.0f) },
		{ [&] { return "Opacity: " + std::to_string(window.get_opacity()); }, top_left(260.0f, 40.0f) },
		{ [&] { return "Is Resizable: " + bool_str(window.is_resizable()); }, top_left(260.0f, 60.0f) },
		{ [&] { return "Is Visible: " + bool_str(window.is_visible()); }, top_left(260.0f, 80.0f) },
		{ [&] { return "Is Hidden: " + bool_str(window.is_hidden()); }, top_left(260.0f, 100.0f) },

		{ [&] { return "Is Focused: " + bool_str(window.is_focused()); }, top_left(510.0f, 20.0f) },
		{ [&] { return "Is Decorated: " + bool_str(window.is_decorated()); }, top_left(510.0f, 40.0f) },
		{ [&] { return "Is Topmost: " + bool_str(window.is_topmost()); }, top_left(510.0f, 60.0f) },
		{ [&] { return "Focuses On Show: " + bool_str(window.focuses_on_show()); }, top_left(510.0f, 80.0f) },
		{ [&] { return "# MSAA Samples: " + std::to_string(window.get_n_samples_msaa()); }, top_left(510.0f, 100.0f) },

		{ [&] { return "Is Fullscreen: " + bool_str(window.is_fullscreen()); }, top_left(760.0f, 20.0f) },
		{ [&] { return "Is Maximized: " + bool_str(window.is_maximized()); }, top_left(760.0f, 40.0f) },
		{ [&] { return "Is Minimized: " + bool_str(window.is_minimized()); }, top_left(760.0f, 60.0f) },

		{ [&] { return std::string("MONITOR INFO"); }, top_right(20.0f, 160.0f) },
		{ [&] { return "Name: " + monitor.get_name(); }, top_right(20.0f, 180.0f) },
		{ [&] { return "Dimensions: " + monitor.get_dimensions().to_string(); }, top_right(20.0f, 200.0f) },
		{ [&] { return "Bit Depth: " + monitor.get_bit_depth().to_string(); }, top_right(20.0f, 220.0f) },
		{ [&] { return "Refresh Rate: " + std::to_string(monitor.get_refresh_rate()) + "Hz"; }, top_right(20.0f, 240.0f) },
		{ [&] { return "Physical Size: " + monitor.get_physical_size().to_string(); }, top_right(20.0f, 260.0f) },
		{ [&] { return "Content Scale: " + monitor.get_content_scale().to_string(); }, top_right(20.0f, 280.0f) },
		{ [&] { return "Position: " + monitor.get_position().to_string(); }, top_right(20.0f, 300.0f) },
		{ [&] { return "Work Area: " + monitor.get_work_area().to_string(); }, top_right(20.0f, 320.0f) },
		{ [&] { return "Is Primary: " + bool_str(monitor.is_primary()); }, top_right(20.0f, 340.0f) },
	};

	for (InfoLine& line : lines)
	{
		line.text = onyx::TextRenderable(line.value(), roboto, onyx::math::Vec4::black());
	}
	// added after construction is complete so the renderer's pointers into `lines` stay valid
	for (InfoLine& line : lines) renderer.add(line.text);

	onyx::TextRenderable esc("[ESC] Close Window", roboto, onyx::math::Vec4::black());
	onyx::TextRenderable up("[UP] Increase Opacity", roboto, onyx::math::Vec4::black());
	onyx::TextRenderable down("[DOWN] Decrease Opacity", roboto, onyx::math::Vec4::black());
	onyx::TextRenderable f1 ("[F1] Toggle Title", roboto, onyx::math::Vec4::black());
	onyx::TextRenderable f2 ("[F2] Toggle Background Color From Mouse Pos", roboto, onyx::math::Vec4::black());
	onyx::TextRenderable f3 ("[F3] Focus Window", roboto, onyx::math::Vec4::black());
	onyx::TextRenderable f4 ("[F4] Toggle Resizable", roboto, onyx::math::Vec4::black());
	onyx::TextRenderable f5 ("[F5] Toggle Decorated", roboto, onyx::math::Vec4::black());
	onyx::TextRenderable f6 ("[F6] Toggle Topmost", roboto, onyx::math::Vec4::black());
	onyx::TextRenderable f7 ("[F7] Toggle Focus On Show", roboto, onyx::math::Vec4::black());
	onyx::TextRenderable f8 ("[F8] Minimize", roboto, onyx::math::Vec4::black());
	onyx::TextRenderable f9 ("[F9] Maximize", roboto, onyx::math::Vec4::black());
	onyx::TextRenderable f10("[F10] Restore", roboto, onyx::math::Vec4::black());
	onyx::TextRenderable f11("[F11] Request Attention", roboto, onyx::math::Vec4::black());
	onyx::TextRenderable f12("[F12] Toggle Fullscreen", roboto, onyx::math::Vec4::black());
	esc.set_position(onyx::math::Vec2(10.0f, 290.0f));
	up.set_position(onyx::math::Vec2(10.0f, 270.0f));
	down.set_position(onyx::math::Vec2(10.0f, 250.0f));
	f1.set_position(onyx::math::Vec2(10.0f, 230.0f));
	f2.set_position(onyx::math::Vec2(10.0f, 210.0f));
	f3.set_position(onyx::math::Vec2(10.0f, 190.0f));
	f4.set_position(onyx::math::Vec2(10.0f, 170.0f));
	f5.set_position(onyx::math::Vec2(10.0f, 150.0f));
	f6.set_position(onyx::math::Vec2(10.0f, 130.0f));
	f7.set_position(onyx::math::Vec2(10.0f, 110.0f));
	f8.set_position(onyx::math::Vec2(10.0f, 90.0f));
	f9.set_position(onyx::math::Vec2(10.0f, 70.0f));
	f10.set_position(onyx::math::Vec2(10.0f, 50.0f));
	f11.set_position(onyx::math::Vec2(10.0f, 30.0f));
	f12.set_position(onyx::math::Vec2(10.0f, 10.0f));

	onyx::UiRenderable logo = onyx::UiRenderable::textured_square(256.0f, onyx::Texture::load(onyx::resources("textures/onyx.png")));
	logo.set_position(onyx::math::Vec2(550.0f, 270.0f));
	logo.scale(0.6f);

	renderer.add(esc);
	renderer.add(up);
	renderer.add(down);
	renderer.add(f1);
	renderer.add(f2);
	renderer.add(f3);
	renderer.add(f4);
	renderer.add(f5);
	renderer.add(f6);
	renderer.add(f7);
	renderer.add(f8);
	renderer.add(f9);
	renderer.add(f10);
	renderer.add(f11);
	renderer.add(f12);

	renderer.add(logo);

	bool title1 = true;
	bool mouse_pos_is_color = false;

	while (window.is_open())
	{
		float dt = static_cast<float>(window.get_delta_time());

		input.update();
		cam.update();
		monitor = onyx::Monitor::get_primary();
		for (InfoLine& line : lines)
		{
			line.text.set_text(line.value());
			line.text.set_position(line.place(line.text.get_width(), (float)window.get_buffer_width(), (float)window.get_buffer_height()));
		}

		if (mouse_pos_is_color)
		{
			window.set_background_color(onyx::math::Vec3(static_cast<float>(input.get_mouse_pos().get_x() / window.get_width()), static_cast<float>(input.get_mouse_pos().get_y() / window.get_height()), 1.0f));
		}

		if (input.is_key_tapped(onyx::Key::Escape)) window.close();
		if (input.is_key_down(onyx::Key::ArrowUp)) window.set_opacity(window.get_opacity() + 0.5f * dt);
		if (input.is_key_down(onyx::Key::ArrowDown)) window.set_opacity(window.get_opacity() - 0.5f * dt);
		if (input.is_key_tapped(onyx::Key::F1))
		{
			if (title1)
			{
				window.set_title("Example: Window (2)");
				title1 = false;
			}
			else
			{
				window.set_title("Example: Window (1)");
				title1 = true;
			}
		}
		if (input.is_key_tapped(onyx::Key::F2)) mouse_pos_is_color = !mouse_pos_is_color;
		if (input.is_key_tapped(onyx::Key::F3)) window.focus();
		if (input.is_key_tapped(onyx::Key::F4)) window.toggle_resizable();
		if (input.is_key_tapped(onyx::Key::F5)) window.toggle_decorated();
		if (input.is_key_tapped(onyx::Key::F6)) window.toggle_topmost();
		if (input.is_key_tapped(onyx::Key::F7)) window.toggle_focus_on_show();
		if (input.is_key_tapped(onyx::Key::F8)) window.minimize();
		if (input.is_key_tapped(onyx::Key::F9)) window.maximize();
		if (input.is_key_tapped(onyx::Key::F10)) window.restore();
		if (input.is_key_tapped(onyx::Key::F11)) window.request_attention();
		if (input.is_key_tapped(onyx::Key::F12)) window.toggle_fullscreen(950, 600, onyx::math::IVec2(100, 100));

		window.start_render();
		renderer.render();
		window.end_render();
	}

	renderer.dispose();
	roboto.dispose();
	window.dispose();
	onyx::cleanup();
}
