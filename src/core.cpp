#pragma warning(disable : 4244; disable: 4267)

#include "core.h"

#include <string>
#include <unordered_map>
#include <atomic>
#include <thread>
#include <mutex>
#include <cstdlib>
#include <filesystem>

#include <ft2build.h>
#include FT_FREETYPE_H

#define STB_IMAGE_IMPLEMENTATION
#include <stbi/stb_image.h>

#include "math.h"
#include "window.h"
#include "input_handler.h"
#include "camera.h"
#include "projection.h"
#include "model.h"
#include "text_renderable.h"
#include "text_renderable_3d.h"
#include "file_utils.h"

using onyx::math::Vec2, onyx::math::Vec3, onyx::math::Vec4;

std::atomic<bool> initialized = false;
std::atomic<bool> gl_initialized = false;
std::atomic<onyx::ErrorHandler*> p_error_handler = nullptr;
std::atomic<void*> old_user_ptr = nullptr;

std::string resource_path;
FT_Library ft;
std::vector<std::pair<void*, bool>> mallocs;
std::unordered_map<std::string, void*> user_ptrs;
std::pair<bool, u32> vsync = { true, 1 };

std::mutex mtx_resource_path;
std::mutex mtx_ft;
std::mutex mtx_mallocs;
std::mutex mtx_user_ptrs;
std::mutex mtx_vsync;

void onyx_seed_random(u32 seed);

void onyx_set_gl_init(bool val)
{
	gl_initialized = val;
}

FT_Library* onyx_get_ft()
{
	mtx_ft.lock();
	FT_Library* p_ft = &ft;
	mtx_ft.unlock();
	return p_ft;
}

void onyx_add_malloc(void* ptr, bool array)
{
	mtx_mallocs.lock();
	mallocs.push_back(std::pair<void*, bool>(ptr, array));
	mtx_mallocs.unlock();
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
		case GL_STACK_OVERFLOW:					return "STACK_OVERFLOW";
		case GL_STACK_UNDERFLOW:				return "STACK_UNDERFLOW";
		case GL_OUT_OF_MEMORY:					return "OUT_OF_MEMORY";
		case GL_INVALID_FRAMEBUFFER_OPERATION:	return "INVALID_FRAMEBUFFER_OPERATION";
	}

	return "UNKNOWN";
}

u32 gl_check_error(const std::string& file, int line)
{
	u32 error_code;
	while ((error_code = glGetError()) != GL_NO_ERROR)
	{
		onyx_glerr(onyx::GLError{
			.code = error_code,
			.file = file.substr(file.find_last_of("\\") + 1),
			.line = line
			}
		);
	}
	return error_code;
}

void onyx::init()
{
	if (initialized) return;

	initialized = true;
	mtx_resource_path.lock();
	if (resource_path == "") resource_path = "../resources/";
	mtx_resource_path.unlock();

	stbi_set_flip_vertically_on_load(true);

	mtx_ft.lock();
	FT_Init_FreeType(&ft);
	mtx_ft.unlock();

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef ONYX_OS_MAC
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

	for (int i = GLFW_JOYSTICK_1; i <= GLFW_JOYSTICK_16; i++)
	{
		glfwSetJoystickUserPointer(i, nullptr);
	}

	onyx_seed_random(time(nullptr));
}

void onyx::init(ErrorHandler& error_handler)
{
	if (initialized) return;

	p_error_handler = &error_handler;

	stbi_set_flip_vertically_on_load(true);

	if (initialized)
	{
		onyx_warn(Warning{
				.source_function = "onyx::init(ErrorHandler& error_handler)",
				.message = "Attempted to initialize library when it is already initialized. Initialization aborted.",
				.how_to_fix = "If reinitialization was intentional, terminate the library first.",
				.severity = Warning::Severity::Low
			}
		);
		return;
	}
	initialized = true;
	mtx_resource_path.lock();
	// Must match the default in init() above. Deliberately relative rather than derived from
	// __FILE__: baking the build machine's source path into the binary makes the default
	// meaningless anywhere the library is actually shipped. Callers that load their own assets
	// should set this explicitly with set_resource_path().
	if (resource_path == "") resource_path = "../resources/";
	mtx_resource_path.unlock();

	mtx_ft.lock();
	if (FT_Init_FreeType(&ft))
	{
		onyx_err(Error{
			.source_function = "onyx::init(ErrorHandler& error_handler)",
			.message = "Failed to initialize FreeType.",
			.how_to_fix = "Ensure the FreeType library is downloaded for your specific platform. If you are not running Windows x64, you will need to download FreeType for yourself, you can't just use the one from the Onyx download.",
			}
		);
		mtx_ft.unlock();
		return;
	}
	mtx_ft.unlock();

	if (!glfwInit())
	{
		onyx_err(Error{
			   .source_function = "onyx::init(ErrorHandler& error_handler)",
			   .message = "Failed to initialize GLFW.",
			   .how_to_fix = "Ensure the GLFW library is downloaded for your specific platform. If you are not running Windows x64, you will need to download GLFW for yourself, you can't just use the one from the Onyx download.",
			}
		);
		return;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef ONYX_OS_MAC
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

	for (int i = GLFW_JOYSTICK_1; i <= GLFW_JOYSTICK_16; i++)
	{
		glfwSetJoystickUserPointer(i, nullptr);
	}

	onyx_seed_random(time(nullptr));
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
	std::string ver = std::to_string(ONYX_VERSION_MAJOR) + "." + std::to_string(ONYX_VERSION_MINOR) + "." + std::to_string(ONYX_VERSION_PATCH);
	if (ONYX_ALPHA) ver += "-alpha";
	else if (ONYX_BETA) ver += "-beta";
	else if (ONYX_RELEASE_CANDIDATE) ver += "-rc";
	if (!ONYX_STABLE) ver += std::to_string(ONYX_PRE_RELEASE_NUM);
	return ver;
}

void onyx::terminate()
{
	if (!initialized) return;

	mtx_ft.lock();
	FT_Done_FreeType(ft);
	mtx_ft.unlock();
	glfwTerminate();

	mtx_mallocs.lock();
	int size = mallocs.size();
	mtx_mallocs.unlock();
	for (int i = size - 1; i >= 0; i--)
	{
		mtx_mallocs.lock();
		if (mallocs[i].second && mallocs[i].first != nullptr) delete[] mallocs[i].first;
		else if (mallocs[i].first != nullptr) delete mallocs[i].first;
		mallocs.pop_back();
		mtx_mallocs.unlock();
	}
	initialized = false;
}

std::string onyx::get_clipboard_string()
{
	return glfwGetClipboardString(nullptr);
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
	
	mtx_resource_path.lock();
	if (path[path.length() - 1] != '/' && path[path.length() - 1] != '\\') resource_path = path + "/";
	else resource_path = path;
	mtx_resource_path.unlock();
}

void onyx::set_user_ptr(void* ptr)
{
	old_user_ptr = ptr;
}

void onyx::set_user_ptr(const std::string& name, void* ptr)
{
	mtx_user_ptrs.lock();
	user_ptrs.insert_or_assign(name, ptr);
	mtx_user_ptrs.unlock();
}

std::string onyx::get_resource_path()
{
	mtx_resource_path.lock();
	std::string res_path = resource_path;
	mtx_resource_path.unlock();
	return res_path;
}

std::string onyx::get_cache_path()
{
	static const std::string cache_path = []() -> std::string
	{
		std::string base;

#if defined(ONYX_OS_WINDOWS)
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
	mtx_resource_path.lock();
	std::string res_path = resource_path;
	mtx_resource_path.unlock();
	if (path.length() == 0) return res_path;
	return res_path + (path[0] == '/' || path[0] == '\\' ? path.substr(1) : path);
}

std::string onyx::res(const std::string& path)
{
	mtx_resource_path.lock();
	std::string res_path = resource_path;
	mtx_resource_path.unlock();
	if (path.length() == 0) return res_path;
	return res_path + (path[0] == '/' || path[0] == '\\' ? path.substr(1) : path);
}

void* onyx::get_user_ptr()
{
	return old_user_ptr;
}

void* onyx::get_user_ptr(const std::string& name, bool* result)
{
	if (p_error_handler || result)
	{
		mtx_user_ptrs.lock();
		auto it = user_ptrs.find(name);
		if (it == user_ptrs.end())
		{
			mtx_user_ptrs.unlock();
			if (p_error_handler != nullptr) onyx_err(Error{
					.source_function = "onyx::get_user_ptr(const std::string& name, bool* result)",
					.message = "User pointer with name \"" + name + "\" not found.",
					.how_to_fix = "Ensure a user pointer with this name was set."
				}
			);
			if (result != nullptr) *result = false;
			return nullptr;
		}
		if (result != nullptr) *result = true;
		void* ptr = it->second;
		mtx_user_ptrs.unlock();
		return ptr;
	}
	else
	{
		mtx_user_ptrs.lock();
		void* ptr = user_ptrs.at(name);
		mtx_user_ptrs.unlock();
		return ptr;
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
	if (result != nullptr) *result = true;
	return std::string((const char*)glGetString(GL_RENDERER));

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
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
	int ns = (int)(seconds * 1000000000);
	std::this_thread::sleep_for(std::chrono::nanoseconds(ns));
}

bool onyx::Disposable::is_disposed() const
{
	return this->disposed;
}
