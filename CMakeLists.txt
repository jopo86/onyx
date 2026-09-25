cmake_minimum_required(VERSION 3.25)
project(Onyx VERSION 2.0.0 LANGUAGES C CXX)

# pre-release tag without the leading dash ("alpha", "beta.2", "rc.1"); empty for a stable release
set(ONYX_VERSION_SUFFIX "alpha")

include(FetchContent)

# Emits build/compile_commands.json so editors/tooling resolve the real include
# paths and compile definitions (e.g. ONYX_EXAMPLE_RESOURCES) instead of guessing.
# Honored by the Makefile and Ninja generators.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(ONYX_BUILD_EXAMPLES "Build the Onyx example programs" ${PROJECT_IS_TOP_LEVEL})
option(ONYX_WARNINGS_AS_ERRORS "Treat compiler warnings as errors when building Onyx" OFF)
option(ONYX_SANITIZE "Build Onyx and the examples with AddressSanitizer + UndefinedBehaviorSanitizer (GCC/Clang)" OFF)

# ---------------------------------------------------------------------------
# dependencies
# ---------------------------------------------------------------------------

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

# strips FreeType's optional dependencies (only applies when built from source)
set(FT_DISABLE_ZLIB ON CACHE BOOL "" FORCE)
set(FT_DISABLE_BZIP2 ON CACHE BOOL "" FORCE)
set(FT_DISABLE_PNG ON CACHE BOOL "" FORCE)
set(FT_DISABLE_HARFBUZZ ON CACHE BOOL "" FORCE)
set(FT_DISABLE_BROTLI ON CACHE BOOL "" FORCE)

set(GLM_BUILD_LIBRARY OFF CACHE BOOL "" FORCE)
set(GLM_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLM_BUILD_INSTALL OFF CACHE BOOL "" FORCE)

# FIND_PACKAGE_ARGS makes CMake quietly try find_package() first and only clone
# if the dependency isn't already installed. Set FETCHCONTENT_TRY_FIND_PACKAGE_MODE=NEVER
# to force building everything from source. SYSTEM keeps their headers' warnings out of ours.
FetchContent_Declare(glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4  GIT_SHALLOW TRUE
    SYSTEM
    # 3.4 floor, not 3.3: CursorType in core.hpp uses the standard cursor
    # constants added in 3.4 (GLFW_RESIZE_*, GLFW_NOT_ALLOWED_CURSOR).
    FIND_PACKAGE_ARGS 3.4 NAMES glfw3)
FetchContent_Declare(freetype
    GIT_REPOSITORY https://github.com/freetype/freetype.git
    GIT_TAG VER-2-13-3  GIT_SHALLOW TRUE
    SYSTEM
    FIND_PACKAGE_ARGS 2.11 NAMES Freetype)
FetchContent_Declare(glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 1.0.1  GIT_SHALLOW TRUE
    SYSTEM
    FIND_PACKAGE_ARGS 1.0)
FetchContent_MakeAvailable(glfw freetype glm)

# FreeType's in-build target is `freetype`; find_package() instead provides
# `Freetype::Freetype`. Normalize so the link line below works either way.
if(NOT TARGET Freetype::Freetype)
    add_library(Freetype::Freetype ALIAS freetype)
endif()

# glad: OpenGL 4.1 core loader, generated with glad 0.1.36 (see extern/README.md)
add_library(onyx_glad STATIC extern/glad/src/glad.c)
target_include_directories(onyx_glad SYSTEM PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/extern/glad/include>)
set_target_properties(onyx_glad PROPERTIES POSITION_INDEPENDENT_CODE ON)

# ---------------------------------------------------------------------------
# library
# ---------------------------------------------------------------------------

string(TOLOWER "${ONYX_VERSION_SUFFIX}" _onyx_suffix)
set(ONYX_VERSION_STRING "${PROJECT_VERSION}")
if(_onyx_suffix)
    string(APPEND ONYX_VERSION_STRING "-${ONYX_VERSION_SUFFIX}")
endif()
macro(_onyx_suffix_flag var prefix)
    if(_onyx_suffix MATCHES "^${prefix}")
        set(${var} true)
    else()
        set(${var} false)
    endif()
endmacro()
_onyx_suffix_flag(ONYX_ALPHA "alpha")
_onyx_suffix_flag(ONYX_BETA "beta")
_onyx_suffix_flag(ONYX_RELEASE_CANDIDATE "rc")
if(_onyx_suffix)
    set(ONYX_STABLE false)
else()
    set(ONYX_STABLE true)
endif()
configure_file(cmake/version.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/include/onyx/version.hpp @ONLY)

add_library(onyx
    src/camera.cpp
    src/char_renderable.cpp
    src/core.cpp
    src/error_handler.cpp
    src/file_utils.cpp
    src/fog.cpp
    src/font.cpp
    src/gamepad.cpp
    src/image_data.cpp
    src/index_buffer.cpp
    src/input_handler.cpp
    src/lighting.cpp
    src/math_swizzle.cpp
    src/math_wrappers.cpp
    src/mesh.cpp
    src/model.cpp
    src/model_renderable.cpp
    src/monitor.cpp
    src/projection.cpp
    src/renderable.cpp
    src/renderer.cpp
    src/shader.cpp
    src/stb_image.cpp
    src/text_renderable.cpp
    src/text_renderable_3d.cpp
    src/texture.cpp
    src/ui_renderable.cpp
    src/vertex_buffer.cpp
    src/window.cpp)
add_library(Onyx::onyx ALIAS onyx)

target_compile_features(onyx PUBLIC cxx_std_20)
target_include_directories(onyx
    PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
            $<INSTALL_INTERFACE:include>)
# single-header libraries only used inside the implementation
target_include_directories(onyx SYSTEM PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/stb
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/obj_loader)

target_link_libraries(onyx PUBLIC onyx_glad glfw Freetype::Freetype glm::glm)

# lock-key queries in src/input_handler.cpp talk to the OS directly
if(APPLE)
    target_link_libraries(onyx PRIVATE "-framework ApplicationServices")
elseif(UNIX)
    find_package(X11 REQUIRED)
    target_link_libraries(onyx PRIVATE X11::X11)
endif()

function(onyx_set_warnings target)
    if(MSVC)
        target_compile_options(${target} PRIVATE /W4 /permissive- $<$<BOOL:${ONYX_WARNINGS_AS_ERRORS}>:/WX>)
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic $<$<BOOL:${ONYX_WARNINGS_AS_ERRORS}>:-Werror>)
        # GCC 12 emits a false -Wrestrict for `"literal" + std::string` at -O2+ (GCC bug 105329)
        if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 12 AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 13)
            target_compile_options(${target} PRIVATE -Wno-restrict)
        endif()
    endif()
endfunction()
onyx_set_warnings(onyx)

if(ONYX_SANITIZE)
    if(MSVC)
        message(WARNING "ONYX_SANITIZE: only AddressSanitizer is supported on MSVC")
        target_compile_options(onyx PUBLIC /fsanitize=address)
    else()
        target_compile_options(onyx PUBLIC -fsanitize=address,undefined -fno-omit-frame-pointer)
        target_link_options(onyx PUBLIC -fsanitize=address,undefined)
    endif()
endif()

# ---------------------------------------------------------------------------
# examples
# ---------------------------------------------------------------------------

if(ONYX_BUILD_EXAMPLES)
    set(ONYX_EXAMPLES bouncing_ball cubes presets window)
    foreach(example_name ${ONYX_EXAMPLES})
        add_executable(onyx_example_${example_name} examples/${example_name}.cpp)
        target_link_libraries(onyx_example_${example_name} PRIVATE Onyx::onyx)
        onyx_set_warnings(onyx_example_${example_name})
        # Absolute so the examples run from any working directory. The library's own
        # default resource path is deliberately relative (see src/core.cpp), so the
        # examples set theirs explicitly rather than depending on where they're launched.
        target_compile_definitions(onyx_example_${example_name} PRIVATE
            ONYX_EXAMPLE_RESOURCES="${CMAKE_CURRENT_SOURCE_DIR}/examples/resources")
        set_target_properties(onyx_example_${example_name} PROPERTIES
            OUTPUT_NAME ${example_name}
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/examples)
    endforeach()
endif()
