#pragma once

#include <unordered_map>
#include <unordered_set>

#include "Core.h"
#include "Gamepad.h"
#include "Math.h"

namespace Onyx
{
	class Window;

	/*
		@brief A class to handle input from a window.
	 */
	class InputHandler
	{
		friend class Window;

		/*
			@brief The key callback function signature.
			@param key The GLFW key.
			TODO: scancode param
			@param action The GLFW action.
			TODO: mods param
		*/
		typedef void(*KeyCallbackFn)(int key, int scancode, int action, int mods);

		/*
			@brief The mouse button callback function signature.
			@param key The GLFW button.
			@param action The GLFW action.
			TODO: mods param
		*/
		typedef void(*MouseButtonCallbackFn)(int button, int action, int mods);

		/*
			@brief The mouse position callback function signature.
			@param x The X position of the mouse as a window coordinate.
			@param y The Y position of the mouse as a window coordinate.
		*/
		typedef void(*MousePosCallbackFn)(double x, double y);

		/*
			@brief The scroll callback function signature.
			@param dx The change in scroll on the X axis.
			@param dy The change in scroll on the Y axis (the only axis for mice).
		*/
		typedef void(*ScrollCallbackFn)(double dx, double dy);

		/*
			@brief The key callback function signature.
			@param jid The GLFW joystick ID.
			@param event The GLFW event.
		*/
		typedef void(*JoystickCallbackFn)(int jid, int event);

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
			@brief Gets the key associated with the specified character.
			@param c The character to get the key of.
			@return The key associated with the specified character.
		 */
		static Onyx::Key CharToKey(char c);

		/*
			@brief Gets the character associated with the specified key.
			@param key The key to get the character of.
			@return The character associated with the specified key.
		 */
		static char KeyToChar(Onyx::Key key);

		/*
			@brief Gets the key associated with the specified string.
			@param str The string to get the key of.
			@return The key associated with the specified string.
		 */
		static Onyx::Key StrToKey(const char* str);

		/*
			@brief Gets the string associated with the specified key.
			@param key The key to get the string of.
			@return The string associated with the specified key.
		 */
		static const char* KeyToStr(Onyx::Key key);

		/*
			@brief Gets the mouse button associated with the specified string.
			@param str The string to get the mouse button of.
			@return The mouse button associated with the specified string.
		 */
		static Onyx::MouseButton StrToMouseButton(const char* str);

		/*
			@brief Gets the string associated with the specified mouse button.
			@param button The mouse button to get the string of.
			@return The string associated with the specified mouse button.
		 */
		static const char* MouseButtonToStr(Onyx::MouseButton button);

		/*
			@brief Gets the set of keys that are tapped.
		 *	Please note that the set is in no particular order!
			Ignores key cooldowns.
			@return The set of keys that are tapped.
		 */
		const std::unordered_set<Onyx::Key>& getKeysTapped() const;

		/*
			@brief Gets the set of keys that are down.
		 *	Please note that the set is in no particular order!
			Ignores key cooldowns.
			@return The set of keys that are down.
		 */
		const std::unordered_set<Onyx::Key>& getKeysDown() const;

		/*
			@brief Gets the set of mouse buttons that are tapped.
		 *	Please note that the set is in no particular order!
			Ignores mouse button cooldowns.
			@return The set of mouse buttons that are tapped.
		 */
		const std::unordered_set<Onyx::MouseButton>& getMouseButtonsTapped() const;

		/*
			@brief Gets the set of mouse buttons that are down.
		 *	Please note that the set is in no particular order!
			Ignores mouse button cooldowns.
			@return The set of mouse buttons that are down.
		 */
		const std::unordered_set<Onyx::MouseButton>& getMouseButtonsDown() const;

		/*
			@brief Gets the repeated key.
			Will return `Onyx::Key::Null` if no key is being repeated.
			@return The repeated key.
		 */
		Onyx::Key getRepeatedKey() const;

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
			This function will return true only if it was pressed in the same frame this function was called in.
			@param key The key to check.
			@return Whether the specified key was tapped.
		 */
		bool isKeyTapped(Onyx::Key key) const;

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
			@brief Gets whether the specified key is currently tapped or repeated.
			See `isKeyTapped` and `isKeyRepeating` for more info.
			@param key The key to check.
			@return Whether the specified key is tapped or repeated.
		 */
		bool isKeyTappedOrRepeated(Onyx::Key key);

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
			This function will return true only if it was pressed in the same frame this function was called in.
			@param button The mouse button to check.
			@return Whether the specified mouse button was tapped.
		 */
		bool isMouseButtonTapped(Onyx::MouseButton button) const;

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
			@brief Sets the key callback function.
			@param callback The callback function.
			See definition of `KeyCallbackFn` for parameter info.
		 */
		void setKeyCallback(KeyCallbackFn callback);

		/*
			@brief Sets the mouse button callback function.
			@param callback The callback function.
			See definition of `MouseButtonCallbackFn` for parameter info.
		 */
		void setMouseButtonCallback(MouseButtonCallbackFn callback);

		/*
			@brief Sets the mouse position callback function.
			@param callback The callback function.
			See definition of `MousePosCallbackFn` for parameter info.
		 */
		void setMousePosCallback(MousePosCallbackFn callback);

		/*
			@brief Sets the scroll callback function.
			@param callback The callback function.
			See definition of `ScrollCallbackFn` for parameter info.
		 */
		void setScrollCallback(ScrollCallbackFn callback);

		/*
			@brief Sets the joystick callback function.
			@param callback The callback function.
			See definition of `JoystickCallbackFn` for parameter info.
		 */
		void setJoystickCallback(JoystickCallbackFn callback);

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

		/*
			@brief Checks whether caps lock is on.
			This function uses platform-specific APIs, not Onyx key presses.
			@return Whether caps lock is on.
		 */
		static bool IsCapsLockOn();

		/*
			@brief Checks whether num lock is on.
			This function uses platform-specific APIs, not Onyx key presses.
			@return Whether num lock is on.
		 */
		static bool IsNumLockOn();

		/*
			@brief Checks whether scroll lock is on.
			This function uses platform-specific APIs, not Onyx key presses.
			@return Whether scroll lock is on.
		 */
		static bool IsScrollLockOn();

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

		const static std::unordered_map<char, Onyx::Key> s_charToKeyMap;
		const static std::unordered_map<Onyx::Key, char> s_keyToCharMap;

		const static std::unordered_map<const char*, Onyx::Key> s_strToKeyMap;
		const static std::unordered_map<Onyx::Key, const char*> s_keyToStrMap;

		const static std::unordered_map<const char*, Onyx::MouseButton> s_strToButtonMap;
		const static std::unordered_map<Onyx::MouseButton, const char*> s_buttonToStrMap;

		std::unordered_set<Onyx::Key> m_keysTappedSet;
		std::unordered_set<Onyx::Key> m_keysDownSet;

		std::unordered_set<Onyx::MouseButton> m_buttonsTappedSet;
		std::unordered_set<Onyx::MouseButton> m_buttonsDownSet;

		Onyx::Key m_repeatedKey;

		Onyx::Math::DVec2 m_mousePos;
		Onyx::Math::DVec2 m_lastMousePos;
		Onyx::Math::DVec2 m_mouseDeltas;
		Onyx::Math::DVec2 m_scrollDeltas;
		bool m_scrollThisFrame;

		std::vector<Onyx::Gamepad> m_gamepads;

		bool m_cursorLock;

		KeyCallbackFn m_pKeyCallback;
		MouseButtonCallbackFn m_pMouseButtonCallback;
		MousePosCallbackFn m_pMousePosCallback;
		ScrollCallbackFn m_pScrollCallback;
		JoystickCallbackFn m_pJoystickCallback;

		void keyCallback(int key, int scancode, int action, int mods);
		void mouseButtonCallback(int button, int action, int mods);
		void mousePosCallback(double x, double y);
		void scrollCallback(double dx, double dy);
		void joystickCallback(int jid, int event);
	};
}
