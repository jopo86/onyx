cmake_minimum_required(VERSION 3.24)
project(Onyx VERSION 2.0.0 LANGUAGES C CXX)
set(ONYX_VERSION_SUFFIX "alpha")

include(FetchContent)

# Emits build/compile_commands.json so editors/tooling resolve the real include
# paths and compile definitions (e.g. ONYX_EXAMPLE_RESOURCES) instead of guessing.
# Honored by the Makefile and Ninja generators.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(ONYX_BUILD_EXAMPLES "Build the Onyx example programs" ON)

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

# FIND_PACKAGE_ARGS makes CMake quietly try find_package() first and only clone
# if the dependency isn't already installed. Set FETCHCONTENT_TRY_FIND_PACKAGE_MODE=NEVER
# to force building both from source.
FetchContent_Declare(glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4  GIT_SHALLOW TRUE
    # 3.4 floor, not 3.3: CursorType in core.hpp uses the standard cursor
    # constants added in 3.4 (GLFW_RESIZE_*, GLFW_NOT_ALLOWED_CURSOR).
    FIND_PACKAGE_ARGS 3.4 NAMES glfw3)
FetchContent_Declare(freetype
    GIT_REPOSITORY https://github.com/freetype/freetype.git
    GIT_TAG VER-2-13-3  GIT_SHALLOW TRUE
    FIND_PACKAGE_ARGS 2.11 NAMES Freetype)
FetchContent_MakeAvailable(glfw freetype)

# FreeType's in-build target is `freetype`; find_package() instead provides
# `Freetype::Freetype`. Normalize so the link line below works either way.
if(NOT TARGET Freetype::Freetype)
    add_library(Freetype::Freetype ALIAS freetype)
endif()

file(GLOB SRC_CPP_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(onyx ${SRC_CPP_FILES} ${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c)
target_compile_features(onyx PUBLIC cxx_std_20)
target_include_directories(onyx
    PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>)
target_include_directories(onyx SYSTEM
    PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/extern)

target_link_libraries(onyx PUBLIC glfw Freetype::Freetype)
target_compile_options(onyx PRIVATE
    $<$<AND:$<COMPILE_LANGUAGE:CXX>,$<CXX_COMPILER_ID:GNU,Clang,AppleClang>>:-Wno-volatile;-Wno-delete-incomplete>)

if(ONYX_BUILD_EXAMPLES)
    file(GLOB EXAMPLE_CPP_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp)
    foreach(example_file ${EXAMPLE_CPP_FILES})
        get_filename_component(example_name ${example_file} NAME_WE)
        add_executable(onyx_example_${example_name} ${example_file})
        target_link_libraries(onyx_example_${example_name} PRIVATE onyx)
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
