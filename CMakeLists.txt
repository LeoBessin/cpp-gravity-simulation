cmake_minimum_required(VERSION 4.0)
project(cpp_gravity_simulation)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_gravity_simulation
        main.cpp
        main.h
        window.cpp
        window.h
        circle.cpp
        circle.h
)

find_package(glfw3 REQUIRED)
target_link_libraries(cpp_gravity_simulation PRIVATE glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(cpp_gravity_simulation PRIVATE glfw OpenGL::GL)


