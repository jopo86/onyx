#include <onyx/core.hpp>

#include <string>
#include <unordered_map>
#include <atomic>
#include <thread>
#include <mutex>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <filesystem>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <stb_image.h>

#include <onyx/math_wrappers.hpp>
#include <onyx/window.hpp>
#include <onyx/input_handler.hpp>
#include <onyx/camera.hpp>
#include <onyx/projection.hpp>
#include <onyx/model.hpp>
#include <onyx/text_renderable.hpp>
#include <onyx/text_renderable_3d.hpp>
#include <onyx/file_utils.hpp>
#include "internal.hpp"

using onyx::math::Vec2, onyx::math::Vec3, onyx::math::Vec4;

namespace
{
	std::atomic<bool> initialized = false;
	std::atomic<bool> gl_initialized = false;
	std::atomic<onyx::ErrorHandler*> p_error_handler = nullptr;

	std::string resource_path;
	FT_Library ft;
	std::vector<std::pair<void*, void(*)(void*)>> mallocs;
	std::unordered_map<std::string, void*> user_ptrs;

	std::mutex mtx_resource_path;
	std::mutex mtx_ft;
	std::mutex mtx_mallocs;
	std::mutex mtx_user_ptrs;
}

void onyx_set_gl_init(bool val)
{
	gl_initialized = val;
}

FT_Library* onyx_get_ft()
{
	std::lock_guard lock(mtx_ft);
	return &ft;
}

void onyx_add_malloc_impl(void* ptr, void(*deleter)(void*))
{
	std::lock_guard lock(mtx_mallocs);
	mallocs.push_back(std::pair<void*, void(*)(void*)>(ptr, deleter));
}

void onyx_err(const onyx::Error& error)
{
	if (p_error_handler != nullptr) (*p_error_handler).err(error);
}

void onyx_warn(const onyx::Warning& warning)
{
	if (p_error_handler != nullptr) (*p_error_handler).warn(warning);
}

void onyx_glerr(const onyx::GLError& error)
{
	std::cout << error.to_string() << "\n\n";
}

const char* gl_error_to_string(u32 error_code)
{
	switch (error_code)
	{
		case GL_INVALID_ENUM:					return "INVALID_ENUM";
		case GL_INVALID_VALUE:					return "INVALID_VALUE";
		case GL_INVALID_OPERATION:				return "INVALID_OPERATION";
		case GL_OUT_OF_MEMORY:					return "OUT_OF_MEMORY";
		case GL_INVALID_FRAMEBUFFER_OPERATION:	return "INVALID_FRAMEBUFFER_OPERATION";
	}

	return "UNKNOWN";
}

u32 gl_check_error(const std::string& file, int line)
{
	u32 first_error = GL_NO_ERROR;
	u32 error_code;
	while ((error_code = glGetError()) != GL_NO_ERROR)
	{
		if (first_error == GL_NO_ERROR) first_error = error_code;
		onyx_glerr(onyx::GLError{
			.code = error_code,
			.file = std::filesystem::path(file).filename().string(),
			.line = line
			}
		);
	}
	return first_error;
}

void onyx::init()
{
	if (initialized) return;

	{
		std::lock_guard lock(mtx_resource_path);
		if (resource_path == "") resource_path = "../resources/";
	}

	stbi_set_flip_vertically_on_load(true);

	{
		std::lock_guard lock(mtx_ft);
		if (FT_Init_FreeType(&ft)) return;
	}

	if (!glfwInit())
	{
		std::lock_guard lock(mtx_ft);
		FT_Done_FreeType(ft);
		return;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef ONYX_OS_MAC
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

	onyx_seed_random((u32)time(nullptr));

	initialized = true;
}

void onyx::init(ErrorHandler& error_handler)
{
	if (initialized)
	{
		error_handler.warn(Warning{
				.source_function = "onyx::init(ErrorHandler& error_handler)",
				.message = "Attempted to initialize library when it is already initialized. Initialization aborted.",
				.how_to_fix = "If reinitialization was intentional, terminate the library first.",
				.severity = Warning::Severity::Low
			}
		);
		return;
	}

	p_error_handler = &error_handler;

	stbi_set_flip_vertically_on_load(true);

	{
		std::lock_guard lock(mtx_resource_path);
		// Must match the default in init() above. Deliberately relative rather than derived from
		// __FILE__: baking the build machine's source path into the binary makes the default
		// meaningless anywhere the library is actually shipped. Callers that load their own assets
		// should set this explicitly with set_resource_path().
		if (resource_path == "") resource_path = "../resources/";
	}

	{
		std::lock_guard lock(mtx_ft);
		if (FT_Init_FreeType(&ft))
		{
			onyx_err(Error{
					.source_function = "onyx::init(ErrorHandler& error_handler)",
					.message = "Failed to initialize FreeType.",
					.how_to_fix = "Ensure FreeType was found and linked correctly when configuring the project with CMake.",
				}
			);
			return;
		}
	}

	if (!glfwInit())
	{
		onyx_err(Error{
			   .source_function = "onyx::init(ErrorHandler& error_handler)",
			   .message = "Failed to initialize GLFW.",
			   .how_to_fix = "Ensure GLFW was found and linked correctly when configuring the project with CMake, and that a display is available.",
			}
		);
		std::lock_guard lock(mtx_ft);
		FT_Done_FreeType(ft);
		return;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef ONYX_OS_MAC
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

	onyx_seed_random((u32)time(nullptr));

	initialized = true;
}

int onyx::get_version_major()
{
	return ONYX_VERSION_MAJOR;
}

int onyx::get_version_minor()
{
	return ONYX_VERSION_MINOR;
}

int onyx::get_version_patch()
{
	return ONYX_VERSION_PATCH;
}

bool onyx::is_alpha()
{
	return ONYX_ALPHA;
}

bool onyx::is_beta()
{
	return ONYX_BETA;
}

bool onyx::is_release_candidate()
{
	return ONYX_RELEASE_CANDIDATE;
}

bool onyx::is_stable()
{
	return ONYX_STABLE;
}

std::string onyx::get_version_string()
{
	return ONYX_VERSION_STRING;
}

void onyx::cleanup()
{
	if (!initialized) return;

	{
		std::lock_guard lock(mtx_ft);
		FT_Done_FreeType(ft);
	}
	glfwTerminate();

	{
		std::lock_guard lock(mtx_mallocs);
		for (auto it = mallocs.rbegin(); it != mallocs.rend(); ++it)
		{
			if (it->first != nullptr) it->second(it->first);
		}
		mallocs.clear();
	}

	gl_initialized = false;
	initialized = false;
}

std::string onyx::get_clipboard_string()
{
	const char* str = glfwGetClipboardString(nullptr);
	return str != nullptr ? std::string(str) : std::string();
}

void onyx::set_clipboard_string(const std::string& str)
{
	glfwSetClipboardString(nullptr, str.c_str());
}

bool onyx::is_initialized()
{
	return initialized;
}

bool onyx::is_opengl_initialized()
{
	return gl_initialized;
}

void onyx::set_error_handler(ErrorHandler& error_handler)
{
	p_error_handler = &error_handler;
}

void onyx::set_resource_path(std::string path)
{
	if (path.length() == 0) return;

	std::lock_guard lock(mtx_resource_path);
	if (path[path.length() - 1] != '/' && path[path.length() - 1] != '\\') resource_path = path + "/";
	else resource_path = path;
}

void onyx::set_user_ptr(const std::string& name, void* ptr)
{
	std::lock_guard lock(mtx_user_ptrs);
	user_ptrs.insert_or_assign(name, ptr);
}

std::string onyx::get_resource_path()
{
	std::lock_guard lock(mtx_resource_path);
	return resource_path;
}

std::string onyx::get_cache_path()
{
	static const std::string cache_path = []() -> std::string
	{
		std::string base;

#if defined(ONYX_OS_WINDOWS) && defined(_MSC_VER)
		// MSVC deprecates getenv (C4996); MinGW's msvcrt does not provide _dupenv_s, so it uses getenv below
		char* local_app_data = nullptr;
		size_t local_app_data_len = 0;
		if (_dupenv_s(&local_app_data, &local_app_data_len, "LOCALAPPDATA") == 0 && local_app_data != nullptr) base = local_app_data;
		std::free(local_app_data);
#elif defined(ONYX_OS_WINDOWS)
		if (const char* local_app_data = std::getenv("LOCALAPPDATA")) base = local_app_data;
#elif defined(ONYX_OS_MAC)
		if (const char* home = std::getenv("HOME")) base = std::string(home) + "/Library/Caches";
#else
		if (const char* xdg_cache = std::getenv("XDG_CACHE_HOME")) base = xdg_cache;
		else if (const char* home = std::getenv("HOME")) base = std::string(home) + "/.cache";
#endif

		// Last resort if the environment gives us nothing to work with. The cache is
		// optional, so a temp dir is an acceptable (if less persistent) fallback.
		if (base.empty())
		{
			std::error_code ec;
			std::filesystem::path tmp = std::filesystem::temp_directory_path(ec);
			base = ec ? "." : tmp.string();
		}

		return (std::filesystem::path(base) / "onyx" / "shaders").string() + "/";
	}();

	return cache_path;
}

std::string onyx::resources(const std::string& path)
{
	std::string res_path = get_resource_path();
	if (path.length() == 0) return res_path;
	return res_path + (path[0] == '/' || path[0] == '\\' ? path.substr(1) : path);
}

std::string onyx::res(const std::string& path)
{
	return resources(path);
}

void* onyx::get_user_ptr(const std::string& name, bool* result)
{
	if (p_error_handler || result)
	{
		void* ptr = nullptr;
		bool found = false;
		{
			std::lock_guard lock(mtx_user_ptrs);
			auto it = user_ptrs.find(name);
			if (it != user_ptrs.end())
			{
				found = true;
				ptr = it->second;
			}
		}

		if (!found)
		{
			onyx_err(Error{
					.source_function = "onyx::get_user_ptr(const std::string& name, bool* result)",
					.message = "User pointer with name \"" + name + "\" not found.",
					.how_to_fix = "Ensure a user pointer with this name was set."
				}
			);
			if (result != nullptr) *result = false;
			return nullptr;
		}
		if (result != nullptr) *result = true;
		return ptr;
	}
	else
	{
		std::lock_guard lock(mtx_user_ptrs);
		return user_ptrs.at(name);
	}
}

double onyx::get_time()
{
	return glfwGetTime();
}

std::string onyx::get_graphics_name(bool* result)
{
	if (!gl_initialized)
	{
		onyx_err(Error{
				.source_function = "onyx::get_graphics_name()",
				.message = "OpenGL is not initialized, name unavailable.",
				.how_to_fix = "Initialze OpenGL by initializing a window before this function is called."
			}
		);
		if (result != nullptr) *result = false;
		return "";
	}

	const GLubyte* p_name = glGetString(GL_RENDERER);

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif

	if (result != nullptr) *result = p_name != nullptr;
	return p_name != nullptr ? std::string((const char*)p_name) : std::string();
}

bool onyx::is_extension_supported(const std::string& ext, bool* result)
{
	if (!gl_initialized)
	{
		onyx_err(Error{
				.source_function = "onyx::is_extension_supported(const std::string& ext, bool* result)",
				.message = "OpenGL is not initialized, extension support unknown.",
				.how_to_fix = "Initialze OpenGL by initializing a window before this function is called."
			}
		);
		if (result != nullptr) *result = false;
		return false;
	}
	if (result != nullptr) *result = true;
	return glfwExtensionSupported(ext.c_str()) == GLFW_TRUE;
}

void onyx::sleep(double seconds)
{
	if (seconds <= 0.0) return;
	std::this_thread::sleep_for(std::chrono::duration<double>(seconds));
}

bool onyx::Disposable::is_disposed() const
{
	return this->disposed;
}
