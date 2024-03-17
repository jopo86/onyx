#pragma once

#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Core.h"
#include "Window.h"
#include "Math.h"

namespace Onyx
{

	/*
		@brief A class to handle input from a window.
		This class can be used to access the state of keys and mouse buttons, as well as the mouse position.
		It can also lock/unlock the cursor.
	 */
	class InputHandler
	{
		friend class Window;

	public:
		/*
			@brief Creates an empty InputHandler object.
			Trying to use an input handler constructed like this will result in undefined behavior.
		 */
		InputHandler();

		/*
			@brief Creates a new InputHandler object for the specified window.
			@param window The window to handle input for.
		 */
		InputHandler(Window& window);

		/*
			@brief Updates mouse deltas and active key cooldowns.
			Should be called each frame.
		 */
		void update();

		/*
			@brief Gets the keystate of the specified key.
			Either ONYX_KEYSTATE_UP, DOWN, or REPEAT.
			@param key The key to check. Use the definitions prefixed with ONYX_KEY.
		 */
		int getKeystate(int key);

		/*
			@brief Gets whether the specified key was pressed but is not repeating.
			@param key The key to check. Use the definitions prefixed with ONYX_KEY.
			@return Whether the specified key was pressed but is not repeating.
		 */
		bool isKeyPressed(int key);

		/*
			@brief Gets whether the specified key has been pressed long enough to be repeating.
			@param key The key to check. Use the definitions prefixed with ONYX_KEY.
			@return Whether the specified key has been pressed long enough to be repeating.
		 */
		bool isKeyRepeated(int key);

		/*
			@brief Gets whether the specified key is currently pressed down.
			@param key The key to check. Use the definitions prefixed with ONYX_KEY.
			@return Whether the specified key is pressed down.
		 */
		bool isKeyDown(int key);

		/*
			@brief Gets the keystate of the specified mouse button.
			Either ONYX_KEYSTATE_UP, DOWN, or REPEAT.
			@param button The mouse button to check. Use the definitions prefixed with ONYX_MOUSE_BUTTON.
		 */
		int getMouseButtonState(int button);

		/*
			@brief Gets whether the specified mouse button was pressed but is not repeating.
			@param button The mouse button to check. Use the definitions prefixed with ONYX_KEY.
			@return Whether the specified mouse button was pressed but is not repeating.
		 */
		bool isMouseButtonPressed(int button);

		/*
			@brief Gets whether the specified mouse button has been pressed long enough to be repeating.
			@param button The mouse button to check. Use the definitions prefixed with ONYX_KEY.
			@return Whether the specified mouse button has been pressed long enough to be repeating.
		 */
		bool isMouseButtonRepeated(int button);

		/*
			@brief Gets whether the specified mouse button is currently pressed down.
			@param button The mouse button to check. Use the definitions prefixed with ONYX_KEY.
			@return Whether the specified mouse button is pressed down.
		 */
		bool isMouseButtonDown(int button);

		/*
			@brief Sets a cooldown for the specified key.
			Cooldowns make it so once a key has been pressed,
			it is only detected as pressed once,
			and not again until the cooldown is over.
			@param key The key to apply the cooldown to.
			@param cooldown The cooldown time, in seconds.
		 */
		void setKeyCooldown(int key, float cooldown);

		/*
			@brief Sets a cooldown for the specified mouse button.
			Cooldowns make it so once a mouse button has been pressed,
			it is only detected as pressed once,
			and not again until the cooldown is over.
			@param button The mouse button to apply the cooldown to.
			@param cooldown The cooldown time, in seconds.
		 */
		void setMouseButtonCooldown(int button, float cooldown);

		/*
			@brief Sets whether the cursor is locked.
			Cursor lock makes the cursor invisible and locks its movement, while still allowing camera movement.
			@param lock Whether the cursor should be locked.
		 */
		void setCursorLock(bool lock);

		/*
			@brief Toggles the cursor lock.
		 */
		void toggleCursorLock();

		/*
			@brief Gets the position of the mouse.
			This is independent of whether update() is called each frame.
			@return The position of the mouse.
		 */
		Onyx::Math::DVec2& getMousePos();

		/*
			@brief Gets the change in position of the mouse since the last update.
			@return The change in position of the mouse since the last frame.
		 */
		Onyx::Math::DVec2& getMouseDeltas();

	private:
		Window* p_win;

		int keys[ONYX_MAX_KEY];
		float keyCooldowns[ONYX_MAX_KEY];
		float setKeyCooldowns[ONYX_MAX_KEY];

		int buttons[ONYX_MAX_MOUSE_BUTTON];
		float buttonCooldowns[ONYX_MAX_MOUSE_BUTTON];
		float setButtonCooldowns[ONYX_MAX_MOUSE_BUTTON];

		std::vector<int> activeKeyCooldowns;
		std::vector<int> activeButtonCooldowns;

		Onyx::Math::DVec2 mousePos;
		Onyx::Math::DVec2 lastMousePos;
		Onyx::Math::DVec2 mouseDeltas;

		bool cursorLock;

		void RCB_key(int key, int scancode, int action, int mods);
		void RCB_mouseButton(int button, int action, int mods);
		void RCB_cursorPos(double x, double y);
	};
}
