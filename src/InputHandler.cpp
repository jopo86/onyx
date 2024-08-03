#pragma warning(disable : 4244; disable: 33011)

#include "InputHandler.h"

#include "Window.h"

#ifdef ONYX_OS_WINDOWS
	#include <windows.h>
#elif defined(ONYX_OS_LINUX)
	#include <X11/XKBlib.h>
	#include <X11/Xlib.h>
	#undef Button1
	#undef Button2
	#undef Button3
	#undef Button4
	#undef Button5
	#undef Button6
	#undef Button7
	#undef Button8
#elif defined(ONYX_OS_MAC)
	#include <CoreGraphics/CGEventSource.h>
#endif

using Onyx::Math::DVec2;

void onyx_err(const Onyx::Error&);
void onyx_warn(const Onyx::Warning&);

const std::unordered_map<char, Onyx::Key> Onyx::InputHandler::s_charToKeyMap = {
	{ ' ', Onyx::Key::Space },
	{ '\'', Onyx::Key::Apostrophe },
	{ ',', Onyx::Key::Comma },
	{ '-', Onyx::Key::Minus },
	{ '.', Onyx::Key::Period },
	{ '/', Onyx::Key::Slash },
	{ '0', Onyx::Key::Num0 },
	{ '1', Onyx::Key::Num1 },
	{ '2', Onyx::Key::Num2 },
	{ '3', Onyx::Key::Num3 },
	{ '4', Onyx::Key::Num4 },
	{ '5', Onyx::Key::Num5 },
	{ '6', Onyx::Key::Num6 },
	{ '7', Onyx::Key::Num7 },
	{ '8', Onyx::Key::Num8 },
	{ '9', Onyx::Key::Num9 },
	{ ';', Onyx::Key::Semicolon },
	{ '=', Onyx::Key::Equal },
	{ 'A', Onyx::Key::A },
	{ 'B', Onyx::Key::B },
	{ 'C', Onyx::Key::C },
	{ 'D', Onyx::Key::D },
	{ 'E', Onyx::Key::E },
	{ 'F', Onyx::Key::F },
	{ 'G', Onyx::Key::G },
	{ 'H', Onyx::Key::H },
	{ 'I', Onyx::Key::I },
	{ 'J', Onyx::Key::J },
	{ 'K', Onyx::Key::K },
	{ 'L', Onyx::Key::L },
	{ 'M', Onyx::Key::M },
	{ 'N', Onyx::Key::N },
	{ 'O', Onyx::Key::O },
	{ 'P', Onyx::Key::P },
	{ 'Q', Onyx::Key::Q },
	{ 'R', Onyx::Key::R },
	{ 'S', Onyx::Key::S },
	{ 'T', Onyx::Key::T },
	{ 'U', Onyx::Key::U },
	{ 'V', Onyx::Key::V },
	{ 'W', Onyx::Key::W },
	{ 'X', Onyx::Key::X },
	{ 'Y', Onyx::Key::Y },
	{ 'Z', Onyx::Key::Z },
	{ '[', Onyx::Key::LeftBracket },
	{ '\\', Onyx::Key::Backslash },
	{ ']', Onyx::Key::RightBracket },
	{ '`', Onyx::Key::GraveAccent },
	{ '!', Onyx::Key::World1 },
	{ '"', Onyx::Key::World2 }
};

const std::unordered_map<Onyx::Key, char> Onyx::InputHandler::s_keyToCharMap = {
	{ Onyx::Key::Space, ' ' },
	{ Onyx::Key::Apostrophe, '\'' },
	{ Onyx::Key::Comma, ',' },
	{ Onyx::Key::Minus, '-' },
	{ Onyx::Key::Period, '.' },
	{ Onyx::Key::Slash, '/' },
	{ Onyx::Key::Num0, '0' },
	{ Onyx::Key::Num1, '1' },
	{ Onyx::Key::Num2, '2' },
	{ Onyx::Key::Num3, '3' },
	{ Onyx::Key::Num4, '4' },
	{ Onyx::Key::Num5, '5' },
	{ Onyx::Key::Num6, '6' },
	{ Onyx::Key::Num7, '7' },
	{ Onyx::Key::Num8, '8' },
	{ Onyx::Key::Num9, '9' },
	{ Onyx::Key::Semicolon, ';' },
	{ Onyx::Key::Equal, '=' },
	{ Onyx::Key::A, 'A' },
	{ Onyx::Key::B, 'B' },
	{ Onyx::Key::C, 'C' },
	{ Onyx::Key::D, 'D' },
	{ Onyx::Key::E, 'E' },
	{ Onyx::Key::F, 'F' },
	{ Onyx::Key::G, 'G' },
	{ Onyx::Key::H, 'H' },
	{ Onyx::Key::I, 'I' },
	{ Onyx::Key::J, 'J' },
	{ Onyx::Key::K, 'K' },
	{ Onyx::Key::L, 'L' },
	{ Onyx::Key::M, 'M' },
	{ Onyx::Key::N, 'N' },
	{ Onyx::Key::O, 'O' },
	{ Onyx::Key::P, 'P' },
	{ Onyx::Key::Q, 'Q' },
	{ Onyx::Key::R, 'R' },
	{ Onyx::Key::S, 'S' },
	{ Onyx::Key::T, 'T' },
	{ Onyx::Key::U, 'U' },
	{ Onyx::Key::V, 'V' },
	{ Onyx::Key::W, 'W' },
	{ Onyx::Key::X, 'X' },
	{ Onyx::Key::Y, 'Y' },
	{ Onyx::Key::Z, 'Z' },
	{ Onyx::Key::LeftBracket, '[' },
	{ Onyx::Key::Backslash, '\\' },
	{ Onyx::Key::RightBracket, ']' },
	{ Onyx::Key::GraveAccent, '`' },
	{ Onyx::Key::World1, '!' },
	{ Onyx::Key::World2, '"' }
};

const std::unordered_map<const char*, Onyx::Key> Onyx::InputHandler::s_strToKeyMap = {
	{ "Null", Onyx::Key::Null },
	{ "Unknown", Onyx::Key::Unknown },
	{ "Space", Onyx::Key::Space },
	{ "Apostrophe", Onyx::Key::Apostrophe },
	{ "Comma", Onyx::Key::Comma },
	{ "Minus", Onyx::Key::Minus },
	{ "Period", Onyx::Key::Period },
	{ "Slash", Onyx::Key::Slash },
	{ "Num0", Onyx::Key::Num0 },
	{ "Num1", Onyx::Key::Num1 },
	{ "Num2", Onyx::Key::Num2 },
	{ "Num3", Onyx::Key::Num3 },
	{ "Num4", Onyx::Key::Num4 },
	{ "Num5", Onyx::Key::Num5 },
	{ "Num6", Onyx::Key::Num6 },
	{ "Num7", Onyx::Key::Num7 },
	{ "Num8", Onyx::Key::Num8 },
	{ "Num9", Onyx::Key::Num9 },
	{ "Semicolon", Onyx::Key::Semicolon },
	{ "Equal", Onyx::Key::Equal },
	{ "A", Onyx::Key::A },
	{ "B", Onyx::Key::B },
	{ "C", Onyx::Key::C },
	{ "D", Onyx::Key::D },
	{ "E", Onyx::Key::E },
	{ "F", Onyx::Key::F },
	{ "G", Onyx::Key::G },
	{ "H", Onyx::Key::H },
	{ "I", Onyx::Key::I },
	{ "J", Onyx::Key::J },
	{ "K", Onyx::Key::K },
	{ "L", Onyx::Key::L },
	{ "M", Onyx::Key::M },
	{ "N", Onyx::Key::N },
	{ "O", Onyx::Key::O },
	{ "P", Onyx::Key::P },
	{ "Q", Onyx::Key::Q },
	{ "R", Onyx::Key::R },
	{ "S", Onyx::Key::S },
	{ "T", Onyx::Key::T },
	{ "U", Onyx::Key::U },
	{ "V", Onyx::Key::V },
	{ "W", Onyx::Key::W },
	{ "X", Onyx::Key::X },
	{ "Y", Onyx::Key::Y },
	{ "Z", Onyx::Key::Z },
	{ "LeftBracket", Onyx::Key::LeftBracket },
	{ "Backslash", Onyx::Key::Backslash },
	{ "RightBracket", Onyx::Key::RightBracket },
	{ "GraveAccent", Onyx::Key::GraveAccent },
	{ "World1", Onyx::Key::World1 },
	{ "World2", Onyx::Key::World2 },
	{ "Escape", Onyx::Key::Escape },
	{ "Enter", Onyx::Key::Enter },
	{ "Tab", Onyx::Key::Tab },
	{ "Backspace", Onyx::Key::Backspace },
	{ "Insert", Onyx::Key::Insert },
	{ "Delete", Onyx::Key::Delete },
	{ "ArrowRight", Onyx::Key::ArrowRight },
	{ "ArrowLeft", Onyx::Key::ArrowLeft },
	{ "ArrowDown", Onyx::Key::ArrowDown },
	{ "ArrowUp", Onyx::Key::ArrowUp },
	{ "PageUp", Onyx::Key::PageUp },
	{ "PageDown", Onyx::Key::PageDown },
	{ "Home", Onyx::Key::Home },
	{ "End", Onyx::Key::End },
	{ "CapsLock", Onyx::Key::CapsLock },
	{ "ScrollLock", Onyx::Key::ScrollLock },
	{ "NumLock", Onyx::Key::NumLock },
	{ "PrintScreen", Onyx::Key::PrintScreen },
	{ "Pause", Onyx::Key::Pause },
	{ "F1", Onyx::Key::F1 },
	{ "F2", Onyx::Key::F2 },
	{ "F3", Onyx::Key::F3 },
	{ "F4", Onyx::Key::F4 },
	{ "F5", Onyx::Key::F5 },
	{ "F6", Onyx::Key::F6 },
	{ "F7", Onyx::Key::F7 },
	{ "F8", Onyx::Key::F8 },
	{ "F9", Onyx::Key::F9 },
	{ "F10", Onyx::Key::F10 },
	{ "F11", Onyx::Key::F11 },
	{ "F12", Onyx::Key::F12 },
	{ "F13", Onyx::Key::F13 },
	{ "F14", Onyx::Key::F14 },
	{ "F15", Onyx::Key::F15 },
	{ "F16", Onyx::Key::F16 },
	{ "F17", Onyx::Key::F17 },
	{ "F18", Onyx::Key::F18 },
	{ "F19", Onyx::Key::F19 },
	{ "F20", Onyx::Key::F20 },
	{ "F21", Onyx::Key::F21 },
	{ "F22", Onyx::Key::F22 },
	{ "F23", Onyx::Key::F23 },
	{ "F24", Onyx::Key::F24 },
	{ "F25", Onyx::Key::F25 },
	{ "Numpad0", Onyx::Key::Numpad0 },
	{ "Numpad1", Onyx::Key::Numpad1 },
	{ "Numpad2", Onyx::Key::Numpad2 },
	{ "Numpad3", Onyx::Key::Numpad3 },
	{ "Numpad4", Onyx::Key::Numpad4 },
	{ "Numpad5", Onyx::Key::Numpad5 },
	{ "Numpad6", Onyx::Key::Numpad6 },
	{ "Numpad7", Onyx::Key::Numpad7 },
	{ "Numpad8", Onyx::Key::Numpad8 },
	{ "Numpad9", Onyx::Key::Numpad9 },
	{ "NumpadDecimal", Onyx::Key::NumpadDecimal },
	{ "NumpadDivide", Onyx::Key::NumpadDivide },
	{ "NumpadMultiply", Onyx::Key::NumpadMultiply },
	{ "NumpadSubtract", Onyx::Key::NumpadSubtract },
	{ "NumpadAdd", Onyx::Key::NumpadAdd },
	{ "NumpadEnter", Onyx::Key::NumpadEnter },
	{ "NumpadEqual", Onyx::Key::NumpadEqual },
	{ "LeftShift", Onyx::Key::LeftShift },
	{ "LeftControl", Onyx::Key::LeftControl },
	{ "LeftAlt", Onyx::Key::LeftAlt },
	{ "LeftSuper", Onyx::Key::LeftSuper },
	{ "RightShift", Onyx::Key::RightShift },
	{ "RightControl", Onyx::Key::RightControl },
	{ "RightAlt", Onyx::Key::RightAlt },
	{ "RightSuper", Onyx::Key::RightSuper },
	{ "Menu", Onyx::Key::Menu },
	{ "MaxKey", Onyx::Key::MaxKey }
};

const std::unordered_map<Onyx::Key, const char*> Onyx::InputHandler::s_keyToStrMap = {
	{ Onyx::Key::Null, "Null" },
	{ Onyx::Key::Unknown, "Unknown" },
	{ Onyx::Key::Space, "Space" },
	{ Onyx::Key::Apostrophe, "Apostrophe" },
	{ Onyx::Key::Comma, "Comma" },
	{ Onyx::Key::Minus, "Minus" },
	{ Onyx::Key::Period, "Period" },
	{ Onyx::Key::Slash, "Slash" },
	{ Onyx::Key::Num0, "Num0" },
	{ Onyx::Key::Num1, "Num1" },
	{ Onyx::Key::Num2, "Num2" },
	{ Onyx::Key::Num3, "Num3" },
	{ Onyx::Key::Num4, "Num4" },
	{ Onyx::Key::Num5, "Num5" },
	{ Onyx::Key::Num6, "Num6" },
	{ Onyx::Key::Num7, "Num7" },
	{ Onyx::Key::Num8, "Num8" },
	{ Onyx::Key::Num9, "Num9" },
	{ Onyx::Key::Semicolon, "Semicolon" },
	{ Onyx::Key::Equal, "Equal" },
	{ Onyx::Key::A, "A" },
	{ Onyx::Key::B, "B" },
	{ Onyx::Key::C, "C" },
	{ Onyx::Key::D, "D" },
	{ Onyx::Key::E, "E" },
	{ Onyx::Key::F, "F" },
	{ Onyx::Key::G, "G" },
	{ Onyx::Key::H, "H" },
	{ Onyx::Key::I, "I" },
	{ Onyx::Key::J, "J" },
	{ Onyx::Key::K, "K" },
	{ Onyx::Key::L, "L" },
	{ Onyx::Key::M, "M" },
	{ Onyx::Key::N, "N" },
	{ Onyx::Key::O, "O" },
	{ Onyx::Key::P, "P" },
	{ Onyx::Key::Q, "Q" },
	{ Onyx::Key::R, "R" },
	{ Onyx::Key::S, "S" },
	{ Onyx::Key::T, "T" },
	{ Onyx::Key::U, "U" },
	{ Onyx::Key::V, "V" },
	{ Onyx::Key::W, "W" },
	{ Onyx::Key::X, "X" },
	{ Onyx::Key::Y, "Y" },
	{ Onyx::Key::Z, "Z" },
	{ Onyx::Key::LeftBracket, "LeftBracket" },
	{ Onyx::Key::Backslash, "Backslash" },
	{ Onyx::Key::RightBracket, "RightBracket" },
	{ Onyx::Key::GraveAccent, "GraveAccent" },
	{ Onyx::Key::World1, "World1" },
	{ Onyx::Key::World2, "World2" },
	{ Onyx::Key::Escape, "Escape" },
	{ Onyx::Key::Enter, "Enter" },
	{ Onyx::Key::Tab, "Tab" },
	{ Onyx::Key::Backspace, "Backspace" },
	{ Onyx::Key::Insert, "Insert" },
	{ Onyx::Key::Delete, "Delete" },
	{ Onyx::Key::ArrowRight, "ArrowRight" },
	{ Onyx::Key::ArrowLeft, "ArrowLeft" },
	{ Onyx::Key::ArrowDown, "ArrowDown" },
	{ Onyx::Key::ArrowUp, "ArrowUp" },
	{ Onyx::Key::PageUp, "PageUp" },
	{ Onyx::Key::PageDown, "PageDown" },
	{ Onyx::Key::Home, "Home" },
	{ Onyx::Key::End, "End" },
	{ Onyx::Key::CapsLock, "CapsLock" },
	{ Onyx::Key::ScrollLock, "ScrollLock" },
	{ Onyx::Key::NumLock, "NumLock" },
	{ Onyx::Key::PrintScreen, "PrintScreen" },
	{ Onyx::Key::Pause, "Pause" },
	{ Onyx::Key::F1, "F1" },
	{ Onyx::Key::F2, "F2" },
	{ Onyx::Key::F3, "F3" },
	{ Onyx::Key::F4, "F4" },
	{ Onyx::Key::F5, "F5" },
	{ Onyx::Key::F6, "F6" },
	{ Onyx::Key::F7, "F7" },
	{ Onyx::Key::F8, "F8" },
	{ Onyx::Key::F9, "F9" },
	{ Onyx::Key::F10, "F10" },
	{ Onyx::Key::F11, "F11" },
	{ Onyx::Key::F12, "F12" },
	{ Onyx::Key::F13, "F13" },
	{ Onyx::Key::F14, "F14" },
	{ Onyx::Key::F15, "F15" },
	{ Onyx::Key::F16, "F16" },
	{ Onyx::Key::F17, "F17" },
	{ Onyx::Key::F18, "F18" },
	{ Onyx::Key::F19, "F19" },
	{ Onyx::Key::F20, "F20" },
	{ Onyx::Key::F21, "F21" },
	{ Onyx::Key::F22, "F22" },
	{ Onyx::Key::F23, "F23" },
	{ Onyx::Key::F24, "F24" },
	{ Onyx::Key::F25, "F25" },
	{ Onyx::Key::Numpad0, "Numpad0" },
	{ Onyx::Key::Numpad1, "Numpad1" },
	{ Onyx::Key::Numpad2, "Numpad2" },
	{ Onyx::Key::Numpad3, "Numpad3" },
	{ Onyx::Key::Numpad4, "Numpad4" },
	{ Onyx::Key::Numpad5, "Numpad5" },
	{ Onyx::Key::Numpad6, "Numpad6" },
	{ Onyx::Key::Numpad7, "Numpad7" },
	{ Onyx::Key::Numpad8, "Numpad8" },
	{ Onyx::Key::Numpad9, "Numpad9" },
	{ Onyx::Key::NumpadDecimal, "NumpadDecimal" },
	{ Onyx::Key::NumpadDivide, "NumpadDivide" },
	{ Onyx::Key::NumpadMultiply, "NumpadMultiply" },
	{ Onyx::Key::NumpadSubtract, "NumpadSubtract" },
	{ Onyx::Key::NumpadAdd, "NumpadAdd" },
	{ Onyx::Key::NumpadEnter, "NumpadEnter" },
	{ Onyx::Key::NumpadEqual, "NumpadEqual" },
	{ Onyx::Key::LeftShift, "LeftShift" },
	{ Onyx::Key::LeftControl, "LeftControl" },
	{ Onyx::Key::LeftAlt, "LeftAlt" },
	{ Onyx::Key::LeftSuper, "LeftSuper" },
	{ Onyx::Key::RightShift, "RightShift" },
	{ Onyx::Key::RightControl, "RightControl" },
	{ Onyx::Key::RightAlt, "RightAlt" },
	{ Onyx::Key::RightSuper, "RightSuper" },
	{ Onyx::Key::Menu, "Menu" },
	{ Onyx::Key::MaxKey, "MaxKey" }
};

const std::unordered_map<const char*, Onyx::MouseButton> Onyx::InputHandler::s_strToButtonMap = {
	{ "Null", Onyx::MouseButton::Null },
	{ "Unknown", Onyx::MouseButton::Unknown },
	{ "Button1", Onyx::MouseButton::Button1 },
	{ "Button2", Onyx::MouseButton::Button2 },
	{ "Button3", Onyx::MouseButton::Button3 },
	{ "Button4", Onyx::MouseButton::Button4 },
	{ "Button5", Onyx::MouseButton::Button5 },
	{ "Button6", Onyx::MouseButton::Button6 },
	{ "Button7", Onyx::MouseButton::Button7 },
	{ "Button8", Onyx::MouseButton::Button8 },
	{ "Left", Onyx::MouseButton::Left },
	{ "Right", Onyx::MouseButton::Right },
	{ "Middle", Onyx::MouseButton::Middle },
	{ "SideBack", Onyx::MouseButton::SideBack },
	{ "SideFront", Onyx::MouseButton::SideFront },
	{ "MaxButton", Onyx::MouseButton::MaxButton }
};

const std::unordered_map<Onyx::MouseButton, const char*> Onyx::InputHandler::s_buttonToStrMap = {
	{ Onyx::MouseButton::Null, "Null" },
	{ Onyx::MouseButton::Unknown, "Unknown" },
	{ Onyx::MouseButton::Button1, "Button1" },
	{ Onyx::MouseButton::Button2, "Button2" },
	{ Onyx::MouseButton::Button3, "Button3" },
	{ Onyx::MouseButton::Button4, "Button4" },
	{ Onyx::MouseButton::Button5, "Button5" },
	{ Onyx::MouseButton::Button6, "Button6" },
	{ Onyx::MouseButton::Button7, "Button7" },
	{ Onyx::MouseButton::Button8, "Button8" },
	{ Onyx::MouseButton::Left, "Left" },
	{ Onyx::MouseButton::Right, "Right" },
	{ Onyx::MouseButton::Middle, "Middle" },
	{ Onyx::MouseButton::SideBack, "SideBack" },
	{ Onyx::MouseButton::SideFront, "SideFront" },
	{ Onyx::MouseButton::MaxButton, "MaxButton" }
};

std::mutex Onyx::InputHandler::s_mtx_charToKeyMap;
std::mutex Onyx::InputHandler::s_mtx_keyToCharMap;
std::mutex Onyx::InputHandler::s_mtx_strToKeyMap;
std::mutex Onyx::InputHandler::s_mtx_keyToStrMap;
std::mutex Onyx::InputHandler::s_mtx_strToButtonMap;
std::mutex Onyx::InputHandler::s_mtx_buttonToStrMap;

Onyx::InputHandler::InputHandler()
{
	m_pWin = nullptr;
	m_pKeyCallback = nullptr;
	m_pMouseButtonCallback = nullptr;
	m_pMousePosCallback = nullptr;
	m_pScrollCallback = nullptr;
	m_pJoystickCallback = nullptr;

	for (int i = 0; i < (int)Onyx::Key::MaxKey; i++)
	{
		m_keys[i] = Onyx::KeyState::Untouched;
		m_keysTapped[i] = false;
		m_keyCooldowns[i] = 0.0f;
		m_setKeyCooldowns[i] = 0.0f;
	}

	for (int i = 0; i < (int)Onyx::MouseButton::MaxButton; i++)
	{
		m_buttons[i] = Onyx::KeyState::Untouched;
		m_buttonsTapped[i] = false;
		m_buttonCooldowns[i] = 0.0f;
		m_setButtonCooldowns[i] = 0.0f;
	}

	m_mousePos = DVec2(0.0f);
	m_lastMousePos = DVec2(0.0f);
	m_mouseDeltas = DVec2(0.0f);

	m_cursorLock = false;
	m_scrollThisFrame = false;

	for (int jid = GLFW_JOYSTICK_1; jid <= GLFW_JOYSTICK_16; jid++)
	{
		if (glfwJoystickIsGamepad(jid)) m_gamepads.push_back(Gamepad(jid));
	}

	m_repeatedKey = Onyx::Key::Null;
}

void Onyx::InputHandler::update()
{
	for (bool& tapped : m_keysTapped) tapped = false;
	for (bool& tapped : m_buttonsTapped) tapped = false;
	m_keysTappedSet.clear();
	m_buttonsTappedSet.clear();

	m_scrollThisFrame = false;
	glfwPollEvents();

	m_mouseDeltas.set(m_mousePos.getX() - m_lastMousePos.getX(), m_mousePos.getY() - m_lastMousePos.getY());
	m_lastMousePos = m_mousePos;
	if (!m_scrollThisFrame) m_scrollDeltas.set(0.0, 0.0);

	for (Gamepad& gp : m_gamepads)
	{
		if (gp.isConnected()) gp.update();
	}

	if (m_pWin == nullptr)
	{
		onyx_err(Error{
				.sourceFunction = "Onyx::InputHandler::update()",
				.message = "Window pointer is null.",
				.howToFix = "Make sure the input handler was linked to a window (Window::linkInputHandler())."
			}
		);
		return;
	}

	for (Onyx::Key key : m_activeKeyCooldowns)
	{
		if (m_keyCooldowns[(int)key] >= 0) m_keyCooldowns[(int)key] -= m_pWin->m_deltaTime;
	}

	for (Onyx::MouseButton button : m_activeButtonCooldowns)
	{
		if (m_buttonCooldowns[(int)button] >= 0) m_buttonCooldowns[(int)button] -= m_pWin->m_deltaTime;
	}

	if (m_keys[(int)Key::F7] == KeyState::Press || m_keys[(int)Key::F7] == KeyState::Repeat ||
		m_keys[(int)Key::F8] == KeyState::Press || m_keys[(int)Key::F8] == KeyState::Repeat ||
		m_keys[(int)Key::F9] == KeyState::Press || m_keys[(int)Key::F9] == KeyState::Repeat)
	{
		return;
	}
	m_pWin->m_numFramesInputNotUpdated = 0; // problem line
}

Onyx::Key Onyx::InputHandler::CharToKey(char c)
{
	s_mtx_charToKeyMap.lock();
	auto it = s_charToKeyMap.find(c);
	if (it != s_charToKeyMap.end())
	{
		s_mtx_charToKeyMap.unlock();
		return it->second;
	}
	s_mtx_charToKeyMap.unlock();

	onyx_warn(Warning{
			.sourceFunction = "Onyx::InputHandler::CharToKey(char)",
			.message = "Character not found in map, returning Onyx::Key::Unknown.",
			.howToFix = "Make sure the character is in the map.",
			.severity = Onyx::Warning::Severity::Low
		}
	);
	return Onyx::Key::Unknown;
}

char Onyx::InputHandler::KeyToChar(Onyx::Key key)
{
	s_mtx_keyToCharMap.lock();
	auto it = s_keyToCharMap.find(key);
	if (it != s_keyToCharMap.end()) 
	{
		s_mtx_keyToCharMap.unlock();
		return it->second;
	}
	s_mtx_keyToCharMap.unlock();

	onyx_warn(Warning{
			.sourceFunction = "Onyx::InputHandler::KeyToChar(Onyx::Key)",
			.message = "Key not found in map, returning ' '.",
			.howToFix = "Make sure the key is in the map.",
			.severity = Onyx::Warning::Severity::Low
		}
	);
	return ' ';
}

Onyx::Key Onyx::InputHandler::StrToKey(const char* str)
{
	s_mtx_strToKeyMap.lock();
	auto it = s_strToKeyMap.find(str);
	if (it != s_strToKeyMap.end()) 
	{
		s_mtx_strToKeyMap.unlock();
		return it->second;
	}
	s_mtx_strToKeyMap.unlock();

	onyx_warn(Warning{
			.sourceFunction = "Onyx::InputHandler::StrToKey(const char*)",
			.message = "String not found in map, returning Onyx::Key::Unknown.",
			.howToFix = "Make sure the string is in the map.",
			.severity = Onyx::Warning::Severity::Low
		}
	);
	return Onyx::Key::Unknown;
}

const char* Onyx::InputHandler::KeyToStr(Onyx::Key key)
{
	s_mtx_keyToStrMap.lock();
	auto it = s_keyToStrMap.find(key);
	if (it != s_keyToStrMap.end()) 
	{
		s_mtx_keyToStrMap.unlock();
		return it->second;
	}
	s_mtx_keyToStrMap.unlock();

	onyx_warn(Warning{
			.sourceFunction = "Onyx::InputHandler::KeyToStr(Onyx::Key)",
			.message = "Key not found in map, returning \"Unknown\".",
			.howToFix = "Make sure the key is in the map.",
			.severity = Onyx::Warning::Severity::Low
		}
	);
	return "Unknown";
}

Onyx::MouseButton Onyx::InputHandler::StrToMouseButton(const char* str)
{
	s_mtx_strToButtonMap.lock();
	auto it = s_strToButtonMap.find(str);
	if (it != s_strToButtonMap.end()) 
	{
		s_mtx_strToButtonMap.unlock();
		return it->second;
	}
	s_mtx_strToButtonMap.unlock();

	onyx_warn(Warning{
			.sourceFunction = "Onyx::InputHandler::StrToButton(const char*)",
			.message = "String not found in map, returning Onyx::MouseButton::Unknown.",
			.howToFix = "Make sure the string is in the map.",
			.severity = Onyx::Warning::Severity::Low
		}
	);
	return Onyx::MouseButton::Unknown;
}

const char* Onyx::InputHandler::MouseButtonToStr(Onyx::MouseButton button)
{
	s_mtx_buttonToStrMap.lock();
	auto it = s_buttonToStrMap.find(button);
	if (it != s_buttonToStrMap.end()) 
	{
		s_mtx_buttonToStrMap.unlock();
		return it->second;
	}
	s_mtx_buttonToStrMap.unlock();

	onyx_warn(Warning{
			.sourceFunction = "Onyx::InputHandler::MouseButtonToStr(Onyx::MouseButton)",
			.message = "Button not found in map, returning \"Unknown\".",
			.howToFix = "Make sure the button is in the map.",
			.severity = Onyx::Warning::Severity::Low
		}
	);
	return "Unknown";
}

const std::unordered_set<Onyx::Key>& Onyx::InputHandler::getKeysTapped() const
{
	return m_keysTappedSet;
}

const std::unordered_set<Onyx::Key>& Onyx::InputHandler::getKeysDown() const
{
	return m_keysDownSet;
}

const std::unordered_set<Onyx::MouseButton>& Onyx::InputHandler::getMouseButtonsTapped() const
{
	return m_buttonsTappedSet;
}

const std::unordered_set<Onyx::MouseButton>& Onyx::InputHandler::getMouseButtonsDown() const
{
	return m_buttonsDownSet;
}

Onyx::Key Onyx::InputHandler::getRepeatedKey() const
{
	return m_repeatedKey;
}

Onyx::KeyState Onyx::InputHandler::getKeyState(Onyx::Key key) const
{
	return m_keys[(int)key];
}

bool Onyx::InputHandler::isKeyPressed(Onyx::Key _key)
{
	int key = (int)_key;
	if (key < 0) return false;
	bool retval = m_keyCooldowns[key] <= 0 ? m_keys[key] == Onyx::KeyState::Press : false;
	if (retval) m_keyCooldowns[key] = m_setKeyCooldowns[key];
	return retval;
}

bool Onyx::InputHandler::isKeyTapped(Onyx::Key _key) const
{
	int key = (int)_key;
	if (key < 0) return false;
	return m_keysTapped[key];
}

bool Onyx::InputHandler::isKeyRepeated(Onyx::Key _key)
{
	int key = (int)_key;
	if (key < 0) return false;
	bool retval = m_keyCooldowns[key] <= 0 ? m_keys[key] == Onyx::KeyState::Repeat : false;
	if (retval) m_keyCooldowns[key] = m_setKeyCooldowns[key];
	return retval;
}

bool Onyx::InputHandler::isKeyDown(Onyx::Key _key)
{
	int key = (int)_key;
	if (key < 0) return false;
	bool retval = m_keyCooldowns[key] <= 0 ? m_keys[key] == Onyx::KeyState::Press || m_keys[key] == Onyx::KeyState::Repeat : false;
	if (retval) m_keyCooldowns[key] = m_setKeyCooldowns[key];
	return retval;
}

bool Onyx::InputHandler::isKeyTappedOrRepeated(Onyx::Key key)
{
	return isKeyTapped(key) || isKeyRepeated(key);
}

Onyx::KeyState Onyx::InputHandler::getMouseButtonState(Onyx::MouseButton _button) const
{
	int button = (int)_button;
	return m_buttons[button];
}

bool Onyx::InputHandler::isMouseButtonPressed(Onyx::MouseButton _button)
{
	int button = (int)_button;
	if (button < 0) return false;
	bool retval = m_buttonCooldowns[button] <= 0 ? m_buttons[button] == Onyx::KeyState::Press : false;
	if (retval) m_buttonCooldowns[button] = m_setButtonCooldowns[button];
	return retval;
}

bool Onyx::InputHandler::isMouseButtonTapped(Onyx::MouseButton _button) const
{
	int button = (int)_button;
	if (button < 0) return false;
	return m_buttonsTapped[button];
}

bool Onyx::InputHandler::isMouseButtonRepeated(Onyx::MouseButton _button)
{
	int button = (int)_button;
	if (button < 0) return false;
	bool retval = m_buttonCooldowns[button] <= 0 ? m_buttons[button] == Onyx::KeyState::Repeat : false;
	if (retval) m_buttonCooldowns[button] = m_setButtonCooldowns[button];
	return retval;
}

bool Onyx::InputHandler::isMouseButtonDown(Onyx::MouseButton _button)
{
	int button = (int)_button;
	if (button < 0) return false;
	bool retval = m_buttonCooldowns[button] <= 0 ? m_buttons[button] == Onyx::KeyState::Press || m_buttons[button] == Onyx::KeyState::Repeat : false;
	if (retval) m_buttonCooldowns[button] = m_setButtonCooldowns[button];
	return retval;
}

void Onyx::InputHandler::setKeyCooldown(Onyx::Key key, float cooldown)
{
	m_activeKeyCooldowns.push_back(key);
	m_setKeyCooldowns[(int)key] = cooldown;
}

void Onyx::InputHandler::setMouseButtonCooldown(Onyx::MouseButton button, float cooldown)
{
	m_activeButtonCooldowns.push_back(button);
	m_setButtonCooldowns[(int)button] = cooldown;
}

void Onyx::InputHandler::setCursorLock(bool lock)
{
	m_cursorLock = lock;
	glfwSetInputMode(m_pWin->m_pGlfwWin, GLFW_CURSOR, lock ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
}

void Onyx::InputHandler::toggleCursorLock()
{
	setCursorLock(!m_cursorLock);
}

void Onyx::InputHandler::setKeyCallback(KeyCallbackFn callback)
{
	m_pKeyCallback = callback;
}

void Onyx::InputHandler::setMouseButtonCallback(MouseButtonCallbackFn callback)
{
	m_pMouseButtonCallback = callback;
}

void Onyx::InputHandler::setMousePosCallback(MousePosCallbackFn callback)
{
	m_pMousePosCallback = callback;
}

void Onyx::InputHandler::setScrollCallback(ScrollCallbackFn callback)
{
	m_pScrollCallback = callback;
}

void Onyx::InputHandler::setJoystickCallback(JoystickCallbackFn callback)
{
	m_pJoystickCallback = callback;
}

bool Onyx::InputHandler::isCursorLocked() const
{
	return m_cursorLock;
}

void Onyx::InputHandler::refreshGamepads()
{
	for (int jid = GLFW_JOYSTICK_1; jid <= GLFW_JOYSTICK_16; jid++)
	{
		if (glfwJoystickIsGamepad(jid))
		{
			bool found = false;
			for (Gamepad& gamepad : m_gamepads)
			{
				if (gamepad.getGlfwID() == jid)
				{
					found = true;
					break;
				}
			}

			if (!found) m_gamepads.push_back(Gamepad(jid));
		}
	}
}

const Onyx::Math::DVec2& Onyx::InputHandler::getMousePos() const
{
	return m_mousePos;
}

const Onyx::Math::DVec2& Onyx::InputHandler::getMouseDeltas() const
{
	return m_mouseDeltas;
}

const Onyx::Math::DVec2& Onyx::InputHandler::getScrollDeltas() const
{
	return m_scrollDeltas;
}

const std::vector<Onyx::Gamepad>& Onyx::InputHandler::getGamepads() const
{
	return m_gamepads;
}

#ifdef ONYX_OS_WINDOWS
	bool Onyx::InputHandler::IsCapsLockOn()
	{
		return GetKeyState(VK_CAPITAL) & 1;
	}

	bool Onyx::InputHandler::IsNumLockOn()
	{
		return GetKeyState(VK_NUMLOCK) & 1;
	}

	bool Onyx::InputHandler::IsScrollLockOn()
	{
		return GetKeyState(VK_SCROLL) & 1;
	}

#elif defined(ONYX_OS_LINUX)
	bool Onyx::InputHandler::IsCapsLockOn()
	{
		Display* d = XOpenDisplay(NULL);
		if (!d) return false;
		uint n;
		XkbGetIndicatorState(d, XkbUseCoreKbd, &n);
		XCloseDisplay(d);
		return n & 0x01;
	}

	bool Onyx::InputHandler::IsNumLockOn()
	{
		Display* d = XOpenDisplay(NULL);
		if (!d) return false;
		uint n;
		XkbGetIndicatorState(d, XkbUseCoreKbd, &n);
		XCloseDisplay(d);
		return n & 0x02;
	}

	bool Onyx::InputHandler::IsScrollLockOn()
	{
		Display* d = XOpenDisplay(NULL);
		if (!d) return false;
		uint n;
		XkbGetIndicatorState(d, XkbUseCoreKbd, &n);
		XCloseDisplay(d);
		return n & 0x04;
	}

#elif defined(ONYX_OS_MAC)
	bool Onyx::InputHandler::IsCapsLockOn()
	{
		return CGEventSourceKeyState(kCGEventSourceStateHIDSystemState, kVK_CapsLock);
	}

	bool Onyx::InputHandler::IsNumLockOn()
	{
		return false;
	}

	bool Onyx::InputHandler::IsScrollLockOn()
	{
		return false;
	}

#else
	bool Onyx::InputHandler::IsCapsLockOn()
	{
		return false;
	}

	bool Onyx::InputHandler::IsNumLockOn()
	{
		return false;
	}

	bool Onyx::InputHandler::IsScrollLockOn()
	{
		return false;
	}

#endif

void Onyx::InputHandler::keyCallback(int key, int scancode, int action, int mods)
{
	m_keys[key] = (Onyx::KeyState)action;
	if (action == GLFW_PRESS) 
	{
		m_keysTapped[key] = true;

		m_keysTappedSet.insert((Onyx::Key)key);
		m_keysDownSet.insert((Onyx::Key)key);
	}
	else if (action == GLFW_REPEAT)
	{
		m_repeatedKey = (Onyx::Key)key;
	}
	else if (action == GLFW_RELEASE)
	{
		m_keysDownSet.erase((Onyx::Key)key);
		if (m_repeatedKey == (Onyx::Key)key) m_repeatedKey = Onyx::Key::Null;
	}

	if (m_pKeyCallback) m_pKeyCallback(key, scancode, action, mods);
}

void Onyx::InputHandler::mouseButtonCallback(int button, int action, int mods)
{
	m_buttons[button] = (Onyx::KeyState)action;
	if (action == GLFW_PRESS) 
	{
		m_buttonsTapped[button] = true;

		m_buttonsTappedSet.insert((Onyx::MouseButton)button);
		m_buttonsDownSet.insert((Onyx::MouseButton)button);
	}
	else if (action == GLFW_RELEASE)
	{
		m_buttonsDownSet.erase((Onyx::MouseButton)button);
	}

	if (m_pMouseButtonCallback) m_pMouseButtonCallback(button, action, mods);
}

void Onyx::InputHandler::mousePosCallback(double x, double y)
{
	m_mousePos.set(x, y);

	if (m_pMousePosCallback) m_pMousePosCallback(x, y);
}

void Onyx::InputHandler::scrollCallback(double dx, double dy)
{
	m_scrollDeltas.set(dx, dy);
	m_scrollThisFrame = true;

	if (m_pScrollCallback) m_pScrollCallback(dx, dy);
}

void Onyx::InputHandler::joystickCallback(int jid, int event)
{
	if (!glfwJoystickIsGamepad(jid)) return;

	if (m_pJoystickCallback != nullptr) m_pJoystickCallback(jid, event);

	bool found = false;
	for (Gamepad& gamepad : m_gamepads)
	{
		if (gamepad.getGlfwID() == jid)
		{
			found = true;
			break;
		}
	}

	if (!found && event == GLFW_CONNECTED) m_gamepads.push_back(Gamepad(jid));
	else if (found && event == GLFW_DISCONNECTED)
	{
		Gamepad* pGP = (Gamepad*)glfwGetJoystickUserPointer(jid);
		if (pGP != nullptr)
		{
			pGP->m_state.buttons[(int)GamepadButton::A] = GLFW_RELEASE;
			pGP->m_state.buttons[(int)GamepadButton::B] = GLFW_RELEASE;
			pGP->m_state.buttons[(int)GamepadButton::X] = GLFW_RELEASE;
			pGP->m_state.buttons[(int)GamepadButton::Y] = GLFW_RELEASE;
			pGP->m_state.buttons[(int)GamepadButton::LeftBumper] = GLFW_RELEASE;
			pGP->m_state.buttons[(int)GamepadButton::RightBumper] = GLFW_RELEASE;
			pGP->m_state.buttons[(int)GamepadButton::Back] = GLFW_RELEASE;
			pGP->m_state.buttons[(int)GamepadButton::Start] = GLFW_RELEASE;
			pGP->m_state.buttons[(int)GamepadButton::Guide] = GLFW_RELEASE;
			pGP->m_state.buttons[(int)GamepadButton::LeftStick] = GLFW_RELEASE;
			pGP->m_state.buttons[(int)GamepadButton::RightStick] = GLFW_RELEASE;
			pGP->m_state.buttons[(int)GamepadButton::DpadUp] = GLFW_RELEASE;
			pGP->m_state.buttons[(int)GamepadButton::DpadRight] = GLFW_RELEASE;
			pGP->m_state.buttons[(int)GamepadButton::DpadDown] = GLFW_RELEASE;
			pGP->m_state.buttons[(int)GamepadButton::DpadLeft] = GLFW_RELEASE;

			pGP->m_state.axes[(int)GamepadAxis::LeftX] = 0.0f;
			pGP->m_state.axes[(int)GamepadAxis::LeftY] = 0.0f;
			pGP->m_state.axes[(int)GamepadAxis::RightX] = 0.0f;
			pGP->m_state.axes[(int)GamepadAxis::RightY] = 0.0f;
			pGP->m_state.axes[(int)GamepadAxis::LeftTrigger] = 0.0f;
			pGP->m_state.axes[(int)GamepadAxis::RightTrigger] = 0.0f;
		}
	}
}
