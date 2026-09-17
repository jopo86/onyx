#pragma warning(disable: 4244)

#include "window_test.h"

#include "../src/core.h"
#include "../src/window.h"
#include "../src/renderer.h"
#include "../src/input_handler.h"
#include "../src/camera.h"

static onyx::Window window;

static onyx::TextRenderable title;
static onyx::TextRenderable dimensions;
static onyx::TextRenderable buffer_dimensions;
static onyx::TextRenderable position;
static onyx::TextRenderable frame;
static onyx::TextRenderable fps;
static onyx::TextRenderable delta_time;
static onyx::TextRenderable opacity;
static onyx::TextRenderable background_color;
static onyx::TextRenderable is_resizable;
static onyx::TextRenderable is_visible;
static onyx::TextRenderable is_hidden;
static onyx::TextRenderable is_focused;
static onyx::TextRenderable is_decorated;
static onyx::TextRenderable is_topmost;
static onyx::TextRenderable focuses_on_show;
static onyx::TextRenderable n_samples_msaa;
static onyx::TextRenderable is_fullscreen;
static onyx::TextRenderable is_maximized;
static onyx::TextRenderable is_minimized;

static onyx::TextRenderable monitor_label;
static onyx::TextRenderable monitor_name;
static onyx::TextRenderable monitor_dimensions;
static onyx::TextRenderable monitor_bit_depth;
static onyx::TextRenderable monitor_refresh_rate;
static onyx::TextRenderable monitor_physical_size;
static onyx::TextRenderable monitor_content_scale;
static onyx::TextRenderable monitor_position;
static onyx::TextRenderable monitor_work_area;
static onyx::TextRenderable monitor_is_primary;

static onyx::Font roboto;

void update_text();
void update_positions();

void window_test::run()
{
	onyx::ErrorHandler error_handler(true, true);
	onyx::init(error_handler);

	window = onyx::Window(
		onyx::WindowProperties{
			.title = "Title 1",
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

	roboto = onyx::Font::load(onyx::resources("fonts/Roboto/Roboto-Regular.ttf"), 16);

	title =             onyx::TextRenderable("Title: " + window.get_title(), roboto, onyx::math::Vec4::black());
	dimensions =        onyx::TextRenderable("Dimensions: " + std::to_string(window.get_width()) + "x" + std::to_string(window.get_height()), roboto, onyx::math::Vec4::black());
	buffer_dimensions =  onyx::TextRenderable("Buffer Dimensions: " + std::to_string(window.get_buffer_width()) + "x" + std::to_string(window.get_buffer_height()), roboto, onyx::math::Vec4::black());
	position =          onyx::TextRenderable("Position: " + window.get_position().to_string(), roboto, onyx::math::Vec4::black());
	frame =             onyx::TextRenderable("Frame: " + std::to_string(window.get_frame()), roboto, onyx::math::Vec4::black());
	fps =               onyx::TextRenderable("FPS: " + std::to_string(window.get_fps()), roboto, onyx::math::Vec4::black());
	delta_time =         onyx::TextRenderable("Delta Time: " + std::to_string(window.get_delta_time()) + "s", roboto, onyx::math::Vec4::black());
	opacity =			onyx::TextRenderable("Opacity: " + std::to_string(window.get_opacity()), roboto, onyx::math::Vec4::black());
	background_color =	onyx::TextRenderable("Background Color: " + window.get_background_color().to_string(), roboto, onyx::math::Vec4::black());
	is_resizable =		onyx::TextRenderable("Is Resizable: " + std::string(window.is_resizable() ? "true" : "false"), roboto, onyx::math::Vec4::black());
	is_visible =			onyx::TextRenderable("Is Visible: " + std::string(window.is_visible() ? "true" : "false"), roboto, onyx::math::Vec4::black());
	is_hidden =			onyx::TextRenderable("Is Hidden: " + std::string(window.is_hidden() ? "true" : "false"), roboto, onyx::math::Vec4::black());
	is_focused =			onyx::TextRenderable("Is Focused: " + std::string(window.is_focused() ? "true" : "false"), roboto, onyx::math::Vec4::black());
	is_decorated =		onyx::TextRenderable("Is Decorated: " + std::string(window.is_decorated() ? "true" : "false"), roboto, onyx::math::Vec4::black());
	is_topmost =			onyx::TextRenderable("Is Topmost: " + std::string(window.is_topmost() ? "true" : "false"), roboto, onyx::math::Vec4::black());
	focuses_on_show =		onyx::TextRenderable("Focuses On Show: " + std::string(window.focuses_on_show() ? "true" : "false"), roboto, onyx::math::Vec4::black());
	n_samples_msaa =		onyx::TextRenderable("# MSAA Samples: " + std::to_string(window.get_n_samples_msaa()), roboto, onyx::math::Vec4::black());
	is_fullscreen =		onyx::TextRenderable("Is Fullscreen: " + std::string(window.is_fullscreen() ? "true" : "false"), roboto, onyx::math::Vec4::black());
	is_maximized =		onyx::TextRenderable("Is Maximized: " + std::string(window.is_maximized() ? "true" : "false"), roboto, onyx::math::Vec4::black());
	is_minimized =		onyx::TextRenderable("Is Minimized: " + std::string(window.is_minimized() ? "true" : "false"), roboto, onyx::math::Vec4::black());

	monitor_label =		onyx::TextRenderable("MONITOR INFO", roboto, onyx::math::Vec4::black());
	monitor_name =		onyx::TextRenderable("Name: " + monitor.get_name(), roboto, onyx::math::Vec4::black());
	monitor_dimensions =	onyx::TextRenderable("Dimensions: " + monitor.get_dimensions().to_string(), roboto, onyx::math::Vec4::black());
	monitor_bit_depth =	onyx::TextRenderable("Bit Depth: " + monitor.get_bit_depth().to_string(), roboto, onyx::math::Vec4::black());
	monitor_refresh_rate = onyx::TextRenderable("Refresh Rate: " + std::to_string(monitor.get_refresh_rate()) + "Hz", roboto, onyx::math::Vec4::black());
	monitor_physical_size = onyx::TextRenderable("Physical Size: " + monitor.get_physical_size().to_string(), roboto, onyx::math::Vec4::black());
	monitor_content_scale = onyx::TextRenderable("Content Scale: " + monitor.get_content_scale().to_string(), roboto, onyx::math::Vec4::black());
	monitor_position =	onyx::TextRenderable("Position: " + monitor.get_position().to_string(), roboto, onyx::math::Vec4::black());
	monitor_work_area =	onyx::TextRenderable("Work Area: " + monitor.get_work_area().to_string(), roboto, onyx::math::Vec4::black());
	monitor_is_primary =	onyx::TextRenderable("Is Primary: " + std::string(monitor.is_primary() ? "true" : "false"), roboto, onyx::math::Vec4::black());

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

	renderer.add(title);
	renderer.add(dimensions);
	renderer.add(buffer_dimensions);
	renderer.add(position);
	renderer.add(frame);
	renderer.add(fps);
	renderer.add(delta_time);
	renderer.add(opacity);
	renderer.add(background_color);
	renderer.add(is_resizable);
	renderer.add(is_visible);
	renderer.add(is_hidden);
	renderer.add(is_focused);
	renderer.add(is_decorated);
	renderer.add(is_topmost);
	renderer.add(focuses_on_show);
	renderer.add(n_samples_msaa);
	renderer.add(is_fullscreen);
	renderer.add(is_maximized);
	renderer.add(is_minimized);

	renderer.add(monitor_label);
	renderer.add(monitor_name);
	renderer.add(monitor_dimensions);
	renderer.add(monitor_bit_depth);
	renderer.add(monitor_refresh_rate);
	renderer.add(monitor_physical_size);
	renderer.add(monitor_content_scale);
	renderer.add(monitor_position);
	renderer.add(monitor_work_area);
	renderer.add(monitor_is_primary);

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
		double dt = window.get_delta_time();

		input.update();
		cam.update();
		update_text();
		update_positions();

		if (mouse_pos_is_color)
		{
			window.set_background_color(onyx::math::Vec3(input.get_mouse_pos().get_x() / window.get_width(), input.get_mouse_pos().get_y() / window.get_height(), 1.0f));
		}

		if (input.is_key_tapped(onyx::Key::Escape)) window.close();
		if (input.is_key_tapped(onyx::Key::ArrowUp)) window.set_opacity(window.get_opacity() + 0.5 * dt);
		if (input.is_key_tapped(onyx::Key::ArrowDown)) window.set_opacity(window.get_opacity() - 0.5 * dt);
		if (input.is_key_tapped(onyx::Key::F1))
		{
			if (title1)
			{
				window.set_title("Title 2");
				title1 = false;
			}
			else
			{
				window.set_title("Title 1");
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
	window.dispose();
	onyx::cleanup();
}

void update_text()
{
	title.set_text("Title: " + window.get_title());
	dimensions.set_text("Dimensions: " + std::to_string(window.get_width()) + "x" + std::to_string(window.get_height()));
	buffer_dimensions.set_text("Buffer Dimensions: " + std::to_string(window.get_buffer_width()) + "x" + std::to_string(window.get_buffer_height()));
	position.set_text("Position: " + window.get_position().to_string());
	frame.set_text("Frame: " + std::to_string(window.get_frame()));
	fps.set_text("FPS: " + std::to_string(window.get_fps()));
	delta_time.set_text("Delta Time: " + std::to_string(window.get_delta_time()) + "s");
	opacity.set_text("Opacity: " + std::to_string(window.get_opacity()));
	background_color.set_text("Background Color: " + window.get_background_color().to_string());
	is_resizable.set_text("Is Resizable: " + std::string(window.is_resizable() ? "true" : "false"));
	is_visible.set_text("Is Visible: " + std::string(window.is_visible() ? "true" : "false"));
	is_hidden.set_text("Is Hidden: " + std::string(window.is_hidden() ? "true" : "false"));
	is_focused.set_text("Is Focused: " + std::string(window.is_focused() ? "true" : "false"));
	is_decorated.set_text("Is Decorated: " + std::string(window.is_decorated() ? "true" : "false"));
	is_topmost.set_text("Is Topmost: " + std::string(window.is_topmost() ? "true" : "false"));
	focuses_on_show.set_text("Focuses On Show: " + std::string(window.focuses_on_show() ? "true" : "false"));
	n_samples_msaa.set_text("# MSAA Samples: " + std::to_string(window.get_n_samples_msaa()));
	is_fullscreen.set_text("Is Fullscreen: " + std::string(window.is_fullscreen() ? "true" : "false"));
	is_maximized.set_text("Is Maximized: " + std::string(window.is_maximized() ? "true" : "false"));
	is_minimized.set_text("Is Minimized: " + std::string(window.is_minimized() ? "true" : "false"));	

	monitor_name.set_text("Name: " + onyx::Monitor::get_primary().get_name());
	monitor_dimensions.set_text("Dimensions: " + onyx::Monitor::get_primary().get_dimensions().to_string());
	monitor_bit_depth.set_text("Bit Depth: " + onyx::Monitor::get_primary().get_bit_depth().to_string());
	monitor_refresh_rate.set_text("Refresh Rate: " + std::to_string(onyx::Monitor::get_primary().get_refresh_rate()) + "Hz");
	monitor_physical_size.set_text("Physical Size: " + onyx::Monitor::get_primary().get_physical_size().to_string());
	monitor_content_scale.set_text("Content Scale: " + onyx::Monitor::get_primary().get_content_scale().to_string());
	monitor_position.set_text("Position: " + onyx::Monitor::get_primary().get_position().to_string());
	monitor_work_area.set_text("Work Area: " + onyx::Monitor::get_primary().get_work_area().to_string());
	monitor_is_primary.set_text("Is Primary: " + std::string(onyx::Monitor::get_primary().is_primary() ? "true" : "false"));
}

void update_positions()
{
	title.set_position(onyx::math::Vec2(10.0f, window.get_buffer_height() - 20.0f));
	dimensions.set_position(onyx::math::Vec2(10.0f, window.get_buffer_height() - 40.0f));
	buffer_dimensions.set_position(onyx::math::Vec2(10.0f, window.get_buffer_height() - 60.0f));
	position.set_position(onyx::math::Vec2(10.0f, window.get_buffer_height() - 80.0f));
	frame.set_position(onyx::math::Vec2(10.0f, window.get_buffer_height() - 100.0f));
	fps.set_position(onyx::math::Vec2(10.0f, window.get_buffer_height() - 120.0f));
	background_color.set_position(onyx::math::Vec2(10.0f, window.get_buffer_height() - 140.0f));
	delta_time.set_position(onyx::math::Vec2(260.0f, window.get_buffer_height() - 20.0f));
	opacity.set_position(onyx::math::Vec2(260.0f, window.get_buffer_height() - 40.0f));
	is_resizable.set_position(onyx::math::Vec2(260.0f, window.get_buffer_height() - 60.0f));
	is_visible.set_position(onyx::math::Vec2(260.0f, window.get_buffer_height() - 80.0f));
	is_hidden.set_position(onyx::math::Vec2(260.0f, window.get_buffer_height() - 100.0f));
	is_focused.set_position(onyx::math::Vec2(510.0f, window.get_buffer_height() - 20));
	is_decorated.set_position(onyx::math::Vec2(510.0f, window.get_buffer_height() - 40));
	is_topmost.set_position(onyx::math::Vec2(510.0f, window.get_buffer_height() - 60));
	focuses_on_show.set_position(onyx::math::Vec2(510.0f, window.get_buffer_height() - 80));
	n_samples_msaa.set_position(onyx::math::Vec2(510.0f, window.get_buffer_height() - 100));
	is_fullscreen.set_position(onyx::math::Vec2(760.0f, window.get_buffer_height() - 20));
	is_maximized.set_position(onyx::math::Vec2(760.0f, window.get_buffer_height() - 40));
	is_minimized.set_position(onyx::math::Vec2(760.0f, window.get_buffer_height() - 60));

	monitor_label.set_position(onyx::math::Vec2(window.get_buffer_width() - 20.0f - monitor_label.get_width(), window.get_buffer_height() - 160.0f));
	monitor_name.set_position(onyx::math::Vec2(window.get_buffer_width() - 20.0f - monitor_name.get_width(), window.get_buffer_height() - 180.0f));
	monitor_dimensions.set_position(onyx::math::Vec2(window.get_buffer_width() - 20.0f - monitor_dimensions.get_width(), window.get_buffer_height() - 200.0f));
	monitor_bit_depth.set_position(onyx::math::Vec2(window.get_buffer_width() - 20.0f - monitor_bit_depth.get_width(), window.get_buffer_height() - 220.0f));
	monitor_refresh_rate.set_position(onyx::math::Vec2(window.get_buffer_width() - 20.0f - monitor_refresh_rate.get_width(), window.get_buffer_height() - 240.0f));
	monitor_physical_size.set_position(onyx::math::Vec2(window.get_buffer_width() - 20.0f - monitor_physical_size.get_width(), window.get_buffer_height() - 260.0f));
	monitor_content_scale.set_position(onyx::math::Vec2(window.get_buffer_width() - 20.0f - monitor_content_scale.get_width(), window.get_buffer_height() - 280.0f));
	monitor_position.set_position(onyx::math::Vec2(window.get_buffer_width() - 20.0f - monitor_position.get_width(), window.get_buffer_height() - 300.0f));
	monitor_work_area.set_position(onyx::math::Vec2(window.get_buffer_width() - 20.0f - monitor_work_area.get_width(), window.get_buffer_height() - 320.0f));
	monitor_is_primary.set_position(onyx::math::Vec2(window.get_buffer_width() - 20.0f - monitor_is_primary.get_width(), window.get_buffer_height() - 340.0f));
}
