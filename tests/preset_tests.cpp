#pragma warning(disable: 4244)

#include "preset_tests.h"

using onyx::ErrorHandler, onyx::Window, onyx::Monitor, onyx::WindowProperties, 
onyx::InputHandler, onyx::Mesh, onyx::Shader, onyx::Renderable, onyx::UiRenderable, 
onyx::Camera, onyx::Projection, onyx::Renderer, onyx::VertexBuffer,
onyx::IndexBuffer, onyx::Texture, onyx::Lighting, onyx::Key,
onyx::math::Vec2, onyx::math::Vec3, onyx::math::Vec4, onyx::math::IVec2,
onyx::init, onyx::terminate, onyx::resources;

bool preset_tests::run_mesh_test(onyx::Window& window, Mesh mesh)
{
	window.set_background_color(onyx::math::Vec3(0.0f, 0.0f, 0.0f));
	Monitor primary_monitor = Monitor::get_primary();
	window.set_position(IVec2(primary_monitor.get_dimensions().get_x() / 2 - window.get_width() / 2, primary_monitor.get_dimensions().get_y() / 2 - window.get_height() / 2));

	InputHandler input;
	window.link_input_handler(input);

	Renderable obj(mesh, onyx::Shader::p_color(Vec4(1.0f, 1.0f, 1.0f, 1.0f)));

	Camera cam(Projection::perspective(60.0f, 1280, 720));
	window.link_camera(cam);
	cam.translate_fb(-2.0f);

	Lighting lighting(Vec3::white(), 0.3f, Vec3(-0.2f, -1.0f, -0.3f));

	Renderer renderer(cam, lighting);
	window.link_renderer(renderer);
	renderer.add(obj);

	const double CAM_SPEED = 4.0;
	const double CAM_SENS = 50.0;

	input.set_cursor_lock(true);

	bool result = true;

	while (window.is_open())
	{
		input.update();

		double dt = window.get_delta_time();

		if (input.is_key_down(Key::Escape)) window.close();
		if (input.is_key_down(Key::X))
		{
			result = false;
			window.close();
		}
		if (input.is_key_tapped(Key::Num1)) Renderer::toggle_wireframe();
		if (input.is_key_down(Key::W)) cam.translate_fb( CAM_SPEED * dt);
		if (input.is_key_down(Key::A)) cam.translate_lr(-CAM_SPEED * dt);
		if (input.is_key_down(Key::S)) cam.translate_fb(-CAM_SPEED * dt);
		if (input.is_key_down(Key::D)) cam.translate_lr( CAM_SPEED * dt);
		if (input.is_key_down(Key::Space)) cam.translate_ud( CAM_SPEED * dt);
		if (input.is_key_down(Key::C)) cam.translate_ud(-CAM_SPEED * dt);

		cam.rotate(CAM_SENS / 200 * input.get_mouse_deltas().get_x(), CAM_SENS / 200 * input.get_mouse_deltas().get_y());
		cam.update();

		window.start_render();
		renderer.render();
		window.end_render();
	}

	window.dispose();
	renderer.dispose();

	return result;
}

bool preset_tests::run_renderable_test(onyx::Window& window, Renderable renderable)
{
	window.set_background_color(Vec3(0.0f, 0.0f, 0.0f));
	Monitor primary_monitor = Monitor::get_primary();
	window.set_position(IVec2(primary_monitor.get_dimensions().get_x() / 2 - window.get_width() / 2, primary_monitor.get_dimensions().get_y() / 2 - window.get_height() / 2));

	InputHandler input;
	window.link_input_handler(input);

	Renderable obj = renderable;

	Camera cam(Projection::perspective(60.0f, 1280, 720));
	window.link_camera(cam);
	cam.translate_fb(-2.0f);

	Lighting lighting(Vec3::white(), 0.3f, Vec3(-0.2f, -1.0f, -0.3f));

	Renderer renderer(cam, lighting);
	window.link_renderer(renderer);
	renderer.add(obj);

	const double CAM_SPEED = 4.0;
	const double CAM_SENS = 50.0;

	input.set_cursor_lock(true);

	bool result = true;

	while (window.is_open())
	{
		input.update();

		double dt = window.get_delta_time();

		if (input.is_key_down(Key::Escape)) window.close();
		if (input.is_key_down(Key::X))
        {
            result = false;
            window.close();
        }
		if (input.is_key_tapped(Key::Num1)) Renderer::toggle_wireframe();
		if (input.is_key_down(Key::W)) cam.translate_fb(CAM_SPEED * dt);
		if (input.is_key_down(Key::A)) cam.translate_lr(-CAM_SPEED * dt);
		if (input.is_key_down(Key::S)) cam.translate_fb(-CAM_SPEED * dt);
		if (input.is_key_down(Key::D)) cam.translate_lr(CAM_SPEED * dt);
		if (input.is_key_down(Key::Space)) cam.translate_ud(CAM_SPEED * dt);
		if (input.is_key_down(Key::C)) cam.translate_ud(-CAM_SPEED * dt);

		cam.rotate(CAM_SENS / 200 * input.get_mouse_deltas().get_x(), CAM_SENS / 200 * input.get_mouse_deltas().get_y());
		cam.update();

		window.start_render();
		renderer.render();
		window.end_render();
	}

	window.dispose();
	renderer.dispose();

	return result;
}

bool preset_tests::run_ui_renderable_test(onyx::Window& window, UiRenderable renderable)
{
    window.set_background_color(Vec3(0.0f, 0.0f, 0.0f));
	Monitor primary_monitor = Monitor::get_primary();
	window.set_position(IVec2(primary_monitor.get_dimensions().get_x() / 2 - window.get_width() / 2, primary_monitor.get_dimensions().get_y() / 2 - window.get_height() / 2));

    InputHandler input;
    window.link_input_handler(input);

    UiRenderable obj = renderable;
	obj.set_position(Vec2(300, 300));

    Camera cam(Projection::orthographic(1280, 720));
    window.link_camera(cam);

    Renderer renderer(cam);
    window.link_renderer(renderer);
    renderer.add(obj);

    const double CAM_SPEED = 4.0;
    const double CAM_SENS = 50.0;

    input.set_cursor_lock(true);
    input.set_key_cooldown(Key::Num1, 0.5f);

    bool result = true;

    while (window.is_open())
    {
        input.update();

        double dt = window.get_delta_time();

        if (input.is_key_down(Key::Escape)) window.close();
        if (input.is_key_down(Key::X))
        {
            result = false;
            window.close();
        }
        if (input.is_key_tapped(Key::Num1)) Renderer::toggle_wireframe();
        if (input.is_key_down(Key::W)) cam.translate_fb(CAM_SPEED * dt);
        if (input.is_key_down(Key::A)) cam.translate_lr(-CAM_SPEED * dt);
        if (input.is_key_down(Key::S)) cam.translate_fb(-CAM_SPEED * dt);
        if (input.is_key_down(Key::D)) cam.translate_lr(CAM_SPEED * dt);
        if (input.is_key_down(Key::Space)) cam.translate_ud(CAM_SPEED * dt);
        if (input.is_key_down(Key::C)) cam.translate_ud(-CAM_SPEED * dt);

        cam.rotate(CAM_SENS / 200 * input.get_mouse_deltas().get_x(), CAM_SENS / 200 * input.get_mouse_deltas().get_y());
        cam.update();

        window.start_render();
        renderer.render();
        window.end_render();
    }

    window.dispose();
    renderer.dispose();

    return result;
}

bool preset_tests::mesh_test_triangle1()
{
	ErrorHandler error_handler(true, true);
	init(error_handler);
	Window win(WindowProperties{ .title = "mesh_test_triangle1", .width = 1280, .height = 720, .n_samples_msaa = 16 });
	win.init();
	bool result = run_mesh_test(win, Mesh::triangle(1.0f));
	win.dispose();
	terminate();
	return result;
}

bool preset_tests::mesh_test_triangle2()
{
	ErrorHandler error_handler(true, true);
    init(error_handler);
	Window win(WindowProperties{ .title = "mesh_test_triangle2", .width = 1280, .height = 720, .n_samples_msaa = 16 });
	win.init();
    bool result = run_mesh_test(win, Mesh::triangle(1.0f, 1.0f));
	win.dispose();
    terminate();
	return result;
}

bool preset_tests::mesh_test_square()
{
	ErrorHandler error_handler(true, true);
    init(error_handler);
	Window win(WindowProperties{ .title = "mesh_test_square", .width = 1280, .height = 720, .n_samples_msaa = 16 });
	win.init();
    bool result = run_mesh_test(win, Mesh::square(1.0f));
	win.dispose();
    terminate();
	return result;
}

bool preset_tests::mesh_test_quad()
{
	ErrorHandler error_handler(true, true);
    init(error_handler);
	Window win(WindowProperties{ .title = "MeshTest_Quad1", .width = 1280, .height = 720, .n_samples_msaa = 16 });
	win.init();
    bool result = run_mesh_test(win, Mesh::quad(2.0f, 1.0f));
	win.dispose();
    terminate();
	return result;
}

bool preset_tests::mesh_test_circle()
{
	ErrorHandler error_handler(true, true);
	init(error_handler);
	Window win(WindowProperties{ .title = "mesh_test_circle", .width = 1280, .height = 720, .n_samples_msaa = 16 });
	win.init();
	bool result = run_mesh_test(win, Mesh::circle(
		0.5f, 50
	));
	win.dispose();
	terminate();
	return result;
}

bool preset_tests::mesh_test_cube()
{
	ErrorHandler error_handler(true, true);
    init(error_handler);
	Window win(WindowProperties{ .title = "mesh_test_cube", .width = 1280, .height = 720, .n_samples_msaa = 16 });
	win.init();
    bool result = run_mesh_test(win, Mesh::cube(1.0f));
	win.dispose();
    terminate();
	return result;
}

bool preset_tests::mesh_test_rect_prism()
{
	ErrorHandler error_handler(true, true);
	init(error_handler);
	Window win(WindowProperties{ .title = "mesh_test_rect_prism", .width = 1280, .height = 720, .n_samples_msaa = 16 });
	win.init();
    bool result = run_mesh_test(win, Mesh::rect_prism(1.0f, 1.0f, 1.0f));
	win.dispose();
    terminate();
	return result;
}

bool preset_tests::mesh_test_cylinder()
{
	ErrorHandler error_handler(true, true);
	init(error_handler);
	Window win(WindowProperties{ .title = "mesh_test_cylinder", .width = 1280, .height = 720, .n_samples_msaa = 16 });
	win.init();
	bool result = run_mesh_test(win, Mesh::cylinder(0.2f, 2.0f, 50, false, false));
	win.dispose();
	terminate();
	return result;
}

bool preset_tests::renderable_test_colored_triangle()
{
	ErrorHandler error_handler(true, true);
	init(error_handler);
    Window win(WindowProperties{ .title = "renderable_test_colored_triangle", .width = 1280, .height = 720, .n_samples_msaa = 16 });
    win.init();
	bool result = run_renderable_test(win, Renderable::colored_triangle(1.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
	win.dispose();
	terminate();
	return result;
}

bool preset_tests::renderable_test_vertex_colored_triangle()
{
	ErrorHandler error_handler(true, true);
    init(error_handler);
    Window win(WindowProperties{ .title = "renderable_test_vertex_colored_triangle", .width = 1280, .height = 720, .n_samples_msaa = 16 });
    win.init();
    bool result = run_renderable_test(win, Renderable::vertex_colored_triangle(1.0f));
	win.dispose();
    terminate();
	return result;
}

bool preset_tests::renderable_test_textured_triangle()
{
	ErrorHandler error_handler(true, true);
    init(error_handler);
    Window win(WindowProperties{ .title = "renderable_test_textured_triangle", .width = 1280, .height = 720, .n_samples_msaa = 16 });
    win.init();
    bool result = run_renderable_test(win, Renderable::textured_triangle(1.0f, Texture::load(resources("textures/container.jpg"))));
	win.dispose();
    terminate();
	return result;
}

bool preset_tests::renderable_test_colored_square()
{
	ErrorHandler error_handler(true, true);
    init(error_handler);
    Window win(WindowProperties{ .title = "renderable_test_colored_square", .width = 1280, .height = 720, .n_samples_msaa = 16 });
    win.init();
    bool result = run_renderable_test(win, Renderable::colored_square(1.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
	win.dispose();
    terminate();
	return result;
}

bool preset_tests::renderable_test_colored_quad()
{
	ErrorHandler error_handler(true, true);
	init(error_handler);
    Window win(WindowProperties{ .title = "renderable_test_colored_quad", .width = 1280, .height = 720, .n_samples_msaa = 16 });
    win.init();
    bool result = run_renderable_test(win, Renderable::colored_quad(2.0f, 1.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
	win.dispose();
    terminate();
	return result;
}

bool preset_tests::renderable_test_vertex_colored_square()
{
	ErrorHandler error_handler(true, true);
    init(error_handler);
    Window win(WindowProperties{ .title = "renderable_test_vertex_colored_square", .width = 1280, .height = 720, .n_samples_msaa = 16 });
    win.init();
    bool result = run_renderable_test(win, Renderable::vertex_colored_square(1.0f));
	win.dispose();
    terminate();
	return result;
}

bool preset_tests::renderable_test_vertex_colored_quad()
{
	ErrorHandler error_handler(true, true);
    init(error_handler);
    Window win(WindowProperties{ .title = "renderable_test_vertex_colored_quad", .width = 1280, .height = 720, .n_samples_msaa = 16 });
    win.init();
    bool result = run_renderable_test(win, Renderable::vertex_colored_quad(2.0f, 1.0f));
	win.dispose();
    terminate();
	return result;
}

bool preset_tests::renderable_test_colored_circle()
{
	ErrorHandler error_handler(true, true);
	init(error_handler);
	Window win(WindowProperties{ .title = "renderable_test_colored_circle", .width = 1280, .height = 720, .n_samples_msaa = 16 });
	win.init();
	bool result = run_renderable_test(win, Renderable::colored_circle(0.5f, 50, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
	win.dispose();
	terminate();
	return result;
}

bool preset_tests::renderable_test_vertex_colored_circle()
{
	ErrorHandler error_handler(true, true);
	init(error_handler);
	Window win(WindowProperties{ .title = "renderable_test_vertex_colored_circle", .width = 1280, .height = 720, .n_samples_msaa = 16 });
	win.init();
	bool result = run_renderable_test(win, Renderable::vertex_colored_circle(0.5f, 50));
	win.dispose();
	terminate();
	return result;
}

bool preset_tests::renderable_test_textured_circle()
{
	ErrorHandler error_handler(true, true);
	init(error_handler);
	Window win(WindowProperties{ .title = "renderable_test_textured_circle", .width = 1280, .height = 720, .n_samples_msaa = 16 });
	win.init();
	bool result = run_renderable_test(win, Renderable::textured_circle(0.5f, 50, Texture::load(resources("textures/container.jpg"))));
	win.dispose();
	terminate();
	return result;
}

bool preset_tests::renderable_test_textured_square()
{
	ErrorHandler error_handler(true, true);
    init(error_handler);
    Window win(WindowProperties{ .title = "renderable_test_textured_square", .width = 1280, .height = 720, .n_samples_msaa = 16 });
    win.init();
    bool result = run_renderable_test(win, Renderable::textured_square(1.0f, Texture::load(resources("textures/container.jpg"))));
	win.dispose();
    terminate();
	return result;
}

bool preset_tests::renderable_test_textured_quad()
{
	ErrorHandler error_handler(true, true);
    init(error_handler);
    Window win(WindowProperties{ .title = "renderable_test_textured_quad", .width = 1280, .height = 720, .n_samples_msaa = 16 });
    win.init();
    bool result = run_renderable_test(win, Renderable::textured_quad(2.0f, 1.0f, Texture::load(resources("textures/container.jpg"))));
	win.dispose();
    terminate();
	return result;
}

bool preset_tests::renderable_test_colored_cube()
{
	ErrorHandler error_handler(true, true);
    init(error_handler);
    Window win(WindowProperties{ .title = "renderable_test_colored_cube", .width = 1280, .height = 720, .n_samples_msaa = 16 });
    win.init();
    bool result = run_renderable_test(win, Renderable::colored_cube(1.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
	win.dispose();
    terminate();
	return result;
}

bool preset_tests::renderable_test_textured_cube()
{
	ErrorHandler error_handler(true, true);
	init(error_handler);
    Window win(WindowProperties{ .title = "renderable_test_textured_cube", .width = 1280, .height = 720, .n_samples_msaa = 16 });
    win.init();
    bool result = run_renderable_test(win, Renderable::textured_cube(1.0f, Texture::load(resources("textures/container.jpg"))));
	win.dispose();
    terminate();
	return result;
}

bool preset_tests::renderable_test_colored_rect_prism()
{
	ErrorHandler error_handler(true, true);
	init(error_handler);
	Window win(WindowProperties{ .title = "renderable_test_colored_rect_prism", .width = 1280, .height = 720, .n_samples_msaa = 16 });
	win.init();
	bool result = run_renderable_test(win, Renderable::colored_rect_prism(2.0f, 1.0f, 1.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
	win.dispose();
	terminate();
	return result;
}

bool preset_tests::renderable_test_textured_rect_prism()
{
	ErrorHandler error_handler(true, true);
	init(error_handler);
	Window win(WindowProperties{ .title = "renderable_test_textured_rect_prism", .width = 1280, .height = 720, .n_samples_msaa = 16 });
	win.init();
	bool result = run_renderable_test(win, Renderable::textured_rect_prism(2.0f, 1.0f, 1.0f, Texture::load(resources("textures/container.jpg"))));
	win.dispose();
	terminate();
	return result;
}

bool preset_tests::renderable_test_colored_cylinder()
{
	ErrorHandler error_handler(true, true);
	init(error_handler);
	Window win(WindowProperties{ .title = "renderable_test_colored_cylinder", .width = 1280, .height = 720, .n_samples_msaa = 16 });
	win.init();
	bool result = run_renderable_test(win, Renderable::colored_cylinder(0.2f, 2.0f, 50, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
	win.dispose();
	terminate();
	return result;
}

bool preset_tests::renderable_test_textured_cylinder()
{
	ErrorHandler error_handler(true, true);
	init(error_handler);
	Window win(WindowProperties{ .title = "renderable_test_textured_cylinder", .width = 1280, .height = 720, .n_samples_msaa = 16 });
	win.init();
	bool result = run_renderable_test(win, Renderable::textured_cylinder(0.2f, 2.0f, 50, Texture::load(resources("textures/container.jpg"))));
	win.dispose();
	terminate();
	return result;
}

bool preset_tests::ui_renderable_test_colored_triangle()
{
    ErrorHandler error_handler(true, true);
    init(error_handler);
    Window win(WindowProperties{ .title = "ui_renderable_test_colored_triangle", .width = 1280, .height = 720, .n_samples_msaa = 16 });
    win.init();
    bool result = run_ui_renderable_test(win, UiRenderable::colored_triangle(100.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
	win.dispose();
    terminate();
    return result;
}

bool preset_tests::ui_renderable_test_textured_triangle()
{
    ErrorHandler error_handler(true, true);
    init(error_handler);
    Window win(WindowProperties{ .title = "ui_renderable_test_textured_triangle", .width = 1280, .height = 720, .n_samples_msaa = 16 });
    win.init();
    bool result = run_ui_renderable_test(win, UiRenderable::textured_triangle(100.0f, Texture::load(resources("textures/container.jpg"))));
	win.dispose();
    terminate();
    return result;
}

bool preset_tests::ui_renderable_test_colored_square()
{
    ErrorHandler error_handler(true, true);
    init(error_handler);
    Window win(WindowProperties{ .title = "ui_renderable_test_colored_square", .width = 1280, .height = 720, .n_samples_msaa = 16 });
    win.init();
    bool result = run_ui_renderable_test(win, UiRenderable::colored_square(100.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
	win.dispose();
    terminate();
    return result;
}

bool preset_tests::ui_renderable_test_textured_square()
{
    ErrorHandler error_handler(true, true);
    init(error_handler);
    Window win(WindowProperties{ .title = "ui_renderable_test_textured_square", .width = 1280, .height = 720, .n_samples_msaa = 16 });
    win.init();
    bool result = run_ui_renderable_test(win, UiRenderable::textured_square(100.0f, Texture::load(resources("textures/container.jpg"))));
	win.dispose();
    terminate();
    return result;
}

bool preset_tests::ui_renderable_test_colored_quad()
{
    ErrorHandler error_handler(true, true);
    init(error_handler);
    Window win(WindowProperties{ .title = "ui_renderable_test_colored_quad", .width = 1280, .height = 720, .n_samples_msaa = 16 });
    win.init();
    bool result = run_ui_renderable_test(win, UiRenderable::colored_quad(200.0f, 100.0f, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
	win.dispose();
    terminate();
    return result;
}

bool preset_tests::ui_renderable_test_textured_quad()
{
    ErrorHandler error_handler(true, true);
    init(error_handler);
    Window win(WindowProperties{ .title = "ui_renderable_test_textured_quad", .width = 1280, .height = 720, .n_samples_msaa = 16 });
    win.init();
    bool result = run_ui_renderable_test(win, UiRenderable::textured_quad(200.0f, 100.0f, Texture::load(resources("textures/container.jpg"))));
	win.dispose();
    terminate();
    return result;
}

bool preset_tests::ui_renderable_test_colored_circle()
{
	ErrorHandler error_handler(true, true);
	init(error_handler);
	Window win(WindowProperties{ .title = "ui_renderable_test_colored_circle", .width = 1280, .height = 720, .n_samples_msaa = 16 });
	win.init();
	bool result = run_ui_renderable_test(win, UiRenderable::colored_circle(50.0f, 50, Vec4(0.0f, 1.0f, 0.0f, 1.0f)));
	win.dispose();
	terminate();
	return result;
}

bool preset_tests::ui_renderable_test_textured_circle()
{
	ErrorHandler error_handler(true, true);
	init(error_handler);
	Window win(WindowProperties{ .title = "ui_renderable_test_textured_circle", .width = 1280, .height = 720, .n_samples_msaa = 16 });
	win.init();
	bool result = run_ui_renderable_test(win, UiRenderable::textured_circle(50.0f, 50, Texture::load(resources("textures/container.jpg"))));
	win.dispose();
	terminate();
	return result;
}

void preset_tests::run_all_tests()
{
	if (mesh_test_triangle1()) std::cout << "mesh_test_triangle1 - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "mesh_test_triangle1 - \x1b[31mFAILED\x1b[39m\n";

	if (mesh_test_triangle2()) std::cout << "mesh_test_triangle2 - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "mesh_test_triangle2 - \x1b[31mFAILED\x1b[39m\n";

	if (mesh_test_square()) std::cout << "mesh_test_square - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "mesh_test_square - \x1b[31mFAILED\x1b[39m\n";

	if (mesh_test_quad()) std::cout << "mesh_test_quad - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "mesh_test_quad - \x1b[31mFAILED\x1b[39m\n";

	if (mesh_test_circle()) std::cout << "mesh_test_circle - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "mesh_test_circle - \x1b[31mFAILED\x1b[39m\n";

	if (mesh_test_cube()) std::cout << "mesh_test_cube - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "mesh_test_cube - \x1b[31mFAILED\x1b[39m\n";

	if (mesh_test_rect_prism()) std::cout << "mesh_test_rect_prism - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "mesh_test_rect_prism - \x1b[31mFAILED\x1b[39m\n";

	if (mesh_test_cylinder()) std::cout << "mesh_test_cylinder - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "mesh_test_cylinder - \x1b[31mFAILED\x1b[39m\n";

	if (renderable_test_colored_triangle()) std::cout << "renderable_test_colored_triangle - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "renderable_test_colored_triangle - \x1b[31mFAILED\x1b[39m\n";

	if (renderable_test_vertex_colored_triangle()) std::cout << "renderable_test_vertex_colored_triangle - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "renderable_test_vertex_colored_triangle - \x1b[31mFAILED\x1b[39m\n";

	if (renderable_test_textured_triangle()) std::cout << "renderable_test_textured_triangle - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "renderable_test_textured_triangle - \x1b[31mFAILED\x1b[39m\n";

	if (renderable_test_colored_square()) std::cout << "renderable_test_colored_square - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "renderable_test_colored_square - \x1b[31mFAILED\x1b[39m\n";

	if (renderable_test_colored_quad()) std::cout << "renderable_test_colored_quad - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "renderable_test_colored_quad - \x1b[31mFAILED\x1b[39m\n";

	if (renderable_test_vertex_colored_square()) std::cout << "renderable_test_vertex_colored_square - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "renderable_test_vertex_colored_square - \x1b[31mFAILED\x1b[39m\n";

	if (renderable_test_vertex_colored_quad()) std::cout << "renderable_test_vertex_colored_quad - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "renderable_test_vertex_colored_quad - \x1b[31mFAILED\x1b[39m\n";

	if (renderable_test_colored_circle()) std::cout << "renderable_test_colored_circle - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "renderable_test_colored_circle - \x1b[31mFAILED\x1b[39m\n";

	if (renderable_test_vertex_colored_circle()) std::cout << "renderable_test_vertex_colored_circle - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "renderable_test_vertex_colored_circle - \x1b[31mFAILED\x1b[39m\n";

	if (renderable_test_textured_circle()) std::cout << "renderable_test_textured_circle - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "renderable_test_textured_circle - \x1b[31mFAILED\x1b[39m\n";

	if (renderable_test_textured_square()) std::cout << "renderable_test_textured_square - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "renderable_test_textured_square - \x1b[31mFAILED\x1b[39m\n";

	if (renderable_test_textured_quad()) std::cout << "renderable_test_textured_quad - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "renderable_test_textured_quad - \x1b[31mFAILED\x1b[39m\n";

	if (renderable_test_colored_cube()) std::cout << "renderable_test_colored_cube - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "renderable_test_colored_cube - \x1b[31mFAILED\x1b[39m\n";

	if (renderable_test_textured_cube()) std::cout << "renderable_test_textured_cube - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "renderable_test_textured_cube - \x1b[31mFAILED\x1b[39m\n";

	if (renderable_test_colored_rect_prism()) std::cout << "renderable_test_colored_rect_prism - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "renderable_test_colored_rect_prism - \x1b[31mFAILED\x1b[39m\n";

	if (renderable_test_textured_rect_prism()) std::cout << "renderable_test_textured_rect_prism - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "renderable_test_textured_rect_prism - \x1b[31mFAILED\x1b[39m\n";

	if (renderable_test_colored_cylinder()) std::cout << "renderable_test_colored_cylinder - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "renderable_test_colored_cylinder - \x1b[31mFAILED\x1b[39m\n";

	if (renderable_test_textured_cylinder()) std::cout << "renderable_test_textured_cylinder - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "renderable_test_textured_cylinder - \x1b[31mFAILED\x1b[39m\n";

	if (ui_renderable_test_colored_triangle()) std::cout << "ui_renderable_test_colored_triangle - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "ui_renderable_test_colored_triangle - \x1b[31mFAILED\x1b[39m\n";

	if (ui_renderable_test_textured_triangle()) std::cout << "ui_renderable_test_textured_triangle - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "ui_renderable_test_textured_triangle - \x1b[31mFAILED\x1b[39m\n";

	if (ui_renderable_test_colored_square()) std::cout << "ui_renderable_test_colored_square - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "ui_renderable_test_colored_square - \x1b[31mFAILED\x1b[39m\n";

	if (ui_renderable_test_textured_square()) std::cout << "ui_renderable_test_textured_square - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "ui_renderable_test_textured_square - \x1b[31mFAILED\x1b[39m\n";

	if (ui_renderable_test_colored_quad()) std::cout << "ui_renderable_test_colored_quad - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "ui_renderable_test_colored_quad - \x1b[31mFAILED\x1b[39m\n";

	if (ui_renderable_test_textured_quad()) std::cout << "ui_renderable_test_textured_quad - \x1b[32mCOMPLETE\x1b[39m\n";
    else std::cout << "ui_renderable_test_textured_quad - \x1b[31mFAILED\x1b[39m\n";

	if (ui_renderable_test_colored_circle()) std::cout << "ui_renderable_test_colored_circle - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "ui_renderable_test_colored_circle - \x1b[31mFAILED\x1b[39m\n";

	if (ui_renderable_test_textured_circle()) std::cout << "ui_renderable_test_textured_circle - \x1b[32mCOMPLETE\x1b[39m\n";
	else std::cout << "ui_renderable_test_textured_circle - \x1b[31mFAILED\x1b[39m\n";

	std::cout << "\n";
}
