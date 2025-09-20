cmake_minimum_required(VERSION 4.0)
project(cpp_gravity_simulation)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_gravity_simulation
        src/main.cpp
        src/main.h
        src/graphics/window.cpp
        src/graphics/window.h
        src/graphics/draw.cpp
        src/graphics/draw.h
        src/core/ball.cpp
        src/core/ball.h
        src/core/constants.cpp
        src/core/constants.h
)

find_package(glfw3 REQUIRED)
target_link_libraries(cpp_gravity_simulation PRIVATE glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(cpp_gravity_simulation PRIVATE glfw OpenGL::GL)


