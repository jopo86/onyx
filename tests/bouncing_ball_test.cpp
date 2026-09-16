#pragma warning(disable: 6386; disable: 4244; disable: 305 )

#include "bouncing_ball_test.h"

#include "../src/core.h"
#include "../src/math.h"
#include "../src/window.h"
#include "../src/monitor.h"
#include "../src/input_handler.h"
#include "../src/camera.h"

using namespace onyx;
using namespace onyx::math;

void onyx_add_malloc(void*, bool);

double f(double x, double y);
double df_dx(double x, double y, double h = 0.0001);
double df_dy(double x, double y, double h = 0.0001);
DVec3 f_norm(double x, double y);
DVec2 f_grad(double x, double y);
Mesh* generate_surface(double width, double depth, const DVec2& domain_x, const DVec2& domain_y, int nX, int nY);

void bouncing_ball_test::run()
{

	ErrorHandler error_handler(true, true);
	init(error_handler);

	Window window(WindowProperties{
			.title = "Bouncing Ball demo",
			.width = 1280,
			.height = 720,
			.n_samples_msaa = 16,
			.background_color = Vec3::black()
		}
	);
	window.init();
	window.fullscreen();

	Monitor monitor = Monitor::get_primary();
	window.set_position(IVec2(monitor.get_width() / 2 - window.get_width() / 2, monitor.get_height() / 2 - window.get_height() / 2));

	InputHandler input;
	window.link_input_handler(input);

	Camera cam(Projection::perspective(60.0f, 1280, 720));
	window.link_camera(cam);
	cam.translate_fb(-6.0f);

	Lighting lighting(Vec3(1.0f, 1.0f, 1.0f), 0.3f, Vec3(-0.2f, -1.0f, -0.3f));

	Renderer renderer(cam, lighting);
	window.link_renderer(renderer);

	const double GRAPH_WIDTH = 5.0;
	const double GRAPH_RANGE = 30.0;
	const int GRAPH_SUBDIVISIONS = 100;

	const bool ALLOW_SCENE_EXPLORE = false;
	const bool DIRECTOR_MODE = true;

	const float CAM_SPEED = 6.0f;
	const float CAM_SENS = 30.0f;

	const float GRAVITY = -9.81f;
	const float BOUNCINESS = 0.7f;
	const float BOUNDARY_OFFSET = 0.08f;
	const float CORRECTION_OFFSET = 0.01f;

	Mesh* mesh = generate_surface(GRAPH_WIDTH, GRAPH_WIDTH, DVec2(-GRAPH_RANGE / 2, GRAPH_RANGE / 2), DVec2(-GRAPH_RANGE / 2, GRAPH_RANGE / 2), GRAPH_SUBDIVISIONS, GRAPH_SUBDIVISIONS);
	Renderable surface(*mesh, Shader::pn_color(Vec4::green()));
	renderer.add(surface);

	ModelRenderable ball(Model::load_obj(resources("models/sphere.obj")));
	ball.scale(0.001f);
	ball.translate(Vec3(rand(-(GRAPH_WIDTH * 0.9) / 2, (GRAPH_WIDTH * 0.9) / 2), 1.0f, rand(-(GRAPH_WIDTH * 0.9) / 2, (GRAPH_WIDTH * 0.9) / 2)));
	renderer.add(ball);

	Vec3 ball_velocity(rand(-3.0f, 3.0f), 0.0f, rand(-3.0f, 3.0f));

	float start = get_time();

	input.set_cursor_lock(true);

	while (window.is_open())
	{
		double dt = window.get_delta_time();
		double dx = input.get_mouse_deltas().get_x();
		double dy = input.get_mouse_deltas().get_y();

		input.update();

		if (input.is_key_tapped(Key::Escape)) window.close();
		if (input.is_key_tapped(Key::F12)) window.toggle_fullscreen(1280, 720, IVec2(monitor.get_width() / 2 - window.get_width() / 2, monitor.get_height() / 2 - window.get_height() / 2));
		if (input.is_key_tapped(Key::F1)) Renderer::toggle_wireframe();
		if (input.is_key_tapped(Key::F2)) renderer.toggle_lighting_enabled();
		if (input.is_key_tapped(Key::R))
		{
			ball.set_position(Vec3(rand(-(GRAPH_WIDTH * 0.9) / 2, (GRAPH_WIDTH * 0.9) / 2), 1.0f, rand(-(GRAPH_WIDTH * 0.9) / 2, (GRAPH_WIDTH * 0.9) / 2)));
			ball_velocity = Vec3(rand(-3.0f, 3.0f), 0.0f, rand(-3.0f, 3.0f));
			start = get_time();
		}

		if (ALLOW_SCENE_EXPLORE)
		{
			if (input.is_key_down(Key::W)) cam.translate_fb( CAM_SPEED * dt);
			if (input.is_key_down(Key::A)) cam.translate_lr(-CAM_SPEED * dt);
			if (input.is_key_down(Key::S)) cam.translate_fb(-CAM_SPEED * dt);
			if (input.is_key_down(Key::D)) cam.translate_lr( CAM_SPEED * dt);
			if (input.is_key_down(Key::C)) cam.translate_ud(-CAM_SPEED * dt);
			if (input.is_key_down(Key::Space)) cam.translate_ud(CAM_SPEED * dt);

			cam.rotate(CAM_SENS * .005 * dx, CAM_SENS * .005 * dy);
		}
		else
		{
			if (!DIRECTOR_MODE)
			{
				float dist = cam.get_position().magnitude();
				if (::abs(dx) > 1.0) cam.translate_lr(-CAM_SPEED * .002 * dx);
				if (::abs(dy) > 1.0) cam.translate_ud(-CAM_SPEED * .002 * dy);
				cam.set_position(cam.get_position().get_normalized() * dist);
				cam.look_at(Vec3(0));
			}
			else
			{
				cam.set_position(Vec3(sinf(get_time() / 2.0f) * 5.0f, 4.0f, cosf(get_time() / 2.0f) * 5.0f));
				cam.look_at(Vec3(0));
			}
		}
		cam.update();

		if (get_time() - start > 1.0)
		{
			Vec3 ball_pos = ball.get_position();

			float x = remap(ball_pos.get_x(), Vec2(-GRAPH_WIDTH / 2, GRAPH_WIDTH / 2), Vec2(-GRAPH_RANGE / 2, GRAPH_RANGE / 2));
			float z = remap(ball_pos.get_z(), Vec2(-GRAPH_WIDTH / 2, GRAPH_WIDTH / 2), Vec2(-GRAPH_RANGE / 2, GRAPH_RANGE / 2));
			float y = f(x, z);
			if (ball_pos.get_y() < y + 0.12f)
			{
				ball.set_position(Vec3(ball_pos.get_x(), y + 0.13f, ball_pos.get_z()));
				std::cout << ball_velocity.to_string() << " ---> ";
				Vec3 norm = f_norm(x, z);
				Vec3 reflected = reflect(ball_velocity, norm);
				std::cout << reflected.to_string() << "\n";
				ball_velocity = reflected * BOUNCINESS;
				ball_velocity.set_y(-ball_velocity.get_y());
				if (ball_velocity.get_y() < 0.01f) ball_velocity.set_y(0.0f);
			}
			else if (ball_pos.get_y() > y + 0.12f) ball_velocity.set_y(ball_velocity.get_y() + GRAVITY * dt);

			if (ball_pos.get_y() <= y + 0.13f)
			{
				DVec2 grad_xy = f_grad(x, z);
				Vec3 grad(grad_xy.get_x(), 0.0f, grad_xy.get_y());
				if (grad.magnitude() > 0.001f && grad.magnitude() < 0.05f) grad.set_magnitude(0.05f);
				ball_velocity -= grad;
			}

			if (get_time() - start > 5.0 && ball_velocity.magnitude() < 0.2f) ball_velocity.set(0.0f, 0.0f, 0.0f);

			ball.translate(ball_velocity * dt); 

			if (ball_pos.get_x() < -GRAPH_WIDTH / 2 + BOUNDARY_OFFSET)
			{
				ball_velocity.set_x(-ball_velocity.get_x());
				ball.set_position(Vec3(-GRAPH_WIDTH / 2 + BOUNDARY_OFFSET + CORRECTION_OFFSET, ball_pos.get_y(), ball_pos.get_z()));
			}
			if (ball_pos.get_x() > GRAPH_WIDTH / 2 - BOUNDARY_OFFSET)
			{
				ball_velocity.set_x(-ball_velocity.get_x());
				ball.set_position(Vec3(GRAPH_WIDTH / 2 - BOUNDARY_OFFSET - CORRECTION_OFFSET, ball_pos.get_y(), ball_pos.get_z()));
			}
			if (ball_pos.get_z() < -GRAPH_WIDTH / 2 + BOUNDARY_OFFSET)
			{
				ball_velocity.set_z(-ball_velocity.get_z());
				ball.set_position(Vec3(ball_pos.get_x(), ball_pos.get_y(), -GRAPH_WIDTH / 2 + BOUNDARY_OFFSET + CORRECTION_OFFSET));
			}
			if (ball_pos.get_z() > GRAPH_WIDTH / 2 - BOUNDARY_OFFSET)
			{
				ball_velocity.set_z(-ball_velocity.get_z());
				ball.set_position(Vec3(ball_pos.get_x(), ball_pos.get_y(), GRAPH_WIDTH / 2 - BOUNDARY_OFFSET - CORRECTION_OFFSET));
			}
		}

		window.start_render();
		renderer.render();
		window.end_render();
	}

	window.dispose();
	renderer.dispose();

	onyx::terminate();
}

double f(double x, double y)
{
    return (::sin(x) + ::sin(y) + ::cos(x / 2) + ::cos(y / 2) + ::sin(x / 4) + ::sin(y / 4) + ::cos(x / 6) + ::sin(sqrtf(x * x + y * y))) / 9;
	//return sin(sqrt(x * x + y * y)) / 5;
	//return (x * x + y * y) / 75;
	//return sin(x) / 5;
}

double df_dx(double x, double y, double h)
{
	return (f(x + h, y) - f(x, y)) / h;
}

double df_dy(double x, double y, double h)
{
	return (f(x, y + h) - f(x, y)) / h;
}

DVec3 f_norm(double x, double y)
{
    return cross(DVec3(1, 0, df_dx(x, y)), DVec3(0, 1, df_dy(x, y))).get_normalized();
}

DVec2 f_grad(double x, double y)
{
	return DVec2(df_dx(x, y), df_dy(x, y));
}

Mesh* generate_surface(double width, double depth, const DVec2& domain_x, const DVec2& domain_y, int nX, int nY)
{
    int vcount = nX * nY * 6;
    int icount = (nX - 1) * (nY - 1) * 6;

    float* vertices = new float[vcount];

    double x_step = (domain_x.get_y() - domain_x.get_x()) / (nX - 1);
    double y_step = (domain_y.get_y() - domain_y.get_x()) / (nY - 1);

    for (int i = 0; i < nX; i++)
    {
        double x = domain_x.get_x() + i * x_step;
        for (int j = 0; j < nY; j++)
        {
            double y = domain_y.get_x() + j * y_step;
            int vi = (i * nY + j) * 6;
            double z = f(x, y);
            DVec3 norm = f_norm(x, y);
            vertices[vi + 0] = remap(x, DVec2(domain_x.get_x(), domain_x.get_y()), DVec2(-width / 2, width / 2));
			vertices[vi + 1] = z;
            vertices[vi + 2] = remap(y, DVec2(domain_y.get_x(), domain_y.get_y()), DVec2(-depth / 2, depth / 2));
            vertices[vi + 3] = norm.get_x();
            vertices[vi + 4] = norm.get_y();
            vertices[vi + 5] = norm.get_z();
        }
    }

    VertexBuffer vb(vertices, vcount * sizeof(float), VertexFormat::PN);

    u32* indices = new u32[icount];
    for (int i = 0; i < nX - 1; i++)
    {
        for (int j = 0; j < nY - 1; j++)
        {
            int ii = (i * (nY - 1) + j) * 6;
            int v_index = i * nY + j;
            indices[ii + 0] = v_index;
            indices[ii + 1] = v_index + 1;
            indices[ii + 2] = v_index + nY;

            indices[ii + 3] = v_index + 1;
            indices[ii + 4] = v_index + nY + 1;
            indices[ii + 5] = v_index + nY;
        }
    }

    IndexBuffer ib(indices, icount * sizeof(u32));

    Mesh* mesh = new Mesh(vb, ib);
    onyx_add_malloc(mesh, false);

    delete[] vertices;
    delete[] indices;

    return mesh;
}
