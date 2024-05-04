#pragma warning(disable: 4244)

#include "WindowTest.h"

#include "../src/Core.h"
#include "../src/Window.h"
#include "../src/Renderer.h"

static Onyx::Window window;

static Onyx::TextRenderable title;
static Onyx::TextRenderable dimensions;
static Onyx::TextRenderable bufferDimensions;
static Onyx::TextRenderable position;
static Onyx::TextRenderable frame;
static Onyx::TextRenderable fps;
static Onyx::TextRenderable deltaTime;
static Onyx::TextRenderable opacity;
static Onyx::TextRenderable backgroundColor;
static Onyx::TextRenderable isResizable;
static Onyx::TextRenderable isVisible;
static Onyx::TextRenderable isHidden;
static Onyx::TextRenderable isFocused;
static Onyx::TextRenderable isDecorated;
static Onyx::TextRenderable isTopmost;
static Onyx::TextRenderable focusesOnShow;
static Onyx::TextRenderable nSamplesMSAA;
static Onyx::TextRenderable isFullscreen;
static Onyx::TextRenderable isMaximized;
static Onyx::TextRenderable isMinimized;

static Onyx::Font roboto;

void updateText();
void updatePositions();

void WindowTest::Run()
{
	Onyx::ErrorHandler errorHandler(true, true);
	Onyx::Init(errorHandler);

	window = Onyx::Window(
		Onyx::WindowProperties{
			.title = "Title 1",
			.width = 950,
			.height = 600,
			.position = Onyx::Math::IVec2(100, 100),
			.nSamplesMSAA = 4,
			.backgroundColor = Onyx::Math::Vec3::White()
		}
	);
	window.init();

	Onyx::InputHandler input;
	window.linkInputHandler(input);

	Onyx::Camera cam(Onyx::Projection::Orthographic(1280.0f, 600.0f));
	window.linkCamera(cam);
	Onyx::Renderer renderer(cam);
	window.linkRenderer(renderer);

	roboto = Onyx::Font::Load(Onyx::Resources("fonts/Roboto/Roboto-Regular.ttf"), 16);

	title =             Onyx::TextRenderable("Title: " + window.getTitle(), roboto, Onyx::Math::Vec4::Black());
	dimensions =        Onyx::TextRenderable("Dimensions: " + std::to_string(window.getWidth()) + "x" + std::to_string(window.getHeight()), roboto, Onyx::Math::Vec4::Black());
	bufferDimensions =  Onyx::TextRenderable("Buffer Dimensions: " + std::to_string(window.getBufferWidth()) + "x" + std::to_string(window.getBufferHeight()), roboto, Onyx::Math::Vec4::Black());
	position =          Onyx::TextRenderable("Position: " + window.getPosition().toString(), roboto, Onyx::Math::Vec4::Black());
	frame =             Onyx::TextRenderable("Frame: " + std::to_string(window.getFrame()), roboto, Onyx::Math::Vec4::Black());
	fps =               Onyx::TextRenderable("FPS: " + std::to_string(window.getFPS()), roboto, Onyx::Math::Vec4::Black());
	deltaTime =         Onyx::TextRenderable("Delta Time: " + std::to_string(window.getDeltaTime()) + "s", roboto, Onyx::Math::Vec4::Black());
	opacity =			Onyx::TextRenderable("Opacity: " + std::to_string(window.getOpacity()), roboto, Onyx::Math::Vec4::Black());
	backgroundColor =	Onyx::TextRenderable("Background Color: " + window.getBackgroundColor().toString(), roboto, Onyx::Math::Vec4::Black());
	isResizable =		Onyx::TextRenderable("Is Resizable: " + std::string(window.isResizable() ? "true" : "false"), roboto, Onyx::Math::Vec4::Black());
	isVisible =			Onyx::TextRenderable("Is Visible: " + std::string(window.isVisible() ? "true" : "false"), roboto, Onyx::Math::Vec4::Black());
	isHidden =			Onyx::TextRenderable("Is Hidden: " + std::string(window.isHidden() ? "true" : "false"), roboto, Onyx::Math::Vec4::Black());
	isFocused =			Onyx::TextRenderable("Is Focused: " + std::string(window.isFocused() ? "true" : "false"), roboto, Onyx::Math::Vec4::Black());
	isDecorated =		Onyx::TextRenderable("Is Decorated: " + std::string(window.isDecorated() ? "true" : "false"), roboto, Onyx::Math::Vec4::Black());
	isTopmost =			Onyx::TextRenderable("Is Topmost: " + std::string(window.isTopmost() ? "true" : "false"), roboto, Onyx::Math::Vec4::Black());
	focusesOnShow =		Onyx::TextRenderable("Focuses On Show: " + std::string(window.focusesOnShow() ? "true" : "false"), roboto, Onyx::Math::Vec4::Black());
	nSamplesMSAA =		Onyx::TextRenderable("# MSAA Samples: " + std::to_string(window.getNSamplesMSAA()), roboto, Onyx::Math::Vec4::Black());
	isFullscreen =		Onyx::TextRenderable("Is Fullscreen: " + std::string(window.isFullscreen() ? "true" : "false"), roboto, Onyx::Math::Vec4::Black());
	isMaximized =		Onyx::TextRenderable("Is Maximized: " + std::string(window.isMaximized() ? "true" : "false"), roboto, Onyx::Math::Vec4::Black());
	isMinimized =		Onyx::TextRenderable("Is Minimized: " + std::string(window.isMinimized() ? "true" : "false"), roboto, Onyx::Math::Vec4::Black());

	Onyx::TextRenderable esc("[ESC] Close Window", roboto, Onyx::Math::Vec4::Black());
	Onyx::TextRenderable up("[UP] Increase Opacity", roboto, Onyx::Math::Vec4::Black());
	Onyx::TextRenderable down("[DOWN] Decrease Opacity", roboto, Onyx::Math::Vec4::Black());
	Onyx::TextRenderable f1 ("[F1] Toggle Title", roboto, Onyx::Math::Vec4::Black());
	Onyx::TextRenderable f2 ("[F2] Toggle Background Color From Mouse Pos", roboto, Onyx::Math::Vec4::Black());
	Onyx::TextRenderable f3 ("[F3] Focus Window", roboto, Onyx::Math::Vec4::Black());
	Onyx::TextRenderable f4 ("[F4] Toggle Resizable", roboto, Onyx::Math::Vec4::Black());
	Onyx::TextRenderable f5 ("[F5] Toggle Decorated", roboto, Onyx::Math::Vec4::Black());
	Onyx::TextRenderable f6 ("[F6] Toggle Topmost", roboto, Onyx::Math::Vec4::Black());
	Onyx::TextRenderable f7 ("[F7] Toggle Focus On Show", roboto, Onyx::Math::Vec4::Black());
	Onyx::TextRenderable f8 ("[F8] Minimize", roboto, Onyx::Math::Vec4::Black());
	Onyx::TextRenderable f9 ("[F9] Maximize", roboto, Onyx::Math::Vec4::Black());
	Onyx::TextRenderable f10("[F10] Restore", roboto, Onyx::Math::Vec4::Black());
	Onyx::TextRenderable f11("[F11] Request Attention", roboto, Onyx::Math::Vec4::Black());
	Onyx::TextRenderable f12("[F12] Toggle Fullscreen", roboto, Onyx::Math::Vec4::Black());
	esc.setPosition(Onyx::Math::Vec2(10.0f, 290.0f));
	up.setPosition(Onyx::Math::Vec2(10.0f, 270.0f));
	down.setPosition(Onyx::Math::Vec2(10.0f, 250.0f));
	f1.setPosition(Onyx::Math::Vec2(10.0f, 230.0f));
	f2.setPosition(Onyx::Math::Vec2(10.0f, 210.0f));
	f3.setPosition(Onyx::Math::Vec2(10.0f, 190.0f));
	f4.setPosition(Onyx::Math::Vec2(10.0f, 170.0f));
	f5.setPosition(Onyx::Math::Vec2(10.0f, 150.0f));
	f6.setPosition(Onyx::Math::Vec2(10.0f, 130.0f));
	f7.setPosition(Onyx::Math::Vec2(10.0f, 110.0f));
	f8.setPosition(Onyx::Math::Vec2(10.0f, 90.0f));
	f9.setPosition(Onyx::Math::Vec2(10.0f, 70.0f));
	f10.setPosition(Onyx::Math::Vec2(10.0f, 50.0f));
	f11.setPosition(Onyx::Math::Vec2(10.0f, 30.0f));
	f12.setPosition(Onyx::Math::Vec2(10.0f, 10.0f));

	Onyx::UiRenderable logo(Onyx::Mesh(Onyx::VertexBuffer::Square(256.0f, true), Onyx::IndexBuffer::Square()), Onyx::Texture::Load(Onyx::Resources("textures/onyx.png")));
	logo.setPosition(Onyx::Math::Vec2(640.0f, 270.0f));

	renderer.add(title);
	renderer.add(dimensions);
	renderer.add(bufferDimensions);
	renderer.add(position);
	renderer.add(frame);
	renderer.add(fps);
	renderer.add(deltaTime);
	renderer.add(opacity);
	renderer.add(backgroundColor);
	renderer.add(isResizable);
	renderer.add(isVisible);
	renderer.add(isHidden);
	renderer.add(isFocused);
	renderer.add(isDecorated);
	renderer.add(isTopmost);
	renderer.add(focusesOnShow);
	renderer.add(nSamplesMSAA);
	renderer.add(isFullscreen);
	renderer.add(isMaximized);
	renderer.add(isMinimized);

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
	bool mousePosIsColor = false;

	input.setKeyCooldown(Onyx::Key::F1, 0.5f);
	input.setKeyCooldown(Onyx::Key::F2, 0.5f);
	input.setKeyCooldown(Onyx::Key::F3, 0.5f);
	input.setKeyCooldown(Onyx::Key::F4, 0.5f);
	input.setKeyCooldown(Onyx::Key::F5, 0.5f);
	input.setKeyCooldown(Onyx::Key::F6, 0.5f);
	input.setKeyCooldown(Onyx::Key::F7, 0.5f);
	input.setKeyCooldown(Onyx::Key::F8, 0.5f);
	input.setKeyCooldown(Onyx::Key::F9, 0.5f);
	input.setKeyCooldown(Onyx::Key::F10, 0.5f);
	input.setKeyCooldown(Onyx::Key::F11, 0.5f);
	input.setKeyCooldown(Onyx::Key::F12, 0.5f);

	while (window.isOpen())
	{
		double dt = window.getDeltaTime();

		input.update();
		cam.update();
		updateText();
		updatePositions();

		if (mousePosIsColor)
		{
			window.setBackgroundColor(Onyx::Math::Vec3(input.getMousePos().getX() / window.getWidth(), input.getMousePos().getY() / window.getHeight(), 1.0f));
		}

		if (input.isKeyDown(Onyx::Key::Escape)) window.close();
		if (input.isKeyDown(Onyx::Key::ArrowUp)) window.setOpacity(window.getOpacity() + 0.5 * dt);
		if (input.isKeyDown(Onyx::Key::ArrowDown)) window.setOpacity(window.getOpacity() - 0.5 * dt);
		if (input.isKeyDown(Onyx::Key::F1))
		{
			if (title1)
			{
				window.setTitle("Title 2");
				title1 = false;
			}
			else
			{
				window.setTitle("Title 1");
				title1 = true;
			}
		}
		if (input.isKeyDown(Onyx::Key::F2)) mousePosIsColor = !mousePosIsColor;
		if (input.isKeyDown(Onyx::Key::F3)) window.focus();
		if (input.isKeyDown(Onyx::Key::F4)) window.toggleResizable();
		if (input.isKeyDown(Onyx::Key::F5)) window.toggleDecorated();
		if (input.isKeyDown(Onyx::Key::F6)) window.toggleTopmost();
		if (input.isKeyDown(Onyx::Key::F7)) window.toggleFocusOnShow();
		if (input.isKeyDown(Onyx::Key::F8)) window.minimize();
		if (input.isKeyDown(Onyx::Key::F9)) window.maximize();
		if (input.isKeyDown(Onyx::Key::F10)) window.restore();
		if (input.isKeyDown(Onyx::Key::F11)) window.requestAttention();
		if (input.isKeyDown(Onyx::Key::F12)) window.toggleFullscreen(950, 600, Onyx::Math::IVec2(100, 100));

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();
	Onyx::Terminate();
}

void updateText()
{
	title.setText("Title: " + window.getTitle());
	dimensions.setText("Dimensions: " + std::to_string(window.getWidth()) + "x" + std::to_string(window.getHeight()));
	bufferDimensions.setText("Buffer Dimensions: " + std::to_string(window.getBufferWidth()) + "x" + std::to_string(window.getBufferHeight()));
	position.setText("Position: " + window.getPosition().toString());
	frame.setText("Frame: " + std::to_string(window.getFrame()));
	fps.setText("FPS: " + std::to_string(window.getFPS()));
	deltaTime.setText("Delta Time: " + std::to_string(window.getDeltaTime()) + "s");
	opacity.setText("Opacity: " + std::to_string(window.getOpacity()));
	backgroundColor.setText("Background Color: " + window.getBackgroundColor().toString());
	isResizable.setText("Is Resizable: " + std::string(window.isResizable() ? "true" : "false"));
	isVisible.setText("Is Visible: " + std::string(window.isVisible() ? "true" : "false"));
	isHidden.setText("Is Hidden: " + std::string(window.isHidden() ? "true" : "false"));
	isFocused.setText("Is Focused: " + std::string(window.isFocused() ? "true" : "false"));
	isDecorated.setText("Is Decorated: " + std::string(window.isDecorated() ? "true" : "false"));
	isTopmost.setText("Is Topmost: " + std::string(window.isTopmost() ? "true" : "false"));
	focusesOnShow.setText("Focuses On Show: " + std::string(window.focusesOnShow() ? "true" : "false"));
	nSamplesMSAA.setText("# MSAA Samples: " + std::to_string(window.getNSamplesMSAA()));
	isFullscreen.setText("Is Fullscreen: " + std::string(window.isFullscreen() ? "true" : "false"));
	isMaximized.setText("Is Maximized: " + std::string(window.isMaximized() ? "true" : "false"));
	isMinimized.setText("Is Minimized: " + std::string(window.isMinimized() ? "true" : "false"));	
}

void updatePositions()
{
	title.setPosition(Onyx::Math::Vec2(10.0f, window.getBufferHeight() - 20.0f));
	dimensions.setPosition(Onyx::Math::Vec2(10.0f, window.getBufferHeight() - 40.0f));
	bufferDimensions.setPosition(Onyx::Math::Vec2(10.0f, window.getBufferHeight() - 60.0f));
	position.setPosition(Onyx::Math::Vec2(10.0f, window.getBufferHeight() - 80.0f));
	frame.setPosition(Onyx::Math::Vec2(10.0f, window.getBufferHeight() - 100.0f));
	fps.setPosition(Onyx::Math::Vec2(10.0f, window.getBufferHeight() - 120.0f));
	backgroundColor.setPosition(Onyx::Math::Vec2(10.0f, window.getBufferHeight() - 140.0f));
	deltaTime.setPosition(Onyx::Math::Vec2(260.0f, window.getBufferHeight() - 20.0f));
	opacity.setPosition(Onyx::Math::Vec2(260.0f, window.getBufferHeight() - 40.0f));
	isResizable.setPosition(Onyx::Math::Vec2(260.0f, window.getBufferHeight() - 60.0f));
	isVisible.setPosition(Onyx::Math::Vec2(260.0f, window.getBufferHeight() - 80.0f));
	isHidden.setPosition(Onyx::Math::Vec2(260.0f, window.getBufferHeight() - 100.0f));
	isFocused.setPosition(Onyx::Math::Vec2(510.0f, window.getBufferHeight() - 20));
	isDecorated.setPosition(Onyx::Math::Vec2(510.0f, window.getBufferHeight() - 40));
	isTopmost.setPosition(Onyx::Math::Vec2(510.0f, window.getBufferHeight() - 60));
	focusesOnShow.setPosition(Onyx::Math::Vec2(510.0f, window.getBufferHeight() - 80));
	nSamplesMSAA.setPosition(Onyx::Math::Vec2(510.0f, window.getBufferHeight() - 100));
	isFullscreen.setPosition(Onyx::Math::Vec2(760.0f, window.getBufferHeight() - 20));
	isMaximized.setPosition(Onyx::Math::Vec2(760.0f, window.getBufferHeight() - 40));
	isMinimized.setPosition(Onyx::Math::Vec2(760.0f, window.getBufferHeight() - 60));

}
