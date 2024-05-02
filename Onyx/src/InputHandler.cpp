#pragma warning(disable : 4244; disable: 33011)

#include "InputHandler.h"

using Onyx::Math::DVec2;

Onyx::InputHandler::InputHandler()
{
	m_pWin = nullptr;

	for (int i = 0; i < Onyx::Key::MaxKey; i++)
	{
		m_keys[i] = Onyx::KeyState::Untouched;
		m_keyCooldowns[i] = 0.0f;
		m_setKeyCooldowns[i] = 0.0f;
	}

	for (int i = 0; i < Onyx::MouseButton::MaxButton; i++)
	{
		m_buttons[i] = Onyx::KeyState::Untouched;
		m_buttonCooldowns[i] = 0.0f;
		m_setButtonCooldowns[i] = 0.0f;
	}

	m_mousePos = DVec2(0.0f);
	m_lastMousePos = DVec2(0.0f);
	m_mouseDeltas = DVec2(0.0f);

	m_cursorLock = false;
}

void Onyx::InputHandler::update()
{
	m_mouseDeltas.setX(m_mousePos.getX() - m_lastMousePos.getX());
	m_mouseDeltas.setY(m_mousePos.getY() - m_lastMousePos.getY());

	m_lastMousePos.setX(m_mousePos.getX());
	m_lastMousePos.setY(m_mousePos.getY());

	for (int key : m_activeKeyCooldowns)
	{
		if (m_keyCooldowns[key] >= 0) m_keyCooldowns[key] -= m_pWin->m_deltaTime;
	}

	for (int button : m_activeButtonCooldowns)
	{
		if (m_buttonCooldowns[button] >= 0) m_buttonCooldowns[button] -= m_pWin->m_deltaTime;
	}
}

Onyx::KeyState Onyx::InputHandler::getKeyState(Onyx::Key key) const
{
	return m_keys[key];
}

bool Onyx::InputHandler::isKeyPressed(Onyx::Key key)
{
	if (key < 0) return false;
	bool retval = m_keyCooldowns[key] <= 0 ? m_keys[key] == Onyx::KeyState::Press : false;
	if (retval) m_keyCooldowns[key] = m_setKeyCooldowns[key];
	return retval;
}

bool Onyx::InputHandler::isKeyRepeated(Onyx::Key key)
{
	if (key < 0) return false;
	bool retval = m_keyCooldowns[key] <= 0 ? m_keys[key] == Onyx::KeyState::Repeat : false;
	if (retval) m_keyCooldowns[key] = m_setKeyCooldowns[key];
	return retval;
}

bool Onyx::InputHandler::isKeyDown(Onyx::Key key)
{
	if (key < 0) return false;
	bool retval = m_keyCooldowns[key] <= 0 ? m_keys[key] == Onyx::KeyState::Press || m_keys[key] == Onyx::KeyState::Repeat : false;
	if (retval) m_keyCooldowns[key] = m_setKeyCooldowns[key];
	return retval;
}

Onyx::KeyState Onyx::InputHandler::getMouseButtonState(Onyx::MouseButton button) const
{
	return m_buttons[button];
}

bool Onyx::InputHandler::isMouseButtonPressed(Onyx::MouseButton button)
{
	if (button < 0) return false;
	bool retval = m_buttonCooldowns[button] <= 0 ? m_buttons[button] == Onyx::KeyState::Press : false;
	if (retval) m_buttonCooldowns[button] = m_setButtonCooldowns[button];
	return retval;
}

bool Onyx::InputHandler::isMouseButtonRepeated(Onyx::MouseButton button)
{
	if (button < 0) return false;
	bool retval = m_buttonCooldowns[button] <= 0 ? m_buttons[button] == Onyx::KeyState::Repeat : false;
	if (retval) m_buttonCooldowns[button] = m_setButtonCooldowns[button];
	return retval;
}

bool Onyx::InputHandler::isMouseButtonDown(Onyx::MouseButton button)
{
	if (button < 0) return false;
	bool retval = m_buttonCooldowns[button] <= 0 ? m_buttons[button] == Onyx::KeyState::Press || m_buttons[button] == Onyx::KeyState::Repeat : false;
	if (retval) m_buttonCooldowns[button] = m_setButtonCooldowns[button];
	return retval;
}

void Onyx::InputHandler::setKeyCooldown(Onyx::Key key, float cooldown)
{
	m_activeKeyCooldowns.push_back(key);
	m_setKeyCooldowns[key] = cooldown;
}

void Onyx::InputHandler::setMouseButtonCooldown(Onyx::MouseButton button, float cooldown)
{
	m_activeButtonCooldowns.push_back(button);
	m_setButtonCooldowns[button] = cooldown;
}

void Onyx::InputHandler::setCursorLock(bool lock)
{
	m_cursorLock = lock;
	glfwSetInputMode(m_pWin->m_pGlfwWin, GLFW_CURSOR, lock ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
}

void Onyx::InputHandler::toggleCursorLock()
{
	setCursorLock(!m_cursorLock);
}

const Onyx::Math::DVec2& Onyx::InputHandler::getMousePos() const
{
	return m_mousePos;
}

const Onyx::Math::DVec2& Onyx::InputHandler::getMouseDeltas() const
{
	return m_mouseDeltas;
}

const Onyx::Math::DVec2& Onyx::InputHandler::getScrollDeltas() const
{
	return m_scrollDeltas;
}

void Onyx::InputHandler::keyCallback(int key, int scancode, int action, int mods)
{
	m_keys[key] = (Onyx::KeyState)action;
}

void Onyx::InputHandler::mouseButtonCallback(int button, int action, int mods)
{
	m_buttons[button] = (Onyx::KeyState)action;
}

void Onyx::InputHandler::cursorPosCallback(double x, double y)
{
	m_mousePos.set(x, y);
}

void Onyx::InputHandler::scrollCallback(double dx, double dy)
{
	m_scrollDeltas.set(dx, dy);
}
