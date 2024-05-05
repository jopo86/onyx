#include "Gamepad.h"

void onyx_err(const Onyx::Error&);
void onyx_warn(const Onyx::Warning&);

Onyx::Gamepad::Gamepad()
{
	m_joystickID = 0;
	m_state = GLFWgamepadstate{
		.buttons = { 0 },
		.axes = { 0 }
	};
}

Onyx::Gamepad::Gamepad(int joystickID, bool* result)
{
	if (!glfwJoystickIsGamepad(joystickID))
	{
		onyx_err(Error{
				.sourceFunction = "Onyx::Gamepad::Gamepad(int joystickID)",
				.message = "The joystick at the specified ID is not a gamepad.",
				.howToFix = "Make sure the joystick is a gamepad before creating a Gamepad object from it."
			}
		);
		m_joystickID = 0;
		if (result != nullptr) *result = false;
	}

	m_joystickID = joystickID;
	m_state = GLFWgamepadstate{
		.buttons = { 0 },
		.axes = { 0 }
	};

	if (isConnected())
	{
		m_name = glfwGetJoystickName(joystickID);
		glfwSetJoystickUserPointer(joystickID, this);
		update();
	}
}

void Onyx::Gamepad::update()
{
	if (isConnected())
	{
		glfwGetGamepadState(m_joystickID, &m_state);
		m_state.axes[GLFW_GAMEPAD_AXIS_LEFT_Y] = -m_state.axes[GLFW_GAMEPAD_AXIS_LEFT_Y];
		m_state.axes[GLFW_GAMEPAD_AXIS_RIGHT_Y] = -m_state.axes[GLFW_GAMEPAD_AXIS_RIGHT_Y];
	}
	else
	{
		onyx_warn(Warning{
				.sourceFunction = "void Onyx::Gamepad::update()",
				.message = "Gamepad is no longer connected and present, cannot update",
				.severity = Warning::Severity::Low
			}
		);
	}
}

const std::string& Onyx::Gamepad::getName() const
{
	return m_name;
}

int Onyx::Gamepad::getGlfwID() const
{
	return m_joystickID;
}

bool Onyx::Gamepad::isButtonPressed(GamepadButton button) const
{
	return m_state.buttons[(int)button] == GLFW_PRESS;
}

float Onyx::Gamepad::getAxis(GamepadAxis axis) const
{
	return m_state.axes[(int)axis];
}

bool Onyx::Gamepad::isConnected() const
{
	return glfwJoystickPresent(m_joystickID);
}
