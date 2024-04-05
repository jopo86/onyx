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

	lightShader.use();
	lightShader.setVec3("u_color", Vec3(1.0f, 1.0f, 1.0f));

	objShader.use();
	objShader.setVec3("objectColor", Vec3(0.9f, 0.9f, 0.9f));
	objShader.setVec3("lightColor", Vec3(1.0f, 1.0f, 1.0f));
	objShader.setVec3("viewPos", Vec3(0.0f));

	objShader.setVec3("material.ambient", Vec3(1.0f, 0.5f, 0.31f));
	objShader.setVec3("material.diffuse", Vec3(1.0f, 0.5f, 0.31f));
	objShader.setVec3("material.specular", Vec3(0.5f, 0.5f, 0.5f));
	objShader.setFloat("material.shininess", 32.0f);

	Vec3 lightColor;

	Vec3 lightPos(0.0f, 1.0f, 0.0f);
	objShader.setVec3("lightPos", lightPos);

	const Vec2 vec1(0.0f);
	const Vec2 vec2(0.0f);
	const Vec2 vec3 = vec1 + vec2;

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

		lightPos.setX(cos(Onyx::GetTime()) * 2.0f);
		lightPos.setZ(sin(Onyx::GetTime()) * 2.0f);

		light.resetTransform();
		light.translate(lightPos);

		objShader.use();
		objShader.setVec3("viewPos", cam.getPosition());
		objShader.setVec3("lightPos", lightPos);

		lightColor.setX(sin(Onyx::GetTime() * 2.0f));
		lightColor.setY(sin(Onyx::GetTime() * 0.7f));
		lightColor.setZ(sin(Onyx::GetTime() * 1.3f));

		Vec3 diffuseColor = lightColor * 0.5f;
		Vec3 ambientColor = diffuseColor * 0.2f;

		objShader.setVec3("light.ambient", ambientColor);
		objShader.setVec3("light.diffuse", diffuseColor);
		objShader.setVec3("light.specular", Vec3(1.0f, 1.0f, 1.0f));

		lightShader.use();
		lightShader.setVec3("u_color", lightColor);

		window.startRender();
		renderer.render();
		window.endRender();
	}

	window.dispose();
	renderer.dispose();

	Onyx::Terminate();
	
	return 0;
}
