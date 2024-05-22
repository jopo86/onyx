#pragma warning(disable: 6386; disable: 4244; disable: 305 )

#include "BouncingBallTest.h"

#include "../src/Core.h"
#include "../src/Math.h"
#include "../src/Window.h"
#include "../src/Monitor.h"

using namespace Onyx;
using namespace Onyx::Math;

void onyx_add_malloc(void*, bool);

double f(double x, double y);
double df_dx(double x, double y, double h = 0.0001);
double df_dy(double x, double y, double h = 0.0001);
DVec3 f_norm(double x, double y);
DVec2 f_grad(double x, double y);
Mesh* generateSurface(double width, double depth, const DVec2& domainX, const DVec2& domainY, int nX, int nY);

void BouncingBallTest::Run()
{

	ErrorHandler errorHandler(true, true);
	Init(errorHandler);

	Window window(WindowProperties{
			.title = "Bouncing Ball Demo",
			.width = 1280,
			.height = 720,
			.nSamplesMSAA = 16,
			.backgroundColor = Vec3::Black()
		}
	);
	window.init();
	window.fullscreen();

	Monitor monitor = Monitor::GetPrimary();
	window.setPosition(IVec2(monitor.getWidth() / 2 - window.getWidth() / 2, monitor.getHeight() / 2 - window.getHeight() / 2));

	InputHandler input;
	window.linkInputHandler(input);

	Camera cam(Projection::Perspective(60.0f, 1280, 720));
	window.linkCamera(cam);
	cam.translateFB(-6.0f);

	Lighting lighting(Vec3(1.0f, 1.0f, 1.0f), 0.3f, Vec3(-0.2f, -1.0f, -0.3f));

	Renderer renderer(cam, lighting);
	window.linkRenderer(renderer);

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

	Mesh* mesh = generateSurface(GRAPH_WIDTH, GRAPH_WIDTH, DVec2(-GRAPH_RANGE / 2, GRAPH_RANGE / 2), DVec2(-GRAPH_RANGE / 2, GRAPH_RANGE / 2), GRAPH_SUBDIVISIONS, GRAPH_SUBDIVISIONS);
	Renderable surface(*mesh, Shader::PN_Color(Vec4::Green()));
	renderer.add(surface);

	ModelRenderable ball(Model::LoadOBJ(Resources("models/sphere.obj")));
	ball.scale(0.001f);
	ball.translate(Vec3(Rand(-(GRAPH_WIDTH * 0.9) / 2, (GRAPH_WIDTH * 0.9) / 2), 1.0f, Rand(-(GRAPH_WIDTH * 0.9) / 2, (GRAPH_WIDTH * 0.9) / 2)));
	renderer.add(ball);

	Vec3 ballVelocity(Rand(-3.0f, 3.0f), 0.0f, Rand(-3.0f, 3.0f));

	float start = GetTime();

	input.setCursorLock(true);

	while (window.isOpen())
	{
		double dt = window.getDeltaTime();
		double dx = input.getMouseDeltas().getX();
		double dy = input.getMouseDeltas().getY();

		input.update();

		if (input.isKeyTapped(Key::Escape)) window.close();
		if (input.isKeyTapped(Key::F12)) window.toggleFullscreen(1280, 720, IVec2(monitor.getWidth() / 2 - window.getWidth() / 2, monitor.getHeight() / 2 - window.getHeight() / 2));
		if (input.isKeyTapped(Key::F1)) Renderer::ToggleWireframe();
		if (input.isKeyTapped(Key::F2)) renderer.toggleLightingEnabled();
		if (input.isKeyTapped(Key::R))
		{
			ball.setPosition(Vec3(Rand(-(GRAPH_WIDTH * 0.9) / 2, (GRAPH_WIDTH * 0.9) / 2), 1.0f, Rand(-(GRAPH_WIDTH * 0.9) / 2, (GRAPH_WIDTH * 0.9) / 2)));
			ballVelocity = Vec3(Rand(-3.0f, 3.0f), 0.0f, Rand(-3.0f, 3.0f));
			start = GetTime();
		}

		if (ALLOW_SCENE_EXPLORE)
		{
			if (input.isKeyDown(Key::W)) cam.translateFB( CAM_SPEED * dt);
			if (input.isKeyDown(Key::A)) cam.translateLR(-CAM_SPEED * dt);
			if (input.isKeyDown(Key::S)) cam.translateFB(-CAM_SPEED * dt);
			if (input.isKeyDown(Key::D)) cam.translateLR( CAM_SPEED * dt);
			if (input.isKeyDown(Key::C)) cam.translateUD(-CAM_SPEED * dt);
			if (input.isKeyDown(Key::Space)) cam.translateUD(CAM_SPEED * dt);

			cam.rotate(CAM_SENS * .005 * dx, CAM_SENS * .005 * dy);
		}
		else
		{
			if (!DIRECTOR_MODE)
			{
				float dist = cam.getPosition().magnitude();
				if (abs(dx) > 1.0) cam.translateLR(-CAM_SPEED * .002 * dx);
				if (abs(dy) > 1.0) cam.translateUD(-CAM_SPEED * .002 * dy);
				cam.setPosition(cam.getPosition().getNormalized() * dist);
				cam.lookAt(Vec3(0));
			}
			else
			{
				cam.setPosition(Vec3(sinf(GetTime() / 2.0f) * 5.0f, 4.0f, cosf(GetTime() / 2.0f) * 5.0f));
				cam.lookAt(Vec3(0));
			}
		}
		cam.update();

		if (GetTime() - start > 1.0)
		{
			Vec3 ballPos = ball.getPosition();

			float x = Remap(ballPos.getX(), Vec2(-GRAPH_WIDTH / 2, GRAPH_WIDTH / 2), Vec2(-GRAPH_RANGE / 2, GRAPH_RANGE / 2));
			float z = Remap(ballPos.getZ(), Vec2(-GRAPH_WIDTH / 2, GRAPH_WIDTH / 2), Vec2(-GRAPH_RANGE / 2, GRAPH_RANGE / 2));
			float y = f(x, z);
			if (ballPos.getY() < y + 0.12f)
			{
				ball.setPosition(Vec3(ballPos.getX(), y + 0.13f, ballPos.getZ()));
				std::cout << ballVelocity.toString() << " ---> ";
				Vec3 norm = f_norm(x, z);
				Vec3 reflected = Reflect(ballVelocity, norm);
				std::cout << reflected.toString() << "\n";
				ballVelocity = reflected * BOUNCINESS;
				ballVelocity.setY(-ballVelocity.getY());
				if (ballVelocity.getY() < 0.01f) ballVelocity.setY(0.0f);
			}
			else if (ballPos.getY() > y + 0.12f) ballVelocity.setY(ballVelocity.getY() + GRAVITY * dt);

			if (ballPos.getY() <= y + 0.13f)
			{
				DVec2 gradXY = f_grad(x, z);
				Vec3 grad(gradXY.getX(), 0.0f, gradXY.getY());
				if (grad.magnitude() > 0.001f && grad.magnitude() < 0.05f) grad.setMagnitude(0.05f);
				ballVelocity -= grad;
			}

			if (GetTime() - start > 5.0 && ballVelocity.magnitude() < 0.2f) ballVelocity.set(0.0f, 0.0f, 0.0f);

			ball.translate(ballVelocity * dt); 

			if (ballPos.getX() < -GRAPH_WIDTH / 2 + BOUNDARY_OFFSET)
			{
				ballVelocity.setX(-ballVelocity.getX());
				ball.setPosition(Vec3(-GRAPH_WIDTH / 2 + BOUNDARY_OFFSET + CORRECTION_OFFSET, ballPos.getY(), ballPos.getZ()));
			}
			if (ballPos.getX() > GRAPH_WIDTH / 2 - BOUNDARY_OFFSET)
			{
				ballVelocity.setX(-ballVelocity.getX());
				ball.setPosition(Vec3(GRAPH_WIDTH / 2 - BOUNDARY_OFFSET - CORRECTION_OFFSET, ballPos.getY(), ballPos.getZ()));
			}
			if (ballPos.getZ() < -GRAPH_WIDTH / 2 + BOUNDARY_OFFSET)
			{
				ballVelocity.setZ(-ballVelocity.getZ());
				ball.setPosition(Vec3(ballPos.getX(), ballPos.getY(), -GRAPH_WIDTH / 2 + BOUNDARY_OFFSET + CORRECTION_OFFSET));
			}
			if (ballPos.getZ() > GRAPH_WIDTH / 2 - BOUNDARY_OFFSET)
			{
				ballVelocity.setZ(-ballVelocity.getZ());
				ball.setPosition(Vec3(ballPos.getX(), ballPos.getY(), GRAPH_WIDTH / 2 - BOUNDARY_OFFSET - CORRECTION_OFFSET));
			}
		}

		window.startRender();
		renderer.render();
		window.endRender();
	}

	window.dispose();
	renderer.dispose();

	Onyx::Terminate();
}

double f(double x, double y)
{
    return (sin(x) + sin(y) + cos(x / 2) + cos(y / 2) + sin(x / 4) + sin(y / 4) + cos(x / 6) + sin(sqrtf(x * x + y * y))) / 9;
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
    return Cross(DVec3(1, 0, df_dx(x, y)), DVec3(0, 1, df_dy(x, y))).getNormalized();
}

DVec2 f_grad(double x, double y)
{
	return DVec2(df_dx(x, y), df_dy(x, y));
}

Mesh* generateSurface(double width, double depth, const DVec2& domainX, const DVec2& domainY, int nX, int nY)
{
    int vcount = nX * nY * 6;
    int icount = (nX - 1) * (nY - 1) * 6;

    float* vertices = new float[vcount];

    double xStep = (domainX.getY() - domainX.getX()) / (nX - 1);
    double yStep = (domainY.getY() - domainY.getX()) / (nY - 1);

    for (int i = 0; i < nX; i++)
    {
        double x = domainX.getX() + i * xStep;
        for (int j = 0; j < nY; j++)
        {
            double y = domainY.getX() + j * yStep;
            int vi = (i * nY + j) * 6;
            double z = f(x, y);
            DVec3 norm = f_norm(x, y);
            vertices[vi + 0] = Remap(x, DVec2(domainX.getX(), domainX.getY()), DVec2(-width / 2, width / 2));
			vertices[vi + 1] = z;
            vertices[vi + 2] = Remap(y, DVec2(domainY.getX(), domainY.getY()), DVec2(-depth / 2, depth / 2));
            vertices[vi + 3] = norm.getX();
            vertices[vi + 4] = norm.getY();
            vertices[vi + 5] = norm.getZ();
        }
    }

    VertexBuffer vb(vertices, vcount * sizeof(float), VertexFormat::PN);

    uint* indices = new uint[icount];
    for (int i = 0; i < nX - 1; i++)
    {
        for (int j = 0; j < nY - 1; j++)
        {
            int ii = (i * (nY - 1) + j) * 6;
            int vIndex = i * nY + j;
            indices[ii + 0] = vIndex;
            indices[ii + 1] = vIndex + 1;
            indices[ii + 2] = vIndex + nY;

            indices[ii + 3] = vIndex + 1;
            indices[ii + 4] = vIndex + nY + 1;
            indices[ii + 5] = vIndex + nY;
        }
    }

    IndexBuffer ib(indices, icount * sizeof(uint));

    Mesh* mesh = new Mesh(vb, ib);
    onyx_add_malloc(mesh, false);

    delete[] vertices;
    delete[] indices;

    return mesh;
}
