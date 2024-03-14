#pragma once

#include <string>

#include "ErrorHandler.h"

#include <ft2build.h>
#include FT_FREETYPE_H

/*
 * @file A header file containing useful definitions used by the Onyx library as well as the user.
 */

/*
 * Definitions for system info.
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
 * Definitions for vertex formats.
 * These are used to tell the MgMesh class how the array of vertices is formatted.
 * They allow specification of what types of vertices are in the array (V/C/T) and how they are ordered.
 * V = vertices, C = colors, T = texture coordinates
 */
#define ONYX_VERTEX_FORMAT_V					400
#define ONYX_VERTEX_FORMAT_VC					401
#define ONYX_VERTEX_FORMAT_CV					402
#define ONYX_VERTEX_FORMAT_VT					403
#define ONYX_VERTEX_FORMAT_TV					404
#define ONYX_VERTEX_FORMAT_VCT					405
#define ONYX_VERTEX_FORMAT_VTC					406
#define ONYX_VERTEX_FORMAT_CVT					407
#define ONYX_VERTEX_FORMAT_TVC					408
#define ONYX_VERTEX_FORMAT_CTV					409
#define ONYX_VERTEX_FORMAT_TCV					410

/*
 * Definitions for meshes.
 * Used by MgMeshPresets::GetIndices(int mesh)
 *									  ^^^^^^
 */
#define ONYX_MESH_TRIANGLE						411
#define ONYX_MESH_SQUARE						412
#define ONYX_MESH_RECT							413
#define ONYX_MESH_CUBE							414
#define ONYX_MESH_RECT_PRISM					415

/*
 * Definitions for projection types.
 */
#define ONYX_PROJECTION_TYPE_ORTHOGRAPHIC		416
#define ONYX_PROJECTION_TYPE_PERSPECTIVE		417

/*
 * Definitions for each key on a keyboard.
 * These are used to specify what the target key is when testing if a key is up/down by the MgInputHandler class.
 */
#define ONYX_KEY_UNKNOWN						-1
#define ONYX_KEY_SPACE							32
#define ONYX_KEY_APOSTROPHE						39
#define ONYX_KEY_COMMA							44
#define ONYX_KEY_MINUS							45
#define ONYX_KEY_PERIOD							46
#define ONYX_KEY_SLASH							47
#define ONYX_KEY_0								48
#define ONYX_KEY_1								49
#define ONYX_KEY_2								50
#define ONYX_KEY_3								51
#define ONYX_KEY_4								52
#define ONYX_KEY_5								53
#define ONYX_KEY_6								54
#define ONYX_KEY_7								55
#define ONYX_KEY_8								56
#define ONYX_KEY_9								57
#define ONYX_KEY_SEMICOLON						59
#define ONYX_KEY_EQUAL							61
#define ONYX_KEY_A								65
#define ONYX_KEY_B								66
#define ONYX_KEY_C								67
#define ONYX_KEY_D								68
#define ONYX_KEY_E								69
#define ONYX_KEY_F								70
#define ONYX_KEY_G								71
#define ONYX_KEY_H								72
#define ONYX_KEY_I								73
#define ONYX_KEY_J								74
#define ONYX_KEY_K								75
#define ONYX_KEY_L								76
#define ONYX_KEY_M								77
#define ONYX_KEY_N								78
#define ONYX_KEY_O								79
#define ONYX_KEY_P								80
#define ONYX_KEY_Q								81
#define ONYX_KEY_R								82
#define ONYX_KEY_S								83
#define ONYX_KEY_T								84
#define ONYX_KEY_U								85
#define ONYX_KEY_V								86
#define ONYX_KEY_W								87
#define ONYX_KEY_X								88
#define ONYX_KEY_Y								89
#define ONYX_KEY_Z								90
#define ONYX_KEY_LEFT_BRACKET					91
#define ONYX_KEY_BACKSLASH						92
#define ONYX_KEY_RIGHT_BRACKET					93
#define ONYX_KEY_GRAVE_ACCENT					96
#define ONYX_KEY_WORLD_1						161
#define ONYX_KEY_WORLD_2						162
#define ONYX_KEY_ESCAPE							256
#define ONYX_KEY_ENTER							257
#define ONYX_KEY_TAB							258
#define ONYX_KEY_BACKSPACE						259
#define ONYX_KEY_INSERT							260
#define ONYX_KEY_DELETE							261
#define ONYX_KEY_RIGHT							262
#define ONYX_KEY_LEFT							263
#define ONYX_KEY_DOWN							264
#define ONYX_KEY_UP								265
#define ONYX_KEY_PAGE_UP						266
#define ONYX_KEY_PAGE_DOWN						267
#define ONYX_KEY_HOME							268
#define ONYX_KEY_END							269
#define ONYX_KEY_CAPS_LOCK						280
#define ONYX_KEY_SCROLL_LOCK					281
#define ONYX_KEY_NUM_LOCK						282
#define ONYX_KEY_PRINT_SCREEN					283
#define ONYX_KEY_PAUSE							284
#define ONYX_KEY_F1								290
#define ONYX_KEY_F2								291
#define ONYX_KEY_F3								292
#define ONYX_KEY_F4								293
#define ONYX_KEY_F5								294
#define ONYX_KEY_F6								295
#define ONYX_KEY_F7								296
#define ONYX_KEY_F8								297
#define ONYX_KEY_F9								298
#define ONYX_KEY_F10							299
#define ONYX_KEY_F11							300
#define ONYX_KEY_F12							301
#define ONYX_KEY_F13							302
#define ONYX_KEY_F14							303
#define ONYX_KEY_F15							304
#define ONYX_KEY_F16							305
#define ONYX_KEY_F17							306
#define ONYX_KEY_F18							307
#define ONYX_KEY_F19							308
#define ONYX_KEY_F20							309
#define ONYX_KEY_F21							310
#define ONYX_KEY_F22							311
#define ONYX_KEY_F23							312
#define ONYX_KEY_F24							313
#define ONYX_KEY_F25							314
#define ONYX_KEY_NUMPAD_0						320
#define ONYX_KEY_NUMPAD_1						321
#define ONYX_KEY_NUMPAD_2						322
#define ONYX_KEY_NUMPAD_3						323
#define ONYX_KEY_NUMPAD_4						324
#define ONYX_KEY_NUMPAD_5						325
#define ONYX_KEY_NUMPAD_6						326
#define ONYX_KEY_NUMPAD_7						327
#define ONYX_KEY_NUMPAD_8						328
#define ONYX_KEY_NUMPAD_9						329
#define ONYX_KEY_NUMPAD_DECIMAL					330
#define ONYX_KEY_NUMPAD_DIVIDE					331
#define ONYX_KEY_NUMPAD_MULTIPLY				332
#define ONYX_KEY_NUMPAD_SUBTRACT				333
#define ONYX_KEY_NUMPAD_ADD						334
#define ONYX_KEY_NUMPAD_ENTER					335
#define ONYX_KEY_NUMPAD_EQUAL					336
#define ONYX_KEY_LEFT_SHIFT						340
#define ONYX_KEY_LEFT_CONTROL					341
#define ONYX_KEY_LEFT_ALT						342
#define ONYX_KEY_LEFT_SUPER						343
#define ONYX_KEY_RIGHT_SHIFT					344
#define ONYX_KEY_RIGHT_CONTROL					345
#define ONYX_KEY_RIGHT_ALT						346
#define ONYX_KEY_RIGHT_SUPER					347
#define ONYX_KEY_MENU							348
#define ONYX_MAX_KEY							ONYX_KEY_MENU

/*
 * Definitions for each button on a mouse.
 * These are used to specify what the target button is when testing if a mouse button is up/down by the MgInputHandler class.
 */
#define ONYX_MOUSE_BUTTON_1						0
#define ONYX_MOUSE_BUTTON_2						1
#define ONYX_MOUSE_BUTTON_3						2
#define ONYX_MOUSE_BUTTON_4						3
#define ONYX_MOUSE_BUTTON_5						4
#define ONYX_MOUSE_BUTTON_6						5
#define ONYX_MOUSE_BUTTON_7						6
#define ONYX_MOUSE_BUTTON_8						7
#define ONYX_MOUSE_BUTTON_LEFT					ONYX_MOUSE_BUTTON_1
#define ONYX_MOUSE_BUTTON_RIGHT					ONYX_MOUSE_BUTTON_2
#define ONYX_MOUSE_BUTTON_MIDDLE				ONYX_MOUSE_BUTTON_3
#define ONYX_MAX_MOUSE_BUTTON					ONYX_MOUSE_BUTTON_8

/*
 * Definitions for keystates.
 * Used by MgInputHandler.
 */
#define ONYX_KEYSTATE_UNTOUCHED				   -1
#define ONYX_KEYSTATE_RELEASE					0
#define ONYX_KEYSTATE_PRESS						1
#define ONYX_KEYSTATE_REPEAT					2

/*
 * Type definitions for convenience.
 * These are used by the library, but can be used by the user as well.
 */
typedef char								byte;
typedef unsigned char						ubyte;
typedef unsigned short						ushort;
typedef unsigned int						uint;
typedef unsigned long						ulong;
typedef unsigned long long					ulonglong;

/*
 * @brief A namespace for global Onyx functions/settings.
 */
namespace Onyx
{
	/*
	 * @brief Initializes the Onyx library.
	 * Defines some essential variables that may cause errors in the future if undefined.
	 */
	void Init();

	/*
	 * @brief Initializes the Onyx library.
	 * Defines some essential variables that may cause errors in the future if undefined.
	 * Passes any initialization errors to the specified error handler.
	 * @param errorHandler The error handler to use (not permanently, only for this function).
	 */
	void Init(ErrorHandler& errorHandler);

	/*
	 * @brief Terminates the Onyx library.
	 * Frees space used by FreeType.
	 ! Does not dispose of any objects that may have been created.
	 */
	void Terminate();

	/*
	 @brief Starts a little demo of the library. Work in progress.
	 */
	void Demo();

	/*
	 * @brief Gets whether the library has been initialized.
	 * @return Whether Init() has been called.
	 */
	bool IsInitialized();

	/*
	 * @brief Sets the filepath to resources such as shader presets.
	 * This should be the folder that contains the 'shaders' folder.
	 * @param path The path of the resources folder. Doesn't matter if it has a slash at the end or not.
	 */
	void SetResourcePath(std::string path);

	/*
	 * @brief Gets the filepath that resources such as shader presets are stored in.
	 * This function is used by the library when reading files.
	 * @return The path of the resources folder.
	 */
	std::string GetResourcePath();

	/*
	 * @brief Gets the FreeType library.
	 * This function is used by the library when rendering text.
	 * @return The FreeType library.
	 */
	FT_Library* GetFreeTypeLibrary();

	/*
	 * @brief Gets the time (sec) since the backends were initialized, so when the first window was initialized.
	 * Use for calculating delta time.
	 */
	double GetTime();

	/*
	 * @brief Parent class for disposable objects.
	 */
	class Disposable
	{
	public:
		virtual void dispose() = 0;
	};
}
