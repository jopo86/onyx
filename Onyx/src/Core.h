#pragma once

#include <iostream>

#include "ErrorHandler.h"

/*
	@file A header file containing useful definitions used by the Onyx library as well as the user.
 */

#define ONYX_VERSION_MAJOR		1
#define ONYX_VERSION_MINOR		0
#define ONYX_VERSION_PATCH		0

#define ONYX_PRE_RELEASE_NUM	0

#define ONYX_ALPHA              false
#define ONYX_BETA				false
#define ONYX_RELEASE_CANDIDATE	false
#define ONYX_STABLE	            true

//#define ONYX_GL_DEBUG_LOW
//#define ONYX_GL_DEBUG_MED
//#define ONYX_GL_DEBUG_HIGH

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
typedef char								byte;
typedef unsigned char						ubyte;
typedef unsigned short						ushort;
typedef unsigned int						uint;
typedef unsigned long						ulong;
typedef unsigned long long					ulonglong;

const char* _glErrorToString(uint errorCode);
uint _glCheckError(const std::string& file, int line);

#define glErrorToString(uint) _glErrorToString(uint)
#define glCheckError() _glCheckError(__FILE__, __LINE__)

/*
	@brief A namespace for global Onyx functions/settings.
 */
namespace Onyx
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
		@brief Definitions for keys on a keyboard.
		Used for polling input from an InputHandler object.
	 */
	enum class Key
	{
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
		MaxKey = Menu
	};

	/*
		@brief Definitions for mouse buttons.
		Used for polling input from an InputHandler object.
	 */
	enum class MouseButton
	{
		Unknown = -1,
		Button1 = 0,
		Button2 = 1,
		Button3 = 2,
		Button4 = 3,
		Button5 = 4,
		Button6 = 5,
		Button7 = 6,
		Button8 = 7,
		Left = Button1, // @brief Identical to `MouseButton::Button1`
		Right = Button2, // @brief Identical to `MouseButton::Button2`
		Middle = Button3, // @brief Identical to `MouseButton::Button3`
		SideBack = Button4, // @brief Identical to `MouseButton::Button4`
		SideFront = Button5, // @brief Identical to `MouseButton::Button5`
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
		Cross = A, // @brief Identical to `GamepadButton::A`
		Circle = B, // @brief Identical to `GamepadButton::B`
		Square = X, // @brief Identical to `GamepadButton::X`
		Triangle = Y, // @brief Identical to `GamepadButton::Y`
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

	struct GLError
	{
		uint code = 0;
		std::string file = "";
		int line = 0;

		std::string toString() const;
	};

	/*
		@brief Initializes the Onyx library.
		Defines some essential variables that may cause errors in the future if undefined.
	 */
	void Init();

	/*
		@brief Initializes the Onyx library.
		Defines some essential variables that may cause errors in the future if undefined.
		Passes any initialization errors to the specified error handler.
		@param errorHandler The error handler to use (for the entire library).
	 */
	void Init(ErrorHandler& errorHandler);

	/*
		@brief Gets the major version (X.y.z) of the Onyx library.
		@return The major version number.
	 */
	int GetVersionMajor();

	/*
		@brief Gets the minor version (x.Y.z) of the Onyx library.
		@return The minor version number.
	 */
	int GetVersionMinor();

	/*
		@brief Gets the patch version (x.y.Z) of the Onyx library.
		@return The patch version number.
	 */
	int GetVersionPatch();

	/*
		@brief Gets whether this version of the Onyx library is in alpha.
		@return Whether the library is in alpha.
	 */
	bool IsAlpha();

	/*
		@brief Gets whether this version of the Onyx library is in beta.
		@return Whether the library is in beta.
	 */
	bool IsBeta();

	/*
		@brief Gets whether this version of the Onyx library is a release candidate.
		@return Whether the library is a release candidate.
	 */
	bool IsReleaseCandidate();

	/*
		@brief Gets whether this version of the Onyx library is stable.
		@return Whether the library is stable.
	 */
	bool IsStable();

	/*
		@brief Gets the version of the Onyx library as a string.
		@return The version number in the format "x.y.z-preRelease(?)".
	 */
	std::string GetVersionString();

	/*
		@brief Terminates the Onyx library.
		Frees space used by FreeType.
	 !  Does not dispose of any objects that may have been created.
	 */
	void Terminate();

	/*
	 @brief Starts a little demo of the library.
	 */
	void Demo();

	/*
		@brief Gets whether the library has been initialized.
		@return Whether Init() has been called.
	 */
	bool IsInitialized();

	/*
		@brief Gets whether OpenGL has been initialized.
		If a successful call to Window::init() was made, this should return true.
		@return Whether OpenGL has been initialized.
	 */
	bool IsOpenGLInitialized();

	/*
		@brief Sets the error handler to use for the library.
		@param errorHandler The error handler to use.
	 */
	void SetErrorHandler(ErrorHandler& errorHandler);

	/*
		@brief Sets the filepath to resources such as shader presets.
		This should be the folder that contains the 'shaders' folder.
		@param path The path of the resources folder. Doesn't matter if it has a slash at the end or not.
	 */
	void SetResourcePath(std::string path);

	/*
		@brief Sets the user pointer for the library.
		This is needs to be used for setting any callbacks that are member functions.
	 */
	void SetUserPtr(void* ptr);

	/*
		@brief Gets the filepath that resources such as shader presets are stored in.
		This function is used by the library when reading files.
		@return The path of the resources folder.
	 */
	const std::string& GetResourcePath();

	/*
		@brief Gets a file path relative to the resource path.
		@param path The path relative to the resource path.
	 */
	std::string Resources(const std::string& path);

	/*
		@brief Gets the user pointer for the library.
		This is needs to be used for setting any callbacks that are member functions.
	 */
	void* GetUserPtr();

	/*
		@brief Gets the time (sec) since the library was initialized.
	 */
	double GetTime();

	/*
		@brief Returns the name of the Graphics Card / GPU.
		@param result A pointer to a boolean that will be set to true if the name was successfully retrieved, false otherwise.
		@return The name of the GPU.
	 */
	std::string GetGraphicsName(bool* result = nullptr);

	/*
		@brief Parent class for disposable objects.
	 */
	class Disposable
	{
	public:
		virtual void dispose() = 0;
	};
}
