#pragma warning(disable: 4244)

#include <iostream>

#include "../src/Core.h"

#include "UnitTests.h"
#include "PresetTests.h"

using Onyx::Math::Vec2, Onyx::Math::Vec3, Onyx::Math::Vec4;

void lightingTest();


int main()
{
	Onyx::ErrorHandler errorHandler(false, false, false);
	Onyx::Init(errorHandler);
	Onyx::Demo();
	Onyx::Terminate();

	/*UnitTests::RunAllTests();
	PresetTests::RunAllTests();*/

	//lightingTest();
	
	return 0;
}

void lightingTest()
{
	Onyx::ErrorHandler errorHandler(true, true, false);
	Onyx::Init(errorHandler);

	Onyx::Window window("Lighting Test", 1280, 720);
	window.init();
	window.setBackgroundColor(Vec3(0.0f, 0.0f, 0.0f));

	Onyx::InputHandler input(window);


	Onyx::Shader objShader(
		Onyx::FileUtils::ReadLiteral(Onyx::Resources("../tests/shaders/obj.vert")),
		Onyx::FileUtils::ReadLiteral(Onyx::Resources("../tests/shaders/obj.frag"))
	);

	Onyx::Shader lightShader(
		Onyx::FileUtils::ReadLiteral(Onyx::Resources("../tests/shaders/light.vert")),
		Onyx::FileUtils::ReadLiteral(Onyx::Resources("../tests/shaders/light.frag"))
	);

	lightShader.use();
	lightShader.setVec3("u_color", Vec3(1.0f, 1.0f, 1.0f));

	objShader.use();
	objShader.setVec3("objectColor", Vec3(0.9f, 0.9f, 0.9f));
	objShader.setVec3("lightColor", Vec3(1.0f, 1.0f, 1.0f));
	objShader.setVec3("viewPos", Vec3(0.0f));
	objShader.setVec3("light.direction", Vec3(-0.2f, -1.0f, -0.3f));

	objShader.setVec3("material.ambient", Vec3(0.8f, 0.8f, 0.8f));
	objShader.setVec3("material.diffuse", Vec3(0.8f, 0.8f, 0.8f));
	objShader.setVec3("material.specular", Vec3(1.0f, 1.0f, 1.0f));
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
		Onyx::VertexArray(vertices, sizeof(vertices), Onyx::VertexFormat::VN),
		Onyx::IndexArray(indices, sizeof(indices))
	);

	Onyx::Renderable obj(objMesh, objShader);
	Onyx::Renderable light(Onyx::MeshPresets::Cube(0.1f), lightShader);

	Onyx::Camera cam(window, Onyx::Projection::Perspective(60.0f, 1280, 720));
	cam.translate(Vec3(0.6f, 0.4f, -4.0f));

	float uiVertices[] = {
		10.0f, 10.0f, 0.0f,
		160.0f, 10.0f, 0.0f,
		160.0f, 55.0f, 0.0f,
		10.0f, 55.0f, 0.0f
	};

	uint uiIndices[] = {
		0, 1, 2,
		2, 3, 0
	};

	Onyx::UiRenderable ui(
		Onyx::Mesh(
			Onyx::VertexArray(uiVertices, sizeof(uiVertices), Onyx::VertexFormat::V),
			Onyx::IndexArray(uiIndices, sizeof(uiIndices))
		),
		Vec4(1.0f, 1.0f, 1.0f, 0.2f)
	);

	Onyx::Renderer renderer(window, cam);
	renderer.add(obj);
	renderer.add(light);
	renderer.add(ui);

	Onyx::TextRenderer textRenderer(window);
	Onyx::Font roboto = Onyx::Font::Load(Onyx::Resources("fonts/Roboto/Roboto-Regular.ttf"), 32);
	textRenderer.setFont(roboto);

	const float CAM_SPEED = 4.0f;
	const float CAM_SENS = 30.0f;

	int fps = 0.0f;

	input.setCursorLock(true);
	while (window.isOpen())
	{

		if (window.getFrame() % 60 == 0 || window.getFrame() == 1) fps = window.getFPS();

		input.update();

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::W)) cam.translateFB(1.0f * CAM_SPEED * window.getDeltaTime());
		if (input.isKeyDown(Onyx::Key::A)) cam.translateLR(-1.0f * CAM_SPEED * window.getDeltaTime());
		if (input.isKeyDown(Onyx::Key::S)) cam.translateFB(-1.0f * CAM_SPEED * window.getDeltaTime());
		if (input.isKeyDown(Onyx::Key::D)) cam.translateLR(1.0f * CAM_SPEED * window.getDeltaTime());
		if (input.isKeyDown(Onyx::Key::Space)) cam.translateUD(1.0f * CAM_SPEED * window.getDeltaTime());
		if (input.isKeyDown(Onyx::Key::C)) cam.translateUD(-1.0f * CAM_SPEED * window.getDeltaTime());

		cam.rotate(input.getMouseDeltas().getX() * 0.005f * CAM_SENS, input.getMouseDeltas().getY() * 0.005f * CAM_SENS);

		cam.update();

		lightPos.setX(cos(Onyx::GetTime()) * 2.0f);
		lightPos.setY(sin(Onyx::GetTime() * 2.0f));
		lightPos.setZ(sin(Onyx::GetTime()) * 2.0f);

		light.resetTransform();
		light.translate(lightPos);

		objShader.use();
		objShader.setVec3("viewPos", cam.getPosition());
		//objShader.setVec3("light.pos", lightPos);

		lightColor.setX(sin(Onyx::GetTime() * 2.0f));
		lightColor.setY(sin(Onyx::GetTime() * 0.7f));
		lightColor.setZ(sin(Onyx::GetTime() * 1.3f));

		Vec3 diffuseColor = lightColor * 0.5f;
		Vec3 ambientColor = diffuseColor * 0.4f;

		objShader.setVec3("light.ambient", ambientColor);
		objShader.setVec3("light.diffuse", diffuseColor);
		objShader.setVec3("light.specular", lightColor);

		lightShader.use();
		lightShader.setVec3("u_color", lightColor);

		window.startRender();
		renderer.render();
		Onyx::TextRenderer::StartRender();
		textRenderer.render("FPS: " + std::to_string(fps), Vec2(20.0f, 20.0f), Vec3(1.0f, 1.0f, 1.0f));
		Onyx::TextRenderer::EndRender();
		window.endRender();
	}

	window.dispose();
	renderer.dispose();
	roboto.dispose();

	Onyx::Terminate();
}
