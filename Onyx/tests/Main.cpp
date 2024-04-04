#include <iostream>

#include "../src/Core.h"

#include "UnitTests.h"
#include "PresetTests.h"

using Onyx::Math::Vec2, Onyx::Math::Vec3, Onyx::Math::Vec4;

int main()
{
	/*Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);
	Onyx::Demo();
	Onyx::Terminate();*/

	/*UnitTests::RunAllTests();
	PresetTests::RunAllTests();*/

	Onyx::Window window("Lighting Test", 1280, 720);
	window.init();
	window.setBackgroundColor(Vec3(0.0f, 0.0f, 0.0f));

	Onyx::InputHandler input(window);
	
	Onyx::ErrorHandler errorHandler(true, false);
	Onyx::Init(errorHandler);

	Onyx::Shader objShader(
		Onyx::File(Onyx::Resources("../tests/shaders/obj.vert")).readLiteral(),
		Onyx::File(Onyx::Resources("../tests/shaders/obj.frag")).readLiteral()
	);

	Onyx::Shader lightShader(
		Onyx::File(Onyx::Resources("../tests/shaders/light.vert")).readLiteral(),
		Onyx::File(Onyx::Resources("../tests/shaders/light.frag")).readLiteral()
	);

	objShader.use();
	objShader.uniform("objectColor", Vec3(1.0f, 0.5f, 0.31f));
	objShader.uniform("lightColor", Vec3(1.0f, 1.0f, 1.0f));
	objShader.uniform("viewPos", Vec3(0.0f));

	Vec3 lightPos(1.2f, 1.0f, 2.0f);
	objShader.uniform("lightPos", lightPos);

	float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
	};

	uint indices[] = {
		0, 1, 2,
		3, 4, 5,

		6, 7, 8,
		9, 10, 11,

		12, 13, 14,
		15, 16, 17,

		18, 19, 20,
		21, 22, 23,

		24, 25, 26,
		27, 28, 29,

		30, 31, 32,
		33, 34, 35
	};

	Onyx::Mesh objMesh(
		Onyx::VertexArray(vertices, sizeof(vertices), ONYX_VERTEX_FORMAT_VN, false),
		Onyx::IndexArray(indices, sizeof(indices), false)
	);

	Onyx::Renderable obj(objMesh, objShader);
	Onyx::Renderable light(Onyx::MeshPresets::Cube(0.1f), lightShader);

	light.translate(lightPos);

	Onyx::Camera cam(window, Onyx::Projection::Perspective(60.0f, 1280, 720));
	cam.translate(Vec3(0.6f, 0.4f, -4.0f));

	Onyx::Renderer renderer(window, cam);
	renderer.add(obj);
	renderer.add(light);

	const float CAM_SPEED = 4.0f;
	const float CAM_SENS = 30.0f;

	input.setCursorLock(true);
	while (window.isOpen())
	{
		input.update();

		if (input.isKeyDown(ONYX_KEY_ESCAPE)) window.close();
		if (input.isKeyDown(ONYX_KEY_W)) cam.translateFB(1.0f * CAM_SPEED * window.getDeltaTime());
		if (input.isKeyDown(ONYX_KEY_A)) cam.translateLR(-1.0f * CAM_SPEED * window.getDeltaTime());
		if (input.isKeyDown(ONYX_KEY_S)) cam.translateFB(-1.0f * CAM_SPEED * window.getDeltaTime());
		if (input.isKeyDown(ONYX_KEY_D)) cam.translateLR(1.0f * CAM_SPEED * window.getDeltaTime());
		if (input.isKeyDown(ONYX_KEY_SPACE)) cam.translateUD(1.0f * CAM_SPEED * window.getDeltaTime());
		if (input.isKeyDown(ONYX_KEY_C)) cam.translateUD(-1.0f * CAM_SPEED * window.getDeltaTime());

		cam.rotate(input.getMouseDeltas().getX() * 0.005f * CAM_SENS, input.getMouseDeltas().getY() * 0.005f * CAM_SENS);

		cam.update();

		lightPos.setX(1.0f + sin(Onyx::GetTime()) * 2.0f);
		lightPos.setZ(cos(Onyx::GetTime()) * 2.0f);
		lightPos.setY(sin(Onyx::GetTime() / 2.0f));

		light.resetTransform();
		light.translate(lightPos);

		objShader.use();
		objShader.uniform("viewPos", cam.getPosition());
		objShader.uniform("lightPos", lightPos);

		window.startRender();
		renderer.render();
		window.endRender();
	}

	window.dispose();
	renderer.dispose();

	Onyx::Terminate();
	
	return 0;
}
