#include "window.h"
#include "circle.h"
#include <iostream>


constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;
constexpr float CIRCLE_RADIUS = 0.05f;
constexpr float aspect = static_cast<float>(WINDOW_WIDTH) / WINDOW_HEIGHT;

int main() {
    try {
        Window window(WINDOW_WIDTH, WINDOW_HEIGHT, "My OpenGL Window");

        while (!window.shouldClose()) {
            window.clear();
            window.setAspectOrtho(-aspect, aspect, -1.0f, 1.0f, -1.0f, 1.0f);

            drawCircle(0.0f, 0.0f, CIRCLE_RADIUS);

            window.swapBuffers();
            window.pollEvents();
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}
