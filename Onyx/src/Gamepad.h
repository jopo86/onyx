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
		 */
		Gamepad();

		/*
			@brief Creates a Gamepad object from the specified GLFW joystick ID.
			@param joystickID The GLFW joystick ID.
			@param result A pointer to a boolean that will be set to true if the gamepad was created successfully, and false otherwise.
		 */
		Gamepad(int joystickID, bool* result = nullptr);

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
			@brief Checks if a button on the gamepad is pressed.
			@param button The button to check.
			@return True if the button is pressed, false otherwise.
		 */
		bool isButtonPressed(GamepadButton button) const;

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
	};
}
