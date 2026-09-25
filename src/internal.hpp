#pragma once

/*
	@file Library-internal declarations shared between translation units.
	Not part of the public API and not installed.
 */

#include <ft2build.h>
#include FT_FREETYPE_H

#include <onyx/core.hpp>
#include <onyx/error_handler.hpp>

void onyx_err(const onyx::Error& error);
void onyx_warn(const onyx::Warning& warning);
void onyx_glerr(const onyx::GLError& error);

/*
	@brief Registers a heap allocation to be freed by onyx::cleanup(), along with a type-correct deleter.
	Use onyx_add_malloc() rather than calling this directly.
 */
void onyx_add_malloc_impl(void* ptr, void(*deleter)(void*));

/*
	@brief Registers a heap allocation (made with `new` or `new[]`) to be freed by onyx::cleanup().
	The pointer's static type is used to delete it, so pass it with its real type (not void*).
	@param ptr The pointer to free on cleanup.
	@param array Whether the pointer was allocated with `new[]`.
 */
template<typename T>
void onyx_add_malloc(T* ptr, bool array)
{
	if (array) onyx_add_malloc_impl(ptr, [](void* p) { delete[] static_cast<T*>(p); });
	else onyx_add_malloc_impl(ptr, [](void* p) { delete static_cast<T*>(p); });
}

void onyx_set_gl_init(bool val);
FT_Library* onyx_get_ft();
void onyx_seed_random(u32 seed);
