#include <onyx/gamepad.hpp>

#include <string>
#include "internal.hpp"

onyx::Gamepad::Gamepad()
{
	this->joystick_id = -1;
	this->state = GLFWgamepadstate{
		.buttons = { 0 },
		.axes = { 0 }
	};
	for (bool& tapped : this->buttons_tapped) tapped = false;
}

onyx::Gamepad::Gamepad(int joystick_id, bool* result)
{
	this->joystick_id = -1;
	this->state = GLFWgamepadstate{
		.buttons = { 0 },
		.axes = { 0 }
	};
	for (bool& tapped : this->buttons_tapped) tapped = false;

	if (joystick_id < GLFW_JOYSTICK_1 || joystick_id > GLFW_JOYSTICK_LAST || !glfwJoystickIsGamepad(joystick_id))
	{
		onyx_err(Error{
				.source_function = "onyx::Gamepad::Gamepad(int joystick_id)",
				.message = "The joystick at the specified ID is not a gamepad.",
				.how_to_fix = "Make sure the joystick is a gamepad before creating a Gamepad object from it."
			}
		);
		if (result != nullptr) *result = false;
		return;
	}

	this->joystick_id = joystick_id;

	if (is_connected())
	{
		const char* p_name = glfwGetJoystickName(joystick_id);
		if (p_name != nullptr) this->name = p_name;
		update();
	}

	if (result != nullptr) *result = true;
}

void onyx::Gamepad::update()
{
	if (is_connected())
	{
		bool prev_buttons[(int)onyx::GamepadButton::MaxButton + 1];
		for (int i = 0; i <= (int)onyx::GamepadButton::MaxButton; i++)
		{
			prev_buttons[i] = this->state.buttons[i] == GLFW_PRESS;
		}
		glfwGetGamepadState(this->joystick_id, &this->state);
		this->state.axes[GLFW_GAMEPAD_AXIS_LEFT_Y] = -this->state.axes[GLFW_GAMEPAD_AXIS_LEFT_Y];
		this->state.axes[GLFW_GAMEPAD_AXIS_RIGHT_Y] = -this->state.axes[GLFW_GAMEPAD_AXIS_RIGHT_Y];

		for (int i = 0; i <= (int)onyx::GamepadButton::MaxButton; i++)
		{
			this->buttons_tapped[i] = !prev_buttons[i] && this->state.buttons[i] == GLFW_PRESS;
		}
	}
	else
	{
		onyx_warn(Warning{
				.source_function = "onyx::Gamepad::update()",
				.message = "Gamepad is no longer connected and present, cannot update (Joystick ID: GLFW_JOYSTICK_" + std::to_string(this->joystick_id + 1) + ")",
				.severity = Warning::Severity::Low
			}
		);
	}
}

const std::string& onyx::Gamepad::get_name() const
{
	return this->name;
}

int onyx::Gamepad::get_glfw_id() const
{
	return this->joystick_id;
}

bool onyx::Gamepad::is_button_down(GamepadButton button) const
{
	int i = (int)button;
	if (i < 0 || i > (int)GamepadButton::MaxButton) return false;
	return this->state.buttons[i] == GLFW_PRESS;
}

bool onyx::Gamepad::is_button_tapped(GamepadButton button) const
{
	int i = (int)button;
	if (i < 0 || i > (int)GamepadButton::MaxButton) return false;
	return this->buttons_tapped[i];
}

float onyx::Gamepad::get_axis(GamepadAxis axis) const
{
	int i = (int)axis;
	if (i < 0 || i > (int)GamepadAxis::MaxAxis) return 0.0f;
	return this->state.axes[i];
}

bool onyx::Gamepad::is_connected() const
{
	if (this->joystick_id < GLFW_JOYSTICK_1 || this->joystick_id > GLFW_JOYSTICK_LAST) return false;
	return glfwJoystickPresent(this->joystick_id);
}

void onyx::Gamepad::reset_state()
{
	this->state = GLFWgamepadstate{
		.buttons = { 0 },
		.axes = { 0 }
	};
	for (bool& tapped : this->buttons_tapped) tapped = false;
}
