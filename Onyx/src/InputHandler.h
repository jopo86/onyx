#pragma once

#include "Window.h"
#include "Core.h"

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
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
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

	private:
		Window* m_pWin;

		Onyx::KeyState m_keys[Onyx::Key::MaxKey];
		float m_keyCooldowns[Onyx::Key::MaxKey];
		float m_setKeyCooldowns[Onyx::Key::MaxKey];

		Onyx::KeyState m_buttons[Onyx::MouseButton::MaxButton];
		float m_buttonCooldowns[Onyx::MouseButton::MaxButton];
		float m_setButtonCooldowns[Onyx::MouseButton::MaxButton];

		std::vector<Onyx::Key> m_activeKeyCooldowns;
		std::vector<Onyx::MouseButton> m_activeButtonCooldowns;

		Onyx::Math::DVec2 m_mousePos;
		Onyx::Math::DVec2 m_lastMousePos;
		Onyx::Math::DVec2 m_mouseDeltas;
		Onyx::Math::DVec2 m_scrollDeltas;

		bool m_cursorLock;

		void keyCallback(int key, int scancode, int action, int mods);
		void mouseButtonCallback(int button, int action, int mods);
		void cursorPosCallback(double x, double y);
		void scrollCallback(double dx, double dy);
	};
}
