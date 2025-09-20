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

bool Window::isMouseButtonPressed(const int button) const {
    return glfwGetMouseButton(window, button) == GLFW_PRESS;
}

void Window::getMouseWorldPosition(float &worldX, float &worldY) const {
    double mouseX, mouseY;
    glfwGetCursorPos(window, &mouseX, &mouseY);

    int width, height;
    glfwGetWindowSize(window, &width, &height);

    // Convertir les coordonnées de la souris en coordonnées du monde
    worldX = static_cast<float>(mouseX) / width * 2.0f - 1.0f;
    worldY = 1.0f - static_cast<float>(mouseY) / height * 2.0f;
    worldX *= (static_cast<float>(width) / height); // Ajuster pour l'aspect ratio
}

void Window::changeTitle(const std::string &title) const {
    glfwSetWindowTitle(window, title.c_str());
}
