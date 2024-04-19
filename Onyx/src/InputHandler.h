#pragma once

#include "Window.h"
#include "Core.h"

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
		Onyx::KeyState getKeyState(Onyx::Key key) const;

		/*
			@brief Gets whether the specified key was pressed but is not repeating.
			@param key The key to check. Use the definitions prefixed with ONYX_KEY.
			@return Whether the specified key was pressed but is not repeating.
		 */
		bool isKeyPressed(Onyx::Key key);

		/*
			@brief Gets whether the specified key has been pressed long enough to be repeating.
			@param key The key to check. Use the definitions prefixed with ONYX_KEY.
			@return Whether the specified key has been pressed long enough to be repeating.
		 */
		bool isKeyRepeated(Onyx::Key key);

		/*
			@brief Gets whether the specified key is currently pressed down.
			@param key The key to check. Use the definitions prefixed with ONYX_KEY.
			@return Whether the specified key is pressed down.
		 */
		bool isKeyDown(Onyx::Key key);

		/*
			@brief Gets the keystate of the specified mouse button.
			Either ONYX_KEYSTATE_UP, DOWN, or REPEAT.
			@param button The mouse button to check. Use the definitions prefixed with ONYX_MOUSE_BUTTON.
		 */
		Onyx::KeyState getMouseButtonState(Onyx::MouseButton button) const;

		/*
			@brief Gets whether the specified mouse button was pressed but is not repeating.
			@param button The mouse button to check. Use the definitions prefixed with ONYX_KEY.
			@return Whether the specified mouse button was pressed but is not repeating.
		 */
		bool isMouseButtonPressed(Onyx::MouseButton button);

		/*
			@brief Gets whether the specified mouse button has been pressed long enough to be repeating.
			@param button The mouse button to check. Use the definitions prefixed with ONYX_KEY.
			@return Whether the specified mouse button has been pressed long enough to be repeating.
		 */
		bool isMouseButtonRepeated(Onyx::MouseButton button);

		/*
			@brief Gets whether the specified mouse button is currently pressed down.
			@param button The mouse button to check. Use the definitions prefixed with ONYX_KEY.
			@return Whether the specified mouse button is pressed down.
		 */
		bool isMouseButtonDown(Onyx::MouseButton button);

		/*
			@brief Sets a cooldown for the specified key.
			Cooldowns make it so once a key has been pressed,
			it is only detected as pressed once,
			and not again until the cooldown is over.
			@param key The key to apply the cooldown to.
			@param cooldown The cooldown time, in seconds.
		 */
		void setKeyCooldown(Onyx::Key key, float cooldown);

		/*
			@brief Sets a cooldown for the specified mouse button.
			Cooldowns make it so once a mouse button has been pressed,
			it is only detected as pressed once,
			and not again until the cooldown is over.
			@param button The mouse button to apply the cooldown to.
			@param cooldown The cooldown time, in seconds.
		 */
		void setMouseButtonCooldown(Onyx::MouseButton button, float cooldown);

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
		Onyx::Math::DVec2& getMousePos() const;

		/*
			@brief Gets the change in position of the mouse since the last update.
			@return The change in position of the mouse since the last frame.
		 */
		Onyx::Math::DVec2& getMouseDeltas() const;

	private:
		Window* p_win;

		Onyx::KeyState keys[Onyx::Key::MaxKey];
		float keyCooldowns[Onyx::Key::MaxKey];
		float setKeyCooldowns[Onyx::Key::MaxKey];

		Onyx::KeyState buttons[Onyx::MouseButton::MaxButton];
		float buttonCooldowns[Onyx::MouseButton::MaxButton];
		float setButtonCooldowns[Onyx::MouseButton::MaxButton];

		std::vector<Onyx::Key> activeKeyCooldowns;
		std::vector<Onyx::MouseButton> activeButtonCooldowns;

		Onyx::Math::DVec2 mousePos;
		Onyx::Math::DVec2 lastMousePos;
		Onyx::Math::DVec2 mouseDeltas;

		bool cursorLock;

		void rcb_key(int key, int scancode, int action, int mods);
		void rcb_mouseButton(int button, int action, int mods);
		void rcb_cursorPos(double x, double y);
	};
}
