cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Onyx VERSION 1.3.4)

add_compile_options(-Wno-volatile -Wno-delete-incomplete)

add_library(onyx 
    ${CMAKE_SOURCE_DIR}/src/Camera.cpp 
    ${CMAKE_SOURCE_DIR}/src/CharRenderable.cpp 
    ${CMAKE_SOURCE_DIR}/src/Core.cpp 
    ${CMAKE_SOURCE_DIR}/src/ErrorHandler.cpp 
    ${CMAKE_SOURCE_DIR}/src/FileUtils.cpp 
    ${CMAKE_SOURCE_DIR}/src/Fog.cpp 
    ${CMAKE_SOURCE_DIR}/src/Font.cpp 
    ${CMAKE_SOURCE_DIR}/src/Gamepad.cpp 
    ${CMAKE_SOURCE_DIR}/src/glad.c 
    ${CMAKE_SOURCE_DIR}/src/IndexBuffer.cpp 
    ${CMAKE_SOURCE_DIR}/src/InputHandler.cpp 
    ${CMAKE_SOURCE_DIR}/src/Lighting.cpp 
    ${CMAKE_SOURCE_DIR}/src/Math.cpp 
    ${CMAKE_SOURCE_DIR}/src/MathSwizzle.cpp 
    ${CMAKE_SOURCE_DIR}/src/Mesh.cpp 
    ${CMAKE_SOURCE_DIR}/src/Model.cpp 
    ${CMAKE_SOURCE_DIR}/src/ModelRenderable.cpp 
    ${CMAKE_SOURCE_DIR}/src/Monitor.cpp 
    ${CMAKE_SOURCE_DIR}/src/Projection.cpp 
    ${CMAKE_SOURCE_DIR}/src/Renderable.cpp 
    ${CMAKE_SOURCE_DIR}/src/Renderer.cpp 
    ${CMAKE_SOURCE_DIR}/src/Shader.cpp 
    ${CMAKE_SOURCE_DIR}/src/TextRenderable.cpp 
    ${CMAKE_SOURCE_DIR}/src/TextRenderable3D.cpp 
    ${CMAKE_SOURCE_DIR}/src/Texture.cpp 
    ${CMAKE_SOURCE_DIR}/src/UiRenderable.cpp 
    ${CMAKE_SOURCE_DIR}/src/VertexBuffer.cpp 
    ${CMAKE_SOURCE_DIR}/src/Window.cpp
)

add_executable(test
    ${CMAKE_SOURCE_DIR}/tests/BouncingBallTest.cpp
    ${CMAKE_SOURCE_DIR}/tests/Main.cpp
    ${CMAKE_SOURCE_DIR}/tests/PresetTests.cpp
    ${CMAKE_SOURCE_DIR}/tests/WindowTest.cpp
)

target_include_directories(onyx PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_directories(onyx PUBLIC ${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(onyx PUBLIC freetype bz2 glfw3 zlib)

target_include_directories(test PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)
target_link_directories(test PUBLIC ${CMAKE_SOURCE_DIR}/lib ${CMAKE_SOURCE_DIR}/build)
target_link_libraries(test PUBLIC freetype bz2 glfw3 zlib onyx)
