//
// Created by bessi on 20/09/2025.
//

#ifndef CPP_GRAVITY_SIMULATION_WINDOW_H
#define CPP_GRAVITY_SIMULATION_WINDOW_H


#pragma once
#include <GLFW/glfw3.h>
#include <string>

class Window {
public:
    Window(int width, int height, const std::string &title);

    ~Window();

    bool shouldClose() const;

    void pollEvents() const;

    void swapBuffers() const;

    void clear() const;

    void setAspectOrtho(float left, float right, float bottom, float top, float nearVal, float farVal) const;

private:
    GLFWwindow *window;
};


#endif //CPP_GRAVITY_SIMULATION_WINDOW_H
