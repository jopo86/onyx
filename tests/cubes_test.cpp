#include "cubes_test.h"

#include "../src/core.h"
#include "../src/math.h"
#include "../src/window.h"
#include "../src/input_handler.h"
#include "../src/renderer.h"
#include "../src/camera.h"

using onyx::math::Vec3;

void cubes_test::run()
{
    onyx::init();

    onyx::WindowProperties props;
    props.title = "Onyx demo";
    props.width = 2560;
    props.height = 1440;
    props.background_color = Vec3::light_blue();
    props.n_samples_msaa = 4;

	onyx::Window win(props);
	win.init();
	onyx::InputHandler input;
	win.link_input_handler(input);

    onyx::math::Vec4 colors[8] = {
        onyx::math::Vec4::red(),
        onyx::math::Vec4::orange(),
        onyx::math::Vec4::yellow(),
        onyx::math::Vec4::green(),
        onyx::math::Vec4::blue(),
        onyx::math::Vec4::purple(),
        onyx::math::Vec4::pink(),
        onyx::math::Vec4::white(),
    };
    std::vector<onyx::Renderable> renderables;
    int k = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            renderables.push_back(onyx::Renderable::colored_cube(1.0f, colors[k]));
            renderables.back().set_position(Vec3(2.0f * j, 2.0f * i, 0.0f));
            renderables.back().set_rotation(Vec3(onyx::math::rand(0.0f, 360.0f), onyx::math::rand(0.0f, 360.0f), onyx::math::rand(0.0f, 360.0f)));
            k++;
        }
    }

    onyx::Camera cam(onyx::Projection::perspective(60.0f, 2560, 1440));
    cam.set_position(Vec3(3.0f, 1.5f, 5.0f));
    win.link_camera(cam);

    onyx::Lighting lighting(Vec3::white(), 0.2f, Vec3(0.3f, -1.0f, -0.6f));

    onyx::Renderer renderer(cam, lighting);
    win.link_renderer(renderer);

    for (auto& renderable : renderables)
    {
        renderer.add(renderable);
    }

    input.set_cursor_lock(true);
	while (win.is_open())
	{
		input.update();

        if (input.is_key_down(onyx::Key::Escape)) win.close();
        if (input.is_key_down(onyx::Key::W)) cam.translate_fb(6.0f * win.get_delta_time());
        if (input.is_key_down(onyx::Key::S)) cam.translate_fb(-6.0f * win.get_delta_time());
        if (input.is_key_down(onyx::Key::A)) cam.translate_lr(-6.0f * win.get_delta_time());
        if (input.is_key_down(onyx::Key::D)) cam.translate_lr(6.0f * win.get_delta_time());
        if (input.is_key_down(onyx::Key::C)) cam.translate_ud(-6.0f * win.get_delta_time());
        if (input.is_key_down(onyx::Key::Space)) cam.translate_ud(6.0f * win.get_delta_time());

        cam.update();
        cam.rotate(input.get_mouse_deltas().get_x() * 0.2f, input.get_mouse_deltas().get_y() * 0.2f);

		win.start_render();
        renderer.render();
		win.end_render();
	}

	win.dispose();
    renderer.dispose();
	onyx::terminate();
}
