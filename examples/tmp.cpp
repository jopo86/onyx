#include <onyx/prelude.hpp>

int main() {
    onyx::ErrorHandler err_handler(true, true);
    onyx::init(err_handler);

    onyx::Window win;
    win.init();
    
    onyx::InputHandler inp;
    win.link_input_handler(inp);

    onyx::Camera cam(onyx::Projection::perspective(60.0f, 800, 600));
    cam.translate_fb(-3.0f);
    win.link_camera(cam);

    onyx::Lighting lighting(Vec3::white(), 0.3f, Vec3(0.2f, -1.0f, -0.3f));
    onyx::Renderer renderer(cam, lighting);
    win.link_renderer(renderer);

    onyx::Renderable cube = onyx::Renderable::colored_cube(1.0f, Vec4::green());
    renderer.add(cube);

    inp.set_cursor_lock(true);

    const double MOVE_SPEED = 6.0;
	const double MOUSE_SENS = 30.0; 

    while (win.is_open()) {

        inp.update();
		double dx = inp.get_mouse_deltas().get_x();
		double dy = inp.get_mouse_deltas().get_y();
		double dt = win.get_delta_time();

        if (inp.is_key_down(onyx::Key::Esc)) win.close();
		if (inp.is_key_down(onyx::Key::W)) cam.translate_fb(MOVE_SPEED * dt);
		if (inp.is_key_down(onyx::Key::A)) cam.translate_lr(-MOVE_SPEED * dt);
		if (inp.is_key_down(onyx::Key::S)) cam.translate_fb(-MOVE_SPEED * dt);
		if (inp.is_key_down(onyx::Key::D)) cam.translate_lr(MOVE_SPEED * dt);
		if (inp.is_key_down(onyx::Key::Space)) cam.translate_ud(MOVE_SPEED * dt);
		if (inp.is_key_down(onyx::Key::C)) cam.translate_ud(-MOVE_SPEED * dt);

        cam.rotate(MOUSE_SENS * .005 * dx, MOUSE_SENS * .005 * dy);

        cam.update();

        win.start_render();
        renderer.render();
        win.end_render();
    }

    win.dispose();
    onyx::cleanup();
}