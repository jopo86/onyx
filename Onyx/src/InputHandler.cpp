#pragma warning(disable : 4244)

#include "InputHandler.h"

using Onyx::Math::DVec2;

Onyx::InputHandler::InputHandler()
{
	p_win = nullptr;

	for (int i = 0; i < Onyx::Key::MaxKey; i++)
	{
		keys[i] = Onyx::KeyState::Untouched;
		keyCooldowns[i] = 0.0f;
		setKeyCooldowns[i] = 0.0f;
	}

	for (int i = 0; i < Onyx::MouseButton::MaxButton; i++)
	{
		buttons[i] = Onyx::KeyState::Untouched;
		buttonCooldowns[i] = 0.0f;
		setButtonCooldowns[i] = 0.0f;
	}

	mousePos = DVec2(0.0f);
	lastMousePos = DVec2(0.0f);
	mouseDeltas = DVec2(0.0f);

	cursorLock = false;
}

Onyx::InputHandler::InputHandler(Window& window)
{
	p_win = &window;
	window.p_inputHandler = this;

	double mouseX, mouseY;
	glfwGetCursorPos(p_win->p_glfwWin, &mouseX, &mouseY);
	mousePos = DVec2(mouseX, mouseY);
	lastMousePos = DVec2(mouseX, mouseY);

	for (int i = 0; i < Onyx::Key::MaxKey; i++)
	{
		keys[i] = Onyx::KeyState::Untouched;
		keyCooldowns[i] = 0.0f;
		setKeyCooldowns[i] = 0.0f;
	}

	for (int i = 0; i < Onyx::MouseButton::MaxButton; i++)
	{
		buttons[i] = Onyx::KeyState::Untouched;
		buttonCooldowns[i] = 0.0f;
		setButtonCooldowns[i] = 0.0f;
	}

	mouseDeltas = DVec2(0.0f);

	cursorLock = false;
}

void Onyx::InputHandler::update()
{
	mouseDeltas.setX(mousePos.getX() - lastMousePos.getX());
	mouseDeltas.setY(mousePos.getY() - lastMousePos.getY());

	lastMousePos.setX(mousePos.getX());
	lastMousePos.setY(mousePos.getY());

	for (int key : activeKeyCooldowns)
	{
		if (keyCooldowns[key] >= 0) keyCooldowns[key] -= p_win->deltaTime;
	}

	for (int button : activeButtonCooldowns)
	{
		if (buttonCooldowns[button] >= 0) buttonCooldowns[button] -= p_win->deltaTime;
	}
}

Onyx::KeyState Onyx::InputHandler::getKeyState(Onyx::Key key) const
{
	return keys[key];
}

bool Onyx::InputHandler::isKeyPressed(Onyx::Key key)
{
	if (key < 0) return false;
	bool retval = keyCooldowns[key] <= 0 ? keys[key] == Onyx::KeyState::Press : false;
	if (retval) keyCooldowns[key] = setKeyCooldowns[key];
	return retval;
}

bool Onyx::InputHandler::isKeyRepeated(Onyx::Key key)
{
	if (key < 0) return false;
	bool retval = keyCooldowns[key] <= 0 ? keys[key] == Onyx::KeyState::Repeat : false;
	if (retval) keyCooldowns[key] = setKeyCooldowns[key];
	return retval;
}

bool Onyx::InputHandler::isKeyDown(Onyx::Key key)
{
	if (key < 0) return false;
	bool retval = keyCooldowns[key] <= 0 ? keys[key] == Onyx::KeyState::Press || keys[key] == Onyx::KeyState::Repeat : false;
	if (retval) keyCooldowns[key] = setKeyCooldowns[key];
	return retval;
}

Onyx::KeyState Onyx::InputHandler::getMouseButtonState(Onyx::MouseButton button) const
{
	return buttons[button];
}

bool Onyx::InputHandler::isMouseButtonPressed(Onyx::MouseButton button)
{
	if (button < 0) return false;
	bool retval = buttonCooldowns[button] <= 0 ? buttons[button] == Onyx::KeyState::Press : false;
	if (retval) buttonCooldowns[button] = setButtonCooldowns[button];
	return retval;
}

bool Onyx::InputHandler::isMouseButtonRepeated(Onyx::MouseButton button)
{
	if (button < 0) return false;
	bool retval = buttonCooldowns[button] <= 0 ? buttons[button] == Onyx::KeyState::Repeat : false;
	if (retval) buttonCooldowns[button] = setButtonCooldowns[button];
	return retval;
}

bool Onyx::InputHandler::isMouseButtonDown(Onyx::MouseButton button)
{
	if (button < 0) return false;
	bool retval = buttonCooldowns[button] <= 0 ? buttons[button] == Onyx::KeyState::Press || buttons[button] == Onyx::KeyState::Repeat : false;
	if (retval) buttonCooldowns[button] = setButtonCooldowns[button];
	return retval;
}

void Onyx::InputHandler::setKeyCooldown(Onyx::Key key, float cooldown)
{
	activeKeyCooldowns.push_back(key);
	setKeyCooldowns[key] = cooldown;
}

void Onyx::InputHandler::setMouseButtonCooldown(Onyx::MouseButton button, float cooldown)
{
	activeButtonCooldowns.push_back(button);
	setButtonCooldowns[button] = cooldown;
}

void Onyx::InputHandler::setCursorLock(bool lock)
{
	cursorLock = lock;
	glfwSetInputMode(p_win->p_glfwWin, GLFW_CURSOR, lock ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
}

void Onyx::InputHandler::toggleCursorLock()
{
	setCursorLock(!cursorLock);
}

Onyx::Math::DVec2& Onyx::InputHandler::getMousePos() const
{
	return (Math::DVec2&)mousePos;
}

Onyx::Math::DVec2& Onyx::InputHandler::getMouseDeltas() const
{
	return (Math::DVec2&)mouseDeltas;
}

void Onyx::InputHandler::rcb_key(int key, int scancode, int action, int mods) 
{
	keys[key] = (Onyx::KeyState)action;
}

void Onyx::InputHandler::rcb_mouseButton(int button, int action, int mods) 
{
	buttons[button] = (Onyx::KeyState)action;
}

void Onyx::InputHandler::rcb_cursorPos(double x, double y) 
{
	mousePos.setX(x);
	mousePos.setY(y);
}
