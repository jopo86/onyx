#pragma once

#include "Core.h"

#include <iostream>
#include <vector>

#include <GLFW/glfw3.h>

namespace Onyx
{
	/*
		@brief A class to represent a gamepad/controller.
	 */
	class Gamepad
	{
		friend class InputHandler;

	public:
		/*
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
			Gamepads are not meant to be created by the user, they are created and managed by the InputHandler.
		 */
		Gamepad();

		/*
			@brief Updates the gamepad input state.
		 */
		void update();

		/*
			@brief Gets the name of the gamepad.
			@return The human-readable name of the gamepad. Not guaranteed (or likely) to be unique.
		 */
		const std::string& getName() const;

		/*
			@brief Gets the GLFW joystick ID of the gamepad.
			@return The GLFW joystick ID.
		 */
		int getGlfwID() const;

		/*
			@deprecated Use isButtonDown instead.
		 */
		[[deprecated("This function is deprecated and will be removed in the next major release. Use isButtonDown instead.")]]
		bool isButtonPressed(GamepadButton button) const;

		/*
			@brief Checks if a button on the gamepad is down.
			@param button The button to check.
			@return True if the button is down, false otherwise.
		 */
		bool isButtonDown(GamepadButton button) const;

		/*
			@brief Checks if a button on the gamepad is tapped.
			This function will return true only once per button press.
			@param button The button to check.
			@return True if the button is tapped, false otherwise.
		 */
		bool isButtonTapped(GamepadButton button);

		/*
			@brief Gets the value of an axis on the gamepad.
			@param axis The axis to get the value of.
			@return The value of the axis, between -1 and 1.
		 */
		float getAxis(GamepadAxis axis) const;

		/*
			@brief Gets whether the gamepad is connected.
			@return Whether the gamepad is connected.
		 */
		bool isConnected() const;

	private:
		int m_joystickID;
		std::string m_name;
		GLFWgamepadstate m_state;
		bool m_buttonsTapped[(int)Onyx::GamepadButton::MaxButton];

		Gamepad(int joystickID, bool* result = nullptr);
	};
}
