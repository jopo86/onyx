#pragma once

#include "Window.h"
#include "Core.h"
#include "Gamepad.h"

namespace Onyx
{

	/*
		@brief A class to handle input from a window.
	 */
	class InputHandler
	{
		friend class Window;

	public:
		/*
			@brief Creates an InputHandler.
		 !  MUST BE LINKED TO A WINDOW TO USE MOST FUNCTIONS
		 !  Use `Window::linkInputHandler()`
		 */
		InputHandler();

		/*
			@brief Updates the input handler.
			Should be called each frame, before input is polled.
			This function polls events and updates gamepad states, mouse deltas, and cooldowns.
			Cooldowns are updated using the delta time of the window this input handler was linked to.
		 */
		void update();

		/*
			@brief Gets the keystate of the specified key.
			Ignores key cooldowns.
			@param key The key to check.
			@return The keystate of the specified key.
		 */
		Onyx::KeyState getKeyState(Onyx::Key key) const;

		/*
			@brief Gets whether the specified key was pressed but is not repeating.
			@param key The key to check.
			@return Whether the specified key was pressed but is not repeating.
		 */
		bool isKeyPressed(Onyx::Key key);

		/*
			@brief Gets whether the specified key was tapped.
			Ignores key cooldowns.
			This function will return true only once per key press.
			@param key The key to check.
			@return Whether the specified key was tapped.
		 */
		bool isKeyTapped(Onyx::Key key);

		/*
			@brief Gets whether the specified key has been pressed long enough to be repeating.
			@param key The key to check.
			@return Whether the specified key has been pressed long enough to be repeating.
		 */
		bool isKeyRepeated(Onyx::Key key);

		/*
			@brief Gets whether the specified key is currently pressed down.
			@param key The key to check.
			@return Whether the specified key is pressed down.
		 */
		bool isKeyDown(Onyx::Key key);

		/*
			@brief Gets the keystate of the specified mouse button.
			Ignores mouse button cooldowns.
			@param button The mouse button to check.
			@return The keystate of the specified mouse button.
		 */
		Onyx::KeyState getMouseButtonState(Onyx::MouseButton button) const;

		/*
			@brief Gets whether the specified mouse button was pressed but is not repeating.
			@param button The mouse button to check.
			@return Whether the specified mouse button was pressed but is not repeating.
		 */
		bool isMouseButtonPressed(Onyx::MouseButton button);

		/*
			@brief Gets whether the specified mouse button was tapped.
			Ignores mouse button cooldowns.
			This function will return true only once per mouse button press.
			@param button The mouse button to check.
			@return Whether the specified mouse button was tapped.
		 */
		bool isMouseButtonTapped(Onyx::MouseButton button);

		/*
			@brief Gets whether the specified mouse button has been pressed long enough to be repeating.
			@param button The mouse button to check.
			@return Whether the specified mouse button has been pressed long enough to be repeating.
		 */
		bool isMouseButtonRepeated(Onyx::MouseButton button);

		/*
			@brief Gets whether the specified mouse button is currently pressed down.
			@param button The mouse button to check.
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
			@brief Gets whether the cursor is locked.
			@return Whether the cursor is locked.
		 */
		bool isCursorLocked() const;

		/*
			@deprecated There is no longer a need for this function, as newly connected gamepads are automatically added to the list.
		 */
		[[deprecated("This function is deprecated and will be removed in the next major release. There is no longer a need for this function, as newly connected gamepads are automatically added to the list.")]]
		void refreshGamepads();

		/*
			@brief Gets the position of the mouse.
			This is independent of whether update() is called each frame.
			@return The position of the mouse.
		 */
		const Onyx::Math::DVec2& getMousePos() const;

		/*
			@brief Gets the change in position of the mouse since the last update.
			@return The change in position of the mouse since the last frame.
		 */
		const Onyx::Math::DVec2& getMouseDeltas() const;

		/*
			@brief Gets the change in scroll of the mouse since the last update.
			@return The change in scroll of the mouse since the last frame.
		 */
		const Onyx::Math::DVec2& getScrollDeltas() const;

		/*
			@brief Gets all gamepads connected to the system.
			@return A vector of all gamepads connected to the system.
		 */
		const std::vector<Onyx::Gamepad>& getGamepads() const;

	private:
		Window* m_pWin;

		Onyx::KeyState m_keys[(int)Onyx::Key::MaxKey];
		bool m_keysTapped[(int)Onyx::Key::MaxKey];
		float m_keyCooldowns[(int)Onyx::Key::MaxKey];
		float m_setKeyCooldowns[(int)Onyx::Key::MaxKey];

		Onyx::KeyState m_buttons[(int)Onyx::MouseButton::MaxButton];
		bool m_buttonsTapped[(int)Onyx::MouseButton::MaxButton];
		float m_buttonCooldowns[(int)Onyx::MouseButton::MaxButton];
		float m_setButtonCooldowns[(int)Onyx::MouseButton::MaxButton];

		std::vector<Onyx::Key> m_activeKeyCooldowns;
		std::vector<Onyx::MouseButton> m_activeButtonCooldowns;

		Onyx::Math::DVec2 m_mousePos;
		Onyx::Math::DVec2 m_lastMousePos;
		Onyx::Math::DVec2 m_mouseDeltas;
		Onyx::Math::DVec2 m_scrollDeltas;
		bool m_scrollThisFrame;

		std::vector<Onyx::Gamepad> m_gamepads;

		bool m_cursorLock;

		void keyCallback(int key, int scancode, int action, int mods);
		void mouseButtonCallback(int button, int action, int mods);
		void cursorPosCallback(double x, double y);
		void scrollCallback(double dx, double dy);
		void joystickCallback(int jid, int event);
	};
}
