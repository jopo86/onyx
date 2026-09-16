cmake_minimum_required(VERSION 3.14)
project(Onyx VERSION 1.7.1 LANGUAGES C CXX)

include(FetchContent)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

# strips FreeType's optional dependencies
set(FT_DISABLE_ZLIB ON CACHE BOOL "" FORCE)
set(FT_DISABLE_BZIP2 ON CACHE BOOL "" FORCE)
set(FT_DISABLE_PNG ON CACHE BOOL "" FORCE)
set(FT_DISABLE_HARFBUZZ ON CACHE BOOL "" FORCE)
set(FT_DISABLE_BROTLI ON CACHE BOOL "" FORCE)

FetchContent_Declare(glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4  GIT_SHALLOW TRUE)
FetchContent_Declare(freetype
    GIT_REPOSITORY https://github.com/freetype/freetype.git
    GIT_TAG VER-2-13-3  GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(glfw freetype)

file(GLOB SRC_CPP_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB TEST_CPP_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)

add_library(onyx ${SRC_CPP_FILES} ${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c)
target_compile_features(onyx PUBLIC cxx_std_20)
target_include_directories(onyx SYSTEM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(onyx PUBLIC glfw freetype)
target_compile_options(onyx PRIVATE
    $<$<AND:$<COMPILE_LANGUAGE:CXX>,$<CXX_COMPILER_ID:GNU,Clang,AppleClang>>:-Wno-volatile;-Wno-delete-incomplete>)

add_executable(onyx_test ${TEST_CPP_FILES})
target_include_directories(onyx_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(onyx_test PRIVATE onyx)
