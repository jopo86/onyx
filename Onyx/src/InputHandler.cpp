#pragma warning(disable : 4244; disable: 33011)

#include "InputHandler.h"

using Onyx::Math::DVec2;

void onyx_err(const Onyx::Error&);

Onyx::InputHandler::InputHandler()
{
	m_pWin = nullptr;

	for (int i = 0; i < (int)Onyx::Key::MaxKey; i++)
	{
		m_keys[i] = Onyx::KeyState::Untouched;
		m_keyCooldowns[i] = 0.0f;
		m_setKeyCooldowns[i] = 0.0f;
	}

	for (int i = 0; i < (int)Onyx::MouseButton::MaxButton; i++)
	{
		m_buttons[i] = Onyx::KeyState::Untouched;
		m_buttonCooldowns[i] = 0.0f;
		m_setButtonCooldowns[i] = 0.0f;
	}

	m_mousePos = DVec2(0.0f);
	m_lastMousePos = DVec2(0.0f);
	m_mouseDeltas = DVec2(0.0f);

	m_cursorLock = false;
	m_scrollThisFrame = false;

	for (int jid = GLFW_JOYSTICK_1; jid <= GLFW_JOYSTICK_16; jid++)
	{
		if (glfwJoystickIsGamepad(jid)) m_gamepads.push_back(Onyx::Gamepad(jid));
	}
}

void Onyx::InputHandler::update()
{
	if (m_pWin == nullptr)
	{
		onyx_err(Error{
			.sourceFunction = "Onyx::InputHandler::update()",
			.message = "Window pointer is null.",
			.howToFix = "Make sure the input handler was linked to a window (Window::linkInputHandler())."
			}
		);
		return;
	}

	m_scrollThisFrame = false;
	glfwPollEvents();

	m_mouseDeltas.set(m_mousePos.getX() - m_lastMousePos.getX(), m_mousePos.getY() - m_lastMousePos.getY());
	m_lastMousePos = m_mousePos;
	if (!m_scrollThisFrame) m_scrollDeltas.set(0.0, 0.0);

	for (Onyx::Key key : m_activeKeyCooldowns)
	{
		if (m_keyCooldowns[(int)key] >= 0) m_keyCooldowns[(int)key] -= m_pWin->m_deltaTime;
	}

	for (Onyx::MouseButton button : m_activeButtonCooldowns)
	{
		if (m_buttonCooldowns[(int)button] >= 0) m_buttonCooldowns[(int)button] -= m_pWin->m_deltaTime;
	}

	for (Onyx::Gamepad& gp : m_gamepads)
	{
		if (gp.isConnected()) gp.update();
	}
}

Onyx::KeyState Onyx::InputHandler::getKeyState(Onyx::Key key) const
{
	return m_keys[(int)key];
}

bool Onyx::InputHandler::isKeyPressed(Onyx::Key _key)
{
	int key = (int)_key;
	if (key < 0) return false;
	bool retval = m_keyCooldowns[key] <= 0 ? m_keys[key] == Onyx::KeyState::Press : false;
	if (retval) m_keyCooldowns[key] = m_setKeyCooldowns[key];
	return retval;
}

bool Onyx::InputHandler::isKeyRepeated(Onyx::Key _key)
{
	int key = (int)_key;
	if (key < 0) return false;
	bool retval = m_keyCooldowns[key] <= 0 ? m_keys[key] == Onyx::KeyState::Repeat : false;
	if (retval) m_keyCooldowns[key] = m_setKeyCooldowns[key];
	return retval;
}

bool Onyx::InputHandler::isKeyDown(Onyx::Key _key)
{
	int key = (int)_key;
	if (key < 0) return false;
	bool retval = m_keyCooldowns[key] <= 0 ? m_keys[key] == Onyx::KeyState::Press || m_keys[key] == Onyx::KeyState::Repeat : false;
	if (retval) m_keyCooldowns[key] = m_setKeyCooldowns[key];
	return retval;
}

Onyx::KeyState Onyx::InputHandler::getMouseButtonState(Onyx::MouseButton _button) const
{
	int button = (int)_button;
	return m_buttons[button];
}

bool Onyx::InputHandler::isMouseButtonPressed(Onyx::MouseButton _button)
{
	int button = (int)_button;
	if (button < 0) return false;
	bool retval = m_buttonCooldowns[button] <= 0 ? m_buttons[button] == Onyx::KeyState::Press : false;
	if (retval) m_buttonCooldowns[button] = m_setButtonCooldowns[button];
	return retval;
}

bool Onyx::InputHandler::isMouseButtonRepeated(Onyx::MouseButton _button)
{
	int button = (int)_button;
	if (button < 0) return false;
	bool retval = m_buttonCooldowns[button] <= 0 ? m_buttons[button] == Onyx::KeyState::Repeat : false;
	if (retval) m_buttonCooldowns[button] = m_setButtonCooldowns[button];
	return retval;
}

bool Onyx::InputHandler::isMouseButtonDown(Onyx::MouseButton _button)
{
	int button = (int)_button;
	if (button < 0) return false;
	bool retval = m_buttonCooldowns[button] <= 0 ? m_buttons[button] == Onyx::KeyState::Press || m_buttons[button] == Onyx::KeyState::Repeat : false;
	if (retval) m_buttonCooldowns[button] = m_setButtonCooldowns[button];
	return retval;
}

void Onyx::InputHandler::setKeyCooldown(Onyx::Key key, float cooldown)
{
	m_activeKeyCooldowns.push_back(key);
	m_setKeyCooldowns[(int)key] = cooldown;
}

void Onyx::InputHandler::setMouseButtonCooldown(Onyx::MouseButton button, float cooldown)
{
	m_activeButtonCooldowns.push_back(button);
	m_setButtonCooldowns[(int)button] = cooldown;
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

bool Onyx::InputHandler::isCursorLocked() const
{
	return m_cursorLock;
}

void Onyx::InputHandler::refreshGamepads()
{
	for (int jid = GLFW_JOYSTICK_1; jid <= GLFW_JOYSTICK_16; jid++)
	{
		if (glfwJoystickIsGamepad(jid))
		{
			bool found = false;
			for (Onyx::Gamepad& gamepad : m_gamepads)
			{
				if (gamepad.getGlfwID() == jid)
				{
					found = true;
					break;
				}
			}

			if (!found) m_gamepads.push_back(Onyx::Gamepad(jid));
		}
	}
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

const std::vector<Onyx::Gamepad>& Onyx::InputHandler::getGamepads() const
{
	return m_gamepads;
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
	m_scrollThisFrame = true;
}
