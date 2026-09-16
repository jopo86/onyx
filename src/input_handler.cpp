#pragma warning(disable : 4244; disable: 33011)

#include "input_handler.h"

#include "window.h"

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

using onyx::math::DVec2;

void onyx_err(const onyx::Error&);
void onyx_warn(const onyx::Warning&);

const std::unordered_map<char, onyx::Key> onyx::InputHandler::char_to_key_map = {
	{ ' ', onyx::Key::Space },
	{ '\'', onyx::Key::Apostrophe },
	{ ',', onyx::Key::Comma },
	{ '-', onyx::Key::Minus },
	{ '.', onyx::Key::Period },
	{ '/', onyx::Key::Slash },
	{ '0', onyx::Key::Num0 },
	{ '1', onyx::Key::Num1 },
	{ '2', onyx::Key::Num2 },
	{ '3', onyx::Key::Num3 },
	{ '4', onyx::Key::Num4 },
	{ '5', onyx::Key::Num5 },
	{ '6', onyx::Key::Num6 },
	{ '7', onyx::Key::Num7 },
	{ '8', onyx::Key::Num8 },
	{ '9', onyx::Key::Num9 },
	{ ';', onyx::Key::Semicolon },
	{ '=', onyx::Key::Equal },
	{ 'A', onyx::Key::A },
	{ 'B', onyx::Key::B },
	{ 'C', onyx::Key::C },
	{ 'D', onyx::Key::D },
	{ 'E', onyx::Key::E },
	{ 'F', onyx::Key::F },
	{ 'G', onyx::Key::G },
	{ 'H', onyx::Key::H },
	{ 'I', onyx::Key::I },
	{ 'J', onyx::Key::J },
	{ 'K', onyx::Key::K },
	{ 'L', onyx::Key::L },
	{ 'M', onyx::Key::M },
	{ 'N', onyx::Key::N },
	{ 'O', onyx::Key::O },
	{ 'P', onyx::Key::P },
	{ 'Q', onyx::Key::Q },
	{ 'R', onyx::Key::R },
	{ 'S', onyx::Key::S },
	{ 'T', onyx::Key::T },
	{ 'U', onyx::Key::U },
	{ 'V', onyx::Key::V },
	{ 'W', onyx::Key::W },
	{ 'X', onyx::Key::X },
	{ 'Y', onyx::Key::Y },
	{ 'Z', onyx::Key::Z },
	{ '[', onyx::Key::LeftBracket },
	{ '\\', onyx::Key::Backslash },
	{ ']', onyx::Key::RightBracket },
	{ '`', onyx::Key::GraveAccent },
	{ '!', onyx::Key::World1 },
	{ '"', onyx::Key::World2 }
};

const std::unordered_map<onyx::Key, char> onyx::InputHandler::key_to_char_map = {
	{ onyx::Key::Space, ' ' },
	{ onyx::Key::Apostrophe, '\'' },
	{ onyx::Key::Comma, ',' },
	{ onyx::Key::Minus, '-' },
	{ onyx::Key::Period, '.' },
	{ onyx::Key::Slash, '/' },
	{ onyx::Key::Num0, '0' },
	{ onyx::Key::Num1, '1' },
	{ onyx::Key::Num2, '2' },
	{ onyx::Key::Num3, '3' },
	{ onyx::Key::Num4, '4' },
	{ onyx::Key::Num5, '5' },
	{ onyx::Key::Num6, '6' },
	{ onyx::Key::Num7, '7' },
	{ onyx::Key::Num8, '8' },
	{ onyx::Key::Num9, '9' },
	{ onyx::Key::Semicolon, ';' },
	{ onyx::Key::Equal, '=' },
	{ onyx::Key::A, 'A' },
	{ onyx::Key::B, 'B' },
	{ onyx::Key::C, 'C' },
	{ onyx::Key::D, 'D' },
	{ onyx::Key::E, 'E' },
	{ onyx::Key::F, 'F' },
	{ onyx::Key::G, 'G' },
	{ onyx::Key::H, 'H' },
	{ onyx::Key::I, 'I' },
	{ onyx::Key::J, 'J' },
	{ onyx::Key::K, 'K' },
	{ onyx::Key::L, 'L' },
	{ onyx::Key::M, 'M' },
	{ onyx::Key::N, 'N' },
	{ onyx::Key::O, 'O' },
	{ onyx::Key::P, 'P' },
	{ onyx::Key::Q, 'Q' },
	{ onyx::Key::R, 'R' },
	{ onyx::Key::S, 'S' },
	{ onyx::Key::T, 'T' },
	{ onyx::Key::U, 'U' },
	{ onyx::Key::V, 'V' },
	{ onyx::Key::W, 'W' },
	{ onyx::Key::X, 'X' },
	{ onyx::Key::Y, 'Y' },
	{ onyx::Key::Z, 'Z' },
	{ onyx::Key::LeftBracket, '[' },
	{ onyx::Key::Backslash, '\\' },
	{ onyx::Key::RightBracket, ']' },
	{ onyx::Key::GraveAccent, '`' },
	{ onyx::Key::World1, '!' },
	{ onyx::Key::World2, '"' }
};

const std::unordered_map<const char*, onyx::Key> onyx::InputHandler::str_to_key_map = {
	{ "Null", onyx::Key::Null },
	{ "Unknown", onyx::Key::Unknown },
	{ "Space", onyx::Key::Space },
	{ "Apostrophe", onyx::Key::Apostrophe },
	{ "Comma", onyx::Key::Comma },
	{ "Minus", onyx::Key::Minus },
	{ "Period", onyx::Key::Period },
	{ "Slash", onyx::Key::Slash },
	{ "Num0", onyx::Key::Num0 },
	{ "Num1", onyx::Key::Num1 },
	{ "Num2", onyx::Key::Num2 },
	{ "Num3", onyx::Key::Num3 },
	{ "Num4", onyx::Key::Num4 },
	{ "Num5", onyx::Key::Num5 },
	{ "Num6", onyx::Key::Num6 },
	{ "Num7", onyx::Key::Num7 },
	{ "Num8", onyx::Key::Num8 },
	{ "Num9", onyx::Key::Num9 },
	{ "Semicolon", onyx::Key::Semicolon },
	{ "Equal", onyx::Key::Equal },
	{ "A", onyx::Key::A },
	{ "B", onyx::Key::B },
	{ "C", onyx::Key::C },
	{ "D", onyx::Key::D },
	{ "E", onyx::Key::E },
	{ "F", onyx::Key::F },
	{ "G", onyx::Key::G },
	{ "H", onyx::Key::H },
	{ "I", onyx::Key::I },
	{ "J", onyx::Key::J },
	{ "K", onyx::Key::K },
	{ "L", onyx::Key::L },
	{ "M", onyx::Key::M },
	{ "N", onyx::Key::N },
	{ "O", onyx::Key::O },
	{ "P", onyx::Key::P },
	{ "Q", onyx::Key::Q },
	{ "R", onyx::Key::R },
	{ "S", onyx::Key::S },
	{ "T", onyx::Key::T },
	{ "U", onyx::Key::U },
	{ "V", onyx::Key::V },
	{ "W", onyx::Key::W },
	{ "X", onyx::Key::X },
	{ "Y", onyx::Key::Y },
	{ "Z", onyx::Key::Z },
	{ "LeftBracket", onyx::Key::LeftBracket },
	{ "Backslash", onyx::Key::Backslash },
	{ "RightBracket", onyx::Key::RightBracket },
	{ "GraveAccent", onyx::Key::GraveAccent },
	{ "World1", onyx::Key::World1 },
	{ "World2", onyx::Key::World2 },
	{ "Escape", onyx::Key::Escape },
	{ "Enter", onyx::Key::Enter },
	{ "Tab", onyx::Key::Tab },
	{ "Backspace", onyx::Key::Backspace },
	{ "Insert", onyx::Key::Insert },
	{ "Delete", onyx::Key::Delete },
	{ "ArrowRight", onyx::Key::ArrowRight },
	{ "ArrowLeft", onyx::Key::ArrowLeft },
	{ "ArrowDown", onyx::Key::ArrowDown },
	{ "ArrowUp", onyx::Key::ArrowUp },
	{ "PageUp", onyx::Key::PageUp },
	{ "PageDown", onyx::Key::PageDown },
	{ "Home", onyx::Key::Home },
	{ "End", onyx::Key::End },
	{ "CapsLock", onyx::Key::CapsLock },
	{ "ScrollLock", onyx::Key::ScrollLock },
	{ "NumLock", onyx::Key::NumLock },
	{ "PrintScreen", onyx::Key::PrintScreen },
	{ "Pause", onyx::Key::Pause },
	{ "F1", onyx::Key::F1 },
	{ "F2", onyx::Key::F2 },
	{ "F3", onyx::Key::F3 },
	{ "F4", onyx::Key::F4 },
	{ "F5", onyx::Key::F5 },
	{ "F6", onyx::Key::F6 },
	{ "F7", onyx::Key::F7 },
	{ "F8", onyx::Key::F8 },
	{ "F9", onyx::Key::F9 },
	{ "F10", onyx::Key::F10 },
	{ "F11", onyx::Key::F11 },
	{ "F12", onyx::Key::F12 },
	{ "F13", onyx::Key::F13 },
	{ "F14", onyx::Key::F14 },
	{ "F15", onyx::Key::F15 },
	{ "F16", onyx::Key::F16 },
	{ "F17", onyx::Key::F17 },
	{ "F18", onyx::Key::F18 },
	{ "F19", onyx::Key::F19 },
	{ "F20", onyx::Key::F20 },
	{ "F21", onyx::Key::F21 },
	{ "F22", onyx::Key::F22 },
	{ "F23", onyx::Key::F23 },
	{ "F24", onyx::Key::F24 },
	{ "F25", onyx::Key::F25 },
	{ "Numpad0", onyx::Key::Numpad0 },
	{ "Numpad1", onyx::Key::Numpad1 },
	{ "Numpad2", onyx::Key::Numpad2 },
	{ "Numpad3", onyx::Key::Numpad3 },
	{ "Numpad4", onyx::Key::Numpad4 },
	{ "Numpad5", onyx::Key::Numpad5 },
	{ "Numpad6", onyx::Key::Numpad6 },
	{ "Numpad7", onyx::Key::Numpad7 },
	{ "Numpad8", onyx::Key::Numpad8 },
	{ "Numpad9", onyx::Key::Numpad9 },
	{ "NumpadDecimal", onyx::Key::NumpadDecimal },
	{ "NumpadDivide", onyx::Key::NumpadDivide },
	{ "NumpadMultiply", onyx::Key::NumpadMultiply },
	{ "NumpadSubtract", onyx::Key::NumpadSubtract },
	{ "NumpadAdd", onyx::Key::NumpadAdd },
	{ "NumpadEnter", onyx::Key::NumpadEnter },
	{ "NumpadEqual", onyx::Key::NumpadEqual },
	{ "LeftShift", onyx::Key::LeftShift },
	{ "LeftControl", onyx::Key::LeftControl },
	{ "LeftAlt", onyx::Key::LeftAlt },
	{ "LeftSuper", onyx::Key::LeftSuper },
	{ "RightShift", onyx::Key::RightShift },
	{ "RightControl", onyx::Key::RightControl },
	{ "RightAlt", onyx::Key::RightAlt },
	{ "RightSuper", onyx::Key::RightSuper },
	{ "Menu", onyx::Key::Menu },
	{ "MaxKey", onyx::Key::MaxKey }
};

const std::unordered_map<onyx::Key, const char*> onyx::InputHandler::key_to_str_map = {
	{ onyx::Key::Null, "Null" },
	{ onyx::Key::Unknown, "Unknown" },
	{ onyx::Key::Space, "Space" },
	{ onyx::Key::Apostrophe, "Apostrophe" },
	{ onyx::Key::Comma, "Comma" },
	{ onyx::Key::Minus, "Minus" },
	{ onyx::Key::Period, "Period" },
	{ onyx::Key::Slash, "Slash" },
	{ onyx::Key::Num0, "Num0" },
	{ onyx::Key::Num1, "Num1" },
	{ onyx::Key::Num2, "Num2" },
	{ onyx::Key::Num3, "Num3" },
	{ onyx::Key::Num4, "Num4" },
	{ onyx::Key::Num5, "Num5" },
	{ onyx::Key::Num6, "Num6" },
	{ onyx::Key::Num7, "Num7" },
	{ onyx::Key::Num8, "Num8" },
	{ onyx::Key::Num9, "Num9" },
	{ onyx::Key::Semicolon, "Semicolon" },
	{ onyx::Key::Equal, "Equal" },
	{ onyx::Key::A, "A" },
	{ onyx::Key::B, "B" },
	{ onyx::Key::C, "C" },
	{ onyx::Key::D, "D" },
	{ onyx::Key::E, "E" },
	{ onyx::Key::F, "F" },
	{ onyx::Key::G, "G" },
	{ onyx::Key::H, "H" },
	{ onyx::Key::I, "I" },
	{ onyx::Key::J, "J" },
	{ onyx::Key::K, "K" },
	{ onyx::Key::L, "L" },
	{ onyx::Key::M, "M" },
	{ onyx::Key::N, "N" },
	{ onyx::Key::O, "O" },
	{ onyx::Key::P, "P" },
	{ onyx::Key::Q, "Q" },
	{ onyx::Key::R, "R" },
	{ onyx::Key::S, "S" },
	{ onyx::Key::T, "T" },
	{ onyx::Key::U, "U" },
	{ onyx::Key::V, "V" },
	{ onyx::Key::W, "W" },
	{ onyx::Key::X, "X" },
	{ onyx::Key::Y, "Y" },
	{ onyx::Key::Z, "Z" },
	{ onyx::Key::LeftBracket, "LeftBracket" },
	{ onyx::Key::Backslash, "Backslash" },
	{ onyx::Key::RightBracket, "RightBracket" },
	{ onyx::Key::GraveAccent, "GraveAccent" },
	{ onyx::Key::World1, "World1" },
	{ onyx::Key::World2, "World2" },
	{ onyx::Key::Escape, "Escape" },
	{ onyx::Key::Enter, "Enter" },
	{ onyx::Key::Tab, "Tab" },
	{ onyx::Key::Backspace, "Backspace" },
	{ onyx::Key::Insert, "Insert" },
	{ onyx::Key::Delete, "Delete" },
	{ onyx::Key::ArrowRight, "ArrowRight" },
	{ onyx::Key::ArrowLeft, "ArrowLeft" },
	{ onyx::Key::ArrowDown, "ArrowDown" },
	{ onyx::Key::ArrowUp, "ArrowUp" },
	{ onyx::Key::PageUp, "PageUp" },
	{ onyx::Key::PageDown, "PageDown" },
	{ onyx::Key::Home, "Home" },
	{ onyx::Key::End, "End" },
	{ onyx::Key::CapsLock, "CapsLock" },
	{ onyx::Key::ScrollLock, "ScrollLock" },
	{ onyx::Key::NumLock, "NumLock" },
	{ onyx::Key::PrintScreen, "PrintScreen" },
	{ onyx::Key::Pause, "Pause" },
	{ onyx::Key::F1, "F1" },
	{ onyx::Key::F2, "F2" },
	{ onyx::Key::F3, "F3" },
	{ onyx::Key::F4, "F4" },
	{ onyx::Key::F5, "F5" },
	{ onyx::Key::F6, "F6" },
	{ onyx::Key::F7, "F7" },
	{ onyx::Key::F8, "F8" },
	{ onyx::Key::F9, "F9" },
	{ onyx::Key::F10, "F10" },
	{ onyx::Key::F11, "F11" },
	{ onyx::Key::F12, "F12" },
	{ onyx::Key::F13, "F13" },
	{ onyx::Key::F14, "F14" },
	{ onyx::Key::F15, "F15" },
	{ onyx::Key::F16, "F16" },
	{ onyx::Key::F17, "F17" },
	{ onyx::Key::F18, "F18" },
	{ onyx::Key::F19, "F19" },
	{ onyx::Key::F20, "F20" },
	{ onyx::Key::F21, "F21" },
	{ onyx::Key::F22, "F22" },
	{ onyx::Key::F23, "F23" },
	{ onyx::Key::F24, "F24" },
	{ onyx::Key::F25, "F25" },
	{ onyx::Key::Numpad0, "Numpad0" },
	{ onyx::Key::Numpad1, "Numpad1" },
	{ onyx::Key::Numpad2, "Numpad2" },
	{ onyx::Key::Numpad3, "Numpad3" },
	{ onyx::Key::Numpad4, "Numpad4" },
	{ onyx::Key::Numpad5, "Numpad5" },
	{ onyx::Key::Numpad6, "Numpad6" },
	{ onyx::Key::Numpad7, "Numpad7" },
	{ onyx::Key::Numpad8, "Numpad8" },
	{ onyx::Key::Numpad9, "Numpad9" },
	{ onyx::Key::NumpadDecimal, "NumpadDecimal" },
	{ onyx::Key::NumpadDivide, "NumpadDivide" },
	{ onyx::Key::NumpadMultiply, "NumpadMultiply" },
	{ onyx::Key::NumpadSubtract, "NumpadSubtract" },
	{ onyx::Key::NumpadAdd, "NumpadAdd" },
	{ onyx::Key::NumpadEnter, "NumpadEnter" },
	{ onyx::Key::NumpadEqual, "NumpadEqual" },
	{ onyx::Key::LeftShift, "LeftShift" },
	{ onyx::Key::LeftControl, "LeftControl" },
	{ onyx::Key::LeftAlt, "LeftAlt" },
	{ onyx::Key::LeftSuper, "LeftSuper" },
	{ onyx::Key::RightShift, "RightShift" },
	{ onyx::Key::RightControl, "RightControl" },
	{ onyx::Key::RightAlt, "RightAlt" },
	{ onyx::Key::RightSuper, "RightSuper" },
	{ onyx::Key::Menu, "Menu" },
	{ onyx::Key::MaxKey, "MaxKey" }
};

const std::unordered_map<const char*, onyx::MouseButton> onyx::InputHandler::str_to_button_map = {
	{ "Null", onyx::MouseButton::Null },
	{ "Unknown", onyx::MouseButton::Unknown },
	{ "Button1", onyx::MouseButton::Button1 },
	{ "Button2", onyx::MouseButton::Button2 },
	{ "Button3", onyx::MouseButton::Button3 },
	{ "Button4", onyx::MouseButton::Button4 },
	{ "Button5", onyx::MouseButton::Button5 },
	{ "Button6", onyx::MouseButton::Button6 },
	{ "Button7", onyx::MouseButton::Button7 },
	{ "Button8", onyx::MouseButton::Button8 },
	{ "Left", onyx::MouseButton::Left },
	{ "Right", onyx::MouseButton::Right },
	{ "Middle", onyx::MouseButton::Middle },
	{ "SideBack", onyx::MouseButton::SideBack },
	{ "SideFront", onyx::MouseButton::SideFront },
	{ "MaxButton", onyx::MouseButton::MaxButton }
};

const std::unordered_map<onyx::MouseButton, const char*> onyx::InputHandler::button_to_str_map = {
	{ onyx::MouseButton::Null, "Null" },
	{ onyx::MouseButton::Unknown, "Unknown" },
	{ onyx::MouseButton::Button1, "Button1" },
	{ onyx::MouseButton::Button2, "Button2" },
	{ onyx::MouseButton::Button3, "Button3" },
	{ onyx::MouseButton::Button4, "Button4" },
	{ onyx::MouseButton::Button5, "Button5" },
	{ onyx::MouseButton::Button6, "Button6" },
	{ onyx::MouseButton::Button7, "Button7" },
	{ onyx::MouseButton::Button8, "Button8" },
	{ onyx::MouseButton::Left, "Left" },
	{ onyx::MouseButton::Right, "Right" },
	{ onyx::MouseButton::Middle, "Middle" },
	{ onyx::MouseButton::SideBack, "SideBack" },
	{ onyx::MouseButton::SideFront, "SideFront" },
	{ onyx::MouseButton::MaxButton, "MaxButton" }
};

std::mutex onyx::InputHandler::mtx_char_to_key_map;
std::mutex onyx::InputHandler::mtx_key_to_char_map;
std::mutex onyx::InputHandler::mtx_str_to_key_map;
std::mutex onyx::InputHandler::mtx_key_to_str_map;
std::mutex onyx::InputHandler::mtx_str_to_button_map;
std::mutex onyx::InputHandler::mtx_button_to_str_map;

onyx::InputHandler::InputHandler()
{
	this->p_win = nullptr;
	this->p_key_callback = nullptr;
	this->p_mouse_button_callback = nullptr;
	this->p_mouse_pos_callback = nullptr;
	this->p_scroll_callback = nullptr;
	this->p_joystick_callback = nullptr;

	for (int i = 0; i < (int)onyx::Key::MaxKey; i++)
	{
		this->keys[i] = onyx::KeyState::Untouched;
		this->keys_tapped[i] = false;
		this->key_cooldowns[i] = 0.0f;
		this->set_key_cooldowns[i] = 0.0f;
	}

	for (int i = 0; i < (int)onyx::MouseButton::MaxButton; i++)
	{
		this->buttons[i] = onyx::KeyState::Untouched;
		this->buttons_tapped[i] = false;
		this->button_cooldowns[i] = 0.0f;
		this->set_button_cooldowns[i] = 0.0f;
	}

	this->mouse_pos = DVec2(0.0f);
	this->last_mouse_pos = DVec2(0.0f);
	this->mouse_deltas = DVec2(0.0f);

	this->cursor_lock = false;
	this->scroll_this_frame = false;

	for (int jid = GLFW_JOYSTICK_1; jid <= GLFW_JOYSTICK_16; jid++)
	{
		if (glfwJoystickIsGamepad(jid)) this->gamepads.push_back(Gamepad(jid));
	}

	this->repeated_key = onyx::Key::Null;
}

void onyx::InputHandler::update()
{
	for (bool& tapped : this->keys_tapped) tapped = false;
	for (bool& tapped : this->buttons_tapped) tapped = false;
	this->keys_tapped_set.clear();
	this->buttons_tapped_set.clear();

	this->scroll_this_frame = false;
	glfwPollEvents();

	this->mouse_deltas.set(this->mouse_pos.get_x() - this->last_mouse_pos.get_x(), this->mouse_pos.get_y() - this->last_mouse_pos.get_y());
	this->last_mouse_pos = this->mouse_pos;
	if (!this->scroll_this_frame) this->scroll_deltas.set(0.0, 0.0);

	for (Gamepad& gp : this->gamepads)
	{
		if (gp.is_connected()) gp.update();
	}

	if (this->p_win == nullptr)
	{
		onyx_err(Error{
				.source_function = "onyx::InputHandler::update()",
				.message = "Window pointer is null.",
				.how_to_fix = "Make sure the input handler was linked to a window (Window::link_input_handler())."
			}
		);
		return;
	}

	for (onyx::Key key : this->active_key_cooldowns)
	{
		if (this->key_cooldowns[(int)key] >= 0) this->key_cooldowns[(int)key] -= this->p_win->delta_time;
	}

	for (onyx::MouseButton button : this->active_button_cooldowns)
	{
		if (this->button_cooldowns[(int)button] >= 0) this->button_cooldowns[(int)button] -= this->p_win->delta_time;
	}

	this->p_win->num_frames_input_not_updated = 0;
}

onyx::Key onyx::InputHandler::char_to_key(char c)
{
	InputHandler::mtx_char_to_key_map.lock();
	auto it = InputHandler::char_to_key_map.find(c);
	if (it != InputHandler::char_to_key_map.end())
	{
		InputHandler::mtx_char_to_key_map.unlock();
		return it->second;
	}
	InputHandler::mtx_char_to_key_map.unlock();

	onyx_warn(Warning{
			.source_function = "onyx::InputHandler::char_to_key(char)",
			.message = "Character not found in map, returning onyx::Key::Unknown.",
			.how_to_fix = "Make sure the character is in the map.",
			.severity = onyx::Warning::Severity::Low
		}
	);
	return onyx::Key::Unknown;
}

char onyx::InputHandler::key_to_char(onyx::Key key)
{
	InputHandler::mtx_key_to_char_map.lock();
	auto it = InputHandler::key_to_char_map.find(key);
	if (it != InputHandler::key_to_char_map.end()) 
	{
		InputHandler::mtx_key_to_char_map.unlock();
		return it->second;
	}
	InputHandler::mtx_key_to_char_map.unlock();

	onyx_warn(Warning{
			.source_function = "onyx::InputHandler::key_to_char(onyx::Key)",
			.message = "Key not found in map, returning ' '.",
			.how_to_fix = "Make sure the key is in the map.",
			.severity = onyx::Warning::Severity::Low
		}
	);
	return ' ';
}

onyx::Key onyx::InputHandler::str_to_key(const char* str)
{
	InputHandler::mtx_str_to_key_map.lock();
	auto it = InputHandler::str_to_key_map.find(str);
	if (it != InputHandler::str_to_key_map.end()) 
	{
		InputHandler::mtx_str_to_key_map.unlock();
		return it->second;
	}
	InputHandler::mtx_str_to_key_map.unlock();

	onyx_warn(Warning{
			.source_function = "onyx::InputHandler::str_to_key(const char*)",
			.message = "String not found in map, returning onyx::Key::Unknown.",
			.how_to_fix = "Make sure the string is in the map.",
			.severity = onyx::Warning::Severity::Low
		}
	);
	return onyx::Key::Unknown;
}

const char* onyx::InputHandler::key_to_str(onyx::Key key)
{
	InputHandler::mtx_key_to_str_map.lock();
	auto it = InputHandler::key_to_str_map.find(key);
	if (it != InputHandler::key_to_str_map.end()) 
	{
		InputHandler::mtx_key_to_str_map.unlock();
		return it->second;
	}
	InputHandler::mtx_key_to_str_map.unlock();

	onyx_warn(Warning{
			.source_function = "onyx::InputHandler::key_to_str(onyx::Key)",
			.message = "Key not found in map, returning \"Unknown\".",
			.how_to_fix = "Make sure the key is in the map.",
			.severity = onyx::Warning::Severity::Low
		}
	);
	return "Unknown";
}

onyx::MouseButton onyx::InputHandler::str_to_mouse_button(const char* str)
{
	InputHandler::mtx_str_to_button_map.lock();
	auto it = InputHandler::str_to_button_map.find(str);
	if (it != InputHandler::str_to_button_map.end()) 
	{
		InputHandler::mtx_str_to_button_map.unlock();
		return it->second;
	}
	InputHandler::mtx_str_to_button_map.unlock();

	onyx_warn(Warning{
			.source_function = "onyx::InputHandler::str_to_mouse_button(const char*)",
			.message = "String not found in map, returning onyx::MouseButton::Unknown.",
			.how_to_fix = "Make sure the string is in the map.",
			.severity = onyx::Warning::Severity::Low
		}
	);
	return onyx::MouseButton::Unknown;
}

const char* onyx::InputHandler::mouse_button_to_str(onyx::MouseButton button)
{
	InputHandler::mtx_button_to_str_map.lock();
	auto it = InputHandler::button_to_str_map.find(button);
	if (it != InputHandler::button_to_str_map.end()) 
	{
		InputHandler::mtx_button_to_str_map.unlock();
		return it->second;
	}
	InputHandler::mtx_button_to_str_map.unlock();

	onyx_warn(Warning{
			.source_function = "onyx::InputHandler::mouse_button_to_str(onyx::MouseButton)",
			.message = "Button not found in map, returning \"Unknown\".",
			.how_to_fix = "Make sure the button is in the map.",
			.severity = onyx::Warning::Severity::Low
		}
	);
	return "Unknown";
}

const std::unordered_set<onyx::Key>& onyx::InputHandler::get_keys_tapped() const
{
	return this->keys_tapped_set;
}

const std::unordered_set<onyx::Key>& onyx::InputHandler::get_keys_down() const
{
	return this->keys_down_set;
}

const std::unordered_set<onyx::MouseButton>& onyx::InputHandler::get_mouse_buttons_tapped() const
{
	return this->buttons_tapped_set;
}

const std::unordered_set<onyx::MouseButton>& onyx::InputHandler::get_mouse_buttons_down() const
{
	return this->buttons_down_set;
}

onyx::Key onyx::InputHandler::get_repeated_key() const
{
	return this->repeated_key;
}

onyx::KeyState onyx::InputHandler::get_key_state(onyx::Key key) const
{
	return this->keys[(int)key];
}

bool onyx::InputHandler::is_key_pressed(onyx::Key _key)
{
	int key = (int)_key;
	if (key < 0) return false;
	bool retval = this->key_cooldowns[key] <= 0 ? this->keys[key] == onyx::KeyState::Press : false;
	if (retval) this->key_cooldowns[key] = this->set_key_cooldowns[key];
	return retval;
}

bool onyx::InputHandler::is_key_tapped(onyx::Key _key) const
{
	int key = (int)_key;
	if (key < 0) return false;
	return this->keys_tapped[key];
}

bool onyx::InputHandler::is_key_repeated(onyx::Key _key)
{
	int key = (int)_key;
	if (key < 0) return false;
	bool retval = this->key_cooldowns[key] <= 0 ? this->keys[key] == onyx::KeyState::Repeat : false;
	if (retval) this->key_cooldowns[key] = this->set_key_cooldowns[key];
	return retval;
}

bool onyx::InputHandler::is_key_down(onyx::Key _key)
{
	int key = (int)_key;
	if (key < 0) return false;
	bool retval = this->key_cooldowns[key] <= 0 ? this->keys[key] == onyx::KeyState::Press || this->keys[key] == onyx::KeyState::Repeat : false;
	if (retval) this->key_cooldowns[key] = this->set_key_cooldowns[key];
	return retval;
}

bool onyx::InputHandler::is_key_tapped_or_repeated(onyx::Key key)
{
	return is_key_tapped(key) || is_key_repeated(key);
}

onyx::KeyState onyx::InputHandler::get_mouse_button_state(onyx::MouseButton _button) const
{
	int button = (int)_button;
	return this->buttons[button];
}

bool onyx::InputHandler::is_mouse_button_pressed(onyx::MouseButton _button)
{
	int button = (int)_button;
	if (button < 0) return false;
	bool retval = this->button_cooldowns[button] <= 0 ? this->buttons[button] == onyx::KeyState::Press : false;
	if (retval) this->button_cooldowns[button] = this->set_button_cooldowns[button];
	return retval;
}

bool onyx::InputHandler::is_mouse_button_tapped(onyx::MouseButton _button) const
{
	int button = (int)_button;
	if (button < 0) return false;
	return this->buttons_tapped[button];
}

bool onyx::InputHandler::is_mouse_button_repeated(onyx::MouseButton _button)
{
	int button = (int)_button;
	if (button < 0) return false;
	bool retval = this->button_cooldowns[button] <= 0 ? this->buttons[button] == onyx::KeyState::Repeat : false;
	if (retval) this->button_cooldowns[button] = this->set_button_cooldowns[button];
	return retval;
}

bool onyx::InputHandler::is_mouse_button_down(onyx::MouseButton _button)
{
	int button = (int)_button;
	if (button < 0) return false;
	bool retval = this->button_cooldowns[button] <= 0 ? this->buttons[button] == onyx::KeyState::Press || this->buttons[button] == onyx::KeyState::Repeat : false;
	if (retval) this->button_cooldowns[button] = this->set_button_cooldowns[button];
	return retval;
}

void onyx::InputHandler::set_key_cooldown(onyx::Key key, float cooldown)
{
	this->active_key_cooldowns.push_back(key);
	this->set_key_cooldowns[(int)key] = cooldown;
}

void onyx::InputHandler::set_mouse_button_cooldown(onyx::MouseButton button, float cooldown)
{
	this->active_button_cooldowns.push_back(button);
	this->set_button_cooldowns[(int)button] = cooldown;
}

void onyx::InputHandler::set_cursor_lock(bool lock)
{
	this->cursor_lock = lock;
	glfwSetInputMode(this->p_win->p_glfw_win, GLFW_CURSOR, lock ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
}

void onyx::InputHandler::toggle_cursor_lock()
{
	set_cursor_lock(!this->cursor_lock);
}

void onyx::InputHandler::set_key_callback(KeyCallbackFn callback)
{
	this->p_key_callback = callback;
}

void onyx::InputHandler::set_mouse_button_callback(MouseButtonCallbackFn callback)
{
	this->p_mouse_button_callback = callback;
}

void onyx::InputHandler::set_mouse_pos_callback(MousePosCallbackFn callback)
{
	this->p_mouse_pos_callback = callback;
}

void onyx::InputHandler::set_scroll_callback(ScrollCallbackFn callback)
{
	this->p_scroll_callback = callback;
}

void onyx::InputHandler::set_joystick_callback(JoystickCallbackFn callback)
{
	this->p_joystick_callback = callback;
}

bool onyx::InputHandler::is_cursor_locked() const
{
	return this->cursor_lock;
}

void onyx::InputHandler::refresh_gamepads()
{
	for (int jid = GLFW_JOYSTICK_1; jid <= GLFW_JOYSTICK_16; jid++)
	{
		if (glfwJoystickIsGamepad(jid))
		{
			bool found = false;
			for (Gamepad& gamepad : this->gamepads)
			{
				if (gamepad.get_glfw_id() == jid)
				{
					found = true;
					break;
				}
			}

			if (!found) this->gamepads.push_back(Gamepad(jid));
		}
	}
}

const onyx::math::DVec2& onyx::InputHandler::get_mouse_pos() const
{
	return this->mouse_pos;
}

const onyx::math::DVec2& onyx::InputHandler::get_mouse_deltas() const
{
	return this->mouse_deltas;
}

const onyx::math::DVec2& onyx::InputHandler::get_scroll_deltas() const
{
	return this->scroll_deltas;
}

const std::vector<onyx::Gamepad>& onyx::InputHandler::get_gamepads() const
{
	return this->gamepads;
}

#ifdef ONYX_OS_WINDOWS
	bool onyx::InputHandler::is_caps_lock_on()
	{
		return GetKeyState(VK_CAPITAL) & 1;
	}

	bool onyx::InputHandler::is_num_lock_on()
	{
		return GetKeyState(VK_NUMLOCK) & 1;
	}

	bool onyx::InputHandler::is_scroll_lock_on()
	{
		return GetKeyState(VK_SCROLL) & 1;
	}

#elif defined(ONYX_OS_LINUX)
	bool onyx::InputHandler::is_caps_lock_on()
	{
		Display* d = XOpenDisplay(NULL);
		if (!d) return false;
		u32 n;
		XkbGetIndicatorState(d, XkbUseCoreKbd, &n);
		XCloseDisplay(d);
		return n & 0x01;
	}

	bool onyx::InputHandler::is_num_lock_on()
	{
		Display* d = XOpenDisplay(NULL);
		if (!d) return false;
		u32 n;
		XkbGetIndicatorState(d, XkbUseCoreKbd, &n);
		XCloseDisplay(d);
		return n & 0x02;
	}

	bool onyx::InputHandler::is_scroll_lock_on()
	{
		Display* d = XOpenDisplay(NULL);
		if (!d) return false;
		u32 n;
		XkbGetIndicatorState(d, XkbUseCoreKbd, &n);
		XCloseDisplay(d);
		return n & 0x04;
	}

#elif defined(ONYX_OS_MAC)
	bool onyx::InputHandler::is_caps_lock_on()
	{
		return CGEventSourceKeyState(kCGEventSourceStateHIDSystemState, kVK_CapsLock);
	}

	bool onyx::InputHandler::is_num_lock_on()
	{
		return false;
	}

	bool onyx::InputHandler::is_scroll_lock_on()
	{
		return false;
	}

#else
	bool onyx::InputHandler::is_caps_lock_on()
	{
		return false;
	}

	bool onyx::InputHandler::is_num_lock_on()
	{
		return false;
	}

	bool onyx::InputHandler::is_scroll_lock_on()
	{
		return false;
	}

#endif

void onyx::InputHandler::key_callback(int key, int scancode, int action, int mods)
{
	this->keys[key] = (onyx::KeyState)action;
	if (action == GLFW_PRESS) 
	{
		this->keys_tapped[key] = true;

		this->keys_tapped_set.insert((onyx::Key)key);
		this->keys_down_set.insert((onyx::Key)key);
	}
	else if (action == GLFW_REPEAT)
	{
		this->repeated_key = (onyx::Key)key;
	}
	else if (action == GLFW_RELEASE)
	{
		this->keys_down_set.erase((onyx::Key)key);
		if (this->repeated_key == (onyx::Key)key) this->repeated_key = onyx::Key::Null;
	}

	if (this->p_key_callback) this->p_key_callback(key, scancode, action, mods);
}

void onyx::InputHandler::mouse_button_callback(int button, int action, int mods)
{
	this->buttons[button] = (onyx::KeyState)action;
	if (action == GLFW_PRESS) 
	{
		this->buttons_tapped[button] = true;

		this->buttons_tapped_set.insert((onyx::MouseButton)button);
		this->buttons_down_set.insert((onyx::MouseButton)button);
	}
	else if (action == GLFW_RELEASE)
	{
		this->buttons_down_set.erase((onyx::MouseButton)button);
	}

	if (this->p_mouse_button_callback) this->p_mouse_button_callback(button, action, mods);
}

void onyx::InputHandler::mouse_pos_callback(double x, double y)
{
	this->mouse_pos.set(x, y);

	if (this->p_mouse_pos_callback) this->p_mouse_pos_callback(x, y);
}

void onyx::InputHandler::scroll_callback(double dx, double dy)
{
	this->scroll_deltas.set(dx, dy);
	this->scroll_this_frame = true;

	if (this->p_scroll_callback) this->p_scroll_callback(dx, dy);
}

void onyx::InputHandler::joystick_callback(int jid, int event)
{
	if (!glfwJoystickIsGamepad(jid)) return;

	if (this->p_joystick_callback != nullptr) this->p_joystick_callback(jid, event);

	bool found = false;
	for (Gamepad& gamepad : this->gamepads)
	{
		if (gamepad.get_glfw_id() == jid)
		{
			found = true;
			break;
		}
	}

	if (!found && event == GLFW_CONNECTED) this->gamepads.push_back(Gamepad(jid));
	else if (found && event == GLFW_DISCONNECTED)
	{
		Gamepad* p_gp = (Gamepad*)glfwGetJoystickUserPointer(jid);
		if (p_gp != nullptr)
		{
			p_gp->state.buttons[(int)GamepadButton::A] = GLFW_RELEASE;
			p_gp->state.buttons[(int)GamepadButton::B] = GLFW_RELEASE;
			p_gp->state.buttons[(int)GamepadButton::X] = GLFW_RELEASE;
			p_gp->state.buttons[(int)GamepadButton::Y] = GLFW_RELEASE;
			p_gp->state.buttons[(int)GamepadButton::LeftBumper] = GLFW_RELEASE;
			p_gp->state.buttons[(int)GamepadButton::RightBumper] = GLFW_RELEASE;
			p_gp->state.buttons[(int)GamepadButton::Back] = GLFW_RELEASE;
			p_gp->state.buttons[(int)GamepadButton::Start] = GLFW_RELEASE;
			p_gp->state.buttons[(int)GamepadButton::Guide] = GLFW_RELEASE;
			p_gp->state.buttons[(int)GamepadButton::LeftStick] = GLFW_RELEASE;
			p_gp->state.buttons[(int)GamepadButton::RightStick] = GLFW_RELEASE;
			p_gp->state.buttons[(int)GamepadButton::DpadUp] = GLFW_RELEASE;
			p_gp->state.buttons[(int)GamepadButton::DpadRight] = GLFW_RELEASE;
			p_gp->state.buttons[(int)GamepadButton::DpadDown] = GLFW_RELEASE;
			p_gp->state.buttons[(int)GamepadButton::DpadLeft] = GLFW_RELEASE;

			p_gp->state.axes[(int)GamepadAxis::LeftX] = 0.0f;
			p_gp->state.axes[(int)GamepadAxis::LeftY] = 0.0f;
			p_gp->state.axes[(int)GamepadAxis::RightX] = 0.0f;
			p_gp->state.axes[(int)GamepadAxis::RightY] = 0.0f;
			p_gp->state.axes[(int)GamepadAxis::LeftTrigger] = 0.0f;
			p_gp->state.axes[(int)GamepadAxis::RightTrigger] = 0.0f;
		}
	}
}
