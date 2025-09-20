//
// Created by bessi on 20/09/2025.
//

#include "window.h"
#include <stdexcept>
#include <GL/gl.h>

Window::Window(int width, int height, const std::string &title) {
    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create window");
    }
    glfwMakeContextCurrent(window);
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(window);
}

void Window::pollEvents() const {
    glfwPollEvents();
}

void Window::swapBuffers() const {
    glfwSwapBuffers(window);
}

void Window::clear() const {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::setAspectOrtho(const float left, const float right, const float bottom, const float top,
                            const float nearVal, const float farVal) const {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(left, right, bottom, top, nearVal, farVal);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
