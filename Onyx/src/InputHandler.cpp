#pragma warning(disable : 4244)

#include "InputHandler.h"

using Onyx::Math::DVec2;

Onyx::InputHandler::InputHandler()
{
	p_win = nullptr;

	for (int i = 0; i < ONYX_MAX_KEY; i++)
	{
		keys[i] = ONYX_KEYSTATE_UNTOUCHED;
		keyCooldowns[i] = 0.0f;
		setKeyCooldowns[i] = 0.0f;
	}

	for (int i = 0; i < ONYX_MAX_MOUSE_BUTTON; i++)
	{
		buttons[i] = ONYX_KEYSTATE_UNTOUCHED;
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

	for (int i = 0; i < ONYX_MAX_KEY; i++)
	{
		keys[i] = ONYX_KEYSTATE_UNTOUCHED;
		keyCooldowns[i] = 0.0f;
		setKeyCooldowns[i] = 0.0f;
	}

	for (int i = 0; i < ONYX_MAX_MOUSE_BUTTON; i++)
	{
		buttons[i] = ONYX_KEYSTATE_UNTOUCHED;
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

int Onyx::InputHandler::getKeystate(int key)
{
	return keys[key];
}

bool Onyx::InputHandler::isKeyPressed(int key)
{
	bool retval = keyCooldowns[key] <= 0 ? keys[key] == ONYX_KEYSTATE_PRESS : false;
	if (retval) keyCooldowns[key] = setKeyCooldowns[key];
	return retval;
}

bool Onyx::InputHandler::isKeyRepeated(int key)
{
	bool retval = keyCooldowns[key] <= 0 ? keys[key] == ONYX_KEYSTATE_REPEAT : false;
	if (retval) keyCooldowns[key] = setKeyCooldowns[key];
	return retval;
}

bool Onyx::InputHandler::isKeyDown(int key)
{
	bool retval = keyCooldowns[key] <= 0 ? keys[key] == ONYX_KEYSTATE_PRESS || keys[key] == ONYX_KEYSTATE_REPEAT : false;
	if (retval) keyCooldowns[key] = setKeyCooldowns[key];
	return retval;
}

int Onyx::InputHandler::getMouseButtonState(int button)
{
	return buttons[button];
}

bool Onyx::InputHandler::isMouseButtonPressed(int button)
{
	bool retval = buttonCooldowns[button] <= 0 ? buttons[button] == ONYX_KEYSTATE_PRESS : false;
	if (retval) buttonCooldowns[button] = setButtonCooldowns[button];
	return retval;
}

bool Onyx::InputHandler::isMouseButtonRepeated(int button)
{
	bool retval = buttonCooldowns[button] <= 0 ? buttons[button] == ONYX_KEYSTATE_REPEAT : false;
	if (retval) buttonCooldowns[button] = setButtonCooldowns[button];
	return retval;
}

bool Onyx::InputHandler::isMouseButtonDown(int button)
{
	bool retval = buttonCooldowns[button] <= 0 ? buttons[button] == ONYX_KEYSTATE_PRESS || buttons[button] == ONYX_KEYSTATE_REPEAT : false;
	if (retval) buttonCooldowns[button] = setButtonCooldowns[button];
	return retval;
}

void Onyx::InputHandler::setKeyCooldown(int key, float cooldown)
{
	activeKeyCooldowns.push_back(key);
	setKeyCooldowns[key] = cooldown;
}

void Onyx::InputHandler::setMouseButtonCooldown(int button, float cooldown)
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

Onyx::Math::DVec2& Onyx::InputHandler::getMousePos()
{
	return mousePos;
}

Onyx::Math::DVec2& Onyx::InputHandler::getMouseDeltas()
{
	return mouseDeltas;
}

void Onyx::InputHandler::RCB_key(int key, int scancode, int action, int mods) 
{
	keys[key] = action;
}

void Onyx::InputHandler::RCB_mouseButton(int button, int action, int mods) 
{
	buttons[button] = action;
}

void Onyx::InputHandler::RCB_cursorPos(double x, double y) 
{
	mousePos.setX(x);
	mousePos.setY(y);
}
