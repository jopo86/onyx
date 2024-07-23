cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Onyx VERSION 1.6.1)

add_compile_options(-Wno-volatile -Wno-delete-incomplete)

file(GLOB SRC_CPP_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB TEST_CPP_FILES ${CMAKE_SOURCE_DIR}/tests/*.cpp)

add_library(onyx ${SRC_CPP_FILES} ${CMAKE_SOURCE_DIR}/src/glad.c)

add_executable(test ${TEST_CPP_FILES})

if(WIN32)
    target_include_directories(onyx SYSTEM PUBLIC ${CMAKE_SOURCE_DIR}/include)
    target_link_directories(onyx PUBLIC ${CMAKE_SOURCE_DIR}/lib)
    target_link_libraries(onyx PUBLIC opengl32 glfw3 freetype bz2 zlib)

    target_include_directories(test SYSTEM PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)
    target_link_directories(test PUBLIC ${CMAKE_SOURCE_DIR}/lib ${CMAKE_SOURCE_DIR}/build)
    target_link_libraries(test PUBLIC onyx opengl32 glfw3 freetype bz2 zlib)
else()
    target_include_directories(onyx SYSTEM PUBLIC ${CMAKE_SOURCE_DIR}/include)
    target_link_directories(onyx PUBLIC ${CMAKE_SOURCE_DIR}/lib)
    target_link_libraries(onyx PUBLIC GL glfw3 X11 freetype bz2 z)

    target_include_directories(test SYSTEM PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)
    target_link_directories(test PUBLIC ${CMAKE_SOURCE_DIR}/lib ${CMAKE_SOURCE_DIR}/build)
    target_link_libraries(test PUBLIC onyx GL glfw3 X11 freetype bz2 z)
endif()
