#include <onyx/gamepad.hpp>

#include <string>

void onyx_err(const onyx::Error&);
void onyx_warn(const onyx::Warning&);

onyx::Gamepad::Gamepad()
{
	this->joystick_id = 0;
	this->state = GLFWgamepadstate{
		.buttons = { 0 },
		.axes = { 0 }
	};
	for (int i = 0; i < (int)onyx::GamepadButton::MaxButton; i++)
	{
		this->buttons_tapped[i] = false;
	}
}

onyx::Gamepad::Gamepad(int joystick_id, bool* result)
{
	if (!glfwJoystickIsGamepad(joystick_id))
	{
		onyx_err(Error{
				.source_function = "onyx::Gamepad::Gamepad(int joystick_id)",
				.message = "The joystick at the specified ID is not a gamepad.",
				.how_to_fix = "Make sure the joystick is a gamepad before creating a Gamepad object from it."
			}
		);
		this->joystick_id = 0;
		if (result != nullptr) *result = false;
	}

	this->joystick_id = joystick_id;
	this->state = GLFWgamepadstate{
		.buttons = { 0 },
		.axes = { 0 }
	};

	if (is_connected())
	{
		this->name = glfwGetJoystickName(joystick_id);
		glfwSetJoystickUserPointer(joystick_id, this);
		update();
	}
}

void onyx::Gamepad::update()
{
	if (is_connected())
	{
		bool prev_buttons[(int)onyx::GamepadButton::MaxButton];
		for (int i = 0; i < (int)onyx::GamepadButton::MaxButton; i++)
		{
			prev_buttons[i] = this->state.buttons[i] == GLFW_PRESS;
		}
		glfwGetGamepadState(this->joystick_id, &this->state);
		this->state.axes[GLFW_GAMEPAD_AXIS_LEFT_Y] = -this->state.axes[GLFW_GAMEPAD_AXIS_LEFT_Y];
		this->state.axes[GLFW_GAMEPAD_AXIS_RIGHT_Y] = -this->state.axes[GLFW_GAMEPAD_AXIS_RIGHT_Y];

		for (int i = 0; i < (int)onyx::GamepadButton::MaxButton; i++)
		{
			this->buttons_tapped[i] = false;
			if (prev_buttons[i] != this->state.buttons[i] && this->state.buttons[i] == GLFW_PRESS) this->buttons_tapped[i] = true;
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

bool onyx::Gamepad::is_button_pressed(GamepadButton button) const
{
	return is_button_down(button);
}

bool onyx::Gamepad::is_button_down(GamepadButton button) const
{
	return this->state.buttons[(int)button] == GLFW_PRESS;
}

bool onyx::Gamepad::is_button_tapped(GamepadButton button) const
{
	return this->buttons_tapped[(int)button];
}

float onyx::Gamepad::get_axis(GamepadAxis axis) const
{
	return this->state.axes[(int)axis];
}

bool onyx::Gamepad::is_connected() const
{
	return glfwJoystickPresent(this->joystick_id);
}
