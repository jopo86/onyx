#pragma once

#include <unordered_map>
#include <unordered_set>
#include <mutex>

#include "core.h"
#include "gamepad.h"
#include "math_wrappers.h"

namespace onyx
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
			@param The system-specific scancode of the key.
			@param action The GLFW action.
			@param mods A bitfield describing which modifier keys were held down (e.g. GLFW_MOD_SHIFT)
		*/
		typedef void(*KeyCallbackFn)(int key, int scancode, int action, int mods);

		/*
			@brief The mouse button callback function signature.
			@param key The GLFW button.
			@param action The GLFW action.
			@param mods A bitfield describing which modifier keys were held down (e.g. GLFW_MOD_SHIFT)
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
		 !  Use `Window::link_input_handler()`
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
		static onyx::Key char_to_key(char c);

		/*
			@brief Gets the character associated with the specified key.
			@param key The key to get the character of.
			@return The character associated with the specified key.
		 */
		static char key_to_char(onyx::Key key);

		/*
			@brief Gets the key associated with the specified string.
			@param str The string to get the key of.
			@return The key associated with the specified string.
		 */
		static onyx::Key str_to_key(const char* str);

		/*
			@brief Gets the string associated with the specified key.
			@param key The key to get the string of.
			@return The string associated with the specified key.
		 */
		static const char* key_to_str(onyx::Key key);

		/*
			@brief Gets the mouse button associated with the specified string.
			@param str The string to get the mouse button of.
			@return The mouse button associated with the specified string.
		 */
		static onyx::MouseButton str_to_mouse_button(const char* str);

		/*
			@brief Gets the string associated with the specified mouse button.
			@param button The mouse button to get the string of.
			@return The string associated with the specified mouse button.
		 */
		static const char* mouse_button_to_str(onyx::MouseButton button);

		/*
			@brief Gets the set of keys that are tapped.
		 *	Please note that the set is in no particular order!
			Ignores key cooldowns.
			@return The set of keys that are tapped.
		 */
		const std::unordered_set<onyx::Key>& get_keys_tapped() const;

		/*
			@brief Gets the set of keys that are down.
		 *	Please note that the set is in no particular order!
			Ignores key cooldowns.
			@return The set of keys that are down.
		 */
		const std::unordered_set<onyx::Key>& get_keys_down() const;

		/*
			@brief Gets the set of mouse buttons that are tapped.
		 *	Please note that the set is in no particular order!
			Ignores mouse button cooldowns.
			@return The set of mouse buttons that are tapped.
		 */
		const std::unordered_set<onyx::MouseButton>& get_mouse_buttons_tapped() const;

		/*
			@brief Gets the set of mouse buttons that are down.
		 *	Please note that the set is in no particular order!
			Ignores mouse button cooldowns.
			@return The set of mouse buttons that are down.
		 */
		const std::unordered_set<onyx::MouseButton>& get_mouse_buttons_down() const;

		/*
			@brief Gets the repeated key.
			Will return `onyx::Key::Null` if no key is being repeated.
			@return The repeated key.
		 */
		onyx::Key get_repeated_key() const;

		/*
			@brief Gets the keystate of the specified key.
			Ignores key cooldowns.
			@param key The key to check.
			@return The keystate of the specified key.
		 */
		onyx::KeyState get_key_state(onyx::Key key) const;

		/*
			@brief Gets whether the specified key was pressed but is not repeating.
			@param key The key to check.
			@return Whether the specified key was pressed but is not repeating.
		 */
		bool is_key_pressed(onyx::Key key);

		/*
			@brief Gets whether the specified key was tapped.
			Ignores key cooldowns.
			This function will return true only if it was pressed in the same frame this function was called in.
			@param key The key to check.
			@return Whether the specified key was tapped.
		 */
		bool is_key_tapped(onyx::Key key) const;

		/*
			@brief Gets whether the specified key has been pressed long enough to be repeating.
			@param key The key to check.
			@return Whether the specified key has been pressed long enough to be repeating.
		 */
		bool is_key_repeated(onyx::Key key);

		/*
			@brief Gets whether the specified key is currently pressed down.
			@param key The key to check.
			@return Whether the specified key is pressed down.
		 */
		bool is_key_down(onyx::Key key);

		/*
			@brief Gets whether the specified key is currently tapped or repeated.
			See `is_key_tapped` and `is_key_repeating` for more info.
			@param key The key to check.
			@return Whether the specified key is tapped or repeated.
		 */
		bool is_key_tapped_or_repeated(onyx::Key key);

		/*
			@brief Gets the keystate of the specified mouse button.
			Ignores mouse button cooldowns.
			@param button The mouse button to check.
			@return The keystate of the specified mouse button.
		 */
		onyx::KeyState get_mouse_button_state(onyx::MouseButton button) const;

		/*
			@brief Gets whether the specified mouse button was pressed but is not repeating.
			@param button The mouse button to check.
			@return Whether the specified mouse button was pressed but is not repeating.
		 */
		bool is_mouse_button_pressed(onyx::MouseButton button);

		/*
			@brief Gets whether the specified mouse button was tapped.
			Ignores mouse button cooldowns.
			This function will return true only if it was pressed in the same frame this function was called in.
			@param button The mouse button to check.
			@return Whether the specified mouse button was tapped.
		 */
		bool is_mouse_button_tapped(onyx::MouseButton button) const;

		/*
			@brief Gets whether the specified mouse button has been pressed long enough to be repeating.
			@param button The mouse button to check.
			@return Whether the specified mouse button has been pressed long enough to be repeating.
		 */
		bool is_mouse_button_repeated(onyx::MouseButton button);

		/*
			@brief Gets whether the specified mouse button is currently pressed down.
			@param button The mouse button to check.
			@return Whether the specified mouse button is pressed down.
		 */
		bool is_mouse_button_down(onyx::MouseButton button);

		/*
			@brief Sets a cooldown for the specified key.
			Cooldowns make it so once a key has been pressed,
			it is only detected as pressed once,
			and not again until the cooldown is over.
			@param key The key to apply the cooldown to.
			@param cooldown The cooldown time, in seconds.
		 */
		void set_key_cooldown(onyx::Key key, float cooldown);

		/*
			@brief Sets a cooldown for the specified mouse button.
			Cooldowns make it so once a mouse button has been pressed,
			it is only detected as pressed once,
			and not again until the cooldown is over.
			@param button The mouse button to apply the cooldown to.
			@param cooldown The cooldown time, in seconds.
		 */
		void set_mouse_button_cooldown(onyx::MouseButton button, float cooldown);

		/*
			@brief Sets whether the cursor is locked.
			Cursor lock makes the cursor invisible and locks its movement, while still allowing camera movement.
			@param lock Whether the cursor should be locked.
		 */
		void set_cursor_lock(bool lock);

		/*
			@brief Toggles the cursor lock.
		 */
		void toggle_cursor_lock();

		/*
			@brief Sets the key callback function.
			@param callback The callback function.
			See definition of `KeyCallbackFn` for parameter info.
		 */
		void set_key_callback(KeyCallbackFn callback);

		/*
			@brief Sets the mouse button callback function.
			@param callback The callback function.
			See definition of `MouseButtonCallbackFn` for parameter info.
		 */
		void set_mouse_button_callback(MouseButtonCallbackFn callback);

		/*
			@brief Sets the mouse position callback function.
			@param callback The callback function.
			See definition of `MousePosCallbackFn` for parameter info.
		 */
		void set_mouse_pos_callback(MousePosCallbackFn callback);

		/*
			@brief Sets the scroll callback function.
			@param callback The callback function.
			See definition of `ScrollCallbackFn` for parameter info.
		 */
		void set_scroll_callback(ScrollCallbackFn callback);

		/*
			@brief Sets the joystick callback function.
			@param callback The callback function.
			See definition of `JoystickCallbackFn` for parameter info.
		 */
		void set_joystick_callback(JoystickCallbackFn callback);

		/*
			@brief Gets whether the cursor is locked.
			@return Whether the cursor is locked.
		 */
		bool is_cursor_locked() const;

		/*
			@deprecated There is no longer a need for this function, as newly connected gamepads are automatically added to the list.
		 */
		[[deprecated("This function is deprecated and will be removed in the next major release. There is no longer a need for this function, as newly connected gamepads are automatically added to the list.")]]
		void refresh_gamepads();

		/*
			@brief Gets the position of the mouse.
			This is independent of whether update() is called each frame.
			@return The position of the mouse.
		 */
		const onyx::math::DVec2& get_mouse_pos() const;

		/*
			@brief Gets the change in position of the mouse since the last update.
			@return The change in position of the mouse since the last frame.
		 */
		const onyx::math::DVec2& get_mouse_deltas() const;

		/*
			@brief Gets the change in scroll of the mouse since the last update.
			@return The change in scroll of the mouse since the last frame.
		 */
		const onyx::math::DVec2& get_scroll_deltas() const;

		/*
			@brief Gets all gamepads connected to the system.
			@return A vector of all gamepads connected to the system.
		 */
		const std::vector<onyx::Gamepad>& get_gamepads() const;

		/*
			@brief Checks whether caps lock is on.
			This function uses platform-specific APIs, not Onyx key presses.
			@return Whether caps lock is on.
		 */
		static bool is_caps_lock_on();

		/*
			@brief Checks whether num lock is on.
			This function uses platform-specific APIs, not Onyx key presses.
			@return Whether num lock is on.
		 */
		static bool is_num_lock_on();

		/*
			@brief Checks whether scroll lock is on.
			This function uses platform-specific APIs, not Onyx key presses.
			@return Whether scroll lock is on.
		 */
		static bool is_scroll_lock_on();

	private:
		Window* p_win;

		onyx::KeyState keys[(int)onyx::Key::MaxKey];
		bool keys_tapped[(int)onyx::Key::MaxKey];
		float key_cooldowns[(int)onyx::Key::MaxKey];
		float set_key_cooldowns[(int)onyx::Key::MaxKey];

		onyx::KeyState buttons[(int)onyx::MouseButton::MaxButton];
		bool buttons_tapped[(int)onyx::MouseButton::MaxButton];
		float button_cooldowns[(int)onyx::MouseButton::MaxButton];
		float set_button_cooldowns[(int)onyx::MouseButton::MaxButton];

		std::vector<onyx::Key> active_key_cooldowns;
		std::vector<onyx::MouseButton> active_button_cooldowns;

		const static std::unordered_map<char, onyx::Key> char_to_key_map;
		const static std::unordered_map<onyx::Key, char> key_to_char_map;

		const static std::unordered_map<const char*, onyx::Key> str_to_key_map;
		const static std::unordered_map<onyx::Key, const char*> key_to_str_map;

		const static std::unordered_map<const char*, onyx::MouseButton> str_to_button_map;
		const static std::unordered_map<onyx::MouseButton, const char*> button_to_str_map;

		static std::mutex mtx_char_to_key_map;
		static std::mutex mtx_key_to_char_map;

		static std::mutex mtx_str_to_key_map;
		static std::mutex mtx_key_to_str_map;

		static std::mutex mtx_str_to_button_map;
		static std::mutex mtx_button_to_str_map;

		std::unordered_set<onyx::Key> keys_tapped_set;
		std::unordered_set<onyx::Key> keys_down_set;

		std::unordered_set<onyx::MouseButton> buttons_tapped_set;
		std::unordered_set<onyx::MouseButton> buttons_down_set;

		onyx::Key repeated_key;

		onyx::math::DVec2 mouse_pos;
		onyx::math::DVec2 last_mouse_pos;
		onyx::math::DVec2 mouse_deltas;
		onyx::math::DVec2 scroll_deltas;
		bool scroll_this_frame;

		std::vector<onyx::Gamepad> gamepads;

		bool cursor_lock;

		KeyCallbackFn p_key_callback;
		MouseButtonCallbackFn p_mouse_button_callback;
		MousePosCallbackFn p_mouse_pos_callback;
		ScrollCallbackFn p_scroll_callback;
		JoystickCallbackFn p_joystick_callback;

		void key_callback(int key, int scancode, int action, int mods);
		void mouse_button_callback(int button, int action, int mods);
		void mouse_pos_callback(double x, double y);
		void scroll_callback(double dx, double dy);
		void joystick_callback(int jid, int event);
	};
}
