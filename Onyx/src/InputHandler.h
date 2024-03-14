#pragma once

#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Core.h"
#include "Window.h"

namespace Onyx
{

	/*
	 * @brief A class to handle input from a window.
	 * This class can be used to access the state of keys and mouse buttons, as well as the mouse position.
	 * It can also lock/unlock the cursor.
	 */
	class InputHandler
	{
		friend class Window;

	public:
		/*
		 * @brief Creates an empty InputHandler object.
		 * The handler should be assigned to a window through Window::setInputHandler().
		 */
		InputHandler();

		/*
		 * @brief Updates all active key and button cooldowns.
		 * Should be called each frame before input is polled if cooldowns are used.
		 * @param deltaTime The time since the last frame, in seconds.
		 */
		void updateCooldowns(double deltaTime);

		/*
		 * @brief Gets the keystate of the specified key.
		 * Either ONYX_KEYSTATE_UP, DOWN, or REPEAT.
		 * @param key The key to check. Use the definitions prefixed with ONYX_KEY.
		 */
		int getKeystate(int key);

		/*
		 * @brief Gets whether the specified key was pressed but is not repeating.
		 * @param key The key to check. Use the definitions prefixed with ONYX_KEY.
		 * @return Whether the specified key was pressed but is not repeating.
		 */
		bool isKeyPressed(int key);

		/*
		 * @brief Gets whether the specified key has been pressed long enough to be repeating.
		 * @param key The key to check. Use the definitions prefixed with ONYX_KEY.
		 * @return Whether the specified key has been pressed long enough to be repeating.
		 */
		bool isKeyRepeated(int key);

		/*
		 * @brief Gets whether the specified key is currently pressed down.
		 * @param key The key to check. Use the definitions prefixed with ONYX_KEY.
		 * @return Whether the specified key is pressed down.
		 */
		bool isKeyDown(int key);

		/*
		 * @brief Gets the keystate of the specified mouse button.
		 * Either ONYX_KEYSTATE_UP, DOWN, or REPEAT.
		 * @param button The mouse button to check. Use the definitions prefixed with ONYX_MOUSE_BUTTON.
		 */
		int getMouseButtonState(int button);

		/*
		 * @brief Gets whether the specified mouse button was pressed but is not repeating.
		 * @param button The mouse button to check. Use the definitions prefixed with ONYX_KEY.
		 * @return Whether the specified mouse button was pressed but is not repeating.
		 */
		bool isMouseButtonPressed(int button);

		/*
		 * @brief Gets whether the specified mouse button has been pressed long enough to be repeating.
		 * @param button The mouse button to check. Use the definitions prefixed with ONYX_KEY.
		 * @return Whether the specified mouse button has been pressed long enough to be repeating.
		 */
		bool isMouseButtonRepeated(int button);

		/*
		 * @brief Gets whether the specified mouse button is currently pressed down.
		 * @param button The mouse button to check. Use the definitions prefixed with ONYX_KEY.
		 * @return Whether the specified mouse button is pressed down.
		 */
		bool isMouseButtonDown(int button);

		/*
		 * @brief Sets a cooldown for the specified key.
		 * Cooldowns make it so once a key has been pressed,
		 * it is only detected as pressed once,
		 * and not again until the cooldown is over.
		 * @param key The key to apply the cooldown to.
		 * @param cooldown The cooldown time, in seconds.
		 */
		void setKeyCooldown(int key, float cooldown);

		/*
		 * @brief Sets a cooldown for the specified mouse button.
		 * Cooldowns make it so once a mouse button has been pressed,
		 * it is only detected as pressed once,
		 * and not again until the cooldown is over.
		 * @param button The mouse button to apply the cooldown to.
		 * @param cooldown The cooldown time, in seconds.
		 */
		void setMouseButtonCooldown(int button, float cooldown);

		/*
		 * @brief Hides the cursor and locks its movement.
		 */
		void lockCursor();

		/*
		 * @brief Shows the cursor and unlocks its movement.
		 */
		void unlockCursor();

		/*
		 * @brief Toggles the cursor lock.
		 */
		void toggleCursorLock();

		/*
		 * @brief Gets the horizontal position of the mouse cursor.
		 * @return The X screen coordinate of the mouse cursor.
		 */
		double getMouseX();

		/*
		 * @brief Gets the vertical position of the mouse cursor.
		 * @return The Y screen coordinate of the mouse cursor.
		 */
		double getMouseY();

	private:
		GLFWwindow* p_window;

		int keys[ONYX_MAX_KEY];
		float keyCooldowns[ONYX_MAX_KEY];
		float setKeyCooldowns[ONYX_MAX_KEY];

		int buttons[ONYX_MAX_MOUSE_BUTTON];
		float buttonCooldowns[ONYX_MAX_MOUSE_BUTTON];
		float setButtonCooldowns[ONYX_MAX_MOUSE_BUTTON];

		std::vector<int> activeKeyCooldowns;
		std::vector<int> activeButtonCooldowns;

		double mouseX, mouseY;

		bool cursorLock;

		void RCB_key(int key, int scancode, int action, int mods);
		void RCB_mouseButton(int button, int action, int mods);
		void RCB_cursorPos(double x, double y);
	};
}
