#pragma once

#include <iostream>

#include "error_handler.h"

/*
	@file A header file containing useful definitions used by the Onyx library as well as the user.
 */

#define ONYX_VERSION_MAJOR		1
#define ONYX_VERSION_MINOR		7
#define ONYX_VERSION_PATCH		1

#define ONYX_PRE_RELEASE_NUM	0

#define ONYX_ALPHA              false
#define ONYX_BETA				false
#define ONYX_RELEASE_CANDIDATE	false
#define ONYX_STABLE	            true

//#define ONYX_GL_DEBUG_LOW
//#define ONYX_GL_DEBUG_MED
// #define ONYX_GL_DEBUG_HIGH

/*
	Definitions for system info.
 */
#if defined(__LP64__) || defined(_LP64) || defined(__amd64__) || defined(__x86_64__) || defined(_M_X64) || defined(_WIN64) || defined(__ia64__) || defined(_M_IA64) || defined(__aarch64__) || defined(__powerpc64__) || defined(__ppc64__) || defined(__PPC64__) || defined(__mips64__) || defined(__mips64) || defined(__mips64) || defined(__sparc64__) || defined(__arch64__)
#define ONYX_ARCH_64
#elif defined(__i386__) || defined(_M_IX86) || defined(__arm__) || defined(__mips__) || defined(__mips) || defined(__sparc__) || defined(__PPC__) || defined(__ppc__) || defined(__powerpc__) || defined(__powerpc) || defined(__ppc64__) || defined(__PPC64__) || defined(__ppc64) || defined(__PPC64) || defined(__mip) || defined(__mips) || defined(__mips__)
#define ONYX_ARCH_32
#else
#define ONYX_ARCH_UNKNOWN
#endif

#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
#define ONYX_OS_WINDOWS
#elif defined(__linux__) || defined(__linux) || defined(linux) || defined(__gnu_linux__)
#define ONYX_OS_LINUX
#elif defined(__APPLE__) || defined(__MACH__)
#define ONYX_OS_MAC
#else
#define ONYX_OS_UNKNOWN
#endif

#ifdef ONYX_ARCH_64
#define ONYX_BUFFER_SIZE					1024
#elif defined(ONYX_ARCH_32)
#define ONYX_BUFFER_SIZE					512
#else
#define ONYX_BUFFER_SIZE					256
#endif

  /*
   Type definitions for convenience.
   These are used by the library, but can be used by the user as well.
   */
typedef unsigned char						u8;
typedef unsigned short						u16;
typedef unsigned int						u32;
typedef unsigned long						usize;
typedef unsigned long long					u64;

const char* gl_error_to_string(u32 error_code);
u32 gl_check_error(const std::string& file, int line);

#define GL_ERROR_TO_STRING(u32) gl_error_to_string(u32)
#define GL_CHECK_ERROR() gl_check_error(__FILE__, __LINE__)

/*
	@brief A namespace for global Onyx functions/settings.
 */
namespace onyx
{
	/*
		@brief Definitions for the different vertex formats.
		Used for the VertexArray class.
	 */
	enum class VertexFormat
	{
		Null,
		P,
		PN,
		PC,
		PT,
		PCT,
		PNT,
		PNC,
		PNCT
	};

	/*
		@brief Definitions for the different projection types.
		Used for creating a Projection object, which is assigned to a Camera object.
	 */
	enum class ProjectionType
	{
		Null,
		Orthographic,
		Perspective
	};

	/*
		@brief Definitions for the different texture wrap options.
		Used for creating a Texture object.
	 */
	enum class TextureWrap
	{
		Null,
		Repeat,
		MirroredRepeat,
		ClampToEdge
	};

	/*
		@brief Definitions for the different texture filter options.
	 */
	enum class TextureFilter
	{
		Null,
		Nearest,
		Linear
	};

	/*
		@brief Definitions for key states.
		Used for polling input from an InputHandler object.
	 */
	enum KeyState
	{
		Untouched = -1,
		Release = 0,
		Press = 1,
		Repeat = 2
	};

	/*
		@brief Definitions for keys on a keyboard.
		Used for polling input from an InputHandler object.
	 */
	enum class Key
	{
		Null = 0,
		Unknown = -1,
		Space = 32,
		Apostrophe = 39,
		Comma = 44,
		Minus = 45,
		Period = 46,
		Slash = 47,
		Num0 = 48,
		Num1 = 49,
		Num2 = 50,
		Num3 = 51,
		Num4 = 52,
		Num5 = 53,
		Num6 = 54,
		Num7 = 55,
		Num8 = 56,
		Num9 = 57,
		Semicolon = 59,
		Equal = 61,
		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,
		LeftBracket = 91,
		Backslash = 92,
		RightBracket = 93,
		GraveAccent = 96,
		World1 = 161,
		World2 = 162,
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		ArrowRight = 262,
		ArrowLeft = 263,
		ArrowDown = 264,
		ArrowUp = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,
		Numpad0 = 320,
		Numpad1 = 321,
		Numpad2 = 322,
		Numpad3 = 323,
		Numpad4 = 324,
		Numpad5 = 325,
		Numpad6 = 326,
		Numpad7 = 327,
		Numpad8 = 328,
		Numpad9 = 329,
		NumpadDecimal = 330,
		NumpadDivide = 331,
		NumpadMultiply = 332,
		NumpadSubtract = 333,
		NumpadAdd = 334,
		NumpadEnter = 335,
		NumpadEqual = 336,
		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348,

		Application = Menu, 			// @brief Alias for `Key::Menu`
		App = Menu, 					// @brief Alias for `Key::Menu`

		Esc = Escape, 					// @brief Alias for `Key::Escape`
		Return = Enter, 				// @brief Alias for `Key::Enter`

		LCtrl = LeftControl, 			// @brief Alias for `Key::LeftControl`
		RCtrl = RightControl, 			// @brief Alias for `Key::RightControl`
		LShift = LeftShift, 			// @brief Alias for `Key::LeftShift`
		RShift = RightShift, 			// @brief Alias for `Key::RightShift`
		LAlt = LeftAlt, 				// @brief Alias for `Key::LeftAlt`
		RAlt = RightAlt, 				// @brief Alias for `Key::RightAlt`
		LSuper = LeftSuper, 			// @brief Alias for `Key::LeftSuper`
		RSuper = RightSuper, 			// @brief Alias for `Key::RightSuper`
		LeftCommand = LeftSuper, 		// @brief Alias for `Key::LeftSuper`
		RightCommand = RightSuper, 		// @brief Alias for `Key::RightSuper`
		LCmd = LeftSuper, 				// @brief Alias for `Key::LeftSuper`
		RCmd = RightSuper, 				// @brief Alias for `Key::RightSuper`
		LeftWindows = LeftSuper, 		// @brief Alias for `Key::LeftSuper`
		RightWindows = RightSuper, 		// @brief Alias for `Key::RightSuper`
		LWin = LeftSuper, 				// @brief Alias for `Key::LeftSuper`
		RWin = RightSuper, 				// @brief Alias for `Key::RightSuper`
		Windows = LeftSuper, 			// @brief Alias for `Key::LeftSuper`
		Win = LeftSuper, 				// @brief Alias for `Key::LeftSuper`

		PrtSc = PrintScreen, 			// @brief Alias for `Key::PrintScreen`
		Ins = Insert, 					// @brief Alias for `Key::Insert`
		PgUp = PageUp, 					// @brief Alias for `Key::PageUp`
		PgDn = PageDown, 				// @brief Alias for `Key::PageDown`
		Del = Delete, 					// @brief Alias for `Key::Delete`

		Up = ArrowUp, 					// @brief Alias for `Key::ArrowUp`
		Down = ArrowDown, 				// @brief Alias for `Key::ArrowDown`
		Left = ArrowLeft, 				// @brief Alias for `Key::ArrowLeft`
		Right = ArrowRight, 			// @brief Alias for `Key::ArrowRight`

		MaxKey = Menu,
	};

	/*
		@brief Definitions for mouse buttons.
		Used for polling input from an InputHandler object.
	 */
	enum class MouseButton
	{
		Null = -2,
		Unknown = -1,
		Button1 = 0,
		Button2 = 1,
		Button3 = 2,
		Button4 = 3,
		Button5 = 4,
		Button6 = 5,
		Button7 = 6,
		Button8 = 7,

		Left = Button1, 				// @brief Alias for `MouseButton::Button1`
		Right = Button2, 				// @brief Alias for `MouseButton::Button2`
		Middle = Button3, 				// @brief Alias for `MouseButton::Button3`
		SideBack = Button4, 			// @brief Alias for `MouseButton::Button4`
		SideFront = Button5, 			// @brief Alias for `MouseButton::Button5`

		MaxButton = Button8
	};

	/*
		@brief Definitions for gamepad/controller buttons.
		Note that triggers are axes, not buttons.
		Used for polling input from a Gamepad object.
	 */
	enum class GamepadButton
	{
		A = 0,
		B = 1,
		X = 2,
		Y = 3,
		Cross = A, 						// @brief Alias for `GamepadButton::A`
		Circle = B, 					// @brief Alias for `GamepadButton::B`
		Square = X, 					// @brief Alias for `GamepadButton::X`
		Triangle = Y, 					// @brief Alias for `GamepadButton::Y`
		LeftBumper = 4,
		RightBumper = 5,
		Back = 6,
		Start = 7,
		Guide = 8,
		LeftStick = 9,
		RightStick = 10,
		DpadUp = 11,
		DpadRight = 11,
		DpadDown = 13,
		DpadLeft = 14,

		MaxButton = DpadLeft
	};

	/*
		@brief Definitions for gamepad/controller axes.
		These include the sticks and triggers.
		Used for polling input from a Gamepad object.
	 */
	enum class GamepadAxis
	{
		LeftX = 0,
		LeftY = 1,
		RightX = 2,
		RightY = 3,
		LeftTrigger = 4,
		RightTrigger = 5,

		MaxAxis = RightTrigger
	};

	/*
		@brief Definitions for standard cursor types.
	 */
	enum class CursorType
	{
		Null = -1,
		Custom = 0,
		Arrow = 0x00036001,					// @brief The regular arrowhead cursor.
		Ibeam = 0x00036002,					// @brief The text input I-beam cursor.
		Crosshair = 0x00036003,				// @brief The crosshair cursor.
		Hand = 0x00036004,					// @brief The pointing hand cursor.
		NotAllowed = 0x0003600A,			// @brief The not-allowed cursor. Usually a circle with a line through it.
		HorizontalResize = 0x00036005,		// @brief The horizontal resize/move arrow cursor. Usually a horizontal double-headed arrow.
		VerticalResize = 0x00036006,		// @brief The vertical resize/move arrow cursor. Usually a vertical double-headed arrow.
		DiagonalResizeTLBR = 0x00036007, 	// @brief The top-left to bottom-right resize/move arrow cursor. Usually a diagonal double-headed arrow.
		DiagonalResizeBLTR = 0x00036008, 	// @brief The bottom-left to top-right resize/move arrow cursor. Usually a diagonal double-headed arrow.
		AllResize = 0x00036009,				// @brief The all-directions resize/move arrow cursor. Usually a combined horizontal and vertical double-headed arrow or a grabbing hand.

		No = NotAllowed,					// @brief Alias for `CursorType::NotAllowed`
		Move = AllResize,					// @brief Alias for `CursorType::AllResize`
		Grab = AllResize,					// @brief Alias for `CursorType::AllResize`

		ResizeH = HorizontalResize,			// @brief Alias for `CursorType::HorizontalResize`
		ResizeV = VerticalResize,			// @brief Alias for `CursorType::VerticalResize`
		ResizeTLBR = DiagonalResizeTLBR,	// @brief Alias for `CursorType::DiagonalResizeTLBR`
		ResizeBLTR = DiagonalResizeBLTR,	// @brief Alias for `CursorType::DiagonalResizeBLTR`

		MaxCursor = AllResize
	};

	struct GLError
	{
		u32 code = 0;
		std::string file = "";
		int line = 0;

		std::string to_string() const;
	};

	/*
		@brief Initializes the Onyx library.
		Defines some essential variables that may cause errors in the future if undefined.
	 */
	void init();

	/*
		@brief Initializes the Onyx library.
		Defines some essential variables that may cause errors in the future if undefined.
		Passes any initialization errors to the specified error handler.
		@param error_handler The error handler to use (for the entire library).
	 */
	void init(ErrorHandler& error_handler);

	/*
		@brief Gets the major version (X.y.z) of the Onyx library.
		@return The major version number.
	 */
	int get_version_major();

	/*
		@brief Gets the minor version (x.Y.z) of the Onyx library.
		@return The minor version number.
	 */
	int get_version_minor();

	/*
		@brief Gets the patch version (x.y.Z) of the Onyx library.
		@return The patch version number.
	 */
	int get_version_patch();

	/*
		@brief Gets whether this version of the Onyx library is in alpha.
		@return Whether the library is in alpha.
	 */
	bool is_alpha();

	/*
		@brief Gets whether this version of the Onyx library is in beta.
		@return Whether the library is in beta.
	 */
	bool is_beta();

	/*
		@brief Gets whether this version of the Onyx library is a release candidate.
		@return Whether the library is a release candidate.
	 */
	bool is_release_candidate();

	/*
		@brief Gets whether this version of the Onyx library is stable.
		@return Whether the library is stable.
	 */
	bool is_stable();

	/*
		@brief Gets the version of the Onyx library as a string.
		@return The version number in the format "x.y.z-pre_release(?)".
	 */
	std::string get_version_string();

	/*
		@brief Terminates the Onyx library.
		Frees space used by FreeType.
	 !  Does not dispose of any objects that may have been created.
	 */
	void cleanup();

	/*
		@brief Gets the contents of the system clipboard.
		The clipboard is what contains copied text from the user.
		Use this function to 'paste' text.
		@return The contents of the system clipboard as a string.
	 */
	std::string get_clipboard_string();

	/*
		@brief Sets the text to copy to the clipboard.
		The clipboard is what contains copied text from the user.
		Use this function to 'copy' text.
		@param str The text to copy to the clipboard.
	 */
	void set_clipboard_string(const std::string& str);

	/*
		@brief Gets whether the library has been initialized.
		@return Whether init() has been called.
	 */
	bool is_initialized();

	/*
		@brief Gets whether OpenGL has been initialized.
		If a successful call to Window::init() was made, this should return true.
		@return Whether OpenGL has been initialized.
	 */
	bool is_opengl_initialized();

	/*
		@brief Sets the error handler to use for the library.
		@param error_handler The error handler to use.
	 */
	void set_error_handler(ErrorHandler& error_handler);

	/*
		@brief Sets the filepath that your own assets (models, textures, fonts) are loaded from.
		The library's built-in shaders are compiled into the binary and do not need this to be set.
		@param path The path of the resources folder. Doesn't matter if it has a slash at the end or not.
	 */
	void set_resource_path(std::string path);

	/*
		@deprecated Use the named user pointer system instead - `set_user_ptr(const std::string& name, void* ptr)`.
	 */
	[[deprecated("This function is deprecated and will be removed in the next major release. Use the named user pointer system instead - `set_user_ptr(const std::string& name, void* ptr)`.")]]
	void set_user_ptr(void* ptr);

	/*
		@brief Sets a user pointer for the library with the specified name.
		You can set as many user pointers with different names as you want.
		You can do whatever you want with this, but it is mainly used for callbacks.
		The user pointer system uses an unordered map, so the retrieval time is fast.
		If a user pointer with the specified name already exists, it will be overwritten.
		@param name The name of the user pointer.
		@param ptr The pointer to set.
	 */
	void set_user_ptr(const std::string& name, void* ptr);

	/*
		@brief Gets the filepath that your own assets (models, textures, fonts) are loaded from.
		@return The path of the resources folder.
	 */
	std::string get_resource_path();

	/*
		@brief Gets the per-user directory the library caches compiled shader program binaries in.
		This is a platform-appropriate cache location (%LOCALAPPDATA% on Windows,
		$XDG_CACHE_HOME or ~/.cache on Linux, ~/Library/Caches on macOS), not the install
		directory, which may be read-only. The cache is purely an optimization: deleting it
		only costs a one-time recompile, since the shader sources are built into the library.
		@return The path of the cache folder, with a trailing slash.
	 */
	std::string get_cache_path();

	/*
		@brief Gets a file path relative to the resource path.
		Alias for `res(const std::string& path)`.
		@param path The path relative to the resource path.
	 */
	std::string resources(const std::string& path);

	/*
		@brief Gets a file path relative to the resource path.
		Alias for `resources(const std::string& path)`.
		@param path The path relative to the resource path.
	 */
	std::string res(const std::string& path);

	/*
		@deprecated Use the named user pointer system instead - `get_user_ptr(const std::string& name)`.
	 */
	[[deprecated("This function is deprecated and will be removed in the next major release. Use the named user pointer system instead - `get_user_ptr(const std::string& name)`.")]]
	void* get_user_ptr();

	/*
		@brief Gets the user pointer for the library with the specified name.
		You can do whatever you want with this, but it is mainly used for callbacks.
		The user pointer system uses an unordered map, so the retrieval time is fast.
		If there is no error handler and no result argument provided, no error checking will be done.
		@param name The name of the user pointer.
		@param result A pointer to a boolean that will be set to true if the user pointer was successfully retrieved, false otherwise.
		@return The user pointer. An error will be thrown if no user pointer with the specified name exists.
	 */
	void* get_user_ptr(const std::string& name, bool* result = nullptr);

	/*
		@brief Gets the time (sec) since the library was initialized.
		@return The time, in seconds, since the library was initialized.
	 */
	double get_time();

	/*
		@brief Returns the name of the Graphics Card / GPU.
	 !	This function cannot be called before an OpenGL context has been created, so a window needs to be initialized before calling it.
		@param result A pointer to a boolean that will be set to true if the name was successfully retrieved, false otherwise.
		@return The name of the GPU.
	 */
	std::string get_graphics_name(bool* result = nullptr);

	/*
		@brief Checks whether the specified OpenGL extension is supported.
	 !	This function cannot be called before an OpenGL context has been created, so a window needs to be initialized before calling it.
		@param extension The name of the extension to check.
		@param result A pointer to a boolean that will be set to true if this function executed without error, false otherwise.
	 *	`result` is NOT the result of the extension check, only the return value is.
		@return Whether the extension is supported.
	 */
	bool is_extension_supported(const std::string& extension, bool* result = nullptr);

	/*
		@brief Stops the calling thread for the specified number of seconds.
		@param seconds The number of seconds to sleep for.
	 */
	void sleep(double seconds);

	/*
		@brief Parent class for disposable objects.
	 */
	class Disposable
	{
	public:
		/*
			@brief Gets whether the object has been disposed.
			@return True if dispose() has been called, false otherwise.
		 */
		bool is_disposed() const;

		/*
			@brief Destroys the object, freeing any used memory.
			Do not use the object after this is called.
		 */
		virtual void dispose() = 0;

	protected:
		bool disposed = false;
	};
}
